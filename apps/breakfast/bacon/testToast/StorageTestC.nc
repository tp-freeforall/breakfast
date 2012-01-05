#include "TestToast.h"
configuration StorageTestC{
  uses interface UartStream;
  uses interface Get<test_state_t*>;
  provides interface Get<const char*> as GetDesc;
} implementation {
  components StorageTestP;
  components I2CPersistentStorageMasterC;
  
  StorageTestP.I2CPersistentStorageMaster -> I2CPersistentStorageMasterC;

  StorageTestP.UartStream = UartStream;
  StorageTestP.Get = Get;
  GetDesc = StorageTestP.GetDesc;
}
