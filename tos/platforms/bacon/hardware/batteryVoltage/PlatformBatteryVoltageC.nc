configuration PlatformBatteryVoltageC{
  provides interface AdcConfigure<const msp430adc12_channel_config_t *>;
  provides interface SplitControl;
  provides interface Init;
} implementation {
  components PlatformBatteryVoltageP;

  components HplMsp430GeneralIOC;
  components new Msp430GpioC();
  Msp430GpioC.HplGeneralIO -> HplMsp430GeneralIOC.PortJ2;
  PlatformBatteryVoltageP.EnablePin -> Msp430GpioC;

  AdcConfigure = PlatformBatteryVoltageP;
  SplitControl = PlatformBatteryVoltageP;
  Init = PlatformBatteryVoltageP;
} 
