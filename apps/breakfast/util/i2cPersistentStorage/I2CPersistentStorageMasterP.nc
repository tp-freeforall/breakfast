#include "I2CPersistentStorage.h"
module I2CPersistentStorageMasterP{
  provides interface I2CPersistentStorageMaster;
  uses interface I2CComMaster;
} implementation {
  enum{
    S_BUSY = 1 << 0,
    S_WRITING = 1 << 1,
    S_READING = 1 << 2,
  };
  //have to keep track of this between sendDone (writing READ_CMD) and
  // calling receive command.
  i2c_message_t* readMsg;

  uint8_t state;

  task void readTask();

  command void* I2CPersistentStorageMaster.getPayload(i2c_message_t*
  msg){
    i2c_persistent_storage_t* payload = (i2c_persistent_storage_t*)
      call I2CComMaster.getPayload(msg);
    return &payload->data;
  }

  command error_t I2CPersistentStorageMaster.write(uint16_t slaveAddr_,
      i2c_message_t* msg){
    error_t ret;
    i2c_persistent_storage_t* payload = (i2c_persistent_storage_t*)
      call I2CComMaster.getPayload(msg);

    printf("%s: \n\r", __FUNCTION__);
    if (state & S_BUSY){
      return EBUSY;
    }
    payload -> cmd = I2C_STORAGE_WRITE_CMD;
    slaveAddr = slaveAddr_;
    ret =  call I2CComMaster.send(slaveAddr, &msg,
      sizeof(i2c_persistent_storage_t));
    if (ret == SUCCESS){
      state |= (S_BUSY|S_WRITING);
    } 
    return ret;
  }

  event void I2CComMaster.sendDone(error_t error, i2c_message_t* msg){
    printf("%s: \n\r", __FUNCTION__);
    if (state & S_WRITING){
      state = 0;
      signal I2CPersistentStorageMaster.writeDone(error, msg);
    } else if (state & S_READING){
      readMsg = msg;
      post readTask();
    }
  }

  command error_t I2CPersistentStorageMaster.read(uint16_t slaveAddr_,
      i2c_message_t* msg){
    error_t ret;
    i2c_persistent_storage_t* payload = (i2c_persistent_storage_t*)
      call I2CComMaster.getPayload(msg);
    printf("%s: \n\r", __FUNCTION__);
    if (state & S_BUSY){
      return EBUSY;
    }
    payload->cmd = I2C_STORAGE_READ_CMD;
    ret = call I2CComMaster.write(slaveAddr, 0, msg, 1);
    printf("%s: %s\n\r", __FUNCTION__, decodeError(ret));
    if (ret == SUCCESS){
      state |= (S_BUSY|S_READING);
    }
    return ret;
  }

  task void readTask(){
    error_t ret;
    readMsg -> body.header.len = sizeof(i2c_persistent_storage_t);
    ret = call I2CComMaster.receive(readMsg->body.header.slaveAddr,
      readMsg, sizeof(i2c_persistent_storage_t));
    printf("%s: %s\n\r", __FUNCTION__, decodeError(ret));
    if (ret != SUCCESS){
      state = 0;
      signal I2CPersistentStorageMaster.readDone(ret, readMsg);
    }
  }


  event void I2CComMaster.receiveDone(error_t error, 
      i2c_message_t* msg){
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
    state = 0;
    signal I2CPersistentStorageMaster.readDone(error, msg,
      ((i2c_persistent_storage_t*)(call I2CComMaster.getPayload(msg)))->data);
  }
}
