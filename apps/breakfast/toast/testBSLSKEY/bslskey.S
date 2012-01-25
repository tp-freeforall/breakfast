#ifndef BSLSKEY_VAL
#define BSLSKEY_VAL 0xffff
#endif
.section .bslskey, "a", @progbits
  .global __bslskey
  .word __bslskey
  .equ __bslskey, BSLSKEY_VAL
