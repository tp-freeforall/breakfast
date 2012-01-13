interface I2CReaderMaster{
  command error_t sample(uint16_t slaveAddr, i2c_message_t* msg);
  event void sampleDone(error_t error, uint16_t slaveAddr,
    adc_response_t* response, i2c_message_t* msg);
}
