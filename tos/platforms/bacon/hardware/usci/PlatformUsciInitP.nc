module PlatformUsciInitP{
  provides interface Init;
} implementation {
  command error_t Init.init(){
    //Bacon board: I2C data on P2.6, clock on P2.7
    atomic{
      PMAPPWD = PMAPKEY;
      PMAPCTL = PMAPRECFG;
      P2MAP6 = PM_UCB0SDA;
      P2MAP7 = PM_UCB0SCL;
//      P1MAP2 = PM_NONE;
//      P1MAP3 = PM_NONE;
      PMAPPWD = 0x0;
    }
    return SUCCESS;
  }
}
