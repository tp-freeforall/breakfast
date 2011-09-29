#include "Msp430Adc12.h"

module PlatformBatteryVoltageP {
  provides interface AdcConfigure<const msp430adc12_channel_config_t *>;
  provides interface SplitControl;
  provides interface Init;
  uses interface GeneralIO as EnablePin;
}
implementation {

  const msp430adc12_channel_config_t config = {
      inch: INPUT_CHANNEL_A0,
      sref: REFERENCE_VREFplus_AVss,
      ref2_5v: REFVOLT_LEVEL_2_5,
      adc12ssel: SHT_SOURCE_ACLK,
      adc12div: SHT_CLOCK_DIV_1,
      sht: SAMPLE_HOLD_4_CYCLES,
      sampcon_ssel: SAMPCON_SOURCE_SMCLK,
      sampcon_id: SAMPCON_CLOCK_DIV_1
  };
  
  async command const msp430adc12_channel_config_t* AdcConfigure.getConfiguration() {
    return &config;
  }

  bool on = FALSE;
  command error_t Init.init(){
    call EnablePin.makeOutput();
    call EnablePin.clr();
    return SUCCESS;
  }

  task void startDoneTask(){
    signal SplitControl.startDone(SUCCESS);
  }
  task void stopDoneTask(){
    signal SplitControl.stopDone(SUCCESS);
  }

  command error_t SplitControl.start(){
    if (on){
      return EALREADY;
    }else {
      on = TRUE;
      call EnablePin.set();
      post startDoneTask();
      return SUCCESS;
    }
  }

  command error_t SplitControl.stop(){
    if (on){
      on = FALSE;
      call EnablePin.clr();
      post stopDoneTask();
      return SUCCESS;
    } else {
      return EALREADY;
    }
  }

  default event void SplitControl.startDone(error_t err){}
  default event void SplitControl.stopDone(error_t err){}
}

