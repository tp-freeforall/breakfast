#include "I2CTLVStorage.h"
configuration I2CTLVStorageC{
} implementation {
  components I2CTLVStorageP;
  components TLVStorageC;
  components I2CMultiRegisterC;

  I2CTLVStorageP.TLVStorage -> TLVStorageC;
  I2CTLVStorageP.TLVUtils -> TLVStorageC;
  I2CTLVStorageP.I2CRegister ->
    I2CMultiRegisterC.I2CRegister[REGISTER_CLIENT_ID_TLV_STORAGE];
}
