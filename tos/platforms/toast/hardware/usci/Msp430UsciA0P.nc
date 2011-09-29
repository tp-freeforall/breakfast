/** A non-generic instance of Msp430UsciC for USCI_A0. */
configuration Msp430UsciA0P {
  provides {
    interface HplMsp430Usci as USCI;
    interface Resource[uint8_t client];
    interface ResourceRequested[uint8_t client];
    interface ResourceDefaultOwner;
    interface ArbiterInfo;
    interface HplMsp430UsciInterrupts as InterruptsRx[uint8_t mode];
    interface HplMsp430UsciInterrupts as InterruptsTx[uint8_t mode];
  }
  uses {
    interface ResourceConfigure[uint8_t client];
 }

} implementation {

  components new HplMsp430UsciA0C(MSP430_USCI_A0_RESOURCE) as UsciC;
  USCI  = UsciC;
  Resource = UsciC;
  ResourceRequested = UsciC;
  ResourceDefaultOwner = UsciC;
  ArbiterInfo = UsciC;
  ResourceConfigure = UsciC;
  InterruptsRx = UsciC.InterruptsRx;
  InterruptsTx = UsciC.InterruptsTx;

  components HplMsp430UsciInterruptsAB0P as IsrC;
  UsciC.RawInterruptsRx -> IsrC.InterruptsUCA0Rx;
  UsciC.RawInterruptsTx -> IsrC.InterruptsUCA0Tx;
//  IsrC.Usci -> UsciC;
}
