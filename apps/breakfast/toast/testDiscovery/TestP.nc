#include <stdio.h>
#include "decodeError.h"
module TestP{
  uses interface Boot;
  uses interface SplitControl as DiscoverableSplitControl;
  uses interface I2CDiscoverable;
  uses interface SplitControl as DiscovererSplitControl;
  uses interface I2CDiscoverer;
  uses interface UartStream;
  uses interface UartByte;
  uses interface StdControl as UartControl;
} implementation {
  uint8_t rxByte;
  uint16_t localAddr;
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
    error_t error = call DiscovererSplitControl.start();
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error)); 
  }

  task void stopDiscoverer(){
    error_t error = call DiscovererSplitControl.stop();
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
      case 'M':
        post stopDiscoverer();
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

  event void DiscovererSplitControl.startDone(error_t error){
    printf("Discoverer SplitControl.startDone %s: \n\r", decodeError(error));
  }

  event void DiscovererSplitControl.stopDone(error_t error){
    printf("%s: \n\r", __FUNCTION__);
  }
  
  event uint16_t I2CDiscoverer.getLocalAddr(){
    return localAddr;
  }

  async event void I2CDiscoverer.discovered(discoverer_register_union_t* discovery){
    printf("%s: \n\r", __FUNCTION__);
  }

  event uint8_t* I2CDiscoverable.getGlobalAddr(){
    return globalAddr;
  }

  async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t err){};
  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){};

}
