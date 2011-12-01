#include "Msp430Adc12.h"
configuration ExternalPhotoC{
  provides interface Read<uint16_t>;
} implementation {
  components new AdcReadClientC();
  components ExternalPhotoP;
  
  AdcReadClientC.AdcConfigure -> ExternalPhotoP;

  Read = AdcReadClientC;
}
