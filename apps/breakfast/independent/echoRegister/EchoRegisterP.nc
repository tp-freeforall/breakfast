generic module EchoRegisterP(uint8_t registerLen){
  uses interface I2CRegister;
} implementation {
  uint8_t buf[registerLen];

  async event uint8_t* I2CRegister.transactionStart(bool isWrite){
    return buf;
  }

  async event uint8_t I2CRegister.registerLen(){
    return registerLen;
  }

  async event void I2CRegister.transactionStop(uint8_t* reg, 
      uint8_t pos){ 
    uint8_t i;
    for (i = 0; i < registerLen; i++){
      printf("%c", reg[i]); 
    }
  }
}
