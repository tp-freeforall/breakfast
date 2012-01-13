#include "I2CADCReader.h"
configuration I2CADCReaderC{
} implementation {
  components I2CComSlaveMultiC;
  components I2CADCReaderP;
  components new Msp430Adc12ClientC();
  components PlatformSensorPowerC;
  components new TimerMilliC();
  components LocalTime32khzC;

  I2CADCReaderP.I2CComSlave -> I2CComSlaveMultiC.I2CComSlave[I2C_COM_CLIENT_ID_ADCREADER];
  I2CADCReaderP.Resource -> Msp430Adc12ClientC;
  I2CADCReaderP.Msp430Adc12SingleChannel -> Msp430Adc12ClientC;
  I2CADCReaderP.SensorPower -> PlatformSensorPowerC;
  I2CADCReaderP.Timer -> TimerMilliC;
  I2CADCReaderP.LocalTime -> LocalTime32khzC;
}
