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
  UCSCTL6 &= ~XTS;
  UCSCTL6 &= ~(XCAP0 | XCAP1);
  //UCSCTL6 |= XCAP0 | XCAP1;
  #ifndef XCAP_SETTING
  #warning "Using default XCAP_SETTING of 0"
  #define XCAP_SETTING 0
  #endif
  UCSCTL6 |= XT1BYPASS;
  UCSCTL6 |= (XCAP_SETTING << 2);
}

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer

  clock_tune_32khz();

  P1DIR |= BIT1|BIT2;                            // Set P1.1, P1.2 to output direction
  P5SEL |= BIT0|BIT1;                     //select function for P5.0/5.1
  P1SEL |= BIT1;                            // put aclk on P1.1
  PMAPPWD = PMAPKEY;
  PMAPCTL = PMAPRECFG;
  P1MAP1 = PM_ACLK;
  PMAPPWD = 0x0;

  P1SEL &= ~BIT2;  //P1.2: general io

  for (;;)
  {
    volatile unsigned int i;

    P1OUT ^= BIT2;                          // Toggle P6.0 using exclusive-OR

    i = 50000;                              // Delay
    do (i--);
    while (i != 0);
  }
}
