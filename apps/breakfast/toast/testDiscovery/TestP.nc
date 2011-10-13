#include <stdio.h>

module TestP{
  uses interface Boot;
  uses interface SplitControl as DiscoverableSplitControl;
  uses interface I2CDiscoverable;
  uses interface UartStream;
  uses interface UartByte;
  uses interface StdControl as UartControl;
} implementation {
  uint8_t rxByte;
  norace uint8_t globalAddr[GLOBAL_ADDR_LENGTH];

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
    printf("I2C Discovery Test\n\r");
    printGlobalAddr();
  }

  task void startTask(){
    printf("Starting discoverable: %x\n\r", 
      call DiscoverableSplitControl.start());
  }

  task void stopTask(){
    printf("Stopping discoverable: %x\n\r", 
      call DiscoverableSplitControl.stop());
  }

  async event void UartStream.receivedByte(uint8_t byte){
    atomic rxByte = byte;
    switch(rxByte){
      case 'q':
        WDTCTL = 0x00;
        break;
      case 's':
        post startTask();
        break;
      case 'S':
        post stopTask();
        break;
      case 'm':
        printf("TODO: discoverer.\n\r");
        break;
      case 'g':
        globalAddr[GLOBAL_ADDR_LENGTH - 1] ++;
        printGlobalAddr();
        break;
      case '\r':
        printf("\n\r");
        break;
      default:
        printf("%c", byte);
        break;
    }
  }

  event void DiscoverableSplitControl.startDone(error_t error){
    printf("Start done: %x local address: %x\n\r", 
      error, call I2CDiscoverable.getLocalAddr());
  }

  event void DiscoverableSplitControl.stopDone(error_t error){
    printf("Stop done: %x\n\r", error);
  }

  event uint8_t* I2CDiscoverable.getGlobalAddr(){
    return globalAddr;
  }

  async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t err){};
  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){};

}
