#include "I2CCom.h"
interface I2CTLVStorageMaster{
  command void* getPayload(i2c_message_t* msg);
  
  command error_t loadTLVStorage(uint16_t slaveAddr, i2c_message_t* msg);
  event void loaded(error_t error, i2c_message_t* msg);

  command error_t persistTLVStorage(uint16_t slaveAddr, i2c_message_t* msg);
  event void persisted(error_t error, i2c_message_t* msg);
}
