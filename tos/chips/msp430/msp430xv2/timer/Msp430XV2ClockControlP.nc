/* Copyright (c) 2009-2010 People Power Co.
 * All rights reserved.
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
 */


/** Configuration for MSP430 Unified Clock System and Timer A modules.
 *
 * We're going to use TA0 for the 32KHz timer, and TA1 for the 1MHz
 * timer.
 *
 * @author Peter A. Bigot <pab@peoplepowerco.com>
 */

#include "hardware.h"
#include "Msp430XV2Dco.h"

module Msp430XV2ClockControlP @safe() {
  uses {
    interface McuSleepEvents;
  }
  provides {
    interface Msp430XV2ClockControl;
    interface McuPowerOverride;
    interface StdControl as InhibitUcs7WorkaroundControl;
  }
} implementation {

  async command void Msp430XV2ClockControl.configureUnifiedClockSystem (int dco_config)
  {
    uint16_t divs;
    
    atomic {
      /* ACLK is to be set to XT1CLK, assumed to be 32KHz (2^15Hz),
       * falls back to REFOCLK if absent.
       *
       * DCO is to be set as configured.  The clock divider is the
       * minimum value of 2.
       *
       * MCLK is set to DCOCLKDIV, or half the DCO rate.
       *
       * SMLCK is set to DCOCLKDIV / N such that it has a value of ~ 1MHz (2^20 Hz)
       *
       * The technique used here is cribbed from the TI Example programs
       * for the CC430, cc430x613x_UCS_2.c.  */

      //assume that external load capacitors are sufficient unless
      //  otherwise directed
      #ifndef XCAP_SETTING
      #define XCAP_SETTING 0
      #endif 
      UCSCTL6 |= (XCAP_SETTING << 2) ; 

      //if an external crystal is available, then we'll use that for
      //  ACLK and for FLLREF. We have to wait until it stabilizes.
      // Note that if XT1 is not available, this flag will remain set,
      // and so we should skip it.
      #ifdef XT1_AVAILABLE
      do{
        UCSCTL7 &= ~XT1LFOFFG; //clear XT1 fault flag
      } while(UCSCTL7 & XT1LFOFFG); //check if reset by hardware
      //reduce drive strength to minimum 
      UCSCTL6 &= ~XT1DRIVE_3;
      #endif

      /* Disable FLL control */
      __bis_SR_register(SR_SCG0);

      /* Use XT1CLK as the FLL input: if it isn't valid, the module
       * will fall back to REFOCLK.  Use FLLREFDIV value 1 (selected
       * by bits 000) */
      UCSCTL3 = SELREF__XT1CLK;
      /* The appropriate value for DCORSEL is obtained from the DCO
       * Frequency table of the device datasheet.  Find the DCORSEL
       * value from that table where the minimum frequency with DCOx=31
       * is closest to your desired DCO frequency. */
      UCSCTL0 = 0x0000;                         // Set lowest possible DCOx, MODx

      //so, it seems like these are labeled confusingly: 
      //for the first case, while the DCO is running at 2MHz, we are
      //dividing it by two (FLLD_1), so mclk will be
      //  running at 2^5*2^15 = 2^20, which is 1 mhz. confusing.
      switch (dco_config) {
        /* If unrecognized, default to the CC430 power-up value */
        case MSP430XV2_DCO_2MHz_RSEL2:
        default:
          UCSCTL1 = DCORSEL_2;
          UCSCTL2 = FLLD_1 + 31;
          divs = DIVS__1;
          break;
        case MSP430XV2_DCO_4MHz_RSEL3:
          UCSCTL1 = DCORSEL_3;
          UCSCTL2 = FLLD_1 + 63;
          divs = DIVS__2;
          break;
        case MSP430XV2_DCO_8MHz_RSEL3:
          UCSCTL1 = DCORSEL_3;
          UCSCTL2 = FLLD_1 + 127;
          divs = DIVS__4;
          break;
        case MSP430XV2_DCO_8MHz_RSEL4:
          UCSCTL1 = DCORSEL_4;
          UCSCTL2 = FLLD_1 + 127;
          divs = DIVS__4;
          break;
        case MSP430XV2_DCO_16MHz_RSEL4:
          UCSCTL1 = DCORSEL_4;
          UCSCTL2 = FLLD_1 + 255;
          divs = DIVS__8;
          break;
        case MSP430XV2_DCO_16MHz_RSEL5:
          UCSCTL1 = DCORSEL_5;
          UCSCTL2 = FLLD_1 + 255;
          divs = DIVS__8;
          break;
        case MSP430XV2_DCO_32MHz_RSEL5:
          UCSCTL1 = DCORSEL_5;
          UCSCTL2 = FLLD_1 + 511;
          divs = DIVS__16;
          break;
        case MSP430XV2_DCO_32MHz_RSEL6:
          UCSCTL1 = DCORSEL_6;
          UCSCTL2 = FLLD_1 + 511;
          divs = DIVS__16;
          break;
        case MSP430XV2_DCO_64MHz_RSEL6:
          UCSCTL1 = DCORSEL_6;
          UCSCTL2 = FLLD_1 + 1023;
          divs = DIVS__32;
          break;
        case MSP430XV2_DCO_64MHz_RSEL7:
          UCSCTL1 = DCORSEL_7;
          UCSCTL2 = FLLD_1 + 1023;
          divs = DIVS__32;
          break;
      }
    
      __bic_SR_register(SR_SCG0);               // Enable the FLL control loop

#if 0 /* No __delay_cycles intrinsic on MSPGCC (yet) */
      // Worst-case settling time for the DCO when the DCO range bits have been
      // changed is n x 32 x 32 x f_MCLK / f_FLL_reference. See UCS chapter in 5xx
      // UG for optimization.
      // 32 x 32 x 8 MHz / 32,768 Hz = 250000 = MCLK cycles for DCO to settle
      __delay_cycles(250000);
#endif

      // Loop until DCO fault flag is cleared.  Ignore OFIFG, since it
      // incorporates XT1 and XT2 fault detection.
      do {
        UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + XT1HFOFFG + DCOFFG);
        // Clear XT2,XT1,DCO fault flags
        SFRIFG1 &= ~OFIFG;                      // Clear fault flags
      } while (UCSCTL7 & DCOFFG); // Test DCO fault flag
      

      /* Use XT1 for ACLK, and DCOCLKDIV for MCLK and SMCLK */
      //if XT1 is unavailble, then it will switch over to REFOCLK
      UCSCTL4 = SELA__XT1CLK | SELS__DCOCLKDIV | SELM__DCOCLKDIV;;

      /* DIVPA routes ACLK to external pin, undivided
       * DIVA uses ACLK at 2^15 Hz, undivided
       * DIVS (SMCLK) uses DCOCLKDIV / N to produce 2^20Hz
       * DIVM (MCLK) uses DCOCLKDIV to produce DCO/2, undivided
       */
      UCSCTL5 = DIVPA__1 | DIVA__1 | divs | DIVM__1;

    }
  }

  command void Msp430XV2ClockControl.configureTimers ()
  {
    atomic {
      TA0CTL = TASSEL__ACLK | TACLR | MC__STOP | TAIE;
      TA0R = 0;
      TA1CTL = TASSEL__SMCLK | TACLR | MC__STOP | TAIE;
      TA1R = 0;
    }
  }

  async command void Msp430XV2ClockControl.start32khzTimer ()
  {
    atomic TA0CTL = MC__CONTINOUS | (TA0CTL & ~(MC0|MC1));
  }

  async command void Msp430XV2ClockControl.stop32khzTimer ()
  {
    atomic TA0CTL = MC__STOP | (TA0CTL & ~(MC0|MC1));
  }

  async command bool Msp430XV2ClockControl.is32khzTimerRunning ()
  {
    atomic return (MC_STOP != (TA0CTL & ~(MC0|MC1)));
  }

  async command void Msp430XV2ClockControl.startMicroTimer ()
  {
    atomic TA1CTL = MC__CONTINOUS | (TA1CTL & ~(MC0|MC1));
  }

  async command void Msp430XV2ClockControl.stopMicroTimer ()
  {
    atomic TA1CTL = MC__STOP | (TA1CTL & ~(MC0|MC1));
  }

  async command bool Msp430XV2ClockControl.isMicroTimerRunning ()
  {
    atomic return (MC_STOP != (TA1CTL & ~(MC0|MC1)));
  }

  /* Support for UCS7 workaround.  This chip erratum causes DCO
   * drift if the MCU is not active for at least three reference
   * count periods when coming out of LPM2 or higher.  What we'll do
   * is, if the last time we came out of sleep in such a mode isn't
   * at least that long ago, go to sleep in LPM0 instead.  This
   * relies on TA0 being active and at the same rate as REFCLK,
   * which it is.
   *
   * Validate the need for this using the LocalTime bootstrap program.
   * Errors-per-thousand should remain zero if the workaround is
   * effective, and is generally greater than 10 if not effective and
   * the erratum is present in the chip.  Alternatively, verify with
   * SerialEcho and large incoming packets.  (Disable the workaround
   * by setting the minimum active duration value below to zero.)
   *
   * NB: The current implementation means that at most 50% of the time
   * will be in a true low power mode; when the inter-wakeup duration
   * is long, a whole period will be spent in LPM0 while it would be
   * sufficient to wake up after three reference clock periods and
   * re-enter sleep at a deeper level.  To do so would require
   * configuring a timer here, which is a bit too deep in the
   * implementation.  Applications that are particularly concerned
   * about power may implement their own workaround, disabling this
   * one through the InhibitUcs7WorkaroundControl interface.
   */

  enum {
    /** UCS7 suggests waiting at least 3 reference clock periods
     * before disabling FLL. */
    MinimumFLLActiveDuration_refclk = 3
  };

  /** Set to TRUE to inhibit the UCS7 workaround code. */
  bool inhibitUCS7_;

  command error_t InhibitUcs7WorkaroundControl.start ()
  {
    atomic inhibitUCS7_ = TRUE;
    return SUCCESS;
  }
  command error_t InhibitUcs7WorkaroundControl.stop ()
  {
    atomic inhibitUCS7_ = FALSE;
    return SUCCESS;
  }

  /** TA0R value at the last wake-up which re-enabled FLL */
  uint16_t fllRestart_refclk;

  async command mcu_power_t McuPowerOverride.lowestState ()
  {
    mcu_power_t rv = MSP430_POWER_LPM4;

    if (! inhibitUCS7_) {
      uint16_t now_refclk;
      uint16_t fll_active_refclk;
      atomic now_refclk = TA0R;
      if (now_refclk >= fllRestart_refclk) {
        fll_active_refclk = now_refclk - fllRestart_refclk;
      } else {
        fll_active_refclk = fllRestart_refclk - now_refclk;
      }
      if (MinimumFLLActiveDuration_refclk > fll_active_refclk) {
        rv = MSP430_POWER_LPM0;
      }
    }
    return rv;
  }

  async event void McuSleepEvents.preSleep (mcu_power_t sleep_mode) { }

  async event void McuSleepEvents.postSleep (mcu_power_t sleep_mode)
  {
    if (sleep_mode >= MSP430_POWER_LPM1) {
      atomic fllRestart_refclk = TA0R;
    }
  }

}
