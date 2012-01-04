#include "TLVStorage.h"
//Interface that handles reading/writing "tag-length-value" entries in
//information memory according to msp430 user guide.
interface TLVStorage{
  //read segment A TLV structure into tlvs
  command error_t loadTLVStorage(void* tlvs);

  //persist TLV structure (to internal flash)
  command error_t persistTLVStorage(void* tlvs);
}
