#include "TLVStorage.h"

configuration TLVStorageC{
  provides interface TLVStorage;
  provides interface TLVUtils;
} implementation {
  components TLVStorageP;
  components TLVUtilsC;

  TLVStorageP.TLVUtils -> TLVUtilsC;

  TLVStorage = TLVStorageP;
  //TODO: wire init
  TLVUtils = TLVUtilsC;
}
