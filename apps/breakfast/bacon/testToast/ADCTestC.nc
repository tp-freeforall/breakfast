#include "TestToast.h"
configuration ADCTestC{
  uses interface UartStream;
  uses interface Get<test_state_t*>;
  provides interface Get<const char*> as GetDesc;
} implementation {
  components ADCTestP;
  components I2CADCReaderMasterC;
  components new TimerMilliC();

  ADCTestP.I2CADCReaderMaster -> I2CADCReaderMasterC;

  ADCTestP.UartStream = UartStream;
  ADCTestP.Get = Get;
  ADCTestP.Timer -> TimerMilliC;
  GetDesc = ADCTestP.GetDesc;
}
