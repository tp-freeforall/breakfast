/**
 * Define the interrupt handlers for USCI module A0.
 *
 * @author Peter A. Bigot <pab@peoplepowerco.com>
 */

module HplMsp430UsciInterruptsAB0P {
  provides {
    interface HplMsp430UsciInterrupts as InterruptsUCA0Rx;
    interface HplMsp430UsciInterrupts as InterruptsUCA0Tx;
    interface HplMsp430UsciInterrupts as InterruptsUCB0Rx;
    interface HplMsp430UsciInterrupts as InterruptsUCB0Tx;
    interface HplMsp430UsciInterrupts as InterruptsUCB0State;
  }
  uses {
//    interface HplMsp430Usci as Usci;
    interface Leds;
  }
} implementation {

  TOSH_SIGNAL(USCIAB0RX_VECTOR) 
  {
    /* UCA0RXIFG and UCA0RXIE set */
    if ((IFG2 & UCA0RXIFG) && (IE2 & UCA0RXIE) )
    {
      signal InterruptsUCA0Rx.interrupted(IFG2);

    /* UCB0 State change */
    } else {
      signal InterruptsUCB0State.interrupted(IFG2);  
    }
  }

  TOSH_SIGNAL(USCIAB0TX_VECTOR) 
  {        
    /* UCA0TXIFG and UCA0TXIE set */
    if ( (IFG2 & UCA0TXIFG) && (IE2 & UCA0TXIE) )
    {
      signal InterruptsUCA0Tx.interrupted(IFG2);
    }

    /* UCB0RXIFG and UCB0RXIE set */
    else if ( (IFG2 & UCB0RXIFG) && (IE2 & UCB0RXIE) )
    {
      signal InterruptsUCB0Rx.interrupted(IFG2);  
    }

    /* UCB0TXIFG and UCB0TXIE set */
    else if ( (IFG2 & UCB0TXIFG) && (IE2 & UCB0TXIE) )
    {
      signal InterruptsUCB0Tx.interrupted(IFG2);  
    }
  }

  default async event void InterruptsUCB0Rx.interrupted(uint8_t iv){}
  default async event void InterruptsUCB0Tx.interrupted(uint8_t iv){}
  default async event void InterruptsUCB0State.interrupted(uint8_t iv){}
  default async event void InterruptsUCA0Rx.interrupted(uint8_t iv){}
  default async event void InterruptsUCA0Tx.interrupted(uint8_t iv){}

}
