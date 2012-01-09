#include "I2CCom.h"
module I2CComSlaveMultiP {
  provides interface I2CComSlave[uint8_t clientId];
  provides interface SplitControl;
  uses interface Resource;
  uses interface I2CSlave;
} implementation {

  norace uint8_t transCount;

  bool isGC;
  norace bool isReceive = FALSE;

  norace bool isPaused = FALSE;
  norace bool eventPending = FALSE;
  
  i2c_message_t txPkt_;
  i2c_message_t rxPkt_;

  norace i2c_message_t* txPkt = &txPkt_;
  norace i2c_message_t* rxPkt = &rxPkt_;

  enum{
    I2C_COM_SLAVE_INVALID = 0xff,
  };

  norace uint8_t lastClient = I2C_COM_SLAVE_INVALID;

  void transmit();
  void receive();

  async command void* I2CComSlave.getPayload[uint8_t clientId](i2c_message_t* msg){
    return & msg->body.buf;
  }

  async command error_t I2CComSlave.pause[uint8_t clientId](){
    if (clientId == lastClient){
      if (isPaused){
        return EALREADY;
      } else {
        isPaused = TRUE;
        return SUCCESS;
      }
    } else {
      printf("not active client\n\r");
      return EBUSY;
    }
  }

  async command error_t I2CComSlave.unpause[uint8_t clientId](){
    if (clientId == lastClient){
      if (isPaused){
        isPaused = FALSE;
        if (eventPending){
          if (isReceive){
            receive();
          } else {
            transmit();
          }
        } 
        return SUCCESS;
      } else {
        printf("not paused\n\r");
        return EALREADY;
      }
    } else {
      printf("Active Client wrong\n\r");
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
    if (ret == SUCCESS){
      post stopDone();
    }
    return ret;
  }

  event void Resource.granted(){
    signal SplitControl.startDone(SUCCESS);
  }

  //Note: slave receive gets entire packet (including header). Slave
  //  transmit, however, only sends back the body. This is because:
  //  a. slave can't know len (up to master)
  //  b. at the master, only a single client could be using I2c, so
  //     there's no need for multiplexing
  //  c. "slaveAddr" field is meaningless in this context.
  //  d. less bytes, so faster
  void receive(){
    eventPending = FALSE;
    rxPkt->buf[transCount] = call I2CSlave.slaveReceive();
//    printf("r %d %x\n\r", transCount, rxPkt->buf[transCount]);
    transCount++;
  }

  void transmit(){
    if(transCount == 0){
      atomic{
        txPkt = signal I2CComSlave.slaveTXStart[lastClient](txPkt);
      }
    } 
    eventPending = FALSE;
    call I2CSlave.slaveTransmit(txPkt->body.buf[transCount]);
    transCount++;
  }
  
  async event bool I2CSlave.slaveReceiveRequested(){
    if (isGC){
      //ignore
      call I2CSlave.slaveReceive();
      return TRUE;
    } else{
      isReceive = TRUE;
      if (isPaused){
        return FALSE;
      } else {
        receive();
        return TRUE;
      }
    }
  }

  async event bool I2CSlave.slaveTransmitRequested(){
    if (isGC){
      //ignore
      call I2CSlave.slaveTransmit(0xff);
      return TRUE;
    }else {
      isReceive = FALSE;
      if (isPaused){
        return FALSE;
      } else {
        transmit();
        return TRUE;
      }
    }
  }
  
  async event void I2CSlave.slaveStart(bool generalCall){
    P6OUT |= BIT0;
    P6OUT &= ~BIT0;
    isGC = generalCall;
    transCount = 0;
  }
  

  //TODO: what should happen if we are paused when the stop arrives?
  //  can that happen?
  async event void I2CSlave.slaveStop(){
//    printf("%s: \n\r", __FUNCTION__);
    if (! isGC && isReceive){
      lastClient = rxPkt->body.header.clientId;
      atomic{
        rxPkt = signal I2CComSlave.received[lastClient](rxPkt);
      }
    }
  }

  default async event i2c_message_t* I2CComSlave.received[uint8_t clientId]( i2c_message_t* msg){
    printf("%s: \n\r", __FUNCTION__);
    return msg;
  }
  
  default async event i2c_message_t* I2CComSlave.slaveTXStart[uint8_t clientId](i2c_message_t* msg){
    printf("%s: \n\r", __FUNCTION__);
    return msg;
  }

}
 
