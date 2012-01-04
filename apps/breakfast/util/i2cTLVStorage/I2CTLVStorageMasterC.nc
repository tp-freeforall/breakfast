#include "I2CTLVStorage.h"
//wrap storage commands with I2C behavior
//to preserve storage interface, use Set to determine slave addr
configuration I2CTLVStorageMasterC{
  provides interface SplitTLVStorage;
  provides interface TLVUtils;
  provides interface Set<uint16_t>;
} implementation {
  components I2CTLVStorageMasterP;
  components TLVUtilsC;
  
  components new I2CRegisterUserC(REGISTER_CLIENT_ID_TLV_STORAGE);

  I2CTLVStorageMasterP.I2CRegisterUser -> I2CRegisterUserC;
  I2CTLVStorageMasterP.TLVUtils -> TLVUtilsC;

  SplitTLVStorage = I2CTLVStorageMasterP;
  Set = I2CTLVStorageMasterP;

  TLVUtils = TLVUtilsC;
}
