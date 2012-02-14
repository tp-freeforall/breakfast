#include "Msp430Adc12.h"

configuration PlatformApds9007C{
  provides interface GeneralIO as PowerPin;
  provides interface AdcConfigure<const msp430adc12_channel_config_t *>;
} implementation {
  components PlatformApds9007P;
  AdcConfigure = PlatformApds9007P;
  
  components HplMsp430GeneralIOC;
  components new Msp430GpioC();
  Msp430GpioC.HplGeneralIO -> HplMsp430GeneralIOC.Port33;
  PowerPin = Msp430GpioC;
}
