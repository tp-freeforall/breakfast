configuration TestAppC{
} implementation {
  components MainC;
  components TestP;
  components new TimerMilliC();
  components LedsC;
  components SerialPrintfC;

  TestP.Boot -> MainC;
  TestP.Leds -> LedsC;
  TestP.Timer -> TimerMilliC;
}
