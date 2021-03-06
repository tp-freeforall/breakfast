#ifndef I2C_TLV_STORAGE_H
#define I2C_TLV_STORAGE_H

#include "I2CCom.h"
#include "TLVStorage.h"

#define I2C_COM_CLIENT_ID_TLV_STORAGE 0x03

#define TLV_STORAGE_WRITE_CMD 0xa0
#define TLV_STORAGE_READ_CMD  0xa1
#define TLV_STORAGE_RESPONSE_CMD  0xa2

//this is fairly hacky: we need the data to be word-aligned for the
//  checksumming to work correctly.
typedef nx_struct{
  nx_uint16_t cmd;
  nx_uint16_t data[TLV_LEN / sizeof(nx_uint16_t)];
} i2c_tlv_storage_t;

#if I2C_MESSAGE_LEN < TLV_LEN + 2
#error "I2C_MESSAGE_LEN too small to support i2c TLV storage."
#endif

#endif
