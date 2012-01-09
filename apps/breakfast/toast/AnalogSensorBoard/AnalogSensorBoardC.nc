configuration AnalogSensorBoardC{
} implementation {
  components MainC;

  //I2C Clients
  //TODO: I2CADCReaderC
  components I2CPersistentStorageC;
  components I2CTLVStorageC;
  components I2CSynchC;
  
  components I2CComSlaveMultiC;
  components GlobalIDC;

  components AnalogSensorBoardP;
  
  components SerialPrintfC;

  AnalogSensorBoardP.Boot -> MainC.Boot;
  AnalogSensorBoardP.SplitControl -> I2CComSlaveMultiC;
  AnalogSensorBoardP.I2CDiscoverable -> I2CComSlaveMultiC;
  AnalogSensorBoardP.GlobalID -> GlobalIDC;
  
}
