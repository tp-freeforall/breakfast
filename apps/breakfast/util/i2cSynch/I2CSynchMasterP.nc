#include "I2CCom.h"
#include "I2CSynch.h"

module I2CSynchMasterP{
  uses interface I2CComMaster;
  uses interface LocalTime<T32khz>;
  provides interface I2CSynchMaster;
} implementation {
  uint32_t localTime;
  i2c_message_t msg_internal;
  i2c_message_t* msg = &msg_internal;
  bool busy;

  command error_t I2CSynchMaster.synch(uint16_t slaveAddr){
    error_t ret;
    synch_message_t* payload = (synch_message_t*) call I2CComMaster.getPayload(msg);
    if (busy){
      return EBUSY;
    }
    payload->cmd = SYNCH_CMD_READY;
    ret = call I2CComMaster.send(slaveAddr, msg, sizeof(synch_message_t));
    if (ret == SUCCESS){
      busy = TRUE;
    }
    return ret;
  }

  task void readTask();

  event void I2CComMaster.sendDone(error_t error, i2c_message_t* msg_){
    if (error == SUCCESS){
      post readTask();
    } else {
      synch_tuple_t ret = {0, 0};
      busy = FALSE;
      signal I2CSynchMaster.synchDone(error,
        msg->body.header.slaveAddr, ret);
    }
  }

  task void readTask(){
    error_t error;
    synch_tuple_t ret = {0, 0};
    localTime = call LocalTime.get();
    error = call I2CComMaster.receive(msg->body.header.slaveAddr, msg,
      sizeof(nx_uint32_t));
    if (error != SUCCESS){
      busy = FALSE;
      signal I2CSynchMaster.synchDone(error, msg->body.header.slaveAddr, ret);
    }
  }

  event void I2CComMaster.receiveDone(error_t error, i2c_message_t*
  msg_){
    synch_tuple_t ret = {0, 0};
    if (error != SUCCESS){
      busy = FALSE;
      signal I2CSynchMaster.synchDone(error,
        msg->body.header.slaveAddr, ret);
      return;
    } else {
      synch_response_t* pl = (synch_response_t*) call
        I2CComMaster.getPayload(msg);
      ret.localTime = localTime;
      ret.remoteTime = pl->remoteTime;
      busy = FALSE;
      signal I2CSynchMaster.synchDone(SUCCESS,
        msg->body.header.slaveAddr, ret);
    }
  }

}
