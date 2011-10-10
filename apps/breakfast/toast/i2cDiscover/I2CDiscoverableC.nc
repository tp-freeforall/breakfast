generic configuration I2CDiscoverableC(){
  provides interface SplitControl;
  provides interface I2CDiscoverable;
  //TODO: provide I2CDiscoverable
  //      - command getLocalAddress
  //      - event getGlobalAddress
} implementation {
  components new Msp430I2C0C();

  components new I2CDiscoverableP();
  I2CDiscoverableP.I2CPacket -> Msp430I2C0C;
  I2CDiscoverableP.I2CSlave -> Msp430I2C0C;
  
  I2CDiscoverable = I2CDiscoverableP;
  SplitControl = I2CDiscoverableP;
}
