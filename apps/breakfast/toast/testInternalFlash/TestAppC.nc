configuration TestAppC{
} implementation {
  components TestP;
  components new TimerMilliC();
  components SerialPrintfC;
  components MainC;
  components InternalFlashC;

  TestP.Boot -> MainC.Boot;
  TestP.Timer -> TimerMilliC;
  TestP.InternalFlash -> InternalFlashC;
}

