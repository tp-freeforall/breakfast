module PlatformAdcP{
  provides interface Init;
} implementation {

  command error_t Init.init(){
    #warning "PlatformAdcP.init wired"
    atomic{
      PMAPPWD = PMAPKEY;
      PMAPCTL = PMAPRECFG;
      P2MAP0 = PM_ANALOG;
      P2MAP1 = PM_ANALOG;
      P2MAP2 = PM_ANALOG;
      P2MAP3 = PM_ANALOG;
      P2MAP4 = PM_ANALOG;
      P2MAP5 = PM_ANALOG;
      PMAPPWD = 0;
    }
    return SUCCESS;
  }
}
