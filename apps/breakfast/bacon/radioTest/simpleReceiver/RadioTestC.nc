#include "RadioTest.h"

configuration RadioTestC {
} implementation {
  components MainC, LedsC;
  components RadioTestP;

  components new AMReceiverC(AM_RADIO_TEST_PROBE);
  
  components Rf1aActiveMessageC;
  components new TimerMilliC() as AliveTimer;

  RadioTestP.Boot -> MainC.Boot;
  RadioTestP.RadioSplitControl -> Rf1aActiveMessageC.SplitControl;
  RadioTestP.Leds -> LedsC;
  RadioTestP.AliveTimer -> AliveTimer;

}
