/*
 * Copyright (c) 2005-2006 Arch Rock Corporation
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
 * - Neither the name of the Arch Rock Corporation nor the names of
 *   its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * ARCHED ROCK OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE
 */

/**
 * @author Jonathan Hui <jhui@archrock.com>
 * @version $Revision$ $Date$
 */

#include <I2C.h>

module Msp430I2CP {
  
  provides interface Resource[ uint8_t id ];
  provides interface ResourceConfigure[ uint8_t id ];
  provides interface I2CPacket<TI2CBasicAddr> as I2CBasicAddr;
  
  uses interface HplMsp430UsciInterrupts as InterruptsState;
  uses interface HplMsp430UsciInterrupts as InterruptsRx;
  uses interface HplMsp430UsciInterrupts as InterruptsTx;

  uses interface HplMsp430GeneralIO as SDA;
  uses interface HplMsp430GeneralIO as SCL;

//  uses interface Resource as UsciResource[ uint8_t id ];
//  uses interface Msp430UsciConfigure[ uint8_t id ];
//  uses interface HplMsp430I2C as HplI2C;
//  uses interface HplMsp430UsciInterrupts as InterruptsRx[ uint8_t mode ];
//  uses interface HplMsp430UsciInterrupts as InterruptsTx[ uint8_t mode ];
//  uses interface Leds;
  
}

