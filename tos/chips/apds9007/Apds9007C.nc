configuration Apds9007C{
  provides interface Resource;
  provides interface Read<uint16_t>;
  provides interface ReadStream<uint16_t>;
  provides interface ReadNow<uint16_t>;
  provides interface SplitControl;
} implementation {
  //TODO: DC-- to be completely correct, this should pass the read
  //  interfaces through, and return errors as appropriate if the
  //  sensor's off
  components Apds9007P, PlatformApds9007C;

  components new AdcReadClientC();
  Read = AdcReadClientC;

  components new AdcReadStreamClientC();
  ReadStream = AdcReadStreamClientC;

  components new AdcReadNowClientC();
  Resource = AdcReadNowClientC;
  ReadNow = AdcReadNowClientC;

  SplitControl = Apds9007P;

  AdcReadClientC.AdcConfigure -> PlatformApds9007C.AdcConfigure;
  AdcReadStreamClientC.AdcConfigure -> PlatformApds9007C.AdcConfigure;
  AdcReadNowClientC.AdcConfigure -> PlatformApds9007C.AdcConfigure; 
  
  Apds9007P.ShutdownPin -> PlatformApds9007C.ShutdownPin;
}
