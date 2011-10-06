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
 * @author Marcus Chang <marcus.chang@cs.jhu.edu>
 * @author Doug Carlson <carlson@cs.jhu.edu>
 * @version $Revision$ $Date$
 */

#include <I2C.h>

generic module Msp430UsciI2CMasterP(uint8_t TXIE_MASK, uint8_t RXIE_MASK, uint8_t TXIFG_MASK, uint8_t RXIFG_MASK) {
  
  provides interface ResourceConfigure[ uint8_t client ];
  provides interface I2CPacket<TI2CBasicAddr> as I2CBasicAddr[uint8_t client];
  provides interface I2CSlave[uint8_t client];
  provides interface Msp430UsciError[uint8_t client];
  
  uses interface HplMsp430UsciInterrupts as StateInterrupts;
  uses interface HplMsp430UsciInterrupts as RXInterrupts;
  uses interface HplMsp430UsciInterrupts as TXInterrupts;

  uses interface HplMsp430GeneralIO as SDA;
  uses interface HplMsp430GeneralIO as SCL;

  uses interface HplMsp430Usci as Usci;
  uses interface HplMsp430UsciB as UsciB;
  uses interface Msp430UsciConfigure[ uint8_t client ];
  uses interface ArbiterInfo;
  uses interface LocalTime<TMilli> as LocalTime_bms;

}

