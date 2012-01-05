#include "I2CCom.h"
configuration I2CComSlaveMultiC{
  provides interface I2CComSlave[uint8_t clientId];
  provides interface SplitControl;
  provides interface I2CDiscoverable;
} implementation {
  components I2CComSlaveMultiP;
  components new I2CDiscoverableC() as I2CProvider;
  
  I2CComSlaveMultiP.I2CSlave -> I2CProvider.I2CSlave;
  I2CComSlaveMultiP.Resource -> I2CProvider.Resource;

  I2CComSlave = I2CComSlaveMultiP;
  SplitControl = I2CComSlaveMultiP;
  I2CDiscoverable = I2CProvider.I2CDiscoverable;


}
