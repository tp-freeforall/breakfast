
#include "OneWire.h"

/**
 * See the description in the configuration file
 * @author David Moss
 */
module TestP {
  uses {
    interface Boot;
    interface Read<int16_t> as TemperatureCC;
    interface OneWireDeviceInstanceManager;
    
    interface Leds;
  }
}

implementation {

  // Temperature level indicator thresholds, in degrees celsius * 100
  enum {
    TEMP_LEVEL_0 = 0,     // 32 degrees F
    TEMP_LEVEL_1 = 2250,  // 70 degrees F
    TEMP_LEVEL_2 = 2500,  // 74 degrees F
    TEMP_LEVEL_3 = 2750,  // 78 degrees F
  };
  
  /***************** Tasks ****************/
  task void getTemp() {
    if (call TemperatureCC.read() != SUCCESS) {
      call Leds.set(6);
    }
  }
  
  /***************** Boot Events ****************/
  event void Boot.booted() {
    error_t error;
    
    error = call OneWireDeviceInstanceManager.refresh();
    
    if(error != SUCCESS) {
      call Leds.set(2);
      return;
    }
    
  }

  event void OneWireDeviceInstanceManager.refreshDone(error_t result, bool devicesChanged) {
    onewire_t id;
    if (result == SUCCESS) {
      id = call OneWireDeviceInstanceManager.getDevice(call OneWireDeviceInstanceManager.numDevices()-1);
      call OneWireDeviceInstanceManager.setDevice(id);
      post getTemp();
    }
    else {
      call Leds.set(4);
      return;
    }
  }

  /***************** Read Events ****************/
  event void TemperatureCC.readDone(error_t error, int16_t value) {
    int32_t temp_f;
    if (SUCCESS != error) {
      return;
    }
    temp_f = 3200 + (9 * value) / 5;
    
    call Leds.set(0);
    
    if(value > TEMP_LEVEL_1) {
      call Leds.led0On();
    }
    
    if(value > TEMP_LEVEL_2) {
      call Leds.led1On();
    }
    
    if(value > TEMP_LEVEL_3) {
      call Leds.led2On();
    }
    
    post getTemp();
  }
}
