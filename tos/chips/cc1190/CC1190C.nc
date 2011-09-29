configuration CC1190C{
  provides interface StdControl;
  provides interface Init;
  provides interface CC1190;
} implementation {
  components PlatformCC1190C;

  StdControl = PlatformCC1190C;
  Init = PlatformCC1190C;
  CC1190 = PlatformCC1190C;

}
