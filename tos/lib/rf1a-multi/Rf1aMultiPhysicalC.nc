/*
 * same interfaces as Rf1aPhysicalC, same client for wiring, etc.
 * plus rf1amulti
 * internally, rf1aconfigure[]
 * each configuration provider plugs into here
 * provide implementation for rf1aconfigure: look at current client
 * and dispatch accordingly.
 */

#include "Rf1a.h"
#include "Rf1aMulti.h"

/** 
 * Adaptation of Rf1aPhysicalC to support multiple radio configurations
 *
 *
 * @author Doug Carlson <carlson@cs.jhu.edu>
 * @author Peter A. Bigot <pab@peoplepowerco.com> 
 */
generic configuration Rf1aMultiPhysicalC () {
  provides {
    interface Rf1aMulti;
    interface HplMsp430Rf1aIf;
    interface Resource;
    interface Rf1aPhysical;
    interface Rf1aPhysicalMetadata;
    interface Rf1aStatus;
    interface DelayedSendRf1aPhysical;
  }
  uses {
    interface Rf1aTransmitFragment;
    //interface Rf1aConfigure;
  }
} implementation {
  enum {
    /** Unique parameter used for this client */
    CLIENT = unique(UQ_RF1A_CLIENT),
  };
  
  components Rf1aC;
  HplMsp430Rf1aIf = Rf1aC;
  Resource = Rf1aC.Resource[CLIENT];
  Rf1aPhysical = Rf1aC.Rf1aPhysical[CLIENT];
  DelayedSendRf1aPhysical = Rf1aC.DelayedSendRf1aPhysical[CLIENT];
  Rf1aTransmitFragment = Rf1aC.Rf1aTransmitFragment[CLIENT];
  //Rf1aConfigure = Rf1aC.Rf1aConfigure[CLIENT];
  Rf1aPhysicalMetadata = Rf1aC;
  Rf1aStatus = Rf1aC;

  components new Rf1aMultiPhysicalP(UQ_RF1A_MULTI_CONFIG_CLIENT);
  Rf1aC.Rf1aConfigure[CLIENT] -> Rf1aMultiPhysicalP.Rf1aConfigure;
  Rf1aMulti = Rf1aMultiPhysicalP;
/* Non-working config! CC430_50KBPS_135KHZBW_HC

  enum{
    CC430_50KBPS_135KHZBW_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components CC430_50KBPS_135KHZBW_HC;
  Rf1aMultiPhysicalP.SubConfigure[CC430_50KBPS_135KHZBW_HC_LOCAL_ID]
    -> CC430_50KBPS_135KHZBW_HC;
  Rf1aMultiPhysicalP.SubGet[CC430_50KBPS_135KHZBW_HC_LOCAL_ID] 
    -> CC430_50KBPS_135KHZBW_HC;

*/
/* Non-working config! CC430_50KBPS_162KHZBW_HC

  enum{
    CC430_50KBPS_162KHZBW_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components CC430_50KBPS_162KHZBW_HC;
  Rf1aMultiPhysicalP.SubConfigure[CC430_50KBPS_162KHZBW_HC_LOCAL_ID]
    -> CC430_50KBPS_162KHZBW_HC;
  Rf1aMultiPhysicalP.SubGet[CC430_50KBPS_162KHZBW_HC_LOCAL_ID] 
    -> CC430_50KBPS_162KHZBW_HC;

*/

  enum{
    CUSTOM_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components CUSTOM_HC;
  Rf1aMultiPhysicalP.SubConfigure[CUSTOM_HC_LOCAL_ID]
    -> CUSTOM_HC;
  Rf1aMultiPhysicalP.SubGet[CUSTOM_HC_LOCAL_ID] 
    -> CUSTOM_HC;

/* Non-working config! RESET_HC

  enum{
    RESET_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components RESET_HC;
  Rf1aMultiPhysicalP.SubConfigure[RESET_HC_LOCAL_ID]
    -> RESET_HC;
  Rf1aMultiPhysicalP.SubGet[RESET_HC_LOCAL_ID] 
    -> RESET_HC;

*/

  enum{
    SRFS6_868_2FSK_1P2K_SENS_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_2FSK_1P2K_SENS_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_2FSK_1P2K_SENS_HC_LOCAL_ID]
    -> SRFS6_868_2FSK_1P2K_SENS_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_2FSK_1P2K_SENS_HC_LOCAL_ID] 
    -> SRFS6_868_2FSK_1P2K_SENS_HC;


  enum{
    SRFS6_868_GFSK_100K_CUR_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_GFSK_100K_CUR_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_GFSK_100K_CUR_HC_LOCAL_ID]
    -> SRFS6_868_GFSK_100K_CUR_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_GFSK_100K_CUR_HC_LOCAL_ID] 
    -> SRFS6_868_GFSK_100K_CUR_HC;


  enum{
    SRFS6_868_GFSK_100K_SENS_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_GFSK_100K_SENS_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_GFSK_100K_SENS_HC_LOCAL_ID]
    -> SRFS6_868_GFSK_100K_SENS_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_GFSK_100K_SENS_HC_LOCAL_ID] 
    -> SRFS6_868_GFSK_100K_SENS_HC;


  enum{
    SRFS6_868_GFSK_10K_CUR_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_GFSK_10K_CUR_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_GFSK_10K_CUR_HC_LOCAL_ID]
    -> SRFS6_868_GFSK_10K_CUR_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_GFSK_10K_CUR_HC_LOCAL_ID] 
    -> SRFS6_868_GFSK_10K_CUR_HC;


  enum{
    SRFS6_868_GFSK_10K_SENS_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_GFSK_10K_SENS_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_GFSK_10K_SENS_HC_LOCAL_ID]
    -> SRFS6_868_GFSK_10K_SENS_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_GFSK_10K_SENS_HC_LOCAL_ID] 
    -> SRFS6_868_GFSK_10K_SENS_HC;


  enum{
    SRFS6_868_GFSK_175K_CUR_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_GFSK_175K_CUR_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_GFSK_175K_CUR_HC_LOCAL_ID]
    -> SRFS6_868_GFSK_175K_CUR_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_GFSK_175K_CUR_HC_LOCAL_ID] 
    -> SRFS6_868_GFSK_175K_CUR_HC;


  enum{
    SRFS6_868_GFSK_175K_SENS_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_GFSK_175K_SENS_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_GFSK_175K_SENS_HC_LOCAL_ID]
    -> SRFS6_868_GFSK_175K_SENS_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_GFSK_175K_SENS_HC_LOCAL_ID] 
    -> SRFS6_868_GFSK_175K_SENS_HC;


  enum{
    SRFS6_868_GFSK_1P2K_CUR_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_GFSK_1P2K_CUR_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_GFSK_1P2K_CUR_HC_LOCAL_ID]
    -> SRFS6_868_GFSK_1P2K_CUR_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_GFSK_1P2K_CUR_HC_LOCAL_ID] 
    -> SRFS6_868_GFSK_1P2K_CUR_HC;


  enum{
    SRFS6_868_GFSK_1P2K_SENS_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_GFSK_1P2K_SENS_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_GFSK_1P2K_SENS_HC_LOCAL_ID]
    -> SRFS6_868_GFSK_1P2K_SENS_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_GFSK_1P2K_SENS_HC_LOCAL_ID] 
    -> SRFS6_868_GFSK_1P2K_SENS_HC;


  enum{
    SRFS6_868_GFSK_250K_CUR_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_GFSK_250K_CUR_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_GFSK_250K_CUR_HC_LOCAL_ID]
    -> SRFS6_868_GFSK_250K_CUR_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_GFSK_250K_CUR_HC_LOCAL_ID] 
    -> SRFS6_868_GFSK_250K_CUR_HC;


  enum{
    SRFS6_868_GFSK_250K_SENS_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_GFSK_250K_SENS_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_GFSK_250K_SENS_HC_LOCAL_ID]
    -> SRFS6_868_GFSK_250K_SENS_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_GFSK_250K_SENS_HC_LOCAL_ID] 
    -> SRFS6_868_GFSK_250K_SENS_HC;


  enum{
    SRFS6_868_GFSK_2P4K_CUR_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_GFSK_2P4K_CUR_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_GFSK_2P4K_CUR_HC_LOCAL_ID]
    -> SRFS6_868_GFSK_2P4K_CUR_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_GFSK_2P4K_CUR_HC_LOCAL_ID] 
    -> SRFS6_868_GFSK_2P4K_CUR_HC;


  enum{
    SRFS6_868_GFSK_2P4K_SENS_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_GFSK_2P4K_SENS_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_GFSK_2P4K_SENS_HC_LOCAL_ID]
    -> SRFS6_868_GFSK_2P4K_SENS_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_GFSK_2P4K_SENS_HC_LOCAL_ID] 
    -> SRFS6_868_GFSK_2P4K_SENS_HC;


  enum{
    SRFS6_868_GFSK_38P4K_CUR_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_GFSK_38P4K_CUR_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_GFSK_38P4K_CUR_HC_LOCAL_ID]
    -> SRFS6_868_GFSK_38P4K_CUR_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_GFSK_38P4K_CUR_HC_LOCAL_ID] 
    -> SRFS6_868_GFSK_38P4K_CUR_HC;


  enum{
    SRFS6_868_GFSK_38P4K_SENS_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_GFSK_38P4K_SENS_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_GFSK_38P4K_SENS_HC_LOCAL_ID]
    -> SRFS6_868_GFSK_38P4K_SENS_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_GFSK_38P4K_SENS_HC_LOCAL_ID] 
    -> SRFS6_868_GFSK_38P4K_SENS_HC;


  enum{
    SRFS6_868_GFSK_4P8K_CUR_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_GFSK_4P8K_CUR_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_GFSK_4P8K_CUR_HC_LOCAL_ID]
    -> SRFS6_868_GFSK_4P8K_CUR_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_GFSK_4P8K_CUR_HC_LOCAL_ID] 
    -> SRFS6_868_GFSK_4P8K_CUR_HC;


  enum{
    SRFS6_868_GFSK_4P8K_SENS_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_GFSK_4P8K_SENS_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_GFSK_4P8K_SENS_HC_LOCAL_ID]
    -> SRFS6_868_GFSK_4P8K_SENS_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_GFSK_4P8K_SENS_HC_LOCAL_ID] 
    -> SRFS6_868_GFSK_4P8K_SENS_HC;


  enum{
    SRFS6_868_GFSK_76P8K_CUR_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_GFSK_76P8K_CUR_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_GFSK_76P8K_CUR_HC_LOCAL_ID]
    -> SRFS6_868_GFSK_76P8K_CUR_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_GFSK_76P8K_CUR_HC_LOCAL_ID] 
    -> SRFS6_868_GFSK_76P8K_CUR_HC;


  enum{
    SRFS6_868_GFSK_76P8K_SENS_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_GFSK_76P8K_SENS_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_GFSK_76P8K_SENS_HC_LOCAL_ID]
    -> SRFS6_868_GFSK_76P8K_SENS_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_GFSK_76P8K_SENS_HC_LOCAL_ID] 
    -> SRFS6_868_GFSK_76P8K_SENS_HC;


  enum{
    SRFS6_868_MSK_500K_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_868_MSK_500K_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_868_MSK_500K_HC_LOCAL_ID]
    -> SRFS6_868_MSK_500K_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_868_MSK_500K_HC_LOCAL_ID] 
    -> SRFS6_868_MSK_500K_HC;


  enum{
    SRFS6_PRE802154G_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_PRE802154G_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_PRE802154G_HC_LOCAL_ID]
    -> SRFS6_PRE802154G_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_PRE802154G_HC_LOCAL_ID] 
    -> SRFS6_PRE802154G_HC;


  enum{
    SRFS6_RESET_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS6_RESET_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS6_RESET_HC_LOCAL_ID]
    -> SRFS6_RESET_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS6_RESET_HC_LOCAL_ID] 
    -> SRFS6_RESET_HC;


  enum{
    SRFS7_779_MSK_250K_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS7_779_MSK_250K_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS7_779_MSK_250K_HC_LOCAL_ID]
    -> SRFS7_779_MSK_250K_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS7_779_MSK_250K_HC_LOCAL_ID] 
    -> SRFS7_779_MSK_250K_HC;

