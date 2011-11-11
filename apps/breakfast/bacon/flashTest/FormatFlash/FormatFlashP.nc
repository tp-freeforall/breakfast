#include <stdio.h>
#include "decodeError.h"
module FormatFlashP
{
  uses {
    interface Boot;
    interface LogWrite;
    //interface LogRead;
    interface Leds;
    interface StdControl as UartCtl;
    interface UartStream;
  }
}

implementation
{
  task void formatTask();
  event void Boot.booted()
  {
    printf("Format Flash Test\n\r");
    call UartCtl.start();
  }

  async event void UartStream.receivedByte(uint8_t byte){
    switch(byte){
      case 'q':
        WDTCTL = 0;
        break;
      case 'f':
        post formatTask();
        break;
      case '\r':
        printf("\n\r");
        break;
      default:
        printf("%c", byte);
    }
  }

  task void formatTask(){
    error_t err = call LogWrite.erase();
    printf("Erase: %x %s\n\r", err, decodeError(err));
    if (err == SUCCESS){
      call Leds.set(2);   // _G_
    } else {
      call Leds.set(7);   // BGR
    }
  }
  event void LogWrite.eraseDone(error_t err)
  {
    printf("EraseDone: %x %s\n\r", err, decodeError(err));
    if (err == SUCCESS) {
      call Leds.set(4);   // B__
    } else {
      call Leds.set(7);   // BGR
    }
  }
  
  //event void LogRead.readDone(void* buf, storage_len_t len, error_t error) {}
  //event void LogRead.seekDone(error_t error) {}
  
  event void LogWrite.syncDone(error_t error) {}
  event void LogWrite.appendDone(void* buf, storage_len_t len, bool recordsLost, error_t error) {}
  async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t err){}
  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){}
}
