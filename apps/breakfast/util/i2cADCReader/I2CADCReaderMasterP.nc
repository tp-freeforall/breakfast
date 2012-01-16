#include "I2CADCReader.h"
module I2CADCReaderMasterP{
  provides interface I2CADCReaderMaster;
  uses interface I2CComMaster;
  uses interface Timer<TMilli>;
} implementation {
  uint16_t slave;
  i2c_message_t* cmdMsg;
  i2c_message_t responseMsg_internal;
  i2c_message_t* responseMsg = &responseMsg_internal;

  enum {
    S_IDLE = 0x00,
    S_BUSY = 0x80,
    S_WRITING = 0x01,
    S_WAITING = 0x02,
    S_READING = 0x04,
  };

  command adc_reader_pkt_t* I2CADCReaderMaster.getPayload(i2c_message_t* msg){
    return (adc_reader_pkt_t*)call I2CComMaster.getPayload(msg);
  }

  command error_t I2CADCReaderMaster.sample(uint16_t slaveAddr,
      i2c_message_t* msg){
    error_t ret;
    adc_reader_pkt_t* settings;
    if (state & S_BUSY){
      return EBUSY;
    }
    cmdMsg = msg;
    settings = call I2CADCReaderMaster.getPayload(cmdMsg);
    settings->cmd = ADC_READER_CMD_SAMPLE;
    ret = call I2CComMaster.send(slaveAddr, cmdMsg, sizeof(adc_reader_pkt_t));
    if (ret == SUCCESS){
      state = (S_BUSY|S_WRITING);
    }
    return ret;
  }

  event void I2CComMaster.sendDone(error_t error, i2c_message_t* msg){
    uint8_t i;
    uint32_t delay = 0;
    adc_reader_pkt_t* settings = call I2CADCReaderMaster.getPayload(cmdMsg);
    //TODO: verify msg==cmdMsg
    if (error == SUCCESS){
      for (i = 0; i< ADC_NUM_CHANNELS && pl->cfg[i].config.inch !=NO_SAMPLE; i++){
        delay += settings->cfg[i].delayMS + CHANNEL_DELAY;
        //TODO: also get the sample/hold time numbers
      }
      call Timer.startOneShot(delay);
      state = S_BUSY | S_WAITING;
    } else {
      state = S_IDLE;
      responseMsg = signal I2CADCReaderMaster.sampleDone(error,
        cmdMsg->body.header.slaveAddr, cmdMsg, responseMsg);
    }
  }

  event void Timer.fired(){
    error_t error = call
    I2CComMaster.receive(cmdMsg->body.header.slaveAddr, responseMsg,
      sizeof(adc_response_t));
    if (error != SUCCESS){
      state = S_IDLE;
      responseMsg = signal I2CComMaster.receiveDone(error,
        cmdMsg->body.header.slaveAddr, cmdMsg, responseMsg);
    } else {
      state = S_BUSY | S_READING;
    }
  }

  event void I2CComMaster.receiveDone(error_t error, i2c_message_t*
      rMsg){
    //TODO: verify rMsg == responseMsg
    state = S_IDLE;
    responseMsg = signal I2CADCReaderMaster.sampleDone(error,
      cmdMsg->body.header.slaveAddr, cmdMsg, responseMsg);
  }
}
