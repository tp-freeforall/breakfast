configuration TestAppC{
} implementation {
  components MainC;
  components LedsC;
  components SerialPrintfC;
  components TestP;
  components PlatformSerialC;
  components ExternalPhotoC;
  components new TimerMilliC();

  components Apds9007C;
  
  TestP.Boot -> MainC.Boot;
  TestP.Leds -> LedsC;
  TestP.UartControl -> PlatformSerialC.StdControl;
  TestP.UartStream -> PlatformSerialC.UartStream;
  TestP.Read -> ExternalPhotoC.Read;
  TestP.Timer -> TimerMilliC;
  TestP.ReadInternal -> Apds9007C.Read;
  TestP.InternalControl -> Apds9007C.SplitControl;
}
