/** Interface for the standard interrupts available for a
 * physical-layer client of the radio. */
interface Rf1aInterrupts {

  /** RX FIFO filled or above the RX FIFO threshold or end of packet
   * reached (RFIFG4 positive edge).
   *
   * This is a signal that there is message data available.  
   */
  async event void rxFifoAvailable ();

  /** TX FIFO below TX FIFO threshold (RFIFG5 negative edge).
   *
   * This is a signal that the transmitter is going to need more data
   * soon. */
  async event void txFifoAvailable ();

  /** RX FIFO overflowed (RFIFG7 positive edge).
   *
   * This is a signal that the receive buffer overflowed, and data
   * loss has occurred.  The radio client should take steps to abort
   * reception and reset the radio to its normal idle state. */
  async event void rxOverflow ();

  /** TX FIFO underflowed (RFIFG8 positive edge).
   *
   * This is a signal that data was not supplied for an outgoing
   * transmission, and the receiver will have to drop the packet. */
  async event void txUnderflow ();

  /** Sync word sent or received (RFIFG9 positive edge).
   *
   * This is a signal that a fixed location in the message was
   * transmitted or received.  It can be used for synchronizing the
   * transmitter and receiver. */
  async event void syncWordEvent ();

  /** Clear channel assessment when RSSI is below threshold (dependent
   * on current CCA_MODE setting) (RFIFG12 positive edge).
   *
   * This is a signal that no transmissions are active on the channel.
   * It can be used to determine that it is safe to begin
   * transmitting. */
  async event void clearChannel ();

  /** Carrier sense: RSSI is above threshold (RFIFG13 positive edge).
   *
   * This is a signal that transmissions are active on the channel.
   * It can be used to determine that the radio should prepare to
   * receive a message. */
  async event void carrierSense ();

  /** Any other core interrupt that wasn't recognized */
  async event void coreInterrupt (uint16_t iv);

}

