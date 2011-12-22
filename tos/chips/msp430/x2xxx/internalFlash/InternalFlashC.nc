// $Id: InternalFlashC.nc,v 1.4 2010-06-29 22:07:48 scipio Exp $

/*
 *
 *
 * Copyright (c) 2000-2004 The Regents of the University  of California.  
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the
 *   distribution.
 * - Neither the name of the University of California nor the names of
 *   its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 * InternalFlashC.nc - Internal flash implementation for telos msp
 * platform. On the msp, the flash must first be erased before a value
 * can be written. However, the msp can only erase the flash at a
 * segment granularity (128 bytes for the information section). This
 * module allows transparent read/write of individual bytes to the
 * information section by dynamically switching between the two
 * provided segments in the information section.
 *
 * Valid address range is 0x1000 - 0x107E (0x107F is used to store the
 * version number of the information segment).
 *
 * Doug Carlson: Ported to x2xx family 
 *
 * @author Jonathan Hui <jwhui@cs.berkeley.edu>
 * @author Doug Carlson <carlson@cs.jhu.edu>
 */

module InternalFlashC {
  provides interface InternalFlash;
}

implementation {

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


  enum {
    IFLASH_OFFSET     = 0x1000,
    IFLASH_SIZE       = 128,
    IFLASH_SEG0_VNUM_ADDR = 0x107f,
    IFLASH_SEG1_VNUM_ADDR = 0x10ff,
    IFLASH_INVALID_VNUM = -1,
  };

  uint8_t chooseSegment() {
    int8_t vnum0 = *(int8_t*)IFLASH_SEG0_VNUM_ADDR;
    int8_t vnum1 = *(int8_t*)IFLASH_SEG1_VNUM_ADDR;
    if (vnum0 == IFLASH_INVALID_VNUM){
      printf("vnum0 invalid\n\r");
      return 1;
    }else if (vnum1 == IFLASH_INVALID_VNUM){
      printf("vnum1 invalid\n\r");
      return 0;
    }
    return ( (int8_t)(vnum0 - vnum1) < 0 );
  }

  command error_t InternalFlash.write(void* addr, void* buf, uint16_t size) {

    volatile int8_t *newPtr;
    int8_t *oldPtr;
    int8_t *bufPtr = (int8_t*)buf;
    int8_t version;
    uint16_t i;
    //addr: [0x0, 0x7e] -> [0x1000, 0x107e]
    addr += IFLASH_OFFSET;
    newPtr = oldPtr = (int8_t*)IFLASH_OFFSET;
    //map to next segment
    if (chooseSegment()) {
      printf("segment 1\n\r");
      oldPtr += IFLASH_SIZE;
    }
    else {
      printf("segment 0\n\r");
      addr += IFLASH_SIZE;
      newPtr += IFLASH_SIZE;
    }
    
    printf("addr %p oldPtr %p newPtr %p buf %p\n\r", addr, oldPtr, newPtr, buf);

    //set flash timing generator 
    //MCLK: 4mhz on toast, so we divide by 12 to get ~367khz
    //  datasheet indicates it should be between 257khz and 476khz
    FCTL2 = FWKEY + FSSEL1 + (11);
    //clear lock bits (also clears locka!)
    FCTL3 = FWKEY;
    //enable segment erase
    FCTL1 = FWKEY + ERASE;
    //writing to newPtr causes erase to occur
    *newPtr = 0;
    //enable write (disable erase)
    FCTL1 = FWKEY + WRT;
    
    //do the copy
    for ( i = 0; i < IFLASH_SIZE-1; i++, newPtr++, oldPtr++ ) {
      if ((uint16_t)newPtr < (uint16_t)addr || (uint16_t)addr+size <= (uint16_t)newPtr)
	*newPtr = *oldPtr;
      else
	*newPtr = *bufPtr++;
    }
    //write the version
    version = *oldPtr + 1;
    if (version == IFLASH_INVALID_VNUM)
      version++;
    *newPtr = version;
    //disable write
    FCTL1 = FWKEY;
    //lock
    FCTL3 = FWKEY + LOCK + LOCKA;
    printf("version %d (in flash at %p: %d)\n\r", version, newPtr, *newPtr);
    return SUCCESS;

  }

  command error_t InternalFlash.read(void* addr, void* buf, uint16_t size) {
    //find the right physical location
    addr += IFLASH_OFFSET;
    if (chooseSegment())
      addr += IFLASH_SIZE;
    //bingo-bango
    memcpy(buf, addr, size);

    return SUCCESS;

  }

}
