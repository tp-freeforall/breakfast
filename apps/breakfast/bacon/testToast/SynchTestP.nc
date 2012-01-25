#include "I2CSynch.h"
#include "decodeError.h"

module SynchTestP{
  uses interface UartStream;
  uses interface Get<test_state_t*>;
  uses interface I2CSynchMaster;
  provides interface Get<const char*> as GetDesc;
} implementation {
  const char* testDesc = "Synch\n\r r: read\n\r p: print\n\r R: reset\n\r";
  command const char* GetDesc.get(){
    return testDesc;
  }

  enum{
    SYNCH_COUNT = 10,
  };

  uint32_t locals[SYNCH_COUNT];
  uint32_t remotes[SYNCH_COUNT];
  norace uint8_t count;

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
    printf("error: %s (local, remote): (%lu, %lu) \n\r", decodeError(error), result.localTime, result.remoteTime);
    locals[count%SYNCH_COUNT] = result.localTime;
    remotes[count%SYNCH_COUNT] = result.remoteTime;
    count++;
  }

  task void print(){
    int8_t i;
    printf("tuples = [");
    for (i = 0; i < count; i++){
      printf(" (%lu, %lu)", locals[i], remotes[i]);
      if (i < count-1){
        printf(", ");
      }
    }
    printf("]\n\r");
  }

  async event void UartStream.receivedByte(uint8_t byte){
    switch(byte){
      case 'R':
        count = 0;
        break;
      case 'r':
        post read();
        break;
      case 'p':
        post print();
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
