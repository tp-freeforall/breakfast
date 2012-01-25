configuration TestAppC{
} implementation {
  components MainC;
  components PlatformSerialC;
  components SerialPrintfC;
  components TestP;
  components TLVStorageC;

  TestP.Boot -> MainC;
  TestP.UartStream -> PlatformSerialC;
  TestP.StdControl -> PlatformSerialC;
  TestP.TLVStorage -> TLVStorageC;
  TestP.TLVUtils -> TLVStorageC;
}
