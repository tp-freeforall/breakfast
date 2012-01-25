#include "I2CPersistentStorage.h"

configuration I2CPersistentStorageMasterC{
  provides interface I2CPersistentStorageMaster;
} implementation {
  components new I2CComMasterC(I2C_COM_CLIENT_ID_STORAGE);
  components I2CPersistentStorageMasterP;

  I2CPersistentStorageMasterP.I2CComMaster -> I2CComMasterC;

  I2CPersistentStorageMaster = I2CPersistentStorageMasterP;
}
