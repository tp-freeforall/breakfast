#include "I2CCom.h"
interface I2CComMaster{
  command error_t send(uint16_t slaveAddr, i2c_message_t* msg);
  event void sendDone(error_t error, i2c_message_t* msg);

  command error_t receive(uint16_t slaveAddr, i2c_message_t* msg);
  event void receiveDone(error_t error, i2c_message_t* msg);
}
