configuration TestAppC{
} implementation {
  components MainC;
  components TestP;
  components PlatformSerialC;
  components SerialPrintfC;

  components new I2CRegisterC(I2C_REGISTER_LENGTH);

  TestP.Boot -> MainC.Boot;
  TestP.I2CRegister -> I2CRegisterC;
  TestP.SplitControl -> I2CRegisterC;
  TestP.UartStream -> PlatformSerialC.UartStream;
  TestP.UartByte -> PlatformSerialC.UartByte;
  TestP.UartControl -> SerialPrintfC.StdControl;
}
