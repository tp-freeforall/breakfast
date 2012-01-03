#include "I2CADCReader.h"
configuration I2CADCReaderC{
} implementation {
  components I2CMultiRegisterC;
  components I2CADCReaderP;
  components new Msp430Adc12ClientC();
  components PlatformSensorPowerC;
  components new TimerMilliC();

  I2CADCReaderP.I2CRegister -> I2CMultiRegisterC.I2CRegister[REGISTER_CLIENT_ID_ADCREADER];
  I2CADCReaderP.Resource -> Msp430Adc12ClientC;
  I2CADCReaderP.Msp430Adc12SingleChannel -> Msp430Adc12ClientC;
  I2CADCReaderP.SensorPower -> PlatformSensorPowerC;
  I2CADCReaderP.Timer -> TimerMilliC;
}
