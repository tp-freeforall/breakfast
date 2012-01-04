#include "I2CTLVStorage.h"

module I2CTLVStorageP{
  uses interface TLVStorage;
  uses interface TLVUtils;
  uses interface I2CRegister;
} implementation {
  tlv_register_t reg;

  async event uint8_t* I2CRegister.transactionStart(bool isTransmit){
    return reg.buf;
  }

  async event uint8_t I2CRegister.registerLen(){
    return TLV_STORAGE_REGISTER_LEN;
  }

  task void readTask(){
    error_t error = call TLVStorage.loadTLVStorage(reg.s.buf);
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
    call I2CRegister.unPause();
  }

  task void writeTask(){
    error_t error = call TLVStorage.persistTLVStorage(reg.s.buf);
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
    call I2CRegister.unPause();
  }

  async event void I2CRegister.transactionStop(uint8_t* reg_,
      uint8_t pos){
    //commands:
    // simple slave: read/write (entire buffer). master has to
    //   manipulate on their own.
    //   pro: easy to implement
    //   con: extra code at master (will use TLVStorage interface
    switch ( reg.s.cmd ){
      case TLV_STORAGE_WRITE_CMD:
        call I2CRegister.pause();
        post writeTask();
        break;
      case TLV_STORAGE_READ_CMD:
        call I2CRegister.pause();
        post readTask();
        break;
      default:
        break;
    }
  }

}
