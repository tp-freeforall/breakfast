configuration TestAppC{
} implementation {
  components MainC;
  components SerialPrintfC;
  components PlatformSerialC;
  components TestP;

  components I2CPersistentStorageC;
  components I2CMultiRegisterC;
  
  components new I2CDiscovererC();
  components new Msp430UsciI2CB0C();

  TestP.UartControl -> PlatformSerialC;
  TestP.UartStream -> PlatformSerialC;

  TestP.SplitControl -> I2CMultiRegisterC;
  TestP.I2CDiscoverable -> I2CMultiRegisterC;

  TestP.I2CPacket -> Msp430UsciI2CB0C.I2CPacket;
  TestP.Resource -> Msp430UsciI2CB0C.Resource;

  TestP.I2CDiscoverer -> I2CDiscovererC;
  TestP.Boot -> MainC;
}
