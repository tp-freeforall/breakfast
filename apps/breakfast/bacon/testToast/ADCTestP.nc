#include "I2CCom.h"
#include "I2CADCReader.h"


module ADCTestP{
  uses interface I2CADCReaderMaster;

  provides interface Get<const char*> as GetDesc;
  uses interface Get<test_state_t*>;
  uses interface UartStream;
} implementation {
  const char* testDesc = "ADC test:\n\r s: sample\n\r [0-f]: add input channel to sample command\n\r R: reset settings\n\r ?: print settings\n\r i: Increment sample delay\n\r D: reset sample delay to 0"; 

  command const char* GetDesc.get(){
    return testDesc;
  }
  
  i2c_message_t msg_internal;
  i2c_message_t* msg = &msg_internal;

  norace uint8_t newChannel;
  uint8_t channelIndex = 0;
  uint32_t sampleDelay = 0;
  
  //units are binary milliseconds
  #define SAMPLE_DELAY_INCREMENT 256

  task void addChannel(){
    adc_reader_pkt_t* cmd = call I2CADCReaderMaster.getSettings(msg);
    cmd->cfg[channelIndex].config.inch = newChannel;
    cmd->cfg[channelIndex].delayMS = sampleDelay;
    printf("Add %x with %lu delay\n\r", newChannel, sampleDelay);
    channelIndex++;  
  }

  task void printSettings(){
    uint8_t i;
    adc_reader_pkt_t* cmd = call I2CADCReaderMaster.getSettings(msg);
    printf("Settings\n\r");
    for (i=0; i < ADC_NUM_CHANNELS; i++){
      printf("  [%d] : %x ", i, cmd->cfg[i].config.inch);
      if (cmd->cfg[i].config.inch == NO_SAMPLE){
        printf("(None)\n\r");
        break;
      } else {
        printf("%lu\n\r", cmd->cfg[i].delayMS);
      }
    }
  }

  task void reset(){
    uint8_t i;
    adc_reader_pkt_t* cmd = call I2CADCReaderMaster.getSettings(msg);
    channelIndex = 0;
    for (i=0; i<ADC_NUM_CHANNELS; i++){
      cmd->cfg[i].config.inch = NO_SAMPLE;
    }
    sampleDelay = 0;
    printf("ADC config reset.\n\r");
    post printSettings();
  }

  task void incrementDelay(){
    sampleDelay += SAMPLE_DELAY_INCREMENT;
    printf("Delay: %lu\n\r", sampleDelay);
  }

  task void resetDelay(){
    sampleDelay = 0;
    printf("Reset Delay: %lu\n\r", sampleDelay);
  }

  task void sample(){
    test_state_t* state = call Get.get();
    error_t error;
    if (state->slaveCount == 0){
      printf("No slaves, hit 'd' to discover\n\r");
      return;
    } else{
      error = call I2CADCReaderMaster.sample(
        state->slaves[state->currentSlave], msg);
      printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
    }
  }

  event i2c_message_t* I2CADCReaderMaster.sampleDone(error_t error, uint16_t slaveAddr,
      i2c_message_t* cmdMsg, i2c_message_t* responseMsg, 
      adc_response_t* response){
    uint8_t i;
    adc_sample_t cur;
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
    if (response == NULL){
      printf("No response data\n\r");
      return responseMsg;
    }
    for (i = 0; i < ADC_NUM_CHANNELS; i++){
      cur = response->samples[i];
      printf(" [%d]: ", i);
      if (cur.inputChannel == NO_SAMPLE){
        printf("(end)\n\r");
        break;
      }
      printf("%x\t%lu\t%d\n\r", cur.inputChannel, cur.sampleTime,
        cur.sample);
    }
    return responseMsg;
  }

  async event void UartStream.receivedByte(uint8_t byte){
    switch(byte){
      case 's':
        post sample();
        break;
      case '?':
        post printSettings();
        break;
      case 'R':
        post reset();
        break;
      case 'i':
        post incrementDelay();
        break;
      case 'D':
        post resetDelay();
        break;
      case '\r':
        printf("\n\r");
        break;
      default:
        //0-9
        if (byte >= 0x30 && byte <= 0x39){
          newChannel = byte - 0x30;
          printf("Add %c\n\r", byte);
          post addChannel();
        //a-f
        } else if (byte >= 0x61 && byte <= 0x66){
          newChannel = 0x0a + (byte - 0x61);
          printf("Add %c\n\r", byte);
          post addChannel();
        //other
        } else {
          printf("%c", byte);
        }
    }
  }

  async event void UartStream.receiveDone( uint8_t* buf_, uint16_t len,
    error_t error ){}
  async event void UartStream.sendDone( uint8_t* buf_, uint16_t len,
    error_t error ){}
 

}
