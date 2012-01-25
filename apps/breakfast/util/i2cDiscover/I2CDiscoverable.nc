//TODO: parameterize by address type?
interface I2CDiscoverable{
  event uint8_t* getGlobalAddr();
  command uint16_t getLastLocalAddr();
  command void setLocalAddr(uint16_t lastLocalAddr);
  event void assigned(error_t err, uint16_t lastLocalAddr);
}
