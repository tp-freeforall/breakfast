#include "msp430.h"


void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P6DIR |= 0x01;                            // Set P6.0 to output direction
  P6SEL &= ~0x01;                            // Set P6.0 to output direction

  for (;;)
  {
    volatile unsigned int i;

    P6OUT ^= 0x01;                          // Toggle P6.0 using exclusive-OR

    i = 50000;                              // Delay
    do (i--);
    while (i != 0);
  }
}

__attribute((wakeup)) __attribute((interrupt(PORT1_VECTOR))) void P1_ISR(void){
  P6OUT ^=0x01;
}
