module TestP{
  uses interface Boot;
  uses interface Leds;
  uses interface UartStream;
  uses interface StdControl as UartControl;
  uses interface Timer<TMilli>;
} implementation {
  bool keepSampling = FALSE;

  event void Boot.booted(){
    call UartControl.start();
    printf("\n\rNo-TOS ADC test\n\r");
    printf("s: Sample\n\r");
    printf("q: quit/reset\n\r");
    //vcc: from VCC1WB
    P3OUT |= BIT7;
    P3DIR |= BIT7;
    //p1.1 = shutdown pin
    //default: Out, gnd
    P1DIR |= BIT1;
    P1OUT &= ~BIT1;
  }

  task void busyRead(){
    uint8_t cycles = 0;
    //if (REFCTL0 & ~REFMSTR & ~REFGENBUSY){
      //use legacy ref settings
      REFCTL0 &= ~REFMSTR;
      printf("Switched REFMSTR to 0.\n\r");
    //}
    ADC12CTL0  = ADC12SHT02 + ADC12SHT01 + ADC12SHT12 + ADC12SHT11;// + ADC12ON; // match sampling time to non-working version
    ADC12CTL0 += ADC12MSC + ADC12REF2_5V + ADC12REFON;
    ADC12CTL1 = ADC12SHP + ADC12SSEL_1; // ACLK /1
    ADC12MCTL0 = BIT7 + //EOS 
                 // ADC12SREF0 + //AVss -> VRef+ //reads 4095 until
                                //connected to gnd
                              //also: refon seems to toggle back and
                              //forth? what's up with that
                 // ADC12SREF0 + ADC12SREF2 + //VRef- -> VRef+ //reads ~0
                 0 +          //vss -> Vcc: ok!
                 BIT2;  //A4
    //ADC12CTL0 |= ADC12ENC;  //enable conversion
    //input, function select on pin
    P2DIR &= ~BIT4;
    P2SEL |= BIT4;
    //Start it up
    printf("StartConversion:\n\r");
    printf(" P2DIR: %x (4: %x)\n\r", P2DIR, (P2DIR >> 4) & 0x01);
    printf(" P2SEL: %x (4: %x)\n\r", P2SEL, (P2SEL >> 4) & 0x01);
    printf(" P2MAP4: %x\n\r", P2MAP4);
    printf(" ADC12CTL0:  %x\n\r", ADC12CTL0);
    printf("  SHT1x: %x\n\r", (ADC12CTL0_H >> 4) & 0x0f);
    printf("  SHT0x: %x\n\r", (ADC12CTL0_H >> 0) & 0x0f);
    printf("  MSC  : %x\n\r", (ADC12CTL0_L >> 7) & 0x01);
    printf("  REF25: %x\n\r", (ADC12CTL0_L >> 6) & 0x01);
    printf("  REFON: %x\n\r", (ADC12CTL0_L >> 5) & 0x01);
    printf("  ADCON: %x\n\r", (ADC12CTL0_L >> 4) & 0x01);
    printf("  OVIE:  %x\n\r", (ADC12CTL0_L >> 3) & 0x01);
    printf("  TOVIE: %x\n\r", (ADC12CTL0_L >> 2) & 0x01);
    printf("  ENC:   %x\n\r", (ADC12CTL0_L >> 1) & 0x01);
    printf("  SC:    %x\n\r", (ADC12CTL0_L >> 0) & 0x01);
    printf(" ADC12CTL1:  %x\n\r", ADC12CTL1);
    printf("  SA:    %x\n\r", (ADC12CTL1_H >> 4) & 0x0f);
    printf("  SHS:   %x\n\r", (ADC12CTL1_H >> 2) & 0x03);
    printf("  SHP:   %x\n\r", (ADC12CTL1_H >> 1) & 0x01);
    printf("  ISSH:  %x\n\r", (ADC12CTL1_H >> 0) & 0x01);
    printf("  DIVx:  %x\n\r", (ADC12CTL1_L >> 5) & 0x07);
    printf("  SSEL:  %x\n\r", (ADC12CTL1_L >> 3) & 0x03);
    printf("  CONSQ: %x\n\r", (ADC12CTL1_L >> 1) & 0x03);
    printf("  BUSY:  %x\n\r", (ADC12CTL1_L >> 0) & 0x01);
    printf(" ADC12CTL2:  %x\n\r", ADC12CTL2);
    printf("  PDIV:  %x\n\r", (ADC12CTL2_H >> 0) & 0x01);
    printf("  TCOFF: %x\n\r", (ADC12CTL2_L >> 7) & 0x01);
    printf("  RES:   %x\n\r", (ADC12CTL2_L >> 4) & 0x03);
    printf("  DF:    %x\n\r", (ADC12CTL2_L >> 3) & 0x01);
    printf("  SR:    %x\n\r", (ADC12CTL2_L >> 2) & 0x01);
    printf("  ROUT:  %x\n\r", (ADC12CTL2_L >> 1) & 0x01);
    printf("  RBRST: %x\n\r", (ADC12CTL2_L >> 0) & 0x01);
    printf(" ADC12MCTL0: %x\n\r", ADC12MCTL0);
    printf("  EOS:   %x\n\r", (ADC12MCTL0 >> 7) & 0x01);
    printf("  SREF:  %x\n\r", (ADC12MCTL0 >> 4) & 0x07);
    printf("  INCH:  %x\n\r", (ADC12MCTL0 >> 0) & 0x0f);
    ADC12CTL0 |= ADC12ON; 
    ADC12CTL0 |= (ADC12SC + ENC); 
    //busy wait until it completes
    while(ADC12CTL1 & ADC12BUSY){
      cycles ++;
      if(cycles == 0){
        printf(".");
      }
    }
    printf("Read: %x (%d)\n\r", 
      ADC12MEM0, ADC12MEM0);
    call Timer.startOneShot(2048);
  }


  task void startSample(){
    printf("Sampling. \n\r");
    keepSampling = TRUE;
    post busyRead();
  }

  task void stopSample(){
    printf("stop.\n\r");
    keepSampling = FALSE;
  }

  event void Timer.fired(){
    if (keepSampling){
      post busyRead();
    } else{
      printf("Skip.\n\r");
    }
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
      case '\r':
        printf("\n\r");
        break;
      default:
        printf("%c", b);
    }
  }
  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){}
  async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t err){}

}
