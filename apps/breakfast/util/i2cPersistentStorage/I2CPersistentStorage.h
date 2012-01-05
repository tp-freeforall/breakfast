#ifndef I2C_PERSISTENT_STORAGE_H
#define I2C_PERSISTENT_STORAGE_H
#include "I2CRegisterUser.h"
//#include "InternalFlash.h"

#define REGISTER_CLIENT_ID_STORAGE 0x02
#define I2C_STORAGE_READ_CMD 0x01
#define I2C_STORAGE_WRITE_CMD 0x02

#ifndef PERSISTENT_STORAGE_REGISTER_SIZE 
#define PERSISTENT_STORAGE_REGISTER_SIZE 64
#endif

#if PERSISTENT_STORAGE_REGISTER_SIZE > MAX_I2C_REGISTER_LEN
#error PERSISTENT_STORAGE_REGISTER_SIZE is greater than MAX_I2C_REGISTER_LEN.  Redefine MAX_I2C_REGISTER_LEN in order to use the I2CPersistenStorage app.
#endif

typedef nx_struct i2c_persistent_storage_t {
  nxuint8_t cmd;
  nxuint8_t data[IFLASH_SEGMENT_SIZE - 1];
}

#endif
