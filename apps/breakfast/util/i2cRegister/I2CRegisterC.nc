//standard
generic configuration I2CRegisterC(uint8_t registerLength){
  provides interface I2CRegister;
  provides interface SplitControl;
} implementation {
  components new I2CRegisterP(registerLength);
  components new Msp430UsciI2CB0C();

  I2CRegisterP.Resource -> Msp430UsciI2CB0C.Resource;
  I2CRegisterP.I2CPacket -> Msp430UsciI2CB0C.I2CPacket;
  I2CRegisterP.I2CSlave -> Msp430UsciI2CB0C.I2CSlave;

  I2CRegister = I2CRegisterP;
  SplitControl = I2CRegisterP;

}
