#include  <msp430.h>

//mclk: 1.1 mhz
//aclk: 32 khz
void clock_verify_default(void){
  return;
}

//mclk: 1.1 mhz
//aclk: 32 khz
void clock_default(void){
  return;
}

void clock_tune_32khz(void){
  clock_default();
  //UCSCTL6 &= ~XTS;
  //UCSCTL6 &= ~(XCAP0 | XCAP1);
  //UCSCTL6 |= XCAP0 | XCAP1;
  #ifndef XCAP_SETTING
  #warning "Using default XCAP_SETTING of 0"
  #define XCAP_SETTING 0
  #endif
  //UCSCTL6 |= XT1BYPASS;
  UCSCTL6 |= (XCAP_SETTING << 2);

  // Loop until XT1 / osc fault flags cleared
  do
  {
    UCSCTL7 &= ~XT1LFOFFG;                  // Clear XT1 fault flags
    SFRIFG1 &= ~OFIFG;                      // Clear OSC Fault flag
    P1OUT^=BIT4;   //toggle to show status
  }while ( UCSCTL7&XT1LFOFFG );

}

void report(void){
    //p1.3: OFIFG state
    if (SFRIFG1 & OFIFG){
      P1OUT |= BIT3;
    }else{
      P1OUT &= ~BIT3;
    }
    //p1.4: XT1LFOFFG state
    if (UCSCTL7 & XT1LFOFFG){
      P1OUT |= BIT4;
    }else {
      P1OUT &= ~BIT4;
    }
}

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P5SEL |= BIT0|BIT1;  //select function for P5.0/5.1 (XT1)
  P1DIR |= BIT1|BIT2|BIT3|BIT4;  // Set P1.1->P1.4 to output direction
  P1SEL &= ~(BIT2|BIT3|BIT4); //P1.2->P1.4 general io

  clock_tune_32khz();
  
  PMAPPWD = PMAPKEY;
  PMAPCTL = PMAPRECFG;
  P1MAP1 = PM_ACLK;
  PMAPPWD = 0x0;

  P1SEL |= BIT1;  // P1.1: aclk

  for (;;)
  {
    volatile unsigned int i;
    P1OUT ^= BIT3;

    i = 50000;                              // Delay
    do (i--);
    while (i != 0);
  }
}
