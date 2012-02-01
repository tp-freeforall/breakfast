#ifndef RADIO_TEST_H
#define RADIO_TEST_H

#define AM_RADIO_TEST 0x01

typedef nx_struct test_settings_t {
  nx_uint16_t seqNum;
  nx_uint8_t isSender;
  nx_uint8_t powerIndex;
  nx_uint8_t hgm;
  nx_uint8_t channel;
  nx_uint8_t report;
  nx_uint16_t ipi;
} test_settings_t;


#define NUM_POWER_LEVELS 4
int8_t POWER_LEVELS[NUM_POWER_LEVELS] =   {-12,  -6,   0,    10 };
int8_t POWER_SETTINGS[NUM_POWER_LEVELS] = {0x25, 0x2d, 0x8d, 0xc3 };

//TODO: what is the actual limit on these? 256, I guess?
#define NUM_CHANNELS 8

#define TX_LED_DOWNSAMPLE 128

#define SHORT_IPI 1
//32 looks good, 16 too fast
#define LONG_IPI 32

#endif
