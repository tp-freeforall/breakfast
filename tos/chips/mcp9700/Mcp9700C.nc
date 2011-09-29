configuration Mcp9700C{
  provides interface Resource;
  provides interface Read<uint16_t>;
  provides interface ReadStream<uint16_t>;
  provides interface ReadNow<uint16_t>;
  provides interface SplitControl;
} implementation {
  //TODO: DC-- to be completely correct, this should pass the read
  //  interfaces through, and return errors as appropriate if the
  //  sensor's off
  components PlatformMcp9700C;

  components new AdcReadClientC();
  Read = AdcReadClientC;

  components new AdcReadStreamClientC();
  ReadStream = AdcReadStreamClientC;

  components new AdcReadNowClientC();
  Resource = AdcReadNowClientC;
  ReadNow = AdcReadNowClientC;

  SplitControl = PlatformMcp9700C.SplitControl;

  AdcReadClientC.AdcConfigure -> PlatformMcp9700C.AdcConfigure;
  AdcReadStreamClientC.AdcConfigure -> PlatformMcp9700C.AdcConfigure;
  AdcReadNowClientC.AdcConfigure -> PlatformMcp9700C.AdcConfigure; 
}
