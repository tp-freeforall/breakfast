#include <stdio.h>
configuration TestAppC{
} implementation {
  #ifdef DEBUG_TIMER_BUG
  components SerialPrintfC;
  #endif

  components MainC, LedsC, 
    new TimerMilliC() as Timer0, 
    new TimerMilliC() as Timer1;

  components TestP;

  TestP.Boot -> MainC;
  TestP.Leds -> LedsC;
  TestP.Timer0 -> Timer0;
  TestP.Timer1 -> Timer1;
}
