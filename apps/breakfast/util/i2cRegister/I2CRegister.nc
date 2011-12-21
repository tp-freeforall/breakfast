interface I2CRegister{
  //The provider is saying "A transaction is starting, and you're the
  //  client being addressed. I need a buffer to read from/write to"
  //At this point, the user might call the pause command to indicate
  //  that the buffer it returns is not available yet.
  //Note that while the provider is not paused, this buffer may be
  //  read/written willy-nilly
  async event uint8_t* transactionStart(bool isWrite);

  //The provider is asking "how long is the buffer that you have
  //  given me?"
  async event uint8_t registerLen();

  //The provider is saying "This transaction is done: here's the
  //register that was written to/read from, and this is the current
  //position within it."
  //The provider will not modify this buffer again.
  async event void transactionStop(uint8_t* reg, uint8_t pos);
  
  async command error_t pause();
  async command error_t unPause();

}
