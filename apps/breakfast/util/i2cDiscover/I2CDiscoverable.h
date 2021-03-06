#ifndef I2C_DISCOVERABLE_H
#define I2C_DISCOVERABLE_H

#include "GlobalID.h"

#define I2C_DISCOVERY_INITIAL_TIMEOUT 30*1024
#define I2C_DISCOVERY_ROUND_TIMEOUT 512
#define I2C_RANDOMIZE_MAX_DELAY 256
#define I2C_DISCOVERY_POOL_SIZE 10

#define I2C_INVALID_MASTER 0xffff
#define I2C_DISCOVERABLE_UNASSIGNED 0xfffe

#define I2C_FIRST_DISCOVERABLE_ADDR 0x0040
#define I2C_GC_ADDR 0x00
#define I2C_DISCOVERABLE_REQUEST_ADDR 0xad

#define I2C_GC_PROGRAM_ADDR 0x04
#define I2C_GC_RESET_PROGRAM_ADDR 0x06

  typedef struct {
    uint8_t cmd;
    uint8_t globalAddr[GLOBAL_ID_LEN];
    uint16_t localAddr;
  } __attribute__((__packed__)) discoverer_register_t;

  typedef union{
    discoverer_register_t val;
    uint8_t data[sizeof(discoverer_register_t)];
  } __attribute__((__packed__)) discoverer_register_union_t;

#endif
