#include "concxmit.h"
#include <stdio.h>
//originally (c) people power, adapted for modulation scheme testing on 07/11/11 by doug carlson
configuration TestSenderAppC {
} implementation {
  components SerialPrintfC;

  components TestSenderP as TestP;
  components MainC;

  TestP.Boot -> MainC;
  
  components new DelayedAMSenderC(CONCXMIT_RADIO_AM_TEST);
  TestP.RadioSend -> DelayedAMSenderC;
  TestP.DelayedSend -> DelayedAMSenderC;

  components ActiveMessageC;
  TestP.SplitControl -> ActiveMessageC;

  components Rf1aActiveMessageC;
  TestP.Rf1aIf -> Rf1aActiveMessageC;
  //TODO: use compile flags to select which config to use.
  //#if TEST_CONFIG == XXX
  //  components TestConfigXXXP as TestConfigP;
  //#else
  components PDERf1aSettingsP as TestConfigP;
  //#endif
  Rf1aActiveMessageC.Rf1aConfigure -> TestConfigP.Rf1aConfigure;

  components LedsC;
  TestP.Leds -> LedsC;
  
  components HplMsp430GeneralIOC;
  components HplMsp430InterruptC;

  components new Msp430GpioC() as SendPin;
  SendPin.HplGeneralIO -> HplMsp430GeneralIOC.Port11;
  TestP.SendPin -> SendPin;

  components new Msp430InterruptC() as SendInterrupt;
  SendInterrupt.HplInterrupt -> HplMsp430InterruptC.Port11;
  TestP.SendInterrupt -> SendInterrupt;
 

}
