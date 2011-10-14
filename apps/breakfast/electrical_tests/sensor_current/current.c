#include <msp430.h>

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
//  //2.4 v on power 0
//  P4DIR = 0xff;
//  P4OUT = 0xff;
//  P5DIR = 0xff;
//  P5OUT = 0x00;
//  while(1){
//  }
  //TP18 = P3.4
  //0001 0000
  //P3.4: input
  P3SEL &= ~(0x01 << 4);
  P3DIR &= ~(0x01 << 4);

  //SENSOR0_EN = P4.3
  P4SEL &= ~(0x01 << 3);
  P4OUT &= ~(0x01 << 3);
  P4DIR |= (0x01 << 3);

  for (;;)
  {  
    //wait until P3.4 goes low
    while(P3IN & (0x01 << 4));
    //close switch
    P4OUT |= (0x01 << 3);
    //wait until P3.4 goes high
    while (! (P3IN & (0x01 << 4)));
    //open switch
    P4OUT &= ~(0x01 << 3);
  }  
}

