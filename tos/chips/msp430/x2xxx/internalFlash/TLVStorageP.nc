#include "TLVStorage.h"
#include "InternalFlash.h"
#include "InternalFlashFunctions.h"

module TLVStorageP{
  provides interface TLVStorage;
  provides interface Init;
  uses interface TLVUtils;
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
      call TLVUtils.addEntry(TAG_VERSION, 2, (tlv_entry_t*)&e, tlvs,0);
      //TODO: better return code? 
      return SUCCESS;
    }
    return SUCCESS;
  }
  
  void copyIfDirty(){
    void* tlvsA = IFLASH_A_START;
    void* tlvsB = IFLASH_B_START;
    tlv_entry_t* va;
    tlv_entry_t* vb;
    call TLVUtils.findEntry(TAG_VERSION, 0, &va, tlvsA);
    call TLVUtils.findEntry(TAG_VERSION, 0, &vb, tlvsB);
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
    if (0 == call TLVUtils.findEntry(TAG_VERSION, 0, &versionTag, tlvs)){
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
