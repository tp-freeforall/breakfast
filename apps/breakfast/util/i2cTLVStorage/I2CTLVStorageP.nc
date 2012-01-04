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

  task void readTask(){
    error_t error = call TLVStorage.loadTLVStorage(reg.buf);
    call I2CRegister.unPause();
  }

  task void writeTask(){
    error_t error;
    error = call TLVStorage.persistTLVStorage(reg.s.buf);
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
