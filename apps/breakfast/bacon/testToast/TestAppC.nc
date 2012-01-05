#include "TestToast.h"
configuration TestAppC{
} implementation {
  components MainC;
  components PlatformSerialC;
  components SerialPrintfC;
  components LedsC;

  components new I2CDiscovererC();

  components TestP;

  TestP.Boot -> MainC;
  TestP.Leds -> LedsC;
  TestP.StdControl -> PlatformSerialC;
  TestP.SubUartStream -> PlatformSerialC;

  TestP.I2CDiscoverer -> I2CDiscovererC;

  enum{
    STORAGE_TEST_ID = unique(UQ_TEST_CLIENT),
  };
  components StorageTestC;
  StorageTestC.UartStream -> TestP.UartStream[STORAGE_TEST_ID];
  StorageTestC.Get -> TestP.Get;
  TestP.GetDesc[STORAGE_TEST_ID] -> StorageTestC.GetDesc;

//  components TLVStorageTestC;
//  TLVStorageTestC.UartStream = TestP.UartStream[unique(UQ_TEST_CLIENT)];
//  TLVStorageTestC.Get = TestP.Get;

}
