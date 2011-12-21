#define REGISTER_CLIENT_ID_ECHO 0x01
generic configuration EchoRegisterC(uint8_t registerLen) {
} implementation {
  components I2CMultiRegisterC;
  components new EchoRegisterP(registerLen);

  EchoRegisterP.I2CRegister -> I2CMultiRegisterC.I2CRegister[REGISTER_CLIENT_ID_ECHO];
}
