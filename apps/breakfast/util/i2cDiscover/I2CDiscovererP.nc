#include "I2CDiscoverable.h"
//TODO: ten-bit addresses: should be parameterized
generic module I2CDiscovererP(){
  uses interface I2CPacket<TI2CBasicAddr>;
  uses interface I2CSlave;
  uses interface Resource;
  provides interface I2CDiscoverer;
  uses interface Timer<TMilli>;
  provides interface Msp430UsciConfigure;
  uses interface Pool<discoverer_register_union_t>;
  uses interface Queue<discoverer_register_union_t*>;
} implementation {
  uint8_t pos;
  uint8_t transCount;
  norace uint16_t masterAddr = I2C_INVALID_MASTER;
  uint16_t localAddr = I2C_DISCOVERABLE_UNASSIGNED;
  bool isGC;
  bool setAddrNeeded;
  bool resetNeeded;
  bool isReceive;
  uint8_t txByte;
  bool discovered;

  enum{
    S_INIT= 0x00,
    S_OFF = 0x01,
    S_ANNOUNCING = 0x02,
    S_ANNOUNCED = 0x0a,
    S_RESETTING = 0x08,
    S_SETTING = 0x09,
    S_WAITING = 0x03,
    S_ASSIGNING = 0x04,
    S_RESPONDING = 0x05,
    S_ERROR = 0x07,
  };

  uint8_t state = S_OFF;

  task void announce();
  task void signalDone();

  task void restartTimeout(){
//    printf("RESTART\n\r");
    call Timer.startOneShot(I2C_DISCOVERY_ROUND_TIMEOUT);
  }

  void setState(uint8_t s){
    atomic{
//      printf("D %x->%x\n\r", state, s);
      state = s;
    }
  }

  bool checkState(uint8_t s){
    atomic return s == state;
  }
  
  discoverer_register_union_t _reg;
  discoverer_register_union_t* reg = &_reg;

  command error_t I2CDiscoverer.startDiscovery(){
//    printf("%s: \n\r", __FUNCTION__);
    if(checkState(S_OFF)){
      if ( SUCCESS == call Resource.request()){
        discovered = FALSE;
        setState(S_INIT);
        //register setup is : cmd [globalAddr] localAddr
        atomic reg->val.localAddr = I2C_FIRST_DISCOVERABLE_ADDR;
        return SUCCESS;
      } else {
        return FAIL;
      }
    } else {
      return EALREADY;
    }
  }


  event void Resource.granted(){
//    printf("%s: \n\r", __FUNCTION__);
    localAddr = signal I2CDiscoverer.getLocalAddr();
    call I2CSlave.setOwnAddress(localAddr);
    post announce();
  }

  task void announce(){
    error_t err;
//    printf("announce");
    txByte = (localAddr << 1) | 0x01;
    atomic{
      err = call I2CPacket.write(I2C_START|I2C_STOP, I2C_GC_ADDR, 1, &txByte);
      if (err == SUCCESS) {
        post restartTimeout();
        setState(S_ANNOUNCING);
      }
      //TODO: handle EBUSY for lost arbitration
      if( err != SUCCESS){
        setState(S_ERROR);
      }
    }
    //deal with race condition: writing a single byte is damn fast--
    //if we check state then it will likely already have been modified
    //in the writeDone event
    if (err != SUCCESS){
      post signalDone();
    }
  }

  task void resetTask(){
    error_t err;
    txByte = I2C_GC_RESET_PROGRAM_ADDR;
    atomic{
      err = call I2CPacket.write(I2C_START|I2C_STOP, I2C_GC_ADDR, 1, &txByte);
      if (err == SUCCESS){
        post restartTimeout();
        setState(S_RESETTING);
      }
      //TODO: deal with EBUSY (arbitration lost)
      if (err != SUCCESS){
        setState(S_ERROR);
      } 
    }
  }

  task void setTask(){
    error_t err;
    txByte = I2C_GC_PROGRAM_ADDR;
    atomic{
      err = call I2CPacket.write(I2C_START|I2C_STOP, I2C_GC_ADDR, 1, &txByte);
      if (err != SUCCESS){
        printf("NO SET %s\n\r", decodeError(err));
        setState(S_ERROR);
      } else {
//        printf("Setting\n\r");
        post restartTimeout();
        setState(S_SETTING);
      }
    }
  }


  async event void I2CPacket.writeDone(error_t error, uint16_t slaveAddr, uint8_t len, uint8_t* buf){
    uint8_t stateTmp;
    atomic stateTmp = state;
//    printf("%s: %s\n\r", __FUNCTION__, decodeError(error)); 
    switch(stateTmp){
      case S_ANNOUNCING:
        if(error == SUCCESS){
          setState(S_ANNOUNCED);
          post resetTask();
        } else if (error == ENOACK){
          post signalDone();
        } else {
          setState(S_ERROR);
        }
        break;
      case S_RESETTING:
        //fall-through
      case S_SETTING:
        if(error == SUCCESS){
          setState(S_WAITING);
        } else {
          setState(S_ERROR);
        }
        break;
      default:
        setState(S_ERROR);
    }
  }


  async event void I2CSlave.slaveStart(bool generalCall){
    isGC = generalCall;
    transCount = 0;
//    printf("slave start %x \n\r", generalCall);
    //post restartTimeout();
    switch(state){
      case S_WAITING:
        //we expect the master to write the CLAIM cmd, then their global address from
        //  position 0 onward
        setState(S_ASSIGNING);
        break;
      case S_ASSIGNING:
        //we expect the master to read one byte (their local address)
        //  then stop.
        setState(S_RESPONDING);
        break;
      default:
        setState(S_ERROR);
    }
  }

  async event bool I2CSlave.slaveReceiveRequested(){
    uint8_t data = call I2CSlave.slaveReceive();
//    printf("%s: %x\n\r", __FUNCTION__, data);
    if (isGC){
      //first byte ends with 1: own-address announcement from master
      if (data & 0x01){
        // ignoring own-address announcements
      } else {
        switch(data){
          case 0x06:    //reset + set addr
            resetNeeded = TRUE;
            //fall-through
          case 0x04:    //set addr
            setAddrNeeded = TRUE;
            break;
          default://everything else: forbidden!
            setState(S_ERROR);
        }
      }
    } else {
      if(transCount == 0){
        //first byte: offset
        pos = data;
//        printf("pos: %x", pos);
      } else {
//        printf("writing %x to %x (actually %x)\n\r", data, pos, pos%sizeof(discoverer_register_t));
        //everything else: write it to buffer (circular)
        reg->data[(pos++)%sizeof(discoverer_register_t)] = data;
      }
    }
    transCount++;
    return TRUE;
  }

  async event uint8_t I2CSlave.slaveTransmitRequested(){
    isReceive=FALSE;
//    printf("%s: [%x (%x)] = %x\n\r", __FUNCTION__, 
//      pos,
//      pos%sizeof(discoverer_register_t), 
//      reg.data[pos%sizeof(discoverer_register_t)]);
    //return from buf (circular)
    if (reg->val.cmd == I2C_DISCOVERABLE_REQUEST_ADDR){
      call I2CSlave.slaveTransmit(reg->data[(pos++)%sizeof(discoverer_register_t)]);
    } else {
      call I2CSlave.slaveTransmit(0xff);
    }
    return TRUE;
  }


  async event void I2CPacket.readDone(error_t error, uint16_t slaveAddr, uint8_t len, uint8_t* buf){
    uint8_t stateTmp;
//    printf("%s: \n\r", __FUNCTION__);
    atomic stateTmp = state;
    switch(stateTmp){
      default:
        setState(S_ERROR);
    }
  }

  task void checkQueueTask();
  task void discoveredTask(){
    discoverer_register_union_t* tmp;
    bool empty; 
    atomic empty = call Queue.empty();

    if(! empty){
      atomic {
        tmp = call Queue.dequeue();
      }
//      printf("DISCOVERED\n\r");
      discovered = TRUE;
      tmp = signal I2CDiscoverer.discovered(tmp);
      atomic {
        call Pool.put(tmp);
      }
      atomic{
        if(! call Queue.empty()){
          //allow other operations to interleave
          post checkQueueTask();
        }
      }
    }
  }

  task void checkQueueTask(){
    post discoveredTask();
  }

  //TODO: fix the warnings about async calls to queue/pool. Everything
  //else is atomic access so I think that we're cool.
  async event void I2CSlave.slaveStop(){
    uint16_t nextAddr;
//    printf("%s: \n\r", __FUNCTION__);
    if (checkState(S_RESPONDING)){
      if (reg->val.cmd == I2C_DISCOVERABLE_REQUEST_ADDR){
        nextAddr = reg->val.localAddr + 1;
        call Queue.enqueue(reg);
        reg = call Pool.get();
        reg->val.localAddr = nextAddr;
        post checkQueueTask();
      }

      setState(S_WAITING);
    }else{
//      printf("NO SIGNAL\n\r");
      setState(S_ERROR);
    } 
  }

  task void signalDone(){
    call Resource.release();
    call Timer.stop();
    setState(S_OFF);
    signal I2CDiscoverer.discoveryDone(SUCCESS);
  }

  event void Timer.fired(){
    if(discovered){
      discovered = FALSE;
//      printf("AGAIN\n\r");
      post setTask();
    } else {
//      printf("NO MORE\n\r");
      post signalDone();
    }
  }

  const msp430_usci_config_t _config = {
    ctl0: UCSYNC|UCMODE_3|UCMM,
    ctl1: UCSSEL_2,
    br0:  0x08,
    br1:  0x00,
    mctl: 0x00,
    i2coa: I2C_INVALID_MASTER,
  };

  async command const msp430_usci_config_t* Msp430UsciConfigure.getConfiguration(){
    return &_config;
  }

}

