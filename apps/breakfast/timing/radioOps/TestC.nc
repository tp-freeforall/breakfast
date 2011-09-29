//#include "printf.h"
configuration TestC {
}
implementation {
  components MainC;
  components ActiveMessageC;
  components TestP;
  components LedsC, NoLedsC;
  
  components new AMSenderC(0x01);
  components new TimerMilliC() as StartPauseTimer, new TimerMilliC() as SendPauseTimer, new TimerMilliC() as StopPauseTimer;

  components HplMsp430GeneralIOC;

  TestP.Boot -> MainC.Boot;
  TestP.SplitControl -> ActiveMessageC;
  TestP.AMSend -> AMSenderC;
  TestP.Packet -> ActiveMessageC.Packet;
  TestP.StartPauseTimer -> StartPauseTimer;
  TestP.SendPauseTimer -> SendPauseTimer;
  TestP.StopPauseTimer -> StopPauseTimer;
  TestP.MarkerPin -> HplMsp430GeneralIOC.Port23;
  TestP.TimerPin -> HplMsp430GeneralIOC.Port24;
  TestP.Leds -> LedsC;
}
