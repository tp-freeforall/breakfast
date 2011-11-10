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

#include "Bsl.h"
#include <stdio.h>
using namespace std;


void Bsl::setUartFrameHeader(commands_t cmd, uint16_t dataLen, 
  frame_t* frame) {
    frame->SYNC = SYNC;
    frame->core.CMD = cmd;
    //+1 to account for CMD
    uint16_t len = dataLen + 1;
    frame->NH = (len >> 8);
    frame->NL = len & 0xff;
}

void Bsl::setAddrFrameHeader(commands_t cmd, uint16_t dataLen, 
  uint32_t startAddr, frame_t* frame) {
  //+3 to account for address (only lower 3 bytes are used)
  setUartFrameHeader(cmd, dataLen+3, frame);
  frame->core.addrFrame.header.AL = startAddr & 0xff;
  frame->core.addrFrame.header.AM = (startAddr >> 8) & 0xff;
  frame->core.addrFrame.header.AH = (startAddr >> 16) & 0xff;
}

int Bsl::rxPassword(int *err) {
    frame_t txframe;
    frame_t rxframe;
    setUartFrameHeader(RX_PWD, 32, &txframe);
    //default password
    for(int i = 0; i < 32; i++) {
        txframe.core.body[i] = 0xff;
    }
    cout << "Transmit default password ..." << endl;
    int r = s->txrx(err, true, &txframe, &rxframe);
    if (r == -1){
        fprintf(stderr, "rx password failed\n\r");
    } else if(rxframe.core.CMD != RESPONSE_MSG ){
        fprintf(stderr, "Expected RESPONSE_MSG, got %x\n\r", rxframe.core.CMD);
        return -1;
    } else if(rxframe.core.body[0] == MSG_SUCCESS){
        printf("rx password OK\n\r");  
        return r;
    } else {
        fprintf(stderr, "Expected MSG_SUCCESS, got %x\n\r", rxframe.core.body[0]);
        return -1;
    }
}

int Bsl::erase(int *err) {
    int r = 0;
    frame_t txframe;
    frame_t rxframe;
    setUartFrameHeader(MASS_ERASE, 0, &txframe);
    for(int i = 0; i < BSL_RETRIES; i++){
      r = s->invokeBsl(err);
      if(r != -1) {
          cout << "massErase" << endl;
          r = s->txrx(err, true, &txframe, &rxframe);

          if (r != -1 && rxframe.core.CMD == RESPONSE_MSG 
              && rxframe.core.body[0] == MSG_SUCCESS){
            cout << "/massErase" << endl;
            break;
          }
          printf("/massErase (failed)\n\r");
          s->reset(err);
      }
    }
    return r;
}

int Bsl::install(int *err) {
    unsigned len = 0;
    int r = erase(err);
    if(r == -1) {
        cerr << "Bsl::install: could not erase node" << endl;
        return r;
    }
    r = rxPassword(err);
    if(r == -1) {
        cerr << "Bsl::install: password not accepted" << endl;
        return r;
    }
    r = parseIhex(err);
    if(r == -1) {
        cerr << "Bsl::install: could not parse ihex image" << endl;
        return r;
    }
    r = highSpeed(err);
    if(r == -1) {
        cerr << " Bsl::install: could not switch to high speed mode" << endl;
        return r;
    }
    cout << "Program ..." << endl;
    for(std::list<Segment>::const_iterator it = prog.begin(); it != prog.end(); ++it) {
        len += it->len;
        r = writeData(err, (uint16_t)it->startAddr,it->data, it->len);
        if(r == -1) {
            cerr << " Bsl::install: could not write data" << endl;
            return r;
        }
    }
    cout << len << " bytes programmed." << endl;
    r = s->bslExitReset(err);
    if(r == -1) {
        cerr << " Bsl::install: could not reset node" << endl;
    }
    return r;
}

