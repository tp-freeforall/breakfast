configuration Msp430UsciI2CB0P {
  provides {
    interface I2CPacket<TI2CBasicAddr>[uint8_t client];
    interface I2CSlave[uint8_t client];
    interface ResourceConfigure[uint8_t client];
    interface Msp430UsciError[uint8_t client];
  }
  uses {
    interface Msp430UsciConfigure[ uint8_t client ];
    interface HplMsp430GeneralIO as SCL;
    interface HplMsp430GeneralIO as SDA;
  }
} implementation {

  components Msp430UsciB0P as UsciC;

  components new Msp430UsciI2CP() as I2CC;

  I2CC.Usci -> UsciC;
  //TODO: might need to define MSP430_USCI_I2C symbol
  I2CC.Interrupts -> UsciC.Interrupts[MSP430_USCI_I2C];
  I2CC.ArbiterInfo -> UsciC;

  Msp430UsciConfigure = I2CC;
  ResourceConfigure = I2CC;
  I2CPacket = I2CC;
  I2CSlave = I2CC;
  Msp430UsciError = I2CC;
  SCL = I2CC.SCL;
  SDA = I2CC.SDA;

  components LocalTimeMilliC;
  I2CC.LocalTime_bms -> LocalTimeMilliC;

}
