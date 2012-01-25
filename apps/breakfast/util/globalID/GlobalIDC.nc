#include "GlobalID.h"

configuration GlobalIDC{
  provides interface GlobalID;
} implementation {
  components GlobalIDP;
  components TLVStorageC;

  GlobalIDP.TLVStorage -> TLVStorageC;
  GlobalIDP.TLVUtils -> TLVStorageC;

  GlobalID = GlobalIDP;
}
