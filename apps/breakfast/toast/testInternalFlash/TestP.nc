#include <stdio.h>

module TestP{
  uses interface Boot;
  uses interface Timer<TMilli>;
} implementation {
  uint8_t counter;
  event void Boot.booted(){
    call Timer.startPeriodic(1024);
  }

  void unlockForWrite(uint8_t* ptr){
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

  void lockAfterWrite(uint8_t* ptr){
    //TODO: check for whether we were in segment A.
    if (!(FCTL3 & LOCKA)){
      FCTL3 = FWKEY + LOCKA;
    }
    if (!(FCTL3 & LOCK)){
      FCTL3 = FWKEY + LOCK;
    }
  }

  void setupFlashClock(){
    //flash write pw, SMCLK, div 1
    FCTL2 = FWKEY + FSSEL_2 + FN0;
  }

  void eraseSegment(uint8_t* ptr){
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
  void writeFlash(uint8_t* ptr, uint8_t* data, uint8_t len){
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
    printf("test %d\n\r", counter++);
  }

}
