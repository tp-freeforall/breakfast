module TestP{
  uses interface Boot;
  uses interface Leds;
  uses interface Timer<TMilli> as Timer0;
  uses interface Timer<TMilli> as Timer1;
}implementation {

  event void Boot.booted(){
    call Timer0.startPeriodicAt(612, 64);
    call Timer1.startPeriodicAt(347, 256);
  }

  event void Timer0.fired(){
    call Leds.led0Toggle();
  }

  event void Timer1.fired(){
    call Leds.led1Toggle();
  }
} 
