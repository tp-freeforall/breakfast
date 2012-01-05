#ifndef I2C_TLV_STORAGE_H
#define I2C_TLV_STORAGE_H

#define REGISTER_CLIENT_ID_TLV_STORAGE 0x03

#define TLV_STORAGE_REGISTER_LEN 66

#define TLV_STORAGE_WRITE_CMD 0xa0
#define TLV_STORAGE_READ_CMD  0xa1

typedef union{
  uint8_t buf[TLV_LEN];
  struct{
    uint16_t cmd;
    uint8_t buf[TLV_LEN];
  } s __attribute__ ((aligned(16)));
} __attribute__((__packed__)) tlv_register_t;


#endif