implementation {
  
  MSP430REG_NORACE(IE2);

  norace volatile unsigned char UCB0CTL0 __asm ("0x0068");
  norace volatile unsigned char UCB0CTL1 __asm ("0x0069");
  norace volatile unsigned char UCB0BR0 __asm ("0x006A");
  norace volatile unsigned char UCB0BR1 __asm ("0x006B");
  norace volatile unsigned char UCB0TXBUF __asm ("0x006F");
  norace volatile unsigned char UCB0I2COA __asm ("0x0118");
  norace volatile unsigned char UCB0I2CSA __asm ("0x011A");

  norace volatile unsigned char UCB0I2CIE __asm ("0x006C");
  
  enum {
    TIMEOUT = 64,
  };
  
  norace uint8_t* m_buf;
  norace uint8_t m_len;
  norace uint8_t m_pos;
  norace i2c_flags_t m_flags;
  norace uint16_t m_ownaddress = 0x0000;
  
  void resetUCB0();
  void nextRead();
  void nextWrite();
  void signalDone( error_t error );
  
  async command error_t Resource.immediateRequest[ uint8_t id ]() {
//    return call UsciResource.immediateRequest[ id ]();
    return SUCCESS;
  }
  
  async command error_t Resource.request[ uint8_t id ]() {
//    return call UsciResource.request[ id ]();
    return SUCCESS;
  }
  
  async command uint8_t Resource.isOwner[ uint8_t id ]() {
//    return call UsciResource.isOwner[ id ]();
    return SUCCESS;
  }
  
  async command error_t Resource.release[ uint8_t id ]() {
//    return call UsciResource.release[ id ]();
    return SUCCESS;
  }
  
  async command void ResourceConfigure.configure[ uint8_t id ]() {
//    call HplI2C.setModeI2C(call Msp430UsciConfigure.getConfiguration[id]());
  }
  
  async command void ResourceConfigure.unconfigure[ uint8_t id ]() {
//    call HplI2C.clearModeI2C();
  }
  
//  event void UsciResource.granted[ uint8_t id ]() {
//    signal Resource.granted[ id ]();
//  }
  
//  default async command error_t UsciResource.request[ uint8_t id ]() { return FAIL; }
//  default async command error_t UsciResource.immediateRequest[ uint8_t id ]() { return FAIL; }
//  default async command error_t UsciResource.release[ uint8_t id ]() {return FAIL;}
  default event void Resource.granted[ uint8_t id ]() {}
//  default async command const msp430_usci_config_t* Msp430UsciConfigure.getConfiguration[uint8_t id]() {
//    return &msp430_usci_i2c_default_config;
//  }
  

  /*************************************************************************/
  /*************************************************************************/
  /*************************************************************************/
  /*************************************************************************/
  command error_t I2CBasicAddr.setOwnAddress(uint16_t addr)
  {
    m_ownaddress = addr;
    
    return SUCCESS;
  }

  command error_t I2CBasicAddr.enableSlave()
  {
    /**************************************************************/
    UCB0CTL1 = UCSWRST; // enter reset mode

    /*
     * UCB0CTL0
     * UCSLA10    - 10bit slave address (~7bit slave address)
     * UCMM       - MultiMaster mode (~single master mode)
     * UCMST      - Master (~slave)
     * UCMODE_I2C - I2C mode
     * UCSYNC     - I2C mode
     *
     * UCSSEL_SMCLK - SMCLK clock source
     * UCTR         - transmit (~receive)
     *
     */
    UCB0CTL0 = UCMODE_I2C | UCSYNC;

    call SDA.makeOutput();
    call SDA.selectModuleFunc();
    call SCL.makeOutput();
    call SCL.selectModuleFunc();

    UCB0CTL1 &= ~UCSWRST; // exit reset mode

    UCB0I2CIE = UCSTTIE;
    IE2 |= UCB0RXIE | UCB0TXIE;

    /**************************************************************/

    if (m_ownaddress != 0x0000)
    {
      /* set own address */
      UCB0I2COA = m_ownaddress;

      return SUCCESS;
    }
    else
      return FAIL;
  }


  command error_t I2CBasicAddr.disableSlave()
  {
    resetUCB0();

    return SUCCESS;
  }
  

  default async event error_t I2CBasicAddr.slaveReceive(uint8_t data) { return FAIL; }
  default async event uint8_t I2CBasicAddr.slaveTransmit() { return 0x00; }

  default async event void I2CBasicAddr.slaveStart() { ; }
  default async event void I2CBasicAddr.slaveStop() { ; }
  /*************************************************************************/
  /*************************************************************************/
  /*************************************************************************/
  /*************************************************************************/
  async command error_t I2CBasicAddr.read( i2c_flags_t flags,
					   uint16_t addr, uint8_t len, 
					   uint8_t* buf ) 
  {
    uint8_t counter = 0xFF;

    if ( UCB0STAT & UCBBUSY )
      return EBUSY;

    
    m_buf = buf;
    m_len = len;
    m_flags = flags;
    m_pos = 0;


    /* check if this is a new connection or a continuation */
    if (m_flags & I2C_START)
    {
      /**************************************************************/
      UCB0CTL1 = UCSWRST; // enter reset mode

      /*
       * UCB0CTL0
       * UCSLA10    - 10bit slave address (~7bit slave address)
       * UCMM       - MultiMaster mode (~single master mode)
       * UCMST      - Master (~slave)
       * UCMODE_I2C - I2C mode
       * UCSYNC     - I2C mode
       *
       * UCSSEL_SMCLK - SMCLK clock source
       * UCTR         - transmit (~receive)
       *
       */
      UCB0CTL0 = UCMM | UCMST | UCMODE_I2C | UCSYNC;
      UCB0CTL1 = UCSSEL_SMCLK | UCSWRST;

      /* clock prescaler, minimum value is 8 */
      UCB0BR0 = 0x28; // 100 kHz
  //    UCB0BR0 = 0x0A; // 400 kHz
      UCB0BR1 = 0x00;

      call SDA.makeOutput();
      call SDA.selectModuleFunc();
      call SCL.makeOutput();
      call SCL.selectModuleFunc();

      UCB0CTL1 &= ~UCSWRST; // exit reset mode

      UCB0I2CIE = UCNACKIE | UCALIE;
      IE2 |= UCB0RXIE | UCB0TXIE;

      /**************************************************************/

      /* set own address - necessary in multi-master mode */
      UCB0I2COA = m_ownaddress;

      /* set slave address */
      UCB0I2CSA = addr;

      /* UCTXSTT - generate START condition */
      UCB0CTL1 |= UCTXSTT;

      /* if only reading 1 byte, STOP bit must be set right after START bit */
      if ( (m_len == 1) && (m_flags & I2C_STOP) )
      {
        /* wait until START bit has been transmitted */
        while ((UCB0CTL1 & UCTXSTT) && (counter > 0x01))
          counter--;

        /* set stop bit */
        UCB0CTL1 |= UCTXSTP;
      }
    }
    else if (m_flags & I2C_RESTART)
    {
      /* set slave address */
      UCB0I2CSA = addr;

      /* UCTXSTT - generate START condition */
      UCB0CTL1 |= UCTXSTT;

      /* if only reading 1 byte, STOP bit must be set right after START bit */
      if ( (m_len == 1) && (m_flags & I2C_STOP) )
      {
        /* wait until START bit has been transmitted */
        while ((UCB0CTL1 & UCTXSTT) && (counter > 0x01))
          counter--;

        /* set stop bit */
        UCB0CTL1 |= UCTXSTP;
      }
    }
    else
      nextRead();

    if (counter > 0x01)
      return SUCCESS;    
    else
      return FAIL;
  }


  void nextRead()
  {
    uint8_t counter = 0xFF;
    
    /* read byte from RX buffer */
    m_buf[ m_pos++ ] = UCB0RXBUF;

    /* last byte received */    
    if ( m_pos == m_len ) {

      /* single byte exception, STOP bit sent during address transmission */
      if ( m_len > 1 ) {
        /* set STOP bit */
        UCB0CTL1 |= UCTXSTP;

        /* wait until STOP bit has been transmitted */
        while ((UCB0CTL1 & UCTXSTP) && (counter > 0x01))
          counter--;
      }
      
      resetUCB0();
      if (counter > 0x01)
        signal I2CBasicAddr.readDone( SUCCESS, UCB0I2CSA, m_len, m_buf );
      else
        signal I2CBasicAddr.readDone( FAIL, UCB0I2CSA, m_len, m_buf );
    }
  }
  
  /*************************************************************************/
  /*************************************************************************/
  /*************************************************************************/
  /*************************************************************************/
  async command error_t I2CBasicAddr.write( i2c_flags_t flags,
					    uint16_t addr, uint8_t len,
					    uint8_t* buf ) {

    if ( UCB0STAT & UCBBUSY )
      return EBUSY;
      
    m_buf = buf;
    m_len = len;
    m_flags = flags;
    m_pos = 0;

    /* check if this is a new connection or a continuation */
    if (m_flags & I2C_START)
    {
      /**************************************************************/
      UCB0CTL1 = UCSWRST; // enter reset mode

      /*
       * UCB0CTL0
       * UCSLA10    - 10bit slave address (~7bit slave address)
       * UCMM       - MultiMaster mode (~single master mode)
       * UCMST      - Master (~slave)
       * UCMODE_I2C - I2C mode
       * UCSYNC     - I2C mode
       *
       * UCSSEL_SMCLK - SMCLK clock source
       * UCTR         - transmit (~receive)
       *
       */
      UCB0CTL0 = UCMM | UCMST | UCMODE_I2C | UCSYNC;
      UCB0CTL1 = UCSSEL_SMCLK | UCSWRST;

      /* clock prescaler, minimum value is 8 */
      UCB0BR0 = 0x28; // 100 kHz
  //    UCB0BR0 = 0x0A; // 400 kHz
      UCB0BR1 = 0x00;

      call SDA.makeOutput();
      call SDA.selectModuleFunc();
      call SCL.makeOutput();
      call SCL.selectModuleFunc();

      UCB0CTL1 &= ~UCSWRST; // exit reset mode

      UCB0I2CIE = UCNACKIE | UCALIE;
      IE2 |= UCB0RXIE | UCB0TXIE;

      /**************************************************************/

      /* set own address - necessary in multi-master mode */
      UCB0I2COA = m_ownaddress;

      /* set slave address */
      UCB0I2CSA = addr;
     
      /* UCTXSTT - generate START condition */
      UCB0CTL1 |= UCTR | UCTXSTT;
    } 
    /* is this a restart or a direct continuation */
    else if (m_flags & I2C_RESTART)
    {
      /* set slave address */
      UCB0I2CSA = addr;

      /* UCTR - set transmit */
      /* UCTXSTT - generate START condition */
      UCB0CTL1 |= UCTR | UCTXSTT;
    }
    else
      /* contiune writing next byte */
      nextWrite();
    
    return SUCCESS;    
  }


  void nextWrite()
  {
    uint8_t counter = 0xFF;
    
    /* all bytes sent */
    if ( m_pos == m_len ) {

      /* not setting STOP bit allows restarting transfer */
      if ( m_flags & I2C_STOP )
      {
        /* set stop bit */
        UCB0CTL1 |= UCTXSTP;

        /* wait until STOP bit has been transmitted */
        while ((UCB0CTL1 & UCTXSTP) && (counter > 0x01))
          counter--;

        resetUCB0();
      }

      /* fail gracefully */      
      if (counter > 0x01)
        signal I2CBasicAddr.writeDone( SUCCESS, UCB0I2CSA, m_len, m_buf );
      else
        signal I2CBasicAddr.writeDone( FAIL, UCB0I2CSA, m_len, m_buf );
    }
    else
      UCB0TXBUF = m_buf[ m_pos++ ];
  }

  /***************************************************************************/  
  /***************************************************************************/
  /***************************************************************************/

  async event void InterruptsTx.interrupted(uint8_t iv) 
  {
    /* if master mode */
    if (UCB0CTL0 & UCMST)
      nextWrite();
    else
      UCB0TXBUF = signal I2CBasicAddr.slaveTransmit();
  }
  
  async event void InterruptsRx.interrupted(uint8_t iv) 
  {
    /* if master mode */
    if (UCB0CTL0 & UCMST)
      nextRead();
    else
    {
      if (signal I2CBasicAddr.slaveReceive(UCB0RXBUF) != SUCCESS)
        UCB0CTL1 |= UCTXNACK;
    }
  }
  
  async event void InterruptsState.interrupted(uint8_t iv) 
  {
    uint8_t counter = 0xFF;
    
    /* no acknowledgement */
    if (UCB0STAT & UCNACKIFG) 
    {
      /* set stop bit */
      UCB0CTL1 |= UCTXSTP;

      /* wait until STOP bit has been transmitted */
      while ((UCB0CTL1 & UCTXSTP) && (counter > 0x01))
        counter--;

      resetUCB0();
      signal I2CBasicAddr.writeDone( ENOACK, UCB0I2CSA, m_len, m_buf );
    } 
    /* arbitration lost */
    else if (UCB0STAT & UCALIFG) 
    {
      resetUCB0();
      signal I2CBasicAddr.writeDone( EBUSY, UCB0I2CSA, m_len, m_buf );
    }
    /* STOP condition */
    else if (UCB0STAT & UCSTPIFG) 
    {
      /* disable STOP interrupt, enable START interrupt */
      UCB0I2CIE &= ~UCSTPIE;
      UCB0I2CIE |= UCSTTIE;
      
      signal I2CBasicAddr.slaveStop();
    }
    /* START condition */
    else if (UCB0STAT & UCSTTIFG) 
    {
      /* disable START interrupt, enable STOP interrupt */
      UCB0I2CIE &= ~UCSTTIE;
      UCB0I2CIE |= UCSTPIE;

      signal I2CBasicAddr.slaveStart();
    }

  }

  void resetUCB0()
  {
    /* reset default values. 
     * I2C stops
     * SDL and SDA are high impedance
     * UCB0I2CSTAT, bits 0-6 are cleared
     * UCB0TXIE and UCB0RXIE are cleared
     * UCB0TXIFG and UCB0RXIFG are cleared
     */
    UCB0CTL1 = UCSWRST; // enter reset mode
/*
    UCB0CTL0 = UCSYNC;
    UCB0BR0 = 0x00; 
    UCB0BR1 = 0x00;
    UCB0CTL1 &= ~UCSWRST; // exit reset mode

    UCB0I2CIE = 0x00;
*/
  }  


}
