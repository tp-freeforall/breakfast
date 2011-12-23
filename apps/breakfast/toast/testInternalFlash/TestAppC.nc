configuration TestAppC{
} implementation {
  components TestP;
  components new TimerMilliC();
  components SerialPrintfC;
  components MainC;
  //components new InternalFlashx2xxC(0x1000, 2) as InternalFlashC;
  components InternalFlashC;

  TestP.Boot -> MainC.Boot;
  TestP.Timer -> TimerMilliC;
  TestP.InternalFlash -> InternalFlashC;
}

