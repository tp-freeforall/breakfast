#include "I2CDiscoverable.h"
//TODO: ten-bit addresses: should be parameterized
generic module I2CDiscoverableRequesterP(uint8_t globalAddrLength){
  uses interface I2CPacket<TI2CBasicAddr>;
  uses interface I2CSlave;
  uses interface Resource;
  provides interface I2CDiscoverable;
  provides interface SplitControl;
  uses interface Timer<TMilli>;
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
    S_WAITING,
    S_CLAIMING_BUS,
    S_ZEROING_MASTER,
    S_READING_ADDR,
    S_ASSIGNED,
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
      setState(S_WAITING);
      _reservation.msg.pos = 0;
      _reservation.msg.cmd = I2C_DISCOVERABLE_REQUEST_ADDR;
      memcpy(_reservation.msg.globalAddr, signal I2CDiscoverable.getGlobalAddr(), globalAddrLength);
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
    call Timer.startOneShot(I2C_DISCOVERY_ROUND_TIMEOUT);
  }


  async event void I2CSlave.slaveStart(bool generalCall){
    isGC = generalCall;
    setAddrNeeded = FALSE;
    resetNeeded = FALSE;
    transCount = 0;
  }

  async event error_t I2CSlave.slaveReceive(uint8_t data){
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

  task void requestLocalAddrTask(){
    //first, try to write your globally-unique ID to the master, with RESTART 
    //  - Succeeds: you've got the bus, so read from next-local-addr
    //  register
    //  - write succeeds, but get an EBUSY in writeDone: try again
    //    next time
    //  - fails: something's wrong
    if (SUCCESS ==  call I2CPacket.write(I2C_START|I2C_RESTART,
        masterAddr, sizeof(_reservation), _reservation.data)){
      setState(S_CLAIMING_BUS);
    } else {
      //TODO: EBUSY = go back to wait, fail = error?
      setState(S_ERROR);
    }
    
  }

  task void zeroMaster(){
    _reservation.msg.pos = 0x00;
    //write position only
    if (SUCCESS == call I2CPacket.write(I2C_RESTART,
        masterAddr, 1, _reservation.data)){
      setState(S_ZEROING_MASTER);
    }else{
      setState(S_ERROR);
    }
  }

  task void readLocalAddr(){
    if (SUCCESS == call I2CPacket.read(I2C_STOP, masterAddr,
        2, (uint8_t*)(&localAddr))){
      setState(S_READING_ADDR);
    } else {
      setState(S_ERROR);
    }
  }

  async event void I2CPacket.writeDone(error_t error, uint16_t slaveAddr, uint8_t len, uint8_t* buf){
    uint8_t stateTmp;
    atomic stateTmp = state;
    switch(stateTmp){
      case S_CLAIMING_BUS:
        if(error == SUCCESS){
          post zeroMaster();
        } else {
          setState(S_WAITING);
        }
        break;
      case S_ZEROING_MASTER:
        if (error == SUCCESS){
          post readLocalAddr();
        } else {
          setState(S_ERROR);
        }
        break;
      default:
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
}
