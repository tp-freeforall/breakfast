#ifndef INTERNAL_FLASH_H
#define INTERNAL_FLASH_H

#define IFLASH_A_START (void*)0x10c0
#define IFLASH_A_END   (void*)0x10ff
#define IFLASH_B_START (void*)0x1080
#define IFLASH_B_END   (void*)0x10bf
#define IFLASH_C_START (void*)0x1040
#define IFLASH_C_END   (void*)0x107f
#define IFLASH_D_START (void*)0x1000
#define IFLASH_D_END   (void*)0x103f

#define IFLASH_SEGMENT_SIZE   64

//unlock: writing 1 to LOCKA *toggles* it, it doesn't set it.
//Writing 0 has no effect. SO, we want to write 1 if the bit is
//already set
void unlockInternalFlash(volatile void* ptr){
  if ( ptr >= IFLASH_A_START && ptr <= IFLASH_A_END){
    FCTL3 = FWKEY + (FCTL3 & LOCKA);
  } else {
    FCTL3 = FWKEY;
  }
}

//lock: LOCKA & (FCTL3 ^ LOCKA) = 0 if already locked, 1 if not
void lockInternalFlash(volatile void* ptr){
  if ( ptr >= IFLASH_A_START && ptr <= IFLASH_A_END){
    FCTL3 = FWKEY + LOCK + (LOCKA & (FCTL3 ^ LOCKA));
  } else {
    FCTL3 = FWKEY + LOCK;
  }
}

#endif
