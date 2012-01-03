generic configuration RegisterUserC(uint8_t clientId){
  provides interface RegisterUser;
} implementation {
  components new RegisterUserP(clientId);
  components new Msp430UsciI2CB0C() as I2CProvider;

  RegisterUser = RegisterUserP;
  RegisterUserP.I2CPacket -> I2CProvider.I2CPacket;
  RegisterUserP.Resource -> I2CProvider.Resource;
}
