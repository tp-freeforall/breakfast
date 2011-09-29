#include "BusPower.h"

generic configuration BusPowerClientC(){
  provides interface SplitControl;
} implementation {
  enum{
    BUS_POWER_CLIENT_ID=unique(UQ_BUS_POWER_CLIENT),
  };
 
  components BusPowerC;
  SplitControl = BusPowerC.SplitControl[BUS_POWER_CLIENT_ID];
}
