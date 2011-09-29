module NoCC1190P{
  provides interface Init;
  provides interface StdControl;
  provides interface CC1190;
  uses interface GeneralIO as HGMPin;
  uses interface GeneralIO as LNA_ENPin;
  uses interface GeneralIO as PA_ENPin;
  uses interface GeneralIO as PowerPin;
} implementation {
  command error_t Init.init(){ 
    call HGMPin.makeOutput();
    call HGMPin.clr();
    call LNA_ENPin.makeOutput();
    call LNA_ENPin.makeOutput();
    call PA_ENPin.clr();
    call PA_ENPin.clr();
    call PowerPin.makeOutput();
    call PowerPin.clr();
    return SUCCESS; 
  }
  command error_t StdControl.start(){ return SUCCESS;}
  command error_t StdControl.stop(){ return SUCCESS;}
  command void CC1190.RXMode(uint8_t hgm){}
  command void CC1190.TXMode(uint8_t hgm){}
}
