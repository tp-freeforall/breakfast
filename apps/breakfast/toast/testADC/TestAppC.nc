configuration TestAppC{
} implementation {
  components MainC;
  components TestP;
  components new Msp430Adc12ClientAutoRVGC() as ADCClient;
  components new TimerMilliC();
  components SerialPrintfC;
  
  ADCClient.AdcConfigure -> TestP;

  TestP.Boot -> MainC;
  TestP.Resource -> ADCClient.Resource;
  TestP.Msp430Adc12SingleChannel -> ADCClient.Msp430Adc12SingleChannel;
  TestP.Timer -> TimerMilliC;
  
}
