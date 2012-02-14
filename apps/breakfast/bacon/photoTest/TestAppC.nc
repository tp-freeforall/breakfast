configuration TestAppC{
} implementation {
  components MainC;
  components LedsC;
  components SerialPrintfC;
  components TestP;
  components PlatformSerialC;
  components new TimerMilliC();
  
  components Apds9007C as Sensor;
  
  TestP.Boot -> MainC.Boot;
  TestP.Leds -> LedsC;
  TestP.UartControl -> PlatformSerialC.StdControl;
  TestP.UartStream -> PlatformSerialC.UartStream;
  TestP.Timer -> TimerMilliC;
  TestP.Read -> Sensor;
  TestP.SplitControl -> Sensor;
}
