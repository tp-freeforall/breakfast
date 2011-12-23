#include "InternalFlash.h"

module InternalFlashAP{
  provides interface InternalFlash;
  provides interface Init;
} implementation {
  volatile uint8_t* bStatus = (uint8_t*)IFLASH_B_END;
  volatile uint8_t* aStatus = (uint8_t*)IFLASH_A_END;
  
  enum{
    IFA_ERASED = 0xff,
    IFA_DIRTY = 0xfe,
    IFA_CLEAN = 0xfc,
  };

  
  error_t copyIfNeeded(bool lockWhenFinished){
    if (*bStatus == IFA_DIRTY){
      unlockInternalFlash(aStatus);
      FCTL1 = FWKEY + ERASE;
      //erase A
      *aStatus = 0;
      FCTL1 = FWKEY + WRT;
      memcpy(IFLASH_A_START, IFLASH_B_START, IFLASH_SEGMENT_SIZE);
      *aStatus = IFA_CLEAN;
      *bStatus = IFA_CLEAN;
      lockInternalFlash(aStatus);
    }
    return SUCCESS;
  }
  

  command error_t Init.init(){
    //TODO: this divider should be set with the rest of the clock
    //setup
    FCTL2 = FWKEY + FSSEL_1 + 11;
    return copyIfNeeded(TRUE);
  }

  command error_t InternalFlash.read(void* addr, void* buf, uint16_t size){
    if (*bStatus == IFA_DIRTY){
      return FAIL;
    }
    if ((uint16_t)addr + size  > IFLASH_SEGMENT_SIZE - 1){
      return ESIZE;
    }
    memcpy(buf, (void*)((uint16_t)addr + IFLASH_A_START), size);
    return SUCCESS;
  }

  command error_t InternalFlash.write(void* addr, void* buf, uint16_t size){
    if (*bStatus == IFA_DIRTY){
      return FAIL;
    }
    if ((uint16_t)addr + size  > IFLASH_SEGMENT_SIZE - 1){
      return ESIZE;
    }
    unlockInternalFlash(IFLASH_B_START);
    FCTL1 = FWKEY + ERASE;
    //erase B
    *bStatus = 0;
    FCTL1 = FWKEY + WRT;
    memcpy((IFLASH_B_START + (uint16_t)addr), buf, size);
    *bStatus = IFA_DIRTY;
    return copyIfNeeded(TRUE);
  }
}
