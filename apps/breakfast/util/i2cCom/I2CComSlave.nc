#include "I2CCom.h"

interface I2CComSlave {
  //indicates "We have been asked to transmit data. Here is a free
  //  buffer. Give me a buffer to use to field the coming requests"
  async event i2c_message_t* slaveTXStart(i2c_message_t* msg);
  

  //indicates "We just received some data, which is in this buffer.
  //  Give me a free buffer that I can use for the next data that we
  //  receive"
  async event i2c_message_t* received(i2c_message_t* msg);
  
  //tell the I2CComSlave to hold the bus: This could be called, for
  //  instance, if we receive a "send me some data" packet, but we
  //  need to do some stuff before we can provide a usable buffer for
  //  fielding upcoming tx requests.
  async command error_t pause();
  async command error_t unPause();
}
