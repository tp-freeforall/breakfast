configuration TestAppC{
} implementation {
  components MainC;
  components new TimerMilliC();

  components TestP;
  TestP.Boot -> MainC;
  TestP.Timer -> TimerMilliC;

  components new Msp430UsciI2CMasterB0C() as I2CMaster;
  I2CMaster.Msp430UsciConfigure -> TestP.I2CConfigure;
  TestP.I2CBasicAddr -> I2CMaster;
  TestP.I2CResource -> I2CMaster;
  TestP.I2CPacket -> I2CMaster;

  components PlatformSerialC;
  TestP.UartStream -> PlatformSerialC;
  TestP.UartByte -> PlatformSerialC;
  TestP.StdControl -> PlatformSerialC;
}
