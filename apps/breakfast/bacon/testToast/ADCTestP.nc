#include "I2CCom.h"
#include "Msp430Adc12.h"
#include "I2CADCReader.h"


module ADCTestP{
  uses interface I2CADCReaderMaster;

  provides interface Get<const char*> as GetDesc;
  uses interface Get<test_state_t*>;
  uses interface UartStream;
  uses interface Timer<TMilli>;
} implementation {
  bool retry = FALSE;
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
    cmd->cfg[channelIndex].delayMS = sampleDelay;
    cmd->cfg[channelIndex].config.inch = newChannel;
    cmd->cfg[channelIndex].config.sref = REFERENCE_VREFplus_AVss;
    cmd->cfg[channelIndex].config.ref2_5v = REFVOLT_LEVEL_2_5;

    //TODO: check SMCLK settings, want this in uS
    //These configure the adc12clk, which is used as the basis for
    //  t_sample
    //
    // Resistance -> t_sample: 
    //  t_sample > (R_s + 2000)*3.6e-10+ 800e-9
    /**
     * R  
     * (k) t_sample
     *----+---------
     * 0   1.52087306778e-06
     * 5   3.32305573724e-06
     * 10  5.12523840669e-06
     * 15  6.92742107615e-06
     * 20  8.72960374561e-06
     * 25  1.05317864151e-05
     * 30  1.23339690845e-05
     * 35  1.4136151754e-05
     * 40  1.59383344234e-05
     * 45  1.77405170929e-05
     * 50  1.95426997623e-05
     * 55  2.13448824318e-05
     * 60  2.31470651013e-05
     * 65  2.49492477707e-05
     * 70  2.67514304402e-05
     * 75  2.85536131096e-05
     * 80  3.03557957791e-05
     * 85  3.21579784485e-05
     * 90  3.3960161118e-05
     * 95  3.57623437874e-05
     * 100 3.75645264569e-05
     */
    //this is set to 1 binary uS when sourced from SMCLK/1
    cmd->cfg[channelIndex].config.adc12ssel = SHT_SOURCE_SMCLK;
    cmd->cfg[channelIndex].config.adc12div = SHT_CLOCK_DIV_1;
    
    //This defines the sampling time in terms of divided adc12 clock
    //  cycles. 
    //t_sample = adc12clk_period * SAMPLE_HOLD_x_CYCLES
    // so, this can run for up to 1 mS when adc12clk is 1MHz.
    cmd->cfg[channelIndex].config.sht = SAMPLE_HOLD_1024_CYCLES;

    //These define the the sampling period.
    //If samplePeriod (jiffies) is 0, these don't matter (we directly set the
    //  ADC12SC bit when we want to take a sample). (sets SHSx to 0).
    //  When jiffies is 0, MSC is set, which means it will start
    //  each sample as soon as it finishes converting the previous.
    //If jiffies > 0, then these are used to reconfigure timerA
    //  (source/divider), (sets SHSx to 1)
    //  When jiffies > 0, MSC is cleared, meaning that successive
    //  samples are delayed until SHI triggers it again.
    //These are configured to use aclk (32khz crystal, undivided).
    cmd->cfg[channelIndex].samplePeriod = 0;
    cmd->cfg[channelIndex].config.sampcon_ssel = SAMPCON_SOURCE_ACLK;
    cmd->cfg[channelIndex].config.sampcon_id = SAMPCON_CLOCK_DIV_1;
    printf("Add %x with %lu delay\n\r", newChannel, sampleDelay);
    channelIndex++;  
  }

  task void printSettings(){
    uint8_t i;
    adc_reader_pkt_t* cmd = call I2CADCReaderMaster.getSettings(msg);
    printf("Settings\n\r");
    for (i=0; i < ADC_NUM_CHANNELS; i++){
      printf("  [%d] : %x ", i, cmd->cfg[i].config.inch);
      if (cmd->cfg[i].config.inch == INPUT_CHANNEL_NONE){
        printf("(None)\n\r");
        break;
      } else {
        printf("%lu\n\r", cmd->cfg[i].delayMS);
      }
    }
    printf(" Retry: %x\n\r", retry);
  }

  task void reset(){
    uint8_t i;
    adc_reader_pkt_t* cmd = call I2CADCReaderMaster.getSettings(msg);
    channelIndex = 0;
    for (i=0; i<ADC_NUM_CHANNELS; i++){
      cmd->cfg[i].config.inch = INPUT_CHANNEL_NONE;
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
    adc_reader_pkt_t* cmd = call I2CADCReaderMaster.getSettings(msg);
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
    if (response == NULL){
      printf("No response data\n\r");
      return responseMsg;
    }
    for (i = 0; i < ADC_NUM_CHANNELS; i++){
      cur = response->samples[i];
      printf(" MEASURE [%d]: ", i);
      if (cur.inputChannel == INPUT_CHANNEL_NONE){
        printf("(end)\n\r");
        break;
      }
      printf("%x\t%lu\t%d\t%lu\n\r", cur.inputChannel, cur.sampleTime,
        cur.sample, cmd->cfg[i].delayMS);
    }
    if (retry){
      call Timer.startOneShot(1024);
    }
    return responseMsg;
  }

  event void Timer.fired(){
    post sample();
  }

  bool firstUse = TRUE;


  async event void UartStream.receivedByte(uint8_t byte){
    if (firstUse){
      uint8_t i;
      adc_reader_pkt_t* cmd = call I2CADCReaderMaster.getSettings(msg);
      for(i = 0; i< ADC_NUM_CHANNELS; i++){
        cmd->cfg[i].config.inch = INPUT_CHANNEL_NONE;
      }
      firstUse = FALSE;
    }
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
      case 't':
        retry = !retry;
        printf("periodic retry: %d\n\r", retry);
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
