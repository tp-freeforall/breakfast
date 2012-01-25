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
  TestP.Resource -> I2CDiscoverableC.Resource;
  TestP.UartStream -> PlatformSerialC.UartStream;
  TestP.UartByte -> PlatformSerialC.UartByte;
  TestP.UartControl -> SerialPrintfC.StdControl;

  TestP.I2CDiscoverer -> I2CDiscovererC;
  TestP.I2CSlave -> I2CDiscoverableC.I2CSlave;
  TestP.I2CPacket -> I2CDiscoverableC.I2CPacket;;
  
}
