#ifndef RADIO_TEST_H
#define RADIO_TEST_H

#define AM_RADIO_TEST 0x01

typedef nx_struct test_settings_t {
  nx_uint32_t seqNum;
  nx_uint8_t isSender;
  nx_uint8_t powerIndex;
  nx_uint8_t hgm;
  nx_uint8_t channel;
  nx_uint8_t report;
  nx_uint16_t ipi;
  nx_uint8_t hasFe;
  nx_uint16_t testNum;
} test_settings_t;


#define NUM_POWER_LEVELS 1
int8_t POWER_LEVELS[NUM_POWER_LEVELS] =   {0};
int8_t POWER_SETTINGS[NUM_POWER_LEVELS] = {31};

//TODO: what is the actual limit on these? 256, I guess?
#define NUM_CHANNELS 255
#define CHANNEL_INCREMENT 16

#define LED_DOWNSAMPLE 128

#define MAX_RX_COUNTER 100

#define SHORT_IPI 32
//32 looks good (reporting OK + SA shows smooth output)
//nope, 32 triggers some TOO FAST at transmitter.
#define LONG_IPI 64


#endif
