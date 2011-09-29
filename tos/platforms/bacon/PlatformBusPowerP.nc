module PlatformBusPowerP{
  provides interface Init;
  provides interface SplitControl;
  uses interface GeneralIO as EnablePin;
} implementation {
  bool on = FALSE;
  command error_t Init.init(){
    call EnablePin.makeOutput();
    call EnablePin.clr();
    return SUCCESS;
  }

  task void startDoneTask(){
    signal SplitControl.startDone(SUCCESS);
  }
  task void stopDoneTask(){
    signal SplitControl.stopDone(SUCCESS);
  }

  command error_t SplitControl.start(){
    if (on){
      return EALREADY;
    }else {
      on = TRUE;
      call EnablePin.set();
      post startDoneTask();
      return SUCCESS;
    }
  }

  command error_t SplitControl.stop(){
    if (on){
      on = FALSE;
      call EnablePin.clr();
      post stopDoneTask();
      return SUCCESS;
    } else {
      return EALREADY;
    }
  }

  default event void SplitControl.startDone(error_t err){}
  default event void SplitControl.stopDone(error_t err){}
}
