#include "I2C.h"
module TestP{
  uses interface Boot;
  uses interface UartStream;
  uses interface UartByte;
  uses interface StdControl;
  uses interface Timer<TMilli>;

  provides interface Msp430UsciConfigure as I2CConfigure;
  //uses interface I2CPacket<I2BasicAddr>;
} implementation {
  uint8_t idleMsg[]    = ".";              //1
  uint8_t resetMsg[]   = "RESET\n\r";      //7
  uint8_t welcomeMsg[] = "\n\rI2C Test\n\r";   //12

  uint8_t nl[] = "\n\r";                   //2

  uint8_t rxByte;
  uint8_t state;

  enum{
    S_INIT,
    S_IDLE,
    S_ECHOING,
    S_RESETTING,
  };

  void setState(uint8_t s){
    atomic{
      state = s;
      P6OUT = state;
    }
  }

  bool checkState(uint8_t s){
    atomic return (state == s);
  }

  task void restartTimer(){
    call Timer.startOneShot(2048);
  }

  event void Boot.booted(){
    atomic{
      P6DIR = 0xff;
      P6SEL = 0x00;
      P6OUT = 0x00;
    }
    if (call StdControl.start() == SUCCESS){
      setState(S_INIT);
      call Timer.startOneShot(1);
    }
  }

  event void Timer.fired(){
    if(checkState(S_IDLE)){
      call UartStream.send(idleMsg, 1);
    }else if(checkState(S_INIT)){
      call UartStream.send(welcomeMsg, 12);
    }else if(checkState(S_RESETTING)){
      //trigger reset
      WDTCTL = 0x00;
    }
  }

  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){
    if(checkState(S_RESETTING)){
      call Timer.startOneShot(1);
    } else if (checkState(S_ECHOING)){
      setState(S_IDLE);
    } else if (checkState(S_INIT)){
      setState(S_IDLE);
    }
    post restartTimer();
  }

  task void echoTask(){
    call UartStream.send(&rxByte, 1);
  }
  task void nlTask(){
    call UartStream.send(nl, 2);
  }

  async event void UartStream.receivedByte(uint8_t byte){
    atomic{
      rxByte = byte;
    }
    switch (rxByte){
      case 'q':
        setState(S_RESETTING);
        call UartStream.send(resetMsg, 7);
        break;
      case '\r':
        setState(S_ECHOING);
        post nlTask();
        break;
      default:
        setState(S_ECHOING);
        post echoTask();
    }
  }

  async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t err){
  }

  const msp430_usci_config_t i2c_cfg = {
    ctl0: UCSYNC | UCMODE_3,
    ctl1: UCTR,
    br0:  8,
    br1:  0,
    mctl: 0,
    i2coa: 0x42,
  };

  async command const msp430_usci_config_t* I2CConfigure.getConfiguration(){
    return &i2c_cfg;
  }
}
