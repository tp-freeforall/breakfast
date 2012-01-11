#include "I2CADCReader.h"
//TODO: add timestamps to each reading
module I2CADCReaderP{
  uses interface I2CRegister;
  uses interface Msp430Adc12SingleChannel;
  uses interface Resource;
  uses interface GeneralIO as SensorPower[uint8_t channelNum];
  uses interface Timer<TMilli>;
  uses interface LocalTime<T32khz>;
} implementation {
  uint16_t medianBuf[ADC_NUM_SAMPLES];
  i2c_message_t msg_internal;
  i2c_message_t* msg = &msg_internal;
  adc_response_t* response;


  bool processingCommand;
  uint8_t channelNum;
  uint8_t channelStart;

  task void readyNextSample();

  async event uint8_t* I2CRegister.transactionStart(bool isTransmit){
    processingCommand = (!isTransmit);
    if (processingCommand){
      return (uint8_t*)&pkt;
    } else {
      return (uint8_t*) sampleBuffer;
    }
  }

  async event uint8_t I2CRegister.registerLen(){
    if (processingCommand){
      return sizeof(pkt);
    } else {
      return sizeof(uint16_t) * ADC_TOTAL_SAMPLES;
    }
  }

  task void startSamples(){
    call Resource.request();
  }

  void nextSample(){
    adc_reader_config_t cfg = pkt.cfg[channelNum];
    call Msp430Adc12SingleChannel.configureMultiple(&cfg.config, medianBuf, cfg.numSamples, cfg.jiffies);
    response->samples[channelNum].sampleTime = call LocalTime.get();
    call Msp430Adc12SingleChannel.getData();
  }

  uint16_t median(uint16_t* mb, uint8_t len){
    
  }

  async event uint16_t* Msp430Adc12SingleChannel.multipleDataReady(uint16_t * buffer, uint16_t numSamples){
    uint32_t sampleEnd = call LocalTime.get();
    uint32_t sampleMid;
    //turn it off
    if (pkt.cfg[channelNum].config.inch <= 7){
      call SensorPower.clr[pkt.cfg[channelNum].config.inch]();
    }
    //cool, data's in the buffer
    response->samples[channelNum].inputChannel = pkt.cfg[channelNum].config.inch;
    response->samples[channelNum].sampleTime = (response->samples[channelNum].sampleTime + sampleEnd) >> 1;
    response->samples[channelNum].sample = median(medianBuf, );
    channelNum++;
    post readyNextSample();
    //according to interface, return value is ignored for this
    //invocation (since we used configureMultiple)
    return NULL; 
  }

  event void Timer.fired(){
    nextSample();
  }

  task void readyNextSample(){
    //skip to next used channel
    while (pkt.cfg[channelNum].numSamples == 0 && channelNum < ADC_NUM_CHANNELS){
      channelNum++;
    }
    if ( channelNum == ADC_NUM_CHANNELS){
      //done
      call Resource.release();
      call I2CRegister.unPause();
      //at some point, we'll get the transactionStart and read it back
      //Note that from the master's perspective, it will be able to
      //start the next transaction, but it won't be able to read/write
      //anything until we unpause here. If that disturbs the power
      //supply sufficiently to affect the ADC reading, then trouble
      //could ensue.
    } else {
      if (pkt.cfg[channelNum].config.inch <= 7){
        call SensorPower.set[pkt.cfg[channelNum].config.inch]();
      }
      if (pkt.cfg[channelNum].delayMS != 0){
        call Timer.startOneShot(pkt.cfg[channelNum].delayMS);
      } else{
        nextSample();
      }
    }
  }

  event void Resource.granted(){
    channelNum = 0;
    channelStart = 0;
    post readyNextSample();
  }

  
  async event void I2CRegister.transactionStop(uint8_t* reg, 
      uint8_t pos){ 
    if (processingCommand 
        && ((void*)reg == (void*)(&pkt))
        && (pkt.cmd == ADC_READER_CMD_SAMPLE)){
      call I2CRegister.pause();
      post startSamples();
    }else if ((void*)reg == (void*)sampleBuffer){
      //they finished reading from the sample buffer. word.
    }
  }

  //unused
  async event error_t Msp430Adc12SingleChannel.singleDataReady(uint16_t data){ return FAIL;}
  
  //defaults
  default async command void SensorPower.set[uint8_t channelNum_](){}
  default async command void SensorPower.clr[uint8_t channelNum_](){}
  default async command void SensorPower.toggle[uint8_t channelNum_](){}
  default async command bool SensorPower.get[uint8_t channelNum_](){}
  default async command void SensorPower.makeInput[uint8_t channelNum_](){}
  default async command bool SensorPower.isInput[uint8_t channelNum_](){}
  default async command void SensorPower.makeOutput[uint8_t channelNum_](){}
  default async command bool SensorPower.isOutput[uint8_t channelNum_](){}
}
