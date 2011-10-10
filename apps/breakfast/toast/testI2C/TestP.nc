#include "I2C.h"
module TestP{
  uses interface Boot;
  uses interface UartStream;
  uses interface UartByte;
  uses interface StdControl;
  uses interface Timer<TMilli>;

  provides interface Msp430UsciConfigure as I2CConfigure;
  uses interface I2CPacket<TI2CBasicAddr>;
  uses interface I2CSlave;
  uses interface Resource as I2CResource;

  uses interface GpioInterrupt as OWInterrupt;
  uses interface GeneralIO as OWIO;
} implementation {
  uint8_t idleMsg[]    = ".";              //1
  uint8_t resetMsg[]   = "RESET\n\r";      //7
  uint8_t welcomeMsg[] = "\n\rI2C Test\n\r";   //12
  uint8_t writingMsg[] = "WRITING\n\r";    //9
  uint8_t writeDoneMsg[] = "WRITE DONE\n\r"; //12
  uint8_t writeDoneFailMsg[] = "WRITE DONE FAIL\n\r"; //17
  uint8_t writeFailMsg[] = "WRITE FAIL\n\r"; //12
  uint8_t readingMsg[] = "READING\n\r";    //9
  uint8_t readFailMsg[] = "READ FAIL\n\r";    //11
  uint8_t readDoneFailMsg[] = "READ DONE FAIL\n\r";    //16
  uint8_t resourceGrantedMsg[] = "RESOURCE GRANTED\n\r"; //18
  uint8_t disableGCMsg[] = "GC DISABLE\n\r";   //12
  uint8_t disableGCFailMsg[] = "GC DISABLE FAIL\n\r";//17
  uint8_t enableGCMsg[] = "GC ENABLE\n\r";   //11
  uint8_t enableGCFailMsg[] = "GC ENABLE FAIL\n\r";//16
  uint8_t slaveTransmitDoneMsg[] = "SLAVE TRANSMIT DONE\n\r"; //21
  uint8_t myAddrMsg[] = "Me:  \n\r";
  uint8_t slaveAddrMsg[] = "Slave:  \n\r";
  uint8_t gcWritingMsg[] = "WRITING TO GC\n\r";//15
  uint8_t nl[] = "\n\r";                   //2
  uint8_t writeArbitrationLostMsg[] = "WRITE ARBITRATION LOST\n\r";//24
  uint8_t readArbitrationLostMsg[] = "READ ARBITRATION LOST\n\r";//23
  uint8_t arbitrationTestMsg[] = "ARBITRATION TEST: x\n\r";//21

  uint8_t rxByte;
  uint8_t state;
  bool writeBack = FALSE;
  bool rxReportPending = FALSE;

  uint8_t i2c_index;

  // 10010 00
  uint16_t minAddr = 'A';
  uint16_t myAddr;
  uint16_t slaveAddr; 

  typedef struct {
    uint16_t srcAddr;
    uint8_t  data[4];
  } i2c_message_t;

  typedef union {
    i2c_message_t msg;
    uint8_t data[0];
  } i2c_packet_t;

  i2c_packet_t txPkt;
  i2c_packet_t rxPkt;
  
  enum{
    S_INIT = 0x01,
    S_IDLE = 0x00,
    S_ECHOING = 0x02,
    S_RESETTING = 0x03,
    S_WRITE_START = 0x04,
    S_WRITE_FAIL = 0x05,
    S_WRITING = 0x06,
    S_WRITEDONE = 0x07,
    S_WRITEDONE_FAIL = 0x08,
    S_RESOURCE_REQUESTED = 0x09,
    S_RESOURCE_REQUEST_FAIL = 0x0a,
    S_RESOURCE_GRANTED = 0x0b,
    S_READ_START = 0x0c,
    S_READING = 0x0d,
    S_READDONE = 0x0e,
    S_READDONE_FAIL = 0x0f,
    S_READ_FAIL = 0x10,
    S_ENABLE_GC_START = 0x11,
    S_SLAVE_RECEIVE = 0x12,
    S_SLAVE_START = 0x13,
    S_SLAVE_STOP_RECEIVE = 0x14,
    S_SLAVE_STOP_TRANSMIT = 0x15,
    S_SLAVE_TRANSMIT = 0x16,
    S_GC_WRITE_START = 0x17,
    S_DISABLE_GC_START = 0x18,
    S_READ_ARBITRATION_LOST = 0x19,
    S_WRITE_ARBITRATION_LOST = 0x1a,
  };

  void setState(uint8_t s){
    atomic{
      state = s;
      P6OUT = state;
    }
  }

  bool checkState(uint8_t s){
    atomic return (state == s);
  }

  task void restartTimer(){
    call Timer.startOneShot(2048);
  }

  event void Boot.booted(){
    atomic{
      myAddr = minAddr;
      myAddrMsg[4] = myAddr;
      slaveAddr = minAddr;
      slaveAddrMsg[7] = slaveAddr;
      P6DIR = 0xff;
      P6SEL = 0x00;
      P6OUT = 0x00;
      //P6DIR = 0x00;
      txPkt.msg.data[0] = 't';
      txPkt.msg.data[1] = 'x';
      txPkt.msg.data[2] = '\n';
      txPkt.msg.data[3] = '\r';
    }
    call OWIO.makeOutput();
    call OWIO.clr();
    if (call StdControl.start() == SUCCESS){
      setState(S_INIT);
      call Timer.startOneShot(256);
    }
  }

  event void Timer.fired(){
    if(rxReportPending){
      rxReportPending = FALSE;
      call UartStream.send(rxPkt.msg.data, sizeof(rxPkt));
    }else if(checkState(S_IDLE)){
      call UartStream.send(idleMsg, 1);
    }else if(checkState(S_INIT)){
      call UartStream.send(welcomeMsg, 12);
    }else if(checkState(S_SLAVE_STOP_TRANSMIT)){
      call UartStream.send(slaveTransmitDoneMsg, 21);
    }else if(checkState(S_RESETTING)){
      //trigger reset
      WDTCTL = 0x00;
    }
  }

  task void shortTimer(){
      call Timer.startOneShot(256);
  }

  task void doWrite(){
    uint16_t destAddr;

    atomic{
      if (checkState(S_GC_WRITE_START)){
        destAddr = 0x0000;
      } else {
        destAddr = slaveAddr;
      }
    }
    if( SUCCESS == call I2CPacket.write(I2C_START | I2C_STOP, destAddr, sizeof(txPkt), (uint8_t*)&txPkt)){
      setState(S_WRITING);
    }else{
      setState(S_WRITE_FAIL);
      call UartStream.send(writeFailMsg, 12);
    }
    
  }


  task void doRead(){
    uint16_t destAddr;
    atomic destAddr = slaveAddr;
    if (SUCCESS == call I2CPacket.read(I2C_START|I2C_STOP, destAddr, sizeof(rxPkt), rxPkt.data)){
      setState(S_READING);
    } else{
      setState(S_READ_FAIL);
      call UartStream.send(readFailMsg, 11);
    }
  }

  //OK
  task void getResource(){
    if(SUCCESS == call I2CResource.request()){
      setState(S_RESOURCE_REQUESTED);
    } else {
      setState(S_RESOURCE_REQUEST_FAIL);
    }
  }
  
  task void disableGC(){
    if(SUCCESS == call I2CSlave.disableGeneralCall()){
      call UartStream.send(disableGCMsg, 12);
    } else {
      call UartStream.send(disableGCFailMsg, 17 );
    }
    setState(S_IDLE);
  }

  task void enableGC(){
    if(SUCCESS == call I2CSlave.enableGeneralCall()){
      call UartStream.send(enableGCMsg, 11);
    } else {
      call UartStream.send(enableGCFailMsg, 16 );
    }
    setState(S_IDLE);
  }

  async event void UartStream.sendDone(uint8_t* buf, uint16_t len, error_t err){
    if(checkState(S_RESETTING)){
      post shortTimer();
    } else if (checkState(S_INIT)){
      post getResource();
    } else if (checkState(S_WRITE_START)){
      post doWrite();
    } else if (checkState(S_READ_START)){
      post doRead();
    } else if (checkState(S_READDONE)){
      memset(rxPkt.data, 0xff, sizeof(rxPkt));
      setState(S_IDLE);
    } else if(checkState(S_GC_WRITE_START)){
      post doWrite();
    } else {
      setState(S_IDLE);
    }
    post restartTimer();
  }

  task void echoTask(){
    call UartStream.send(&rxByte, 1);
  }

  task void nlTask(){
    call UartStream.send(nl, 2);
  }

  async event void UartStream.receivedByte(uint8_t byte){
    atomic{
      rxByte = byte;
    }
    switch (rxByte){
      case 'q':
        setState(S_RESETTING);
        call UartStream.send(resetMsg, 7);
        break;
      case '\r':
        setState(S_ECHOING);
        post nlTask();
        break;
      case 'w':
        setState(S_WRITE_START);
        txPkt.msg.srcAddr = myAddr;
        call UartStream.send(writingMsg, 9);
        break;
      case 'r':
        setState(S_READ_START);
        call UartStream.send(readingMsg, 9);
        break;
      case 'm':
        myAddr++;
        call I2CSlave.setOwnAddress(myAddr);
        myAddrMsg[4] = myAddr;
        txPkt.msg.srcAddr = myAddr;
        call UartStream.send(myAddrMsg, 7);
        break;
      case 's':
        slaveAddr++;
        slaveAddrMsg[7] = slaveAddr;
        call UartStream.send(slaveAddrMsg, 10);
        break;
      case 'e':
        setState(S_ENABLE_GC_START);
        post enableGC();
        break;
      case 'd':
        setState(S_DISABLE_GC_START);
        post disableGC();
        break;
      case 'g':
        txPkt.msg.srcAddr = myAddr;
        setState(S_GC_WRITE_START);
        call UartStream.send(gcWritingMsg, 15);
        break;
      case 'a':
        writeBack= !writeBack;
        if (writeBack){
          call OWIO.makeInput();
          call OWInterrupt.enableRisingEdge();
        }else {
          call OWIO.makeOutput();
          call OWInterrupt.disable();
        }
        arbitrationTestMsg[18] = (writeBack)?'y':'n';
        call UartStream.send(arbitrationTestMsg, 21);
        break;
      case 't':
        call OWIO.makeOutput();
        call OWIO.clr();
        call OWIO.set();
        call OWIO.clr();
        break;
      default:
        setState(S_ECHOING);
        post echoTask();
    }
  }

  event void I2CResource.granted(){
    setState(S_RESOURCE_GRANTED);
    call UartStream.send(resourceGrantedMsg, 18);
  }

  async event void I2CPacket.writeDone(error_t error, uint16_t addr, uint8_t length, uint8_t* data){
    if(error == SUCCESS){
      setState(S_WRITEDONE);
      call UartStream.send(writeDoneMsg, 12);
    } else if(error == EBUSY){
      setState(S_WRITE_ARBITRATION_LOST);
      call UartStream.send(writeArbitrationLostMsg, 24);
    }else{
      setState(S_WRITEDONE_FAIL);
      call UartStream.send(writeDoneFailMsg, 17);
    }
  }

  async event void UartStream.receiveDone(uint8_t* buf, uint16_t len, error_t err){
  }

  const msp430_usci_config_t i2c_cfg = {
    ctl0: UCSYNC | UCMODE_3 | UCMM,
    ctl1: UCSSEL_2,
    br0:  0x08,
    br1:  0x00,
    mctl: 0,
    i2coa: 'A',
  };


  async command const msp430_usci_config_t* I2CConfigure.getConfiguration(){
    return &i2c_cfg;
  }

  async event void I2CPacket.readDone(error_t error, uint16_t addr, uint8_t length, uint8_t* data){
    if (error == SUCCESS){
      setState(S_READDONE);
      call UartStream.send(data, length);
    }else if(error == EBUSY){
      setState(S_READ_ARBITRATION_LOST);
      call UartStream.send(readArbitrationLostMsg, 23);
    }else {
      setState(S_READDONE_FAIL);
      call UartStream.send(readDoneFailMsg, 16);
    }
  }
  
  async event error_t I2CSlave.slaveReceive(uint8_t b){
    setState(S_SLAVE_RECEIVE);
    rxPkt.data[i2c_index++] = b;
    return SUCCESS;
  }

  async event uint8_t I2CSlave.slaveTransmit(){
    setState(S_SLAVE_TRANSMIT);
    return txPkt.data[i2c_index++];
  }

  async event void I2CSlave.slaveStart(){
    i2c_index = 0;
    txPkt.msg.srcAddr = myAddr;
    setState(S_SLAVE_START);
  }

  async event void I2CSlave.slaveStop(){
    post shortTimer();
    if (checkState(S_SLAVE_RECEIVE)){
      rxReportPending = TRUE;
//      if(writeBack){
//        //echo it
//        memcpy(txPkt.msg.data, rxPkt.msg.data, 4);
//        call I2CPacket.write(I2C_START | I2C_STOP, rxPkt.msg.srcAddr, sizeof(txPkt), txPkt.data);
//      }
      setState(S_SLAVE_STOP_RECEIVE);
    } else if(checkState(S_SLAVE_TRANSMIT)){
      setState(S_SLAVE_STOP_TRANSMIT);
    }
  }
  
  task void tryWriteAL(){
    call I2CPacket.write(I2C_START | I2C_STOP, slaveAddr, sizeof(txPkt), txPkt.data);
  }

  async event void OWInterrupt.fired(){
    post tryWriteAL();
  }

}
