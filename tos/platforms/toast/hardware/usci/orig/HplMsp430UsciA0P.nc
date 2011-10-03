/*
 * Copyright (c) 2009-2010 People Power Co.
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
 */

#include "msp430usci.h"

/**
 * Core implementation for any USCI module present on an MSP430 chip.
 *
 * This module makes available the module-specific registers, along
 * with a small number of higher-level functions like generic USCI
 * chip configuration that are shared among the various modes of the
 * module.
 *
 * @author Peter A. Bigot <pab@peoplepowerco.com> */
generic module HplMsp430UsciA0P(
  /** Identifier for this USCI module, unique across (type, instance) pairs */
  uint8_t USCI_ID
) @safe() {
  provides {
    interface HplMsp430Usci as Usci;
    interface HplMsp430UsciInterrupts as InterruptsRx[ uint8_t mode ];
    interface HplMsp430UsciInterrupts as InterruptsTx[ uint8_t mode ];
  }
  uses {
    interface HplMsp430UsciInterrupts as RawInterruptsRx;
    interface HplMsp430UsciInterrupts as RawInterruptsTx;
    interface ArbiterInfo;
    interface Leds;
  }
}
implementation {

/*  
#define UCmxCTLW0 (*TCAST(volatile uint16_t* ONE, UCmxCTLW0_))
#define UCmxCTL1 (*TCAST(volatile uint8_t* ONE, UCmxCTLW0_ + 0x00)) // yes, ctl1 is at offset zero
#define UCmxCTL0 (*TCAST(volatile uint8_t* ONE, UCmxCTLW0_ + 0x01)) // yes, ctl1 is at offset zero
#define UCmxBRW (*TCAST(volatile uint16_t* ONE, UCmxCTLW0_ + 0x06))
#define UCmxMCTL (*TCAST(volatile uint8_t* ONE, UCmxCTLW0_ + 0x08))
#define UCmxSTAT (*TCAST(volatile uint8_t* ONE, UCmxCTLW0_ + 0x0a))
#define UCmxRXBUF (*TCAST(volatile uint8_t* ONE, UCmxCTLW0_ + 0x0c))
#define UCmxTXBUF (*TCAST(volatile uint8_t* ONE, UCmxCTLW0_ + 0x0e))
#define UCmxABCTL (*TCAST(volatile uint8_t* ONE, UCmxCTLW0_ + 0x10))
#define UCmxI2COA (*TCAST(volatile uint16_t* ONE, UCmxCTLW0_ + 0x10))
#define UCmxIRCTL (*TCAST(volatile uint16_t* ONE, UCmxCTLW0_ + 0x12))
#define UCmxIRTCTL (*TCAST(volatile uint8_t* ONE, UCmxCTLW0_ + 0x12))
#define UCmxIRRCTL (*TCAST(volatile uint8_t* ONE, UCmxCTLW0_ + 0x13))
#define UCmxI2CSA (*TCAST(volatile uint16_t* ONE, UCmxCTLW0_ + 0x12))
#define UCmxICTL (*TCAST(volatile uint16_t* ONE, UCmxCTLW0_ + 0x1c))
#define UCmxIE (*TCAST(volatile uint8_t* ONE, UCmxCTLW0_ + 0x1c))
#define UCmxIFG (*TCAST(volatile uint8_t* ONE, UCmxCTLW0_ + 0x1d))
#define UCmxIV (*TCAST(volatile uint16_t* ONE, UCmxCTLW0_ + 0x1e))
*/

  norace volatile unsigned char UCA0CTL0 __asm ("0x0060");
  norace volatile unsigned char UCA0CTL1 __asm ("0x0061");
  norace volatile unsigned char UCA0BR0 __asm ("0x0062");
  norace volatile unsigned char UCA0BR1 __asm ("0x0063");
  norace volatile unsigned char UCA0MCTL __asm ("0x0064");
  norace volatile unsigned char IE2 __asm ("0x0001");

  async command uint8_t Usci.getModuleIdentifier() { return USCI_ID; }

  async command uint16_t Usci.getCtlw0() 
  { 
    uint16_t tmp;
    
    tmp = UCA0CTL1;
    tmp = (tmp << 8) + UCA0CTL0;
    
    return tmp; 
  }
  
  async command void Usci.setCtlw0(uint16_t v) 
  {
    UCA0CTL1 = (v >> 8);
    UCA0CTL0 = v;
  }
    
  async command uint16_t Usci.getBrw() 
  { 
     uint16_t tmp;
     
     tmp = UCA0BR1;
     tmp = (tmp << 8) + UCA0BR0;
     
     return tmp; 
   }
 
  async command void Usci.setBrw(uint16_t v) 
  {
    UCA0BR1 = (v >> 8);
    UCA0BR0 = v;
  }

  async command uint8_t Usci.getMctl() { return UCA0MCTL; }
  async command void Usci.setMctl(uint8_t v) { UCA0MCTL = v; }
  async command uint8_t Usci.getStat() { return UCA0STAT; }
  async command void Usci.setStat(uint8_t v) { UCA0STAT = v; }
  async command uint8_t Usci.getRxbuf() { return UCA0RXBUF; }
  async command void Usci.setRxbuf(uint8_t v) { 
    //DC: why does this even exist in the interface? This register is
    //read-only.
    //UCA0RXBUF = v; 
  }
  async command uint8_t Usci.getTxbuf() { return UCA0TXBUF; }
  async command void Usci.setTxbuf(uint8_t v) { UCA0TXBUF = v; }
  async command uint8_t Usci.getAbctl() { return UCA0ABCTL; }
  async command void Usci.setAbctl(uint8_t v) { UCA0ABCTL = v; }

  async command uint16_t Usci.getI2coa() 
  { 
    return 0x00; 
  }

  async command void Usci.setI2coa(uint16_t v) 
  {
    ;
  }

  async command uint16_t Usci.getIrctl() 
  { 
     uint16_t tmp;
     
     tmp = UCA0IRRCTL;
     tmp = (tmp << 8) + UCA0IRTCTL;
     
     return tmp; 
  }

  async command void Usci.setIrctl(uint16_t v) 
  {
    UCA0IRRCTL = (v >> 8);
    UCA0IRTCTL = v;
  }

  async command uint8_t Usci.getIrtctl() { return UCA0IRTCTL; }
  async command void Usci.setIrtctl(uint8_t v) { UCA0IRTCTL = v; }
  async command uint8_t Usci.getIrrctl() { return UCA0IRRCTL; }
  async command void Usci.setIrrctl(uint8_t v) { UCA0IRRCTL = v; }

  async command uint16_t Usci.getI2csa() { return 0x00; }
  async command void Usci.setI2csa(uint16_t v) { ; }
  
  async command uint16_t Usci.getIctl() { return IE2; }
  async command uint16_t Usci.setIctl(uint16_t v) { IE2 = v; }
  async command uint8_t Usci.getIe() { return IE2; }
  async command void Usci.setIe(uint8_t v) { IE2 = v; }

  async command uint8_t Usci.getIfg() { return IFG2; }
  async command void Usci.setIfg(uint8_t v) { IFG2 = v; }


  // UCAxIV format
  // 000h No interrupt pending
  // 002h Data received UCRXIFG Highest
  // 004h Transmit buffer empty UCTXIFG Lowest
  async command uint8_t Usci.getIv() 
  { 
    uint8_t ret = 0x00;
    
    if ( (IFG2 & UCA0RXIFG) == UCA0RXIFG)
      ret += 0x02;
      
    if ( (IFG2 & UCA0TXIFG) == UCA0TXIFG)
      ret += 0x04;
      
    return ret;
  }

  async command void Usci.enterResetMode_ () {
//    __asm__ __volatile__("bis %0, %1" : : "i" UCSWRST, "m" UCA0CTL1);
    UCA0CTL1 |= UCSWRST;
  }

  async command void Usci.leaveResetMode_ () {
//    __asm__ __volatile__("bic %0, %1" : : "i" UCSWRST, "m" UCA0CTL1);
    UCA0CTL1 &= ~UCSWRST;
  }

  async command void Usci.configure (const msp430_usci_config_t* config,
                                     bool leave_in_reset)
  {
    if (! config) {
      return;
    }
    call Usci.enterResetMode_();

    UCA0CTL0 = config->ctl0;
    UCA0CTL1 = config->ctl1 + UCSWRST;
    
    UCA0BR0 = config->br0;
    UCA0BR1 = config->br1;

    UCA0MCTL = config->mctl;

    if (! leave_in_reset) {
      call Usci.leaveResetMode_();
    }
  }

  async command uint8_t Usci.currentMode ()
  {
    atomic {
      if (! (UCA0CTL0 & UCSYNC)) {
        return MSP430_USCI_UART;
      }
      if (UCMODE_3 == (UCA0CTL0 & (UCMODE0 | UCMODE1))) {
        return MSP430_USCI_I2C;
      }
      return MSP430_USCI_SPI;
    }
  }

  /* Upon receipt of an interrupt, if the USCI is active then demux
   * the interrupt to the handler for the appropriate USCI mode. */

  async event void RawInterruptsRx.interrupted (uint8_t iv)
  {
    if (call ArbiterInfo.inUse()) {
      signal InterruptsRx.interrupted[ call Usci.currentMode() ](iv);
    }
  }

  async event void RawInterruptsTx.interrupted (uint8_t iv)
  {
    if (call ArbiterInfo.inUse()) {
      signal InterruptsTx.interrupted[ call Usci.currentMode() ](iv);
    }
  }

  default async event void InterruptsRx.interrupted[uint8_t mode] (uint8_t iv) { }
  default async event void InterruptsTx.interrupted[uint8_t mode] (uint8_t iv) { }

/*
#undef UCmxIV
#undef UCmxIFG
#undef UCmxIE
#undef UCmxICTL
#undef UCmxI2CSA
#undef UCmxIRRCTL
#undef UCmxIRTCTL
#undef UCmxIRCTL
#undef UCmxI2COA
#undef UCmxABCTL
#undef UCmxTXBUF
#undef UCmxRXBUF
#undef UCmxSTAT
#undef UCmxMCTL
#undef UCmxBRW
#undef UCmxCTL0
#undef UCmxCTL1
#undef UCmxCTLW0
*/ 
}
