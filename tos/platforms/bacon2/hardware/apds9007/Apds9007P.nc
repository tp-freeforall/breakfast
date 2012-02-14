module Apds9007P{
  provides interface SplitControl;
  uses interface GeneralIO as PowerPin;
} implementation {
  //TODO: DC-- to be completely correct, this should pass the read
  //  interfaces through, and return errors as appropriate if the
  //  sensor's off
  bool on=FALSE;

  task void startDoneTask(){
    signal SplitControl.startDone(SUCCESS);
  }

  task void stopDoneTask(){
    signal SplitControl.stopDone(SUCCESS);
  }

  command error_t SplitControl.start(){
    if (! on){
      call PowerPin.set();
      on = TRUE;
      //TODO: delay for warmup
      post startDoneTask();
      return SUCCESS;
    } else {
      return EALREADY;
    }
  }

  command error_t SplitControl.stop(){
    if (on){
      call PowerPin.clr();
      on = FALSE;
      post stopDoneTask();
      return SUCCESS;
    } else {
      return EALREADY;
    }
  }

  default event void SplitControl.startDone(error_t err){}
  default event void SplitControl.stopDone(error_t err){}
}
