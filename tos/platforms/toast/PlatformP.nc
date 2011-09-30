/*
 * Copyright (c) 2009-2010 People Power Co.
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
 
module PlatformP {
  provides {
    interface Init;
  }
  
  uses {
    interface Init as PlatformPins;
    interface Init as PlatformClock;
    //interface Init as OneWire;
    interface Init as PeripheralInit;
  }
}

implementation {
  
//  void uwait(uint16_t u) { 
//    uint16_t t0 = TA0R;
//    while((TA0R - t0) <= u);
//  } 
  
  command error_t Init.init() {
    WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer
    //TODO: initialize reset pin function
    //SFRRPCR1 = SYSRSTUP | SYSRSTRE; //pullup, enable
    
    call PlatformPins.init();
    call PlatformClock.init();
    //call OneWire.init();

    call PeripheralInit.init();
   

    //This was causing the application to hang.
    // Wait an arbitrary 10 milliseconds for the FLL to calibrate the DCO
    // before letting the system continue on into a low power mode.
    //uwait(1024*10);    
    
    return SUCCESS;
  }
  
  /***************** Defaults ***************/
  default command error_t PeripheralInit.init() {
    return SUCCESS;
  }
  
}

