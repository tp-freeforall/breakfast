generic configuration I2CDiscoverableC(uint8_t globalAddrLength){
  provides interface SplitControl;
  provides interface I2CDiscoverable;
  //TODO: provide I2CDiscoverable
  //      - command getLocalAddress
  //      - event getGlobalAddress
} implementation {
  components new Msp430UsciI2CB0C() as Msp430I2C0C;
  components new TimerMilliC();

  components new I2CDiscoverableRequesterP(globalAddrLength) as I2CDiscoverableP;
  I2CDiscoverableP.I2CPacket -> Msp430I2C0C;
  I2CDiscoverableP.I2CSlave -> Msp430I2C0C;
  I2CDiscoverableP.Resource -> Msp430I2C0C;
  I2CDiscoverableP.Timer -> TimerMilliC;
  
  I2CDiscoverable = I2CDiscoverableP;
  SplitControl = I2CDiscoverableP;
}
