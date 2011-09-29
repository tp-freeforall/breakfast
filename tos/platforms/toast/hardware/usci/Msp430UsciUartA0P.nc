configuration Msp430UsciUartA0P {
  provides {
    interface UartStream[uint8_t client];
    interface UartByte[uint8_t client];
    interface ResourceConfigure[uint8_t client];
    interface Msp430UsciError[uint8_t client];
  }
  uses {
    interface Msp430UsciConfigure[ uint8_t client ];
    interface HplMsp430GeneralIO as URXD;
    interface HplMsp430GeneralIO as UTXD;
  }
} implementation {

  components Msp430UsciA0P as UsciC;

  components new Msp430UsciUartA0P1() as UartC;

  UartC.Usci -> UsciC;
  UartC.InterruptsRx -> UsciC.InterruptsRx[MSP430_USCI_UART];
  UartC.InterruptsTx -> UsciC.InterruptsTx[MSP430_USCI_UART];
  UartC.ArbiterInfo -> UsciC;

  Msp430UsciConfigure = UartC;
  ResourceConfigure = UartC;
  UartStream = UartC;
  UartByte = UartC;
  Msp430UsciError = UartC;
  URXD = UartC.URXD;
  UTXD = UartC.UTXD;

  components LocalTimeMilliC;
  UartC.LocalTime_bms -> LocalTimeMilliC;

}
