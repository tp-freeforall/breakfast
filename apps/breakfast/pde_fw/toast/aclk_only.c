//DC: uncomment for compilation in IAR
//#include "msp430x23x.h"
#include <msp430.h>

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop Watchdog Timer
  P5DIR |= BIT6;
  P5SEL |= BIT6;
  while(1){}
}
