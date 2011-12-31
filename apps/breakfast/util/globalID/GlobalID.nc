interface GlobalID{
  command error_t getID(uint8_t* idBuf, uint8_t maxLen);
  command uint8_t getIDLen();
  command error_t setID(uint8_t* idBuf, uint8_t len);
}
