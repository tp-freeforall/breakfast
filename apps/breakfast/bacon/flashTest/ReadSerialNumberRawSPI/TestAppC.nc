configuration TestAppC{
} implementation {
  components MainC, LedsC;
  components TestP;
  components new TimerMilliC();
  components SerialPrintfC;
  
  components HplStm25pSpiC;
  components HplStm25pPinsC;

  TestP.Boot -> MainC.Boot;
  TestP.Leds -> LedsC;
  TestP.Timer -> TimerMilliC;

  TestP.SpiByte -> HplStm25pSpiC;
  TestP.SpiPacket -> HplStm25pSpiC;
  TestP.Resource -> HplStm25pSpiC;
  TestP.CSN -> HplStm25pPinsC;

  components new Msp430GpioC() as Power;
  components HplMsp430GeneralIOC;
  Power -> HplMsp430GeneralIOC.Port21;
  
  TestP.Power -> Power;
}
