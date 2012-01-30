#include "Rf1aPacket.h"

module TestReceiverP {
  uses interface Boot;
  uses {
    interface Receive as RadioReceive;
    interface SplitControl;
    interface Leds;
    interface Timer<TMilli>;
    interface Rf1aPhysicalMetadata;
  }
} implementation {
  enum{
    S_STARTING,
    S_STARTUP_WAIT,
    S_WAITING,
    S_INTERPACKET_WAIT,
  };

  rf1a_metadata_t metadata;
  message_t rmsg;

  uint8_t state = S_STARTING;
  uint16_t seqNum = 0;

  uint16_t sendCount;

  uint16_t SEND_READY_WAIT = 10;
  uint16_t STARTUP_WAIT = 512;
  uint16_t INTERPACKET_WAIT = 512;
  uint16_t period = 16384;

  event void Boot.booted(){
    //P1.1: TA1 CCR1 compare output
    atomic{
      PMAPPWD = PMAPKEY;
      PMAPCTL = PMAPRECFG;
      P1MAP1 = PM_TA1CCR1A;
      PMAPPWD = 0x00;
    }
    P1DIR |= BIT1;
    P1SEL |= BIT1;
    //output mode 6: negative pulse at end of cycle
    TA1CCTL1 = OUTMOD_6;
    TA1CTL = TASSEL_3 | MC__UP;
    call SplitControl.start();
    printf("Booted\n\r");
  }

  event void SplitControl.startDone(error_t err){
    state = S_STARTUP_WAIT;
    call Timer.startOneShot(STARTUP_WAIT);
  }

  event void Timer.fired(){
    switch(state){
      case S_INTERPACKET_WAIT:
      case S_STARTUP_WAIT:
        printf("Starting send pulses\n\r");
        state = S_WAITING;
        atomic{
          //start PWM: negative pulse with width=send1Offset cycles of
          //  SMCLK, at _end_ of period
          //pulse 
          //stop it
          TA1CCR0 = 0;
          //set pulse width
          TA1CCR1 = period - 1 - SEND_1_OFFSET;
          //and off it goes
          TA1CCR0 = period - 1;
        }
      case S_WAITING:
        //stop timer for reporting
        TA1CCR0 = 0;
        printf("TIMEOUT\n\r");
        state = S_INTERPACKET_WAIT;
        call Timer.startOneShot(INTERPACKET_WAIT);
    }
  }
  
  //When does the timer need to be stopped?
  ////stop timer
  //TA1CCR0 = 0;

  event void SplitControl.stopDone(error_t err){ }

  event message_t* RadioReceive.receive(message_t* msg, void* pl, uint8_t len){ 
    test_packet_t* tpl = (test_packet_t*) pl;

    call Timer.stop();
    //stop timers for reporting
    TA1CCR0 = 0;

    call Rf1aPhysicalMetadata.store(&metadata);
    printf("R %d %d %d %d\n\r", 
      tpl->seqNum, 
      call Rf1aPhysicalMetadata.rssi(&metadata), 
      call Rf1aPhysicalMetadata.lqi(&metadata),
      SEND_1_OFFSET);
//    printf("R %d %d %d %d\n\r", tpl->seqNum, metadata->rssi,
//      metadata->lqi, SEND_1_OFFSET);

    state = S_INTERPACKET_WAIT;
    call Timer.startOneShot(INTERPACKET_WAIT);
    return msg;
  }

}
