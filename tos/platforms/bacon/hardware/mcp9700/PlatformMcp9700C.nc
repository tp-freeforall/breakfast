configuration PlatformMcp9700C{
  provides interface SplitControl;
  provides interface AdcConfigure<const msp430adc12_channel_config_t *>;
  provides interface Init;
} implementation {
  components PlatformMcp9700P;

  components HplMsp430GeneralIOC;
  components new Msp430GpioC();
  Msp430GpioC.HplGeneralIO -> HplMsp430GeneralIOC.PortJ1;

  PlatformMcp9700P.PowerPin -> Msp430GpioC;

  Init = PlatformMcp9700P;
  SplitControl = PlatformMcp9700P;
  AdcConfigure = PlatformMcp9700P;
} 
