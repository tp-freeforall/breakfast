#ifndef I2C_ADCREADER_H
#define I2C_ADCREADER_H

#include "Msp430Adc12.h"

#define REGISTER_CLIENT_ID_ADCREADER 0x03
#define ADC_READER_CMD_SAMPLE 0x03

#ifndef ADC_READER_MAX_SAMPLES
#define ADC_READER_MAX_SAMPLES_PER_CHANNEL 5
#endif

#ifndef ADC_NUM_CHANNELS
#define ADC_NUM_CHANNELS 8
#endif

#define ADC_TOTAL_SAMPLES ADC_NUM_CHANNELS * ADC_READER_MAX_SAMPLES_PER_CHANNEL

//see Msp430Adc12SingleChannel.nc for details: these get passed
//  straight through to that interface.
//  delayMS is used to instruct the reader that it should wait for
//  some timeout after turning on sensors but before starting the ADC
//  module (e.g. so that the master can enter LPM, or so that sensors
//  can warm up).
typedef struct {
  uint32_t delayMS;
  msp430adc12_channel_config_t config;
  uint16_t numSamples;
  uint16_t jiffies;
} adc_reader_config_t;

//a packet consists of a set of these configs: up to 1 per sensor
// this way, we only have one sensor on at a time, and we can specify
// for each sensor how it needs to be warmed up/how many times it
// should get sampled. 
typedef struct {
  uint8_t cmd;
  adc_reader_config_t cfg[ADC_NUM_CHANNELS];
} __attribute__((__packed__)) adc_reader_pkt_t;

#endif
