#include "I2CDiscoverable.h"
#include "TLVStorage.h"
#include "decodeError.h"

module TestP{
  uses interface Boot;
  uses interface UartStream;
  uses interface StdControl;
  uses interface Leds;

  uses interface I2CDiscoverer;

  uses interface I2CPersistentStorageMaster;

  uses interface SplitTLVStorage;
  uses interface TLVUtils;
  uses interface Set<uint16_t>;

} implementation {
  enum {
    MAX_SLAVES = 4,
  };
  uint16_t slaves[MAX_SLAVES];
  uint8_t slaveCount;
  uint8_t buf[63] = { 
    0xca, 0xfe, 0xba, 0xbe, 0xde, 0xad, 0xbe, 0xef,
    0xca, 0xfe, 0xba, 0xbe, 0xde, 0xad, 0xbe, 0xef,
    0xca, 0xfe, 0xba, 0xbe, 0xde, 0xad, 0xbe, 0xef,
    0xca, 0xfe, 0xba, 0xbe, 0xde, 0xad, 0xbe, 0xef,
    0xca, 0xfe, 0xba, 0xbe, 0xde, 0xad, 0xbe, 0xef,
    0xca, 0xfe, 0xba, 0xbe, 0xde, 0xad, 0xbe, 0xef,
    0xca, 0xfe, 0xba, 0xbe, 0xde, 0xad, 0xbe, 0xef,
    0xca, 0xfe, 0xba, 0xbe, 0xde, 0xfa, 0xce,
  };

  event void Boot.booted(){
    call StdControl.start();
    printf("Test Toast apps\n\r");
  }

  task void startDiscovery(){
    printf("Start discovery\n\r");
    slaveCount = 0;
    call I2CDiscoverer.startDiscovery(TRUE, 0x40);
  }

  event uint16_t I2CDiscoverer.getLocalAddr(){
    return TOS_NODE_ID & 0x7F;
  }

  event discoverer_register_union_t* I2CDiscoverer.discovered(discoverer_register_union_t* discovery){
    uint8_t i;
    slaves[slaveCount] = discovery->val.localAddr;
    printf("Assigned %x to ", discovery->val.localAddr);
    for ( i = 0 ; i < GLOBAL_ID_LEN; i++){
      printf("%x ", discovery->val.globalAddr[i]);
    }
    printf("\n\r");
    slaveCount++;
    return discovery;
  }

  event void I2CDiscoverer.discoveryDone(error_t error){
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
  }


  task void readPersistentStorage(){
    error_t error;
    if (slaveCount == 0){
      printf("No slaves found yet ('d' to discover)\n\r");
    } else {
      printf("Reading from local addr %x\n\r", slaves[0]);
      error = call I2CPersistentStorageMaster.read(slaves[0], buf);
      printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
    }
  }
  event void I2CPersistentStorageMaster.readDone(error_t error,
      void* buf_){
    uint8_t i;
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
    if (error == SUCCESS){
      for (i = 0; i < 63; i++){
        if ( i % 8 == 0){
          printf("\n\r [%x]",i);
        }
        printf("\t%x", ((uint8_t*)buf)[i]);
      }
    }
    printf("\n\r");
  }

  task void writePersistentStorage(){
    error_t error;
    if (slaveCount == 0){
      printf("No slaves found yet ('d' to discover)\n\r");
    } else {
      printf("writing to local addr %x\n\r", slaves[0]);
      error = call I2CPersistentStorageMaster.write(slaves[0], buf);
      printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
    }
  }

  event void I2CPersistentStorageMaster.writeDone(error_t error,
      void* buf_){
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
  }

  uint8_t tlv_ba[TLV_LEN];
  void* tlvs = tlv_ba;

  task void loadTLVStorage(){
    error_t error;
    printf("%s: \n\r", __FUNCTION__);
    call Set.set(slaves[0]);
    error = call SplitTLVStorage.loadTLVStorage(tlvs);
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
  }

  event void SplitTLVStorage.loaded(error_t error, void* tlvs_){
    tlv_entry_t* e;
    uint8_t offset = 0;
    uint8_t i;
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
    printf("%s: \n\r", __FUNCTION__);
    call Set.set(slaves[0]);
    error = call SplitTLVStorage.persistTLVStorage(tlvs);
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
  }

  event void SplitTLVStorage.persisted(error_t error, void* tlvs_){
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
  }

  task void addUniqueIDTag(){
    tlv_entry_t* e;
    global_id_entry_t uid;
    uint8_t offset;
    uint8_t i;
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
    call Leds.led0Toggle();
    switch ( byte ){
      case 'd':
        post startDiscovery();
        break;
      case 'r':
        post readPersistentStorage();
        break;
      case 'w':
        post writePersistentStorage();
        break;

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

      case 'q':
        WDTCTL = 0;
        break;
      case '\r':
        printf("\n\r");
        break;
      default:
        printf("%c", byte);
        break;
    }
  }
  
  async event void UartStream.receiveDone( uint8_t* buf_, uint16_t len,
    error_t error ){}
  async event void UartStream.sendDone( uint8_t* buf_, uint16_t len,
    error_t error ){}
}
