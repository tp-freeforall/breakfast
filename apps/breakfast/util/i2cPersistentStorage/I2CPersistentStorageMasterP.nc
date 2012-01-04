#include "I2CPersistentStorage.h"
module I2CPersistentStorageMasterP{
  provides interface I2CPersistentStorageMaster;
  uses interface I2CRegisterUser;
} implementation {
  enum{
    S_BUSY = 1 << 0,
    S_WRITING = 1 << 1,
    S_READING = 1 << 2,
  };
  register_packet_t pkt;
  uint16_t slaveAddr;
  uint8_t state;
  void* readBuf;
  void* writeBuf;

  task void readTask();

  command error_t I2CPersistentStorageMaster.write(uint16_t slaveAddr_,
      void* data){
    error_t ret;
    printf("%s: \n\r", __FUNCTION__);
    if (state & S_BUSY){
      return EBUSY;
    }
    //whelp, wish that I could figure out a better way to do this
    writeBuf = data;
    memcpy(pkt.body.data, data, PERSISTENT_STORAGE_REGISTER_SIZE - 1);
    pkt.body.cmd = I2C_STORAGE_WRITE_CMD;
    slaveAddr = slaveAddr_;
    ret =  call I2CRegisterUser.write(slaveAddr, 0, &pkt,
      PERSISTENT_STORAGE_REGISTER_SIZE);
    if (ret == SUCCESS){
      state |= (S_BUSY|S_WRITING);
    } 
    return ret;
  }

  event void I2CRegisterUser.writeDone(error_t error, uint16_t slaveAddr_, 
      uint8_t pos, uint8_t len, register_packet_t* pkt_){
    printf("%s: \n\r", __FUNCTION__);
    if (state & S_WRITING){
      state = 0;
      signal I2CPersistentStorageMaster.writeDone(error, writeBuf);
    } else if (state & S_READING){
      post readTask();
    }
  }

  command error_t I2CPersistentStorageMaster.read(uint16_t slaveAddr_,
      void* data){
    error_t ret;
    printf("%s: \n\r", __FUNCTION__);
    if (state & S_BUSY){
      return EBUSY;
    }
    readBuf = data;
    //have to write I2C_STORAGE_READ_CMD into command slot before
    //reading. yuck. This is going to turn into:
    // start, write I2C_STORAGE_READ_CMD to 0, stop
    // start, write 1 to position
    // restart, read from 1
    //it would be better if it was
    // start, write I2C_STORAGE_READ_CMD to 0, restart, read from 1

    pkt.body.cmd = I2C_STORAGE_READ_CMD;
    slaveAddr = slaveAddr_;
    ret = call I2CRegisterUser.write(slaveAddr, 0, &pkt, 1);
    printf("%s: %s\n\r", __FUNCTION__, decodeError(ret));
    if (ret == SUCCESS){
      state |= (S_BUSY|S_READING);
    }
    return ret;
  }

  task void readTask(){
    //last byte will be garbage, lookout
    error_t ret = call I2CRegisterUser.read(slaveAddr, 1, &pkt,
      PERSISTENT_STORAGE_REGISTER_SIZE);
    printf("%s: %s\n\r", __FUNCTION__, decodeError(ret));
    if (ret != SUCCESS){
      state = 0;
      signal I2CPersistentStorageMaster.readDone(ret, readBuf);
    }
  }


  event void I2CRegisterUser.readDone(error_t error, 
      uint16_t slaveAddr_, uint8_t pos, 
      register_packet_t* pkt_, uint8_t len){
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
    memcpy(readBuf, pkt.data, PERSISTENT_STORAGE_REGISTER_SIZE);
    state = 0;
    signal I2CPersistentStorageMaster.readDone(error, readBuf);
  }
}
