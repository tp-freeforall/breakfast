configuration TestAppC{
} implementation {
  components MainC;
  components PlatformSerialC;
  components SerialPrintfC;
  components TestP;
  components GlobalIDC;

  TestP.Boot -> MainC;
  TestP.UartStream -> PlatformSerialC;
  TestP.StdControl -> PlatformSerialC;
  TestP.GlobalID -> GlobalIDC;
}
