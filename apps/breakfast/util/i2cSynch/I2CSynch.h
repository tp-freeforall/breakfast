#ifndef I2C_SYNCH_H
#define I2C_SYNCH_H

#define I2C_COM_CLIENT_ID_SYNCH 0x04

#define SYNCH_CMD_READY 0x0a

typedef struct synch_tuple_t{
  uint32_t localTime;
  uint32_t remoteTime;
} synch_tuple_t;

typedef nx_struct synch_message_t{
  nx_uint8_t cmd;
}synch_message_t;

typedef nx_struct synch_response_t{
  nx_uint32_t remoteTime;
}synch_response_t;

#endif
