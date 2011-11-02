#include <stdio.h>
#include "decodeError.h"

module TestP{
  uses interface Boot;
  uses interface Leds;
  uses interface I2CPacket<TI2CBasicAddr>;
  uses interface I2CSlave;
  uses interface Resource;
  uses interface UartStream;
  uses interface StdControl as UartControl;
} implementation {
  event void Boot.booted(){
    call Leds.set(0);
    call UartControl.start();
    printf("UART -> I2C Master echo\n\r");
    call Resource.request();
  }

  norace uint8_t cmd_buf[20];
  norace uint8_t pos = 0;

  uint16_t slaveAddr;

  task void processBuffer(){
    cmd_buf[pos] = 0x00;
    printf("PROCESSING %s\n\r", cmd_buf);
    switch(cmd_buf[0]){
      case 'q':
        //TODO: seeing some garbage at this point: is printf returning
        //  too soon?
        WDTCTL = 0;
        break;
      case 'w':
        slaveAddr = cmd_buf[1];
        printf("Write: %s\n\r", 
          decodeError(
            call I2CPacket.write(I2C_START|I2C_STOP, 
              slaveAddr, 
              pos - 2, 
              cmd_buf+2
            )
          )
        );
        break; 
      default:
        printf("Unknown command %c\n\r", cmd_buf[0]);
        break;
    }
    pos = 0;
  }

  uint16_t counter;
  async event void UartStream.receivedByte(uint8_t byte){
    //TODO: is there something wrong with the leds behavior? it seems
    //to not like counting past 7, and also it's inverted.
    call Leds.set(++counter);
    switch(byte){
      case '\r':
        printf("\n\r");
        if(pos > 0){
          post processBuffer();
        }
        break;
      default:
        cmd_buf[pos++] = byte;
        printf("%c", byte);
        break;
    }
  }

  event void Resource.granted(){
    printf("Granted\n\r");
  }


  async event void I2CPacket.writeDone(error_t error, uint16_t addr, uint8_t len, uint8_t* data){
    printf("WriteDone: %s %x %x\n\r", decodeError(error), addr, len);
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

  async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t err){}
  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){}
}
