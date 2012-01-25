/**
 * InternalFlashAC.nc - Internal flash implementation for msp430x2xxx
 * series. This family has 4 64-byte segments:
 *  0x1000 - 0x103f  D
 *  0x1040 - 0x107f  C
 *  0x1080 - 0x10bf  B
 *  0x10c0 - 0x10ff  A
 * 
 * This configuration takes special care of segment A, which is locked
 * independently (and protected during mass erase).
 * 
 * If segment A is unused, writes will write directly to segment A.
 * If segment A is already in use, the sequence is:
 *   Write to segment B, which is marked as "dirty"
 *   Segment A is erased
 *   Segment B is copied to segment A
 *   Segment B is marked "clean"
 * On startup, segment B is checked for whether it's dirty or
 * not. If it's dirty, then we erase segment A and copy to it.
 *
 * The only possibility for data loss which this introduces is the
 * case where:
 *   Write to segment B
 *   Erase segment A
 *   issue a mass-erase command (e.g. through the BSL)
 *
 * This will be hard to do, especially since the window of time
 * available for this to happen after boot is only a few ms long.
 *
 * @author Doug Carlson <carlson@cs.jhu.edu>
 */

configuration InternalFlashAC{
  provides interface InternalFlash;
}
implementation {
  components MainC;
  components InternalFlashAP;

  MainC.SoftwareInit -> InternalFlashAP.Init;

  InternalFlash = InternalFlashAP;
}
