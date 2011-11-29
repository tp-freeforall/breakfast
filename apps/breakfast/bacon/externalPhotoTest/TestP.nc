module TestP{
  uses interface Boot;
  uses interface Leds;
  uses interface UartStream;
  uses interface StdControl as UartControl;
  uses interface Read<uint16_t>;
  uses interface Timer<TMilli>;
  uses interface Read<uint16_t> as ReadInternal;
  uses interface SplitControl as InternalControl;
} implementation {
  bool keepSampling = FALSE;

  event void Boot.booted(){
    call UartControl.start();
    call InternalControl.start();
    printf("\n\rExternal Photosensor test\n\r");
    printf("s: Sample\n\r");
    printf("g: toggle SD pin from gnd to input\n\r");
    printf("v: toggle VCC from 3.0 to nc\n\r");
    printf("p: toggle P1.0 direction \n\r");
    printf("P: toggle P1.0 out \n\r");
    printf("q: quit/reset\n\r");
    //vcc: from VCC1WB
    P3OUT |= BIT7;
    P3DIR |= BIT7;
    //p1.1 = shutdown pin
    //default: Out, gnd
    P1DIR |= BIT1;
    P1OUT &= ~BIT1;
    //when input: pulldown
    P1REN |= BIT1;
    P1REN &= ~BIT1;

    //p1.0 = where sensor vcc is connected when vcc1wb is open
    P1DIR |= BIT0;
    P1OUT &= ~BIT0;

    
    //I don't see why this has to be done manually.
    P2SEL |= BIT4;
  }

  task void sample(){
    printf("Read: %x\n\r", call Read.read());
  }

  task void startSample(){
    printf("Sampling. \n\r");
    keepSampling = TRUE;
    post sample();
  }

  task void stopSample(){
    printf("stop.\n\r");
    keepSampling = FALSE;
  }

  task void toggleSD(){
    P1DIR ^= BIT1;
    printf("Toggled shutdown (DIR=%x)\n\r", 0x01 & (P1DIR >> 1));
  }

  task void toggleVCC(){
    P3OUT ^= BIT7;
    printf("Toggled VCC (1WBEN = %x)\n\r", 0x01 & (P3OUT >> 7));
  }

  event void Timer.fired(){
    if (keepSampling){
      printf("Read: %x\n\r", call Read.read());
    } else{
      printf("Skip.\n\r");
    }
  }

  task void readInternal(){
    call ReadInternal.read();
  }

  event void ReadInternal.readDone(error_t err, uint16_t val){
    printf("I R: %x Value: %d\n\r", err, val);
    call Timer.startOneShot(2048);
  }

  event void Read.readDone(error_t err, uint16_t val){
    printf("X R: %x SD: %x VCC: %x P2.4DIR: %x P2.4SEL: %x P2MAP4: %x Value: %d\n\r", err, 
      0x01 & (P1DIR >>1), 0x01 & (P3OUT >> 7),
      0x01 & (P2DIR >>4), 0x01 & (P2SEL >> 4),
      P2MAP4,
      val);
    //call Timer.startOneShot(2048);
    post readInternal();
  }

  task void toggleP1Dir(){
    P1DIR ^= BIT0;
    printf("P1.0 Dir: %x\n\r", P1DIR&0x01);
  }

  task void toggleP1Out(){
    P1OUT ^= BIT0;
    printf("P1.0 Out: %x\n\r", P1OUT&0x01);
  }

  async event void UartStream.receivedByte(uint8_t b){
    switch(b){
      case 'q':
        WDTCTL = 0;
        break;
      case 's':
        post startSample();
        break;
      case 'S':
        post stopSample();
        break;
      case 'g':
        post toggleSD();
        break;
      case 'v':
        post toggleVCC();
        break;
      case 'p':
        post toggleP1Dir();
        break;
      case 'P':
        post toggleP1Out();
        break;
      case '\r':
        printf("\n\r");
        break;
      default:
        printf("%c", b);
    }
  }
  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){}
  async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t err){}

  event void InternalControl.startDone(error_t err){}
  event void InternalControl.stopDone(error_t err){}
}