/* Non-working config! SRFS7_868_2FSK_1P2K_SENS_HC

  enum{
    SRFS7_868_2FSK_1P2K_SENS_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS7_868_2FSK_1P2K_SENS_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS7_868_2FSK_1P2K_SENS_HC_LOCAL_ID]
    -> SRFS7_868_2FSK_1P2K_SENS_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS7_868_2FSK_1P2K_SENS_HC_LOCAL_ID] 
    -> SRFS7_868_2FSK_1P2K_SENS_HC;

*/
/* Non-working config! SRFS7_868_GFSK_175K_CUR_HC

  enum{
    SRFS7_868_GFSK_175K_CUR_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS7_868_GFSK_175K_CUR_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS7_868_GFSK_175K_CUR_HC_LOCAL_ID]
    -> SRFS7_868_GFSK_175K_CUR_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS7_868_GFSK_175K_CUR_HC_LOCAL_ID] 
    -> SRFS7_868_GFSK_175K_CUR_HC;

*/
/* Non-working config! SRFS7_868_GFSK_175K_SENS_HC

  enum{
    SRFS7_868_GFSK_175K_SENS_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS7_868_GFSK_175K_SENS_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS7_868_GFSK_175K_SENS_HC_LOCAL_ID]
    -> SRFS7_868_GFSK_175K_SENS_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS7_868_GFSK_175K_SENS_HC_LOCAL_ID] 
    -> SRFS7_868_GFSK_175K_SENS_HC;

*/
/* Non-working config! SRFS7_868_GFSK_1P2K_CUR_HC

  enum{
    SRFS7_868_GFSK_1P2K_CUR_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS7_868_GFSK_1P2K_CUR_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS7_868_GFSK_1P2K_CUR_HC_LOCAL_ID]
    -> SRFS7_868_GFSK_1P2K_CUR_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS7_868_GFSK_1P2K_CUR_HC_LOCAL_ID] 
    -> SRFS7_868_GFSK_1P2K_CUR_HC;

*/
/* Non-working config! SRFS7_868_GFSK_1P2K_SENS_HC

  enum{
    SRFS7_868_GFSK_1P2K_SENS_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS7_868_GFSK_1P2K_SENS_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS7_868_GFSK_1P2K_SENS_HC_LOCAL_ID]
    -> SRFS7_868_GFSK_1P2K_SENS_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS7_868_GFSK_1P2K_SENS_HC_LOCAL_ID] 
    -> SRFS7_868_GFSK_1P2K_SENS_HC;

*/
/* Non-working config! SRFS7_868_GFSK_250K_CUR_HC

  enum{
    SRFS7_868_GFSK_250K_CUR_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS7_868_GFSK_250K_CUR_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS7_868_GFSK_250K_CUR_HC_LOCAL_ID]
    -> SRFS7_868_GFSK_250K_CUR_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS7_868_GFSK_250K_CUR_HC_LOCAL_ID] 
    -> SRFS7_868_GFSK_250K_CUR_HC;

*/
/* Non-working config! SRFS7_868_GFSK_250K_SENS_HC

  enum{
    SRFS7_868_GFSK_250K_SENS_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS7_868_GFSK_250K_SENS_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS7_868_GFSK_250K_SENS_HC_LOCAL_ID]
    -> SRFS7_868_GFSK_250K_SENS_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS7_868_GFSK_250K_SENS_HC_LOCAL_ID] 
    -> SRFS7_868_GFSK_250K_SENS_HC;

*/
/* Non-working config! SRFS7_868_GFSK_38P4K_CUR_HC

  enum{
    SRFS7_868_GFSK_38P4K_CUR_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS7_868_GFSK_38P4K_CUR_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS7_868_GFSK_38P4K_CUR_HC_LOCAL_ID]
    -> SRFS7_868_GFSK_38P4K_CUR_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS7_868_GFSK_38P4K_CUR_HC_LOCAL_ID] 
    -> SRFS7_868_GFSK_38P4K_CUR_HC;

*/
/* Non-working config! SRFS7_868_GFSK_38P4K_SENS_HC

  enum{
    SRFS7_868_GFSK_38P4K_SENS_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS7_868_GFSK_38P4K_SENS_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS7_868_GFSK_38P4K_SENS_HC_LOCAL_ID]
    -> SRFS7_868_GFSK_38P4K_SENS_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS7_868_GFSK_38P4K_SENS_HC_LOCAL_ID] 
    -> SRFS7_868_GFSK_38P4K_SENS_HC;

*/

  enum{
    SRFS7_902P2_GFSK_50K_135B_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS7_902P2_GFSK_50K_135B_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS7_902P2_GFSK_50K_135B_HC_LOCAL_ID]
    -> SRFS7_902P2_GFSK_50K_135B_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS7_902P2_GFSK_50K_135B_HC_LOCAL_ID] 
    -> SRFS7_902P2_GFSK_50K_135B_HC;


  enum{
    SRFS7_902P2_GFSK_50K_163B_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS7_902P2_GFSK_50K_163B_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS7_902P2_GFSK_50K_163B_HC_LOCAL_ID]
    -> SRFS7_902P2_GFSK_50K_163B_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS7_902P2_GFSK_50K_163B_HC_LOCAL_ID] 
    -> SRFS7_902P2_GFSK_50K_163B_HC;

