#ifndef BSLSKEY_VAL
#define BSLSKEY_VAL 0x0000
#endif

#if BSLSKEY_VAL == 0xaa55
#warning BSLSKEY Is set to **PREVENT** BSL invocation.  Only install this binary if you plan to (a) never install again (b) program via JTAG or (c) somehow enter the BSL from within the application.
#warning !!!!!!Seriously reconsider what you're doing!!!!!!!!

#elif BSLSKEY_VAL != 0x0000
#warning BSLSKEY is not set to 0x0000. Supplying an incorrect BSL password will trigger mass erase.
#endif

.section .bslskey, "a", @progbits
  .global __bslskey
  .word __bslskey
  .equ __bslskey, BSLSKEY_VAL
