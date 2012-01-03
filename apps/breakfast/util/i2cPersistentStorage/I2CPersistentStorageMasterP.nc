#include "I2CPersistentStorage.h"
module I2CPersistentStorageMasterP{
  provides interface I2CPersistentStorageMaster;
  uses interface I2CRegisterUser;
} implementation {
  register_packet_t pkt;
  bool busy;
  void* readBuf;
  void* writeBuf;

  command error_t I2CPersistentStorageMaster.write(uint16_t slaveAddr,
      void* data){
    error_t ret;
    printf("%s: \n\r", __FUNCTION__);
    if (busy){
      return EBUSY;
    }
    //whelp, wish that I could figure out a better way to do this
    writeBuf = data;
    memcpy(pkt.body.data, data, PERSISTENT_STORAGE_REGISTER_SIZE - 1);
    pkt.body.cmd = I2C_STORAGE_WRITE_CMD;
    ret =  call I2CRegisterUser.write(slaveAddr, 0, &pkt,
      PERSISTENT_STORAGE_REGISTER_SIZE);
    if (ret == SUCCESS){
      busy = TRUE;
    } 
    return ret;
  }

  event void I2CRegisterUser.writeDone(error_t error, uint16_t slaveAddr, 
      uint8_t pos, uint8_t len, register_packet_t* pkt_){
    busy = FALSE;
    signal I2CPersistentStorageMaster.writeDone(error, writeBuf);
  }

  command error_t I2CPersistentStorageMaster.read(uint16_t slaveAddr,
      void* data){
    error_t ret;
    if (busy){
      return EBUSY;
    }
    readBuf = data;
    ret = call I2CRegisterUser.read(slaveAddr, 0, &pkt,
      PERSISTENT_STORAGE_REGISTER_SIZE);
    if (ret == SUCCESS){
      busy = TRUE;
    }
    return ret;
  }

  event void I2CRegisterUser.readDone(error_t error, 
      uint16_t slaveAddr, uint8_t pos, 
      register_packet_t* pkt_, uint8_t len){
    memcpy(readBuf, pkt.data, PERSISTENT_STORAGE_REGISTER_SIZE);
    busy = FALSE;
    signal I2CPersistentStorageMaster.readDone(error, readBuf);
  }
}
