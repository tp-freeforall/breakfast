#include "RadioTest.h"
#include "printf.h"

module RadioTestSnifferP {
  uses{
    interface Boot;
    interface Leds;
    interface Receive as ReportReceive;
    interface SplitControl as RadioSplitControl;
  }
} implementation {
 
  event void Boot.booted() {
    if (call RadioSplitControl.start() != SUCCESS){
      call Leds.led2On();
    }
  }

  event void RadioSplitControl.startDone(error_t err) {
    if (err != SUCCESS) {
      call Leds.led2On();
    }
  }

  event void RadioSplitControl.stopDone(error_t err) {
  }

  event message_t* ReportReceive.receive(message_t* msg, void* payload, error_t err) {
    report_t* r = (report_t*)payload;
    call Leds.led0Toggle();
    printf("[%u, %lu, %lu, %x, %d, %d]\n", r->probe.node_id, r->probe.bn, r->probe.sn, r->probe.powerLevel, r->rssi, r->lqi);
    printfflush();
    return msg;
  }
  
}
