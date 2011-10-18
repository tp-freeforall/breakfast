//******************************************************************************
//  CC430F513x Demo - USCI_B0 I2C Master TX single bytes to MSP430 Slave
//
//  Description: This demo connects two MSP430's via the I2C bus. The master
//  transmits to the slave. This is the master code. It continuously
//  transmits 00h, 01h, ..., 0ffh and demonstrates how to implement an I2C
//  master transmitter sending a single byte using the USCI_B0 TX interrupt.
//  ACLK = n/a, MCLK = SMCLK = BRCLK = default DCO = ~1.045MHz
//
//                                /|\  /|\
//               CC430F5137      10k  10k     CC430F5137
//                   slave         |    |        master
//             -----------------   |    |   -----------------
//           -|XIN  P2.6/UCB0SDA|<-|----+->|P2.6/UCB0SDA  XIN|-
//            |                 |  |       |                 | 32kHz
//           -|XOUT             |  |       |             XOUT|-
//            |     P2.7/UCB0SCL|<-+------>|P2.7/UCB0SCL     |
//            |                 |          |             P1.0|--> LED
//
//   M Morales
//   Texas Instruments Inc.
//   April 2009
//   Built with CCE Version: 3.2.2 and IAR Embedded Workbench Version: 4.11B
//******************************************************************************

#include <msp430.h>

#ifndef I2C_DIV
#define I2C_DIV 128
#endif

unsigned char TXData;
unsigned char TXByteCtr;
void setupClock(void);
void main(void)
{
  volatile unsigned int i;
 
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  setupClock();

  PMAPPWD = 0x02D52;                        // Get write-access to port mapping regs  
  P2MAP6 = PM_UCB0SDA;                      // Map UCB0SDA output to P2.6 
  P2MAP7 = PM_UCB0SCL;                      // Map UCB0SCL output to P2.7 
  PMAPPWD = 0;                              // Lock port mapping registers 


  P2SEL |= BIT6 + BIT7;                     // Select P2.6 & P2.7 to I2C function
  #ifdef INTERNAL_PULLUP
  //DIR = 0 REN = 1: pullup/down enabled. OUT=1: up OUT=0: down
  P2DIR &= ~(BIT6 + BIT7);
  P2OUT |= (BIT6 + BIT7);
  P2REN |= (BIT6 + BIT7);
  #endif
    
  UCB0CTL1 |= UCSWRST;                      // Enable SW reset
  UCB0CTL0 = UCMST + UCMODE_3 + UCSYNC;     // I2C Master, synchronous mode
  UCB0CTL1 = UCSSEL_2 + UCSWRST;            // Use SMCLK, keep SW reset
  UCB0BR0 = I2C_DIV & 0xff;                             
  UCB0BR1 = I2C_DIV >> 8;
  UCB0I2CSA = 0x48;                         // Slave Address is 048h
  UCB0CTL1 &= ~UCSWRST;                     // Clear SW reset, resume operation
  UCB0IE |= UCTXIE;                         // Enable TX interrupt
//  UCB0IE |= UCNACKIE;                       // Enable NACK interrupt

  TXData = 0x01;                            // Holds TX data
  i = 50000;  //delay (for when slave powered on at the same time as master
  do (i--);
  while (i!= 0);

  while (1)
  {
    TXByteCtr = 1;                          // Load TX byte counter

    while (UCB0CTL1 & UCTXSTP);             // Ensure stop condition got sent
    UCB0CTL1 |= UCTR + UCTXSTT;             // I2C TX, start condition
   
    __bis_SR_register(LPM0_bits + GIE);     // Enter LPM0 w/ interrupts
    __no_operation();                       // Remain in LPM0 until all data
                                            // is TX'd
                                              
    TXData++;                               // Increment data byte
  }
}

//------------------------------------------------------------------------------
// The USCIAB0_ISR is structured such that it can be used to transmit any
// number of bytes by pre-loading TXByteCtr with the byte count.
//------------------------------------------------------------------------------
int __even_in_range(int v, int g){
  return v;
}

//#pragma vector = USCI_B0_VECTOR
//__interrupt void USCI_B0_ISR(void)
__attribute((wakeup)) __attribute((interrupt(USCI_B0_VECTOR))) void USCI_B0_ISR(void) 
{
  switch(__even_in_range(UCB0IV,12))
  {
  case  0: break;                           // Vector  0: No interrupts
  case  2: break;                           // Vector  2: ALIFG
  case  4: 
//    UCB0CTL1 |= UCTXSTP;
//    UCB0IFG &=- ~UCTXIFG;
//    UCB0IFG &=- ~UCNACKIFG;
//    __bic_SR_register_on_exit(LPM0_bits); // Exit LPM0
    break;                           // Vector  4: NACKIFG
  case  6: break;                           // Vector  6: STTIFG
  case  8: break;                           // Vector  8: STPIFG
  case 10: break;                           // Vector 10: RXIFG
  case 12:                                  // Vector 12: TXIFG  
    if (TXByteCtr)                          // Check TX byte counter
    {
      UCB0TXBUF = TXData;                   // Load TX buffer
      TXByteCtr--;                          // Decrement TX byte counter
    }
    else
    {
      UCB0CTL1 |= UCTXSTP;                  // I2C stop condition
      UCB0IFG &= ~UCTXIFG;                  // Clear USCI_B0 TX int flag
      __bic_SR_register_on_exit(LPM0_bits); // Exit LPM0
    }
    break;
  default: break;
  }
}

void setupClock(void){
//  PMAPPWD = 0x02D52;                        // Get write-access to port mapping regs  
//  P1MAP1 = PM_SMCLK;
//  PMAPPWD = 0;                              // Lock port mapping registers  
//  
//  P1DIR |= BIT1;
//  P1SEL |= BIT1;
//
  UCSCTL3 |= SELREF_2;                      // Set DCO FLL reference = REFO
  UCSCTL4 |= SELA_2;                        // Set ACLK = REFO

  __bis_SR_register(SCG0);                  // Disable the FLL control loop
  UCSCTL0 = 0x0000;                         // Set lowest possible DCOx, MODx
  UCSCTL1 = DCORSEL_5;                      // Select DCO range 16MHz operation
  UCSCTL2 = FLLD_1 + 249;                   // Set DCO Multiplier for 8MHz
                                            // (N + 1) * FLLRef = Fdco
                                            // (249 + 1) * 32768 = 8MHz
                                            // Set FLL Div = fDCOCLK/2
  __bic_SR_register(SCG0);                  // Enable the FLL control loop

  // Worst-case settling time for the DCO when the DCO range bits have been
  // changed is n x 32 x 32 x f_MCLK / f_FLL_reference. See UCS chapter in 5xx
  // UG for optimization.
  // 32 x 32 x 8 MHz / 32,768 Hz = 250000 = MCLK cycles for DCO to settle
  __delay_cycles(125000);
  __delay_cycles(125000);

  // Loop until XT1,XT2 & DCO fault flag is cleared
  do
  {
    UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + XT1HFOFFG + DCOFFG);
                                            // Clear XT2,XT1,DCO fault flags
    SFRIFG1 &= ~OFIFG;                      // Clear fault flags
  }while (SFRIFG1&OFIFG);                   // Test oscillator fault flag

}


