configuration Apds9007InitC{
  provides interface Init;
} implementation {
  components PlatformApds9007C;
  components Apds9007InitP;

  Apds9007InitP.PowerPin -> PlatformApds9007C.PowerPin;
  Init = Apds9007InitP;
}
