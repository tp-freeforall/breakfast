configuration TestAppC{
} implementation {
  components MainC;
  components PlatformSerialC;
  components TestP;
  components new TimerMilliC();

  TestP.Boot -> MainC;
  TestP.UartStream -> PlatformSerialC;
  TestP.UartByte -> PlatformSerialC;
  TestP.StdControl -> PlatformSerialC;
  TestP.Timer -> TimerMilliC;
}
