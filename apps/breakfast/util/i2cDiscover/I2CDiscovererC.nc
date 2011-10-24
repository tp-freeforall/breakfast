generic configuration I2CDiscovererC(){
  provides interface SplitControl;
  provides interface I2CDiscoverer;
} implementation {
  components new Msp430UsciI2CB0C() as Msp430I2C0C;
  components new TimerMilliC();

  components new I2CDiscovererP() as I2CDiscovererP;
  I2CDiscovererP.I2CPacket -> Msp430I2C0C;
  I2CDiscovererP.I2CSlave -> Msp430I2C0C;
  I2CDiscovererP.Resource -> Msp430I2C0C;
  I2CDiscovererP.Timer -> TimerMilliC;
  
  I2CDiscoverer = I2CDiscovererP;
  SplitControl  = I2CDiscovererP;
}
