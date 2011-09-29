#include "bacon_radio_test.h"

module ReceiverP {
  uses interface Boot;
  uses interface Leds;

  uses interface SplitControl;
  uses interface Receive;
  uses interface Packet as RadioPacket;
  uses interface Rf1aPacket;

#ifdef HAS_CC1190
  uses interface CC1190;
  uses interface StdControl as CC1190Control;
#endif

  uses interface SplitControl as SerialSplitControl;
  uses interface AMSend as ReportSend;
  uses interface Packet as SerialPacket;


} implementation {
  message_t _msg;
  message_t* msgPtr;
  bool reporting = FALSE;

  event void Boot.booted(){
    msgPtr = &_msg;
    call SplitControl.start();
  }

  event void SplitControl.startDone(error_t err){
    call SerialSplitControl.start();
  }

  void initCC1190(){
    #ifdef HAS_CC1190
    call CC1190Control.start();
    call CC1190.RXMode(HGM_ENABLED);
    #endif
  }

  event void SerialSplitControl.startDone(error_t err){
    initCC1190();
    //OK, ready to receive
  }


  task void reportRX();

  event message_t *Receive.receive(message_t* msg, void* payload, uint8_t len){
    message_t* swp = msgPtr;
    if (reporting){
      call Leds.set(0x7);
      return msg;
    }
    call Leds.led0Toggle();
    msgPtr = msg;
    reporting = TRUE;
    post reportRX();
    return swp;
  }
  
  message_t smsg;
  task void reportRX(){
    report_t* rpt = (report_t*) (call SerialPacket.getPayload(&smsg, sizeof(report_t)));
    test_payload_t* pl = (test_payload_t*)(call RadioPacket.getPayload(msgPtr, sizeof(test_payload_t)));
    rpt->node_id = pl->node_id;
    rpt->sn = pl->sn;
    rpt->powerLevel = pl->powerLevel;
    rpt->hgmTx = pl->hgm;
    rpt->hgmRx = HGM_ENABLED;
    rpt->rssi = call Rf1aPacket.rssi(msgPtr);
    rpt->lqi = call Rf1aPacket.lqi(msgPtr);
    
    call ReportSend.send(AM_BROADCAST_ADDR, &smsg, sizeof(report_t));
  }

  event void ReportSend.sendDone(message_t* msg, error_t err){
    reporting = FALSE;
  }

  event void SplitControl.stopDone(error_t err){}
  event void SerialSplitControl.stopDone(error_t err){}
}
