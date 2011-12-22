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
    uint8_t wdState = WDTCTL & 0x00ff;
    //hold WDT
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

#ifdef TEST_MANUAL
  #define DEST_ADDR ((uint8_t*)0x1000)
  event void Timer.fired(){
    uint8_t check;

    //should be 0xff after fresh install, or whatever it was at the
    //  end of previous cycle
    check = *((uint8_t*)DEST_ADDR);
    printf("Value at %p is %x\n\r", DEST_ADDR, check);
    
    //should be 0xff after erasure
    eraseSegment(DEST_ADDR);
    check = *((uint8_t*)DEST_ADDR);
    printf("Value at %p after erase is %x\n\r", DEST_ADDR, check);

    //should be counter value after write
    writeFlash(DEST_ADDR, &counter, 1);
    check = *((uint8_t*)DEST_ADDR);
    printf("Value at %p after write is %x\n\r", DEST_ADDR, check);

    counter++;
  }
#else
  #define DEST_ADDR ((uint8_t*)0x00)
  event void Timer.fired(){
    uint8_t check = 0;
    error_t error;
    error = call InternalFlash.write(DEST_ADDR, &counter, 1);
    printf("\n\rWrote %d to %p: %s\n\r", counter, DEST_ADDR, decodeError(error));
    error = call InternalFlash.read(DEST_ADDR, &check, 1);
    printf("\n\rRead %d from %p: %s\n\r", check, DEST_ADDR, decodeError(error));
    counter++;
    printf("\n\r\n\r");
  }
#endif 

}
