#ifndef I2C_PERSISTENT_STORAGE_H
#define I2C_PERSISTENT_STORAGE_H

#include "I2CCom.h"
#include "InternalFlash.h"

#define I2C_COM_CLIENT_ID_STORAGE 0x02

#define I2C_STORAGE_READ_CMD     0xb0
#define I2C_STORAGE_WRITE_CMD    0xb1
#define I2C_STORAGE_RESPONSE_CMD 0xb2


typedef nx_struct i2c_persistent_storage_t {
  nx_uint8_t cmd;
  nx_uint8_t data[IFLASH_SEGMENT_SIZE - 1];
} i2c_persistent_storage_t;

#if I2C_MESSAGE_LEN < IFLASH_SEGMENT_SIZE
#error "I2C_MESSAGE_LEN too small to support i2c persistent storage."
#endif

#endif