/* Non-working config! SRFS7_RESET_HC

  enum{
    SRFS7_RESET_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS7_RESET_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS7_RESET_HC_LOCAL_ID]
    -> SRFS7_RESET_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS7_RESET_HC_LOCAL_ID] 
    -> SRFS7_RESET_HC;

*/

  enum{
    SRFS7_STI_902_GFSK_1P2K_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS7_STI_902_GFSK_1P2K_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS7_STI_902_GFSK_1P2K_HC_LOCAL_ID]
    -> SRFS7_STI_902_GFSK_1P2K_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS7_STI_902_GFSK_1P2K_HC_LOCAL_ID] 
    -> SRFS7_STI_902_GFSK_1P2K_HC;


  enum{
    SRFS7_STI_902_GFSK_250K_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components SRFS7_STI_902_GFSK_250K_HC;
  Rf1aMultiPhysicalP.SubConfigure[SRFS7_STI_902_GFSK_250K_HC_LOCAL_ID]
    -> SRFS7_STI_902_GFSK_250K_HC;
  Rf1aMultiPhysicalP.SubGet[SRFS7_STI_902_GFSK_250K_HC_LOCAL_ID] 
    -> SRFS7_STI_902_GFSK_250K_HC;


  enum{
    TINYOSRF1A_HC_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components TINYOSRF1A_HC;
  Rf1aMultiPhysicalP.SubConfigure[TINYOSRF1A_HC_LOCAL_ID]
    -> TINYOSRF1A_HC;
  Rf1aMultiPhysicalP.SubGet[TINYOSRF1A_HC_LOCAL_ID] 
    -> TINYOSRF1A_HC;
}
