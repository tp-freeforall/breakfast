configuration TestAppC{
} implementation {
  components TestP;
  components new TimerMilliC();
  components SerialPrintfC;
  components MainC;
  components InternalFlashC;  //standard (C/D)
  components InternalFlashAC; //segment A

  TestP.Boot -> MainC.Boot;
  TestP.Timer -> TimerMilliC;
  TestP.InternalFlash -> InternalFlashC;
  TestP.InternalFlashA -> InternalFlashAC;
}

