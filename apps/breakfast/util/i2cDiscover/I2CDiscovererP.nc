#include "I2CDiscoverable.h"
//TODO: ten-bit addresses: should be parameterized
generic module I2CDiscovererP(){
  uses interface I2CPacket<TI2CBasicAddr>;
  uses interface I2CSlave;
  uses interface Resource;
  provides interface I2CDiscoverer;
  provides interface SplitControl;
  uses interface Timer<TMilli>;
  //TODO: should provide Msp430UsciConfigure: set UCMM!
} implementation {
  uint8_t pos;
  uint8_t transCount;
  norace uint16_t masterAddr = I2C_INVALID_MASTER;
  uint16_t localAddr = I2C_DISCOVERABLE_UNASSIGNED;
  bool isGC;
  bool setAddrNeeded;
  bool resetNeeded;
  uint8_t state;
  bool isReceive;
  uint8_t txByte;

  enum{
    S_INIT= 0,
    S_OFF = 1,
    S_ANNOUNCING = 2,
    S_ANNOUNCED = 10,
    S_RESETTING = 8,
    S_SETTING = 9,
    S_WAITING = 3,
    S_ASSIGNING = 4,
    S_RESPONDING = 5,
    S_RECEIVING = 6,
    S_ERROR = 7,
  };

  task void announce();

  void setState(uint8_t s){
    atomic{
      printf("I2CDiscovererP %x -> %x\n\r", state, s);
      state = s;
    }
  }

  bool checkState(uint8_t s){
    atomic return s == state;
  }
  
  //TODO: should be buffer swap
  discoverer_register_union_t reg;

  command error_t SplitControl.start(){
    printf("%s: \n\r", __FUNCTION__);
    if ( SUCCESS == call Resource.request()){
      setState(S_INIT);
      //register setup is : cmd [globalAddr] localAddr
      atomic reg.val.localAddr = I2C_FIRST_DISCOVERABLE_ADDR;
      return SUCCESS;
    } else {
      return FAIL;
    }
  }

  event void Resource.granted(){
    printf("%s: \n\r", __FUNCTION__);
    localAddr = signal I2CDiscoverer.getLocalAddr();
    call I2CSlave.setOwnAddress(localAddr);
    post announce();
  }

  task void announce(){
    error_t err;
    printf("announce");
    txByte = (localAddr << 1) | 0x01;
    atomic{
      err = call I2CPacket.write(I2C_START|I2C_STOP, I2C_GC_ADDR, 1, &txByte);
      if( err != SUCCESS){
        setState(S_ERROR);
      }else {
        setState(S_ANNOUNCING);
      }
    }
    //deal with race condition: writing a single byte is damn fast--
    //if we check state then it will likely already have been modified
    //in the writeDone event
    if (err != SUCCESS){
      signal SplitControl.startDone(FAIL);
    }
  }

  task void resetTask(){
    error_t err;
    txByte = I2C_GC_RESET_PROGRAM_ADDR;
    atomic{
      err = call I2CPacket.write(I2C_START|I2C_STOP, I2C_GC_ADDR, 1, &txByte);
      if (err != SUCCESS){
        setState(S_ERROR);
      } else {
        setState(S_RESETTING);
      }
    }
  }

  task void setTask(){
    error_t err;
    txByte = I2C_GC_PROGRAM_ADDR;
    atomic{
      err = call I2CPacket.write(I2C_START|I2C_STOP, I2C_GC_ADDR, 1, &txByte);
      if (err != SUCCESS){
        setState(S_ERROR);
      } else {
        setState(S_SETTING);
      }
    }
  }

  async event void I2CPacket.writeDone(error_t error, uint16_t slaveAddr, uint8_t len, uint8_t* buf){
    uint8_t stateTmp;
    //TODO: this is getting signalled before the call to write completes.
    atomic stateTmp = state;
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error)); 
    switch(stateTmp){
      case S_ANNOUNCING:
        if(error == SUCCESS){
          setState(S_ANNOUNCED);
          post resetTask();
        } else if (error == ENOACK){
          //TODO: nobody home, we're done
        } else {
          setState(S_ERROR);
        }
        break;
      case S_RESETTING:
        //fall-through
      case S_SETTING:
        if(error == SUCCESS){
          setState(S_WAITING);
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
        setState(S_RESPONDING);
        break;
      default:
        setState(S_ERROR);
    }
  }

  async event bool I2CSlave.slaveReceiveRequested(){
    uint8_t data = call I2CSlave.slaveReceive();
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
            setState(S_ERROR);
        }
      }
    } else {
      if(transCount == 0){
        //first byte: offset
        pos = data;
      } else {
        //everything else: write it to buffer (circular)
        reg.data[(pos + transCount - 1)%sizeof(discoverer_register_t)] = data;
      }
    }
    transCount++;
    return TRUE;
  }

  async event uint8_t I2CSlave.slaveTransmitRequested(){
    isReceive=FALSE;
    //return from buf (circular)
    call I2CSlave.slaveTransmit(reg.data[(pos++)%sizeof(discoverer_register_t)]);
    return TRUE;
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


  async event void I2CSlave.slaveStop(){
    if (checkState(S_RECEIVING)){
      //TODO: check command should be done when requester is reading
      //from reg...
      if (reg.val.cmd == I2C_DISCOVERABLE_REQUEST_ADDR){
        signal I2CDiscoverer.discovered(&reg);
        reg.val.localAddr++;
      }
      //continue
      //TODO: set timeout, we might be done
      post setTask();
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

}

