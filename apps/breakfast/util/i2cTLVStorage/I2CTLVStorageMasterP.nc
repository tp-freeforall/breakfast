#include "I2CTLVStorage.h"
#include "I2CCom.h"

module I2CTLVStorageMasterP{
  provides interface I2CTLVStorageMaster;
  uses interface I2CRegisterUser;
  uses interface TLVUtils;
} implementation {
  enum {
    S_IDLE = 0,
    S_LOADING = 1,
    S_PERSISTING = 2,
  }; 
  
  uint8_t state = S_IDLE;
  message_t* readMsg;

  task void readTask(){
    error_t error = call
    I2CComMaster.receive(readMsg->body.header.slaveAddr, readMsg,
      sizeof(i2c_tlv_storage_t));

    if (error != SUCCESS){
      state = S_IDLE;
      readMsg->body.header.len = 0;
      signal I2CTLVStorageMaster.loaded(error, readMsg);
    }
  }

  event void I2CComMaster.sendDone(error_t error, 
      i2c_message_t* msg){
    if (state == S_LOADING){
      if (error == SUCCESS){
        readMsg = msg;
        post readTask();
      } else {
        signal SplitTLVStorage.loaded(error, msg);
      }
    } else if (state == S_PERSISTING){
      state = S_IDLE;
      signal I2CTLVStorageMaster.persisted(error, msg);
    }
  }

 
  event void I2CComMaster.receiveDone(error_t error, 
      i2c_message_t* msg){
    state = S_IDLE;
    signal I2CComMaster.loaded(error, msg);
  }


  command error_t I2CTLVStorageMaster.loadTLVStorage(uint16_t slaveAddr, 
      i2c_message_t* msg){
    error_t ret;
    i2c_tlv_storage_t* payload = (i2c_tlv_storage_t*)call I2CComMaster.getPayload(msg);
    if (state != S_IDLE){
      return EBUSY;
    }
    payload-> cmd = TLV_STORAGE_READ_CMD;
    ret = call I2CComMaster.send(slaveAddr, msg, 1);
    if (ret == SUCCESS){
      state = S_LOADING;
    }
    return ret;
  }

  command error_t I2CTLVStorage.persistTLVStorage(uint16_t slaveAddr,
      i2c_message_t* msg){
    error_t error;
    i2c_tlv_storage_t* payload = (i2c_tlv_storage_t*)call I2CComMaster.getPayload(msg);
    if (state != S_IDLE){
      return EBUSY;
    }

    payload->cmd = TLV_STORAGE_WRITE_CMD;
    error = call I2CComMaster.send(slaveAddr,
      msg,sizeof(i2c_tlv_storage_t));
    if (error == SUCCESS){
      state = S_PERSISTING;
    }
    return error;
  }
}
