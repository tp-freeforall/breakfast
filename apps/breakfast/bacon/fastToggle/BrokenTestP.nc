module TestP{
  uses interface Boot;
} implementation {
  //argahga why do none of these do what I want??!
  //this seems like I should want
  // mode=up
  // output: set/reset
  // TA1CCR0: period (end of pulse)
  // TA1CCR1: start of pulse
  // and decreasing TA1CCR1 should give me a wider pulse.
  uint16_t period = 1 << 15;

  //outmod_3
  uint8_t outmod = OUTMOD_3;
  ////1<<15, 1024: 41.7 ns, 1.29 ms
  uint16_t pulseStart = 1 << 15;
  uint16_t pulseDuration = 1<<14;

  ////1<<15, 2048: 41,7 ns, 1.339 ms
  //uint16_t pulseStart = 1 << 15;
  //uint16_t pulseDuration = 2048;

  ////1<<15, 4096: 41,7 ns, 1.418 ms
  //uint16_t pulseStart = 1 << 15;
  //uint16_t pulseDuration = 4096;

  task void kickNext(){
    //TODO: set up for a single pulse, some time in the future, with
    //duration = pulseDuration
  }

  event void Boot.booted(){
    //uint8_t period_shift = 8;

    //select peripheral function for PM_TA1CCR0A (I think)
    P2SEL |= 3 << 1;
    P2DIR |= 3 << 1;
    //stop timer a 1
    TA1CTL = MC__STOP;

    //per note in datasheet "switching between output modes"
    TA1CCTL0 = OUTMOD_7;
    TA1CCTL0 = outmod;

    TA1CCR0 = period;
    TA1CCR2 = period - pulseDuration; 

    //start timer 1 
    TA1CTL = TASSEL_3 | ID_0 | MC__UP | TACLR;
  }

  //TODO: at overflow interrupt, stop the timer
}
