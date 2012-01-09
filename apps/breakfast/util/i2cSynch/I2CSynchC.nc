#include "I2CSynch.h"
configuration I2CSynchC{
  
} implementation {
  components I2CSynchP;
  components I2CComSlaveMultiC;
  components LocalTime32khzC;

  I2CSynchP.I2CComSlave -> I2CComSlaveMultiC.I2CComSlave[I2C_COM_CLIENT_ID_SYNCH];
  I2CSynchP.LocalTime -> LocalTime32khzC;
}
