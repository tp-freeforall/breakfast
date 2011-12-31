#ifndef TLVSTORAGE_H
#define TLVSTORAGE_H
//See msp430f235.h for TAG_DCO_30, TAG_ADC12_1, TAG_EMPTY, and other
//  constants

#define TAG_VERSION    (0x02)
#define TAG_DCO_CUSTOM (0x03)
//flag value for "match any tag"
#define TAG_ANY        (0x00)

#define TLV_CHECKSUM_LENGTH 2

#define TLV_LEN IFLASH_SEGMENT_SIZE

typedef struct {
  uint8_t tag;
  uint8_t len;
  union{
    uint8_t b[0];
    uint16_t w[0];
  } data;
} tlv_entry_t;

typedef struct{
  tlv_entry_t header;
  uint16_t version;
} version_entry_t;

typedef struct{
  tlv_entry_t header;
  uint8_t bcsctl1;
  uint8_t dcoctl;
} custom_dco_entry_t;
#endif
