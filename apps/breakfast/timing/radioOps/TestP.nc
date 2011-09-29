module TestP {
  uses {
    interface Boot;
    interface AMSend;
    interface SplitControl;
    interface Packet;
    interface HplMsp430GeneralIO as MarkerPin;
    interface HplMsp430GeneralIO as TimerPin;
    interface Timer<TMilli> as StartPauseTimer;
    interface Timer<TMilli> as SendPauseTimer;
    interface Timer<TMilli> as StopPauseTimer;
    interface Leds;
  }
}
implementation {
  message_t m;

  event void Boot.booted() {
    call TimerPin.makeOutput();
    call TimerPin.set();
    call MarkerPin.makeOutput();
    call MarkerPin.clr();
    call StartPauseTimer.startOneShot(TEST_INTERVAL);
    //this turns off all leds on the surf platform (when a bacon binary is on it)
    call Leds.set(7);
    //call Leds.set(1);
  }
   
  event void StartPauseTimer.fired() {
    call TimerPin.clr();
    call MarkerPin.set();
    call MarkerPin.clr();
    call SplitControl.start();
    //call Leds.set(2);
  }

  event void SplitControl.startDone(error_t err) {
    //call Leds.set(3);
    call SendPauseTimer.startOneShot(SEND_PAUSE);
  }
  task void doSend() {
    error_t e;
    //call Leds.set(4);
    e = call AMSend.send(AM_BROADCAST_ADDR, &m, PACKET_SIZE);
    //printf("AMSend.send: %d\n", e);
    //printfflush();
    if (e != SUCCESS) {
      post doSend();
    }
  }
  event void SendPauseTimer.fired() {
    post doSend();
  }

  event void AMSend.sendDone(message_t *msg, error_t err) {
    //call Leds.set(5);
    call StopPauseTimer.startOneShot(STOP_PAUSE);
  }

  event void StopPauseTimer.fired() {
    //call Leds.set(6);
    call SplitControl.stop();
  }

  event void SplitControl.stopDone(error_t err) {
    //call Leds.set(7);
    //call Leds.led0Toggle();
    call TimerPin.set();
    call StartPauseTimer.startOneShot(TEST_INTERVAL);
  }

  
}
