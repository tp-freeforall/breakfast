configuration I2CSynchMasterC{
  provides interface I2CSynchMaster;
} implementation {
  components I2CSynchMasterP;
  components LocalTime32khzC;
  components new I2CComMasterC(I2C_COM_CLIENT_ID_SYNCH);

  I2CSynchMasterP.I2CComMaster -> I2CComMasterC;
  I2CSynchMasterP.LocalTime -> LocalTime32khzC;

  I2CSynchMaster = I2CSynchMasterP;
}
