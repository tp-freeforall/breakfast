#include "I2CTLVStorage.h"
configuration I2CTLVStorageC{
} implementation {
  components I2CTLVStorageP;
  components TLVStorageC;
  components I2CComSlaveMultiC;

  I2CTLVStorageP.TLVStorage -> TLVStorageC;
  I2CTLVStorageP.TLVUtils -> TLVStorageC;
  I2CTLVStorageP.I2CComSlave ->
    I2CComSlaveMultiC.I2CComSlave[I2C_COM_CLIENT_ID_TLV_STORAGE];
}
