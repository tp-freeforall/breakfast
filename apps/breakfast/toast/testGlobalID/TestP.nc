#include <stdio.h>
#include "InternalFlash.h"
#include "TLVStorage.h"
#include "decodeError.h"
#include "GlobalID.h"

module TestP{
  uses interface Boot;
  uses interface UartStream;
  uses interface StdControl;
  uses interface GlobalID;
} implementation {
  uint8_t lsb;

  event void Boot.booted(){
   call StdControl.start();
   printf("GlobalID test\n\r");
  }

  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){
  }

  task void readGlobalID(){
    uint8_t globalID[GLOBAL_ID_LEN];
    uint8_t i;
    error_t error;
    error = call GlobalID.getID(globalID, GLOBAL_ID_LEN);
    printf("getID: %s\n\r", decodeError(error));
    if (error == SUCCESS){
      printf("Global ID: \n\r");
      for (i = 0; i < GLOBAL_ID_LEN; i++){
        printf(" %x\n\r", globalID[i]);
      }
    }
  }
  
  task void setGlobalID(){
    uint8_t gid[GLOBAL_ID_LEN];
    memset(gid, 0, GLOBAL_ID_LEN);
    gid[GLOBAL_ID_LEN-1] = lsb;
    printf("Set ID: %s\n\r", 
      decodeError( call GlobalID.setID(gid, GLOBAL_ID_LEN)));
  }

  async event void UartStream.receivedByte(uint8_t byte){
    switch(byte){
      case '\r':
        printf("\n\r");
        break;
      case 's':
        post setGlobalID();
        break;
      case 'r':
        post readGlobalID();
        break;
      case 'q':
        WDTCTL = 0;
        break;
      case 'i':
        lsb ++;
        printf("LSB %x\n\r", lsb);
        break;
      default:
        printf("%c", byte);
    }
  }

  async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t err){
  }

}
