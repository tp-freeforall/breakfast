#include "I2CDiscoverable.h"
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
//TODO: ten-bit addresses: should be parameterized
generic module I2CDiscoverableRequesterP(){
  uses interface I2CPacket<TI2CBasicAddr>;
  uses interface I2CSlave;
  uses interface Resource;
  provides interface I2CDiscoverable;
  provides interface SplitControl;
  uses interface Timer<TMilli>;
  provides interface Msp430UsciConfigure;
} implementation {
  uint8_t transCount;
  norace uint16_t masterAddr = I2C_INVALID_MASTER;
  uint16_t localAddr = I2C_DISCOVERABLE_UNASSIGNED;
  bool isGC;
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
      printf("I2CDiscoverableRequesterP: %x -> %x\n\r", state, s);
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

  command error_t SplitControl.start(){
    if ( SUCCESS == call Resource.request()){
      setState(S_WAITING);
      _reservation.msg.pos = 0;
      _reservation.msg.cmd = I2C_DISCOVERABLE_REQUEST_ADDR;
      memcpy(_reservation.msg.globalAddr, signal I2CDiscoverable.getGlobalAddr(), I2C_GLOBAL_ADDR_LENGTH);
      return SUCCESS;
    } else {
      return FAIL;
    }
  }

  event void Resource.granted(){
    //start timeout-- if we haven't been assigned an addr by
    //that time, give up.
    setState(S_WAITING);
    call I2CSlave.setOwnAddress(I2C_DISCOVERABLE_UNASSIGNED);
    call I2CSlave.enableGeneralCall();
    call Timer.startOneShot(I2C_DISCOVERY_INITIAL_TIMEOUT);
  }


  async event void I2CSlave.slaveStart(bool generalCall){
    printf("%s: %x \n\r", __FUNCTION__, generalCall);
    isGC = generalCall;
    setAddrNeeded = FALSE;
    resetNeeded = FALSE;
    transCount = 0;
  }

  async event bool I2CSlave.slaveReceiveRequested(){
    uint8_t data = call I2CSlave.slaveReceive();
    printf("%s: \n\r", __FUNCTION__);
    isReceive=TRUE;
    if (isGC){
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
        switch(data){
          case 0x06:    //reset + set addr
            resetNeeded = TRUE;
            //fall-through
          case 0x04:    //set addr
            setAddrNeeded = TRUE;
            break;
          default://everything else: forbidden!
            setState(S_ERROR);
        }
      }
    } 
    return TRUE;
  }

  async event bool I2CSlave.slaveTransmitRequested(){
    isReceive=FALSE;
    setState(S_ERROR);
    call I2CSlave.slaveTransmit(0xff);
    return TRUE;
  }

  task void requestLocalAddrTask(){
    error_t err;
    printf("%s: \n\r", __FUNCTION__);
    //first, try to write your globally-unique ID to the master, with RESTART 
    //  - Succeeds: you've got the bus, so read from next-local-addr
    //  register
    //  - write succeeds, but get an EBUSY in writeDone: try again
    //    next time
    //  - fails: something's wrong
    printf("fixin' to write %x bytes from %p (base %p)\n\r", sizeof(_reservation), _reservation.data, &_reservation);
    atomic{
      err = call I2CPacket.write(I2C_START , masterAddr, sizeof(_reservation), _reservation.data);
      if (err == SUCCESS){
        printf("CLAIMING\n\r");
        setState(S_CLAIMING_BUS);
      } else {
        printf("ERROR\n\r");
        //TODO: EBUSY = go back to wait, fail = error?
        setState(S_ERROR);
      }
    }
    
  }

  task void readLocalAddr(){
    error_t err;
    printf("%s: \n\r", __FUNCTION__);
    //restart: don't check for EBUSY
    err = call I2CPacket.read(I2C_RESTART | I2C_STOP, masterAddr, 2, (uint8_t*)(&localAddr));
    printf("%s:read %s\n\r", __FUNCTION__, decodeError(err));
    if (err == SUCCESS){
      setState(S_READING_ADDR);
    } else {
      setState(S_ERROR);
    }
  }

  async event void I2CPacket.writeDone(error_t error, uint16_t slaveAddr, uint8_t len, uint8_t* buf){
    uint8_t stateTmp;
    atomic stateTmp = state;
    printf("%s: %s \n\r", __FUNCTION__, decodeError(error));
    switch(stateTmp){
      case S_CLAIMING_BUS:
        if(error == SUCCESS){
          post readLocalAddr();
        } else {
          setState(S_WAITING);
        }
        break;
      default:
        printf("bad state:%x \n\r", stateTmp);
        setState(S_ERROR);
    }
  }

  task void assignedTask(){
    call Timer.stop();
    signal SplitControl.startDone(SUCCESS);
  }

  async event void I2CPacket.readDone(error_t error, uint16_t slaveAddr, uint8_t len, uint8_t* buf){
    uint8_t stateTmp;
    atomic stateTmp = state;
    printf("%s: %s \n\r", __FUNCTION__, decodeError(error));
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
  }


  task void processSlaveReceive(){
    printf("%s: \n\r", __FUNCTION__);
    atomic{
      if (isGC){
        if(resetNeeded){
          printf("RESET\n\r");
          localAddr = I2C_DISCOVERABLE_UNASSIGNED;
          setState(S_WAITING);
          resetNeeded = FALSE;
        }
        if(setAddrNeeded && localAddr == I2C_DISCOVERABLE_UNASSIGNED && masterAddr != I2C_INVALID_MASTER){
          //TODO: this could probably be much shorter, no longer
          //waiting undefined time for start of the process, but
          //waiting for a single assignment to complete
          call Timer.startOneShot(I2C_DISCOVERY_ROUND_TIMEOUT);
          setAddrNeeded = FALSE;
          post requestLocalAddrTask();
        }
      }else{
        //nothin'
      }
    }
  }

  task void processSlaveTransmit(){
    //nothin'
  }

  async event void I2CSlave.slaveStop(){
    printf("%s: \n\r", __FUNCTION__);
    if (isReceive){
      post processSlaveReceive();
    } else {
      post processSlaveTransmit();
    }
  }

  task void signalStopDone(){
    signal SplitControl.stopDone(SUCCESS);
  }

  command error_t SplitControl.stop(){
    if (call Resource.isOwner()){
      if(call Resource.release() == SUCCESS){
        post signalStopDone();
        return SUCCESS;
      }else {
        return FAIL;
      }
    } else {
      return EALREADY;
    }
  }

  event void Timer.fired(){
    if (call Resource.isOwner()){
      if (call Resource.release() == SUCCESS){
        signal SplitControl.startDone(ENOACK);
      }else{
        signal SplitControl.startDone(FAIL);
      }
    } else {
      signal SplitControl.startDone(FAIL);
    }
  }

  command uint16_t I2CDiscoverable.getLocalAddr(){
    return localAddr;
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
}
