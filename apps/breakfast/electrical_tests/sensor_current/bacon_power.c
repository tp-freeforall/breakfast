#include <msp430.h>

unsigned int wakeupCount = 0;

void main(void){
  //watchdog off
  WDTCTL = WDTPW + WDTHOLD;

  //turn on VCC_1WB
  P3SEL &= ~BIT7;
  P3DIR |= BIT7;
  P3OUT |= BIT7;

  //config leds
  P3SEL &= ~(BIT0 | BIT1| BIT2);
  P3DIR |= (BIT0 | BIT1 | BIT2);
  P3OUT |= (BIT0 | BIT1 );
  P3OUT &= ~(BIT2);

  //start it up
  //TA1CCTL0 = CCIE;
  //TA1CCR0 = 50000;
  //TA1CTL = TASSEL_2 + MC_2 + TACLR;
  __bis_SR_register(LPM0_bits + GIE);
  __no_operation();
}

__attribute((wakeup)) __attribute((interrupt(TIMER1_A0_VECTOR))) void TIMER1_A0_ISR(void)
{
  wakeupCount++;
  //keep low-order bits, invert (LEDs active low)
  P3OUT =  (P3OUT & ~(BIT0|BIT1|BIT2)) | ~((BIT0|BIT1|BIT2) & wakeupCount);
  TA1CCR0 += 50000;
}
