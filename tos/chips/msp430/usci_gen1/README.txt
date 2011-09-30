This directory contains the USCI implementation for the first
generation USCI module (from Peter Bigot/People Power's explanation):

@TODO@ There are at least three USCI implementations supported over the
MSP430 family.  The implementations are distinguished by the functional
presence preproprocessor macro as defined in the TI standard headers from
Code Composer Studio distribution:

*__MSP430_HAS_USCI__ -- indicates the original USCI implementation on chips:
     msp430x21x2 msp430x22x2 msp430x22x4 msp430x23x msp430x23x0 msp430x241x
     msp430x24x msp430x24x1 msp430x26x msp430x41x2 msp430x471x6 msp430x471x7
     msp430x47x msp430x47x3 msp430x47x4 msp430xG46x msp430xG47x

 __MSP430_HAS_USCI_AB0__ -- second generation USCI implementation on chips:
     msp430x241x msp430x24x msp430x24x1 msp430x26x msp430x471x6 msp430x471x7
     msp430x47x3 msp430x47x4 msp430x241x msp430x24x msp430x24x1 msp430x26x
     msp430x471x6 msp430x471x7 msp430x47x3 msp430x47x4

 __MSP430_HAS_USCI_A0__, __MSP430_HAS_USCI_B0__ -- third generation USCI
   implementation on chips:
     cc430x513x cc430x612x cc430x613x msp430x54x msp430x54xA msp430x551x
     msp430x552x

Some characteristics of note:

USCI A0/A1 offsets (UART/SPI)
=============================
Control registers
-----------------
-0x03 UCA0ABCTL  
-0x02 UCA0IRTCTL 
-0x01 UCAxIRRCTL
 0x00 UCAxCTL0
 0x01 UCAxCTL1
 0x02 UCAxBR0
 0x03 UCAxBR1
 0x04 UCAxMCTL
 0x05 UCAxSTAT
 0x06 UCAxRXBUF
 0x07 UCAxTXBUF

Interrupt Registers
-------------------
 0x00 IE  (A0: IE2,  A1: UC1IE)
 0x01 IFG (A0: IFG2, A1: UC1IFG)


USCI B0/B1 offsets (SPI/I2C)
===========================
Control registers
-----------------
 0x00 UCB0CTL0
 0x01 UCB0CTL1
 0x02 UCB0BR0
 0x03 UCB0BR1
 0x04 UCB0I2CIE
 0x05 UCB0STAT
 0x06 UCB0RXBUF
 0x07 UCB0TXBUF

Interrupt Registers
-------------------
  0x00 IE  (B0: IE2, B1: UC1IE)
  0x01 IFG (B0: IFG2, B1: UC1IFG)

I2C address registers
---------------------
  0x00 UCB0I2COA
  0x02 UCB0I2CSA
