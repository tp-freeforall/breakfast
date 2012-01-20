//DC: replace with below for IAR
//#include "cc430x513x.h"
#include <msp430.h>

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer

  P1DIR |= BIT0;                            // P1.0 output
  
  PMAPPWD = 0x02D52;                        // Get write-access to port mapping regs  
  P1MAP1 = PM_ACLK;                         // Map ACLK output to P2.0 
  P1MAP2 = PM_MCLK;                         // Map MCLK output to P2.2 
  PMAPPWD = 0;                              // Lock port mapping registers  
   
  P1DIR |= BIT1 + BIT2;                     // ACLK, MCLK, SMCLK set out to pins
  P1SEL |= BIT1 + BIT2;                     // P1.1,2 for debugging purposes.
  
  P1DIR |= BIT3;  //p1.3 will be toggled when running correctly
  P1DIR |= BIT4;  //p1.4 will be toggled while XT1LF fault
  
  P2DIR |= BIT4; //p2.4 will be toggled while DCO stabilizing
  P2SEL &= ~BIT4;

  P3DIR |=BIT0;
  P3SEL &=~BIT0;
  
  // Initialize LFXT1
  P5SEL |= 0x03;                            // Select XT1
  #ifndef XCAP_SETTING
  #warning "Using default XCAP_SETTING (0)"
  #define XCAP_SETTING 0
  #endif
  UCSCTL6 = (UCSCTL6 & ~(XCAP_3))|(XCAP_SETTING << 2);           // Internal load cap

  // Loop until XT1 fault flag is cleared
  do
  {
    UCSCTL7 &= ~XT1LFOFFG;                  // Clear XT1 fault flags
    P1OUT^=BIT4;
  }while (UCSCTL7&XT1LFOFFG);               // Test XT1 fault flag
  P1OUT&=~BIT4;

  // Initialize DCO to 2.45MHz
  __bis_SR_register(SCG0);                  // Disable the FLL control loop
  UCSCTL0 = 0x0000;                         // Set lowest possible DCOx, MODx
  UCSCTL1 = DCORSEL_3;                      // Set RSELx for DCO = 4.9 MHz
  UCSCTL2 = FLLD_1 + 74;                    // Set DCO Multiplier for 2.45MHz
                                            // (N + 1) * FLLRef = Fdco
                                            // (74 + 1) * 32768 = 2.45MHz
                                            // Set FLL Div = fDCOCLK/2
  __bic_SR_register(SCG0);                  // Enable the FLL control loop

  // Worst-case settling time for the DCO when the DCO range bits have been
  // changed is n x 32 x 32 x f_MCLK / f_FLL_reference. See UCS chapter in 5xx
  // UG for optimization.
  // 32 x 32 x 2.45 MHz / 32,768 Hz = 76563 = MCLK cycles for DCO to settle
  __delay_cycles(76563);

  // Loop until XT1,XT2 & DCO fault flag is cleared
  do
  {
    UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + XT1HFOFFG + DCOFFG);
                                            // Clear XT2,XT1,DCO fault flags
    SFRIFG1 &= ~OFIFG;                      // Clear fault flags
    P2OUT ^= BIT4;
  }while (SFRIFG1&OFIFG);                   // Test oscillator fault flag
  P2OUT &= ~BIT4;

  P3DIR |= BIT0 | BIT1 | BIT2;
  P3SEL &= ~(BIT0 | BIT1 | BIT2);
  
  //set up timer A to fire every 1/4 second
  TA1CCTL0 = CCIE;
  TA1CCR0 = (32768 /4);
  TA1CTL = TASSEL__ACLK | MC__UP | TACLR;

  __bis_SR_register(LPM0_bits + GIE);
}

void TIMER1_A0_ISR(void) __attribute((wakeup))
__attribute((interrupt(TIMER1_A0_VECTOR)));

int counter;
void TIMER1_A0_ISR(void){
  counter ++;
  P3OUT = (P3OUT & ~(BIT0|BIT1|BIT2))| ((~counter) & (BIT0|BIT1|BIT2));
}



