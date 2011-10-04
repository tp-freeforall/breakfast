#include "I2C.h"
module TestP{
  uses interface Boot;
  uses interface UartStream;
  uses interface UartByte;
  uses interface StdControl;
  uses interface Timer<TMilli>;

  provides interface Msp430UsciConfigure as I2CConfigure;
  uses interface I2CPacket<TI2CBasicAddr>;
  uses interface Resource as I2CResource;
} implementation {
  uint8_t idleMsg[]    = ".";              //1
  uint8_t resetMsg[]   = "RESET\n\r";      //7
  uint8_t welcomeMsg[] = "\n\rI2C Test\n\r";   //12
  uint8_t writingMsg[] = "WRITING\n\r";    //9
  uint8_t writeDoneMsg[] = "WRITE DONE\n\r"; //12
  uint8_t writeDoneFailMsg[] = "WRITE DONE FAIL\n\r"; //17
  uint8_t writeFailMsg[] = "WRITE FAIL\n\r"; //12
  uint8_t readingMsg[] = "READING\n\r";    //9
  uint8_t readFailMsg[] = "READ FAIL\n\r";    //11
  uint8_t readDoneFailMsg[] = "READ DONE FAIL\n\r";    //16
  uint8_t resourceGrantedMsg[] = "RESOURCE GRANTED\n\r"; //18
  uint8_t nl[] = "\n\r";                   //2

  uint8_t rxByte;
  uint8_t state;

  enum{
    S_INIT = 0x01,
    S_IDLE = 0x00,
    S_ECHOING = 0x02,
    S_RESETTING = 0x03,
    S_WRITE_START = 0x04,
    S_WRITE_FAIL = 0x05,
    S_WRITING = 0x06,
    S_WRITEDONE = 0x07,
    S_WRITEDONE_FAIL = 0x08,
    S_RESOURCE_REQUESTED = 0x09,
    S_RESOURCE_REQUEST_FAIL = 0x0a,
    S_RESOURCE_GRANTED = 0x0b,
    S_READ_START = 0x0c,
    S_READING = 0x0d,
    S_READDONE = 0x0e,
    S_READDONE_FAIL = 0x0f,
    S_READ_FAIL = 0x10,
  };

  void setState(uint8_t s){
    atomic{
      state = s;
      //P6OUT = state;
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
      //P6DIR = 0x00;
    }
    if (call StdControl.start() == SUCCESS){
      setState(S_INIT);
      call Timer.startOneShot(256);
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

  task void shortTimer(){
      call Timer.startOneShot(256);
  }

  uint8_t cmd[] = {0xde,0xad,0xbe,0xef};
  uint8_t cmd_len = 4;
  // 10010 00
  uint16_t slaveAddr = 0x0042;
  task void doWrite(){
    //P6OUT = 0x00;
    //P6OUT = 0x01;
    if( SUCCESS == call I2CPacket.write(I2C_START | I2C_STOP,
    slaveAddr, cmd_len, cmd)){
      //P6OUT = 0x02;
      setState(S_WRITING);
    }else{
      //P6OUT = 0x03;
      setState(S_WRITE_FAIL);
      call UartStream.send(writeFailMsg, 12);
    }
  }

  uint8_t i2c_buf[] = {0x00, 0x00, 0x00, 0x00}; 
  uint8_t i2c_len = 4;

  task void doRead(){
    if (SUCCESS == call I2CPacket.read(I2C_START|I2C_STOP, 
          slaveAddr, i2c_len, i2c_buf)){
      setState(S_READING);
    } else{
      setState(S_READ_FAIL);
      call UartStream.send(readFailMsg, 11);
    }
  }

  //OK
  task void getResource(){
    if(SUCCESS == call I2CResource.request()){
      setState(S_RESOURCE_REQUESTED);
    } else {
      setState(S_RESOURCE_REQUEST_FAIL);
    }
  }

  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){
    if(checkState(S_RESETTING)){
      post shortTimer();
    } else if (checkState(S_ECHOING)){
      setState(S_IDLE);
    } else if (checkState(S_INIT)){
      post getResource();
    } else if (checkState(S_WRITE_START)){
      post doWrite();
    } else if (checkState(S_WRITEDONE)){
      setState(S_IDLE);
    } else if (checkState(S_WRITE_FAIL)){
      setState(S_IDLE);
    } else if (checkState(S_WRITEDONE_FAIL)){
      setState(S_IDLE);
    } else if (checkState(S_RESOURCE_GRANTED)){
      setState(S_IDLE);
    } else if (checkState(S_READ_START)){
      post doRead();
    } else if (checkState(S_READDONE)){
      setState(S_IDLE);
    } else if (checkState(S_READDONE_FAIL)){
      setState(S_IDLE);
    } else if (checkState(S_READ_FAIL)){
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
      case 'w':
        setState(S_WRITE_START);
        call UartStream.send(writingMsg, 9);
        break;
      case 'r':
        setState(S_READ_START);
        call UartStream.send(readingMsg, 9);
        break;
      default:
        setState(S_ECHOING);
        post echoTask();
    }
  }

  event void I2CResource.granted(){
    setState(S_RESOURCE_GRANTED);
    call UartStream.send(resourceGrantedMsg, 18);
  }

  async event void I2CPacket.writeDone(error_t error, uint16_t addr, uint8_t length, uint8_t* data){
    if(error == SUCCESS){
      setState(S_WRITEDONE);
      call UartStream.send(writeDoneMsg, 12);
    } else{
      setState(S_WRITEDONE_FAIL);
      call UartStream.send(writeDoneFailMsg, 17);
    }
  }

  async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t err){
  }

  const msp430_usci_config_t i2c_cfg = {
    ctl0: UCSYNC | UCMODE_3| UCMST,
    ctl1: UCSSEL_2 | UCTR,
    br0:  8,
    br1:  0,
    mctl: 0,
    i2coa: 0x42,
  };


  async command const msp430_usci_config_t* I2CConfigure.getConfiguration(){
    return &i2c_cfg;
  }

  async event void I2CPacket.readDone(error_t error, uint16_t addr, uint8_t length, uint8_t* data){
    if (error == SUCCESS){
      setState(S_READDONE);
      call UartStream.send(i2c_buf, 1);
    }else{
      setState(S_READDONE_FAIL);
      call UartStream.send(readDoneFailMsg, 16);
    }
  }
}
