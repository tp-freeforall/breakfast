configuration PlatformCC1190C{
  provides interface Init;
  provides interface CC1190;
  provides interface StdControl;
} implementation{
  #ifdef HAS_CC1190
  components CC1190P;
  #else
  components NoCC1190P as CC1190P;
  #endif

  components HplMsp430GeneralIOC;
  
  components new Msp430GpioC() as HGMGpio;
  HGMGpio.HplGeneralIO -> HplMsp430GeneralIOC.PortJ0;
  CC1190P.HGMPin -> HGMGpio;

  components new Msp430GpioC() as LNA_ENGpio;
  LNA_ENGpio.HplGeneralIO -> HplMsp430GeneralIOC.Port35;
  CC1190P.LNA_ENPin -> LNA_ENGpio;

  components new Msp430GpioC() as PA_ENGpio;
  PA_ENGpio.HplGeneralIO -> HplMsp430GeneralIOC.Port34;
  CC1190P.PA_ENPin -> PA_ENGpio;

  components new Msp430GpioC() as PowerGpio;
  PowerGpio.HplGeneralIO -> HplMsp430GeneralIOC.Port36;
  CC1190P.PowerPin -> PowerGpio;
  
  Init = CC1190P;
  CC1190 = CC1190P;
  StdControl = CC1190P;

}
