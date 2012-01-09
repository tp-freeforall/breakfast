#include "I2CSynch.h"
#include "decodeError.h"

module SynchTestP{
  uses interface UartStream;
  uses interface Get<test_state_t*>;
  uses interface I2CSynchMaster;
  provides interface Get<const char*> as GetDesc;
} implementation {
  const char* testDesc = "Synch\n\r r: read";
  command const char* GetDesc.get(){
    return testDesc;
  }

  task void read(){
    test_state_t* state = call Get.get();
    error_t error;
    if (state->slaveCount == 0){
      printf("No slaves found yet ('d' to discover)\n\r");
    }else{
      error = call I2CSynchMaster.synch(state->slaves[state->currentSlave]);
      printf("%s: %s\n\r", __FUNCTION__, decodeError(error));
    }
  }
  event void I2CSynchMaster.synchDone(error_t error, uint16_t slaveAddr, synch_tuple_t result){
    printf("%s: %s local: %lu remote: %lu\n\r", __FUNCTION__, decodeError(error),
      result.localTime, result.remoteTime);
  }

  async event void UartStream.receivedByte(uint8_t byte){
    switch(byte){
      case 'r':
        post read();
        break;
      default:
        printf("%c", byte);
    }
  }

  async event void UartStream.receiveDone( uint8_t* buf_, uint16_t len,
    error_t error ){}
  async event void UartStream.sendDone( uint8_t* buf_, uint16_t len,
    error_t error ){}
}
