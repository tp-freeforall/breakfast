configuration AnalogSensorBoardC{
} implementation {
  components MainC;

  //I2C Clients
  //TODO: I2CADCReaderC
  components I2CPersistentStorageC;
  //TODO: I2CTLVStorageC
  
  components I2CMultiRegisterC;
  components GlobalIDC;

  components AnalogSensorBoardP;
  
  components SerialPrintfC;

  AnalogSensorBoardP.Boot -> MainC.Boot;
  AnalogSensorBoardP.SplitControl -> I2CMultiRegisterC;
  AnalogSensorBoardP.I2CDiscoverable -> I2CMultiRegisterC;
  AnalogSensorBoardP.GlobalID -> GlobalIDC;
  
}
