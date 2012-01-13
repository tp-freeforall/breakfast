module I2CADCReaderMasterP{
  provides interface I2CADCReaderMaster;
  uses interface I2CComMaster;
  uses interface Timer<TMilli>;
} implementation {
  command error_t I2CADCReaderMaster.sample(uint16_t slaveAddr,
      i2c_message_t* msg){
    //TODO: write to slave
    return FAIL;
  }
  event void I2CComMaster.sendDone(){
    //TODO: Add up delays, set timer for this + standard delay
  }
  event void Timer.fired(){
    //TODO: read back results from slave
  }
  event void I2CComMaster.receiveDone(){
    //TODO: signal results up to master
  }
}
