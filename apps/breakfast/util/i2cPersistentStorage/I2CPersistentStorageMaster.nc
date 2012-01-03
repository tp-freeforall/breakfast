interface I2CPersistentStorageMaster {
  command error_t read(uint16_t slaveAddr, void* data);
  event void readDone(error_t error, void* data);

  command error_t write(uint16_t slaveAddr, void* data);
  event void writeDone(error_t error, void* data);
}
