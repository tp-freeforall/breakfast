#ifndef I2C_COM_H
#define I2C_COM_H

#ifndef I2C_MESSAGE_LEN
#define I2C_MESSAGE_LEN 64
#endif

typedef nx_struct i2c_message_header_t {
  nx_uint16_t slaveAddr;
  nx_uint8_t clientId;
  nx_uint8_t len;
} i2c_message_header_t;

typedef nx_union i2c_message_t{
  nx_uint8_t buf[I2C_MESSAGE_LEN + sizeof(i2c_message_header_t)];
  nx_struct{
    i2c_message_header_t header;
    nx_uint8_t buf[I2C_MESSAGE_LEN];
  } body;
} i2c_message_t; 

#endif
