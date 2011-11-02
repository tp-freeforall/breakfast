#include <stdio.h>
#include "decodeError.h"
module TestP{
  uses interface Boot;
  uses interface SplitControl as DiscoverableSplitControl;
  uses interface I2CDiscoverable;
  uses interface I2CDiscoverer;
  uses interface UartStream;
  uses interface UartByte;
  uses interface StdControl as UartControl;
} implementation {
  uint8_t rxByte;
  uint16_t localAddr = GLOBAL_ADDR_LSB;
  norace uint8_t globalAddr[I2C_GLOBAL_ADDR_LENGTH];

  task void startTask();


  void printGlobalAddr(){
    uint8_t i;
    printf("Global addr:\n\r");
    for(i = 0; i< I2C_GLOBAL_ADDR_LENGTH; i++){
      printf("[%x] %x\n\r", i, globalAddr[i]);
    }
  }

  task void status(){
    printGlobalAddr();
    printf("Local addr: %x\n\r", localAddr);
  }

  event void Boot.booted(){
    P5SEL = BIT4|BIT5|BIT6;
    P5DIR = BIT4|BIT5|BIT6;
    globalAddr[I2C_GLOBAL_ADDR_LENGTH - 1] = GLOBAL_ADDR_LSB;
    call UartControl.start();
    printf("I2C Discovery Test\n\r");
    printGlobalAddr();
    if(AUTO_SLAVE){
      post startTask();
    }
  }

  task void startTask(){
      printf("%s: %s\n\r", __FUNCTION__, decodeError(call DiscoverableSplitControl.start())); 
  }

  task void stopTask(){
    printf("%s: %s\n\r", __FUNCTION__, decodeError(call DiscoverableSplitControl.stop()));
  }

  task void startDiscoverer(){
    error_t error = call I2CDiscoverer.startDiscovery();
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error)); 
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
        post startDiscoverer();
        break;
      case 'g':
        globalAddr[I2C_GLOBAL_ADDR_LENGTH - 1] ++;
        post status();
        break;
      case 'l':
        localAddr++;
        post status();
        break;
      case '?':
        post status();
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
    printf("Start done: %s local address: %x\n\r", 
      decodeError(error), call I2CDiscoverable.getLocalAddr());
    if (error == ENOACK && AUTO_SLAVE){
      post startTask();
    }
  }

  event void DiscoverableSplitControl.stopDone(error_t error){
    printf("Stop done: %s\n\r", decodeError(error));
  }

  event void I2CDiscoverer.discoveryDone(error_t error){
    printf("%s: \n\r", __FUNCTION__);
  }
  
  event uint16_t I2CDiscoverer.getLocalAddr(){
    return localAddr;
  }

  event discoverer_register_union_t* I2CDiscoverer.discovered(discoverer_register_union_t* discovery){
    uint8_t i;
    //printf("%s: \n\r", __FUNCTION__);
    //printf("  Global: ");
    printf(" ");
    for(i = 0; i < I2C_GLOBAL_ADDR_LENGTH; i++){
      printf("%x", discovery->val.globalAddr[i]);
    }
    printf("l: %x\n\r", discovery->val.localAddr);
    return discovery;
  }

  event uint8_t* I2CDiscoverable.getGlobalAddr(){
    return globalAddr;
  }

  async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t err){};
  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){};

}