implementation {
  
  enum {
    TIMEOUT = 64,
  };
  
  norace uint8_t* m_buf;
  norace uint8_t m_len;
  norace uint8_t m_pos;
  norace i2c_flags_t m_flags;
  //TODO: this maybe should be just part of config?
  norace uint16_t m_ownaddress = 0x0000;
  
  void nextRead();
  void nextWrite();
  void signalDone( error_t error );

  void pdbg(uint8_t v){
    atomic{
      P6OUT = 0x00;
      P6OUT = v;
    }
  }

  error_t configure_(const msp430_usci_config_t* config){
    if(! config){
      return FAIL;
    }
    //basic config (leave in reset)
    call Usci.configure(config, TRUE);

    //direction is don't-care in datasheet
    call SCL.selectModuleFunc();
    call SDA.selectModuleFunc();

    //i2c-specific config
    call UsciB.setI2coa(config->i2coa);
    call Usci.leaveResetMode_();

    //No interrupts enabled when in master mode/idle
    return SUCCESS;
  }

  error_t unconfigure_(){
    //TODO: wait until idle
    //TODO: disable interrupts
    //TODO: enter reset
    //TODO: switch pins to gpio
    return FAIL;
  }

  async command void ResourceConfigure.configure[ uint8_t client ]() {
    configure_(call Msp430UsciConfigure.getConfiguration[client]());
  }
  
  async command void ResourceConfigure.unconfigure[ uint8_t client ]() {
    unconfigure_();
  }
  
  /*************************************************************************/
  async command error_t I2CBasicAddr.read[uint8_t client]( i2c_flags_t flags,
					   uint16_t addr, uint8_t len, 
					   uint8_t* buf ) 
  {
    uint8_t counter = 0xFF;
    uint8_t garbage;
    if ( call Usci.getStat() & UCBBUSY ){
      return EBUSY;
    }
    m_buf = buf;
    m_len = len;
    m_flags = flags;
    m_pos = 0;


    /* check if this is a new connection or a continuation */
    if (m_flags & I2C_START) {
      //reading from the RXBUF will clear out any junk left at the end
      //of the last read. This issue stems from the fact that the stop
      //condition is generated after we received the last byte in the
      //previous read (slave might supply another byte before it gets
      //the stop condition, which might still be kicking around the
      //RXBUF)
      garbage = call Usci.getRxbuf();
      // set slave address 
      call UsciB.setI2csa(addr);
      //clear TR bit, set start condition
      call Usci.setCtl1( (call Usci.getCtl1()&(~UCTR))  | UCTXSTT);


      //enable i2c arbitration interrupts, rx 
      call UsciB.setI2cie((call UsciB.getI2cie() & 0xf0) | UCNACKIE | UCALIE);
      call Usci.setIe( call Usci.getIe() | RXIE_MASK );

      /* if only reading 1 byte, STOP bit must be set right after
       * START condition is triggered */
      if ( (m_len == 1) && (m_flags & I2C_STOP) )
      {
        //this logic seems to work fine
        /* wait until START bit has been transmitted */
        while ((call Usci.getCtl1() & UCTXSTT) && (counter > 0x01)){
          counter--;
        }
        /* set stop bit */
        //UCB0CTL1 |= UCTXSTP;
        call Usci.setCtl1(call Usci.getCtl1() | UCTXSTP);
      }
    } else if (m_flags & I2C_RESTART) {
      //TODO: test
      /* set slave address */
      //UCB0I2CSA = addr;
      call UsciB.setI2csa(addr);

      /* UCTXSTT - generate START condition */
      //UCB0CTL1 |= UCTXSTT;
      call Usci.setCtl1(call Usci.getCtl1() | UCTXSTT);

      /* if only reading 1 byte, STOP bit must be set right after START bit */
      if ( (m_len == 1) && (m_flags & I2C_STOP) ) {
        /* wait until START bit has been transmitted */
        while ((call Usci.getCtl1() & UCTXSTT) && (counter > 0x01)){
          counter--;
        }
        /* set stop bit */
        //UCB0CTL1 |= UCTXSTP;
        call Usci.setCtl1(call Usci.getCtl1() | UCTXSTP);
      }
    } else {
      //TODO: test
      nextRead();
    }
    if (counter > 0x01){
      return SUCCESS;    
    } else {
      return FAIL;
    }
  }

  void nextRead()
  {
    uint16_t counter = 0xFFFF;
    //TODO: replace with module-independent calls
    //debug: show position, then byte received
    /* read byte from RX buffer */

    if ((m_pos == (m_len - 2)) && m_len > 1)
    {
      //we want to send NACK + STOP in response to the last byte.
      //if m_pos == m_len-2 and we get the RX interrupt, that means
      //  that the slave has already written the next-to-last byte
      //  and we have acknowledged it--BUT we have not yet read it.
      //By setting the stop condition here, we say "send STOP after
      //the next byte," which will actually be the last byte.
      //
      //it is more intuitive to say "read the next-to-last byte and
      //set the STOP condition real quick before the last byte gets
      //sent so that we can NACK+STOP it". Maybe this would work if
      //you slowed down the I2C clock enough?
      call Usci.setCtl1(call Usci.getCtl1() | UCTXSTP);
    }
    m_buf[ m_pos++ ] = call Usci.getRxbuf();

    //TODO: this should check m_flags: if RESTART flag is present
    if (m_pos == m_len){

      //when we receive the last byte, wait until STP condition is
      //cleared, then return.
      while( (call Usci.getCtl1() & UCTXSTP) && (counter > 0x01)){
        counter --;
      }
      //disable the rx interrupt 
      call Usci.setIe(call Usci.getIe() & ~RXIE_MASK);
      if (counter > 0x01){
        signal I2CBasicAddr.readDone[call ArbiterInfo.userId()]( SUCCESS, call UsciB.getI2csa(), m_pos, m_buf );
      } else {
        signal I2CBasicAddr.readDone[call ArbiterInfo.userId()]( FAIL, call UsciB.getI2csa() , m_pos, m_buf );
      }
    }
  }
  
  void showRegisters(){
    atomic{
      P6OUT = 0x00;
      P6OUT = 0xff;
      P6OUT = UCB0CTL0;
      P6OUT = 0xff;
      P6OUT = UCB0CTL1;
      P6OUT = 0xff;
      P6OUT = UCB0BR0;
      P6OUT = 0xff;
      P6OUT = UCB0BR1;
      P6OUT = 0xff;
      P6OUT = UCB0I2CIE;
      P6OUT = 0xff;
      P6OUT = UCB0STAT;
      P6OUT = 0xff;
      P6OUT = UCB0I2COA;
      P6OUT = 0xff;
      P6OUT = UCB0I2CSA;
      P6OUT = 0xff;
      P6OUT = IE2;
      P6OUT = 0xff;
      P6OUT = 0x00;
    }
  }

  async command error_t I2CBasicAddr.write[uint8_t client]( i2c_flags_t flags,
					    uint16_t addr, uint8_t len,
					    uint8_t* buf ) {

    if ( call Usci.getStat() & UCBBUSY )
      return EBUSY;
      
    m_buf = buf;
    m_len = len;
    m_flags = flags;
    m_pos = 0;

    /* check if this is a new connection or a continuation */
    if (m_flags & I2C_START)
    {
      //sequence as described in 17.3.4.2.1 of slau144h is:
      // - set sa
      // - set UCTR
      // - set UCTXSTT
      // (start/address written, then we get an interrupt)
      // no reset should be necessary for this process. however, when
      // I did it in a different sequence, the first write worked OK
      // but the second one began with the UCSTPIFG set, and the first
      // character was dropped. I have no explanation for why this
      // would be the case.

      // set slave address 
      call UsciB.setI2csa(addr);
      // UCTXSTT - generate START condition 
      call Usci.setCtl1(call Usci.getCtl1() | UCTR | UCTXSTT);
      //enable relevant state interrupts
      call UsciB.setI2cie((call UsciB.getI2cie() & 0xf0) | UCNACKIE | UCALIE);
      //enable tx interrupts 
      call Usci.setIe( call Usci.getIe() | TXIE_MASK);
    } 
    /* is this a restart or a direct continuation */
    else if (m_flags & I2C_RESTART)
    {
      // set slave address 
      call UsciB.setI2csa(addr);

      /* UCTR - set transmit */
      /* UCTXSTT - generate START condition */
      call Usci.setCtl1(call Usci.getCtl1() | UCTR | UCTXSTT);
      //do we not need to enable any interrupts here?
    }
    else{
      // continue writing next byte 
      nextWrite();
    }
    return SUCCESS;    
  }


  void nextWrite()
  {
    uint16_t counter = 0xFFFF;
    /* all bytes sent */
    if ( m_pos == m_len ) {
      /* not setting STOP bit allows restarting transfer */
      if ( m_flags & I2C_STOP )
      {
        /* set stop bit */
        call Usci.setCtl1(call Usci.getCtl1() | UCTXSTP);

        /* wait until STOP bit has been transmitted */
        while ((call Usci.getCtl1() & UCTXSTP) && (counter > 0x01)){
          counter--;
        }
        //TODO: when write is done, should we put module back into
        //  reset?  I think not, the application should release the
        //  resource and then it will deconfigure when it's not in
        //  use.
      }

      //disable tx interrupt, we're DONE 
      //TODO: other interrupts?
      call Usci.setIe(call Usci.getIe() & ~TXIE_MASK );
      /* fail gracefully */      
      if (counter > 0x01){
        signal I2CBasicAddr.writeDone[call ArbiterInfo.userId()]( SUCCESS, call UsciB.getI2csa(), m_len, m_buf );
      } else{
        signal I2CBasicAddr.writeDone[call ArbiterInfo.userId()]( FAIL, call UsciB.getI2csa(), m_len, m_buf );
      }
    } else{
      //send the next char
    //It appears that this is happening during the slave read, which
    //it shouldn't
      call Usci.setTxbuf(m_buf[ m_pos++ ]);
    }
  }

  /***************************************************************************/

  async event void TXInterrupts.interrupted(uint8_t iv) 
  {
    //TODO: check for current client/ownership
    //TODO: no need to check master mode
    /* if master mode */
    if (call Usci.getCtl0() & UCMST){
      nextWrite();
    } else {
      //TODO: move to slave code
      //UCB0TXBUF = signal I2CBasicAddr.slaveTransmit();
    }
  }
  
  async event void RXInterrupts.interrupted(uint8_t iv) 
  {
    uint16_t nackTimeout = 0xffff;
    pdbg(4);
    //TODO: check for current client/ownership
    /* if master mode */
    if (call Usci.getCtl0() & UCMST){
      nextRead();
    } else {
      pdbg(5);
      if( SUCCESS != signal I2CSlave.slaveReceive[call ArbiterInfo.userId()](call Usci.getRxbuf())){
        pdbg(6);
        //How to deal with this? set NACK? Is it not too late to send
        //NACK if we just read from the buffer?
        call Usci.setCtl1(call Usci.getCtl1()|UCTXNACK);
        while ( nackTimeout > 1 && (call Usci.getCtl1() & UCTXNACK)){
          pdbg(7);
          nackTimeout --;
          //wait until NACK is sent
        }
        pdbg(8);
        //should maybe signal to indicate whether the nack made it or
        //not.
        //TODO: reset?
        signal I2CSlave.slaveStop[call ArbiterInfo.userId()]();
      } else {
        pdbg(9);
      }
    }
  }
  
  async event void StateInterrupts.interrupted(uint8_t iv) 
  {
    uint8_t counter = 0xFF;
    if (call Usci.getCtl0() & UCMST){
      //TODO: check for current client/ownership
      //TODO: replace with module-independent calls
      /* no acknowledgement */
      if (call Usci.getStat() & UCNACKIFG) {
        //This occurs during write and read when no ack is received.
        /* set stop bit */
        call Usci.setCtl1(call Usci.getCtl1() | UCTXSTP);
  
        /* wait until STOP bit has been transmitted */
        while ((call Usci.getCtl1() & UCTXSTP) && (counter > 0x01)){
          counter--;
        }
        call Usci.enterResetMode_();
        call Usci.leaveResetMode_();
  
        //signal appropriate event depending on whether we were
        //transmitting or receiving
        //Note that TR will be cleared if we lost MM arbitration because
        //another master addressed us as a slave. However, this should
        //manifest as an AL interrupt, not a NACK interrupt.
        if (call Usci.getCtl1() & UCTR){
          signal I2CBasicAddr.writeDone[call ArbiterInfo.userId()]( ENOACK, call UsciB.getI2csa(), m_len, m_buf );
        }else {
          signal I2CBasicAddr.readDone[call ArbiterInfo.userId()]( ENOACK, call UsciB.getI2csa(), m_len, m_buf );
        }
      } 
    } else {
      //slave-specific
      /* arbitration lost (we USED TO be master)*/
      if (UCB0STAT & UCALIFG) 
      {
        call Usci.enterResetMode_();
        call Usci.leaveResetMode_();
        signal I2CBasicAddr.writeDone[call ArbiterInfo.userId()]( EBUSY, UCB0I2CSA, m_len, m_buf );
      }

      /* STOP condition */
      else if (UCB0STAT & UCSTPIFG) 
      {
        /* disable STOP interrupt, enable START interrupt */
        //UCB0I2CIE &= ~UCSTPIE;
        //UCB0I2CIE |= UCSTTIE;
        call UsciB.setI2cie((call UsciB.getI2cie() | UCSTTIE) & ~UCSTPIE);
        signal I2CSlave.slaveStop[call ArbiterInfo.userId()]();
      }
      /* START condition */
      else if (UCB0STAT & UCSTTIFG) 
      {
        /* disable START interrupt, enable STOP interrupt */
//        UCB0I2CIE &= ~UCSTTIE;
//        UCB0I2CIE |= UCSTPIE;
        call UsciB.setI2cie((call UsciB.getI2cie() | UCSTPIE) & ~UCSTTIE);
        signal I2CSlave.slaveStart[call ArbiterInfo.userId()]();
      }
    }
  }

  //defaults
  default async event void I2CBasicAddr.readDone[uint8_t client](error_t error, uint16_t addr, uint8_t length, uint8_t* data){}
  default async event void I2CBasicAddr.writeDone[uint8_t client](error_t error, uint16_t addr, uint8_t length, uint8_t* data){}
  default async command const msp430_usci_config_t* Msp430UsciConfigure.getConfiguration[uint8_t client](){
    //TODO: sensible default!!!
    return NULL;
  }

/***** Slave-mode functions ***/
  //part of config?
  command error_t I2CSlave.setOwnAddress[uint8_t client](uint16_t addr)
  {
    m_ownaddress = addr;
    call UsciB.setI2coa(m_ownaddress);
    
    return SUCCESS;
  }

  command error_t I2CSlave.enableSlave[uint8_t client]()
  {
    pdbg(1);
    /**************************************************************/
    //UCB0CTL1 = UCSWRST; // enter reset mode
    call Usci.enterResetMode_();

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
    //UCB0CTL0 = UCMODE_I2C | UCSYNC;
    call Usci.setCtl0(call Usci.getCtl0() & ~UCMST);
    call Usci.leaveResetMode_();

//    call SDA.makeOutput();
//    call SDA.selectModuleFunc();
//    call SCL.makeOutput();
//    call SCL.selectModuleFunc();
    
//    UCB0CTL1 &= ~UCSWRST; // exit reset mode

//    UCB0I2CIE = UCSTTIE;
//    IE2 |= UCB0RXIE | UCB0TXIE;
    call UsciB.setI2cie(call UsciB.getI2cie() | UCSTTIE);
    call Usci.setIe(call Usci.getIe() | RXIE_MASK | TXIE_MASK);
    pdbg(2);

    /**************************************************************/
    if (m_ownaddress == 0x0000){
      pdbg(3);
      //if we haven't set an address, then try to get it from the
      //configuration.
      m_ownaddress = (call Msp430UsciConfigure.getConfiguration[client]())-> i2coa;
      call UsciB.setI2coa(m_ownaddress);
      //showRegisters();
      return SUCCESS;
    }
    else{
      return FAIL;
    }
  }


  command error_t I2CSlave.disableSlave[uint8_t client]()
  {
    //TODO: check ownership
    call Usci.enterResetMode_();
    //go back to being a master
    call Usci.setCtl0(call Usci.getCtl0() | UCMST);
    call Usci.leaveResetMode_();
    //resetUCB0();
    return SUCCESS;
  }
  

  default async event error_t I2CSlave.slaveReceive[uint8_t client](uint8_t data) { return FAIL; }
  default async event uint8_t I2CSlave.slaveTransmit[uint8_t client]() { return 0x00; }

  default async event void I2CSlave.slaveStart[uint8_t client]() { ; }
  default async event void I2CSlave.slaveStop[uint8_t client]() { ; }


}
