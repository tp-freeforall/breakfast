#include "RadioTest.h"

module RadioTestP {
  uses{
    interface Boot;
    interface Leds;
    interface Receive;
    interface SplitControl as RadioSplitControl;
    interface Timer<TMilli> as AliveTimer;
  }
} implementation {
  enum {
    S_OFF = 0x00,
    S_ON = 0x01,
    S_IDLE = 0x02,
    S_ERR = 0x07,
    S_MAX = 0x10,
  };

  uint8_t state;
  uint16_t count = 0;
 
  void setState(uint8_t newState) {
    if (state < S_ERR ){
      state = newState;
    } else {
      //ignore, already in error state
    }
  }
  event void AliveTimer.fired() {
    call Leds.led0Toggle();
  }

  event void Boot.booted() {
    call RadioSplitControl.start();
  }

  event void RadioSplitControl.startDone(error_t err) {
    if (err == SUCCESS) {
      call AliveTimer.startPeriodic(5000);
    } else {
      setState(S_ERR);
    }
  }

  event void RadioSplitControl.stopDone(error_t err) {
    setState(S_OFF);
  }
 
  event message_t* Receive.receive(message_t* msg, void* payload, error_t err) {
    count ++;
    if (count % 10){
      call Leds.led1Toggle();
    }
    call Leds.led2Toggle();
    return msg;
  }
  
}
