module TestP{
  uses interface Boot;
  uses interface Timer<TMilli>;
} implementation {
  event void Boot.booted(){
    call Timer.startPeriodic(256);
    P2SEL &= ~(BIT6|BIT7);
    P2DIR |= BIT6 | BIT7;
  }

  event void Timer.fired(){
    P2OUT ^= BIT6|BIT7;
    printf("OUT: %x\n\r", P2OUT);
    printf("DIR: %x\n\r", P2DIR);
    printf("SEL: %x\n\r", P2SEL);
  }
}
