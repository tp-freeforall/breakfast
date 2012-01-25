generic configuration I2CDiscoverableC(){
  provides interface I2CDiscoverable;
  provides interface Resource;
  provides interface I2CSlave;
  provides interface I2CPacket<TI2CBasicAddr>;
} implementation {
  components new Msp430UsciI2CB0C() as Msp430I2C0C;
  components new TimerMilliC() as RandomizeTimer;
  components RandomC;

  components new I2CDiscoverableRequesterP() as I2CDiscoverableP;
  I2CDiscoverableP.SubI2CPacket -> Msp430I2C0C;
  I2CDiscoverableP.SubI2CSlave -> Msp430I2C0C;
  I2CDiscoverableP.SubResource -> Msp430I2C0C;
  I2CDiscoverableP.RandomizeTimer -> RandomizeTimer;
  I2CDiscoverableP.Random -> RandomC;
  I2CDiscoverableP.RandomInit -> RandomC.SeedInit;
  Msp430I2C0C.Msp430UsciConfigure -> I2CDiscoverableP.Msp430UsciConfigure;
  
  I2CDiscoverable = I2CDiscoverableP;
  Resource = I2CDiscoverableP.Resource;
  I2CSlave = I2CDiscoverableP.I2CSlave;
  I2CPacket = I2CDiscoverableP.I2CPacket;
}
