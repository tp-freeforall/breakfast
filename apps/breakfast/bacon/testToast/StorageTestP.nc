module StorageTestP{
  uses interface UartStream;
  uses interface Get<test_state_t*>;
  uses interface I2CPersistentStorageMaster;
  provides interface Get<const char*> as GetDesc;
} implementation {
  const char* testDesc = "Persistent Storage\n\r r: read\n\r w: write";

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

  command const char* GetDesc.get(){
    return testDesc;
  }

  task void readPersistentStorage(){
    error_t error;
    test_state_t* state = call Get.get();
    if (state->slaveCount == 0){
      printf("No slaves found yet ('d' to discover)\n\r");
    } else {
      printf("Reading from local addr %x\n\r", state->slaves[state->currentSlave]);
      error = call I2CPersistentStorageMaster.read(state->slaves[state->currentSlave], buf);
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
    test_state_t* state = call Get.get();
    if (state->slaveCount == 0){
      printf("No slaves found yet ('d' to discover)\n\r");
    } else {
      printf("writing to local addr %x\n\r", state->slaves[state->currentSlave]);
      error = call I2CPersistentStorageMaster.write(state->slaves[state->currentSlave], buf);
      printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
    }
  }

  event void I2CPersistentStorageMaster.writeDone(error_t error,
      void* buf_){
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
  }


  async event void UartStream.receivedByte(uint8_t byte){
    switch(byte){
      case 'r':
        post readPersistentStorage();
        break;
      case 'w':
        post writePersistentStorage();
        break;
      default:
        printf("%c", byte);
    }
  }

  async event void UartStream.receiveDone( uint8_t* buf_, uint16_t len,
    error_t error ){}
  async event void UartStream.sendDone( uint8_t* buf_, uint16_t len,
    error_t error ){}
}
