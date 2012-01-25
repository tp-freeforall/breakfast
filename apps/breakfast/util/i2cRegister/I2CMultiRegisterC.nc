configuration I2CMultiRegisterC{
  provides interface I2CRegister[uint8_t clientId];
  provides interface SplitControl;
  //TODO: this really shouldn't be here, but I can't figure out how to
  //  make this modular.
  provides interface I2CDiscoverable;
} implementation {
  components new I2CMultiRegisterP();
  components new I2CDiscoverableC() as I2CProvider;
  
  I2CMultiRegisterP.I2CSlave -> I2CProvider.I2CSlave;
  I2CMultiRegisterP.Resource -> I2CProvider.Resource;

  I2CRegister = I2CMultiRegisterP;
  SplitControl = I2CMultiRegisterP;
  I2CDiscoverable = I2CProvider.I2CDiscoverable;

}
