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
 * DC: modified for use with msp430f235 
 *
 * @author Philip Levis
 * @author Vlado Handziski
 * @author Joe Polastre
 * @author Cory Sharp
 * @author Doug Carlson
 * @date   October 26, 2005
 * @see  Please refer to TEP 112 for more information about this component and its
 *          intended use.
 *
 */

module McuSleepC @safe() {
  provides {
    interface McuSleep;
    interface McuPowerState;
  }
  uses {
    interface McuPowerOverride;
  }
}
implementation {
  bool dirty = TRUE;
  mcu_power_t powerState = MSP430_POWER_ACTIVE;

  /* Note that the power values are maintained in an order
   * based on their active components, NOT on their values.*/
  // NOTE: This table should be in progmem.
  const uint16_t msp430PowerBits[MSP430_POWER_LPM4 + 1] = {
    0,                                       // ACTIVE
    SR_CPUOFF,                               // LPM0
    SR_SCG0+SR_CPUOFF,                       // LPM1
    SR_SCG1+SR_CPUOFF,                       // LPM2
    SR_SCG1+SR_SCG0+SR_CPUOFF,               // LPM3
    SR_SCG1+SR_SCG0+SR_OSCOFF+SR_CPUOFF,     // LPM4
  };
   
  mcu_power_t getPowerState() {
    mcu_power_t pState = MSP430_POWER_LPM4;
    bool smclk_from_dco = !(BCSCTL2 & SELS);
   
    //OK, so:
    // LPM4- Only interrupts, everything shut down
    // LPM3- Keep ACLK running, everything else shut down
    // LPM2- leave DC generator enabled, but shut off DCO.
    // LPM1- Leave ACLK, SMCLK running. Disable DCO if not used for
    //       MCLK
    // LPM0- Leave ACLK, SMCLK, DCO/DC generator running
    // Active- CPU enabled, everything active

    //Timer B keeps us at LPM 3 if it's sourced from ACLK and has
    //interrupts enabled
    if(((TBCTL & TBSSEL_3) == TBSSEL_ACLK) &&
       (TBCTL & TBIE)){
      pState = MSP430_POWER_LPM3;
    }

    //Timer A keeps us at LPM1 if:
    //smclk sourced from dco and
    //Timer A sourced from smclk and
    //Timer A in use (at least one CC module has an enabled interrupt)
    //? Timer A interrupts are enabled
    if(smclk_from_dco &&     
       (((TACTL & TASSEL_3) == TASSEL_SMCLK) && 
       ((TACCTL0 & CCIE) | (TACCTL1 & CCIE) | (TACCTL2 & CCIE))) &&
       (TACTL & TAIE)
      ){
      pState = MSP430_POWER_LPM1;
    }


    //USCI check: UART mode, SPI mode, I2C mode
    //TODO: not necessary? 
    //  uart: see 15.3.14 in msp430x2xx family user's guide
    //  spi:  see 16.3.7
    //  i2c:  see 17.3.6
    //
    // "The USCI module provides automatic clock activation for SMCLK
    // for use with low-power modes. When
    // SMCLK is the USCI clock source, and is inactive because the device
    // is in a low-power mode, the USCI
    // module automatically activates it when needed, regardless of the
    // control-bit settings for the clock source.
    // The clock remains active until the USCI module returns to its idle
    // condition. After the USCI module returns
    // to the idle condition, control of the clock source reverts to the
    // settings of its control bits. Automatic clock
    // activation is not provided for ACLK.
    // When the USCI module activates an inactive clock source, the clock
    // source becomes active for the whole
    // device and any peripheral configured to use the clock source may
    // be affected. For example, a timer using
    // SMCLK will increment while the USCI module forces SMCLK
    // active."
    //
    // spi/i2c text indicate specifically that in slave mode LPM4 is
    // fine. Not sure why uart doesn't mention this. Do we need to
    // leave the DC generator on for this, or will it just bring it up
    // automatically? Only time will tell.

#ifdef __msp430_have_adc12
    // ADC12 check, pre-condition: pState != MSP430_POWER_ACTIVE
    if (ADC12CTL0 & ADC12ON){
      if (ADC12CTL1 & ADC12SSEL_2){
        // sample or conversion operation with MCLK or SMCLK
        if (ADC12CTL1 & ADC12SSEL_1){
          //LPM1 if:
          // - ADC12 on (ADC12CTL0 & ADC12ON)
          // - ADC12 using SMCLK (ADC12SSEL_2 set, as is ADC12SSEL_1)
          pState = MSP430_POWER_LPM1;
        }else{
          //Active if ADC12 using MCLK
          pState = MSP430_POWER_ACTIVE;
        }
      } else if ((ADC12CTL1 & SHS0) && ((TACTL & TASSEL_3) == TASSEL_2)){
        // Timer A is used as sample-and-hold source and SMCLK sources Timer A
        // (Timer A interrupts are always disabled when it is used by the 
        // ADC subsystem, that's why the Timer check above is not enough)

        //LPM1 if:
        // - not using MCLK/SMCLK directly, but SMCLK is sourcing
        //   Timer A and ADC12 is doing sample-and-hold with TimerA
        //   as the source
	      pState = MSP430_POWER_LPM1;
      }
    }
#endif
    
    return pState;
  }
  
  void computePowerState() {
    powerState = mcombine(getPowerState(),
			  call McuPowerOverride.lowestState());
  }
  
  async command void McuSleep.sleep() {
    uint16_t temp;
    if (dirty) {
      computePowerState();
      //dirty = 0;
    }
    temp = msp430PowerBits[powerState] | SR_GIE;
    __asm__ __volatile__( "bis  %0, r2" : : "m" (temp) );
    // All of memory may change at this point...
    asm volatile ("" : : : "memory");
    __nesc_disable_interrupt();
  }

  async command void McuPowerState.update() {
    atomic dirty = 1;
  }

 default async command mcu_power_t McuPowerOverride.lowestState() {
   return MSP430_POWER_LPM4;
 }

}
