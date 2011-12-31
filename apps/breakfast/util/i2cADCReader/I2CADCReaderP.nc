#include "I2CADCReader.h"
//TODO: should do VCC and internal temp measurements here, too.
//TODO: ADC calibration constants should be retrieved from an
//  I2CTLVStorage component
module I2CADCReaderP{
  uses interface I2CRegister;
  uses interface Msp430Adc12SingleChannel;
  uses interface Resource;
  uses interface GeneralIO[uint8_t channelNum] as SensorPower;
} implementation {
  uint16_t sampleBuffer[ADC_TOTAL_SAMPLES];
  adc_reader_pkt_t pkt;
  bool processingCommand;
  async event uint8_t* I2CRegister.transactionStart(bool isTransmit){
    processingCommand = (!isTransmit);
    if (processingCommand){
      return &pkt;
    } else {
      return (uint8_t*) sampleBuffer;
    }
  }

  async event uint8_t I2CRegister.registerLen(){
    
  }

  task void startSamples(){
    call Resource.request();
  }

  void nextSample(){
    adc_reader_config_t cfg = pkt.cfg[channelNum];
    call Msp430Adc12SingleChannel.configureMultiple(cfg.config, &buffer[channelStart], cfg.numSamples, cfg.jiffies);
    call Msp430Adc12SingleChannel.getData();
  }

  async event uint16_t* Msp430Adc12SingleChannel.multipleDataReady(uint16_t * buffer, uint16_t numSamples){
    //turn it off
    if (pkt.cfg[channelNum].inch <= 7){
      call SensorPower[pkt.cfg[channelNum].inch].clr();
    }
    //cool, data's in the buffer
    channelStart += pkt.cfg[channelNum].numSamples;
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
      call I2CRegister.unpause();
      //at some point, we'll get the transactionStart and read it back
      //Note that from the master's perspective, it will be able to
      //start the next transaction, but it won't be able to read/write
      //anything until we unpause here. If that disturbs the power
      //supply sufficiently to affect the ADC reading, then trouble
      //could ensue.
    } else {
      if (pkt.cfg[channelNum].inch <= 7){
        call SensorPower[pkt.cfg[channelNum]].set();
      }
      if (cfg.delayMS != 0){
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
    //TODO: timestamping: mark transactionStop time
    if (processingCommand && reg == &pkt 
        && pkt.command == ADC_READER_CMD_SAMPLE){
      call I2CRegister.pause();
      post startSamples();
    }else if (reg == sampleBuffer){
      //they finished reading from the sample buffer. word.
    }
  }

  default async command void SensorPower.set[uint8_t channelNum](){}
  default async command void SensorPower.clr()[uint8_t channelNum]{}
  default async command void SensorPower.toggle()[uint8_t channelNum]{}
  default async command bool SensorPower.get()[uint8_t channelNum]{}
  default async command void SensorPower.makeInput()[uint8_t channelNum]{}
  default async command bool SensorPower.isInput()[uint8_t channelNum]{}
  default async command void SensorPower.makeOutput()[uint8_t channelNum]{}
  default async command bool SensorPower.isOutput()[uint8_t channelNum]{}
}
