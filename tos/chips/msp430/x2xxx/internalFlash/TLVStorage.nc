#include "TLVStorage.h"

//Interface that handles reading/writing "tag-length-value" entries in
//information memory according to msp430 user guide.
interface TLVStorage{
  //read segment A TLV structure into tlvs
  command error_t loadTLVStorage(void* tlvs);

  //find first available space after offset, write a new tlv entry into it, and
  //return the offset where the new tlv entry begins.
  command uint8_t addEntry(uint8_t tag, uint8_t len, tlv_entry_t* entry, void* tlvs, uint8_t offset);

  //delete the entry at offset and free space. Returns FAIL if offset
  //does not point to the start of an entry.
  command error_t deleteEntry(uint8_t offset, void* tlvs);

  //locate an entry in the tlv storage: return the first offset
  //at or after startOffset where tag is found. Write it into entry.
  //returns 0 if it's not found.
  command uint8_t findEntry(uint8_t tag, uint8_t startOffset, 
    tlv_entry_t** entry, void* tlvs);

  //persist TLV structure (to internal flash)
  command error_t persistTLVStorage(void* tlvs);
}
