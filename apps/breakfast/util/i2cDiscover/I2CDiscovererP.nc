#include "I2CDiscoverable.h"
//TODO: ten-bit addresses: should be parameterized
generic module I2CDiscovererP(uint8_t globalAddrLength){
  uses interface I2CPacket<TI2CBasicAddr>;
  uses interface I2CSlave;
  uses interface Resource;
  provides interface I2CDiscoverer;
  provides interface SplitControl;
  uses interface Timer<TMilli>;
  //TODO: should provide Msp430UsciConfigure: set UCMM!
} implementation {
  uint8_t reg[I2C_DISCOVERABLE_REGISTERS_SIZE];
  uint8_t pos;
  uint8_t transCount;
  norace uint16_t masterAddr = I2C_INVALID_MASTER;
  uint16_t localAddr = I2C_DISCOVERABLE_UNASSIGNED;
  bool isGC;
  bool setAddrNeeded;
  bool resetNeeded;
  uint8_t state;
  bool isReceive;

  enum{
    S_ERROR,
    S_OFF,
  };

  void setState(uint8_t s){
    atomic{
      state = s;
    }
  }

  bool checkState(uint8_t s){
    atomic return s == state;
  }

  
  typedef struct {
    uint8_t pos;
    uint8_t cmd;
    uint8_t globalAddr[globalAddrLength];
  } discoverable_reservation_msg_t;

  typedef union{
    discoverable_reservation_msg_t msg;
    uint8_t data[0];
  } discoverable_reservation_t;

  discoverable_reservation_t _reservation;

  command error_t SplitControl.start(){
    if ( SUCCESS == call Resource.request()){
      setState(S_INIT);
      //TODO: put this in a structure
      //register setup is : cmd [globalAddr] localAddr
      reg[globalAddrLength] = I2C_FIRST_DISCOVERABLE_ADDR;
      return SUCCESS;
    } else {
      return FAIL;
    }
  }

  event void Resource.granted(){
    localAddr = signal I2CDiscoverer.getLocalAddr();
    call I2CSlave.setOwnAddress(localAddr);
    post announce();
  }

  task void announce(){
    reg[0] = (localAddr << 1) | 0x01;
    if( SUCCESS != call I2CPacket.write(I2C_START|I2C_STOP, I2C_GC_ADDR, 1, reg)){
      setState(S_ERROR);
      signal SplitControl.startDone(FAIL);
    }else {
      setState(S_ANNOUNCING);
    }
  }

  async event void I2CPacket.writeDone(error_t error, uint16_t slaveAddr, uint8_t len, uint8_t* buf){
    uint8_t stateTmp;
    atomic stateTmp = state;
    switch(stateTmp){
      case S_ANNOUNCING:
        if(error == SUCCESS){
          setState(S_WAITING);
        } else if (error == ENOACK){
          //TODO: nobody home, we're done
        } else {
          setState(S_ERROR);
        }
        break;
      default:
        setState(S_ERROR);
    }
  }

  task void startRound(){
  }

  async event void I2CSlave.slaveStart(bool generalCall){
    isGC = generalCall;
    transCount = 0;
    switch(state){
      case S_WAITING:
        //we expect the master to write the CLAIM cmd, then their global address from
        //  position 0 onward
        setState(S_ASSIGNING);
        break;
      case S_ASSIGNING:
        //we expect the master to read one byte (their local address)
        //  then stop.
        break;
      default:
        setState(S_ERROR);
    }
  }

  async event error_t I2CSlave.slaveReceive(uint8_t data){
    if (isGC){
      //first byte ends with 1: own-address announcement from master
      if (data & 0x01){
        // ignoring own-address announcements
      } else {
        switch(data){
          case 0x06:    //reset + set addr
            resetNeeded = TRUE;
            //fall-through
          case 0x04:    //set addr
            setAddrNeeded = TRUE;
            break;
          default://everything else: forbidden!
            return EINVAL;
        }
      }
    } else {
      if(transCount == 0){
        //first byte: offset
        pos = data;
      } else {
        //everything else: write it to buffer if space permits
        if (pos+transCount <= I2C_DISCOVERABLE_REGISTERS_SIZE){
          reg[pos + transCount - 1] = data;
        } else {
          return ESIZE;
        }
      }
    }
    transCount++;
    return SUCCESS;
  }

  async event uint8_t I2CSlave.slaveTransmit(){
    isReceive=FALSE;
    if(pos + transCount <= I2C_DISCOVERABLE_REGISTERS_SIZE){
      return reg[pos + (transCount++) -1];
    } else {
      return 0xff;
    }
  }


  task void assignedTask(){
    call Timer.stop();
    signal SplitControl.startDone(SUCCESS);
  }

  async event void I2CPacket.readDone(error_t error, uint16_t slaveAddr, uint8_t len, uint8_t* buf){
    uint8_t stateTmp;
    atomic stateTmp = state;
    switch(stateTmp){
     default:
        setState(S_ERROR);
    }
  }


  task void processSlaveReceive(){
    call Timer.startOneShot(I2C_DISCOVERY_ROUND_TIMEOUT);
    atomic{
      if (isGC){
        if(resetNeeded){
          localAddr = I2C_DISCOVERABLE_UNASSIGNED;
          setState(S_WAITING);
          resetNeeded = FALSE;
        }
        if(setAddrNeeded && localAddr == I2C_DISCOVERABLE_UNASSIGNED && masterAddr != I2C_INVALID_MASTER){
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
    if (checkState(S_RECEIVING)){
      signal I2CDiscoverer.transactionEnd(reg);
      reg[globalAddrLength]++;
    }else{
      setState(S_ERROR);
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
}

