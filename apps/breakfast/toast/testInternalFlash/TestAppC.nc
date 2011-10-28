configuration TestAppC{
} implementation {
  components TestP;
  components new TimerMilliC();
  components SerialPrintfC;
  components MainC;

  TestP.Boot -> MainC.Boot;
  TestP.Timer -> TimerMilliC;
}

