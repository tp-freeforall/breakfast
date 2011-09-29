#include "RadioTest.h"

#include "printf.h"

module RadioTestP {
  uses{
    interface Boot;
    interface Timer<TMilli> as SendTimer;
    interface Leds;
    interface AMSend as ProbeSend;
    interface AMSend as ReportSend;
    interface Receive;
    interface SplitControl as RadioSplitControl;
    interface Packet;
    interface Rf1aPacket;
  }
} implementation {
  enum {
    S_OFF = 0x00,
    S_ON = 0x01,
    S_IDLE = 0x02,
    S_PROBING = 0x03,
    S_RECEIVE = 0x04,
    S_REPORTING = 0x05,
    S_PAUSE = 0x06,
    S_MAX = 0x30,
  };


  message_t m;
  uint32_t sn;
  uint8_t state = S_OFF;
 
  void setState(uint8_t newState) {
    if (state < S_MAX ){
      state = newState;
      call Leds.set(state);
    } else {
      //ignore, already in error state
    }
  }

  event void Boot.booted() {
    if (call RadioSplitControl.start() == SUCCESS){
      setState(S_ON);
    }
  }

  error_t doSend() {
    probe_t* payload = (probe_t*)(call Packet.getPayload(&m, sizeof(probe_t)));
    error_t e;
    call Packet.clear(&m);
    payload -> sn = sn++;
    e = call ProbeSend.send(AM_BROADCAST_ADDR, &m, sizeof(probe_t));
    return e;
  }

  event void RadioSplitControl.startDone(error_t err) {
    if (state == S_ON) {
      if (err == SUCCESS) {
        setState(S_IDLE);
        if( IS_SENDER && (doSend() == SUCCESS) ){
          setState(S_PROBING);
        } else {
          setState(0x47);
        }
      } else {
        setState(0x37);
      }
    }
  }

  event void RadioSplitControl.stopDone(error_t err) {
    setState(S_OFF);
  }

  event void ProbeSend.sendDone(message_t* msg, error_t error) {
    if (state == S_PROBING) {
      if (error == SUCCESS) {
        setState(S_PAUSE);
        call SendTimer.startOneShot(SEND_INTERVAL);
      } else {
        setState(0x57);
      }
    } else {
      setState(0x67);
    }
  }

  event void ReportSend.sendDone(message_t* msg, error_t err) {
    if (state == S_REPORTING) {
      if (err == SUCCESS){
        setState(S_IDLE);
      } else {
        setState(0xc7);
      }
    } else {
      setState(0xb7);
    }
  }

  event void SendTimer.fired() {
    if (state == S_PAUSE) {
      if (doSend() == SUCCESS){
        setState(S_PROBING);
      } else {
        setState(0x87);
      }
    } else {
      setState(0x77);
    }
  }
 
  event message_t* Receive.receive(message_t* msg, void* payload, error_t err) {
    if (state == S_IDLE) {
      probe_t* p = (probe_t*)payload;
      report_t* r = (report_t*)(call Packet.getPayload(&m, sizeof(report_t)));
      call Packet.clear(&m);
      r -> probe = *p;
      r -> rssi = call Rf1aPacket.rssi(msg);
      r -> lqi = call Rf1aPacket.lqi(msg);
      //TODO include power
      printf("[%lu, %lu, %d, %d]\n", p->bn, p->sn, r->rssi, r->lqi);
      printfflush();
      if (call ReportSend.send(AM_BROADCAST_ADDR, &m, sizeof(report_t)) == SUCCESS){
        setState(S_REPORTING);
      } else {
        setState(0x97);
      }
    } else {
      setState(0xa7);
    }
    return msg;
  }
  
}
