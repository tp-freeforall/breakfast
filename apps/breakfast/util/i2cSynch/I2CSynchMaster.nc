#include "I2CSynch.h"
interface I2CSynchMaster{
  command error_t synch(uint16_t slaveAddr);
  event void synchDone(error_t error, uint16_t slaveAddr, synch_tuple_t tuple);
}
