//man I wish I could avoid all these stupid copies
#include "I2CTLVStorage.h"
module I2CTLVStorageMasterP{
  provides interface SplitTLVStorage;
  provides interface Set<uint16_t>;
  uses interface I2CRegisterUser;
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
    error_t error = call I2CRegisterUser.read(slaveAddr, 1, &pkt,
      TLV_STORAGE_REGISTER_LEN - 1);
  }

  event void I2CRegisterUser.writeDone(error_t error, 
      uint16_t slaveAddr, uint8_t pos, uint8_t len, 
      register_packet_t* pkt){
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

  event void I2CRegisterUser.readDone(error_t error, 
      uint16_t slaveAddr, uint8_t pos, register_packet_t* pkt, 
      uint8_t len){
    if (error == SUCCESS){
      memcpy(buf, reg.buf, TLV_STORAGE_REGISTER_LEN - 1);
    }
    state = S_IDLE;
    signal SplitTLVStorage.loaded(error, buf);
  }


  command error_t SplitTLVStorage.loadTLVStorage(void* tlvs){
    error_t ret;
    if (state != S_IDLE){
      return EBUSY;
    }
    if (slaveAddr == 0){
      return FAIL;
    }
    pkt.body.cmd = TLV_STORAGE_READ_CMD;
    ret = call I2CRegisterUser.write(slaveAddr, 0, &pkt, 1);
    if (ret == SUCCESS){
      buf = tlvs;
      state = S_READING;
    }
    return ret;
  }

  command error_t SplitTLVStorage.persistTLVStorage(void* tlvs){
    error_t error;
    if (state != S_IDLE){
      return EBUSY;
    }
    if (slaveAddr == 0){
      return FAIL;
    }
    pkt.body.cmd = TLV_STORAGE_WRITE_CMD;
    memcpy(pkt.body.data, tlvs, TLV_STORAGE_REGISTER_LEN - 1);
    error = call I2CRegisterUser.write(slaveAddr, 0, &pkt,
      TLV_STORAGE_REGISTER_LEN);
    return error;
  }
}
