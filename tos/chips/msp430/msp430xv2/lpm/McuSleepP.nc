/* Copyright (c) 2009-2010 People Power Co.
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

/*
 * "Copyright (c) 2005 Stanford University. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software and
 * its documentation for any purpose, without fee, and without written
 * agreement is hereby granted, provided that the above copyright
 * notice, the following two paragraphs and the author appear in all
 * copies of this software.
 * 
 * IN NO EVENT SHALL STANFORD UNIVERSITY BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES
 * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN
 * IF STANFORD UNIVERSITY HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 * 
 * STANFORD UNIVERSITY SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE
 * PROVIDED HEREUNDER IS ON AN "AS IS" BASIS, AND STANFORD UNIVERSITY
 * HAS NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, UPDATES,
 * ENHANCEMENTS, OR MODIFICATIONS."
 *
 */

/**
 * Implementation of TEP 112 (Microcontroller Power Management) for
 * the MSP430. Code for low power calculation copied from older
 * msp430hardware.h by Vlado Handziski, Joe Polastre, and Cory Sharp.
 *
 * Uses TI defines to identify which USCI resources are present.
 * Locate these by searching for HAS_T in the TI Code Composer Studio
 * header files in ccsv4/msp430/include.  MSPGCC and IAR should match
 * these definitions.
 *
 * @author Philip Levis
 * @author Vlado Handziski
 * @author Joe Polastre
 * @author Cory Sharp
 * @author Peter A. Bigot <pab@peoplepowerco.com>
 * @date   October 26, 2005
 * @see  Please refer to TEP 112 for more information about this component and its
 *          intended use.
 *
 */

module McuSleepP @safe() {
  provides {
    interface McuSleep;
    interface McuPowerState;
    interface McuSleepEvents;
  }
  uses {
    interface McuPowerOverride;
  }
}

implementation {

  /* Note that the power values are maintained in an order
   * based on their active components, NOT on their values.*/
  // NOTE: This table should be in progmem.
  // NOTE: On 5xx architectures, we assume SMCLKOFF is not set
  const uint16_t msp430PowerBits[MSP430_POWER_LPM4 + 1] = {
    0,                                       // ACTIVE
    SR_CPUOFF,                               // LPM0
    SR_SCG0+SR_CPUOFF,                       // LPM1
    SR_SCG1+SR_CPUOFF,                       // LPM2
    SR_SCG1+SR_SCG0+SR_CPUOFF,               // LPM3
    SR_SCG1+SR_SCG0+SR_OSCOFF+SR_CPUOFF,     // LPM4
  };

  async command void McuSleep.sleep() {
    uint16_t temp;
    mcu_power_t power_state;
        
    power_state = call McuPowerOverride.lowestState();
    signal McuSleepEvents.preSleep(power_state);
    temp = msp430PowerBits[power_state] | SR_GIE;
    __asm__ __volatile__( "bis  %0, r2" : : "m" (temp) );
    // All of memory may change at this point...
    asm volatile ("" : : : "memory");
    __nesc_disable_interrupt();
    signal McuSleepEvents.postSleep(power_state);
  }

  async command void McuPowerState.update ()
  {
    // Do nothing; we always recalculate
  }

  default async command mcu_power_t McuPowerOverride.lowestState()
  {
    return MSP430_POWER_LPM4;
  }

  default async event void McuSleepEvents.preSleep(mcu_power_t sleep_mode) { }
  default async event void McuSleepEvents.postSleep(mcu_power_t sleep_mode) { }

}
