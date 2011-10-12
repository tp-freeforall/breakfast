#include <stdio.h>

module TestP{
  uses interface Boot;
  uses interface UartStream;
  uses interface UartByte;
  uses interface StdControl as UartControl;
  uses interface I2CRegister;
  uses interface SplitControl;
} implementation {
  uint8_t rxByte;
  norace uint8_t globalAddr[GLOBAL_ADDR_LENGTH];
  uint8_t _reg[I2C_REGISTER_LENGTH];
  uint8_t* reg=_reg;

  void printGlobalAddr(){
    uint8_t i;
    printf("Global addr:");
    for(i = 0; i< GLOBAL_ADDR_LENGTH; i++){
      printf("%x ", globalAddr[i]);
    }
    printf("\n\r");
  }

  event void Boot.booted(){
    call UartControl.start();
    printf("I2C Register Test\n\r");
    //printGlobalAddr();
    call SplitControl.start();
  }

  async event void UartStream.receivedByte(uint8_t byte){
    atomic rxByte = byte;
    switch(rxByte){
      case 'q':
        WDTCTL = 0x00;
        break;
     case '\r':
        printf("\n\r");
        break;
      default:
        printf("%c", byte);
        break;
    }
  }

  event void SplitControl.startDone(error_t error){
    call I2CRegister.setOwnAddress('B');
  }

  event void SplitControl.stopDone(error_t error){
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
    printf("%s: \n\r", __FUNCTION__);
    reg = reg_;
    post printReg();
    return swp;
  }

  async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t err){};
  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){};

}
