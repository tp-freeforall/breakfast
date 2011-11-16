#include "StorageVolumes.h"

configuration FlashTestAppC {}

implementation
{
  components SerialPrintfC,
             PlatformSerialC;
  components FlashTestP,
             MainC,
             new LogStorageC(VOLUME_SENSORLOG, FALSE),
             LedsC;
             
  FlashTestP.Boot -> MainC;
  FlashTestP.Leds -> LedsC;
  FlashTestP.LogRead -> LogStorageC;
  FlashTestP.LogWrite -> LogStorageC;
  FlashTestP.UartCtl -> PlatformSerialC;
  FlashTestP.UartStream -> PlatformSerialC;
}
