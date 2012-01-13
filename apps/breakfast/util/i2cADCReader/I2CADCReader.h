#ifndef I2C_ADCREADER_H
#define I2C_ADCREADER_H

#include "Msp430Adc12.h"

#define I2C_COM_CLIENT_ID_ADCREADER 0x01
#define ADC_READER_CMD_SAMPLE 0x0c

#ifndef ADC_NUM_SAMPLES
#define ADC_NUM_SAMPLES 5
#endif

//8 external, (Vcc-Vss)/2, temp
#ifndef ADC_NUM_CHANNELS
#define ADC_NUM_CHANNELS 8 + 2
#endif

//marker for "stop reading now"
#define NO_SAMPLE 0xff

#define ADC_TOTAL_SAMPLES ADC_NUM_CHANNELS * ADC_READER_MAX_SAMPLES_PER_CHANNEL

//see Msp430Adc12SingleChannel.nc for details: these get passed
//  straight through to that interface.
//  delayMS is used to instruct the reader that it should wait for
//  some timeout after turning on sensors but before starting the ADC
//  module (e.g. so that the master can enter LPM, or so that sensors
//  can warm up).
typedef struct adc_reader_config_t {
  uint32_t delayMS;
  msp430adc12_channel_config_t config;
  uint16_t jiffies;
} adc_reader_config_t;

//a packet consists of a set of these configs: up to 1 per sensor
//  (plus one for input voltage and one for internal temp)
// this way, we only have one sensor on at a time, and we can specify
// for each sensor how it needs to be warmed up/how many times it
// should get sampled. 
typedef struct adc_reader_pkt_t{
  uint8_t cmd;
  adc_reader_config_t cfg[ADC_NUM_CHANNELS];
} __attribute__((__packed__)) adc_reader_pkt_t;


typedef nx_struct adc_sample_t {
  nx_uint8_t inputChannel;
  nx_uint32_t sampleTime;
  nx_uint16_t sample;
} adc_sample_t;

typedef nx_struct adc_response_t {
  adc_sample_t samples[ADC_NUM_CHANNELS];
} adc_response_t;

#endif
