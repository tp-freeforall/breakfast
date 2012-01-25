#include "GlobalID.h"
module AnalogSensorBoardP{
  uses interface Boot;
  uses interface SplitControl;
  uses interface GlobalID;
  uses interface I2CDiscoverable;
} implementation {
  uint8_t globalId[GLOBAL_ID_LEN];

  event void Boot.booted(){
    //TODO: check for lastLocalAddr in flash and call
    //  I2CDiscoverable.setLocalAddr before starting
    printf("booted\n\r");
    call SplitControl.start();
  }

  event uint8_t* I2CDiscoverable.getGlobalAddr(){
    call GlobalID.getID(globalId, GLOBAL_ID_LEN);
    return globalId;
  }

  event void SplitControl.startDone(error_t error){
    //cool
  }

  event void SplitControl.stopDone(error_t error){
  }

  event void I2CDiscoverable.assigned(error_t err, uint16_t lastLocalAddr){
    //TODO: persist lastLocalAddr to flash (replace previous)
  }

}
