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
    call StdControl.start();
    call Timer.startPeriodic(1024);
  }
  uint8_t message[] = "hi\n\r";

  event void Timer.fired(){
    call UartStream.send(message, 4);
  }

  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){
    P6OUT ^= 0x01;
  }

  async event void UartStream.receivedByte(uint8_t byte){
    P6OUT ^= 0x02;
  }

  async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t
  err){
    P6OUT ^= 0x04;
  }

}
