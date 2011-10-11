//TODO: ten-bit addresses: should be parameterized
generic module I2CDiscoverableP(uint8_t globalAddrLength){
  uses interface I2CPacket<I2CBasicAddr>;
  uses interface I2CSlave;
  uses interface Resource;
  provides interface I2CDiscoverable;
  provides interface SplitControl;
  uses interface Timer<TMilli>;
} implementation {
  uint8_t reg[I2C_DISCOVERABLE_REGISTERS_SIZE];
  uint8_t pos;
  uint8_t transCount;
  uint16_t masterAddr = I2C_INVALID_MASTER;
  bool isGC;
  bool setAddrNeeded;
  bool resetNeeded;
  
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
  uint16_t localAddr;

  command void SplitControl.start(){
    call Resource.request();
    _reservation.msg.pos = 0;
    _reservation.msg.cmd = I2C_DISCOVERABLE_REQUEST_ADDR;
    memcpy(_reservation.msg.globalAddr, signal I2CDiscoverable.getGlobalAddr(), globalAddrLength);
  }

  event void Resource.requested(){
    //start timeout-- if we haven't been assigned an addr by
    //that time, give up.
    state = S_WAITING;
    call I2CSlave.setOwnAddress(I2C_DISCOVERABLE_UNASSIGNED);
    call I2CSlave.enableGeneralCall();
    call Timer.startOneShot(I2C_DISCOVERY_ROUND_TIMEOUT);
  }


  async event void slaveStart(bool generalCall){
    isGC = generalCall;
    setAddrNeeded = FALSE;
    resetNeeded = FALSE;
    transCount = 0;
  }

  async event error_t slaveReceive(uint8_t data){
    isReceive=TRUE;
    if (isGC){
      //first byte ends with 1: own-address announcement from master
      if (data & 0x01){
        masterAddr = data >> 1;
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
  }

  async event uint8_t slaveTransmit(){
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
    if (SUCCESS ==  call I2CPacket.write(I2C_START|I2C_RESTART, masterAddr, _reservation.data, sizeof(_reservation))){
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
        masterAddr, _reservation.data, 1)){
      setState(S_ZEROING_MASTER);
    }else{
      setState(S_ERROR);
    }
  }

  task void readLocalAddr(){
    if (SUCCESS == call I2CPacket.read(I2C_STOP, masterAddr,
        &localAddr, 1)){
      setState(S_READING_ADDR);
    } else {
      setState(S_ERROR);
    }
  }

  event void I2CPacket.writeDone(error_t error, uint16_t slaveAddr, uint8_t* buf, uint8_t len){
    switch(state){
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

  event void I2CPacket.readDone(error_t error, uint16_t slaveAddr, uint8_t* buf,
      uint8_t len){
    switch(state){
      case S_READING_ADDR:
        if (error == SUCCESS){
          //great, we're all set.
          setState(S_ASSIGNED);
          call Timer.stop();
          signal SplitControl.startDone(SUCCESS);
        } else {
          setSTate(S_ERROR);
        }
        break;
      default:
        setState(S_ERROR);
    }
  }


  task void processSlaveReceive(){
    call Timer.startOneShot(I2C_DISCOVERY_ROUND_TIMEOUT);
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

  task void processSlaveTransmit(){
    //nothin'
  }

  async event void slaveStop(){
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
    if (Resource.isOwner()){
      if(call Resource.release() == SUCCESS){
        post signalStopDoneTask();
        return SUCCESS;
      }else {
        return FAIL;
      }
    } else {
      return EALREADY;
    }
  }

  command uint16_t I2CDiscoverable.getLocalAddr(){
    return localAddr;
  }
}
