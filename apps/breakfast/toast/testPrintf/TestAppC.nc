configuration TestAppC{
} implementation{
  components MainC;
  components TestP;
  components new TimerMilliC();

  components SerialPrintfC;
  components PlatformSerialC;

  TestP.Boot -> MainC.Boot;
  TestP.StdControl -> SerialPrintfC;
  TestP.Timer -> TimerMilliC;
  TestP.UartStream -> PlatformSerialC;
}
