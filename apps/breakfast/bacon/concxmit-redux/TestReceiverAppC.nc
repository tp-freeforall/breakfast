#include "concxmit.h"
#include "stdio.h"

//originally (c) people power, adapted for modulation scheme testing on 07/11/11 by doug carlson
configuration TestReceiverAppC {
} implementation {
  components SerialPrintfC;

  components TestReceiverP as TestP;
  components MainC;

  TestP.Boot -> MainC;
  
  components new AMReceiverC(CONCXMIT_RADIO_AM_TEST);
  TestP.RadioReceive -> AMReceiverC;

  components ActiveMessageC;
  TestP.SplitControl -> ActiveMessageC;
  components Rf1aActiveMessageC;
  components PDERf1aSettingsP as TestConfigP;
  Rf1aActiveMessageC.Rf1aConfigure -> TestConfigP.Rf1aConfigure;

  components LedsC;
  TestP.Leds -> LedsC;

  components new TimerMilliC();
  TestP.Timer -> TimerMilliC;

  components HplMsp430GeneralIOC;
  components new Msp430GpioC() as ResetPin;
  ResetPin.HplGeneralIO -> HplMsp430GeneralIOC.Port24;
  TestP.ResetPin -> ResetPin;

  components Rf1aC;
  TestP.Rf1aPhysicalMetadata -> Rf1aC.Rf1aPhysicalMetadata;

}
