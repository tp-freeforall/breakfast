configuration TestAppC{
} implementation {
  components MainC;
  components TestP;

  components new TimerMilliC();

  TestP.Boot -> MainC;
  TestP.Timer -> TimerMilliC;
}
