#include "RegisterUser.h"

generic module RegisterUserP(uint8_t clientId){
  provides interface RegisterUser;
  uses interface I2CPacket<TI2CBasicAddr>;
  uses interface Resource;
} implementation {

  enum {
    S_WRITE_REQUESTED = 0x01,
    S_WRITING = 0x02,
    S_READ_REQUESTED = 0x03,
    S_SEEKING = 0x04,
    S_READING = 0x05,
    S_IDLE = 0x06,
  };

  norace uint8_t state;
  register_packet_t* pkt;

  void release(){
    atomic{
      call Resource.release();
      state = S_IDLE;
    }
  }

  command error_t RegisterUser.write(uint16_t slaveAddr_, uint8_t pos,
      register_pkt_t* pkt_, uint8_t len_){
    error_t ret = call Resource.request();
    if ( ret == SUCCESS ){
      pkt = pkt_;
      pkt->header.clientId = clientId;
      pkt->header.pos = pos;
      pkt->footer.len = len_;
      pkt->footer.slaveAddr = slaveAddr_;
      state = S_WRITE_REQUESTED;
    } 
    return ret;
  }

  task void write(){
    //footer.len is just data length, add in header
    error_t error = call I2CPacket.write(I2C_START|I2C_STOP,
      pkt->footer.slaveAddr, 
      pkt->footer.len + sizeof(register_packet_header_t), 
      (uint8_t*) pkt); 
    if (error != SUCCESS){
      signalError = error;
      post signalWriteDone();
    }
  }

  task void seek(){
    //just write the client ID/position
    error_t error = call I2CPacket.write(I2C_START,
      pkt->footer.slaveAddr, sizeof(register_packet_header_t),
      (uint8_t*)pkt);
    if (error != success){
      signalError = error;
      post signalReadDone();
    }
  }

  event void Resource.granted(){
    switch (state){
      case S_WRITE_REQUESTED:
        state = S_WRITING;
        post write();
        break;
      case S_READ_REQUESTED:
        state = S_SEEKING;
        post seek();
        break;
      default:
        break;
    }
  }

  task void signalWriteDone(){
    release();
    signal RegisterUser.writeDone(signalError, pkt->footer.slaveAddr,
      pkt->header.pos, pkt->footer.len, pkt)
  }

  task void signalReadDone(){
    release();
    signal RegisterUser.readDone(signalError, pkt->footer.slaveAddr,
      pkt->header.pos, pkt->footer.len, pkt);
  }

  async event void I2CPacket.writeDone(error_t error, uint16_t addr,
      uint8_t length, uint8_t* data){
    switch (state){
      case S_WRITING:
        signalError = error;
        pkt->footer.len = length;
        post signalWriteDone();
        break;
      case S_SEEKING:
        if (error == SUCCESS){
          post readTask();
        } else {
          signalError = error;
          //indicate "no bytes read" since we failed to seek
          pkt->footer.len = 0;
          post signalReadDone();
        }
        break;
    }
  }

  task void readTask(){
    //read into pkt->data 
    signalError = call I2CPacket.read(I2C_RESTART|I2C_STOP,
      pkt->footer.slaveAddr, pkt->footer.len, pkt->data);
    if (signalError == SUCCESS){
      state = S_READING;
    } else {
      // no bytes read.
      pkt->footer.len = 0;
      post signalReadDone();
    }
  }

  command error_t RegisterUser.read(uint16_t slaveAddr, uint8_t pos,
      register_packet_t* pkt, uint8_t len){
    error_t ret = call Resource.request();
    if (ret == SUCCESS){
      pkt->header.clientId = clientId;
      pkt->header.pos = pos;
      pkt->footer.len = len;
      pkt->footer.slaveAddr = slaveAddr;
      state = S_READ_REQUESTED;
    } 
    return ret;
  }

  async event void I2CPacket.readDone(error_t error, uint16_t addr,
      uint8_t length, uint8_t* data){
    pkt->footer.len = length;
    signalError = error;
    post signalReadDone();
  }


}
