/** A component that supports transmitting and receiving bare packets
 * using the RF1A infrastructure.
 *
 * @param BUFFER_SIZE The number of octets reserved for each of the
 * transmission and reception buffers.
 *
 * @author Peter A. Bigot <pab@peoplepowerco.com>
 */
generic configuration BareRf1aC (unsigned int BUFFER_SIZE) {
  provides {
    interface BareTxRx;
    interface BareMetadata;
    interface SplitControl;
  }
} implementation {
  components new BareRf1aP(BUFFER_SIZE);

  components new Rf1aPhysicalC();
  BareRf1aP.Resource -> Rf1aPhysicalC;
  BareRf1aP.Rf1aPhysical -> Rf1aPhysicalC;
  BareRf1aP.Rf1aPhysicalMetadata -> Rf1aPhysicalC;
  
  BareTxRx = BareRf1aP;
  BareMetadata = BareRf1aP;
  SplitControl = BareRf1aP;
}
