#include <stdio.h>

module TestP{
  uses interface Boot;
  uses interface Timer<TMilli>;
  uses interface Leds;
} implementation {
  uint16_t counter;

  event void Boot.booted(){
    call Timer.startPeriodic(1024);
  }

  event void Timer.fired(){
    printf("Test: %d\r\n", counter++);
    call Leds.set(counter);
  }
}
