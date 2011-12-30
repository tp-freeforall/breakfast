#include "TLVStorage.h"
#include "InternalFlash.h"

module TLVStorageP{
  provides interface TLVStorage;
  provides interface Init;
} implementation {

  int16_t computeChecksum(void* tlvs){
    int16_t* wa = (int16_t*) tlvs;
    int16_t crc = 0x00;
    uint8_t i;
    for (i = 1; i < IFLASH_SEGMENT_SIZE / sizeof(uint16_t); i++){
      crc ^= wa[i];
    }
    return crc;
  }
  bool verifyChecksum(void* tlvs){
    int16_t* wa = (int16_t*) tlvs;
    return 0 == (wa[0] + computeChecksum(tlvs));
  }

  command error_t TLVStorage.loadTLVStorage(void* tlvs){
    uint8_t* ba = (uint8_t*) tlvs;
    version_entry_t e;
    memcpy(tlvs, IFLASH_A_START, IFLASH_SEGMENT_SIZE);
    if (!verifyChecksum(tlvs)){
      memset(tlvs, 0xff, IFLASH_SEGMENT_SIZE);
      e.version = 0;
      ba[TLV_CHECKSUM_LENGTH] = TAG_EMPTY;
      ba[TLV_CHECKSUM_LENGTH+1] = 60;
      call TLVStorage.addEntry(TAG_VERSION, 2, (tlv_entry_t*)&e, tlvs,0);
      //TODO: better return code? 
      return SUCCESS;
    }
    return SUCCESS;
  }
  
  //find first available space if offset is 0 OR try to use exactly
  //offset if it's not 0, write a new tlv entry into it, and
  //return the offset where the new tlv entry begins. Return 0 if it
  //couldn't be written.
  command uint8_t TLVStorage.addEntry(uint8_t tag, uint8_t len, tlv_entry_t* entry, void* tlvs, uint8_t offset){
    uint8_t* ba = (uint8_t*) tlvs;
    uint16_t index = TLV_CHECKSUM_LENGTH;
    uint16_t endIndex;
    uint8_t emptyLen;
    tlv_entry_t* e;
    entry->tag = tag;
    entry->len = len;
    //if it's 0: use as-is
    //if it's >0:
    //  - find empty that completely overlaps offset+len+2
    //  - cut it up so that an empty starts at offset
    //  - leave index set to offset
    if(offset > 0){
      //when this loop ends, index will either be > offset or sitting
      //on the start of a TAG_EMPTY which is large enough to fit it.
      while (index <= offset){
        e = (tlv_entry_t*)&ba[index];
        endIndex = index + 2 + len;
        if (e->tag == TAG_EMPTY && 
          offset >= index && 
          (endIndex <= e->len + 2 + index)){
          //OK, it fits here. 
          //if there's space before it, cut TAG_EMPTY up so that
          //offset is on a TAG_EMPTY boundary, then update index
          //appropriately
          if (offset > index){
            ba[offset] = TAG_EMPTY;
            ba[offset+1] = (endIndex - offset - 2 );
            e-> len = (offset - index - 2);
            index = offset;
            break;
          }
        }
        index = index + 2 + e->len;
      }
      //offset didn't work, so don't try to insert it.
      if (index > offset){
        return 0;
      }
    }else {
      index = TLV_CHECKSUM_LENGTH;
    }
    
    //seek to next available TAG_EMPTY and put it in
    while (index < IFLASH_SEGMENT_SIZE){
      e = (tlv_entry_t*) &ba[index];
      if(e->tag == TAG_EMPTY && e->len >= len){
        emptyLen = e->len;
        e-> tag = tag;
        e-> len = len;
        if (entry != NULL){
          memcpy(e->data.b, entry->data.b, len);
        } else {
          //when no data provided, wipe out the body
          memset(e->data.b, 0xff, len);
        }
        //take up remaining space with TAG_EMPTY
        if (emptyLen - len > 2){
          ba[index + 2 + len] = TAG_EMPTY;
          ba[index + 2 + len + 1] = emptyLen - len - 2;
        }
        return index;
      } else {
        index = index + 2 + e->len;
      }
    }
    return 0;
  }

  void mergeEmpty(void* tlvs){
    uint8_t* ba = (uint8_t*) tlvs;
    uint16_t index = TLV_CHECKSUM_LENGTH;
    tlv_entry_t* e;
    tlv_entry_t* n;
    while (index < IFLASH_SEGMENT_SIZE){
      e = (tlv_entry_t*)(&ba[index]);
      n = (tlv_entry_t*)(&ba[index+e->len+2]);
      //current entry hits the end of the segment, so stop
      if (e->len + index + 2 >= IFLASH_SEGMENT_SIZE){
        break;
      }
      //this entry and next are both empty, so merge them.
      // leave index at the same point in case there are 3+ EMPTY's
      if (e->tag == TAG_EMPTY && n->tag == TAG_EMPTY){
        //add 2 bytes for removed header
        e->len += 2 + n->len;
        //wipe it
        memset(e->data.b, 0xff, e->len);
        continue;
      }else{
        //no merge possible, so skip to next entry
        index += e->len + 2;
      }
    }
  }

  //delete the entry at offset and free space. Returns FAIL if offset
  //does not point to the start of an entry.
  command error_t TLVStorage.deleteEntry(uint8_t offset, void* tlvs){
    uint8_t* ba = (uint8_t*) tlvs;
    uint16_t index = TLV_CHECKSUM_LENGTH;
    tlv_entry_t* e;
    //skip ahead to offset
    while (index < offset){
      e = (tlv_entry_t*)(&ba[index]);
      index += 2 + e->len;
    }
    e = (tlv_entry_t*)(&ba[index]);
    //offset provided wasn't an entry.
    if (index != offset){
      return FAIL;
    }else{
      e->tag = TAG_EMPTY;
      memset(e->data.b, 0xff, e->len);
      mergeEmpty(tlvs);
      return SUCCESS;
    }
  }

  //locate an entry in the tlv storage: return the first offset
  //at or after startOffset where tag is found. Set *entry to a
  //pointer to the entry.  returns 0 if it's not found.
  command uint8_t TLVStorage.findEntry(uint8_t tag, uint8_t startOffset, 
    tlv_entry_t** entry, void* tlvs){
    tlv_entry_t* e;
    uint8_t* ba = (uint8_t*) tlvs;
    uint16_t index = TLV_CHECKSUM_LENGTH;
    while (index < IFLASH_SEGMENT_SIZE){
      e = (tlv_entry_t*)(&ba[index]);
      if(index >= startOffset && (tag == TAG_ANY || e->tag == tag)){
        *entry = e;
        return index;
      }else{
        index += (2 + e->len);
      }
    }
    *entry = NULL;
    //not found
    return 0;
  }

  void copyIfDirty(){
    void* tlvsA = IFLASH_A_START;
    void* tlvsB = IFLASH_B_START;
    tlv_entry_t* va;
    tlv_entry_t* vb;
    call TLVStorage.findEntry(TAG_VERSION, 0, &va, tlvsA);
    call TLVStorage.findEntry(TAG_VERSION, 0, &vb, tlvsB);
    //check 
    if (vb == NULL){
      //TODO: error condition
      return;
    }
    //copy if any holds:
    //B has version tag, A doesn't
    //B's version = A's version + 1
    if ((va == NULL && vb != NULL) 
      || (vb->data.w[0]  == 1 + va->data.w[0])){
      unlockInternalFlash(IFLASH_A_START);
      FCTL1 = FWKEY+ERASE;
      *((uint8_t*)IFLASH_A_START) = 0;
      FCTL1 = FWKEY + WRT;
      memcpy(IFLASH_A_START, IFLASH_B_START, IFLASH_SEGMENT_SIZE);
      FCTL1 = FWKEY;
      lockInternalFlash(IFLASH_A_START);
    }else{
      //no copy needed
    }
  }

  command error_t Init.init(){
    copyIfDirty();
  }

  void writeToB(void* tlvs){
    unlockInternalFlash(IFLASH_B_START);
    FCTL1 = FWKEY + ERASE;
    *((uint8_t*)IFLASH_B_START) = 0;
    FCTL1 = FWKEY+WRT;
    memcpy(IFLASH_B_START, tlvs, IFLASH_SEGMENT_SIZE);
    FCTL1 = FWKEY;
    lockInternalFlash(IFLASH_B_START);
  }

  //persist TLV structure (to internal flash)
  command error_t TLVStorage.persistTLVStorage(void* tlvs){
    tlv_entry_t* versionTag;
    int16_t* wa = (int16_t*)tlvs;
    if (0 == call TLVStorage.findEntry(TAG_VERSION, 0, &versionTag, tlvs)){
      //there should always be a TAG_VERSION in here if tlvs was
      //loaded via this component.
      return FAIL; 
    } else {
      //increment version
      (versionTag->data.w)[0] ++;
    }
    //checksum: bitwise XOR of the data, stored as -1*checksum (see
    //24.3 in user guide: verification is done by xoring the data,
    //then adding the result to the checksum-to-be-verified. if the
    //result is NOT 0, then it is flagged as bad.
    wa[0] = -1*computeChecksum(tlvs);
    writeToB(tlvs);
    copyIfDirty();
    return SUCCESS;
  }

}
