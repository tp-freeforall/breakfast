#include "RadioTest.h"

configuration RadioTestC {
} implementation {
  components MainC, LedsC;
  components new TimerMilliC() as SendTimer;
  components RadioTestP;

  components new AMSenderC(AM_RADIO_TEST_PROBE) as ProbeSend;
  components new AMSenderC(AM_RADIO_TEST_REPORT) as ReportSend;
  components new AMReceiverC(AM_RADIO_TEST_PROBE);
  
  //TODO: looks like we'll need to mess around with the RF1a code in order to modify power levels...
  components Rf1aActiveMessageC;

  RadioTestP.Boot -> MainC.Boot;
  RadioTestP.SendTimer -> SendTimer;
  RadioTestP.RadioSplitControl -> Rf1aActiveMessageC.SplitControl;
  RadioTestP.Leds -> LedsC;
  RadioTestP.Packet -> Rf1aActiveMessageC.Packet;
  RadioTestP.Rf1aPacket -> Rf1aActiveMessageC.Rf1aPacket;
  RadioTestP.ProbeSend -> ProbeSend;
  RadioTestP.ReportSend -> ReportSend;

}
