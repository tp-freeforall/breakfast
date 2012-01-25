generic configuration I2CRegisterUserC(uint8_t clientId){
  provides interface I2CRegisterUser;
} implementation {
  components new I2CRegisterUserP(clientId);
  components new Msp430UsciI2CB0C() as I2CProvider;

  I2CRegisterUser = I2CRegisterUserP;
  I2CRegisterUserP.I2CPacket -> I2CProvider.I2CPacket;
  I2CRegisterUserP.Resource -> I2CProvider.Resource;
}
