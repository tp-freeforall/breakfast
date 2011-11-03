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
  norace uint8_t cmd_buf[20];
  norace uint8_t pos = 0;
  norace uint8_t slavePos = 0;

  uint16_t slaveAddr;

  event void Boot.booted(){
    call Leds.set(0);
    call UartControl.start();
    printf("UART -> I2C Master echo\n\r");
    call Resource.request();
  }


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
        //'0' -> general call
        if (slaveAddr == '0'){
          slaveAddr = 0x00;
        }
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
      case 'r':
        slaveAddr = cmd_buf[1];
        printf("Read: %s\n\r",
          decodeError(
            call I2CPacket.read(I2C_START|I2C_STOP,
              slaveAddr,
              pos - 2,
              cmd_buf
            )
          )
        );
        break;
      case 'o':
        printf("Set own address: %x\n\r", cmd_buf[1]);
        call I2CSlave.setOwnAddress(cmd_buf[1]);
        break;
      case 'g':
        printf("enable general call\n\r");
        call I2CSlave.enableGeneralCall();
        break;
      case 'G':
        printf("disable general call\n\r");
        call I2CSlave.disableGeneralCall();
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
    uint8_t i;
    printf("ReadDone: %s %x %x: ", decodeError(error), addr, len);
    for(i=0; i < len; i++){
      printf("%c", data[i]);
    }
    printf("\n\r");
  }

  async event bool I2CSlave.slaveReceiveRequested() {
    cmd_buf[slavePos++] = call I2CSlave.slaveReceive();
    return TRUE;
  }

  async event bool I2CSlave.slaveTransmitRequested(){
    call I2CSlave.slaveTransmit(cmd_buf[(slavePos++)%pos]);
    return TRUE;
  }

  async event void I2CSlave.slaveStart(bool isGeneralCall){
    printf("Slave Start\n\r");
    slavePos = 0;
  }

  async event void I2CSlave.slaveStop(){
    uint8_t i;
    printf("Slave stop: ");
    for(i = 0; i < slavePos; i++){
      printf("%c", cmd_buf[i]);
    }
    printf("\n\r");
  }

  async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t err){}
  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){}
}
