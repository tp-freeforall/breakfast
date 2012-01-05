#include "I2CCom.h"
#include "I2CTLVStorage.h"

module TLVStorageTestP{
  uses interface I2CTLVStorageMaster;
  uses interface TLVUtils;

  provides interface Get<const char*> as GetDesc;
  uses interface Get<test_state_t*>;
  uses interface UartStream;
} implementation{

  const char* testDesc = "TLV Storage test:\n\r l: load\n\r a: add uid tag\n\r p: persist\n\r d: delete\n\r"; 

  command const char* GetDesc.get(){
    return testDesc;
  }
  
  i2c_message_t msg;

  task void loadTLVStorage(){
    error_t error;
    test_state_t* state = call Get.get();
    printf("%s: \n\r", __FUNCTION__);
    error = call
    I2CTLVStorageMaster.loadTLVStorage(state->slaves[state->currentSlave],
      &msg);
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
  }

  event void I2CTLVStorageMaster.loaded(error_t error, i2c_message_t* msg_){
    tlv_entry_t* e;
    uint8_t offset = 0;
    uint8_t i;
    void* tlvs_ = call I2CTLVStorageMaster.getPayload(msg_);
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
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

  task void persistTLVStorage(){
    error_t error;
    test_state_t* state = call Get.get();
    printf("%s: \n\r", __FUNCTION__);
    error = call I2CTLVStorageMaster.persistTLVStorage(state->slaves[state->currentSlave], &msg);
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
  }

  event void I2CTLVStorageMaster.persisted(error_t error, i2c_message_t* tlvs_){
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
  }

  task void addUniqueIDTag(){
    tlv_entry_t* e;
    global_id_entry_t uid;
    uint8_t offset;
    uint8_t i;
    void* tlvs = call I2CTLVStorageMaster.getPayload(&msg);
    printf("%s: \n\r", __FUNCTION__);
    if( 0 == call TLVUtils.findEntry(TAG_GLOBAL_ID, 0, &e, tlvs)){
      memset(uid.id, 0, 8);
      uid.id[7] = 1;
      offset = call TLVUtils.addEntry(TAG_GLOBAL_ID, 8, (tlv_entry_t*)&uid,
        tlvs, 0);
      if (offset != 0){
        printf("Added at offset %x\n\r", offset);
      } else {
        printf("Not added!\n\r");
        return;
      }
    }else {
      printf("Unique ID already present: ");
      for ( i = 0 ; i < 8 ; i++){
        printf("%x ", ((global_id_entry_t*)e)->id[i]);
      }
      printf("\n\r");
    }
  }

  task void updateUniqueIDTag(){
    global_id_entry_t* uid;
    uint8_t offset;
    void* tlvs = call I2CTLVStorageMaster.getPayload(&msg);
    printf("%s: \n\r", __FUNCTION__);
    offset = call TLVUtils.findEntry(TAG_GLOBAL_ID, 0, (tlv_entry_t**)&uid,
      tlvs);
    if (NULL == uid){
      printf("No unique Id tag found.\n\r");
    } else {
      printf("Unique ID at offset %x\n\r", offset);
      uid->id[7] += 1;
    }
  }

  task void deleteUniqueIDTag(){
    global_id_entry_t* uid;
    uint8_t offset;
    error_t error;
    void* tlvs = call I2CTLVStorageMaster.getPayload(&msg);
    offset = call TLVUtils.findEntry(TAG_GLOBAL_ID, 0, (tlv_entry_t**)&uid,
      tlvs);
    if (offset != 0){
      printf("Unique ID found at %x.\n\r", offset);
      error = call TLVUtils.deleteEntry(offset, tlvs);
      printf("delete: %s\n\r", decodeError(error));
    }else{
      printf("No Unique ID tag to delete.\n\r");
    }
  }

  async event void UartStream.receivedByte(uint8_t byte){
    switch(byte){
      case 'l':
        post loadTLVStorage();
        break;
      case 'p':
        post persistTLVStorage();
        break;
      case 'a':
        post addUniqueIDTag();
        break;
      case 'u':
        post updateUniqueIDTag();
        break;
      case 'D':
        post deleteUniqueIDTag();
        break;
    }
  }

  async event void UartStream.receiveDone( uint8_t* buf_, uint16_t len,
    error_t error ){}
  async event void UartStream.sendDone( uint8_t* buf_, uint16_t len,
    error_t error ){}
}
