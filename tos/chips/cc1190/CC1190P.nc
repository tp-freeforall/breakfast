module CC1190P{
  provides interface StdControl;
  provides interface Init;
  provides interface CC1190;

  uses interface GeneralIO as HGMPin;
  uses interface GeneralIO as LNA_ENPin;
  uses interface GeneralIO as PA_ENPin;
  uses interface GeneralIO as PowerPin;
} implementation {

  #warning "Test: using real CC1190 impl"
  //starts in LGM receive mode
  command error_t StdControl.start(){
    call PowerPin.set();
    return SUCCESS;
  }

  command error_t StdControl.stop(){
    //TODO: lowest-current settings for control pins
    call PowerPin.clr();
    return SUCCESS;
  }

  //pin directions, powered down
  command error_t Init.init(){
    call HGMPin.makeOutput();
    call HGMPin.clr();
    call LNA_ENPin.makeOutput();
    call LNA_ENPin.clr();
    call PA_ENPin.makeOutput();
    call PA_ENPin.clr();

    call PowerPin.makeOutput();
    call PowerPin.clr();

    return SUCCESS;
  }

  command void CC1190.RXMode(uint8_t hgm){
    call PA_ENPin.clr();
    call LNA_ENPin.set();
    if (hgm){
      call HGMPin.set();
    } else {
      call HGMPin.clr();
    }
  }

  command void CC1190.TXMode(uint8_t hgm){
    call PA_ENPin.set();
    call LNA_ENPin.clr();
    if (hgm){
      call HGMPin.set();
    } else {
      call HGMPin.clr();
    }
  }

}
