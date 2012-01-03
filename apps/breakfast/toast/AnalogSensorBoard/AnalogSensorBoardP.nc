module AnalogSensorBoardP{
  uses interface Boot;
  uses interface SplitControl;
} implementation {
  event void Boot.booted(){
    call SplitControl.start();
  }

  event void SplitControl.startDone(error_t error){
    //cool
  }

  event void SplitControl.stopDone(error_t error){
  }

}
