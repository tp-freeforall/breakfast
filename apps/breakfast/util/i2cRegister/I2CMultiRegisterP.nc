#include "I2CMultiRegister.h"

generic module I2CMultiRegisterP () {
  provides interface I2CRegister[uint8_t clientId];
  provides interface SplitControl;
  uses interface Resource;
  uses interface I2CSlave;
} implementation {
  //nb: pos here is maintained from the master's perspective: to them,
  //  it appears that index 0 is the client ID, index 1 is where the cmd
  //  is stored, and data starts at index 2.
  //nb: using % to wrap the buffer is really just meant to prevent
  //  out-of-bounds access. the extra logic required to allow wrapping
  //  AND let activeClient be at "index 0" is not worth it for this
  //  rare case
  uint8_t pos;
  uint8_t* buf;
  uint8_t bufLen;
  uint8_t transCount;
  bool isGC;
  bool isPaused = FALSE;
  bool receivePending = FALSE;
  bool transmitPending = FALSE;
  
  enum{
    I2C_MULTI_REGISTER_INVALID = 0xff,
  };

  uint8_t activeClient = I2C_MULTI_REGISTER_INVALID;

  void transmit();
  void receive();

  async command error_t I2CRegister.pause[uint8_t clientId](){
    printf("%s: \n\r", __FUNCTION__);
    if (clientId == activeClient){
      if (isPaused){
        return EALREADY;
      } else {
        isPaused = TRUE;
        return SUCCESS;
      }
    } else {
      return EBUSY;
    }
  }

  async command error_t I2CRegister.unPause[uint8_t clientId](){
    printf("%s: \n\r", __FUNCTION__);
    if (clientId == activeClient){
      if (!isPaused){
        isPaused = FALSE;
        if (receivePending && transmitPending){
          return FAIL;
        }
        if (transmitPending){
          transmit();
        } else if (receivePending){
          receive();
        }
        return SUCCESS;
      } else {
        return EALREADY;
      }
    } else {
      return EBUSY;
    }
  }

  command error_t SplitControl.start(){
    return call Resource.request();
  }

  task void stopDone(){
    signal SplitControl.stopDone(SUCCESS);
  }

  command error_t SplitControl.stop(){
    error_t ret = call Resource.release();
    printf("%s: \n\r", __FUNCTION__);
    if (ret == SUCCESS){
      post stopDone();
    }
    return ret;
  }

  event void Resource.granted(){
    signal SplitControl.startDone(SUCCESS);
  }

  void receive(){
    buf[(pos-1)%bufLen] = call I2CSlave.slaveReceive();
    pos++;
    transCount++;
    receivePending = FALSE;
  }

  void transmit(){
    call I2CSlave.slaveTransmit(buf[(pos-1)%bufLen]);
    pos++;
    transCount++;
    transmitPending = FALSE;
  }
  
  async event bool I2CSlave.slaveReceiveRequested(){
    if (isGC){
      //ignore
      call I2CSlave.slaveReceive();
      return TRUE;
    }
    if (transCount == 0){
      buf = signal I2CRegister.transactionStart[activeClient](FALSE);
      bufLen = signal I2CRegister.registerLen[activeClient]();
    }
    if (transCount == 0){
      pos = call I2CSlave.slaveReceive();
      transCount++;
      return TRUE;
    } else {
      if (pos == 0){
        activeClient = call I2CSlave.slaveReceive();
        pos++;
        transCount ++;
        return TRUE;
      } else {
        if (isPaused){
          receivePending = TRUE;
          return FALSE;
        } else {
          receive();
          return TRUE;
        }
      }
    }
  }

  //master tries to read: alert activeClient that a transaction is
  //  starting so that they can provide the buffer from which the
  //  master will read and pause it if needed.
  async event bool I2CSlave.slaveTransmitRequested(){
    if (isGC){
      //ignore
      call I2CSlave.slaveTransmit(0xff);
      return TRUE;
    }
    if(transCount == 0){
      buf = signal I2CRegister.transactionStart[activeClient](TRUE);
      bufLen = signal I2CRegister.registerLen[activeClient]();
    } 
    if (isPaused){
      transmitPending = TRUE;
      return FALSE;
    } else {
      transmit();
      return TRUE;
    }

  }
  
  async event void I2CSlave.slaveStart(bool generalCall){
    isGC = generalCall;
    transCount = 0;
  }

  async event void I2CSlave.slaveStop(){
    printf("%s: \n\r", __FUNCTION__);
    if (! isGC){
      signal I2CRegister.transactionStop[activeClient](buf, pos);
    }
  }

  default async event void I2CRegister.transactionStop[uint8_t clientId](
      uint8_t* reg, uint8_t pos_){
    printf("%s: \n\r", __FUNCTION__);
  }
  
  uint8_t default_buffer;
  default async event uint8_t* I2CRegister.transactionStart[uint8_t clientId](bool isWrite){
    printf("%s: \n\r", __FUNCTION__);
    return &default_buffer;
  }
  default async event uint8_t I2CRegister.registerLen[uint8_t clientId](){
    printf("%s: \n\r", __FUNCTION__);
    return sizeof(default_buffer);
  }
}
