#include <stdio.h>
#include "decodeError.h"
#include "I2CDiscoverable.h"
module TestP{
  uses interface Boot;
  uses interface I2CDiscoverable;
  uses interface I2CDiscoverer;
  uses interface UartStream;
  uses interface UartByte;
  uses interface StdControl as UartControl;
} implementation {
  uint8_t rxByte;
  uint16_t localAddr = GLOBAL_ADDR_LSB;
  uint16_t myLocalAddr = I2C_DISCOVERABLE_UNASSIGNED;
  norace uint8_t globalAddr[I2C_GLOBAL_ADDR_LENGTH];
  bool reset = TRUE;

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
    //TODO: read myLocalAddr back from flash.
    printf("%s: %s\n\r", __FUNCTION__, decodeError(call I2CDiscoverable.startDiscoverable(myLocalAddr))); 
  }


  task void startDiscoverer(){
    error_t error = call I2CDiscoverer.startDiscovery(reset);
    printf("%s: %x %s\n\r", __FUNCTION__, reset, decodeError(error)); 
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
      case 'M':
        reset = TRUE;
        post startDiscoverer();
        break;
      case 'm':
        reset = FALSE;
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

  event void I2CDiscoverable.endDiscoverable(error_t error, uint16_t lastLocalAddr){
    printf("End Discoverable: %s local address: %x\n\r", decodeError(error), lastLocalAddr);
    myLocalAddr = lastLocalAddr;
    if (AUTO_SLAVE){
      post startTask();
    }
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
