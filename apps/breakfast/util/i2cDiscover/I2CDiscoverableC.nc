generic configuration I2CDiscoverableC(){
  provides interface SplitControl;
  provides interface I2CDiscoverable;
} implementation {
  components new Msp430UsciI2CB0C() as Msp430I2C0C;
  components new TimerMilliC();

  components new I2CDiscoverableRequesterP() as I2CDiscoverableP;
  I2CDiscoverableP.I2CPacket -> Msp430I2C0C;
  I2CDiscoverableP.I2CSlave -> Msp430I2C0C;
  I2CDiscoverableP.Resource -> Msp430I2C0C;
  I2CDiscoverableP.Timer -> TimerMilliC;
  Msp430I2C0C.Msp430UsciConfigure -> I2CDiscoverableP.Msp430UsciConfigure;
  
  I2CDiscoverable = I2CDiscoverableP;
  SplitControl = I2CDiscoverableP;
}
