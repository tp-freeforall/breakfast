//DC: uncomment for compilation in IAR
//#include "msp430x23x.h"
#include <msp430.h>

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop Watchdog Timer
  #ifndef XCAP_SETTING
  #warning "Using default XCAP_SETTING of 0"
  #define XCAP_SETTING 0
  #endif
  BCSCTL3 = 0x00 | (XCAP_SETTING << 2);
  P5DIR |= BIT6;
  P5SEL |= BIT6;
  while(1){}
}
