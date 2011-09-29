module TestP{ 
  uses interface Boot;
  uses interface CC1190;
  uses interface StdControl;

} implementation {
  event void Boot.booted(){
    uint16_t i;
    //1000 1110
    P3DIR |= 0x01;
    call StdControl.start();
    call CC1190.TXMode(0);
    while(1){
      i++;
      if (i == 0){
        P3OUT ^= 0x01;
      }
    }
  }
}
