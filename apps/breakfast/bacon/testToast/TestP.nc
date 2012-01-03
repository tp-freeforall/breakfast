#include "I2CDiscoverable.h"
#include "decodeError.h"

module TestP{
  uses interface Boot;
  uses interface I2CDiscoverer;
  uses interface UartStream;
  uses interface StdControl;
  uses interface I2CPersistentStorageMaster;
  uses interface Leds;
} implementation {
  enum {
    MAX_SLAVES = 4,
  };
  uint16_t slaves[MAX_SLAVES];
  uint8_t slaveCount;

  event void Boot.booted(){
    call StdControl.start();
    printf("Test Toast apps\n\r");
  }

  task void startDiscovery(){
    printf("Start discovery\n\r");
    slaveCount = 0;
    call I2CDiscoverer.startDiscovery(TRUE, 0x40);
  }

  event uint16_t I2CDiscoverer.getLocalAddr(){
    return TOS_NODE_ID & 0x7F;
  }

  event discoverer_register_union_t* I2CDiscoverer.discovered(discoverer_register_union_t* discovery){
    uint8_t i;
    slaves[slaveCount] = discovery->val.localAddr;
    printf("Assigned %x to ", discovery->val.localAddr);
    for ( i = 0 ; i < GLOBAL_ID_LEN; i++){
      printf("%x ", discovery->val.globalAddr[i]);
    }
    printf("\n\r");
    slaveCount++;
    return discovery;
  }

  event void I2CDiscoverer.discoveryDone(error_t error){
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
  }

  uint8_t buf[64];

  task void readPersistentStorage(){
    error_t error;
    if (slaveCount == 0){
      printf("No slaves found yet ('d' to discover)\n\r");
    } else {
      printf("Reading from local addr %x\n\r", slaves[0]);
      error = call I2CPersistentStorageMaster.read(slaves[0], buf);
      printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
    }
  }
  event void I2CPersistentStorageMaster.readDone(error_t error,
      void* buf_){
    uint8_t i;
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
    if (error == SUCCESS){
      for (i = 0; i < 64; i++){
        if ( i % 8 == 0){
          printf("\n\r [%x]",i);
        }
        printf(" %x", ((uint8_t*)buf)[i]);
      }
    }
    printf("\n\r");
  }

  task void writePersistentStorage(){
    error_t error;
    if (slaveCount == 0){
      printf("No slaves found yet ('d' to discover)\n\r");
    } else {
      printf("writing to local addr %x\n\r", slaves[0]);
      error = call I2CPersistentStorageMaster.write(slaves[0], buf);
      printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
    }
  }

  event void I2CPersistentStorageMaster.writeDone(error_t error,
      void* buf_){
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
  }

  async event void UartStream.receivedByte(uint8_t byte){
    call Leds.led0Toggle();
    switch ( byte ){
      case 'd':
        post startDiscovery();
        break;
      case 'r':
        post readPersistentStorage();
        break;
      case 'w':
        post writePersistentStorage();
        break;
      case 'q':
        WDTCTL = 0;
        break;
      case '\r':
        printf("\n\r");
        break;
      default:
        printf("%c", byte);
        break;
    }
  }
  
  async event void UartStream.receiveDone( uint8_t* buf_, uint16_t len,
    error_t error ){}
  async event void UartStream.sendDone( uint8_t* buf_, uint16_t len,
    error_t error ){}
}
