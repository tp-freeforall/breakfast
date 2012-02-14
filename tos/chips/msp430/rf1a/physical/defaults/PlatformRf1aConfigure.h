#ifndef PLATFORM_RF1A_CONFIGURE_H
#define PLATFORM_RF1A_CONFIGURE_H
#warning "Using default PlatformRf1aConfigure.h"

/** The default values are read from a file named smartrf_RF1A.h,
 * which should contain register settings as exported from SmartRF
 * Studio using the SimplicitTI settings template. */
#if TINYOS_SMARTRF_USE_CUSTOM
#warning RF1A Custom (remember to define RF1A_CHANNEL_{MIN,MAX})
#include <smartrf/CUSTOM.h>
#elif TINYOS_SMARTRF_USE_LEGACY
/* Legacy configuration */
#warning RF1A using legacy configuration
#include "smartrf_RF1A.h"
#elif TINYOS_SMARTRF_802_15_4C
#warning RF1A using 779-787 MHz-based 250kbps MSK PHY
#include <smartrf/SRFS7_779_MSK_250K.h>
#else
#warning RF1A using 902.2 MHz-based 50Kbps 135kHz BW 802.15.4g PHY
#include <smartrf/SRFS7_902p2_GFSK_50K_135B.h>
#endif

#ifndef RF1A_CHANNEL_MIN
/** The minimum legal value to use when assigning a channel.  Best
 * practice is that channel zero has a base (not center) frequency at
 * the lower bound of your region's ISM band (902MHz in the US). */
#define RF1A_CHANNEL_MIN 0
#endif /* RF1A_CHANNEL_MIN */

#ifndef RF1A_CHANNEL_MAX
/** The maximum legal value to use when assigning a channel.  Best
 * practice is that this channel spans up to but not beyond the upper
 * bound of your region's ISM band (928MHz in the US). */
#define RF1A_CHANNEL_MAX 128
#endif /* RF1A_CHANNEL_MIN */

#ifndef SMARTRF_SETTING_IOCFG0
/* Work around bogus register name emitted in early versions of
 * SmartRF Studio */
#define SMARTRF_SETTING_IOCFG0 SMARTRF_SETTING_IOCFG0D
#endif /* SMARTRF_SETTING_IOCFG0 */

/* @TODO@ move this out of the header so it can be more easily overridden */
rf1a_config_t rf1a_default_config = {
  iocfg2: SMARTRF_SETTING_IOCFG2,
#if defined(SMARTRF_SETTING_IOCFG1)
  iocfg1: SMARTRF_SETTING_IOCFG1,
#else // IOCFG1
  iocfg1: 0x2e, // tristate
#endif // IOCFG1
  iocfg0: SMARTRF_SETTING_IOCFG0,
  fifothr: SMARTRF_SETTING_FIFOTHR,
#if defined(SMARTRF_SETTING_SYNC1)
  sync1: SMARTRF_SETTING_SYNC1,
  sync0: SMARTRF_SETTING_SYNC0,
#else
  sync1: 0xd3,
  sync0: 0x91,
#endif
  pktlen: SMARTRF_SETTING_PKTLEN,
  pktctrl1: SMARTRF_SETTING_PKTCTRL1,
  pktctrl0: SMARTRF_SETTING_PKTCTRL0,
  addr: SMARTRF_SETTING_ADDR,
#ifdef USER_SETTING_CHANNR
  channr: USER_SETTING_CHANNR,
#else
  channr: SMARTRF_SETTING_CHANNR,
#endif
  fsctrl1: SMARTRF_SETTING_FSCTRL1,
  fsctrl0: SMARTRF_SETTING_FSCTRL0,
  freq2: SMARTRF_SETTING_FREQ2,
  freq1: SMARTRF_SETTING_FREQ1,
  freq0: SMARTRF_SETTING_FREQ0,
  mdmcfg4: SMARTRF_SETTING_MDMCFG4,
  mdmcfg3: SMARTRF_SETTING_MDMCFG3,
  mdmcfg2: SMARTRF_SETTING_MDMCFG2,
  mdmcfg1: SMARTRF_SETTING_MDMCFG1,
  mdmcfg0: SMARTRF_SETTING_MDMCFG0,
  deviatn: SMARTRF_SETTING_DEVIATN,
#if defined(SMARTRF_SETTING_MCSM2)
  mcsm2: SMARTRF_SETTING_MCSM2,
#else // MCSM2
  mcsm2: 0x07,
#endif // MCSM2
#if defined(SMARTRF_SETTING_MCSM1)
  mcsm1: SMARTRF_SETTING_MCSM1,
#else // MCSM1
  mcsm1: 0x30,
#endif // MCSM1
  mcsm0: SMARTRF_SETTING_MCSM0,
  foccfg: SMARTRF_SETTING_FOCCFG,
  bscfg: SMARTRF_SETTING_BSCFG,
  agcctrl2: SMARTRF_SETTING_AGCCTRL2,
  agcctrl1: SMARTRF_SETTING_AGCCTRL1,
  agcctrl0: SMARTRF_SETTING_AGCCTRL0,
#if defined(SMARTRF_SETTING_WOREVT1)
  worevt1: SMARTRF_SETTING_WOREVT1,
#else // WOREVT1
  worevt1: 0x80,
#endif // WOREVT1
#if defined(SMARTRF_SETTING_WOREVT0)
  worevt0: SMARTRF_SETTING_WOREVT0,
#else // WOREVT0
  worevt0: 0x00,
#endif // WOREVT0
#if defined(SMARTRF_SETTING_WORCTL)
  worctl: SMARTRF_SETTING_WORCTL,
#else // WORCTL
  worctrl: 0xf0,
#endif // WORCTL
  frend1: SMARTRF_SETTING_FREND1,
  frend0: SMARTRF_SETTING_FREND0,
  fscal3: SMARTRF_SETTING_FSCAL3,
  fscal2: SMARTRF_SETTING_FSCAL2,
  fscal1: SMARTRF_SETTING_FSCAL1,
  fscal0: SMARTRF_SETTING_FSCAL0,
  // _rcctrl1 reserved
  // _rcctrl0 reserved
  fstest: SMARTRF_SETTING_FSTEST,
  // ptest do not write
  // agctest do not write
  test2: SMARTRF_SETTING_TEST2,
  test1: SMARTRF_SETTING_TEST1,
  test0: SMARTRF_SETTING_TEST0,
  /* NB: This declaration only specifies the first power level.  You
   * want to use ASK, you write your own. */
#if defined(SMARTRF_SETTING_PATABLE0)
  patable: { SMARTRF_SETTING_PATABLE0 },
#else
  patable: { 0xc6 }
#endif
};

#endif
