interface I2CSlave{
  command error_t setOwnAddress(uint16_t addr);
  command error_t enableGeneralCall();
  command error_t disableGeneralCall();
  async event error_t slaveReceive(uint8_t data);
  async event uint8_t slaveTransmit();

  //should these return error so we can say "no, I'm not going to be a
  //slave right now"?
  //TODO: pass bool to indicate whether it's for GC or direct
  async event void slaveStart();
  //or maybe we should pass an error to slaveStop so that the top
  //level can know that it ended abnormally
  async event void slaveStop();
}
