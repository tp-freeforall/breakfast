generic configuration I2CDiscovererC(){
  provides interface I2CDiscoverer;
} implementation {
  components new Msp430UsciI2CB0C() as Msp430I2C0C;
  components new TimerMilliC();
  components new QueueC(discoverer_register_union_t*, I2C_DISCOVERY_POOL_SIZE);
  components new PoolC(discoverer_register_union_t, I2C_DISCOVERY_POOL_SIZE);

  components new I2CDiscovererP() as I2CDiscovererP;
  I2CDiscovererP.I2CPacket -> Msp430I2C0C;
  I2CDiscovererP.I2CSlave -> Msp430I2C0C;
  I2CDiscovererP.Resource -> Msp430I2C0C;
  I2CDiscovererP.Timer -> TimerMilliC;
  I2CDiscovererP.Queue -> QueueC;
  I2CDiscovererP.Pool -> PoolC;
  Msp430I2C0C.Msp430UsciConfigure -> I2CDiscovererP.Msp430UsciConfigure;
  
  I2CDiscoverer = I2CDiscovererP;
}
