#include "concxmit.h"
//originally (c) people power, adapted for modulation scheme testing on 07/11/11 by doug carlson
configuration TestReceiverAppC {
} implementation {
  components TestReceiverP as TestP;
  components MainC;

  TestP.Boot -> MainC;
  
  components new AMReceiverC(CONCXMIT_RADIO_AM_TEST);
  TestP.RadioReceive -> AMReceiverC;

  components SerialActiveMessageC;
  TestP.SerialSplitControl -> SerialActiveMessageC;
  components new SerialAMSenderC(CONCXMIT_SERIAL_AM_RECEIVER_REPORT) as ReportSend;
  components new SerialAMReceiverC(CONCXMIT_SERIAL_AM_CMD) as ReceiveCmd;
  TestP.ReportSend -> ReportSend;
  TestP.ReceiveCmd -> ReceiveCmd;

  components ActiveMessageC;
  TestP.SplitControl -> ActiveMessageC;
  components Rf1aActiveMessageC;
  TestP.Rf1aMulti -> Rf1aActiveMessageC;

  components LedsC;
  TestP.Leds -> LedsC;

  //signal "use next config" to senders
  components HplMsp430GeneralIOC;

  components new Msp430GpioC() as NextPin;
  NextPin.HplGeneralIO -> HplMsp430GeneralIOC.Port20;
  TestP.NextPin -> NextPin;

  //signal "get ready to send" to senders
  components new Msp430GpioC() as SendReadyPin;
  SendReadyPin.HplGeneralIO -> HplMsp430GeneralIOC.Port21;
  TestP.SendReadyPin -> SendReadyPin;

  components new TimerMilliC();
  TestP.Timer -> TimerMilliC;

  components Rf1aC;
  TestP.Rf1aPhysicalMetadata -> Rf1aC.Rf1aPhysicalMetadata;

  components BusyWaitMicroC;
  TestP.BusyWait -> BusyWaitMicroC;
}
