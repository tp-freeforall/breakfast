#include "msp430usart.h"
configuration TestAppC{
} implementation {
  components MainC;
  components TestP;
  components LedsC;
  //components new Msp430I2CC() as I2C;
  components new TimerMilliC();
  //components PlatformSerialC;
  components new Msp430I2CC();

  components new Msp430GpioC() as Pin0;
  components new Msp430GpioC() as Pin1;
  components new Msp430GpioC() as Pin2;
  components new Msp430GpioC() as Pin3;
  components HplMsp430GeneralIOC;
  Pin0.HplGeneralIO -> HplMsp430GeneralIOC.Port60;
  Pin1.HplGeneralIO -> HplMsp430GeneralIOC.Port61;
  Pin2.HplGeneralIO -> HplMsp430GeneralIOC.Port62;
  Pin3.HplGeneralIO -> HplMsp430GeneralIOC.Port63;

  TestP.Boot -> MainC.Boot;
  TestP.Leds -> LedsC;
  TestP.Timer -> TimerMilliC;
  TestP.Pin0 -> Pin0;
  TestP.Pin1 -> Pin1;
  TestP.Pin2 -> Pin2;
  TestP.Pin3 -> Pin3;

  TestP.Resource -> Msp430I2CC.Resource;
  TestP.ResourceRequested -> Msp430I2CC.ResourceRequested;
  TestP.I2CBasicAddr -> Msp430I2CC.I2CBasicAddr;
  Msp430I2CC.Msp430I2CConfigure -> TestP.Msp430I2CConfigure;

//  TestP.UartControl -> PlatformSerialC;
//  TestP.UartStream -> PlatformSerialC;
//  TestP.UartByte -> PlatformSerialC;
} 
