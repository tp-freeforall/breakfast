configuration TestAppC{
} implementation {
  components MainC;
  components new TimerMilliC();
  components TestP;
  components PlatformSerialC;
  components SerialPrintfC;
 
  TestP.Boot -> MainC;
  TestP.Timer -> TimerMilliC;
}
