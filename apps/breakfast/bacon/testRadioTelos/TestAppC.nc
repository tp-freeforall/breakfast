#include "radioTest.h"

configuration TestAppC{
} implementation {
  components TestP;

  components MainC, LedsC, new TimerMilliC();
  TestP.Boot -> MainC;
  TestP.Leds -> LedsC;
  TestP.Timer -> TimerMilliC;
  components new TimerMilliC() as IndicatorTimer;
  TestP.IndicatorTimer -> IndicatorTimer;
  components new TimerMilliC() as WDTResetTimer;
  TestP.WDTResetTimer -> WDTResetTimer;

  components PlatformSerialC;
  components SerialPrintfC;
  TestP.SerialControl -> PlatformSerialC;
  TestP.UartStream -> PlatformSerialC;

  components ActiveMessageC;
  components new AMSenderC(AM_RADIO_TEST);
  components new AMReceiverC(AM_RADIO_TEST);
  TestP.SplitControl -> ActiveMessageC;
  TestP.AMSend -> AMSenderC;
  TestP.AMPacket -> AMSenderC;
  TestP.Receive -> AMReceiverC;

  components CC2420ActiveMessageC;
  TestP.CC2420Packet -> CC2420ActiveMessageC;

  //for setting tx power
//  TestP.Rf1aIf -> Rf1aActiveMessageC;
//  TestP.Rf1aPhysical -> Rf1aActiveMessageC;

//  components CC1190C;
//  TestP.AmpControl -> CC1190C;
//  TestP.CC1190 -> CC1190C;

//  components PDERf1aSettingsP as TestConfigP;
//  Rf1aActiveMessageC.Rf1aConfigure -> TestConfigP.Rf1aConfigure;
//
//  components Rf1aC;
//  TestP.Rf1aPhysicalMetadata -> Rf1aC.Rf1aPhysicalMetadata;
}
