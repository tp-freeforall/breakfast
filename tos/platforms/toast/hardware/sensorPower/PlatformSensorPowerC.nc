configuration PlatformSensorPowerC{
  provides interface GeneralIO[uint8_t channelNum] as SensorPower;
} implementation {
  components HplMsp430GeneralIOC;

  components new Msp430GpioC() as Sensor0,
    new Msp430GpioC() as Sensor1,
    new Msp430GpioC() as Sensor2,
    new Msp430GpioC() as Sensor3,
    new Msp430GpioC() as Sensor4,
    new Msp430GpioC() as Sensor5,
    new Msp430GpioC() as Sensor6,
    new Msp430GpioC() as Sensor7;
  Sensor0.HplGeneralIO -> HplMsp430GeneralIOC.Port43;
  Sensor1.HplGeneralIO -> HplMsp430GeneralIOC.Port44;
  Sensor2.HplGeneralIO -> HplMsp430GeneralIOC.Port45;
  Sensor3.HplGeneralIO -> HplMsp430GeneralIOC.Port46;
  Sensor4.HplGeneralIO -> HplMsp430GeneralIOC.Port50;
  Sensor5.HplGeneralIO -> HplMsp430GeneralIOC.Port51;
  Sensor6.HplGeneralIO -> HplMsp430GeneralIOC.Port52;
  Sensor7.HplGeneralIO -> HplMsp430GeneralIOC.Port53;

  SensorPower[0] = Sensor0;
  SensorPower[1] = Sensor1;
  SensorPower[2] = Sensor2;
  SensorPower[3] = Sensor3;
  SensorPower[4] = Sensor4;
  SensorPower[5] = Sensor5;
  SensorPower[6] = Sensor6;
  SensorPower[7] = Sensor7;
}
