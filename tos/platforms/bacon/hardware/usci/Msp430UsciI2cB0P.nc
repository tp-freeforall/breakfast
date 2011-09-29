configuration Msp430UsciI2cB0P {
  provides {
    interface I2CPacket[ uint8_t client ];
//    interface Msp430UsciError;
    interface ResourceConfigure[ uint8_t client ];
  }
  uses {
    interface Msp430UsciConfigure[ uint8_t client ];
    interface HplMsp430GeneralIO as SDA;
    interface HplMsp430GeneralIO as SCL;
 }
} implementation {

  components Msp430UsciB0P as UsciC;

  components new Msp430UsciI2cP() as I2cC;
  I2cC.Usci -> UsciC;
  I2cC.Interrupts -> UsciC.Interrupts[MSP430_USCI_SPI];
  I2cC.ArbiterInfo -> UsciC;

  Msp430UsciConfigure = I2cC;
  ResourceConfigure = I2cC;
  I2cPacket = I2cC;
//  I2cByte = I2cC;
//  Msp430UsciError = I2cC;
  SDA = I2cC.SDA;
  SCL = I2cC.SCL;
}
