#include "I2CDiscoverable.h"

interface I2CDiscoverer{
  event uint16_t getLocalAddr();
  event discoverer_register_union_t* discovered(discoverer_register_union_t* discovery);
  command error_t startDiscovery(bool reset);
  event void discoveryDone(error_t error);
}
