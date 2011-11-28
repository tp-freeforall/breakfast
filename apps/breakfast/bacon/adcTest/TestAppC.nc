configuration TestAppC{
} implementation {
  components MainC;
  components LedsC;
  components SerialPrintfC;
  components TestP;
  components PlatformSerialC;
  components new TimerMilliC();
  
  TestP.Boot -> MainC.Boot;
  TestP.Leds -> LedsC;
  TestP.UartControl -> PlatformSerialC.StdControl;
  TestP.UartStream -> PlatformSerialC.UartStream;
  TestP.Timer -> TimerMilliC;
}
