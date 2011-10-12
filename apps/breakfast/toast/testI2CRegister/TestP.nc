#include <stdio.h>

module TestP{
  uses interface Boot;
  uses interface UartStream;
  uses interface UartByte;
  uses interface StdControl as UartControl;
  uses interface I2CRegister;
  uses interface SplitControl;
  uses interface I2CPacket<TI2CBasicAddr>;
  uses interface Resource;
} implementation {
  uint8_t rxByte;
  norace uint8_t globalAddr[GLOBAL_ADDR_LENGTH];
  uint8_t _reg[I2C_REGISTER_LENGTH];
  uint8_t* reg=_reg;
  uint16_t slaveAddr;
  
  char* errors[] = {
    "SUCCESS",
    "FAIL",
    "ESIZE",
    "ECANCEL",
    "EOFF",
    "EBUSY",
    "EINVAL",
    "ERETRY",
    "ERESERVE",
    "EALREADY",
    "ENOMEM",
    "ENOACK",
    "ELAST",
  };

  char* decodeError(error_t err){
    return errors[err];
  }

  typedef struct{
    uint8_t cmd;
    uint8_t data[I2C_REGISTER_LENGTH -1];
  } reg_msg_body_t;

  typedef struct{
    uint8_t pos;
    reg_msg_body_t body;
  //} reg_msg_t;
  }__attribute__((__packed__)) reg_msg_t;

  typedef union{
    reg_msg_t msg;
    uint8_t data[I2C_REGISTER_LENGTH + 1];
  } reg_pkt_t;

  reg_pkt_t txPkt;

  void printGlobalAddr(){
    uint8_t i;
    printf("Global addr:");
    for(i = 0; i< GLOBAL_ADDR_LENGTH; i++){
      printf("%x ", globalAddr[i]);
    }
    printf("\n\r");
  }

  void status(){
    printf("Slave: %c Pos: %x Cmd: %x Data[0]: %x\n\r", slaveAddr, txPkt.msg.pos, txPkt.msg.body.cmd, txPkt.msg.body.data[0]);
  }

  event void Boot.booted(){
    uint8_t i;
    uint8_t* p;
    call UartControl.start();
    printf("I2C Register Test\n\r");
    //printGlobalAddr();
    txPkt.msg.pos = 0;
    txPkt.msg.body.cmd = 'm';
    txPkt.msg.body.data[0] = 'a';
    slaveAddr = 'A';
    printf("&txPkt: %p\n\r", &txPkt);
    printf("&txPkt.msg: %p\n\r", &txPkt.msg);
    printf("&txPkt.msg.pos: %p\n\r", &txPkt.msg.pos);
    printf("&txPkt.msg.body: %p\n\r", &txPkt.msg.body);
    printf("&txPkt.msg.body.cmd: %p\n\r", &txPkt.msg.body.cmd);
    printf("&txPkt.msg.body.data: %p\n\r", &txPkt.msg.body.data);
    printf("&txPkt.data: %p\n\r", &txPkt.data);
    printf("txPkt.data: %p\n\r", txPkt.data);
    for(i = 0; i< sizeof(txPkt.msg); i++){
      p = ((uint8_t*)&txPkt)+i;
      printf("txPkt[%d](%p): %x\n\r", i, p, *p);
    }

  }

  task void receiver(){
    if(call Resource.isOwner()){
      printf("Release resource: %s\n\r", decodeError(call Resource.release()));
    }else {
      call SplitControl.start();
    }
  }

  task void write(){
    if (! call Resource.isOwner()){
      if (call SplitControl.stop() != SUCCESS){
        printf("Stop fail, requesting: %s\n\r", decodeError(call Resource.request()));
      }else{
        printf("stopping.\n\r");
      }
    }else{
      printf("Writing: %s %x %p\n\r", decodeError(call
      I2CPacket.write(I2C_START|I2C_STOP, slaveAddr, sizeof(txPkt.msg), txPkt.data)), sizeof(txPkt.msg), txPkt.data);
    }
  }

  async event void I2CPacket.writeDone(error_t error, uint16_t addr, uint8_t len, uint8_t* data){
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
  }

  async event void I2CPacket.readDone(error_t error, uint16_t addr, uint8_t len, uint8_t* data){
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
  }

  async event void UartStream.receivedByte(uint8_t byte){
    atomic rxByte = byte;
    switch(rxByte){
      case 'q':
        WDTCTL = 0x00;
        break;
      case 'w':
        post write();
        break;
      case 'p':
        txPkt.msg.pos++;
        break;
      case 'c':
        txPkt.msg.body.cmd++;
        break;
      case 'd':
        txPkt.msg.body.data[0]++;
        break;
      case 's':
        slaveAddr ++;
        status();
        break;
      case 'r':
        post receiver();
        break;
      case '\r':
        printf("\n\r");
        break;
      default:
        printf("%c", byte);
        break;
    }
  }

  event void Resource.granted(){
   printf("%s: \n\r", __FUNCTION__);
   post write();
  }

  event void SplitControl.startDone(error_t error){
    printf("Register started\n\r");
    call I2CRegister.setOwnAddress('B');
  }

  event void SplitControl.stopDone(error_t error){
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
    call Resource.request();
  }

  async event void I2CRegister.transactionStart(bool generalCall){
    printf("%s: \n\r", __FUNCTION__);
  }

  task void printReg(){
    atomic{
      uint8_t i;
      printf("Contents: ");
      for (i = 0; i < I2C_REGISTER_LENGTH; i++){
        printf("%c", reg[i]);
      }
      printf("\n\r");
    }
  }

  async event uint8_t* I2CRegister.transactionStop(uint8_t* reg_, uint8_t len, uint8_t gcCmd){
    uint8_t* swp = reg;
    printf("Stop reg=%p got=%p\n\r", reg, reg_);
    reg = reg_;
    post printReg();
    printf("Stop return: reg=%p return=%p\n\r", reg, swp);
    return swp;
  }

  async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t err){};
  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){};

}
