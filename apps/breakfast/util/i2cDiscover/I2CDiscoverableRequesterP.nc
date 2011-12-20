/**
 * - should receive master address, then reset/set cmd. When
 *   this is received, try to claim the bus by writing to the bus
 *   head via requestLocalAddr task (does not send stop condition). Attempt to
 *   write pos 0, cmd = "claim", data = global address
 * - when this write completes, either we get SUCCESS, at which point
 *   we try to read the next byte from the bus head (our local
 *   address), or we get something else and go back to sitting around
 *   waiting for a reset/set.
 * - if we manage to read from the bus head, then signal startDone to
 *   indicate that we have a local address now.
 * 
**/
#include "I2CDiscoverable.h"
//TODO: ten-bit addresses: should be parameterized
generic module I2CDiscoverableRequesterP(){
  uses interface I2CPacket<TI2CBasicAddr> as SubI2CPacket;
  uses interface I2CSlave as SubI2CSlave;
  uses interface Resource as SubResource;
  provides interface I2CDiscoverable;
  uses interface Timer<TMilli> as RandomizeTimer;
  uses interface Random;
  uses interface ParameterInit<uint16_t> as RandomInit;
  provides interface Msp430UsciConfigure;
  provides interface Resource;
  provides interface I2CSlave;
  provides interface I2CPacket<TI2CBasicAddr>;
} implementation {
  uint8_t transCount;
  norace uint16_t masterAddr = I2C_INVALID_MASTER;
  norace uint16_t lastLocalAddr = I2C_DISCOVERABLE_UNASSIGNED;
  bool isDiscovering;
  bool setAddrNeeded;
  bool resetNeeded;
  uint8_t state;
  bool isReceive;

  enum{
    S_WAITING = 0x00,
    S_CLAIMING_BUS = 0x01,
    S_READING_ADDR = 0x02,
    S_ASSIGNED = 0x03,
    S_ERROR = 0x04,
    S_OFF = 0x05,
  };

  void setState(uint8_t s){
    atomic{
      //printf("DAble: %x->%x\n\r", state, s);
      state = s;
    }
  }

  bool checkState(uint8_t s){
    atomic return s == state;
  }
  
  typedef struct {
    uint8_t pos;
    uint8_t cmd;
    uint8_t globalAddr[I2C_GLOBAL_ADDR_LENGTH];
  } __attribute__((__packed__)) discoverable_reservation_msg_t;

  typedef union{
    discoverable_reservation_msg_t msg;
    uint8_t data[sizeof(discoverable_reservation_msg_t)];
  } __attribute__((__packed__)) discoverable_reservation_t;

  discoverable_reservation_t _reservation;

  command void I2CDiscoverable.setLocalAddr(uint16_t lastLocalAddr_){
    lastLocalAddr = lastLocalAddr_;
  }

  void init(){
    setState(S_WAITING);
    _reservation.msg.pos = 0;
    _reservation.msg.cmd = I2C_DISCOVERABLE_REQUEST_ADDR;
    memcpy(_reservation.msg.globalAddr, signal I2CDiscoverable.getGlobalAddr(), I2C_GLOBAL_ADDR_LENGTH);
    call SubI2CSlave.setOwnAddress(lastLocalAddr);
    call SubI2CSlave.enableGeneralCall();

    //TODO: should randomize with hash of the whole address
    call RandomInit.init(_reservation.msg.globalAddr[I2C_GLOBAL_ADDR_LENGTH-1]);
  }

  async command error_t Resource.request(){
    return call SubResource.request();
  }

  async command error_t Resource.release(){
    return call SubResource.release();
  }

  async command bool Resource.isOwner(){
    return call SubResource.isOwner();
  }

  async command error_t Resource.immediateRequest(){
    error_t ret = call SubResource.immediateRequest();
    if (SUCCESS == ret){
      init();
    }
    return ret;
  }

  event void SubResource.granted(){
    init();
    signal Resource.granted();
  }


  async event void SubI2CSlave.slaveStart(bool generalCall){
    //printf("%s: %x \n\r", __FUNCTION__, generalCall);
    isDiscovering = generalCall;
    setAddrNeeded = FALSE;
    resetNeeded = FALSE;
    transCount = 0;
    if (! isDiscovering){
      signal I2CSlave.slaveStart(generalCall);
    }
  }

  async event bool SubI2CSlave.slaveReceiveRequested(){
    uint8_t data;
    //printf("%s: \n\r", __FUNCTION__);
    //printf("RX %x\n\r", data);
    if (isDiscovering){
      isReceive=TRUE;
      data = call SubI2CSlave.slaveReceive();
      //first byte ends with 1: own-address announcement from master
      if (data & 0x01){
        if (checkState(S_WAITING) || checkState(S_ASSIGNED)){
          masterAddr = data >> 1;
        } else {
          //changing the master address while we're doing anything
          //(except waiting or chillin) is bad.
          setState(S_ERROR);
        }
      } else {
        //printf("Set flags\n\r");
        switch(data){
          case 0x06:    //reset + set addr
            //printf("reset needed\n\r");
            resetNeeded = TRUE;
            //fall-through
          case 0x04:    //set addr
            //printf("set needed\n\r");
            setAddrNeeded = TRUE;
            break;
          default://everything else: forbidden!
            setState(S_ERROR);
        }
      }
      return TRUE;
    } else {
      //Not doing discovery, so just signal it up.
      return signal I2CSlave.slaveReceiveRequested();
    }
  }

  async command uint8_t I2CSlave.slaveReceive(){
    if (isDiscovering){
      //Should not be allowed to disrupt discovery process
      return 0xff;
    } else {
      return call SubI2CSlave.slaveReceive();
    }
  }

  async event bool SubI2CSlave.slaveTransmitRequested(){
    if (isDiscovering){
      isReceive=FALSE;
      setState(S_ERROR);
      call SubI2CSlave.slaveTransmit(0xff);
      return TRUE;
    } else {
      return signal I2CSlave.slaveTransmitRequested();
    }
  }
  
  async command void I2CSlave.slaveTransmit(uint8_t data){
    if (isDiscovering){
      //ignore it. I guess that this command should actually return
      //error_t 
    } else {
      call SubI2CSlave.slaveTransmit(data);
    }
  }

  task void requestLocalAddrTask(){
    error_t err;
    //printf("%s: \n\r", __FUNCTION__);
    //first, try to write your globally-unique ID to the master, with RESTART 
    //  - Succeeds: you've got the bus, so read from next-local-addr
    //  register
    //  - write succeeds, but get an EBUSY in writeDone: try again
    //    next time
    //  - fails: something's wrong
    //printf("fixin' to write %x bytes from %p (base %p)\n\r", sizeof(_reservation), _reservation.data, &_reservation);
    atomic{
      err = call SubI2CPacket.write(I2C_START , masterAddr, sizeof(_reservation), _reservation.data);
      if (err == SUCCESS){
        //printf("CLAIM\n\r");
        setState(S_CLAIMING_BUS);
      } else {
        //printf("RLE: ERROR\n\r");
        //TODO: EBUSY = go back to wait, fail = error?
        setState(S_ERROR);
      }
    }
    
  }

  task void readLocalAddr(){
    error_t err;
    //printf("%s: \n\r", __FUNCTION__);
    //restart: don't check for EBUSY
    err = call SubI2CPacket.read(I2C_RESTART | I2C_STOP, masterAddr, 2, (uint8_t*)(&lastLocalAddr));
//    printf("%s:read %s\n\r", __FUNCTION__, decodeError(err));
    if (err == SUCCESS){
      setState(S_READING_ADDR);
    } else {
      setState(S_ERROR);
    }
  }

  async event void SubI2CPacket.writeDone(error_t error, uint16_t slaveAddr, uint8_t len, uint8_t* buf){
    uint8_t stateTmp;
    atomic stateTmp = state;
//    printf("%s: %s \n\r", __FUNCTION__, decodeError(error));
    if (isDiscovering){
      switch(stateTmp){
        case S_CLAIMING_BUS:
          if(error == SUCCESS){
            post readLocalAddr();
          } else {
            setState(S_WAITING);
          }
          break;
        default:
  //        printf("bad state:%x \n\r", stateTmp);
          setState(S_ERROR);
      }
    } else {
      signal I2CPacket.writeDone(error, slaveAddr, len, buf);
    }
  }

  task void assignedTask(){
    setState(S_OFF);
    signal I2CDiscoverable.assigned(SUCCESS, lastLocalAddr);
  }

  async event void SubI2CPacket.readDone(error_t error, uint16_t slaveAddr, uint8_t len, uint8_t* buf){
    uint8_t stateTmp;
    atomic stateTmp = state;
//    printf("%s: %s \n\r", __FUNCTION__, decodeError(error));
    if (isDiscovering){
      switch(stateTmp){
        case S_READING_ADDR:
          if (error == SUCCESS){
            //great, we're all set.
            setState(S_ASSIGNED);
            post assignedTask();
          } else {
            setState(S_ERROR);
          }
          break;
        default:
          setState(S_ERROR);
      }
    } else {
      signal I2CPacket.readDone(error, slaveAddr, len, buf);
    }
  }

  event void RandomizeTimer.fired(){
    post requestLocalAddrTask();
  }
  
  task void setTimers(){
    call RandomizeTimer.startOneShot(call Random.rand16() % I2C_RANDOMIZE_MAX_DELAY);
  }

  //OK: initial announcement causes SR task to get posted.  Conditions
  //hold for it to be ignored (it's not a reset or setAddr)
  //the second message (set or reset) is either missed or causes a
  //re-post, which doesn't do us much good.
  async event void SubI2CSlave.slaveStop(){
    //printf("%s: \n\r", __FUNCTION__);
    if (isDiscovering){
      if (isReceive && (resetNeeded || setAddrNeeded)){
        if (resetNeeded){
          lastLocalAddr = I2C_DISCOVERABLE_UNASSIGNED;
          resetNeeded = FALSE;
        }
        if (setAddrNeeded 
            && (lastLocalAddr == I2C_DISCOVERABLE_UNASSIGNED) 
            && (masterAddr != I2C_INVALID_MASTER)){
          setAddrNeeded = FALSE;
          post setTimers();
        }
      }
    } else {
      signal I2CSlave.slaveStop();
    }
  }

  command uint16_t I2CDiscoverable.getLastLocalAddr(){
    return lastLocalAddr;
  }

  const msp430_usci_config_t _config = {
    ctl0: UCSYNC|UCMODE_3|UCMM,
    ctl1: UCSSEL_2,
    br0:  0x08,
    br1:  0x00,
    mctl: 0x00,
    i2coa: I2C_DISCOVERABLE_UNASSIGNED,
  };

  async command const msp430_usci_config_t* Msp430UsciConfigure.getConfiguration(){
    return &_config;
  }

  
  command error_t I2CSlave.setOwnAddress(uint16_t addr){
    if ( isDiscovering){
      return EBUSY;
    } else {
      return call SubI2CSlave.setOwnAddress(addr);
    }
  }

  command error_t I2CSlave.enableGeneralCall(){
    if (isDiscovering){
      return EBUSY;
    } else {
      return call SubI2CSlave.enableGeneralCall();
    }
  }

  command error_t I2CSlave.disableGeneralCall(){
    if (isDiscovering){
      return EBUSY;
    } else {
      return call SubI2CSlave.disableGeneralCall();
    }
  }

  async command error_t I2CPacket.read(i2c_flags_t flags, uint16_t addr, 
      uint8_t length, uint8_t* data){
    if (isDiscovering){
      return EBUSY;
    } else {
      return call SubI2CPacket.read(flags, addr, length, data);
    }
  }

  async command error_t I2CPacket.write(i2c_flags_t flags, uint16_t addr,
      uint8_t length, uint8_t* data){
    if (isDiscovering){
      return EBUSY;
    } else {
      return call SubI2CPacket.write(flags, addr, length, data);
    }
  }

}
