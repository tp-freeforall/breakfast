#include  <msp430.h>

//mclk: 20mhz
//aclk: 32khz
void clock_1mhz(void){
  if(CALBC1_1MHZ == 0xFF || CALDCO_1MHZ == 0xFF){
    return;
  }
  BCSCTL1 = XT2OFF | CALBC1_1MHZ;
  BCSCTL2 = 0;
  BCSCTL3 = 0;
  DCOCTL  = CALDCO_1MHZ;
}

//this produces 1.1 mhz/32khz. Because one or both of the calibration
//values are not set.
void clock_8mhz(void){
  //These values are 0xff. why!?!
  if(CALBC1_8MHZ == 0xFF || CALDCO_8MHZ == 0xFF){
    return;
  }
  BCSCTL1 = CALBC1_8MHZ;
  DCOCTL  = CALDCO_8MHZ;
}

//mclk: 1.1 mhz
//aclk: 32 khz
void clock_verify_default(void){
  DCOCTL  = 0x60;
  BCSCTL1 = 0x87;
  BCSCTL2 = 0x00;
  BCSCTL3 = 0x05;
}

//mclk: 1.1 mhz
//aclk: 32 khz
void clock_default(void){
  return;
}

void clock_tune_32khz(void){
  DCOCTL  = 0x60;
  BCSCTL1 = 0x87;
  BCSCTL2 = 0x00;
  //xcap= 0: 32.7673
  //xcap= 3: 32.7651
  #ifndef XCAP_SETTING
  #warning "Using default XCAP_SETTING of 0"
  #define XCAP_SETTING 0
  #endif
  BCSCTL3 = 0x00 | (XCAP_SETTING << 2);
}

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer

  clock_tune_32khz();

  P6DIR |= 0x01;                            // Set P6.0 to output direction
  P5DIR |= 0x50;                            // Set p5.4, p5.6 output
  P5SEL |= 0x50;                            // use MCLK, aclk

  for (;;)
  {
    volatile unsigned int i;

    P6OUT ^= 0x01;                          // Toggle P6.0 using exclusive-OR

    i = 50000;                              // Delay
    do (i--);
    while (i != 0);
  }
}
