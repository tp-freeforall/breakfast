#ifndef I2C_COM_H
#define I2C_COM_H

typedef nx_struct i2c_message_header_t {
  nxuint8_t clientId;
  nxuint8_t len;
} i2c_message_header_t;

typedef nx_struct i2c_message_t{
  union{
    nxuint8_t buf[I2C_MESSAGE_LEN + sizeof(i2c_message_header_t)];
    nx_struct{
      i2c_message_header_t header;
      nx_uint8_t buf[I2C_MESSAGE_LEN];
    } body;
  }
} i2c_message_t; 

#endif
