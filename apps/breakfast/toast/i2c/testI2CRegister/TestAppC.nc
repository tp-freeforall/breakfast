#include <stdio.h>
configuration TestAppC{
} implementation {
  components MainC;
  components TestP;
  components PlatformSerialC;
  components SerialPrintfC;

  components new EchoRegisterC(10);
  components I2CMultiRegisterC;

  components new I2CDiscovererC();
  components new Msp430UsciI2CB0C();

  TestP.Boot -> MainC.Boot;

  TestP.SplitControl -> I2CMultiRegisterC;
  TestP.I2CDiscoverable -> I2CMultiRegisterC;

  TestP.I2CPacket -> Msp430UsciI2CB0C.I2CPacket;
  TestP.Resource -> Msp430UsciI2CB0C.Resource;

  TestP.I2CDiscoverer -> I2CDiscovererC;

  TestP.UartStream -> PlatformSerialC.UartStream;
  TestP.UartByte -> PlatformSerialC.UartByte;
  TestP.UartControl -> SerialPrintfC.StdControl;
}
