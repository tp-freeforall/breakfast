#include "msp430usci.h"
configuration ToastAppC{}
implementation {
  components MainC, ToastC;

  MainC.Boot <- ToastC;

  components new Msp430I2CC() as I2CC;
  ToastC.I2CResource -> I2CC;
//  ToastC.I2CResourceRequested -> I2CC;
  ToastC.I2CBasicAddr -> I2CC;

//  I2CC.Msp430UsciConfigure -> ToastC;
  
  components PlatformSerialC;
  ToastC.UartControl -> PlatformSerialC;
  ToastC.UartStream -> PlatformSerialC;
  ToastC.UartByte -> PlatformSerialC;
}

