module I2CDiscoverableRegisterP{
  uses interface I2CRegister;
  uses interface I2CPacket<TI2CBasicAddr>;
  uses interface SplitControl as RegisterSplitControl;
  uses interface Resource as MasterResource;
  provides interface SplitControl as DiscoverableSplitControl;
  provides interface I2CDiscoverable;
} implementation {
  enum{
    S_INIT,
    S_IDLE,
    S_IDLE_START,
    S_HEAD_FOUND,
    S_HEAD_FOUND_START,
    S_CLAIM_SWITCH,
    S_CLAIM_READY,
    S_CLAIMING,
    S_READING_LOCAL,
    S_ASSIGNED,
    S_ERROR,
    S_STARTING_REGISTER,
  };
  uint8_t state = S_INIT;
  uint16_t localAddr = I2C_DISCOVERABLE_UNASSIGNED;
  uint16_t masterAddr = I2C_INVALID_MASTER;

  void setState(uint8_t s){
    atomic state = s;
  }

  command error_t DiscoverableSplitControl.start(){
    error_t ret;
    if(checkState(S_INIT)){
      ret = call RegisterSplitControl.start() 
      if (ret == SUCCESS){
        setState(S_STARTING_REGISTER);
      }else {
        setState(S_ERROR);
      }
      return ret;
    }else {
      return FAIL;
    }
  }

  event void RegisterSplitControl.startDone(error_t err){
    printf("%s: \n\r", __FUNCTION__);
    if (err == SUCCESS){
    }
  }

  async event void I2CRegister.transactionStart(bool generalCall){
    printf("%s: \n\r", __FUNCTION__);
    switch(state){
      case S_IDLE:
        setState(S_IDLE_START);
        break;
      case S_HEAD_FOUND:
        setState(S_HEAD_FOUND_START);
        break;
      default:
        setState(S_ERROR);
        break;
    }
  }

  async event uint8_t* I2CRegister.transactionStop(uint8_t* reg, uint8_t len, uint8_t gcCmd){
    printf("%s: \n\r", __FUNCTION__);
    switch(state){
      case S_IDLE_START:
        if(gcCmd & 0x01){
          masterAddr = gcCmd >> 1;
          setState(S_HEAD_FOUND);
        } else {
          printf("Expected 1 in LSB, got 0\n\r");
          setState(S_ERROR);
        }
        break;
      default:
        setState(S_ERROR);
        break;
    }
  }

  
  command uint16_t I2CDiscoverable.getLocalAddr(){
    printf("%s: \n\r", __FUNCTION__);
    return localAddr;
  }
}
