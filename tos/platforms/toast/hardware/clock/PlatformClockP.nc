/* Copyright (c) 2010 People Power Co.
 * All rights reserved.
 *
 * This open source code was developed with funding from People Power Company
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the
 *   distribution.
 * - Neither the name of the People Power Corporation nor the names of
 *   its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * PEOPLE POWER CO. OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE
 *
 */

/** Top-level initialization of anything to do with the clock
 * subsystem.
 *
 * @author Peter A. Bigot <pab@peoplepowerco.com>
 * @author Doug Carlson <carlson@cs.jhu.edu>
 */

#include "InternalFlash.h"
#include "TLVStorage.h"

module PlatformClockP {
  provides interface Init;
  uses interface Init as SubInit;
  uses interface TLVStorage;
  uses interface TLVUtils;
} implementation {

  default command error_t SubInit.init () {
    return SUCCESS;
  }

//DCO self-calibration code (c) Texas Instruments 2006
#define DELTA_2MHZ_BINARY_32khz_aclk 512               // 512 x 4096Hz = 2097152 hz
#define DELTA_4MHZ_BINARY_32khz_aclk 1024               // 1024 x 4096Hz = 4194304hz
#define DELTA_1MHZ_32khz_aclk    244                   // 244 x 4096Hz = 999.4KHz
#define DELTA_8MHZ_32khz_aclk    1953                  // 1953 x 4096Hz = 7.99MHz
#define DELTA_12MHZ_32khz_aclk   2930                  // 2930 x 4096Hz = 12.00MHz
#define DELTA_16MHZ_32khz_aclk   3906                  // 3906 x 4096Hz = 15.99MHz

#define DELTA_4MHZ_BINARY_VLOCLK_aclk 1398              // 1398 x 3000Hz = 4194000

  void set_dco(uint16_t delta, void* tlvs){
    uint16_t Compare, Oldcapture = 0;
    custom_dco_entry_t e;

    BCSCTL1 |= DIVA_3;                        // ACLK = LFXT1CLK/8
    TACCTL2 = CM_1 + CCIS_1 + CAP;            // CAP, ACLK
    TACTL = TASSEL_2 + MC_2 + TACLR;          // SMCLK, cont-mode, clear
  
    while (1)
    {
      while (!(CCIFG & TACCTL2));             // Wait until capture occured
      TACCTL2 &= ~CCIFG;                      // Capture occured, clear flag
      Compare = TACCR2;                       // Get current captured SMCLK
      Compare = Compare - Oldcapture;         // SMCLK difference
      Oldcapture = TACCR2;                    // Save current captured SMCLK
  
      if (delta == Compare)
        break;                                // If equal, leave "while(1)"
      else if (delta < Compare)
      {
        DCOCTL--;                             // DCO is too fast, slow it down
        if (DCOCTL == 0xFF)                   // Did DCO roll under?
          if (BCSCTL1 & 0x0f)
            BCSCTL1--;                        // Select lower RSEL
      }
      else
      {
        DCOCTL++;                             // DCO is too slow, speed it up
        if (DCOCTL == 0x00)                   // Did DCO roll over?
          if ((BCSCTL1 & 0x0f) != 0x0f)
            BCSCTL1++;                        // Sel higher RSEL
      }
    }
    TACCTL2 = 0;                              // Stop TACCR2
    TACTL = 0;                                // Stop Timer_A
    BCSCTL1 &= ~DIVA_3;                       // ACLK = LFXT1CLK

    e.bcsctl1 = BCSCTL1;
    e.dcoctl = DCOCTL;
    call TLVUtils.addEntry(TAG_DCO_CUSTOM, 2, (tlv_entry_t*)&e, tlvs, 0);
    call TLVStorage.persistTLVStorage(tlvs);
  }

  void initClocks(){
    uint8_t ba[IFLASH_SEGMENT_SIZE];
    custom_dco_entry_t* e;
    call TLVStorage.loadTLVStorage(ba);
    if (0 == call TLVUtils.findEntry(TAG_DCO_CUSTOM, 0,
      (tlv_entry_t**)&e, ba)){
        #ifdef PLATFORM_HAS_32KHZ_CRYSTAL
            ////External crystal
            ////XT2S   = 0  : XT2 range (don't care, no XT2)
            ////LFXT1Sx= 00 : 32768 Hz crystal on LFXT1
            ////XCAPx  = 00 : no internal load capacitors(all external)
            BCSCTL3 = XCAP_0;
            set_dco(DELTA_4MHZ_BINARY_32khz_aclk, ba);
        #else
            #warning "calibrating DCO with VLOCLK"
            //VLOCLK : 12 khz (11.75khz, actually)
            //XT2S    00  : don't care
            //LFXT1Sx 10  : VLOCLK
            //XCAPX   00  : don't know
            BCSCTL3 = 0x20;
            set_dco(DELTA_4MHZ_BINARY_VLOCLK_aclk, ba);
        #endif
    } else{
        BCSCTL1 = e->bcsctl1;
        DCOCTL = e->dcoctl;
    }
    //XT2OFF = 1 : XT2 is off if it is not used for MCLK or SMCLK
    //XTS = 0
    //ACLK is src /1
    BCSCTL1 |= XT2OFF;
    BCSCTL1 &= (~DIVA_0);


    //SELMx  = 00 : MCLK source is DCO
    //DIVMx  = 00 : MCLK is src /1  
    //SELS   = 0  : SMCLK source is DCO
    //DIVS   = 00 : SMCLK is src /1
    //DCOR   = 0 : internal resistor
    BCSCTL2 = 0x00;

  }

  void initTimers(){
    //TimerA: 2**20 = smclk/4  ( 1 mhz )
    TACTL = TASSEL_SMCLK | ID_DIV4 | TAIE;

    //TimerB: source from aclk (32khz, or vloclk)
    TBCTL = TBSSEL_ACLK | TBIE;
  }

  void startTimers(){
    TACTL = MC1 | (TACTL & ~(MC1|MC0));
    TBCTL = MC1 | (TBCTL & ~(MC1|MC0));
  }

  void initFlashClock(){
    //4 mhz / 12 (11+1) -> "Flash timing generator frequency"
    FCTL2 = FWKEY + FSSEL_1 + 11;
  }

  command error_t Init.init ()
  {
    initClocks();
    initTimers();
    initFlashClock();
    startTimers();
    return call SubInit.init();
  }

  

}
