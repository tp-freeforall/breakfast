interface I2CReaderMaster{
  command error_t sample(uint16_t slaveAddr, i2c_message_t* msg);
  event i2c_message_t* sampleDone(error_t error, uint16_t slaveAddr,
    i2c_message_t* cmdMsg, i2c_message_t* responseMsg);
}
