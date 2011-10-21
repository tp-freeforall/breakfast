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
  P3SEL &= ~(BIT4);
  P3DIR &= ~(BIT4);

  //SENSOR0_EN = P4.3
  P4SEL &= ~(BIT3);
  P4OUT &= ~(BIT3);
  P4DIR |= (BIT3);

  //SENSOR4_EN = P5.0
  P5SEL &= ~(BIT0);
  P5OUT &= ~(BIT0);
  P5DIR |= (BIT0);

  //SENSOR0_IN = P6.0
  //SENSOR4_IN = P6.4
  P6SEL &= ~(BIT0|BIT4);
  P6DIR &= ~(BIT0|BIT4);


  for (;;)
  {  
    //wait until P3.4 goes low
    while(P3IN & (BIT4));

    //close switches
    P4OUT |= (BIT3);
    P5OUT |= (BIT0);

    //wait until P3.4 goes high
    while (! (P3IN & (BIT4)));

    //open switches
    P4OUT &= ~(BIT3);
    P5OUT &= ~(BIT0);
  }  
}

