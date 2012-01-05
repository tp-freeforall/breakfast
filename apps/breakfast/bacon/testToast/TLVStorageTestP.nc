module TLVStorageTestP{
  uses interface SplitTLVStorage;
  uses interface TLVUtils;
  uses interface Set<uint16_t>;

  provides interface Get<const char*> as GetDesc;
  uses interface Get<test_state_t*>;
} implementation{

  const char* testDesc = "TLV Storage test:\n\r l: load\n\r a: add uid tag\n\r p: persist\n\r d: delete\n\r"; 

  command const char* GetDesc.get(){
    return testDesc;
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

  async event void SubUartStream.receivedByte(uint8_t byte){
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
}
