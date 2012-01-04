//man I wish I could avoid all these stupid copies
#include "I2CTLVStorage.h"
module I2CTLVStorageMasterP{
  provides interface SplitTLVStorage;
  provides interface Set<uint16_t>;
  uses interface I2CRegisterUser;
  uses interface TLVUtils;
} implementation {
  enum {
    S_IDLE = 0,
    S_LOADING = 1,
    S_PERSISTING = 2,
  }; 
  
  uint8_t state = S_IDLE;
  uint16_t curSlave = 0;
  register_packet_t pkt;
  void* buf;

  command void Set.set(uint16_t val){
    curSlave = val;
  }

  task void readTask(){
    error_t error = call I2CRegisterUser.read(curSlave, 0, &pkt,
      TLV_STORAGE_REGISTER_LEN - 1);
    if (error != SUCCESS){
      state = S_IDLE;
      signal SplitTLVStorage.loaded(error, buf);
    }
  }

  event void I2CRegisterUser.writeDone(error_t error, 
      uint16_t slaveAddr, uint8_t pos, uint8_t len, 
      register_packet_t* pkt_){
    if (state == S_LOADING){
      if (error == SUCCESS){
        post readTask();
      } else {
        signal SplitTLVStorage.loaded(error, buf);
      }
    } else if (state == S_PERSISTING){
      state = S_IDLE;
      signal SplitTLVStorage.persisted(error, buf);
    }
  }

  void debugTLV(void* tlvs_){
    tlv_entry_t* e;
    uint8_t offset = 0;
    uint8_t i;
    do{
      offset = call TLVUtils.findEntry(TAG_ANY, offset+1, &e, tlvs_);
      if (e != NULL){
        printf("------------\n\r");
        printf(" Offset: %d\n\r", offset);
        printf(" Tag:\t[%d]\t%x\n\r", offset, e->tag);
        printf(" Len:\t[%d]\t%x\n\r", offset+1, e->len);
        if (e->tag != TAG_EMPTY){
        printf(" Data:\n\r");
        for (i = 0; i < e->len; i++){
          printf("  [%d]\t(%d)\t%x\n\r", offset+2+i, i, e->data.b[i]);
        }
        }else{
          printf("  [%d]->[%d] (empty)\n\r", offset+2,
          offset+2+e->len-1);
        }
      }
    } while( offset != 0);
  }

 
  event void I2CRegisterUser.readDone(error_t error, 
      uint16_t slaveAddr, uint8_t pos, register_packet_t* pkt_, 
      uint8_t len){
    if (error == SUCCESS){
      memcpy(buf, pkt.data, TLV_STORAGE_REGISTER_LEN - 1);
    }
    state = S_IDLE;
    signal SplitTLVStorage.loaded(error, buf);
  }


  command error_t SplitTLVStorage.loadTLVStorage(void* tlvs){
    error_t ret;
    if (state != S_IDLE){
      return EBUSY;
    }
    if (curSlave == 0){
      return FAIL;
    }
    pkt.body.cmd = TLV_STORAGE_READ_CMD;
    ret = call I2CRegisterUser.write(curSlave, 0, &pkt, 1);
    if (ret == SUCCESS){
      buf = tlvs;
      state = S_LOADING;
    }
    return ret;
  }

  command error_t SplitTLVStorage.persistTLVStorage(void* tlvs){
    error_t error;
    if (state != S_IDLE){
      return EBUSY;
    }
    if (curSlave == 0){
      return FAIL;
    }
    pkt.body.cmd = TLV_STORAGE_WRITE_CMD;
    memcpy(pkt.body.data, tlvs, TLV_STORAGE_REGISTER_LEN - 1);
    error = call I2CRegisterUser.write(curSlave, 0, &pkt,
      TLV_STORAGE_REGISTER_LEN);
    return error;
  }
}
