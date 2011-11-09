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
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "../config.h"
#ifdef HAVE_LINUX_VERSION_H
#include <linux/version.h>
#else
#define LINUX_VERSION_CODE 1
#define KERNEL_VERSION 3
#endif

#include "Serial.h"

using namespace std;

int serial_connect(int* err, const char* dev, int* readFD, int* writeFD, termios* pt)
{
    struct termios my_tios;
    struct serial_struct serinfo;
    int r = 0;
    *readFD = -1;
    *writeFD = -1;
    for(int i = 0; i < 2; i++) {
        *readFD = open(dev, O_RDONLY | O_NOCTTY | O_NONBLOCK);
        *err = errno;
        if(*readFD != -1) {
            break;
        }
        else if((*readFD == -1) && (errno == EAGAIN)) {
            serial_delay(1000000);
        }
        else {
            return -1;
        }
    }
    if(*readFD == -1) {
        return -1;
    }
    
    for(int i = 0; i < 3; i++) {
        *writeFD = open(dev, O_WRONLY | O_NOCTTY);
        *err = errno;
        if(*writeFD != -1) {
            break;
        }
        else if((*writeFD == -1) && (errno == EAGAIN)) {
            serial_delay(1000000);
        }
        else {
            close(*readFD);
            *readFD = -1;
            return -1;
        }
    }
    if(*writeFD == -1) {
        close(*readFD);
        *readFD = -1;
        return -1;
    }
    /* prepare attributes */
#if defined(HAVE_LINUX_VERSION_H) && (LINUX_VERSION_CODE < KERNEL_VERSION(2,6,24))
    r = tcgetattr(*writeFD, &my_tios);
    if(r == -1) {
        *err = errno;
        close(*readFD);
        close(*writeFD);
        return -1;
    }
    *pt = my_tios;
    cfmakeraw(&my_tios);
    my_tios.c_iflag |= IGNBRK | INPCK;
    my_tios.c_cflag |= (CS8 | CLOCAL | CREAD | PARENB);
    cfsetispeed(&my_tios, B38400); // dummy
    cfsetospeed(&my_tios, B38400); // dummy    

    r = tcsetattr(*readFD, TCSANOW, &my_tios);
    if(r == -1) {
        *err = errno;
        r = tcsetattr(*writeFD, TCSANOW, pt);
        close(*readFD);
        close(*writeFD);
        return -1;        
    }
    
    /* hack for baudrate */
    r = ioctl(*writeFD, TIOCGSERIAL, &serinfo);
    if(r == -1) {
        *err = errno;
        r = tcsetattr(*writeFD, TCSANOW, pt);
        close(*readFD);
        close(*writeFD);
        return -1;        
    }    
    serinfo.custom_divisor = serinfo.baud_base / 9600;
    if(serinfo.custom_divisor == 0) serinfo.custom_divisor = 1;
    serinfo.flags &= ~ASYNC_SPD_MASK;
    serinfo.flags |= ASYNC_SPD_CUST;
    r = ioctl(*writeFD, TIOCSSERIAL, &serinfo);
    if(r == -1) {
        *err = errno;
        r = tcsetattr(*writeFD, TCSANOW, pt);
        close(*readFD);
        close(*writeFD);
        return -1;        
    }
#else
    r = tcgetattr(*writeFD, &my_tios);
    if(r == -1) {
        *err = errno;
        close(*readFD);
        close(*writeFD);
        return -1;
    }
    *pt = my_tios;
    cfmakeraw(&my_tios);
    my_tios.c_iflag |= IGNBRK | INPCK;
    my_tios.c_cflag |= (CS8 | CLOCAL | CREAD | PARENB);
    cfsetispeed(&my_tios, B9600);
    cfsetospeed(&my_tios, B9600);
    r = tcsetattr(*readFD, TCSANOW, &my_tios);
    if(r == -1) {
        *err = errno;
        r = tcsetattr(*writeFD, TCSANOW, pt);
        close(*readFD);
        close(*writeFD);
        return -1;        
    }
#endif
    
    // clear buffers
    r = tcflush(*writeFD, TCIOFLUSH);
    if(r == -1) {
        *err = errno;
        r = tcsetattr(*writeFD, TCSANOW, pt);
        close(*readFD);
        close(*writeFD);
        return -1;        
    }
    if(r == -1) {
        *err = errno;
        r = tcsetattr(*writeFD, TCSANOW, pt);
        close(*readFD);
        close(*writeFD);
    }
    return r;
};

int BaseSerial::setPins(int *err) {
    setRST(err);
    return setTEST(err);
}

int BaseSerial::resetPins(int *err) {
    setRST(err);
    return clrTEST(err);
}

int BaseSerial::disconnect(int *err) {
    int r;
    if(serialWriteFD != -1) {
        r = resetPins(err);
        if(r == -1) {
            cerr << "WARN: BaseSerial::disconnect could not reset pins, " << strerror(*err) << endl;
        }
        r = tcsetattr(serialWriteFD, TCSANOW, &oldtermios);
    }
    if(serialReadFD != -1) {
        r = close(serialReadFD);
        if(r == -1) {
            *err = errno;
        }
        serialReadFD = -1;
    }
    if(serialWriteFD != -1) {
        r = close(serialWriteFD);
        if(r == -1) {
            *err = errno;
        }
        serialWriteFD = -1;    
    }
    return r;
}

