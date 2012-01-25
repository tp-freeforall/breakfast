#include "TestToast.h"
configuration SynchTestC{
  uses interface UartStream;
  uses interface Get<test_state_t*>;
  provides interface Get<const char*> as GetDesc;
} implementation {
  components SynchTestP;
  components I2CSynchMasterC;

  SynchTestP.I2CSynchMaster -> I2CSynchMasterC;

  SynchTestP.UartStream = UartStream;
  SynchTestP.Get = Get;
  GetDesc = SynchTestP.GetDesc;
}

