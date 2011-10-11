//TODO: ten-bit addresses: should be parameterized
generic module I2CDiscoverableP(uint8_t globalAddrLength){
  uses interface I2CPacket<I2CBasicAddr>;
  uses interface I2CSlave;
  uses interface Resource;
  provides interface I2CDiscoverable;
  provides interface SplitControl;
  uses interface Timer<TMilli>;
  uses interface Random;
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
    uint16_t localAddr;
    uint8_t globalAddr[globalAddrLength];
  } discoverable_claim_msg_t;

  typedef union{
    discoverable_claim_msg_t msg;
    uint8_t data[0];
  } discoverable_claim_t;

  discoverable_claim_t _claim;
  uint16_t localAddr;

  command void SplitControl.start(){
    call Resource.request();
    _claim.msg.pos = 0;
    _claim.msg.cmd = I2C_DISCOVERABLE_CLAIM_ADDR;
    _claim.msg.localAddr = I2C_DISCOVERABLE_UNASSIGNED;
    //TODO: seed rand with xor of global addr words: Put this in
    //the platform definition.
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

  uint16_t generateLocalAddr(uint8_t* globalAddress){
    uint8_t i;
    uint16_t ret; // = call Random.rand16();

    //return the lower 16 bits the first time around. If there's a
    //conflict, then we try some randomization thing. 
    for(i = 0; i< globalAddrLength; i++){
      if (i & 0x01){
        ret ^= (globalAddress[i] <<8)
      } else {
        ret ^= globalAddress[i];
      }
    }
    return ret;
  }

  uint16_t makeValid(uint16_t addr){
    //TODO: 10-bit addressing: make sure that neither the lower 10
    //bits nor the lower 7 bits violate the rules
    addr &= 0x007f;

    //TODO: this distribution is no longer uniform :(
    //upper 4 bits cannot be 1111 or 0000. Flip the upper bit.
    if (((addr >> 3) == 0x0000 ) 
        || ((addr >> 3) == 0x0078)){
      addr ^= 0x0040;
    }
    return addr;
  }

  task void claimLocalAddrTask(){
    //write to master
    //  - position 0
    //  - I2C_DISCOVERABLE_CLAIM
    //  - globalAddr
    //  - localAddr
    call I2CSlave.setOwnAddress(localAddr);
    _claim.msg.localAddr = localAddr;
    memcopy(_claim.msg.globalAddr, signal I2CDiscoverable.getGlobalAddress(), globalAddrLength);
    //TODO: right types?
    call I2CPacket.write(I2C_START|I2C_STOP, masterAddr, _claim.data, sizeof(_claim));
  }

  event void I2CPacket.writeDone(uint16_t slaveAddr, uint8_t* buf, uint8_t len){
    if (error == SUCCESS){
      //TODO: now, we wait for confirmation
    } else{
      //TODO: now, we wait for another round to start. probably lost
      //  arbitration
    }
  }


  task void processSlaveReceive(){
    call Timer.startOneShot(I2C_DISCOVERY_ROUND_TIMEOUT);
    if (isGC){
      if(resetNeeded){
        discoveryRounds = 0;
        resetNeeded = FALSE;
      }
      if(setAddrNeeded){
        localAddr = makeValid(generateLocalAddr(signal I2CDiscoverable.getGlobalAddress(), discoveryRounds));
        setAddrNeeded = FALSE;
      }
      if(masterAddr != I2C_INVALID_MASTER){
        post claimLocalAddrTask();
      }
    }else{
      switch(reg[0]){
        case I2C_CMD_ASSIGNED:
          //hooray, we got a local address!
          //signal startDone, quit waiting for timeout
          call Timer.stop();
          signal SplitControl.startDone();
          break;
        case I2C_CMD_CONFLICT:
          //wait for another round to start
          break;
        default:
          break;
      }
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
}
