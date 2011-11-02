configuration TestAppC{
} implementation {
  components MainC;
  components TestP;
  components LedsC;
  components SerialPrintfC;
  components PlatformSerialC;

  components new Msp430UsciI2CB0C() as I2C;

  TestP.Boot -> MainC;
  TestP.Leds -> LedsC;
  TestP.I2CPacket -> I2C.I2CPacket;
  TestP.I2CSlave -> I2C.I2CSlave;
  TestP.Resource -> I2C.Resource;
  TestP.UartControl -> PlatformSerialC;
  TestP.UartStream -> PlatformSerialC;
}
