#include "GlobalID.h"
#include "TLVStorage.h"

module GlobalIDP{
  provides interface GlobalID;
  uses interface TLVStorage;
  uses interface TLVUtils;
} implementation {
  command error_t GlobalID.getID(uint8_t* idBuf, uint8_t maxLen){
    if (maxLen < GLOBAL_ID_LEN){
      return ESIZE;
    } else {
      global_id_entry_t* gid;
      uint8_t ba[TLV_LEN];
      error_t err;
      err = call TLVStorage.loadTLVStorage(ba);
      if (err != SUCCESS){
        return err;
      }
      call TLVUtils.findEntry(TAG_GLOBAL_ID, 0, (tlv_entry_t**)&gid, ba);
      if (gid != NULL){
        memcpy(idBuf, gid->id, GLOBAL_ID_LEN);
        return SUCCESS;
      } else {
        return FAIL;
      }
    }
  }

  command uint8_t GlobalID.getIDLen(){
    return GLOBAL_ID_LEN;
  }

  command error_t GlobalID.setID(uint8_t* idBuf, uint8_t len){
    global_id_entry_t gid;
    tlv_entry_t* previous;
    uint8_t offset;
    uint8_t ba[TLV_LEN];
    error_t err;
    if (len > GLOBAL_ID_LEN){
      return ESIZE;
    }
    memcpy(gid.id, idBuf, len);
    err = call TLVStorage.loadTLVStorage(ba);
    if (err != SUCCESS){
      return err;
    }
    offset = call TLVUtils.findEntry(TAG_GLOBAL_ID, 0, &previous,
      ba);
    if (previous != NULL){
      err = call TLVUtils.deleteEntry(offset, ba);
      if (SUCCESS != err){
        return err;
      }
    }
    offset = call TLVUtils.addEntry(TAG_GLOBAL_ID, len, (tlv_entry_t*)&gid, 
      ba, 0);
    if (offset != 0){
      return call TLVStorage.persistTLVStorage(ba);
    } else {
      return FAIL;
    }
  }

}
