//TODO: parameterize by address type?
interface I2CDiscoverable{
  event uint8_t* getGlobalAddr();
  command uint16_t getLocalAddr();
}
