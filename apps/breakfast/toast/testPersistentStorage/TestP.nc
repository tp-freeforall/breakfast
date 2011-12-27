#include "decodeError.h"
#include "I2CPersistentStorage.h"
module TestP{
  uses interface Boot;
  uses interface UartStream;
  uses interface StdControl as UartControl;

  //slave
  uses interface SplitControl;
  uses interface I2CDiscoverable;

  //master 
  uses interface I2CPacket<TI2CBasicAddr>;
  uses interface Resource;
  uses interface I2CDiscoverer;

} implementation {
  bool isRead;
  bool seeking;
  uint8_t globalAddr[GLOBAL_ADDR_LENGTH];
  uint16_t slaveAddr;
  uint8_t readBackBuf[64];
  uint8_t count;

  typedef struct {
    uint8_t pos;
    union {
      uint8_t data[65];
      struct{
        uint8_t clientId;
        uint8_t cmd;
        uint8_t data[63];
      } body;
    };
  } __attribute__((__packed__)) i2c_pkt_t;

  i2c_pkt_t pkt;

  event void Boot.booted(){
    uint8_t i;
    printf("I2C Persistent Storage Test\n\r");
    call UartControl.start();
    globalAddr[GLOBAL_ADDR_LENGTH -1 ] = TOS_NODE_ID;
    for (i = 0; i < 63; i++){
      pkt.body.data[i] = i;
    }
  }

  event uint16_t I2CDiscoverer.getLocalAddr(){
    return TOS_NODE_ID;
  }

  event discoverer_register_union_t*
      I2CDiscoverer.discovered(discoverer_register_union_t* discovery){
    uint8_t i;
    slaveAddr = discovery -> val.localAddr;
    printf("Assigned %x to ", slaveAddr);
    for (i = 0; i < GLOBAL_ADDR_LENGTH; i++){
      printf("%x", discovery -> val.globalAddr[i]);
    }
    printf("\n\r");
    return discovery;
  }

  event void I2CDiscoverer.discoveryDone(error_t error){
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
  }

  event uint8_t* I2CDiscoverable.getGlobalAddr(){
    return globalAddr;
  }

  event void I2CDiscoverable.assigned(error_t err, uint16_t lastLocalAddr){
    printf("Assigned to %x\n\r", lastLocalAddr);
  }

  event void SplitControl.startDone(error_t error){
    printf("Register/discoverable started\n\r");
  }

  event void SplitControl.stopDone(error_t error){
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
  }

  task void slaveStart(){
    error_t error = call SplitControl.start();
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
  }

  task void masterStart(){
    printf("stop slave: %s\n\r", decodeError(call SplitControl.stop()));
    printf("Start discoverer: %s\n\r", decodeError(call I2CDiscoverer.startDiscovery(TRUE, 0x40)));
  }
  
  task void write(){
    pkt.pos = 0;
    pkt.body.clientId = REGISTER_CLIENT_ID_STORAGE;
    pkt.body.cmd = I2C_STORAGE_WRITE_CMD;
    printf("Sizeof: %d pkt %p pos %p client %p cmd %p data start %p \n\r", 
      sizeof(pkt), &pkt, &pkt.pos, &pkt.body.clientId, &pkt.body.cmd, &pkt.body.data);
    call I2CPacket.write(I2C_START|I2C_STOP, slaveAddr, 66, (uint8_t*)&pkt);
  }

  task void seek(){
    pkt.pos = 0;
    pkt.body.clientId = REGISTER_CLIENT_ID_STORAGE;
    pkt.body.cmd = I2C_STORAGE_READ_CMD;
    call I2CPacket.write(I2C_START, slaveAddr, 3, (uint8_t*)&pkt); 
    seeking = TRUE;
    //printf("%s: %s\n\r", __FUNCTION__, decodeError(call I2CPacket.read(I2C_START|I2C_STOP, slaveAddr, 63, readBackBuf)));
  }

  task void read(){
    call I2CPacket.read(I2C_RESTART| I2C_STOP, slaveAddr, 63, readBackBuf);
  }

  async event void I2CPacket.writeDone(error_t error, uint16_t addr, uint8_t len, uint8_t* data){ 
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
    if (seeking){
      seeking = FALSE;
      post read();
    } 
  }

  event void Resource.granted(){
    if(isRead){
      post seek();
    } else {
      post write();
    }
  }

  task void startWrite(){
    isRead = FALSE;
    if (! call Resource.isOwner()){
      call Resource.request();
    } else {
      post write();
    }
  }

  task void report(){
    uint8_t i;
    printf("Read back: [\n\r");
    for (i=0; i < 63; i++){
      printf("%c", readBackBuf[i]);
    }
    printf("\n\r]\n\r");
  }

  async event void I2CPacket.readDone(error_t error, uint16_t addr, uint8_t len, uint8_t* data){
    printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
    post report();
  }

  task void startRead(){
    printf("%s: \n\r", __FUNCTION__);
    isRead = TRUE;
    if (! call Resource.isOwner()){
      call Resource.request();
    } else {
      post seek();
    }
  }

  async event void UartStream.receivedByte(uint8_t b){
    uint8_t data = b;
    switch(b){
      case 'q':
        WDTCTL = 0x00;
        break;
      case 's':
        post slaveStart();
        break;
      case 'd':
        post masterStart();
        break;
      case 'w':
        post startWrite();
        break;
      case 'r':
        post startRead();
        break;
      case '\r':
        printf("\n\r");
        break;
      default:
        printf("%c", data);
        //pkt.body.data[count] = data;
        //count++;
        break;
    }
  }

  async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t err){};
  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){};
}
