#include "RadioTest.h"

configuration RadioTestSnifferC {
} implementation {
  components MainC, LedsC;
  components RadioTestSnifferP;

  components new AMReceiverC(AM_RADIO_TEST_REPORT) as ReportReceive;
  
  components Rf1aActiveMessageC;

  RadioTestSnifferP.Boot -> MainC.Boot;
  RadioTestSnifferP.RadioSplitControl -> Rf1aActiveMessageC.SplitControl;
  RadioTestSnifferP.Leds -> LedsC;
  RadioTestSnifferP.ReportReceive -> ReportReceive;

}
