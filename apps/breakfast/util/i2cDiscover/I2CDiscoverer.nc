#include "I2CDiscoverable.h"

interface I2CDiscoverer{
  event uint16_t getLocalAddr();
  async event void discovered(discoverer_register_union_t* discovery);
  command error_t startDiscovery();
  event void discoveryDone(error_t error);
}
