#include "InternalFlash.h"
#include "I2CPersistentStorage.h"
#include "decodeError.h"
#include "I2CCom.h"

module I2CPersistentStorageP{
  uses interface I2CComSlave;
  uses interface InternalFlash;
} implementation {
  i2c_message_t msg_internal;
  i2c_message_t* msg = &msg_internal;
  
  i2c_message_t* swap(i2c_message_t* msg_){
    i2c_message_t* swp = msg;
    msg = msg_;
    return swp;
  }

  task void readTask(){
    i2c_persistent_storage_t* payload =
      (i2c_persistent_storage_t*) call I2CComSlave.getPayload(msg);
    payload->cmd = I2C_STORAGE_RESPONSE_CMD;
    //last byte is version
    call InternalFlash.read(0, payload->data, IFLASH_SEGMENT_SIZE - 1);
    call I2CComSlave.unpause();
  }

  //we don't unpause the lower layer until the data is filled into
  //  msg, so it's fine to just return that and do the swap.
  async event i2c_message_t* I2CComSlave.slaveTXStart(i2c_message_t* msg_){
    return swap(msg_);
  }

  task void writeTask(){
    i2c_persistent_storage_t* payload =
      (i2c_persistent_storage_t*) call I2CComSlave.getPayload(msg);
    call InternalFlash.write(0, payload->data, IFLASH_SEGMENT_SIZE - 1);
    call I2CComSlave.unpause();
  }

  async event i2c_message_t* I2CComSlave.received(i2c_message_t* msg_){ 
    i2c_persistent_storage_t* payload =
      (i2c_persistent_storage_t*) call I2CComSlave.getPayload(msg);
    switch(payload->cmd){
      case I2C_STORAGE_WRITE_CMD:
        //do not let any other commands come in until we're done with
        //  this one.
        call I2CComSlave.pause();
        post writeTask();
        //we need to hang onto this buffer, since we're going to
        //  persist the data to flash. do a swap.
        return swap(msg_);
      case I2C_STORAGE_READ_CMD:
        call I2CComSlave.pause();
        post readTask();
        return msg_;
      default:
        return msg_;
    }
  }

}
