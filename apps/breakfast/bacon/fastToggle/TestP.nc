#include <UserButton.h>

module TestP{
  uses interface Boot;
  uses interface Notify<button_state_t>;
  uses interface BusyWait<TMicro, uint16_t>;
} implementation {
  //96 ns @ 8192
  //88 ns @ 4096
  //same  @ 32768
  //this definitively shows that the pulse in mode 2 comes at the
  //  start of the cycle
  //with output mode 6, ccr1 = period - width:
  //157.5 ns @ 4096
  //78 ns @ 2048
  // hoooray
  //16384 gives 630 uS to clear end of atomic block
  uint16_t period = 16384;
  uint16_t pulseWidth = 1;
  uint16_t WAIT_TIME = 10;

  event void Boot.booted(){
    uint16_t bw;
    call Notify.enable();

    WDTCTL = WDTPW + WDTHOLD;

    //P2.2 TA1 CCR1 
    P2DIR |= BIT2;
    P2SEL |= BIT2;

    //P2.3: gpio out
    P2DIR |= BIT3;
    P2OUT &= (~BIT3);
    P2SEL &= (~BIT3);

    TA1CCR0 = period - 1;
    TA1CCR1 = period - 1 - pulseWidth;

    TA1CCTL1 = OUTMOD_6;
    TA1CTL = TASSEL_3 | MC__UP;

  }

  event void Notify.notify(button_state_t val){
    uint8_t cycles = 0;
    if (val == BUTTON_RELEASED){
      P2OUT |= BIT3;
      TA1CCR0 = period - 1;
    } else {
      P2OUT &= (~BIT3);
      TA1CCR0 = 0;
    }
  } 

}
