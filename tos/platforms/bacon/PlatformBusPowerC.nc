configuration PlatformBusPowerC{
  provides interface Init;
} implementation {
  components PlatformBusPowerP;
  components BusPowerC;

  Init = PlatformBusPowerP;

  BusPowerC.SubSplitControl -> PlatformBusPowerP;
  components HplMsp430GeneralIOC;
  components new Msp430GpioC() as EnablePin;
  EnablePin.HplGeneralIO -> HplMsp430GeneralIOC.Port37;
  PlatformBusPowerP.EnablePin -> EnablePin;
}
