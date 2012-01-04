configuration TestAppC{
} implementation {
  components MainC;
  components PlatformSerialC;
  components SerialPrintfC;
  components LedsC;

  components new I2CDiscovererC();
  components I2CPersistentStorageMasterC;
  components I2CTLVStorageMasterC;

  components TestP;

  TestP.Boot -> MainC;
  TestP.Leds -> LedsC;
  TestP.StdControl -> PlatformSerialC;
  TestP.UartStream -> PlatformSerialC;

  TestP.I2CDiscoverer -> I2CDiscovererC;
  TestP.I2CPersistentStorageMaster -> I2CPersistentStorageMasterC;
  TestP.SplitTLVStorage -> I2CTLVStorageMasterC;
  TestP.Set -> I2CTLVStorageMasterC;
  TestP.TLVUtils -> I2CTLVStorageMasterC;

}
