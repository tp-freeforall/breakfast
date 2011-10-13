#include <stdio.h>

module TestP{
  uses interface Boot;
  uses interface StdControl;
  uses interface Timer<TMilli>;
  uses interface UartStream;
} implementation {
  uint8_t rxByte;

  event void Boot.booted(){
    //call StdControl.start();
    P6DIR = 0xff;
    call Timer.startOneShot(1024);
  }

  event void Timer.fired(){
    printf("0123456789");
  }

//  task void echoTask(){
//    printf("RECEIVED: %c\n\r", rxByte);
//  }
//

  async event void UartStream.receivedByte(uint8_t byte){
    //atomic rxByte = byte;
    if (byte == 'q'){
      WDTCTL = 0x00;
    }
  }

  async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t err){}

  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){}

}
