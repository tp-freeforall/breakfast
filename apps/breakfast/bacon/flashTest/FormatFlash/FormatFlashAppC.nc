#include "StorageVolumes.h"

configuration FormatFlashAppC {}

implementation
{
  components SerialPrintfC,
             PlatformSerialC;
  components FormatFlashP,
             MainC,
             new LogStorageC(VOLUME_SENSORLOG, TRUE),
             LedsC;
             
  FormatFlashP.Boot -> MainC;
  FormatFlashP.Leds -> LedsC;
  //FormatFlashP.LogRead -> LogStorageC;
  FormatFlashP.LogWrite -> LogStorageC;
  FormatFlashP.UartCtl -> PlatformSerialC;
  FormatFlashP.UartStream -> PlatformSerialC;
}
