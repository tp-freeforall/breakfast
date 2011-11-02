//TODO: parameterize by address type?
interface I2CDiscoverable{
  event uint8_t* getGlobalAddr();
  command uint16_t getLastLocalAddr();
  command error_t startDiscoverable(uint16_t lastLocalAddr);
  event void endDiscoverable(error_t err, uint16_t lastLocalAddr);
}
