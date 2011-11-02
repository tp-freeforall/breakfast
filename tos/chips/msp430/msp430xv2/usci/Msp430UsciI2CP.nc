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
 *
 */

#include "msp430usci.h"

/**
 * Implement the UART-related interfaces for a MSP430 USCI module
 * instance.
 *
 * Interrupt Management
 * --------------------
 *
 * Upon grant of the USCI in UART mode to a client, interrupts are
 * turned off.
 *
 * On the MSP430, when the TX interrupt is raised the MCU
 * automatically clears the UCTXIFG bit that indicates that the TXBUF
 * is available for writing characters.  Rather than maintain local
 * state managed by cooperation between the TX interrupt handler and
 * the send code, we leave the TX interrupt disabled and rely on the
 * UCTXIFG flag to indicate that single-byte transmission is
 * permitted.
 *
 * An exception to this is in support of the UartSerial.send()
 * function.  The transmit interrupt is enabled when the outgoing
 * message is provided; subsequent sends are interrupt-driven, and the
 * interrupt is disabled just prior to transmitting the last character
 * of the packet.  This leaves the UCTXIFG flag set upon completion of
 * the transfer.
 *
 * The receive interrupt is enabled upon configuration.  It is
 * controlled using the UartStream functions.  While a buffered
 * receive operation is active, received characters will be stored and
 * no notification provided until the full packet has been received.
 * If no buffered receive operation is active, the receivedByte()
 * event will be signaled for each received character.
 *
 * As with the transmit interrupt, MCU execution of the receive
 * interrupt clears the UCRXIFG flag, making interrupt-driven
 * reception fundamentally incompatible with the busy-waiting
 * UartByte.receive() method.
 *
 * @author Peter A. Bigot <pab@peoplepowerco.com> */
generic module Msp430UsciUartP () @safe() {
  provides {
    //TODO: usci_gen1 interfaces
    interface ResourceConfigure[ uint8_t client ];
    interface Msp430UsciError[ uint8_t client ];
  }

  uses {
    interface HplMsp430Usci as Usci;
    interface HplMsp430UsciInterrupts as Interrupts;
    interface HplMsp430GeneralIO as SCL;
    interface HplMsp430GeneralIO as SDA;

    interface Msp430UsciConfigure[ uint8_t client ];

    interface ArbiterInfo;
    
    interface LocalTime<TMilli> as LocalTime_bms;
  }

} implementation {
  //TODO: port from usci_gen1 implementation
}
