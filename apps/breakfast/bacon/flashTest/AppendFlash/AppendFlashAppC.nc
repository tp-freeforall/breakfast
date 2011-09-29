#include "StorageVolumes.h"

configuration AppendFlashAppC {}

implementation
{
  components AppendFlashP,
             MainC,
             new LogStorageC(VOLUME_SENSORLOG, TRUE),
             LedsC;
             
  AppendFlashP.Boot -> MainC;
  AppendFlashP.Leds -> LedsC;
  AppendFlashP.LogRead -> LogStorageC;
  AppendFlashP.LogWrite -> LogStorageC;
}
