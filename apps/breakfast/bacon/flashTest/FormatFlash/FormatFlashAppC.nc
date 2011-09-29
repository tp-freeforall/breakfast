#include "StorageVolumes.h"

configuration FormatFlashAppC {}

implementation
{
  components FormatFlashP,
             MainC,
             new LogStorageC(VOLUME_SENSORLOG, TRUE),
             LedsC;
             
  FormatFlashP.Boot -> MainC;
  FormatFlashP.Leds -> LedsC;
  //FormatFlashP.LogRead -> LogStorageC;
  FormatFlashP.LogWrite -> LogStorageC;
}