int Bsl::writeBlock(int *err, const uint16_t addr, const uint8_t* data, const uint16_t len) {
    frame_t txframe;
    frame_t rxframe;
    setAddrFrameHeader(RX_DATA, len, addr, &txframe);
    memcpy(txframe.core.addrFrame.body, data, len);
    int r = s->txrx(err, true, &txframe, &rxframe);
    if (r == -1){
        fprintf(stderr, "rx data failed\n\r");
        return -1;
    } else if(rxframe.core.CMD != RESPONSE_MSG ){
        fprintf(stderr, "Expected RESPONSE_MSG, got %x\n\r", rxframe.core.CMD);
        return -1;
    } else if(rxframe.core.body[0] == MSG_SUCCESS){
        printf("rx data OK\n\r");  
        return r;
    } else {
        fprintf(stderr, "Expected MSG_SUCCESS, got %x\n\r", rxframe.core.body[0]);
        return -1;
    }
}

int Bsl::writeData(int *err, const uint16_t addr, const uint8_t* data, const uint16_t len) {
    int r = 0;
    if(!data) {
        cerr << "Command::write(): data==NULL" << endl;
        return -1;
    }
    if(addr+len>0x10000) {
        cerr << "Command::write(): addr+len>0x10000" << endl;
        return -1;
    }
    int l;
    uint16_t adr;
    for(int i=0; i<len; i+=l) {
        l=len-i;
        if(l>CHUNKSIZE) l=CHUNKSIZE;
        adr=addr+i;
        r = writeBlock(err, adr, &data[i], l);
        if(r == -1) {
            break;
        }
    }
    return r;
}

//Note: the flash bsl takes a 24-bit address, but:
// a. The cc430f5137, which is what we care about at the moment,
//    only has 32k so we never use the AH byte
// b. The parseIhex code lifted from the previous impl expects
//    16-bit addresses.
// c. Not sure if msp430-objdump will even generate 32-bit ihex
//    files.
int Bsl::parseIhex(int *err) {
    char buf[512];
    Segment segment;
    segment.len = 0;
    segment.startAddr = 0;
    int r;
    FILE *readFD = fopen(image, "r");
    if(readFD == NULL) {
        *err = errno;
        cerr << "Bsl::parseIhex: Could not open " << image << endl;
        return -1;
    };
    while(fgets(buf, 512, readFD) == buf) {
        uint16_t len;
        uint16_t addr;
        uint16_t recType;
        uint16_t checksum = 0;
        uint16_t byte;
        unsigned i;
        if(buf[0] != (uint8_t)':') {
            cerr << "Bsl::parseIhex:  " << image << "is not an ihex" << endl;
            return -1;
        }
        sscanf(buf,":%2hx%4hx%2hx",&len, &addr, &recType);
        checksum = len + (addr>>8) + (addr & 0xff) + recType;
        if(recType == 0) {
            if((segment.len != 0) && (segment.startAddr + segment.len != addr)) {
                prog.push_back(segment);
                segment.len = 0;
            }
            if(segment.len == 0) {
                segment.startAddr = addr;
            }
            for(i = 0; i  < len; i++) {
                sscanf(buf+9+2*i,"%2hx",&byte);
                segment.data[segment.len] = byte;
                checksum += segment.data[segment.len];
                ++segment.len;
            }
            checksum = (-checksum) & 0xff;
            sscanf(buf+9+2*i,"%4hx",&byte);
            if(checksum == byte) {
                
            } else {
                cerr << "Bsl::parseIhex wrong data line format in " << image << endl;
                fclose(readFD);
                return -1;
            }
        }
        else if(recType == 1) {
            prog.push_back(segment);
        }
    }
    r = fclose(readFD);
    if(r == -1) {
        *err = errno;
    }
    return r;
}

int Bsl::highSpeed(int *err) {
    frame_t txframe;
    frame_t rxframe;
    int r;
    //TODO: safety
    setUartFrameHeader(BAUDRATE, 1, &txframe);
    txframe.core.body[0] = BAUDRATE_115200;
    r = s->txrx(err, false, &txframe, &rxframe);
    if(r != -1) {
        serial_delay(10000);
        r = s->highSpeed(err);
    }
    return r;
}
