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
  
  #ifndef XT1_INITIAL_DRIVE
  #warning "Using default XT1_INITIAL_DRIVE of 3"
  #define XT1_INITIAL_DRIVE 3
  #endif

  UCSCTL6 = (UCSCTL6 & ~XT1DRIVE_3) | (XT1_INITIAL_DRIVE << 6);

  // Loop until XT1 / osc fault flags cleared
  do
  {
    UCSCTL7 &= ~XT1LFOFFG;                  // Clear XT1 fault flag
    P1OUT^=BIT4;   //toggle to show status
  }while ( UCSCTL7&XT1LFOFFG );

  #ifndef XT1_FINAL_DRIVE
  #warning "Using default XT1_FINAL_DRIVE of 3"
  #define XT1_FINAL_DRIVE 3
  #endif
  UCSCTL6 = (UCSCTL6 & ~XT1DRIVE_3) | (XT1_FINAL_DRIVE << 6);
 
  __bis_SR_register(SCG0);                  // Disable the FLL control loop
  UCSCTL0 = 0x0000;                         // Set lowest possible DCOx, MODx
  UCSCTL1 = DCORSEL_1; //pick range that covers 2x target
  UCSCTL2 = FLLD_1 + 63; 
  //FLLD_1 means "FLL will see 1/2 dco"
  //(FLLN+1)*2^15 = actual frequency to be achieved

  __bic_SR_register(SCG0);                  // Enable the FLL control loop
  // FLLREFDIV*32*32*(f_MCLK/f_FLL_ref)
  // this is a worst-case: one of those 32's might not be 32 (not sure
  // how to optimize it, though)
  __delay_cycles(65536);

  do
  {
    UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + XT1HFOFFG + DCOFFG);
    SFRIFG1 &= ~OFIFG;                      // Clear fault flags
    P2OUT ^= BIT4;
  } while(SFRIFG1 & OFIFG);
  P2OUT &= ~BIT4;

}

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P5SEL |= BIT0|BIT1;  //select function for P5.0/5.1 (XT1)
  P1DIR |= BIT1|BIT2|BIT3|BIT4;  // Set P1.1->P1.4 to output direction
  P1SEL &= ~(BIT3|BIT4); //P1.2->P1.4 general io
  P2DIR |= BIT4;
  P2SEL &= ~BIT4;
  
  //output aclk
  PMAPPWD = PMAPKEY;
  PMAPCTL = PMAPRECFG;
  P1MAP1 = PM_ACLK;
  P1MAP2 = PM_MCLK;
  PMAPPWD = 0x0;

  P1SEL |= BIT1|BIT2;  // P1.1: aclk, p1.2 mclk

  clock_tune_32khz();

  for (;;)
  {
    volatile unsigned int i;
    P1OUT ^= BIT3;

    i = 50000;                              // Delay
    do (i--);
    while (i != 0);
  }
}
