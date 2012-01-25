#include <stdio.h>
#include "decodeError.h"

module TestP{
  uses interface Boot;
  uses interface Timer<TMilli>;
  uses interface InternalFlash;
  uses interface InternalFlash as InternalFlashA;

} implementation {
  uint8_t counter;
  uint8_t counterA = 10;
  event void Boot.booted(){
    printf("Booted\n\r");
    call Timer.startPeriodic(1024);
  }

  #define DEST_ADDR ((uint8_t*)0x00)
  event void Timer.fired(){
    uint8_t check = 0;
    error_t error = FAIL;
    error = call InternalFlash.write(DEST_ADDR, &counter, 1);
    printf("Wrote %d to %p (STD): %s\n\r", counter, DEST_ADDR, decodeError(error));
    error = call InternalFlashA.write(DEST_ADDR, &counterA, 1);
    printf("Wrote %d to %p (A):   %s\n\r", counterA, DEST_ADDR, decodeError(error));

    error = call InternalFlash.read(DEST_ADDR, &check, 1);
    printf("Read %d from %p (STD): %s\n\r", check, DEST_ADDR, decodeError(error));
    error = call InternalFlashA.read(DEST_ADDR, &check, 1);
    printf("Read %d from %p (A):   %s\n\r", check, DEST_ADDR, decodeError(error));
    counter++;
    counterA++;
    printf("\n\r----\n\r");
    if (counter > 4){
      printf("Stopping\n\r");
      call Timer.stop();
    }
  }

}
