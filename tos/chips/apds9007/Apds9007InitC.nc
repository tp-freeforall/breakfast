configuration Apds9007InitC{
  provides interface Init;
} implementation {
  components PlatformApds9007C;
  components Apds9007InitP;

  Apds9007InitP.ShutdownPin -> PlatformApds9007C.ShutdownPin;
  Init = Apds9007InitP;
}
