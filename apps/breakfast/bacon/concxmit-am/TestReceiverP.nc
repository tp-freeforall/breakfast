module TestReceiverP {
  uses interface Boot;
  uses {
    interface Receive as RadioReceive;
    interface Receive as ReceiveCmd;
    interface AMSend as ReportSend;
    interface SplitControl;
    interface SplitControl as SerialSplitControl;
    interface Leds;
    interface Rf1aMulti;
    interface GeneralIO as SendReadyPin;
    interface GeneralIO as NextPin;
    interface Timer<TMilli>;
    interface Rf1aPhysicalMetadata;
    interface BusyWait<TMicro, uint16_t>;
  }
} implementation {
  enum{
    S_STARTING,
    S_ERROR,
    S_READY,
    S_TRY_NEXTCONFIG,
    S_START_NEXTCONFIG,
    S_SEND_READY,
    S_RADIO_STARTING,
    S_RADIO_STOPPING,
    S_SEND_START,
    S_WAITING,
    S_REPORTING,
    S_SEND_READY_WAITING,
  };
  rf1a_metadata_t metadata;
  message_t rmsg;
  message_t smsg;
  uint8_t state = S_STARTING;
  uint8_t radioOn = FALSE;
  uint16_t seqNum = 0;

  uint16_t sendCount;
  uint16_t send1Offset;

  uint16_t SEND_READY_WAIT = 10;
  uint16_t period = 16384;

  event void Boot.booted(){
    //P2.2: TA1 CCR1 compare output
    P2DIR |= BIT2;
    P2SEL |= BIT2;
    //output mode 6: negative pulse at end of cycle
    TA1CCTL1 = OUTMOD_6;
    TA1CTL = TASSEL_3 | MC__UP;

    call NextPin.makeOutput();
    call NextPin.clr();
    call SendReadyPin.makeOutput();
    call SendReadyPin.clr();
    call SerialSplitControl.start();
  }

  event void SerialSplitControl.startDone(error_t err){
    state = S_READY;
  }
  
  task void tryNextConfigTask();
  task void nextConfigTask();
  task void sendTask();

  event message_t* ReceiveCmd.receive(message_t* msg, void* pl, uint8_t len){ 
    cmd_t* cmd = (cmd_t*) pl;
    switch (cmd->cmd){
      //next config: post task to switch/bounce next pin
      case CONCXMIT_CMD_NEXT:
        post tryNextConfigTask();
        state = S_TRY_NEXTCONFIG;
        break;
      //send: copy contents
      case CONCXMIT_CMD_SEND:
        if (state != S_SEND_READY){
          state = S_ERROR;
        } else {
          call Leds.led0Toggle();
          state = S_SEND_START;
          sendCount = cmd->sendCount;
          send1Offset = cmd->send1Offset;
          post sendTask();
        }
        break;
      default:
        state = S_ERROR;
    }
    return msg;
  }
  
  //tell senders to switch, switch self, start radio.
  task void nextConfigTask(){
    call NextPin.set();
    call NextPin.clr();
    call Rf1aMulti.setConfig( ((call Rf1aMulti.getConfig())+1) % (call Rf1aMulti.getNumConfigs()));
    call SplitControl.start();
    seqNum = 0;
    state = S_RADIO_STARTING;
  }

  task void tryNextConfigTask(){
    if (radioOn){
      state = S_RADIO_STOPPING;
      call SplitControl.stop();
    }else{
      state = S_START_NEXTCONFIG;
      post nextConfigTask();
    }
  }

  event void SplitControl.stopDone(error_t err){
    radioOn = FALSE;
    state = S_START_NEXTCONFIG;
    post nextConfigTask();
  }

  event void SplitControl.startDone(error_t err){
    state = S_SEND_READY;
    radioOn = TRUE;
  }

  task void sendTask(){
    call Leds.led1Toggle();
    if (sendCount != 0){
      call Leds.led2Toggle();
      state = S_SEND_READY_WAITING;
      call SendReadyPin.set();
      call SendReadyPin.clr();
      call Timer.startOneShot(SEND_READY_WAIT);
    }else{
      //stop timer
      TA1CCR0 = 0;
      state = S_SEND_READY;
    }
  }

  event void Timer.fired(){
    receiver_report_t* rpt = (receiver_report_t*)(call
      ReportSend.getPayload(&smsg, sizeof(receiver_report_t)));
    switch(state){
      case S_SEND_READY_WAITING:
        //this indicates that we've given the senders time to queue up
        //a packet, and they should send them now.
        state = S_WAITING;
        atomic{
          //start PWM: negative pulse with width=send1Offset cycles of
          //  SMCLK, at _end_ of period
          //pulse 
          //stop it
          TA1CCR0 = 0;
          //set pulse width
          TA1CCR1 = period - 1 - send1Offset;
          //and off it goes
          TA1CCR0 = period - 1;
        }
        call Timer.startOneShot(SEND_TIMEOUT);
        sendCount--;
        break;
      case S_WAITING:
        //this indicates that timeout occurred with no response received
        state = S_REPORTING;
        rpt -> configId = (call Rf1aMulti.getConfigId());
        rpt -> seqNum = seqNum;
        rpt -> received = 0;
        rpt -> rssi = 0;
        rpt -> lqi = 0;
        rpt -> send1Offset = send1Offset;

        seqNum++;
        call ReportSend.send(AM_BROADCAST_ADDR, &smsg, sizeof(receiver_report_t));
        break;
      default:
    }

  }

  event void ReportSend.sendDone(message_t* msg, error_t err){
    state = S_SEND_START;
    //TODO: may have to introduce a delay here so that senders can
    //  queue up the next packet, etc
    post sendTask();
  }

  event message_t* RadioReceive.receive(message_t* msg, void* pl, uint8_t len){ 
    receiver_report_t* rpt = (receiver_report_t*)(call
      ReportSend.getPayload(&smsg, sizeof(receiver_report_t)));
    call Timer.stop();
    call Rf1aPhysicalMetadata.store(&metadata);
    state = S_REPORTING;
    rpt -> configId = (call Rf1aMulti.getConfigId());
    rpt -> seqNum = seqNum;
    rpt -> received = 1;
    rpt -> rssi = call Rf1aPhysicalMetadata.rssi(&metadata);
    rpt -> lqi = call Rf1aPhysicalMetadata.rssi(&metadata);
    rpt -> send1Offset = send1Offset;

    seqNum ++;
    call ReportSend.send(AM_BROADCAST_ADDR, &smsg, sizeof(receiver_report_t));
    return msg;
  }

  event void SerialSplitControl.stopDone(error_t err){}
}
