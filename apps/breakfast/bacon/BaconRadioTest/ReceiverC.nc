#include "bacon_radio_test.h"

configuration ReceiverC{
} implementation {
  components ReceiverP as Test;

  components MainC;
  Test.Boot -> MainC;
  
  components LedsC;
  Test.Leds -> LedsC;

  components ActiveMessageC;
  Test.SplitControl -> ActiveMessageC;
  Test.RadioPacket -> ActiveMessageC;

  components new AMReceiverC(AM_TXRX);
  Test.Receive -> AMReceiverC;

#ifdef HAS_CC1190
  components CC1190C;
  Test.CC1190 -> CC1190C;
  Test.CC1190Control -> CC1190C;
#endif
  components SerialActiveMessageC;
  Test.SerialSplitControl -> SerialActiveMessageC;
  Test.SerialPacket -> SerialActiveMessageC;
  components new SerialAMSenderC(AM_REPORT);
  Test.ReportSend -> SerialAMSenderC;

  components Rf1aActiveMessageC;
  Test.Rf1aPacket -> Rf1aActiveMessageC;

  

}
