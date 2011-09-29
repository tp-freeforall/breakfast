module TestP{
  uses interface Boot;
  uses interface Timer<TMilli>;

} implementation {
  task void task1();
  task void task2();

  task void task1(){
    post task2();
  }

  task void task2(){
    post task1();
  }

  event void Boot.booted(){
    P6DIR = 0x03;
    P6SEL = 0x00;
    P6OUT = 0x00;
    
    P5DIR |= 0x70;                            // Set p5.4, p5.5, p5.6 output
    P5SEL |= 0x70;                            // use MCLK, smclk, aclk
    call Timer.startPeriodic(1024);
    //post task1();
  }
  
  event void Timer.fired(){
    P6OUT ^= 0x01;
  }

}
