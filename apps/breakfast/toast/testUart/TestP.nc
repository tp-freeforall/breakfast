module TestP{
  uses interface Boot;
  uses interface UartStream;
  uses interface UartByte;
  uses interface StdControl;
  uses interface Timer<TMilli>;
} implementation {
  
  event void Boot.booted(){
    atomic{
      P6DIR = 0xff;
      P6SEL = 0x00;
      P6OUT = 0x00;
    }
    P6OUT = 0x01;
    if (call StdControl.start() == SUCCESS){
      P6OUT = 0x03;
    }else{
      P6OUT = 0x0f;
    }
    call Timer.startPeriodic(20);
  }
  uint8_t message[] = "hi\n\r";

  event void Timer.fired(){
    P6OUT = 0x04;
    //call UartStream.send(message, 4);
    P6OUT = 0x05;
  }

  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){
  }

  async event void UartStream.receivedByte(uint8_t byte){
  }

  async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t
  err){
  }

}
