#include <stdio.h>

module TestP{
  uses interface Boot;
  uses interface GeneralIO as CSN;
  uses interface GeneralIO as Power;
  uses interface SpiByte;
  uses interface SpiPacket;
  uses interface Resource;
  uses interface Timer<TMilli>;
  uses interface Leds;
} implementation {
  //forward declarations
  task void readSerialTask();
  task void reportIDTask();

  #define ID_LEN 20
  #define S_RDID 0x9F
  uint8_t id_buf[ID_LEN];

  event void Boot.booted(){
    call Leds.led0On();
    call Timer.startPeriodic(1024);
    call CSN.makeOutput();
    call CSN.set();
    call Power.makeOutput();
    call Power.clr();
  } 

  event void Timer.fired(){
    if(call Power.get()){
      call Power.clr();
    } else{
      call Leds.led2Toggle();
      call Power.set();
    }
    call Leds.led1Toggle();
    call Resource.request();
  }

  event void Resource.granted(){
    post readSerialTask();
  }

  task void readSerialTask(){
    call CSN.clr();
    call SpiByte.write(S_RDID);
    call SpiPacket.send(NULL, id_buf, ID_LEN);
  }

  async event void SpiPacket.sendDone( uint8_t* txBuf, uint8_t* rxBuf, uint16_t len,
                             error_t error ){
    call CSN.set();
    call Resource.release();
    post reportIDTask();
  }

  task void reportIDTask(){
    uint8_t i;
    if(call Power.get()){
      printf("1 ");
    } else{
      printf("0 ");
    }
    for (i=0; i < ID_LEN; i++){
      printf("%x", id_buf[i]);
    }
    printf("\n\r");
    memset(id_buf, 0, ID_LEN);
  }
}
