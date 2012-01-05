//TODO: generic? client ID, start, numSegments
#include "InternalFlash.h"
configuration I2CPersistentStorageC{
} implementation {
  components I2CPersistentStorageP;

  components new InternalFlashx2xxC((uint16_t)IFLASH_D_START, 2);
  components I2CComSlaveMultiC;

  I2CPersistentStorageP.InternalFlash -> InternalFlashx2xxC;
  I2CPersistentStorageP.I2CComSlave -> I2CComSlaveMultiC.I2CComSlave[REGISTER_CLIENT_ID_STORAGE];
}
