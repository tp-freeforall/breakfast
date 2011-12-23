/**
 * InternalFlashC.nc - Internal flash implementation for msp430x2xxx
 * series. This family has 4 64-byte segments:
 *  0x1000 - 0x103f  D
 *  0x1040 - 0x107f  C
 *  0x1080 - 0x10bf  B
 *  0x10c0 - 0x10ff  A
 * 
 * Segment A is locked independently of the other segments, but this
 * implementation *does not* give it any special attention otherwise.
 *
 * This configuration exposes all 4 64-byte segments.
 *
 * Addresses must be between 0 and 63 (0x3f). The highest order byte
 * of each segment is reserved for version tracking (though only
 * 0x10FF is used for this purpose).  When new data is written, the
 * oldest segment is erased and the data is stored there. The current
 * segment number is updated after an erase/write and is about as
 * atomic as an operation can get, so this should prevent data loss if
 * a failure occurs in the middle of an operation.
 * 
 *
 * @author Doug Carlson <carlson@cs.jhu.edu>
 */

configuration InternalFlashC{
  provides interface InternalFlash;
}
implementation {
  components new InternalFlashx2xxC(0x1000, 4);
  InternalFlash = InternalFlashx2xxC;
}
