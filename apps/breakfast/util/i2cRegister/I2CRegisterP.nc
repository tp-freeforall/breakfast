generic module I2CRegisterP(uint8_t registerLength){
  provides interface I2CRegister;
  provides interface SplitControl;
  uses interface Resource;
  uses interface I2CSlave;
  uses interface I2CPacket<TI2CBasicAddr>;
  //TODO: i2cconfigure?
} implementation {
  uint8_t pos;
  uint8_t _reg[registerLength];
  uint8_t* reg = _reg;
  uint8_t transCount;
  bool isGC;
  uint8_t gcCmd;

  async command error_t I2CRegister.pause(){
    printf("%s: \n\r", __FUNCTION__);
  }

  async command error_t I2CRegister.unPause(){
    printf("%s: \n\r", __FUNCTION__);
  }

  command void I2CRegister.setOwnAddress(uint16_t addr){
    printf("%s: %c\n\r", __FUNCTION__, addr);
    call I2CSlave.setOwnAddress(addr);
  }
  
  command error_t SplitControl.start(){
    return call Resource.request();
  }

  task void stopDone(){
    signal SplitControl.stopDone(SUCCESS);
  }

  command error_t SplitControl.stop(){
    error_t ret = call Resource.release();
    printf("%s: \n\r", __FUNCTION__);
    if (ret == SUCCESS){
      post stopDone();
    }
    return ret;
  }

  event void Resource.granted(){
    signal SplitControl.startDone(SUCCESS);
  }

  async event void I2CPacket.readDone(error_t error, uint16_t addr, uint8_t length, uint8_t* data){
  }

  async event void I2CPacket.writeDone(error_t error, uint16_t addr, uint8_t length, uint8_t* data){
  }
  
  //yeah, this all has to be atomic
  task void receive(){
    atomic{
      uint8_t data = call I2CSlave.slaveReceive();
      printf("RX %x", data);
      if (isGC && transCount < 2) {
        //General call: 0th byte is reset/setaddr/announce. standard
        //behavior begins after this.
        if(transCount == 0){
          printf(" -> gcCmd\n\r");
          gcCmd = data;
        }else{
          printf(" -> pos\n\r");
          pos = data;
        }
      } else {
        if(transCount == 0){
          printf(" -> pos\n\r");
          pos = data;
        }else {
          printf(" -> reg[%x]\n\r", pos%registerLength);
          reg[pos%registerLength] = data;
          pos++;
        }
      }
      transCount++;
    }
  }

  async event bool I2CSlave.slaveReceiveRequested(){
    post receive();
    return TRUE;
  }

  task void transmit(){
    transCount++;
    call I2CSlave.slaveTransmit(0xff);
  }

  async event bool I2CSlave.slaveTransmitRequested(){
    post transmit();
    return TRUE;
  }
  
  async event void I2CSlave.slaveStart(bool generalCall){
    signal I2CRegister.transactionStart(generalCall);
    isGC = generalCall;
    transCount = 0;
  }

  async event void I2CSlave.slaveStop(){
    printf("%s: \n\r", __FUNCTION__);
    signal I2CRegister.transactionStop(reg, registerLength, gcCmd);
  }

}
