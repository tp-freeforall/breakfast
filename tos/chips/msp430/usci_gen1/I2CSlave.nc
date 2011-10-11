interface I2CSlave{
  command error_t setOwnAddress(uint16_t addr);
  command error_t enableGeneralCall();
  command error_t disableGeneralCall();

  //signalled when a byte is sitting in the RXBUF
  // return TRUE if it should be acknowledged, FALSE if it should be
  //   NACKed
  // if you return TRUE, you MUST follow with a call to slaveReceive
  // at some point, preferably very soon.
  async event bool slaveReceiveRequested();
  //retrieve the byte from the RXBUF. Should be called only once
  // for each time that slaveReceiveRequested() is signalled
  async command uint8_t slaveReceive();

  //signalled when a byte is expected in TXBUF.
  // return TRUE if you plan to write to it, FALSE otherwise
  async event bool slaveTransmitRequested();
  async command void slaveTransmit(uint8_t data);

  //should these return error so we can say "no, I'm not going to be a
  //slave right now"?
  async event void slaveStart(bool isGeneralCall);
  //or maybe we should pass an error to slaveStop so that the top
  //level can know that it ended abnormally
  async event void slaveStop();
}
