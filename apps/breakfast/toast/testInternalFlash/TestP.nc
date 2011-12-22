#include <stdio.h>
#include "decodeError.h"

module TestP{
  uses interface Boot;
  uses interface Timer<TMilli>;
  uses interface InternalFlash;

} implementation {
  uint8_t counter;
  event void Boot.booted(){
    printf("Booted\n\r");
    call Timer.startPeriodic(1024);
  }

  void unlockForWrite(volatile uint8_t* ptr){
    //TODO: check ptr address for lock/unlock A
    //unlock segment A if needed
    if (FCTL3 & LOCKA){
      FCTL3 = FWKEY + LOCKA;
    }
    //unlock flash if needed
    if (FCTL3 & LOCK){
      FCTL3 = FWKEY + LOCK;
    }
  }

  void lockAfterWrite(volatile uint8_t* ptr){
    //TODO: check for whether we were in segment A.
    if (!(FCTL3 & LOCKA)){
      FCTL3 = FWKEY + LOCKA;
    }
    if (!(FCTL3 & LOCK)){
      FCTL3 = FWKEY + LOCK;
    }
  }

  void setupFlashClock(){
    //flash write pw, mclk, divide by 12
    FCTL2 = FWKEY + FSSEL_1 + 11;
  }

  void eraseSegment(volatile uint8_t* ptr){
    uint8_t wdState = WDTCTL && 0x00ff;
    //disable WDT
    WDTCTL = WDTPW + WDTHOLD;

    setupFlashClock();
    unlockForWrite(ptr);

    //set up for the segment erase
    //MERAS=0, ERASE=1: erase segment
    FCTL1 = FWKEY + ERASE;
    //dummy write to segment being erased: in this case, info A
    *ptr = 0;
    //should stall until done

    lockAfterWrite(ptr);
    //put WDT back as it was
    WDTCTL = WDTPW + wdState;
  }

  //TODO: watch out for cumulative programming time limit
  //since this is running from flash, can only do byte/word writes
  void writeFlash(volatile uint8_t* ptr, uint8_t* data, uint8_t len){
    uint8_t i;
    uint8_t wdState = WDTCTL & 0x00ff;
    WDTCTL = WDTPW + WDTHOLD;

    setupFlashClock();
    unlockForWrite(ptr);
    //set up for write
    FCTL1 = FWKEY + WRT;
    for(i = 0; i < len; i++){
      ptr[i] = data[i];
    }
    //clear write bit
    FCTL1 = FWKEY;
    lockAfterWrite(ptr);
    WDTCTL = WDTPW + wdState;
  }

  event void Timer.fired(){
    error_t error = SUCCESS;
    uint8_t check = 0;
    counter++;
    //eraseSegment((uint8_t*)0x1000);
    //writeFlash((uint8_t*)0x1000, &counter, 1);

    error = call InternalFlash.write((void*)0x0000, &counter, 1);
    printf("write %d %s\n\r", counter, decodeError(error));
    error = call InternalFlash.read((void*)0x0000, &check, 1);
    //check = *((uint8_t*)0x1000);
    printf("read: %d \n\r", check);
    if (check != counter){
      call Timer.stop();
    }
  }

}
