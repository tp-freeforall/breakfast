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

module InternalFlashC{
  provides interface InternalFlash;
}

implementation {

   enum{
    IFLASH_SEGMENT_SIZE = 64,
    IFLASH_NUM_SEGMENTS = 4,
    IFLASH_ERASED = 0xFF,
  };

  #define IFLASH_START ((void*) 0x1000)
  #define IFLASH_END   ((void*) 0x10FF)
  #define IFLASH_NEXT  ((uint8_t*) 0x10FF)

  uint8_t fromInverseUnary(uint8_t iu){
    uint8_t ret = 0;

    iu ^= 0xFF;
    while (iu){
      ret += 1;
      iu = (iu >> 1);
    }
    return ret;
  }

  uint8_t incrementInverseUnary(uint8_t iu){
    uint8_t ret = (iu - 1) & iu;
    return ret;
  }

  int8_t getNextSegmentIndex(){
    return fromInverseUnary(*IFLASH_NEXT) % IFLASH_NUM_SEGMENTS;
  }

  uint8_t* getNextSegmentStart(){
    uint8_t* ret;
    uint8_t index = (IFLASH_NUM_SEGMENTS - getNextSegmentIndex() - 1)%IFLASH_NUM_SEGMENTS;

    ret = IFLASH_START + (index * IFLASH_SEGMENT_SIZE);
    return ret;
  }

  uint8_t* getCurrentSegmentStart(){
    uint8_t* ret;
    uint8_t index = (IFLASH_NUM_SEGMENTS - getNextSegmentIndex() )%IFLASH_NUM_SEGMENTS;
    ret = IFLASH_START + (index * IFLASH_SEGMENT_SIZE);
    return ret;
  }

  void incrementSegmentIndex(){
    volatile uint8_t* index = IFLASH_NEXT;
    uint8_t nextVal;
    nextVal = incrementInverseUnary(*index);
    *index = nextVal;
  }

  //we can flip bits from 1 to 0 without doing a segment erase, so:
  // 0xffff = "segment A erased"  -> write A, read D : 0
  // 0xfffe = "segment A written" -> write B, read A : 1
  // 0xfffc = "segment B written" -> write C, read B : 2
  // 0xfff8 = "segment C written" -> write D, read C : 3
  // 0xfff0 = "segment D written" -> write A, read D : 4
  command error_t InternalFlash.write(void* addr, void* buf, uint16_t size) {
    volatile uint8_t* targetSegmentStart;
    uint8_t wdState;
    
    if ((uint16_t)addr + size > IFLASH_SEGMENT_SIZE - 1){
      return ESIZE;
    }
    targetSegmentStart = getNextSegmentStart();


    wdState = WDTCTL & 0x00ff;
    WDTCTL = WDTPW + WDTHOLD;
    //set up timing generator (mclk/12 puts it in the right range)
    FCTL2 = FWKEY + FSSEL_1 + 11;

    //unlock: writing 1 to LOCKA *toggles* it, it doesn't set it.
    //Writing 0 has no effect. SO, we want to write 1 if the bit is
    //already set
    FCTL3 = FWKEY + (FCTL3 & LOCKA); 
    //erase the target segment
    FCTL1 = FWKEY + ERASE;
    *targetSegmentStart = 0;

    //write to it
    FCTL1 = FWKEY + WRT;
    memcpy((void*)((uint16_t)addr + targetSegmentStart), buf, size);

    incrementSegmentIndex();

    FCTL1 = FWKEY;
    //lock: LOCKA & (FCTL3 ^ LOCKA) = 0 if already locked, 1 if not
    FCTL3 = FWKEY + LOCK + (LOCKA & (FCTL3 ^ LOCKA));
    WDTCTL = WDTPW + wdState;
    return SUCCESS;
  }

  command error_t InternalFlash.read(void* addr, void* buf, uint16_t size) {
    void* targetSegmentStart = (void*) getCurrentSegmentStart();

    if ((size + (uint16_t)addr) > (IFLASH_SEGMENT_SIZE - 1 )){
      return ESIZE;
    }
    addr = (void*)((uint16_t)targetSegmentStart + (uint16_t)addr);

    //bingo-bango
    memcpy(buf, addr, size);
    return SUCCESS;
  }

}
