#include "TLVStorage.h"

module TLVUtilsC{
  provides interface TLVUtils;
} implementation{
  
  //find first available space if offset is 0 OR try to use exactly
  //offset if it's not 0, write a new tlv entry into it, and
  //return the offset where the new tlv entry begins. Return 0 if it
  //couldn't be written.
  command uint8_t TLVUtils.addEntry(uint8_t tag, uint8_t len, tlv_entry_t* entry, void* tlvs, uint8_t offset){
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
  command error_t TLVUtils.deleteEntry(uint8_t offset, void* tlvs){
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
  command uint8_t TLVUtils.findEntry(uint8_t tag, uint8_t startOffset, 
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
}
