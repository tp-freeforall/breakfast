#include <stdio.h>

module TestP{
  uses interface Boot;
  uses interface Timer<TMilli>;
  uses interface Leds;
  uses interface I2CPacket<TI2CBasicAddr>;
  uses interface I2CSlave;
  uses interface Resource;
} implementation {
  uint16_t counter;

  event void Boot.booted(){
    call Timer.startPeriodic(1024);
  }

  event void Timer.fired(){
    printf("Test: %d\r\n", counter++);
    call Leds.set(counter);
  }
  
  event void Resource.granted(){
  }

  async event void I2CPacket.writeDone(error_t error, uint16_t addr, uint8_t len, uint8_t* data){
  }

  async event void I2CPacket.readDone(error_t error, uint16_t addr, uint8_t len, uint8_t* data){
  }

  async event bool I2CSlave.slaveReceiveRequested() {
    //TODO: handle appropriately
    call I2CSlave.slaveReceive();
    return TRUE;
  }

  async event bool I2CSlave.slaveTransmitRequested(){
    //TODO: handle appropriately
    call I2CSlave.slaveTransmit(0xff);
    return TRUE;
  }

  async event void I2CSlave.slaveStart(bool isGeneralCall){
  }

  async event void I2CSlave.slaveStop(){
  }
  
}
