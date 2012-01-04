#ifndef TLVSTORAGE_H
#define TLVSTORAGE_H

#define TAG_VERSION    (0x02)
#define TAG_DCO_CUSTOM (0x03)
//flag value for "match any tag"
#define TAG_ANY        (0x00)

//See msp430f235.h for TAG_DCO_30, TAG_ADC12_1, TAG_EMPTY, and other
//  constants. OK, the cc430f5137 uses different conventions, awesome.
#ifndef TAG_EMPTY
#define TAG_EMPTY (0xfe)
#endif
#ifndef TAG_DCO_30
#define TAG_DCO_30 (0x01)
#endif
#ifndef TAG_ADC12_1
#define TAG_ADC12_1 (0x08)
#endif

#define TLV_CHECKSUM_LENGTH 2

#ifndef TLV_LEN
#define TLV_LEN 64
#endif

typedef struct {
  uint8_t tag;
  uint8_t len;
  union{
    uint8_t b[0];
    uint16_t w[0];
  } data;
} __attribute__((__packed__)) tlv_entry_t;

typedef struct{
  tlv_entry_t header;
  uint16_t version;
} __attribute__((__packed__)) version_entry_t;

typedef struct{
  tlv_entry_t header;
  uint8_t bcsctl1;
  uint8_t dcoctl;
} __attribute__((__packed__)) custom_dco_entry_t;
#endif
