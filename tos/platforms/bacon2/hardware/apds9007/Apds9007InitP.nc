module Apds9007InitP{
  provides interface Init;
  uses interface GeneralIO as PowerPin;
} implementation {
  command error_t Init.init(){
    call PowerPin.makeOutput();
    call PowerPin.clr();
    return SUCCESS;
  }
  
}
