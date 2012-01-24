//******************************************************************************
//   MSP430x24x Demo - USCI_A0, 115200 UART Echo ISR, DCO SMCLK, LPM4
//
//   Description: Echo a received character, RX ISR used. Normal mode is LPM4.
//   Automatic clock activation for SMCLK through the USCI is demonstrated.
//   All I/O configured as low outputs to eliminate floating inputs.
//   USCI_A0 RX interrupt triggers TX Echo.
//   Baud rate divider with 1MHz = 1MHz/115200 = ~8.7
//   ACLK = n/a, MCLK = SMCLK = CALxxx_1MHZ = 1MHz
//
//                MSP430F249
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P2.1|-->SMCLK = 1MHz (active on demand)
//            |                 |
//            |     P3.4/UCA0TXD|------------>
//            |                 | 115200 - 8N1
//            |     P3.5/UCA0RXD|<------------
//
//  B. Nisarga
//  Texas Instruments Inc.
//  September 2007
//  Built with CCE Version: 3.2.0 and IAR Embedded Workbench Version: 3.42A
//******************************************************************************
#include <msp430.h>
typedef unsigned int uint16_t;
typedef unsigned char uint8_t;

uint8_t counter = 0;

void config_dco(uint16_t delta){
    uint16_t Compare, Oldcapture = 0; 
    //wait for oscillator fault to clear
    while(BCSCTL3 & LFXT1OF){
    };

    BCSCTL1 |= DIVA_3;                        // ACLK = LFXT1CLK/8
    TACCTL2 = CM_1 + CCIS_1 + CAP;            // CAP, ACLK
    TACTL = TASSEL_2 + MC_2 + TACLR;          // SMCLK, cont-mode, clear
  
    while (1)
    {  
      while (!(CCIFG & TACCTL2));             // Wait until capture occured
      TACCTL2 &= ~CCIFG;                      // Capture occured, clear flag
      Compare = TACCR2;                       // Get current captured SMCLK
      Compare = Compare - Oldcapture;         // SMCLK difference
      Oldcapture = TACCR2;                    // Save current captured SMCLK
  
      if (delta == Compare)
        break;                                // If equal, leave "while(1)"
      else if (delta < Compare)
      {  
        DCOCTL--;                             // DCO is too fast, slow it down
        if (DCOCTL == 0xFF)                   // Did DCO roll under?
          if (BCSCTL1 & 0x0f)
            BCSCTL1--;                        // Select lower RSEL
      }  
      else
      {  
        DCOCTL++;                             // DCO is too slow, speed it up
        if (DCOCTL == 0x00)                   // Did DCO roll over?
          if ((BCSCTL1 & 0x0f) != 0x0f)
            BCSCTL1++;                        // Sel higher RSEL
      }  
    }  
    TACCTL2 = 0;                              // Stop TACCR2
    TACTL = 0;                                // Stop Timer_A
    BCSCTL1 &= ~DIVA_3;                       // ACLK = LFXT1CLK
}

#define ASCII_ZERO 48
#define ASCII_A 97

uint8_t nibbleToChar(uint8_t b){
  if ((b & 0x0f) < 0x0a){
    return ASCII_ZERO + (b&0x0f);
  }else{
    return ASCII_A + ((b&0x0f) - 0x0a);
  }
}

void printByte(uint8_t b){
  while (!(IFG2&UCA0TXIFG));                // USCI_A0 TX buffer ready?
  UCA0TXBUF = nibbleToChar(b >> 4);
  while (!(IFG2&UCA0TXIFG));                // USCI_A0 TX buffer ready?
  UCA0TXBUF = nibbleToChar(b);
}

void printChar(uint8_t c){
  while (!(IFG2&UCA0TXIFG));                // USCI_A0 TX buffer ready?
  UCA0TXBUF = c;
}

void nl(void){
  while (!(IFG2&UCA0TXIFG));                // USCI_A0 TX buffer ready?
  UCA0TXBUF ='\n';
  while (!(IFG2&UCA0TXIFG));                // USCI_A0 TX buffer ready?
  UCA0TXBUF ='\r';
}


void main(void)
{
  uint16_t i;
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  #define DELTA_1MHZ_32khz_aclk    244                   // 244 x 4096Hz = 999.4KHz
  config_dco(DELTA_1MHZ_32khz_aclk);
  P1DIR = 0xFF;                             // All P1.x outputs
  P1OUT = 0;                                // All P1.x reset
  P2SEL = 0x02;                             // P2.1 = SMCLK, others GPIO
  P2DIR = 0xFF;                             // All P2.x outputs
  P2OUT = 0;                                // All P2.x reset
  P3SEL = 0x30;                             // P3.4,5 = USCI_A0 TXD/RXD
  P3DIR = 0xFF;                             // All P3.x outputs
  P3OUT = 0;                                // All P3.x reset
  P4DIR = 0xFF;                             // All P4.x outputs
  P4OUT = 0;                                // All P4.x reset
  P5DIR = 0xFF;                             // All P5.x outputs
  P5OUT = 0;                                // All P5.x reset
  P6DIR = 0xFF;                             // All P6.x outputs
  P6OUT = 0;                                // All P6.x reset  
  
  UCA0CTL1 |= UCSSEL_2;                     // SMCLK
  UCA0BR0 = 8;                              // 1MHz 115200
  UCA0BR1 = 0;                              // 1MHz 115200
  UCA0MCTL = UCBRS2 + UCBRS0;               // Modulation UCBRSx = 5
  UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
  //IE2 |= UCA0RXIE;                          // Enable USCI_A0 RX interrupt

  //power pin
  P4SEL &= (0x01 << 3);
  P4DIR |= (0x01 << 3);
  P4OUT |= (0x01 << 3);

  //ADC setup
  P6SEL |= 0x01;                            // Enable A/D channel A0
  ADC12CTL0 = ADC12ON+SHT0_2+REFON+REF2_5V; // Turn on and set up ADC12
  ADC12CTL1 = SHP;                          // Use sampling timer
  ADC12MCTL0 = SREF_1;                      // Vr+=Vref+
 
  ADC12IE = 0x01;                           // Enable ADC12IFG.0
  ADC12CTL0 |= ENC;                         // Enable conversions
  while (1)
  {
    for ( i=0; i<0x3600; i++);                // Delay for reference start-up
    ADC12CTL0 |= ADC12SC;                   // Start conversion
    _BIS_SR(LPM0_bits + GIE); //enter lpm0 + interrupts
  }
}

//void USCI0RX_ISR(void) __attribute((wakeup)) __attribute((interrupt(USCIAB0RX_VECTOR)));
//void USCI0RX_ISR(void)
//{
//  uint8_t garbage = UCA0RXBUF;
//  while (!(IFG2&UCA0TXIFG));                // USCI_A0 TX buffer ready?
//  printByte(counter);
//  nl();
//  //UCA0TXBUF = UCA0RXBUF;                    // TX -> RXed character
//  counter++;
//}

void ADC12_ISR(void) __attribute((wakeup)) __attribute((interrupt(ADC12_VECTOR)));
void ADC12_ISR(void){
    printChar('D');
    printChar('A');
    printChar('T');
    printChar('A');
    printChar(' ');
    printByte((ADC12MEM0 & 0xff00) >> 8);
    printByte(ADC12MEM0 & 0xff);
    nl();
    _BIC_SR_IRQ(LPM0_bits);                   // Clear LPM0, SET BREAKPOINT HERE
}

