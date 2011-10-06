#include "I2C.h"
module TestP{
  uses interface Boot;
  uses interface UartStream;
  uses interface UartByte;
  uses interface StdControl;
  uses interface Timer<TMilli>;

  provides interface Msp430UsciConfigure as I2CConfigure;
  uses interface I2CPacket<TI2CBasicAddr>;
  uses interface I2CSlave;
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
  uint8_t enableSlaveMsg[] = "SLAVE ENABLE\n\r";   //14
  uint8_t enableSlaveFailMsg[] = "SLAVE ENABLE FAIL\n\r";//19
  uint8_t slaveTransmitDoneMsg[] = "SLAVE TRANSMIT DONE\n\r"; //21
  uint8_t myAddrMsg[] = "Me:  \n\r";
  uint8_t slaveAddrMsg[] = "Slave:  \n\r";
  uint8_t gcWritingMsg[] = "WRITING TO GC\n\r";//15
  uint8_t nl[] = "\n\r";                   //2

  uint8_t rxByte;
  uint8_t state;

  uint8_t i2c_buf[] = {0xff,0xff,0xff,0xff, 0xff, 0xff};
  uint8_t i2c_len = 6;
  uint8_t i2c_index;
  uint8_t bufLen;

  uint8_t cmd[] = "doug";
  uint8_t cmd_len = 4;

  // 10010 00
  uint16_t minAddr = 'A';
  uint16_t myAddr;
  uint16_t slaveAddr; 

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
    S_ENABLE_SLAVE_START = 0x11,
    S_SLAVE_RECEIVE = 0x12,
    S_SLAVE_START = 0x13,
    S_SLAVE_STOP_RECEIVE = 0x14,
    S_SLAVE_STOP_TRANSMIT = 0x15,
    S_SLAVE_TRANSMIT = 0x16,
    S_GC_WRITE_START = 0x17,
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
      myAddr = minAddr;
      myAddrMsg[4] = myAddr;
      slaveAddr = minAddr;
      slaveAddrMsg[7] = slaveAddr;
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
    }else if(checkState(S_SLAVE_STOP_RECEIVE)){
      atomic{
        bufLen = i2c_index;
      }
      call UartStream.send(i2c_buf, bufLen);
    }else if(checkState(S_SLAVE_STOP_TRANSMIT)){
      call UartStream.send(slaveTransmitDoneMsg, 21);
    }else if(checkState(S_RESETTING)){
      //trigger reset
      WDTCTL = 0x00;
    }
  }

  task void shortTimer(){
      call Timer.startOneShot(256);
  }

  task void doWrite(){
    uint16_t destAddr;

    if (checkState(S_GC_WRITE_START)){
      destAddr = 0x0000;
    } else {
      destAddr = slaveAddr;
    }

    if( SUCCESS == call I2CPacket.write(I2C_START | I2C_STOP, destAddr, cmd_len, cmd)){
      setState(S_WRITING);
    }else{
      setState(S_WRITE_FAIL);
      call UartStream.send(writeFailMsg, 12);
    }
    
  }


  task void doRead(){
    if (SUCCESS == call I2CPacket.read(I2C_START|I2C_STOP, 
          slaveAddr, cmd_len, i2c_buf)){
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
  
  task void enableSlave(){
    if(SUCCESS == call I2CSlave.enableSlave()){
      call UartStream.send(enableSlaveMsg, 14);
    } else {
      call UartStream.send(enableSlaveFailMsg, 19 );
    }
    setState(S_IDLE);
  }

  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){
    if(checkState(S_RESETTING)){
      post shortTimer();
    } else if (checkState(S_INIT)){
      post getResource();
    } else if (checkState(S_WRITE_START)){
      post doWrite();
    } else if (checkState(S_READ_START)){
      post doRead();
    } else if (checkState(S_READDONE)){
      memset(i2c_buf, 0xff, i2c_len);
      setState(S_IDLE);
    } else if(checkState(S_GC_WRITE_START)){
      post doWrite();
    } else {
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
      case 'm':
        myAddr++;
        call I2CSlave.setOwnAddress(myAddr);
        myAddrMsg[4] = myAddr;
        call UartStream.send(myAddrMsg, 7);
        break;
      case 's':
        slaveAddr++;
        slaveAddrMsg[7] = slaveAddr;
        call UartStream.send(slaveAddrMsg, 10);
        break;
      case 'e':
        setState(S_ENABLE_SLAVE_START);
        post enableSlave();
        break;
      case 'g':
        setState(S_GC_WRITE_START);
        call UartStream.send(gcWritingMsg, 15);
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
    br0:  0x08,
    br1:  0x00,
    mctl: 0,
    i2coa: 'A',
  };


  async command const msp430_usci_config_t* I2CConfigure.getConfiguration(){
    return &i2c_cfg;
  }

  async event void I2CPacket.readDone(error_t error, uint16_t addr, uint8_t length, uint8_t* data){
    if (error == SUCCESS){
      setState(S_READDONE);
//      atomic{
//        uint8_t i;
//        P6OUT = 0xff;
//        P6OUT = 0x00;
//        P6OUT = 0xff;
//        P6OUT = 0x00;
//        
//        for ( i = 0; i < length; i++){
//          P6OUT = data[i];
//        }
//        P6OUT = 0x00;
//      }
      call UartStream.send(data, length);
    }else{
      setState(S_READDONE_FAIL);
      call UartStream.send(readDoneFailMsg, 16);
    }
  }
  
  async event error_t I2CSlave.slaveReceive(uint8_t data){
    setState(S_SLAVE_RECEIVE);
    i2c_buf[i2c_index++] = data;
    return SUCCESS;
  }

  async event uint8_t I2CSlave.slaveTransmit(){
    setState(S_SLAVE_TRANSMIT);
    return i2c_buf[i2c_index++];
  }

  async event void I2CSlave.slaveStart(){
    i2c_index = 0;
    setState(S_SLAVE_START);
  }

  async event void I2CSlave.slaveStop(){
    post shortTimer();
    if (checkState(S_SLAVE_RECEIVE)){
      setState(S_SLAVE_STOP_RECEIVE);
    } else if(checkState(S_SLAVE_TRANSMIT)){
      setState(S_SLAVE_STOP_TRANSMIT);
    }
  }
}
