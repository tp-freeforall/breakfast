configuration BatteryVoltageC{
  provides interface Resource;
  provides interface Read<uint16_t>;
  provides interface ReadStream<uint16_t>;
  provides interface ReadNow<uint16_t>;
  provides interface SplitControl;
} implementation {
  //TODO: DC-- to be completely correct, this should pass the read
  //  interfaces through, and return errors as appropriate if the
  //  sensor's off
  components PlatformBatteryVoltageC;

  components new AdcReadClientC();
  Read = AdcReadClientC;

  components new AdcReadStreamClientC();
  ReadStream = AdcReadStreamClientC;

  components new AdcReadNowClientC();
  Resource = AdcReadNowClientC;
  ReadNow = AdcReadNowClientC;

  SplitControl = PlatformBatteryVoltageC.SplitControl;

  AdcReadClientC.AdcConfigure -> PlatformBatteryVoltageC.AdcConfigure;
  AdcReadStreamClientC.AdcConfigure -> PlatformBatteryVoltageC.AdcConfigure;
  AdcReadNowClientC.AdcConfigure -> PlatformBatteryVoltageC.AdcConfigure; 
}

