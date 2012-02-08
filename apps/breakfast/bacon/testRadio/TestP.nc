#include <stdio.h>
#include "radioTest.h"

module TestP{
  uses interface Boot;
  uses interface Leds;
  uses interface Timer<TMilli>;
  uses interface Timer<TMilli> as IndicatorTimer;

  uses interface StdControl as SerialControl;
  uses interface UartStream;

  uses interface AMSend;
  uses interface AMPacket;
  uses interface Receive;
  uses interface SplitControl;
 
  uses interface HplMsp430Rf1aIf as Rf1aIf;
  uses interface Rf1aPhysicalMetadata;
  uses interface Rf1aPhysical;

  uses interface CC1190;
  uses interface StdControl as AmpControl;

} implementation {
  bool needsRestart;

  bool radioBusy = FALSE;

  norace test_settings_t settings;
  uint32_t rxCounter = 0;
  //uint8_t prrBuf[PRR_BUF_LEN];
  //uint8_t prrIndex = 0;

  message_t msg_internal;
  message_t* msg = &msg_internal;

  rf1a_metadata_t metadata;

  void printSettings(test_settings_t* s){
    printf(" (seqNum, %u)", s->seqNum);
    printf(" (isSender, %x)", s->isSender);
    printf(" (power, %d)", POWER_LEVELS[s->powerIndex]);
    printf(" (hgm, %x)", s->hgm);
    printf(" (channel, %d)", s->channel);
    printf(" (report, %x)", s->report);
    printf(" (ipi, %u)", s->ipi);
    printf(" (hasFe, %x)", s->hasFe);
    printf("\n\r");
  }

  void printMinimal(test_settings_t* s){
    printf("%u %d %x %d %x\n", s->seqNum, POWER_LEVELS[s->powerIndex],
      s->hgm, s->channel, s->hasFe);
  }

  task void printSettingsTask(){
    printf("SETTINGS");
    printSettings(&settings);
  }

  event void Boot.booted(){
    call SerialControl.start();
    #ifndef QUIET
    printf("Radio Test app\n\r t: toggle RX/TX mode\n\r p: increment TX power\n\r h: toggle cc1190 HGM\n\r c: increment channel\n\r i: toggle IPI (cont. v. report-able)\n\r r: toggle serial reporting\n\r q: reset\n\r");
    #endif
    settings.seqNum = 0;
    settings.isSender = IS_SENDER;
    settings.powerIndex = POWER_INDEX;
    settings.hgm = HGM;
    settings.channel = CHANNEL;
    settings.report = REPORT;
    if (USE_LONG_IPI){
      settings.ipi = LONG_IPI;
    } else{
      settings.ipi = SHORT_IPI;
    }
    settings.hasFe = HAS_FE;

    //memset(prrBuf, 0, PRR_BUF_LEN);

    //post printSettingsTask();
    call SplitControl.start();
  }

  task void restartRadio(){
    call Timer.stop();
    call SplitControl.stop();
  }

  event void SplitControl.stopDone(error_t error){
    call SplitControl.start();
  }


  event void SplitControl.startDone(error_t error){
    needsRestart = FALSE;
    #ifndef QUIET
    printf("Radio on\n\r");
    #endif
    call AmpControl.start();
    call Rf1aPhysical.setChannel(settings.channel);
    call Leds.led0Off();
    call Leds.led1Off();
    call Leds.led2Off();
    if (settings.isSender){
      settings.seqNum = 0;
      memcpy(call AMSend.getPayload(msg, sizeof(test_settings_t)),
        &settings, sizeof(test_settings_t));
      call CC1190.TXMode(settings.hgm);
      call Rf1aIf.writeSinglePATable(POWER_SETTINGS[settings.powerIndex]);
      call Timer.startPeriodic(settings.ipi);
      call IndicatorTimer.stop();
    }else{
      call CC1190.RXMode(settings.hgm);
      call IndicatorTimer.startPeriodic(256);
    }
  }

  uint8_t indicatorSlot = 0;
  #define RX_LEVELS 5
  #define LEVEL_5 100UL
  #define LEVEL_4 95UL
  #define LEVEL_3 90UL
  #define LEVEL_2 50UL
  #define LEVEL_1 20UL

  #define LED_ON 2
  #define LED_OFF 0
  #define LED_BLINK 1
  
  #define THRESH_1 (LEVEL_1*100UL* MAX_RX_COUNTER)/(10000UL)
  #define THRESH_2 (LEVEL_2*100UL* MAX_RX_COUNTER)/(10000UL)
  #define THRESH_3 (LEVEL_3*100UL* MAX_RX_COUNTER)/(10000UL)
  #define THRESH_4 (LEVEL_4*100UL* MAX_RX_COUNTER)/(10000UL)
  #define THRESH_5 (LEVEL_5*100UL* MAX_RX_COUNTER)/(10000UL)

  uint32_t thresholds[RX_LEVELS+1] = {0, THRESH_1, THRESH_2, THRESH_3,
    THRESH_4, THRESH_5};

  event void IndicatorTimer.fired(){
    uint8_t level;
    uint8_t led0 = LED_OFF;
    uint8_t led1 = LED_OFF;
    uint8_t led2 = LED_OFF;
    uint8_t ledState = 0;

    call Leds.set(0);
    for (level = RX_LEVELS; level != 0 ;level--){
      if (rxCounter >= thresholds[level]){
        break;
      }
    }
    if (level > 0){
      led0 = LED_ON;
    }else{
      led0 = LED_BLINK;
    }

    if (level > 2){
      led1 = LED_ON;
    }else if (level > 1){
      led1 = LED_BLINK;
    }

    if (level > 4 ){
      led2 = LED_ON;
    }else if (level > 3){
      led2 = LED_BLINK;
    }

    //blink | on: set led
    ledState |= (led0 == LED_OFF)?(0 << 0):(1<<0);
    ledState |= (led1 == LED_OFF)?(0 << 1):(1<<1);
    ledState |= (led2 == LED_OFF)?(0 << 2):(1<<2);
    //blink & even slot: clear led
    if ((indicatorSlot % 2) == 0){
      ledState &= ~((led0 == LED_BLINK)?(1<<0):(0<<0));
      ledState &= ~((led1 == LED_BLINK)?(1<<1):(0<<1));
      ledState &= ~((led2 == LED_BLINK)?(1<<2):(0<<2));
    }
    call Leds.set(ledState);
    indicatorSlot++;
  }

  uint16_t lastSN;
//  uint32_t lastIpi;
//  #define IPI_DELAY 16
//
  event void Timer.fired(){
    if (needsRestart){
      post restartRadio();
    }else{
      if (settings.isSender){
        if (!radioBusy){
          radioBusy = TRUE;
          call AMSend.send(AM_BROADCAST_ADDR, msg,
            sizeof(test_settings_t));
        }else{
          printf("TOO FAST\n\r");
        }
      }else{
        lastSN++;
//        printf("lost %lu (%u?)\n\r", call Timer.getNow(), lastSN);
//        call Timer.startOneShot(lastIpi + IPI_DELAY);
//  
        if (settings.report){
          #ifdef REPORT_LOST
          printf("LOST\n\r");
          #endif
        }
        if (rxCounter > 0){
          rxCounter --;
        }
      }
    }
  }

  event void AMSend.sendDone(message_t* msg_, error_t err){
    test_settings_t* pkt = call AMSend.getPayload(msg,
      sizeof(test_settings_t));
    radioBusy = FALSE;
    if (settings.report){
      //printf("TX %lu", call Timer.getNow());
      printf("TX ");
      #ifdef QUIET
      printf("%d ", TOS_NODE_ID);
      printMinimal(pkt);
      #else
      printSettings(pkt);
      #endif

    }
    if ((pkt->ipi == LONG_IPI) || 
      ((pkt->ipi == SHORT_IPI) 
        && ((pkt->seqNum % LONG_IPI) == 0))){
      call Leds.led0Toggle();
      call Leds.led1Toggle();
      call Leds.led2Toggle();
    }
    pkt->seqNum++;

    if (needsRestart){
      needsRestart = FALSE;
      post restartRadio();
    } else{
      //call Timer.startOneShot(pkt->ipi);
    }
  }

  bool firstRX = TRUE;
  event message_t* Receive.receive(message_t* msg_, void* pl, uint8_t len){ 
    test_settings_t* pkt = (test_settings_t*)pl;
    uint32_t rxTime = call Timer.getNow();
    uint32_t lostAt = rxTime + ((pkt->ipi)/2);

    //1 received
    rxCounter++;
//    //subtract any intervening ones missed
//    if (! firstRX){
//      rxCounter -= (pkt->seqNum - lastSN - 1); 
//    } 
//    firstRX = FALSE;

    lastSN = pkt->seqNum;
    if (rxCounter > MAX_RX_COUNTER){
      rxCounter = MAX_RX_COUNTER;
    }

    //TODO: periodic timer component seems to be messed up: in some
    //      cases it starts immediately and fires every few ms.
    //printf("at %lu spa %lu %u\n\r", rxTime, lostAt, pkt->ipi);
    call Timer.startPeriodicAt(lostAt, (pkt->ipi));

    call Rf1aPhysicalMetadata.store(&metadata);
    if (settings.report){
      printf("RX ");
      #ifdef QUIET
      printf("%d ", TOS_NODE_ID);
      printf("%x ", settings.hgm);
      printf("%d ", call Rf1aPhysicalMetadata.rssi(&metadata));
      printf("%d ", call Rf1aPhysicalMetadata.lqi(&metadata));
      printf("%x ", HAS_FE);
      printf("%d ", call AMPacket.source(msg_));
      printMinimal(pkt);
      #else
      printf(" (rssi, %d)", call Rf1aPhysicalMetadata.rssi(&metadata));
      printf(" (lqi, %d)", call Rf1aPhysicalMetadata.lqi(&metadata));
      printSettings(pkt);
      #endif
    }

    return msg_;
  }

  task void requestRestart(){
    needsRestart = TRUE;
  }

  async event void UartStream.receivedByte(uint8_t byte){
    switch ( byte ){
      case 't':
        settings.isSender = !settings.isSender;
        post printSettingsTask();
        post restartRadio();
        break;

      case 'p':
        settings.powerIndex = (settings.powerIndex+1)%NUM_POWER_LEVELS;
        post printSettingsTask();
        post requestRestart();
        break;

      case 'h':
        settings.hgm = !settings.hgm;
        post printSettingsTask();
        post requestRestart();
        break;

      case 'c':
        settings.channel = (settings.channel + CHANNEL_INCREMENT) %NUM_CHANNELS;
        post printSettingsTask();
        post requestRestart();
        break;

      case 'i':
        if (settings.ipi == SHORT_IPI){
          settings.ipi = LONG_IPI;
        }else{
          settings.ipi = SHORT_IPI;
        }
        post printSettingsTask();
        post requestRestart();
        break;

      case 'r':
        settings.report = !settings.report;
        post printSettingsTask();
        post restartRadio();
        break;

      case 'q':
        WDTCTL = 0;
        break;
      case '\r':
        printf("\n\r");
        break;
      default:
        printf("%c", byte);
        break;
    }
  }
  
  async event void UartStream.receiveDone( uint8_t* buf_, uint16_t len,
    error_t error ){}
  async event void UartStream.sendDone( uint8_t* buf_, uint16_t len,
    error_t error ){}

  async event void Rf1aPhysical.sendDone (int result) { }
  async event void Rf1aPhysical.receiveStarted (unsigned int length) { }
  async event void Rf1aPhysical.receiveDone (uint8_t* buffer,
                                             unsigned int count,
                                             int result) { }
  async event void Rf1aPhysical.receiveBufferFilled (uint8_t* buffer,
                                                     unsigned int count) { }
  async event void Rf1aPhysical.frameStarted () { }
  async event void Rf1aPhysical.clearChannel () { }
  async event void Rf1aPhysical.carrierSense () { }
  async event void Rf1aPhysical.released () { }
 
}
