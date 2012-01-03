#include "I2CPersistentStorage.h"

configuration I2CPersistentStorageMasterC{
  provides interface I2CPersistentStorageMaster;
} implementation {
  components new I2CRegisterUserC(REGISTER_CLIENT_ID_STORAGE);
  components I2CPersistentStorageMasterP;

  I2CPersistentStorageMasterP.I2CRegisterUser -> I2CRegisterUserC;

  I2CPersistentStorageMaster = I2CPersistentStorageMasterP;
}
