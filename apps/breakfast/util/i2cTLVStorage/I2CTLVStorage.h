#ifndef I2C_TLV_STORAGE_H
#define I2C_TLV_STORAGE_H

#define REGISTER_CLIENT_ID_TLV_STORAGE 0x03

#define TLV_STORAGE_REGISTER_LEN 65

#define TLV_STORAGE_WRITE_CMD 0xa0
#define TLV_STORAGE_READ_CMD  0xa1

typedef union{
  uint8_t buf[TLV_STORAGE_REGISTER_LEN];
  struct{
    uint8_t cmd;
    uint8_t buf[TLV_STORAGE_REGISTER_LEN - 1];
  } s;
} __attribute__((__packed__)) tlv_register_t;


#endif
