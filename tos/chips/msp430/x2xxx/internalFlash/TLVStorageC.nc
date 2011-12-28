#include "TLVStorage.h"

configuration TLVStorageC{
  provides interface TLVStorage;
} implementation {
  components TLVStorageP;
  TLVStorage = TLVStorageP;
  //TODO: wire init
}
