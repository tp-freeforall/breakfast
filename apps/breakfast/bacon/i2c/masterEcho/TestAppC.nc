configuration TestAppC{
} implementation {
  components MainC;
  components TestP;
  components new TimerMilliC();
  components LedsC;
  components SerialPrintfC;

  components new Msp430UsciI2CB0C() as I2C;

  TestP.Boot -> MainC;
  TestP.Leds -> LedsC;
  TestP.Timer -> TimerMilliC;
  TestP.I2CPacket -> I2C.I2CPacket;
  TestP.I2CSlave -> I2C.I2CSlave;
  TestP.Resource -> I2C.Resource;
}
