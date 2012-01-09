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
    response->remoteTime = localTime;
    return msg_;
  }

  async event i2c_message_t* I2CComSlave.received(i2c_message_t* msg_){
    synch_message_t* pl = (synch_message_t*) call I2CComSlave.getPayload(msg_);
    switch (pl->cmd){
      case SYNCH_CMD_READY:
        //not actually used, just needed so that receive works
        //correctly.
        break;
      default:
        break;
    }
    return msg_;
  }
}
