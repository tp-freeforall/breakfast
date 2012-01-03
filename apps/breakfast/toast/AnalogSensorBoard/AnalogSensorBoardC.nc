configuration AnalogSensorBoardC{
} implementation {
  components MainC;

  //I2C Clients
  components I2CADCReaderC;
  //TODO: I2CPersistentStorageC
  //TODO: I2CTLVStorageC
  
  components I2CMultiRegisterC;

  components AnalogSensorBoardP;

  AnalogSensorBoardP.Boot -> MainC.Boot;
  AnalogSensorBoardP.SplitControl -> I2CMultiRegisterC;
  
}
