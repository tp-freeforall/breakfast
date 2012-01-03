#ifndef REGISTER_USER_H
#define REGISTER_USER_H

#ifndef MAX_I2C_REGISTER_LEN
#define MAX_I2C_REGISTER_LEN 65
#endif

//should these be nx types?
typedef struct{
  uint8_t pos;
  uint8_t clientId;
} __attribute__((__packed__)) register_packet_header_t;

typedef struct{
  uint16_t slaveAddr;
  uint8_t len;
} __attribute__((__packed__)) register_packet_footer_t;

typedef struct{
  register_packet_header_t header;
  union{
    uint8_t data[MAX_I2C_REGISTER_LEN];
    struct {
      uint8_t cmd;
      uint8_t data[MAX_I2C_REGISTER_LEN - 1];
    } body;
  };
  register_packet_footer_t footer;
} __attribute__((__packed__)) register_packet_t;

#endif
