interface I2CPersistentStorageMaster {
  command void* getPayload(i2c_message_t* msg);

  command error_t read(uint16_t slaveAddr, i2c_message_t* msg);
  event void readDone(error_t error, i2c_message_t* msg);

  command error_t write(uint16_t slaveAddr, i2c_message_t* msg);
  event void writeDone(error_t error, i2c_message_t* msg);
}
