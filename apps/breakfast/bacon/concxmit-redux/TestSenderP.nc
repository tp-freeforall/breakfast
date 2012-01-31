//#include "printf.h"

module TestSenderP {
  uses interface Boot;
  uses {
    interface AMSend as RadioSend;
    interface SplitControl;
    interface Leds;
    interface GpioInterrupt as SendInterrupt;
    interface GeneralIO as SendPin;
    interface GpioInterrupt as EnableInterrupt;
    interface GeneralIO as EnablePin;
    interface GpioInterrupt as ResetInterrupt;
    interface GeneralIO as ResetPin;
    interface DelayedSend;
    interface HplMsp430Rf1aIf as Rf1aIf;
  }
  uses interface HplMsp430GeneralIO as HplResetPin;
  uses interface HplMsp430GeneralIO as HplEnablePin;
  uses interface Timer<TMilli>;
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
    S_ENABLED           = 0x0D,
  };

  message_t rmsg;

  uint8_t state = S_STARTING;
  uint16_t seqNum = 0;

  task void loadNextTask();

  event void Boot.booted(){
    printf("Booted\n\r");
    #ifdef SENDER1
    printf("Sender 1 (FE)\n\r");
    #else
    printf("Sender 2 (RE)\n\r");
    #endif
    //call Timer.startOneShot(128);
    call SendPin.makeInput();

    call EnablePin.makeInput();
    call HplEnablePin.setResistor(MSP430_PORT_RESISTOR_PULLDOWN);
    call EnableInterrupt.enableRisingEdge();

    call ResetPin.makeInput();
    call HplResetPin.setResistor(MSP430_PORT_RESISTOR_PULLDOWN);
    call ResetInterrupt.enableRisingEdge();

    call SplitControl.start();
  }

  uint8_t counter = 0;
  event void Timer.fired(){
    //call Leds.set(counter);
    counter++;
    printf("Alive: %d %x\n\r", counter, state);
    call Timer.startOneShot(2048);
  }

  task void resetInterruptTask(){
    printf("RESET\n\r");
    //trigger reset
    WDTCTL=0;
  }

  async event void ResetInterrupt.fired(){
    post resetInterruptTask();
  }

  event void SplitControl.startDone(error_t err){
    //printf("Radio on\n\r");
    atomic{
      state = S_NEED_LOAD;
      post loadNextTask();
      //Sender 1 transmits at lower power to reduce impact of catpure
      //effect
      #ifdef SENDER1
      call Rf1aIf.writeSinglePATable(TX_POWER_1);
      #else
      call Rf1aIf.writeSinglePATable(TX_POWER_2);
      #endif
    }
  }

  task void loadNextTask(){
    test_packet_t* pl = (test_packet_t*)call RadioSend.getPayload(&rmsg, sizeof(test_packet_t));
    error_t error;
    pl -> seqNum = seqNum;
    atomic{
      state = S_LOADING;
    }
    error = call RadioSend.send(AM_BROADCAST_ADDR, &rmsg,
      sizeof(test_packet_t));
    //printf("RS.send %x \n\r", error);
  }

  task void unexpectedSendReady(){
    printf("Unexpected sendReady received\n\r");
  }

  async event void DelayedSend.sendReady(){
    if (state == S_LOADING){
      state = S_LOADED;
    } else {
      post unexpectedSendReady();
    }
  }

  task void reportEnableInterrupt(){
    //printf("EI\n\r");
  }

  async event void EnableInterrupt.fired(){
    post reportEnableInterrupt();
    if (state == S_LOADED){
      //the "send" pulse is negative, so sender1 should fire at the
      //falling edge
      #ifdef SENDER1
        call SendInterrupt.enableFallingEdge();
      #else
        call SendInterrupt.enableRisingEdge();
      #endif
      state = S_ENABLED;
    }
  }

  task void reportSendInterrupt(){
    //printf("SI\n\r");
  }

  async event void SendInterrupt.fired(){
    post reportSendInterrupt();
    if (state == S_ENABLED){
      //turn off send interrupt until we're done sending/reporting this
      //one
      call SendInterrupt.disable();
      state = S_SENDING;
      call DelayedSend.completeSend();
    } else {
      state = S_ERROR;
    }
  }

  task void reportTask();
  event void RadioSend.sendDone(message_t* msg, error_t err){
    //printf("SEND DONE\n\r");
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
    printf("TX %u\n\r", seqNum);
    seqNum++;
    state = S_NEED_LOAD;
    post loadNextTask();
  }

  event void SplitControl.stopDone(error_t err){
  }

}
