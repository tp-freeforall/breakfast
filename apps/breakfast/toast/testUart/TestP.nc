module TestP{
  uses interface Boot;
  uses interface UartStream;
  uses interface UartByte;
  uses interface StdControl;
  uses interface Timer<TMilli>;
} implementation {
  uint8_t message[] = "hi\n\r";
  uint8_t rxByte;

  task void restartTimer(){
    call Timer.startOneShot(5120);
  }
  
  event void Boot.booted(){
    atomic{
      P6DIR = 0xff;
      P6SEL = 0x00;
      P6OUT = 0x00;
    }
    if (call StdControl.start() != SUCCESS){
      P6OUT = 0x0f;
    }
    post restartTimer();
  }


  event void Timer.fired(){
    if(call UartStream.send(message, 4) != SUCCESS){
      P6OUT = 0x0f;
    }
  }

  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){
    post restartTimer();
  }

  task void echoTask(){
    call UartStream.send(&rxByte, 1);
  }

  async event void UartStream.receivedByte(uint8_t byte){
    atomic{
      rxByte = byte;
    }
    post echoTask();
  }

  async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t err){
  }

}
