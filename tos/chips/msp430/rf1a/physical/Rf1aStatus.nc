#include "Rf1a.h"
interface Rf1aStatus {
  /** Return a value indicating the status of the radio.  The value is
   * one of the enumeration values of rf1a_status_e (excepting RF1A_S_MASK) */
  async command rf1a_status_e get ();
}
