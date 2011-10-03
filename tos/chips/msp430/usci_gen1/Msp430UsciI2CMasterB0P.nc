configuration Msp430UsciI2CMasterB0P {
  provides {
    interface I2CPacket<TI2CBasicAddr>[uint8_t client];
    interface ResourceConfigure[uint8_t client];
    interface Msp430UsciError[uint8_t client];
  }
  uses {
    interface Msp430UsciConfigure[ uint8_t client ];
    //TODO: should these not come from the Usci instance?
    interface HplMsp430GeneralIO as URXD;
    interface HplMsp430GeneralIO as UTXD;
  }
} implementation {

  components Msp430UsciB0P as UsciC;
  //masks are module-specific so they need to be passed in.
  //alternately, the masks could be retrieved from the UsciA interface
  components new Msp430UsciI2CMasterP(UCB0TXIE, UCB0RXIE, UCB0TXIFG, UCB0RXIFG) as I2CC;

  I2CC.Usci -> UsciC;
  I2CC.UsciB -> UsciC;
  I2CC.RXInterrupts -> UsciC.RXInterrupts[MSP430_USCI_I2C];
  I2CC.TXInterrupts -> UsciC.TXInterrupts[MSP430_USCI_I2C];
  I2CC.StateInterrupts -> UsciC.StateInterrupts[MSP430_USCI_I2C];
  I2CC.ArbiterInfo -> UsciC;

  Msp430UsciConfigure = I2CC;
  ResourceConfigure = I2CC;
  I2CPacket = I2CC;
  Msp430UsciError = I2CC;
  URXD = I2CC.URXD;
  UTXD = I2CC.UTXD;

  components LocalTimeMilliC;
  UartC.LocalTime_bms -> LocalTimeMilliC;

}
