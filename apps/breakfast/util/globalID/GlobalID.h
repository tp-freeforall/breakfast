#ifndef GLOBAL_ID_H
#define GLOBAL_ID_H

#include "TLVStorage.h"

#define TAG_GLOBAL_ID (0x04)

#ifndef GLOBAL_ID_LEN
#define GLOBAL_ID_LEN 8
#else
#warning "Using non-standard GLOBAL_ID_LEN!"
#endif

typedef struct{
  tlv_entry_t header;
  uint8_t id[GLOBAL_ID_LEN];
} global_id_entry_t;


#endif
