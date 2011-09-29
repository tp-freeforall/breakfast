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

#include <stdio.h>
#include "platformflash.h"

/**
 * See the explanation in the configuration file
 * @author David Moss
 */
module TestP {
  uses {
    interface Boot;
    interface Resource;
    interface Memory;
    interface Timer<TMilli> as ErrorIndicatorTimer;
    
    interface Leds;
    }
}

implementation {

  /** Buffer to read and write data to and from flash */
  uint8_t buffer[256];
  
  /** Storage for an error value so we can blink the appropriate LED */
  uint8_t errorValue;
  
  enum {
    STAGE_eraseChip = 0,
    STAGE_write = 1,
    STAGE_eraseBlock = 2,
    STAGE_verifyBlock = 3,
    
    NOTIFY_activity = 4,
    NOTIFY_allDone = 7,
  };
  
  /***************** Prototypes ****************/
  bool isFilledWith(uint8_t *buf, uint8_t fillByte, uint16_t length);
  void error(uint8_t errno);
  
  /***************** Boot Events ****************/
  event void Boot.booted() {
    // Request the SPI bus resource before interacting with the SPI bus
    //("Booted--requesting flash chip\n");
    call Resource.request();
  }
  
  /***************** Resource Events ****************/
  event void Resource.granted() {
    int i;
    
    // 1. Erase the chip
    //("Erasing chip\n");
    call Leds.set(STAGE_eraseChip);
    call Memory.eraseChip();
    
    // 2. Verify all bytes are erased to 0xFF's
    //("Verifying erase\n");
    call Leds.set(STAGE_eraseChip);
    for(i = 0; i < MEMORY_NUM_PAGES; i++) {
      call Memory.read((i * 256), &buffer, sizeof(buffer));
      call Leds.led2Toggle();
      
      if(!isFilledWith(buffer, 0xFF, sizeof(buffer))) {
        error(STAGE_eraseChip);
        return;
      }
    }
    
    // 3. Write the flash to 0x0's
    //("Writing zeros\n");
    call Leds.set(STAGE_write);
    memset(&buffer, 0x0, sizeof(buffer));
    for(i = 0; i < MEMORY_NUM_PAGES; i++) {
      call Memory.write((i * 256), &buffer, sizeof(buffer));
      call Leds.led2Toggle();
    }
    
    // 4. Verify the flash was written 0x0's
    //("Verifying zeros\n");
    call Leds.set(STAGE_write);
    for(i = 0; i < MEMORY_NUM_PAGES; i++) {
      call Memory.read((i * 256), &buffer, sizeof(buffer));
      call Leds.led2Toggle();
      
      if(!isFilledWith(buffer, 0x0, sizeof(buffer))) {
        error(STAGE_write);
        return;
      }
    }
    
    // 5. Erase each individual block of the chip
    //("Erasing block\n");
    call Leds.set(STAGE_eraseBlock);
    for(i = 0; i < MEMORY_NUM_ERASEUNITS; i++) {
      call Memory.eraseBlock(i);
      call Leds.led2Toggle();
    }
    
    // 6. Verify all blocks were erased
    //("Verifying erased block\n");
    call Leds.set(STAGE_verifyBlock);
    for(i = 0; i < MEMORY_NUM_PAGES; i++) {
      call Memory.read((i * 256), &buffer, sizeof(buffer));
      call Leds.led2Toggle();
      
      if(!isFilledWith(buffer, 0xFF, sizeof(buffer))) {
        error(STAGE_eraseBlock);
        return;
      }
    }
    
    // All done!
    //("All tests completed successfully\n");
    call Leds.set(NOTIFY_allDone);
    call Resource.release();
  }
  
  /***************** Timer Events ****************/
  event void ErrorIndicatorTimer.fired() {
//    call MultiLed.toggle(errorValue);
  }
  
  /***************** Functions ****************/
  /**
   * @return TRUE if the given buffer of the given length is filled completely
   *     with the given fill byte.
   */
  bool isFilledWith(uint8_t *buf, uint8_t fillByte, uint16_t length) {
    int i;
    
    for(i = 0; i < length; i++) {
      if(*buf != fillByte) {
        return FALSE;
      }
      
      buf++;
    }
    
    return TRUE;
  }
  
  
  /**
   * Kick off the error indicator LED so we know where the problem
   * occurred. The Resource.release() is good practice.
   */
  void error(uint8_t errno) {
    errorValue = errno;
    
    //call MultiLed.off(NOTIFY_activity);
    call ErrorIndicatorTimer.startPeriodic(128);
    call Resource.release();
  }
}

