#include <stdio.h>

module TestP{
  uses interface Boot;
  uses interface Timer<TMilli>;
  uses interface Leds;
} implementation {
  uint16_t counter;
  #define TIMER_OFFSET 64
  #define TIMER_PERIOD (uint32_t)128

  event void Boot.booted(){
    uint32_t timerNow = call Timer.getNow();
//    uint32_t timerAt = timerNow - TIMER_OFFSET;
    printf("now: %lu \n\r", timerNow);
    call Timer.startPeriodicAt(128, 64);
  }

  event void Timer.fired(){
    printf("F: %lu\n", call Timer.getNow());
    counter++;
    //printf("Test: %d\r\n", counter++);
    call Leds.set(counter);
  }
}
