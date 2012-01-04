#include "InternalFlash.h"
#include "I2CPersistentStorage.h"
#include "decodeError.h"

module I2CPersistentStorageP{
  uses interface I2CRegister;
  uses interface InternalFlash;
} implementation {
  enum {
    REGISTER_LEN = IFLASH_SEGMENT_SIZE,
  };

  uint8_t buf[REGISTER_LEN];

  task void readFlashTask(){
//    printf("%s: %s \n\r", __FUNCTION__, decodeError( call InternalFlash.read(0, &buf[1], IFLASH_SEGMENT_SIZE - 1)));
    //last byte is version
    call I2CRegister.unPause();
  }

  async event uint8_t* I2CRegister.transactionStart(bool isTransmit){
//    printf("%s: it %x\n\r", __FUNCTION__, isTransmit);
    if (isTransmit){
      call I2CRegister.pause();
      post readFlashTask();
    }
    return buf;
  }

  async event uint8_t I2CRegister.registerLen(){
    return REGISTER_LEN;
  }

  task void writeTask(){
//    printf("%s: %s\n\r", __FUNCTION__, decodeError(call InternalFlash.write(0, &buf[1], IFLASH_SEGMENT_SIZE - 1)));
    call I2CRegister.unPause();
  }

  async event void I2CRegister.transactionStop(uint8_t* reg, 
      uint8_t pos){ 
//    printf("%s: buf: %p cmd: %x\n\r", __FUNCTION__, reg, reg[0]);
    switch(reg[0]){
      case I2C_STORAGE_WRITE_CMD:
//        printf("write cmd\n\r");
        call I2CRegister.pause();
        post writeTask();
        break;
      case I2C_STORAGE_READ_CMD:
//        printf("read cmd\n\r");
        break;
      default:
//        printf("unrecognized cmd %x\n\r", reg[0]);
        break;
    }
  }

}
