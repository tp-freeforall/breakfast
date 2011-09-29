#include "bacon_radio_test.h"

configuration SenderC{
} implementation {
  components SenderP as Test;

  components MainC;
  Test.Boot -> MainC;
  
  components LedsC;
  Test.Leds -> LedsC;

  components ActiveMessageC;
  Test.SplitControl -> ActiveMessageC;
  Test.RadioPacket -> ActiveMessageC;
  components new AMSenderC(AM_TXRX);
  Test.RadioSend -> AMSenderC;

  
  components CC1190C;
  Test.CC1190 -> CC1190C;
  Test.CC1190Control -> CC1190C;

  components SerialActiveMessageC;
  Test.SerialSplitControl -> SerialActiveMessageC;
  Test.SerialPacket -> SerialActiveMessageC;
  components new SerialAMSenderC(AM_REPORT);
  Test.ReportSend -> SerialAMSenderC;

  components Rf1aActiveMessageC;
  Test.Rf1aPacket -> Rf1aActiveMessageC;
  Test.Rf1aIf -> Rf1aActiveMessageC;

  components new TimerMilliC();
  Test.SendTimer -> TimerMilliC;

}
