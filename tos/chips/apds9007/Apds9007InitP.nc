module Apds9007InitP{
  provides interface Init;
  uses interface GeneralIO as ShutdownPin;
} implementation {
  command error_t Init.init(){
    call ShutdownPin.makeOutput();
    call ShutdownPin.set();
    return SUCCESS;
  }
  
}
