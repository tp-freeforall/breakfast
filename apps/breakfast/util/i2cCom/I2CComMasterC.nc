generic configuration I2CComMasterC(uint8_t clientId){
  provides interface I2CComMaster;
} implementation {
  components new I2CComMasterP(clientId);
  components new Msp430UsciI2CB0C() as I2CProvider;

  I2CComMasterP.I2CPacket -> I2CProvider.I2CPacket;
  I2CComMasterP.Resource -> I2CProvider.Resource;

  I2CComMaster = I2CComMasterP;
}
