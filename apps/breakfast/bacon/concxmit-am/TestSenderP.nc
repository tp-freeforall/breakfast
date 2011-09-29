//#include "printf.h"

module TestSenderP {
  uses interface Boot;
  uses {
    interface AMSend as RadioSend;
    interface AMSend as ReportSend;
    interface SplitControl;
    interface SplitControl as SerialSplitControl;
    interface Leds;
    interface Rf1aMulti;
    interface GpioInterrupt as NextInterrupt;
    interface GpioInterrupt as SendInterrupt;
    interface GpioInterrupt as SendReadyInterrupt;
    interface GeneralIO as NextPin;
    interface GeneralIO as SendReadyPin;
    interface GeneralIO as DebugPin;
    interface HplMsp430GeneralIO as HplSendReadyPin;
    interface GeneralIO as SendPin;
    interface DelayedSendRf1aPhysical;
    interface HplMsp430Rf1aIf as Rf1aIf;
  }
} implementation {
  enum{
    S_STARTING          = 0x01,
    S_READY             = 0x02,
    S_START_NEXTCONFIG  = 0x03,
    S_RADIO_STOPPING    = 0x04,
    S_RADIO_STARTING    = 0x05,
    S_NEED_LOAD         = 0x06,
    S_LOADING           = 0x07,
    S_LOADED            = 0x08,
    S_WAITING_FOR_SEND  = 0x09,
    S_SENDING           = 0x0A,
    S_REPORTING         = 0x0B,
    S_ERROR             = 0x0C,
  };

  rf1a_metadata_t metadata;
  message_t rmsg;
  message_t smsg;

  uint8_t state = S_STARTING;
  uint8_t radioOn = FALSE;
  uint16_t seqNum = 0;

  event void Boot.booted(){
    call Leds.set(3);
    call NextInterrupt.enableRisingEdge();
    call NextPin.makeInput();

    call HplSendReadyPin.selectIOFunc();
    call SendReadyPin.makeInput();
    
    call SendPin.makeInput();
    call DebugPin.makeOutput();
    call DebugPin.clr();

    call SerialSplitControl.start();
  }

  event void SerialSplitControl.startDone(error_t err){
    call Leds.set(0);
    atomic{
      state = S_READY;
    }
    //printf("serial started\n");
    //printf("S %x\n", state);
    //printfflush();
  }

  task void tryNextConfigTask();
  task void nextConfigTask();
  task void loadNextTask();
 
  task void reportNI(){
    //printf("ni.f\n");
    //printf("S %x\n", state);
    //printfflush();
  }
  task void reportSRI(){
    //printf("sri.f\n");
    //printf("S %x\n", state);
    //printfflush();
  }
  task void reportSI(){
    //printf("si.f\n");
    //printf("S %x\n", state);
    //printfflush();
  }
  async event void NextInterrupt.fired(){
    post reportNI();
    post tryNextConfigTask();
  }

  //stop radio if needed, then switch configs and restart it.
  task void tryNextConfigTask(){
    //printf("tnct\n");
    //printf("S %x\n", state);
    //printfflush();
    if (radioOn){
      //TODO: might need to cancel the last transmission if it doesn't
      //get cleared out correctly at stop
      atomic{
        state = S_RADIO_STOPPING;
        call SplitControl.stop();
      }
    }else{
      atomic{
        state = S_START_NEXTCONFIG;
        post nextConfigTask();
      }
    }
  }

  event void SplitControl.stopDone(error_t err){
    //printf("sc.stopd %d\n", err);
    //printf("S %x\n", state);
    //printfflush();
    atomic{
      radioOn = FALSE;
      state = S_START_NEXTCONFIG;
      post nextConfigTask();
    }
  }

  task void nextConfigTask(){
    //printf("nct\n");
    //printf("S %x\n", state);
    //printfflush();
    atomic{
      call Rf1aMulti.setConfig( ((call Rf1aMulti.getConfig())+1) % (call Rf1aMulti.getNumConfigs()));
      call SplitControl.start();
      seqNum = 0;
      state = S_RADIO_STARTING;
      call Leds.set(1);
    }
  }

  event void SplitControl.startDone(error_t err){
    //printf("sc.startd %d\n", err);
    //printf("S %x\n", state);
    //printfflush();
    atomic{
      state = S_NEED_LOAD;
      call SendReadyInterrupt.enableFallingEdge();
      radioOn = TRUE;
      //Sender 1 transmits at lower power to reduce impact of catpure
      //effect
      #ifdef SENDER1
      call Rf1aIf.writeSinglePATable(TX_POWER_1);
      #else
      call Rf1aIf.writeSinglePATable(TX_POWER_2);
      #endif
    }
  }

  error_t rserr = 0xdc;
  
  task void reportRserr(){
    //printf("rs.s err: %x\n", rserr);
    //printfflush();
  }

  task void loadNextTask(){
    test_packet_t* pl = (test_packet_t*)call RadioSend.getPayload(&rmsg, sizeof(test_packet_t));
    //printf("lnt\n");
    //printf("S %x\n", state);
    //printfflush();
    pl -> seqNum = seqNum;
    atomic{
      state = S_LOADING;
    }
    //printf("S %x\n", state);
    //printfflush();

    rserr = call RadioSend.send(AM_BROADCAST_ADDR, &rmsg, sizeof(test_packet_t));
    post reportRserr();
  }

  async event void SendReadyInterrupt.fired(){
    call DebugPin.set();
    post reportSRI();
    call Leds.set(2);
    if (state == S_NEED_LOAD){
      post loadNextTask();
      call SendReadyInterrupt.disable();
    } else {
      state = S_ERROR;
    }
  }
  
  async event void SendInterrupt.fired(){
    //turn off send interrupt until next sendready interrupt
    //received
    call SendInterrupt.disable();
    if (state == S_LOADED){
      state = S_SENDING;
      call DelayedSendRf1aPhysical.completeSend();
    } else {
      state = S_ERROR;
    }
    post reportSI();
    call Leds.set(3);
  }

  task void reportTask();

  event void RadioSend.sendDone(message_t* msg, error_t err){
    //printf("rs.sd\n");
    //printf("S %x\n", state);
    //printfflush();
    atomic{
      if (state == S_SENDING){
        state = S_REPORTING;
      } else {
        state = S_ERROR;
      }
      post reportTask();
    }
  }

  task void reportTask(){
    sender_report_t* rpt = call ReportSend.getPayload(&smsg, sizeof(sender_report_t));
    //printf("rt\n");
    //printf("S %x\n", state);
    //printfflush();
    rpt -> configId = call Rf1aMulti.getConfigId();
    rpt -> seqNum = seqNum;
    call ReportSend.send(AM_BROADCAST_ADDR, &smsg, sizeof(sender_report_t));
  }

  event void ReportSend.sendDone(message_t* msg, error_t err){
    //printf("rep.sd\n");
    //printf("S %x\n", state);
    //printfflush();
    atomic{
      state = S_NEED_LOAD;
      call SendReadyInterrupt.enableFallingEdge();
      seqNum ++;
    }
  }

  event void SerialSplitControl.stopDone(error_t err){}
  task void reportDSSR(){
    //printf("DS.sr\n");
    //printf("S %x\n", state);
    //printfflush();
  }

  async event void DelayedSendRf1aPhysical.sendReady(){
    call DebugPin.clr();
    if (state == S_LOADING){
      state = S_LOADED;
      //the "send" pulse is negative, so sender1 should fire at the
      //falling edge
      #ifdef SENDER1
        call SendInterrupt.enableFallingEdge();
      #else
        call SendInterrupt.enableRisingEdge();
      #endif
    } else {
      //seem to get these during the send process itself?
      call DelayedSendRf1aPhysical.completeSend();
    }
    post reportDSSR();
  }
}
