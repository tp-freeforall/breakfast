/* 
 * Copyright (c) 2009-2010 People Power Company
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


/**
 * Implement the LED-relevant interfaces for the SuRF platform.
 *
 * Traditionally, the PlatformLedsC component has exported named
 * GeneralIO interfaces, which are subsequently used in a LedsP
 * implementation to support the Leds interface.  Whether an LED is
 * active-high or active-low is platform specific, and therefore
 * should not be delegated to a supposedly platform-dependent
 * component.
 *
 * We need to implement the LED functionality here.  But we're in the
 * platform-specific file, so we know we're using an MSP430.  There's
 * no point in trying to use generic GeneralIO interfaces to interact
 * with the registers.  Eliminating them, while using a table to
 * identify LED positions, drops the code size by about 64 bytes and
 * makes the interface cleaner.
 *
 * @author Peter A. Bigot <pab@peoplepowerco.com>
 */
module PlatformLedP {
  provides {
    interface Init;
    interface Leds;
    interface Led[uint8_t led_id];
    interface MultiLed;
  }
} implementation {


  command error_t Init.init() {

    return SUCCESS;
  }

  async command void Leds.led0Off () { return; }
  async command void Leds.led0On () { return; }
  async command void Leds.led0Toggle () { return; }
  async command void Leds.led1Off () { return; }
  async command void Leds.led1On () { return; }
  async command void Leds.led1Toggle () { return; }
  async command void Leds.led2Off () { return; }
  async command void Leds.led2On () { return; }
  async command void Leds.led2Toggle () { return; }
  async command uint8_t Leds.get () { return 0; }
  async command void Leds.set (uint8_t v) { return; }

  async command unsigned int MultiLed.get () { return 0; }
  async command void MultiLed.set (unsigned int value) { return; }
  async command void MultiLed.on (unsigned int led_id) { return; }
  async command void MultiLed.off (unsigned int led_id) { return; }
  async command void MultiLed.setSingle (unsigned int led_id, bool on) { return; }
  async command void MultiLed.toggle (unsigned int led_id) { return; }
  async command void Led.on[uint8_t led_id] () { return; }
  async command void Led.off[uint8_t led_id] () { return; }
  async command void Led.set[uint8_t led_id] (bool on) { return; }
  async command void Led.toggle[uint8_t led_id] () { return; }

}

