#ifndef INTERNAL_FLASH_FUNCTIONS_H
#define INTERNAL_FLASH_FUNCTIONS_H

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
