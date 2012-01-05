#include "TestToast.h"
configuration TLVStorageTestC{
  uses interface UartStream;
  uses interface Get<test_state_t*>;
} implementation {
  components TVLStorageTestP;
  components I2CTLVStorageMasterC;

  TLVStorageTestP.SplitTLVStorage -> I2CTLVStorageMasterC;
  TLVStorageTestP.Set -> I2CTLVStorageMasterC;
  TLVStorageTestP.TLVUtils -> I2CTLVStorageMasterC;

  TLVStorageTestP.UartStream = UartStream;
  TLVStorageTestP.Get = Get;
}
