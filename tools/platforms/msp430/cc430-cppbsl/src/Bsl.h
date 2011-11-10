/* -*- mode:c++; indent-tabs-mode:nil -*-
 * Copyright (c) 2007, Technische Universitaet Berlin
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name of the Technische Universitaet Berlin nor the names
 *   of its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/**
 * hand rolled bsl tool, other ones are too slow
 * @author Andreas Koepke <koepke at tkn.tu-berlin.de>
 * @date 2007-04-16
 */

#ifndef BSL_BSL_H
#define BSL_BSL_H

#include <string.h>
#include <iostream>
#include <list>
#include "Parameters.h"
#include "Serial.h"

#ifndef BSL_RETRIES 
#define BSL_RETRIES 5
#endif

class Bsl {
protected:
    BaseSerial *s;
    const char *image;
    const int CHUNKSIZE;
    
    //DC: modified for flash-based BSL
    enum commands_t {
        MASS_ERASE = 0x15,
        RX_DATA = 0x10,
        RX_PWD = 0x11,
        BAUDRATE = 0x52,
    };

    enum {
        RESPONSE_OTHER = 0x3a,
        RESPONSE_MSG = 0x3b,
        MSG_SUCCESS = 0x00,
    };

    enum{
      BAUDRATE_115200 = 0x06,
    };

    enum syncByte_t {
        SYNC = 0x80
    };

    class Segment {
    public:
        uint32_t startAddr;
        unsigned len;
        uint8_t  data[65536];
        Segment(const Segment& a) {
            startAddr = a.startAddr;
            len = a.len;
            memcpy(data, a.data, len);
        }
        Segment() {
            startAddr = 0;
            len = 0;
        }
    };
    
    std::list<Segment> prog;
    
protected:    
    int rxPassword(int* err);
    int writeBlock(int *err, const uint16_t addr, const uint8_t* data, const uint16_t len);
    int writeData(int *err, const uint16_t addr, const uint8_t* data, const uint16_t len);
    int parseIhex(int *err);
    void setUartFrameHeader(commands_t cmd, uint16_t dataLen, frame_t* frame);
    void setAddrFrameHeader(commands_t cmd, uint16_t dataLen, uint32_t startAddr, frame_t* frame);
    int highSpeed(int *err);
    
public:
    Bsl(BaseSerial* ser, const char *img, int cs=250) : s(ser), image(img), CHUNKSIZE(cs) {
    };

    ~Bsl() {
    }
    
    int reset(int *err) { return s->reset(err);};
    int erase(int *err);
    int install(int *err);
};

#endif
