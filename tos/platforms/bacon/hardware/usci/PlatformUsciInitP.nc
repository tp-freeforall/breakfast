module PlatformUsciInitP{
  provides interface Init;
} implementation {
  command error_t Init.init(){
    //Bacon board: I2C data on P2.6, clock on P2.7
    atomic{
      PMAPPWD = 0x02D52;
      P2MAP6 = PM_UCB0SDA;
      P2MAP7 = PM_UCB0SCL;
      PMAPPWD = 0x0;
    }
    return SUCCESS;
  }
}
