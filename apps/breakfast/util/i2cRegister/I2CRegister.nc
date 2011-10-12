interface I2CRegister{
  //signalled when start condition received
  //- this can happen multiple times in a row in the case of
  //repeated-starts
  async event void transactionStart(bool generalCall);

  //signalled when start condition received
  //- Must return a pointer to a buffer of length >= len
  //- The provider of this interface gets exclusive use to the
  //  returned buffer.
  //- According to the I2C standards, the first non-address byte of a
  //  GC write is either:
  //  - the 7-bit master address (indicated by LSB=1, address in upper
  //    7 bits)
  //  - 0x06: reset and program address
  //  - 0x04: program address
  //  - anything else: supposed to be ignored.
  //- 0x00 is explicitly disallowed from being used in this position,
  //so if gcCmd is 0x00, this indicates "no gcCmd"
  async event uint8_t* transactionStop(uint8_t* reg, uint8_t len, uint8_t gcCmd);

  async command error_t pause();
  async command error_t unPause();

  command void setOwnAddress(uint16_t addr);

}
