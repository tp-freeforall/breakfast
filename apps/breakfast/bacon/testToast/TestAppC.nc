configuration TestAppC{
} implementation {
  components MainC;
  components new I2CDiscovererC();
  components PlatformSerialC;
  components SerialPrintfC;
  components I2CPersistentStorageMasterC;
  components TestP;
  components LedsC;

  TestP.Boot -> MainC;
  TestP.Leds -> LedsC;

  TestP.I2CPersistentStorageMaster -> I2CPersistentStorageMasterC;
  TestP.I2CDiscoverer -> I2CDiscovererC;

  TestP.StdControl -> PlatformSerialC;
  TestP.UartStream -> PlatformSerialC;
}
