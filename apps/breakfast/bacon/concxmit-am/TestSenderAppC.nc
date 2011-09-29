#include "concxmit.h"
//originally (c) people power, adapted for modulation scheme testing on 07/11/11 by doug carlson
configuration TestSenderAppC {
} implementation {
  components TestSenderP as TestP;
  components MainC;

  TestP.Boot -> MainC;
  
  components new AMSenderC(CONCXMIT_RADIO_AM_TEST);
  TestP.RadioSend -> AMSenderC;

  components SerialActiveMessageC;
  TestP.SerialSplitControl -> SerialActiveMessageC;
  components new SerialAMSenderC(CONCXMIT_SERIAL_AM_SENDER_REPORT) as ReportSend;
  TestP.ReportSend -> ReportSend;

  components ActiveMessageC;
  TestP.SplitControl -> ActiveMessageC;
  components Rf1aActiveMessageC;
  TestP.Rf1aMulti -> Rf1aActiveMessageC;
  TestP.DelayedSendRf1aPhysical -> Rf1aActiveMessageC;
  TestP.Rf1aIf -> Rf1aActiveMessageC;


  components LedsC;
  TestP.Leds -> LedsC;

  //"use next config" to senders
  components HplMsp430InterruptC;
  components HplMsp430GeneralIOC;

  components new Msp430GpioC() as NextPin;
  NextPin.HplGeneralIO -> HplMsp430GeneralIOC.Port20;
  TestP.NextPin -> NextPin;
  components new Msp430InterruptC() as NextInterrupt;
  NextInterrupt.HplInterrupt -> HplMsp430InterruptC.Port20;
  TestP.NextInterrupt -> NextInterrupt;

  components new Msp430GpioC() as SendReadyPin;
  SendReadyPin.HplGeneralIO -> HplMsp430GeneralIOC.Port21;
  TestP.HplSendReadyPin -> HplMsp430GeneralIOC.Port21;
  //TODO: wire up so that we can select IO func. why isn't this
  //exposed through the generalIO interface?
  TestP.SendReadyPin -> SendReadyPin;
  
  components new Msp430InterruptC() as SendReadyInterrupt;
  SendReadyInterrupt.HplInterrupt -> HplMsp430InterruptC.Port21;
  TestP.SendReadyInterrupt -> SendReadyInterrupt;
  
  components new Msp430GpioC() as SendPin;
  SendPin.HplGeneralIO -> HplMsp430GeneralIOC.Port22;
  TestP.SendPin -> SendPin;

  components new Msp430InterruptC() as SendInterrupt;
  SendInterrupt.HplInterrupt -> HplMsp430InterruptC.Port22;
  TestP.SendInterrupt -> SendInterrupt;

  components new Msp430GpioC() as DebugPin;
  DebugPin.HplGeneralIO -> HplMsp430GeneralIOC.Port24;
  TestP.DebugPin -> DebugPin;

  

}