//TODO: update for flash
int BaseSerial::reset(int *err) {
    int r = 0;
    r = setRST(err);
    if(r == -1) return -1;
    r = setTEST(err);
    if(r == -1) return -1;
    serial_delay(switchdelay);
    r = clrRST(err);
    if(r == -1) return -1;
    serial_delay(switchdelay);
    r = setRST(err);
    if(r == -1) return -1;
    serial_delay(switchdelay);
    cout << "Reset device ..." << endl;
    return clearBuffers(err);
};

//TODO: update for flash
int BaseSerial::invokeBsl(int *err) {
    int r = 0;
    r = setRST(err);
    if(r == -1) return -1;
    r = setTEST(err);
    if(r == -1) return -1;
    serial_delay(switchdelay);
    r = clrRST(err);
    if(r == -1) return -1;
    r = setTEST(err);
    if(r == -1) return -1;
    r = clrTEST(err);
    if(r == -1) return -1;
    r = setTEST(err);
    if(r == -1) return -1;
    r = clrTEST(err);
    if(r == -1) return -1;
    r = setRST(err);
    if(r == -1) return -1;
    r = setTEST(err);
    if(r == -1) return -1;
    serial_delay(switchdelay);
    cout << "Invoking BSL..." << endl;
    return clearBuffers(err);
}

int BaseSerial::readFD(int *err, char *buffer, int count, int maxCount) {
    int cnt = 0;
    int retries = 0;
    timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    while(cnt == 0) {
        int tmpCnt = read(serialReadFD, buffer, maxCount);
        *err = errno;
        if((tmpCnt == 0) || ((tmpCnt < 0) && (errno == EAGAIN))) {
            FD_SET(serialReadFD, &rfds);
            if(select(serialReadFD + 1, &rfds, NULL, NULL, &tv) < 0) {
                *err = errno;
                return -1;
            }
            FD_CLR(serialReadFD, &rfds);
            if(retries++ >= 2) {
                cerr << "FATAL: BaseSerial::readFD no data available after 1s" << endl;
                return -1;
            }
        }
        else if(tmpCnt > 0) {
            cnt += tmpCnt;
        }
        else {
            return -1;
        }
    }
    return cnt;
}

int BaseSerial::txrx(int *err, bool responseExpected, frame_t *txframe, frame_t *rxframe) {
    int r = 0;
    char sync = SYNC;
    uint8_t ack = 0;
    if((txframe == NULL) || (txframe->NL + (txframe->NH << 8)) == 0 || (rxframe == NULL)) {
        cerr << "BaseSerial::txrx: precondition not fulfilled, "
             << " txFrame: " << txframe
             << " rxFrame: " << rxframe
             << " txframe->NH: " << (unsigned) txframe->NH 
             << " txframe->NL: " << (unsigned) txframe->NL 
             << endl;
        return -1;
    }
    //checksum/transmit frame
    checksum(txframe);    
    //length is the value of NH NL, plus 2 bytes for NH NL plus 2
    //  bytes for crc
    txframe->SYNC = SYNC;
    r = write(serialWriteFD, (char *)txframe, ((txframe->NH << 8) + txframe->NL) + 4);
    if(r < ((txframe->NH << 8) + txframe->NL) + 4) {
        *err = errno;
        return -1;
    }
    //read single byte to check ack
    r = readFD(err, (char*)&ack, 1, 1);
    if (ack == DATA_ACK){
      //if we expect to get more than an ack, read back the sync +
      //length, then the data
      if(responseExpected){
        r = readFD(err, (char*)rxframe, 3, 3);
        int len = ((rxframe -> NH << 8) + rxframe -> NL);
        //TODO: check r
        r = readFD(err, (char*)(&rxframe->data), len, sizeof(rxframe) - 3);
        //TODO: verify checksum
      } else {
        return r;
      }
    } else {
      //TODO: proper error handling
    }
    return r;
}

int BaseSerial::highSpeed(int *err) {
    int r;
    //TODO: update defs for 115200 speed
#if defined(HAVE_LINUX_VERSION_H) && (LINUX_VERSION_CODE < KERNEL_VERSION(2,6,24))
    struct serial_struct serinfo;
    r = ioctl(serialWriteFD, TIOCGSERIAL, &serinfo);
    if(r == -1) {
        *err = errno;
        return -1;
    }
    serinfo.custom_divisor = serinfo.baud_base / 38400;
    if(serinfo.custom_divisor == 0) serinfo.custom_divisor = 1;
    serinfo.flags &= ~ASYNC_SPD_MASK;
    serinfo.flags |= ASYNC_SPD_CUST;
    r = ioctl(serialWriteFD, TIOCSSERIAL, &serinfo);
#else
    struct termios my_tios;
    r = tcgetattr(serialWriteFD, &my_tios);
    cfsetispeed(&my_tios, B38400); 
    cfsetospeed(&my_tios, B38400);
    r = tcsetattr(serialReadFD, TCSANOW, &my_tios);
    if(r == -1) {
        *err = errno;
    }
    else {
        r = tcsetattr(serialWriteFD, TCSANOW, &my_tios);
    }
#endif    
    if(r == -1) {
        *err = errno;
        return -1;
    }
    return r;
}