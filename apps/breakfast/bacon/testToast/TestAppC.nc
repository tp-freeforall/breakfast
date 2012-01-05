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
    TLV_STORAGE_TEST_ID = unique(UQ_TEST_CLIENT),
  };
  components TLVStorageTestC;
  TLVStorageTestC.UartStream -> TestP.UartStream[TLV_STORAGE_TEST_ID];
  TLVStorageTestC.Get -> TestP.Get;
  TestP.GetDesc[TLV_STORAGE_TEST_ID] -> TLVStorageTestC.GetDesc;

  enum{
    STORAGE_TEST_ID = unique(UQ_TEST_CLIENT),
  };
  components StorageTestC;
  StorageTestC.UartStream -> TestP.UartStream[STORAGE_TEST_ID];
  StorageTestC.Get -> TestP.Get;
  TestP.GetDesc[STORAGE_TEST_ID] -> StorageTestC.GetDesc;

}
