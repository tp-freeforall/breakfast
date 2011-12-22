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



  void eraseSegment(uint8_t* ptr){
    //set up for the segment erase
    //MERAS=0, ERASE=1: erase segment
    //dummy write to segment being erased: in this case, info A
    *ptr = 0;
    //should stall until done
    FCTL1 = FWKEY;
  }

  //TODO: watch out for cumulative programming time limit
  //since this is running from flash, can only do byte/word writes
  void writeFlash(uint8_t* ptr, uint8_t* data, uint8_t len){
    uint8_t i;
    //set up for write
    FCTL1 = FWKEY + WRT;
    for(i = 0; i < len; i++){
      ptr[i] = data[i];
    }
    //clear write bit
    FCTL1 = FWKEY;
  }

  enum{
    IFLASH_SEGMENT_SIZE = 64,
    IFLASH_ERASED = 0xFF,
  };

  #define IFLASH_START ((void*) 0x1000)
  #define IFLASH_END   ((void*) 0x10FF)
  #define IFLASH_NEXT  ((uint8_t*) 0x10FF)



  uint8_t fromInverseUnary(uint8_t iu){
    uint8_t ret = 0;
    //printf("from IU: %x ", iu);

    iu ^= 0xFF;
    while (iu){
      ret += 1;
      iu = (iu >> 1);
    }
    //printf("-> %x\n\r", ret);
    return ret;
  }

  uint8_t incrementInverseUnary(uint8_t iu){
    uint8_t ret = (iu - 1) & iu;
    //printf("increment IU: %x -> %x\n\r", iu, ret);
    return ret;
  }

  //we can flip bits from 1 to 0 without doing a segment erase, so a
  //freshly-erased segment will be marked with version 1111 1111
  //when we start a new segment, we clear another bit from the
  //previously-existing segments. 
  // this means that at any given time, the oldest segment is the one
  // that has the lowest value in its version byte.
  //e.g. 
  // A      B       C       D
  // 1111   1111    1111    1111
  // 0111   1111    1111    1111
  // 0011   0111    1111    1111
  // 0001   0011    0111    1111
  // 0000   0001    0011    0111
  command error_t InternalFlash.write(void* addr, void* buf, uint16_t size) {
    uint8_t segmentNum;
    uint8_t* targetSegmentStart;
    uint8_t wdState;
    volatile uint8_t* next = IFLASH_NEXT;
    uint8_t nextVal;
    
    if ((uint16_t)addr + size > IFLASH_SEGMENT_SIZE - 1){
      return ESIZE;
    }
    segmentNum = fromInverseUnary(*next);
    targetSegmentStart = (IFLASH_START + (segmentNum * IFLASH_SEGMENT_SIZE));

    printf("Write: Segment start %p\n\r", targetSegmentStart);

    wdState = WDTCTL & 0x00ff;
    //set up timing generator (mclk/12 puts it in the right range)
    FCTL2 = FWKEY + FSSEL_1 + 11;
    //unlock
    FCTL3 = FWKEY; 

    //erase the target segment
    FCTL1 = FWKEY + ERASE;
    *targetSegmentStart = 0;

    //write to it
    FCTL1 = FWKEY + WRT;
    memcpy((void*)((uint16_t)addr + targetSegmentStart), buf, size);
    
    //increment the next segment number
    //TODO: this doesn't seem to always "take". why? are we exceeding
    //  the cumulative programming time for this segment? That can't
    //  be right. 
    nextVal = incrementInverseUnary(*next);
    *next = nextVal;

    //disable write
    FCTL1 = FWKEY;
    //lock
    FCTL3 = FWKEY + LOCK + LOCKA;
    WDTCTL = WDTPW + wdState;
    return SUCCESS;
  }

  command error_t InternalFlash.read(void* addr, void* buf, uint16_t size) {
    void* targetSegmentStart;

    if ((size + (uint16_t)addr) > (IFLASH_SEGMENT_SIZE - 1 )){
      return ESIZE;
    }
    //TODO: fix wrap-around
    targetSegmentStart = IFLASH_START + (fromInverseUnary(*IFLASH_NEXT) - 1)*
      IFLASH_SEGMENT_SIZE;
    printf("Read: Segment start %p \n\r", targetSegmentStart);
    addr = (void*)((uint16_t)targetSegmentStart + (uint16_t)addr);

    //bingo-bango
    memcpy(buf, addr, size);
    return SUCCESS;
  }

}
