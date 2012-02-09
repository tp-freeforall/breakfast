/* Copyright (c) 2010 People Power Co.
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

/** Structures and definitions relevant to configuring an RF1A radio
 * for specific encoding, frequency, etc.
 * 
 * @author Peter A. Bigot <pab@peoplepowerco.com> */

#ifndef _Rf1aConfigure_h_
#define _Rf1aConfigure_h_

/** Configuration for an RF1A radio.  There must be a one-to-one
 * correspondence between the offsets of the tags in this structure
 * and the address of the corresponding register, since configuration
 * involves walking this structure and storing fields.  Certain tags
 * (those marked as RESERVED or NOWRITE) are skipped during the write
 * process). */
typedef struct rf1a_config_t {
  uint8_t iocfg2;             /* 0x00 IOCFG2   - GDO2 output pin configuration  */
  uint8_t iocfg1;             /* 0x01 IOCFG1   - GDO1 output pin configuration  */
  uint8_t iocfg0;             /* 0x02 IOCFG0   - GDO0 output pin configuration  */
  uint8_t fifothr;            /* 0x03 FIFOTHR  - RX FIFO and TX FIFO thresholds */
  uint8_t sync1;              /* 0x04 SYNC1    - Sync word, high byte */
  uint8_t sync0;              /* 0x05 SYNC0    - Sync word, low byte */
  uint8_t pktlen;             /* 0x06 PKTLEN   - Packet length */
  uint8_t pktctrl1;           /* 0x07 PKTCTRL1 - Packet automation control */
  uint8_t pktctrl0;           /* 0x08 PKTCTRL0 - Packet automation control */
  uint8_t addr;               /* 0x09 ADDR     - Device address */
  uint8_t channr;             /* 0x0A CHANNR   - Channel number */
  uint8_t fsctrl1;            /* 0x0B FSCTRL1  - Frequency synthesizer control */
  uint8_t fsctrl0;            /* 0x0C FSCTRL0  - Frequency synthesizer control */
  uint8_t freq2;              /* 0x0D FREQ2    - Frequency control word, high byte */
  uint8_t freq1;              /* 0x0E FREQ1    - Frequency control word, middle byte */
  uint8_t freq0;              /* 0x0F FREQ0    - Frequency control word, low byte */
  uint8_t mdmcfg4;            /* 0x10 MDMCFG4  - Modem configuration */
  uint8_t mdmcfg3;            /* 0x11 MDMCFG3  - Modem configuration */
  uint8_t mdmcfg2;            /* 0x12 MDMCFG2  - Modem configuration */
  uint8_t mdmcfg1;            /* 0x13 MDMCFG1  - Modem configuration */
  uint8_t mdmcfg0;            /* 0x14 MDMCFG0  - Modem configuration */
  uint8_t deviatn;            /* 0x15 DEVIATN  - Modem deviation setting */
  uint8_t mcsm2;              /* 0x16 MCSM2    - Main Radio Control State Machine configuration */
  uint8_t mcsm1;              /* 0x17 MCSM1    - Main Radio Control State Machine configuration */
  uint8_t mcsm0;              /* 0x18 MCSM0    - Main Radio Control State Machine configuration */
  uint8_t foccfg;             /* 0x19 FOCCFG   - Frequency Offset Compensation configuration */
  uint8_t bscfg;              /* 0x1A BSCFG    - Bit Synchronization configuration */
  uint8_t agcctrl2;           /* 0x1B AGCCTRL2 - AGC control */
  uint8_t agcctrl1;           /* 0x1C AGCCTRL1 - AGC control */
  uint8_t agcctrl0;           /* 0x1D AGCCTRL0 - AGC control */
  uint8_t worevt1;            /* 0x1E WOREVT1  - High byte Event0 timeout */
  uint8_t worevt0;            /* 0x1F WOREVT0  - Low byte Event0 timeout */
  uint8_t worctrl;            /* 0x20 WORCTRL  - Wake On Radio control */
  uint8_t frend1;             /* 0x21 FREND1   - Front end RX configuration */
  uint8_t frend0;             /* 0x22 FREND0   - Front end TX configuration */
  uint8_t fscal3;             /* 0x23 FSCAL3   - Frequency synthesizer calibration */
  uint8_t fscal2;             /* 0x24 FSCAL2   - Frequency synthesizer calibration */
  uint8_t fscal1;             /* 0x25 FSCAL1   - Frequency synthesizer calibration */
  uint8_t fscal0;             /* 0x26 FSCAL0   - Frequency synthesizer calibration */
  uint8_t _rcctrl1;           /* RESERVED 0x27 RCCTRL1  - RC oscillator configuration */
  uint8_t _rcctrl0;           /* RESERVED 0x28 RCCTRL0  - RC oscillator configuration */
  uint8_t fstest;             /* NOWRITE 0x29 FSTEST   - Frequency synthesizer calibration control */
  uint8_t ptest;              /* NOWRITE 0x2A PTEST    - Production test */
  uint8_t agctest;            /* NOWRITE 0x2B AGCTEST  - AGC test */
  uint8_t test2;              /* 0x2C TEST2    - Various test settings */
  uint8_t test1;              /* 0x2D TEST1    - Various test settings */
  uint8_t test0;              /* 0x2E TEST0    - Various test settings */
  /* PATABLE is written separately */
  uint8_t patable[8];         /* 0x3E PATABLE  - Output power level (first entry only) */
  /* Status values provided only by Rf1aPhysical.readConfiguration,
   * never written.  It's not clear which of these are useful; the
   * ones I currently think aren't work the ROM are left disabled for
   * now. */
  uint8_t partnum;            /* 0x30 PARTNUM  - Part number */
  uint8_t version;            /* 0x31 VERSION  - Current version number */
#if 0
  uint8_t freqest;            /* 0x32 FREQEST  - Frequency offset estimate */
  uint8_t lqi;                /* 0x33 LQI      - Demodulator eestimate for link quality */
  uint8_t rssi;               /* 0x34 RSSI     - Received signal strength indication */
  uint8_t marcstate;          /* 0x35 MARCSTATE - Control state machine state */
  uint8_t wortime1;           /* 0x36 WORTIME1  - High byte of WOR timer */
  uint8_t wortime0;           /* 0x37 WORTIME0  - Low byte of WOR timer */
  uint8_t pktstatus;          /* 0x38 PKTSTATUS - Current GDOx status and packet status */
  uint8_t vco_vc_dac;         /* 0x39 VCO_VC_DAC - Current setting from PLL calibration module */
#endif
} rf1a_config_t;
 
/** Most of the rf1a_config_t structure can be accessed via a burst
 * register access starting at address zero.  A burst write should
 * consist of this many bytes.  The subsequent fields of the structure
 * should either be ignored (as they are for testing) or written
 * stored piece-wise (e.g., patable0).
 *
 * @note It is recommended that PATABLE0 be written first, so the
 * subsequent write instruction resets the internal table index
 * register. */
#define RF1A_CONFIG_BURST_WRITE_LENGTH (1+FSCAL0)

/** Most of the rf1a_config_t structure can be accessed via a burst
 * register access starting at address zero.  A burst read should
 * consist of this many bytes.  The subsequent fields of the structure
 * must be read piece-wise (e.g., patable).
 *
 * @note It is recommended that PATABLE0 be written first, so the
 * subsequent write instruction resets the internal table index
 * register. */
#define RF1A_CONFIG_BURST_READ_LENGTH (1+TEST0)

//A default version of this file is provided, platforms should provide
//their own for cases where they wish to use specific settings (e.g.
//to match their antenna)
#include "PlatformRf1aConfigure.h"


#endif //  _Rf1aConfigure_h_
