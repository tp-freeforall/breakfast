configuration TestAppC{
} implementation {
  components MainC;
  components TestP;
  components PlatformSerialC;
  components SerialPrintfC;

  components new I2CDiscoverableC();
  components new I2CDiscovererC();

  TestP.Boot -> MainC.Boot;
  TestP.I2CDiscoverable -> I2CDiscoverableC;
  TestP.UartStream -> PlatformSerialC.UartStream;
  TestP.UartByte -> PlatformSerialC.UartByte;
  TestP.UartControl -> SerialPrintfC.StdControl;

  TestP.I2CDiscoverer -> I2CDiscovererC;
  
}
