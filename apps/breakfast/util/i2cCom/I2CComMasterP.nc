#include "I2CCom.h"

generic module I2CComMasterP(uint8_t clientId){
  provides interface I2CComMaster;
  uses interface I2CPacket<TI2CBasicAddr>;
  uses interface Resource;
} implementation {
  norace i2c_message_t* msg;

  enum {
    S_WRITE_REQUESTED = 0x01,
    S_WRITING = 0x02,
    S_READ_REQUESTED = 0x03,
    S_SEEKING = 0x04,
    S_READING = 0x05,
    S_IDLE = 0x06,
  };

  uint8_t state;
  norace error_t signalError;
  i2c_message_t* msg;

  task void signalSendDone();
  task void signalReceiveDone();
  void release();
  task void read();

  command void* I2CComMaster.getPayload(i2c_message_t* msg_){
    return &msg_->body.buf;
  }

  command error_t I2CComMaster.send(uint16_t slaveAddr,
      i2c_message_t* msg_, uint8_t payloadLen){
    error_t ret = call Resource.request();
    printf("%s: \n\r", __FUNCTION__);
    if ( ret == SUCCESS ){
      msg = msg_;
      msg->body.header.slaveAddr = slaveAddr;
      msg->body.header.clientId = clientId;
      msg->body.header.len = payloadLen + sizeof(i2c_message_header_t);
      printf("Payload len %d packet len %d\n\r", payloadLen,
        msg->body.header.len);
      state = S_WRITE_REQUESTED;
    } 
    return ret;
  }

  task void write(){
    error_t error;
    printf("writing %d bytes\n\r", msg->body.header.len);
    P1OUT |= BIT1;
    error = call I2CPacket.write(I2C_START|I2C_STOP,
      msg->body.header.slaveAddr, 
      msg->body.header.len, 
      (uint8_t*)msg->buf); 
    P1OUT &= ~BIT1;
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
    if (error != SUCCESS){
      signalError = error;
      post signalSendDone();
    } else {
      state = S_WRITING;
    }
  }

  async event void I2CPacket.writeDone(error_t error, uint16_t addr,
      uint8_t length, uint8_t* data){
    signalError = error;
    msg->body.header.len = length;
    post signalSendDone();
  }

  task void signalSendDone(){
    printf("%s: %s\n\r", __FUNCTION__, decodeError(signalError));
    release();
    signal I2CComMaster.sendDone(signalError, msg);
  }

  void release(){
    printf("%s: \n\r", __FUNCTION__);
    atomic{
      call Resource.release();
      state = S_IDLE;
    }
  }

  event void Resource.granted(){
    printf("%s: \n\r", __FUNCTION__);
    switch (state){
      case S_WRITE_REQUESTED:
        state = S_WRITING;
        post write();
        break;
      case S_READ_REQUESTED:
        state = S_READING;
        post read();
      default:
        break;
    }
  }

  command error_t I2CComMaster.receive(uint16_t slaveAddr, i2c_message_t*
  msg_, uint8_t len){
    error_t ret = call Resource.request();
    printf("%s: %s\n\r", __FUNCTION__, decodeError(ret));
    if (ret == SUCCESS){
      msg = msg_;
      msg->body.header.slaveAddr = slaveAddr;
      msg->body.header.clientId = clientId;
      //Reading from slave: DOES NOT get header! just the body. see
      //  note in I2CComSlaveMultiP.
      msg->body.header.len = len;
      state = S_READ_REQUESTED;
    }
    return ret;
  }

  task void read(){
    signalError = call I2CPacket.read(I2C_START|I2C_STOP,
      msg->body.header.slaveAddr, msg->body.header.len, (uint8_t*)msg->body.buf);
    printf("%s: %s\n\r", __FUNCTION__, decodeError(signalError));
    if (signalError == SUCCESS){
      state = S_READING;
    } else {
      // no bytes read.
      msg->body.header.len = 0;
      post signalReceiveDone();
    }
  }

  task void signalReceiveDone(){
    printf("%s: %s\n\r", __FUNCTION__, decodeError(signalError));
    release();
    signal I2CComMaster.receiveDone(signalError, msg);
  }

  async event void I2CPacket.readDone(error_t error, uint16_t addr,
      uint8_t length, uint8_t* data){
    msg->body.header.len = length;
    signalError = error;
    post signalReceiveDone();
  }

}
