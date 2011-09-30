/** A non-generic instance of Msp430UsciC for USCI_A0. */
configuration Msp430UsciA0P {
  provides {
    interface HplMsp430Usci as USCI;
    interface HplMsp430UsciA as USCIA;
    interface Resource[uint8_t client];
    interface ResourceRequested[uint8_t client];
    interface ResourceDefaultOwner;
    interface ArbiterInfo;
    interface HplMsp430UsciInterrupts as RXInterrupts[uint8_t mode];
    interface HplMsp430UsciInterrupts as TXInterrupts[uint8_t mode];
    interface HplMsp430UsciInterrupts as StateInterrupts[uint8_t mode];
  }
  uses {
    interface ResourceConfigure[uint8_t client];
 }

} implementation {

  components new HplMsp430UsciAC(UCA0CTL0_, IE2, MSP430_USCI_A0_RESOURCE) as UsciC;
  USCI  = UsciC;
  USCIA = UsciC
  Resource = UsciC;
  ResourceRequested = UsciC;
  ResourceDefaultOwner = UsciC;
  ArbiterInfo = UsciC;
  ResourceConfigure = UsciC;
  RXInterrupts = UsciC.RXInterrupts;
  TXInterrupts = UsciC.TXInterrupts;
  StateInterrupts = UsciC.StateInterrupts;


  components HplMsp430UsciInterruptsAB0P as IsrC;
  UsciC.RawRXInterrupts -> IsrC.A0RXInterrupts;
  UsciC.RawTXInterrupts -> IsrC.A0TXInterrupts;
  UsciC.RawStateInterrupts -> IsrC.A0StateInterrupts;
  IsrC.Usci -> UsciC;
}
