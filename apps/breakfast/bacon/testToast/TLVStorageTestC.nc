#include "TestToast.h"
configuration TLVStorageTestC{
  uses interface UartStream;
  uses interface Get<test_state_t*>;
  provides interface Get<const char*> as GetDesc;
} implementation {
  components TLVStorageTestP;
  components I2CTLVStorageMasterC;

  TLVStorageTestP.I2CTLVStorageMaster -> I2CTLVStorageMasterC;
  TLVStorageTestP.TLVUtils -> I2CTLVStorageMasterC;

  TLVStorageTestP.UartStream = UartStream;
  TLVStorageTestP.Get = Get;
  GetDesc = TLVStorageTestP.GetDesc;
}
