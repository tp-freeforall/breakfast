#include "I2CCom.h"
#include "I2CSynch.h"

module I2CSynchP{
  uses interface LocalTime<T32khz>;
  uses interface I2CComSlave;
} implementation {

  async event i2c_message_t* I2CComSlave.slaveTXStart(i2c_message_t* msg_){
    synch_response_t* response;
    uint32_t localTime = call LocalTime.get();
    response = (synch_response_t*)call I2CComSlave.getPayload(msg_);
    //oscillator fault detected
    if (BCSCTL3 & LFXT1OF){
      response -> remoteTime = 0;
      response -> fault = 1;
    } else {
      response -> remoteTime = localTime;
      response -> fault = 0;
    }
    return msg_;
  }

  task void stabilizeAclk(){
    uint16_t counter = 0xff;
    //wait a while if there's an oscillator fault detected.
    while (counter > 0 && BCSCTL3 & LFXT1OF){
      counter --;
    }
    call I2CComSlave.unpause();
  }

  async event i2c_message_t* I2CComSlave.received(i2c_message_t* msg_){
    synch_message_t* pl = (synch_message_t*) call I2CComSlave.getPayload(msg_);
    switch (pl->cmd){
      case SYNCH_CMD_READY:
        call I2CComSlave.pause();
        post stabilizeAclk();
        break;
      default:
        break;
    }
    return msg_;
  }
}
