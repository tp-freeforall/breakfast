#define nx_struct struct
#define nx_union union
# 149 "/usr/lib/gcc/msp430/4.4.4/include/stddef.h" 3
typedef int ptrdiff_t;
#line 211
typedef unsigned int size_t;
#line 323
typedef int wchar_t;
# 8 "/usr/lib/ncc/deputy_nodeputy.h"
struct __nesc_attr_nonnull {
}  ;
#line 9
struct __nesc_attr_bnd {
#line 9
  void *lo, *hi;
}  ;
#line 10
struct __nesc_attr_bnd_nok {
#line 10
  void *lo, *hi;
}  ;
#line 11
struct __nesc_attr_count {
#line 11
  int n;
}  ;
#line 12
struct __nesc_attr_count_nok {
#line 12
  int n;
}  ;
#line 13
struct __nesc_attr_one {
}  ;
#line 14
struct __nesc_attr_one_nok {
}  ;
#line 15
struct __nesc_attr_dmemset {
#line 15
  int a1, a2, a3;
}  ;
#line 16
struct __nesc_attr_dmemcpy {
#line 16
  int a1, a2, a3;
}  ;
#line 17
struct __nesc_attr_nts {
}  ;
# 38 "/usr/lib/gcc/msp430/4.4.4/../../../../msp430/include/sys/inttypes.h" 3
typedef signed char int8_t;
typedef unsigned char uint8_t;

typedef int int16_t;
typedef unsigned int uint16_t;

typedef long int32_t;
typedef unsigned long uint32_t;

typedef long long int64_t;
typedef unsigned long long uint64_t;




typedef int16_t intptr_t;
typedef uint16_t uintptr_t;
# 235 "/usr/lib/ncc/nesc_nx.h"
static __inline uint8_t __nesc_ntoh_uint8(const void * source)  ;




static __inline uint8_t __nesc_hton_uint8(void * target, uint8_t value)  ;





static __inline uint8_t __nesc_ntoh_leuint8(const void * source)  ;




static __inline uint8_t __nesc_hton_leuint8(void * target, uint8_t value)  ;
#line 264
static __inline uint16_t __nesc_ntoh_uint16(const void * source)  ;




static __inline uint16_t __nesc_hton_uint16(void * target, uint16_t value)  ;






static __inline uint16_t __nesc_ntoh_leuint16(const void * source)  ;




static __inline uint16_t __nesc_hton_leuint16(void * target, uint16_t value)  ;







static inline uint16_t __nesc_bfle_decode16(const uint8_t *msg, unsigned offset, uint8_t length)  ;
#line 289
static inline void __nesc_bfle_encode16(uint8_t *msg, unsigned offset, uint8_t length, uint16_t x)  ;
#line 289
static __inline uint16_t __nesc_ntohbf_leuint16(const void *source, unsigned offset, uint8_t length)  ;
#line 289
static __inline uint16_t __nesc_htonbf_leuint16(void *target, unsigned offset, uint8_t length, uint16_t value)  ;
#line 385
typedef struct { unsigned char data[1]; } __attribute__((packed)) nx_int8_t;typedef int8_t __nesc_nxbase_nx_int8_t  ;
typedef struct { unsigned char data[2]; } __attribute__((packed)) nx_int16_t;typedef int16_t __nesc_nxbase_nx_int16_t  ;
typedef struct { unsigned char data[4]; } __attribute__((packed)) nx_int32_t;typedef int32_t __nesc_nxbase_nx_int32_t  ;
typedef struct { unsigned char data[8]; } __attribute__((packed)) nx_int64_t;typedef int64_t __nesc_nxbase_nx_int64_t  ;
typedef struct { unsigned char data[1]; } __attribute__((packed)) nx_uint8_t;typedef uint8_t __nesc_nxbase_nx_uint8_t  ;
typedef struct { unsigned char data[2]; } __attribute__((packed)) nx_uint16_t;typedef uint16_t __nesc_nxbase_nx_uint16_t  ;
typedef struct { unsigned char data[4]; } __attribute__((packed)) nx_uint32_t;typedef uint32_t __nesc_nxbase_nx_uint32_t  ;
typedef struct { unsigned char data[8]; } __attribute__((packed)) nx_uint64_t;typedef uint64_t __nesc_nxbase_nx_uint64_t  ;


typedef struct { unsigned char data[1]; } __attribute__((packed)) nxle_int8_t;typedef int8_t __nesc_nxbase_nxle_int8_t  ;
typedef struct { unsigned char data[2]; } __attribute__((packed)) nxle_int16_t;typedef int16_t __nesc_nxbase_nxle_int16_t  ;
typedef struct { unsigned char data[4]; } __attribute__((packed)) nxle_int32_t;typedef int32_t __nesc_nxbase_nxle_int32_t  ;
typedef struct { unsigned char data[8]; } __attribute__((packed)) nxle_int64_t;typedef int64_t __nesc_nxbase_nxle_int64_t  ;
typedef struct { unsigned char data[1]; } __attribute__((packed)) nxle_uint8_t;typedef uint8_t __nesc_nxbase_nxle_uint8_t  ;
typedef struct { unsigned char data[2]; } __attribute__((packed)) nxle_uint16_t;typedef uint16_t __nesc_nxbase_nxle_uint16_t  ;
typedef struct { unsigned char data[4]; } __attribute__((packed)) nxle_uint32_t;typedef uint32_t __nesc_nxbase_nxle_uint32_t  ;
typedef struct { unsigned char data[8]; } __attribute__((packed)) nxle_uint64_t;typedef uint64_t __nesc_nxbase_nxle_uint64_t  ;
# 41 "/usr/lib/gcc/msp430/4.4.4/../../../../msp430/include/sys/types.h" 3
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;
typedef unsigned short ushort;
typedef unsigned int uint;

typedef uint8_t u_int8_t;
typedef uint16_t u_int16_t;
typedef uint32_t u_int32_t;
typedef uint64_t u_int64_t;

typedef u_int64_t u_quad_t;
typedef int64_t quad_t;
typedef quad_t *qaddr_t;

typedef char *caddr_t;
typedef const char *c_caddr_t;
typedef volatile char *v_caddr_t;
typedef u_int32_t fixpt_t;
typedef u_int32_t gid_t;
typedef u_int32_t in_addr_t;
typedef u_int16_t in_port_t;
typedef u_int32_t ino_t;
typedef long key_t;
typedef u_int16_t mode_t;
typedef u_int16_t nlink_t;
typedef quad_t rlim_t;
typedef int32_t segsz_t;
typedef int32_t swblk_t;
typedef int32_t ufs_daddr_t;
typedef int32_t ufs_time_t;
typedef u_int32_t uid_t;
# 40 "/usr/lib/gcc/msp430/4.4.4/../../../../msp430/include/string.h" 3
extern void *memset(void *arg_0x402a5220, int arg_0x402a5378, size_t arg_0x402a5510);
#line 61
extern void *memset(void *arg_0x402af118, int arg_0x402af270, size_t arg_0x402af408);
# 59 "/usr/lib/gcc/msp430/4.4.4/../../../../msp430/include/stdlib.h" 3
#line 55
typedef struct __nesc_unnamed4242 {

  int quot;
  int rem;
} div_t;







#line 63
typedef struct __nesc_unnamed4243 {

  long quot;
  long rem;
} ldiv_t;
# 122 "/usr/lib/gcc/msp430/4.4.4/../../../../msp430/include/sys/config.h" 3
typedef long int __int32_t;
typedef unsigned long int __uint32_t;
# 12 "/usr/lib/gcc/msp430/4.4.4/../../../../msp430/include/sys/_types.h" 3
typedef long _off_t;
typedef long _ssize_t;
# 19 "/usr/lib/gcc/msp430/4.4.4/../../../../msp430/include/sys/reent.h" 3
typedef unsigned long __ULong;
#line 31
struct _glue {

  struct _glue *_next;
  int _niobs;
  struct __sFILE *_iobs;
};

struct _Bigint {

  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  __ULong _x[1];
};


struct __tm {

  int __tm_sec;
  int __tm_min;
  int __tm_hour;
  int __tm_mday;
  int __tm_mon;
  int __tm_year;
  int __tm_wday;
  int __tm_yday;
  int __tm_isdst;
};







struct _atexit {
  struct _atexit *_next;
  int _ind;
  void (*_fns[32])(void );
};








struct __sbuf {
  unsigned char *_base;
  int _size;
};






typedef long _fpos_t;
#line 116
struct __sFILE {
  unsigned char *_p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf _bf;
  int _lbfsize;


  void *_cookie;

  int (*_read)(void *_cookie, char *_buf, int _n);
  int (*_write)(void *_cookie, const char *_buf, int _n);

  _fpos_t (*_seek)(void *_cookie, _fpos_t _offset, int _whence);
  int (*_close)(void *_cookie);


  struct __sbuf _ub;
  unsigned char *_up;
  int _ur;


  unsigned char _ubuf[3];
  unsigned char _nbuf[1];


  struct __sbuf _lb;


  int _blksize;
  int _offset;

  struct _reent *_data;
};
#line 174
struct _rand48 {
  unsigned short _seed[3];
  unsigned short _mult[3];
  unsigned short _add;
};









struct _reent {


  int _errno;




  struct __sFILE *_stdin, *_stdout, *_stderr;

  int _inc;
  char _emergency[25];

  int _current_category;
  const char *_current_locale;

  int __sdidinit;

  void (*__cleanup)(struct _reent *arg_0x402d5da8);


  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;


  int _cvtlen;
  char *_cvtbuf;

  union __nesc_unnamed4244 {

    struct __nesc_unnamed4245 {

      unsigned int _unused_rand;
      char *_strtok_last;
      char _asctime_buf[26];
      struct __tm _localtime_buf;
      int _gamma_signgam;
      __extension__ unsigned long long _rand_next;
      struct _rand48 _r48;
    } _reent;



    struct __nesc_unnamed4246 {


      unsigned char *_nextf[30];
      unsigned int _nmalloc[30];
    } _unused;
  } _new;


  struct _atexit *_atexit;
  struct _atexit _atexit0;


  void (**_sig_func)(int arg_0x402d8480);




  struct _glue __sglue;
  struct __sFILE __sf[3];
};
#line 273
struct _reent;
# 18 "/usr/lib/gcc/msp430/4.4.4/../../../../msp430/include/math.h" 3
union __dmath {

  __uint32_t i[2];
  double d;
};




union __dmath;
#line 220
struct exception {


  int type;
  char *name;
  double arg1;
  double arg2;
  double retval;
  int err;
};
#line 273
enum __fdlibm_version {

  __fdlibm_ieee = -1, 
  __fdlibm_svid, 
  __fdlibm_xopen, 
  __fdlibm_posix
};




enum __fdlibm_version;
# 25 "/opt/tinyos-2.x/tos/system/tos.h"
typedef uint8_t bool;
enum __nesc_unnamed4247 {
#line 26
  FALSE = 0, TRUE = 1
};
typedef nx_int8_t nx_bool;
uint16_t TOS_NODE_ID = 1;






struct __nesc_attr_atmostonce {
};
#line 37
struct __nesc_attr_atleastonce {
};
#line 38
struct __nesc_attr_exactlyonce {
};
# 51 "/opt/tinyos-2.x/tos/types/TinyError.h"
enum __nesc_unnamed4248 {
  SUCCESS = 0, 
  FAIL = 1, 
  ESIZE = 2, 
  ECANCEL = 3, 
  EOFF = 4, 
  EBUSY = 5, 
  EINVAL = 6, 
  ERETRY = 7, 
  ERESERVE = 8, 
  EALREADY = 9, 
  ENOMEM = 10, 
  ENOACK = 11, 
  ELAST = 11
};

typedef uint8_t error_t  ;

static inline error_t ecombine(error_t r1, error_t r2)  ;
# 122 "/usr/lib/gcc/msp430/4.4.4/../../../../msp430/include/iomacros.h" 3
extern void __bic_sr_irq(int arg_0x4032c6f8);
# 32 "/usr/lib/gcc/msp430/4.4.4/../../../../msp430/include/msp430/sfr.h" 3
volatile unsigned int SFRIFG1 __asm ("0x0100 + 0x02");






volatile unsigned int SFRRPCR1 __asm ("0x0100 + 0x04");
# 151 "/usr/lib/gcc/msp430/4.4.4/../../../../msp430/include/msp430/pmm.h" 3
volatile unsigned char PMMCTL0_L __asm ("0x0120 + 0x00");
volatile unsigned char PMMCTL0_H __asm ("0x0120 + 0x00 +1");



volatile unsigned int SVSMHCTL __asm ("0x0120 + 0x04");

volatile unsigned int SVSMLCTL __asm ("0x0120 + 0x06");



volatile unsigned int PMMIFG __asm ("0x0120 + 0x0C");
# 23 "/usr/lib/gcc/msp430/4.4.4/../../../../msp430/include/msp430/wdt_a.h" 3
volatile unsigned int WDTCTL __asm ("0x0150 + 0x0C");
#line 108
struct __nesc_unnamed4249 {

  volatile unsigned 
  IS0 : 3, 
  CNTCL : 1, 
  TMSEL : 1, 
  SSEL : 2, 
  HOLD : 1, 
  PW : 8;
};
# 28 "/usr/lib/gcc/msp430/4.4.4/../../../../msp430/include/msp430/unified_clock_system.h" 3
volatile unsigned int UCSCTL0 __asm ("0x0160 + 0x00");





volatile unsigned int UCSCTL1 __asm ("0x0160 + 0x02");

volatile unsigned int UCSCTL1 __asm ("0x0160 + 0x02");





volatile unsigned int UCSCTL2 __asm ("0x0160 + 0x04");





volatile unsigned int UCSCTL3 __asm ("0x0160 + 0x06");





volatile unsigned int UCSCTL4 __asm ("0x0160 + 0x08");





volatile unsigned int UCSCTL5 __asm ("0x0160 + 0x0A");
#line 72
volatile unsigned int UCSCTL7 __asm ("0x0160 + 0x0E");
# 202 "/usr/lib/gcc/msp430/4.4.4/../../../../msp430/include/msp430/sys.h" 3
#line 123
typedef struct __nesc_unnamed4250 {

  union  {

    volatile unsigned int CTL;
    struct  {

      volatile unsigned char CTL_L;
      volatile unsigned char CTL_H;
    } ;
  } ;
  union  {

    volatile unsigned int BSLC;
    struct  {

      volatile unsigned char BSLC_L;
      volatile unsigned char BSLC_H;
    } ;
  } ;
  union  {

    volatile unsigned int ARB;
    struct  {

      volatile unsigned char ARB_L;
      volatile unsigned char ARB_H;
    } ;
  } ;
  union  {

    volatile unsigned int JMBC;
    struct  {

      volatile unsigned char JMBC_L;
      volatile unsigned char JMBC_H;
    } ;
  } ;
  union  {

    volatile unsigned int JMBI0;
    struct  {

      volatile unsigned char JMBI0_L;
      volatile unsigned char JMBI0_H;
    } ;
  } ;
  union  {

    volatile unsigned int JMBI1;
    struct  {

      volatile unsigned char JMBI1_L;
      volatile unsigned char JMBI1_H;
    } ;
  } ;
  union  {

    volatile unsigned int JMBO0;
    struct  {

      volatile unsigned char JMBO0_L;
      volatile unsigned char JMBO0_H;
    } ;
  } ;
  union  {

    volatile unsigned int JMBO1;
    struct  {

      volatile unsigned char JMBO1_L;
      volatile unsigned char JMBO1_H;
    } ;
  } ;
  unsigned int dummy[4];
  volatile unsigned int BERRIV;
  volatile unsigned int UNIV;
  volatile unsigned int SNIV;
  volatile unsigned int RSTIV;
} sys_t;
# 40 "/usr/lib/gcc/msp430/4.4.4/../../../../msp430/include/msp430/gpio_5xxx.h" 3
volatile unsigned char P1OUT __asm ("0x0200 + 0x02");

volatile unsigned char P1DIR __asm ("0x0200 + 0x04");
#line 54
volatile unsigned char P1IE __asm ("0x0200 + 0x1A");

volatile unsigned char P1IFG __asm ("0x0200 + 0x1C");






volatile unsigned char P2OUT __asm ("0x0200 + 0x03");

volatile unsigned char P2DIR __asm ("0x0200 + 0x05");









volatile unsigned char P2IES __asm ("0x0200 + 0x19");

volatile unsigned char P2IE __asm ("0x0200 + 0x1B");

volatile unsigned char P2IFG __asm ("0x0200 + 0x1D");
#line 94
volatile unsigned char P3OUT __asm ("0x0220 + 0x02");

volatile unsigned char P3DIR __asm ("0x0220 + 0x04");
#line 132
volatile unsigned char P5OUT __asm ("0x0240 + 0x02");

volatile unsigned char P5DIR __asm ("0x0240 + 0x04");
#line 261
volatile unsigned char PJOUT __asm ("0x0320 + 0x02");

volatile unsigned char PJDIR __asm ("0x0320 + 0x04");
# 37 "/usr/lib/gcc/msp430/4.4.4/../../../../msp430/include/msp430/timera.h" 3
volatile unsigned int TA0CTL __asm ("0x0340 + 0x00");
#line 73
volatile unsigned int TA0R __asm ("0x0340 + 0x10");
#line 124
volatile unsigned int TA1CTL __asm ("0x0380 + 0x00");
#line 148
volatile unsigned int TA1R __asm ("0x0380 + 0x10");
#line 293
#line 284
typedef struct __nesc_unnamed4251 {
  volatile unsigned 
  taifg : 1, 
  taie : 1, 
  taclr : 1, 
  dummy : 1, 
  tamc : 2, 
  taid : 2, 
  tassel : 2;
} __attribute((packed))  tactl_t;
#line 309
#line 295
typedef struct __nesc_unnamed4252 {
  volatile unsigned 
  ccifg : 1, 
  cov : 1, 
  out : 1, 
  cci : 1, 
  ccie : 1, 
  outmod : 3, 
  cap : 1, 
  dummy : 1, 
  scci : 1, 
  scs : 1, 
  ccis : 2, 
  cm : 2;
} __attribute((packed))  tacctl_t;
# 119 "/usr/lib/gcc/msp430/4.4.4/../../../../msp430/include/msp430/mpy32.h" 3
#line 94
typedef struct __nesc_unnamed4253 {

  volatile unsigned int MPY;
  volatile unsigned int MPYS;
  volatile unsigned int MAC;
  volatile unsigned int MACS;
  volatile unsigned int OP2;
  volatile unsigned int RESLO;
  volatile unsigned int RESHI;
  volatile unsigned int SUMEXT;
  volatile unsigned int MPY32L;
  volatile unsigned int MPY32H;
  volatile unsigned int MPYS32L;
  volatile unsigned int MPYS32H;
  volatile unsigned int MAC32L;
  volatile unsigned int MAC32H;
  volatile unsigned int MACS32L;
  volatile unsigned int MACS32H;
  volatile unsigned int OP2L;
  volatile unsigned int OP2H;
  volatile unsigned int RES0;
  volatile unsigned int RES1;
  volatile unsigned int RES2;
  volatile unsigned int RES3;
  volatile unsigned int MPY32CTL0;
} mpy32_t;
# 26 "/usr/lib/gcc/msp430/4.4.4/../../../../msp430/include/msp430/rf1a.h" 3
volatile unsigned int RF1AIFCTL1 __asm ("0x0f00 + 0x02");
#line 46
volatile unsigned int RF1AIFERRV __asm ("0x0f00 + 0x0c");
#line 58
volatile unsigned int RF1AINSTRW __asm ("0x0f00 + 0x10");

volatile unsigned char RF1AINSTRW_L __asm ("0x0f00 + 0x10");

volatile unsigned char RF1AINSTRW_H __asm ("0x0f00 + 0x11");







volatile unsigned char RF1AINSTR1W_H __asm ("0x0f00 + 0x13");
#line 89
volatile unsigned char RF1ASTAT0W_L __asm ("0x0f00 + 0x20");

volatile unsigned char RF1ASTAT0W_H __asm ("0x0f00 + 0x21");








volatile unsigned char RF1ASTAT1W_L __asm ("0x0f00 + 0x22");
#line 159
volatile unsigned int RF1AIV __asm ("0x0f00 + 0x38");
# 378 "/opt/tinyos-2.x/tos/chips/msp430/msp430hardware.h"
typedef uint8_t mcu_power_t  ;



enum __nesc_unnamed4254 {
  MSP430_POWER_ACTIVE = 0, 
  MSP430_POWER_LPM0 = 1, 
  MSP430_POWER_LPM1 = 2, 
  MSP430_POWER_LPM2 = 3, 
  MSP430_POWER_LPM3 = 4, 
  MSP430_POWER_LPM4 = 5
};

static inline void __nesc_disable_interrupt(void )  ;





static inline void __nesc_enable_interrupt(void )  ;




typedef bool __nesc_atomic_t;
__nesc_atomic_t __nesc_atomic_start(void );
void __nesc_atomic_end(__nesc_atomic_t reenable_interrupts);






__nesc_atomic_t __nesc_atomic_start(void )   ;







void __nesc_atomic_end(__nesc_atomic_t reenable_interrupts)   ;
#line 433
typedef struct { unsigned char data[4]; } __attribute__((packed)) nx_float;typedef float __nesc_nxbase_nx_float  ;
#line 448
enum __nesc_unnamed4255 {
  MSP430_PORT_RESISTOR_INVALID, 
  MSP430_PORT_RESISTOR_OFF, 
  MSP430_PORT_RESISTOR_PULLDOWN, 
  MSP430_PORT_RESISTOR_PULLUP
};


enum __nesc_unnamed4256 {
  MSP430_PORT_DRIVE_STRENGTH_INVALID, 
  MSP430_PORT_DRIVE_STRENGTH_REDUCED, 
  MSP430_PORT_DRIVE_STRENGTH_FULL
};
# 41 "/opt/tinyos-2.x/tos/platforms/surf/hardware.h"
enum __nesc_unnamed4257 {
  TOS_SLEEP_NONE = MSP430_POWER_ACTIVE
};
# 12 "concxmit.h"
#line 10
typedef nx_struct __nesc_unnamed4258 {
  nx_uint16_t seqNum;
} __attribute__((packed)) test_packet_t;
#line 28
#line 24
typedef nx_struct __nesc_unnamed4259 {
  nx_uint8_t cmd;
  nx_uint16_t send1Offset;
  nx_uint16_t sendCount;
} __attribute__((packed)) cmd_t;








#line 30
typedef nx_struct __nesc_unnamed4260 {
  nx_uint16_t configId;
  nx_uint16_t seqNum;
  nx_uint8_t received;
  nx_uint16_t rssi;
  nx_uint16_t lqi;
  nx_uint16_t send1Offset;
} __attribute__((packed)) receiver_report_t;




#line 39
typedef nx_struct __nesc_unnamed4261 {
  nx_uint16_t configId;
  nx_uint16_t seqNum;
} __attribute__((packed)) sender_report_t;
# 40 "/opt/tinyos-2.x/tos/types/IeeeEui64.h"
enum __nesc_unnamed4262 {
#line 40
  IEEE_EUI64_LENGTH = 8
};


#line 42
typedef struct ieee_eui64 {
  uint8_t data[IEEE_EUI64_LENGTH];
} ieee_eui64_t;
# 47 "/opt/tinyos-2.x/tos/types/Ieee154.h"
typedef uint16_t ieee154_panid_t;
typedef uint16_t ieee154_saddr_t;
typedef ieee_eui64_t ieee154_laddr_t;







#line 51
typedef struct __nesc_unnamed4263 {
  uint8_t ieee_mode : 2;
  union __nesc_unnamed4264 {
    ieee154_saddr_t saddr;
    ieee154_laddr_t laddr;
  } ieee_addr;
} ieee154_addr_t;



enum __nesc_unnamed4265 {
  IEEE154_BROADCAST_ADDR = 0xffff, 
  IEEE154_BROADCAST_PAN = 0xffff, 
  IEEE154_LINK_MTU = 127
};
#line 77
enum __nesc_unnamed4266 {
  TOS_IEEE154_SHORT_ADDRESS = 1, 
  TOS_IEEE154_PAN_ID = 22
};


struct ieee154_frame_addr {
  ieee154_addr_t ieee_src;
  ieee154_addr_t ieee_dst;
  ieee154_panid_t ieee_dstpan;
};

enum __nesc_unnamed4267 {
  IEEE154_MIN_HDR_SZ = 6
};
#line 103
enum ieee154_fcf_enums {
  IEEE154_FCF_FRAME_TYPE = 0, 
  IEEE154_FCF_SECURITY_ENABLED = 3, 
  IEEE154_FCF_FRAME_PENDING = 4, 
  IEEE154_FCF_ACK_REQ = 5, 
  IEEE154_FCF_INTRAPAN = 6, 
  IEEE154_FCF_DEST_ADDR_MODE = 10, 
  IEEE154_FCF_SRC_ADDR_MODE = 14
};

enum ieee154_fcf_type_enums {
  IEEE154_TYPE_BEACON = 0, 
  IEEE154_TYPE_DATA = 1, 
  IEEE154_TYPE_ACK = 2, 
  IEEE154_TYPE_MAC_CMD = 3, 
  IEEE154_TYPE_MASK = 7
};

enum ieee154_fcf_addr_mode_enums {
  IEEE154_ADDR_NONE = 0, 
  IEEE154_ADDR_SHORT = 2, 
  IEEE154_ADDR_EXT = 3, 
  IEEE154_ADDR_MASK = 3
};
# 34 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Ieee154PacketLayer.h"
#line 27
typedef nx_struct ieee154_header_t {

  nxle_uint16_t fcf;
  nxle_uint8_t dsn;
  nxle_uint16_t destpan;
  nxle_uint16_t dest;
  nxle_uint16_t src;
} __attribute__((packed)) ieee154_header_t;
#line 46
#line 36
typedef nx_struct ieee154_fcf_t {
  unsigned char __nesc_filler0[2];
} __attribute__((packed)) 







ieee154_fcf_t;
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/Rf1aPacket.h"
enum __nesc_unnamed4268 {

  LOWPAN_NALP_TINYOS = 0x3f
};


typedef ieee154_header_t rf1a_ieee154_t;





#line 65
typedef nx_struct rf1a_nalp_am_t {
  nxle_uint8_t nalp_tinyos;
  nxle_uint8_t am_type;
} __attribute__((packed)) rf1a_nalp_am_t;










#line 71
typedef nx_struct rf1a_metadata_t {


  nxle_uint16_t payload_length;

  nxle_uint8_t rssi;

  nxle_uint8_t lqi;
} __attribute__((packed)) rf1a_metadata_t;
# 15 "/opt/tinyos-2.x/tos/platforms/surf/platform_message.h"
#line 13
typedef union message_header {
  rf1a_ieee154_t rf1a_ieee154;
} message_header_t;


#line 17
typedef union TOSRadioFooter {
} message_footer_t;



#line 20
typedef union TOSRadioMetadata {
  rf1a_metadata_t rf1a;
} message_metadata_t;
# 19 "/opt/tinyos-2.x/tos/types/message.h"
#line 14
typedef nx_struct message_t {
  nx_uint8_t header[sizeof(message_header_t )];
  nx_uint8_t data[127 - sizeof(rf1a_ieee154_t )];
  nx_uint8_t footer[sizeof(message_footer_t )];
  nx_uint8_t metadata[sizeof(message_metadata_t )];
} __attribute__((packed)) message_t;
# 6 "/opt/tinyos-2.x/tos/types/AM.h"
typedef nx_uint8_t nx_am_id_t;
typedef nx_uint8_t nx_am_group_t;
typedef nx_uint16_t nx_am_addr_t;

typedef uint8_t am_id_t;
typedef uint8_t am_group_t;
typedef uint16_t am_addr_t;

enum __nesc_unnamed4269 {
  AM_BROADCAST_ADDR = 0xffff
};









enum __nesc_unnamed4270 {
  TOS_AM_GROUP = 0x22, 
  TOS_AM_ADDRESS = 1
};
# 43 "/opt/tinyos-2.x/tos/types/Leds.h"
enum __nesc_unnamed4271 {
  LEDS_LED0 = 1 << 0, 
  LEDS_LED1 = 1 << 1, 
  LEDS_LED2 = 1 << 2, 
  LEDS_LED3 = 1 << 3, 
  LEDS_LED4 = 1 << 4, 
  LEDS_LED5 = 1 << 5, 
  LEDS_LED6 = 1 << 6, 
  LEDS_LED7 = 1 << 7
};
# 19 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/usci/msp430usci.h"
enum __nesc_unnamed4272 {
  MSP430_USCI_Inactive, 
  MSP430_USCI_UART, 
  MSP430_USCI_SPI, 
  MSP430_USCI_I2C
};








#line 29
typedef struct msp430_usci_config_t {
  uint16_t ctlw0;
  uint16_t brw;
  uint8_t mctl;
} msp430_usci_config_t;





msp430_usci_config_t msp430_usci_uart_default_config = { 

.ctlw0 = (0 << 8) | 0x80, 
#line 61
.brw = 9, 
.mctl = 0x00 + 0x02 };
#line 78
enum __nesc_unnamed4273 {



  MSP430_USCI_ERR_Framing = 0x40, 



  MSP430_USCI_ERR_Overrun = 0x20, 


  MSP430_USCI_ERR_Parity = 0x10, 

  MSP430_USCI_ERR_UCxySTAT = (MSP430_USCI_ERR_Framing | MSP430_USCI_ERR_Overrun) | MSP430_USCI_ERR_Parity
};
# 33 "/opt/tinyos-2.x/tos/types/Resource.h"
typedef uint8_t resource_client_id_t;
# 41 "/opt/tinyos-2.x/tos/lib/timer/Timer.h"
typedef struct __nesc_unnamed4274 {
#line 41
  int notUsed;
} 
#line 41
TSecond;
typedef struct __nesc_unnamed4275 {
#line 42
  int notUsed;
} 
#line 42
TMilli;
typedef struct __nesc_unnamed4276 {
#line 43
  int notUsed;
} 
#line 43
T32khz;
typedef struct __nesc_unnamed4277 {
#line 44
  int notUsed;
} 
#line 44
TMicro;
# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.h"
enum __nesc_unnamed4278 {
  MSP430TIMER_CM_NONE = 0, 
  MSP430TIMER_CM_RISING = 1, 
  MSP430TIMER_CM_FALLING = 2, 
  MSP430TIMER_CM_BOTH = 3, 

  MSP430TIMER_STOP_MODE = 0, 
  MSP430TIMER_UP_MODE = 1, 
  MSP430TIMER_CONTINUOUS_MODE = 2, 
  MSP430TIMER_UPDOWN_MODE = 3, 

  MSP430TIMER_TACLK = 0, 
  MSP430TIMER_TBCLK = 0, 
  MSP430TIMER_ACLK = 1, 
  MSP430TIMER_SMCLK = 2, 
  MSP430TIMER_INCLK = 3, 

  MSP430TIMER_CLOCKDIV_1 = 0, 
  MSP430TIMER_CLOCKDIV_2 = 1, 
  MSP430TIMER_CLOCKDIV_4 = 2, 
  MSP430TIMER_CLOCKDIV_8 = 3
};
#line 75
#line 62
typedef struct __nesc_unnamed4279 {

  int ccifg : 1;
  int cov : 1;
  int out : 1;
  int cci : 1;
  int ccie : 1;
  int outmod : 3;
  int cap : 1;
  int clld : 2;
  int scs : 1;
  int ccis : 2;
  int cm : 2;
} msp430_compare_control_t;
#line 87
#line 77
typedef struct __nesc_unnamed4280 {

  int taifg : 1;
  int taie : 1;
  int taclr : 1;
  int _unused0 : 1;
  int mc : 2;
  int id : 2;
  int tassel : 2;
  int _unused1 : 6;
} msp430_timer_a_control_t;
#line 102
#line 89
typedef struct __nesc_unnamed4281 {

  int tbifg : 1;
  int tbie : 1;
  int tbclr : 1;
  int _unused0 : 1;
  int mc : 2;
  int id : 2;
  int tbssel : 2;
  int _unused1 : 1;
  int cntl : 2;
  int tbclgrp : 2;
  int _unused2 : 1;
} msp430_timer_b_control_t;
# 65 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430XV2Dco.h"
#line 54
typedef enum Msp430XV2DcoConfig_e {
  MSP430XV2_DCO_2MHz_RSEL2, 
  MSP430XV2_DCO_4MHz_RSEL3, 
  MSP430XV2_DCO_8MHz_RSEL3, 
  MSP430XV2_DCO_8MHz_RSEL4, 
  MSP430XV2_DCO_16MHz_RSEL4, 
  MSP430XV2_DCO_16MHz_RSEL5, 
  MSP430XV2_DCO_32MHz_RSEL5, 
  MSP430XV2_DCO_32MHz_RSEL6, 
  MSP430XV2_DCO_64MHz_RSEL6, 
  MSP430XV2_DCO_64MHz_RSEL7
} Msp430XV2DcoConfig_e;
# 59 "/opt/tinyos-2.x/tos/chips/msp430/adc12/Msp430Adc12.h"
#line 48
typedef struct __nesc_unnamed4282 {

  unsigned int inch : 4;
  unsigned int sref : 3;
  unsigned int ref2_5v : 1;
  unsigned int adc12ssel : 2;
  unsigned int adc12div : 3;
  unsigned int sht : 4;
  unsigned int sampcon_ssel : 2;
  unsigned int sampcon_id : 2;
  unsigned int  : 0;
} msp430adc12_channel_config_t;








#line 61
typedef struct __nesc_unnamed4283 {


  volatile unsigned 
  inch : 4, 
  sref : 3, 
  eos : 1;
} __attribute((packed))  adc12memctl_t;

enum inch_enum {


  INPUT_CHANNEL_A0 = 0, 
  INPUT_CHANNEL_A1 = 1, 
  INPUT_CHANNEL_A2 = 2, 
  INPUT_CHANNEL_A3 = 3, 
  INPUT_CHANNEL_A4 = 4, 
  INPUT_CHANNEL_A5 = 5, 
  INPUT_CHANNEL_A6 = 6, 
  INPUT_CHANNEL_A7 = 7, 
  EXTERNAL_REF_VOLTAGE_CHANNEL = 8, 
  REF_VOLTAGE_NEG_TERMINAL_CHANNEL = 9, 
  TEMPERATURE_DIODE_CHANNEL = 10, 
  SUPPLY_VOLTAGE_HALF_CHANNEL = 11, 
  INPUT_CHANNEL_NONE = 12
};

enum sref_enum {

  REFERENCE_AVcc_AVss = 0, 
  REFERENCE_VREFplus_AVss = 1, 
  REFERENCE_VeREFplus_AVss = 2, 
  REFERENCE_AVcc_VREFnegterm = 4, 
  REFERENCE_VREFplus_VREFnegterm = 5, 
  REFERENCE_VeREFplus_VREFnegterm = 6
};

enum ref2_5v_enum {

  REFVOLT_LEVEL_1_5 = 0, 
  REFVOLT_LEVEL_2_5 = 1, 
  REFVOLT_LEVEL_NONE = 0
};

enum adc12ssel_enum {

  SHT_SOURCE_ADC12OSC = 0, 
  SHT_SOURCE_ACLK = 1, 
  SHT_SOURCE_MCLK = 2, 
  SHT_SOURCE_SMCLK = 3
};

enum adc12div_enum {

  SHT_CLOCK_DIV_1 = 0, 
  SHT_CLOCK_DIV_2 = 1, 
  SHT_CLOCK_DIV_3 = 2, 
  SHT_CLOCK_DIV_4 = 3, 
  SHT_CLOCK_DIV_5 = 4, 
  SHT_CLOCK_DIV_6 = 5, 
  SHT_CLOCK_DIV_7 = 6, 
  SHT_CLOCK_DIV_8 = 7
};

enum sht_enum {

  SAMPLE_HOLD_4_CYCLES = 0, 
  SAMPLE_HOLD_8_CYCLES = 1, 
  SAMPLE_HOLD_16_CYCLES = 2, 
  SAMPLE_HOLD_32_CYCLES = 3, 
  SAMPLE_HOLD_64_CYCLES = 4, 
  SAMPLE_HOLD_96_CYCLES = 5, 
  SAMPLE_HOLD_128_CYCLES = 6, 
  SAMPLE_HOLD_192_CYCLES = 7, 
  SAMPLE_HOLD_256_CYCLES = 8, 
  SAMPLE_HOLD_384_CYCLES = 9, 
  SAMPLE_HOLD_512_CYCLES = 10, 
  SAMPLE_HOLD_768_CYCLES = 11, 
  SAMPLE_HOLD_1024_CYCLES = 12
};

enum sampcon_ssel_enum {

  SAMPCON_SOURCE_TACLK = 0, 
  SAMPCON_SOURCE_ACLK = 1, 
  SAMPCON_SOURCE_SMCLK = 2, 
  SAMPCON_SOURCE_INCLK = 3
};

enum sampcon_id_enum {

  SAMPCON_CLOCK_DIV_1 = 0, 
  SAMPCON_CLOCK_DIV_2 = 1, 
  SAMPCON_CLOCK_DIV_4 = 2, 
  SAMPCON_CLOCK_DIV_8 = 3
};
#line 245
#line 233
typedef struct __nesc_unnamed4284 {
  volatile unsigned 
  adc12sc : 1, 
  enc : 1, 
  adc12tovie : 1, 
  adc12ovie : 1, 
  adc12on : 1, 
  refon : 1, 
  r2_5v : 1, 
  msc : 1, 
  sht0 : 4, 
  sht1 : 4;
} __attribute((packed))  adc12ctl0_t;
#line 257
#line 247
typedef struct __nesc_unnamed4285 {
  volatile unsigned 
  adc12busy : 1, 
  conseq : 2, 
  adc12ssel : 2, 
  adc12div : 3, 
  issh : 1, 
  shp : 1, 
  shs : 2, 
  cstartadd : 4;
} __attribute((packed))  adc12ctl1_t;
#line 277
#line 259
typedef struct __nesc_unnamed4286 {
  volatile unsigned 
  bit0 : 1, 
  bit1 : 1, 
  bit2 : 1, 
  bit3 : 1, 
  bit4 : 1, 
  bit5 : 1, 
  bit6 : 1, 
  bit7 : 1, 
  bit8 : 1, 
  bit9 : 1, 
  bit10 : 1, 
  bit11 : 1, 
  bit12 : 1, 
  bit13 : 1, 
  bit14 : 1, 
  bit15 : 1;
} __attribute((packed))  adc12xflg_t;


struct adc12_t {
  adc12ctl0_t ctl0;
  adc12ctl1_t ctl1;
  adc12xflg_t ifg;
  adc12xflg_t ie;
  adc12xflg_t iv;
};
# 114 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.h"
#line 48
typedef struct rf1a_config_t {
  uint8_t iocfg2;
  uint8_t iocfg1;
  uint8_t iocfg0;
  uint8_t fifothr;
  uint8_t sync1;
  uint8_t sync0;
  uint8_t pktlen;
  uint8_t pktctrl1;
  uint8_t pktctrl0;
  uint8_t addr;
  uint8_t channr;
  uint8_t fsctrl1;
  uint8_t fsctrl0;
  uint8_t freq2;
  uint8_t freq1;
  uint8_t freq0;
  uint8_t mdmcfg4;
  uint8_t mdmcfg3;
  uint8_t mdmcfg2;
  uint8_t mdmcfg1;
  uint8_t mdmcfg0;
  uint8_t deviatn;
  uint8_t mcsm2;
  uint8_t mcsm1;
  uint8_t mcsm0;
  uint8_t foccfg;
  uint8_t bscfg;
  uint8_t agcctrl2;
  uint8_t agcctrl1;
  uint8_t agcctrl0;
  uint8_t worevt1;
  uint8_t worevt0;
  uint8_t worctrl;
  uint8_t frend1;
  uint8_t frend0;
  uint8_t fscal3;
  uint8_t fscal2;
  uint8_t fscal1;
  uint8_t fscal0;
  uint8_t _rcctrl1;
  uint8_t _rcctrl0;
  uint8_t fstest;
  uint8_t ptest;
  uint8_t agctest;
  uint8_t test2;
  uint8_t test1;
  uint8_t test0;

  uint8_t patable[8];




  uint8_t partnum;
  uint8_t version;
} 









rf1a_config_t;
#line 176
rf1a_config_t rf1a_default_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x07, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x08, 
.fsctrl0 = 0x00, 
.freq2 = 0x22, 
.freq1 = 0xB3, 
.freq0 = 0x33, 
.mdmcfg4 = 0xAA, 
.mdmcfg3 = 0xF8, 
.mdmcfg2 = 0x13, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x40, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x10, 
.foccfg = 0x1D, 
.bscfg = 0x1C, 
.agcctrl2 = 0x43, 
.agcctrl1 = 0x40, 
.agcctrl0 = 0x91, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0x56, 
.frend0 = 0x10, 
.fscal3 = 0xE9, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };
# 50 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/Rf1a.h"
typedef uint8_t rf1a_status_t;
#line 69
#line 57
typedef enum rf1a_status_e {
  RF1A_S_MASK = 0x70, 
  RF1A_S_FIFOMASK = 0x0F, 
  RF1A_S_IDLE = 0x00, 
  RF1A_S_RX = 0x10, 
  RF1A_S_TX = 0x20, 
  RF1A_S_FSTXON = 0x30, 
  RF1A_S_CALIBRATE = 0x40, 
  RF1A_S_SETTLING = 0x50, 
  RF1A_S_RXFIFO_OVERFLOW = 0x60, 
  RF1A_S_TXFIFO_UNDERFLOW = 0x70, 
  RF1A_S_OFFLINE = 0xFF
} rf1a_status_e;
# 83 "/opt/tinyos-2.x/tos/lib/serial/Serial.h"
typedef uint8_t uart_id_t;



enum __nesc_unnamed4287 {
  HDLC_FLAG_BYTE = 0x7e, 
  HDLC_CTLESC_BYTE = 0x7d
};



enum __nesc_unnamed4288 {
  TOS_SERIAL_ACTIVE_MESSAGE_ID = 0, 
  TOS_SERIAL_CC1000_ID = 1, 
  TOS_SERIAL_802_15_4_ID = 2, 
  TOS_SERIAL_UNKNOWN_ID = 255
};


enum __nesc_unnamed4289 {
  SERIAL_PROTO_ACK = 67, 
  SERIAL_PROTO_PACKET_ACK = 68, 
  SERIAL_PROTO_PACKET_NOACK = 69, 
  SERIAL_PROTO_PACKET_UNKNOWN = 255
};
#line 121
#line 109
typedef struct radio_stats {
  uint8_t version;
  uint8_t flags;
  uint8_t reserved;
  uint8_t platform;
  uint16_t MTU;
  uint16_t radio_crc_fail;
  uint16_t radio_queue_drops;
  uint16_t serial_crc_fail;
  uint16_t serial_tx_fail;
  uint16_t serial_short_packets;
  uint16_t serial_proto_drops;
} radio_stats_t;







#line 123
typedef nx_struct serial_header {
  nx_am_addr_t dest;
  nx_am_addr_t src;
  nx_uint8_t length;
  nx_am_group_t group;
  nx_am_id_t type;
} __attribute__((packed)) serial_header_t;




#line 131
typedef nx_struct serial_packet {
  serial_header_t header;
  nx_uint8_t data[];
} __attribute__((packed)) serial_packet_t;



#line 136
typedef nx_struct serial_metadata {
  nx_uint8_t ack;
} __attribute__((packed)) serial_metadata_t;
# 91 "/opt/tinyos-2.x/tos/system/crc.h"
static uint16_t crcByte(uint16_t crc, uint8_t b);
enum /*Msp430UsciA0P.UsciC*/HplMsp430UsciC__0____nesc_unnamed4290 {
  HplMsp430UsciC__0__USCI_ID = 0U
};
typedef TMilli /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__LocalTime_bms__precision_tag;
enum /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Timer*/Msp430Timer32khzC__0____nesc_unnamed4291 {
  Msp430Timer32khzC__0__ALARM_ID = 0U
};
typedef T32khz /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__frequency_tag;
typedef /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__frequency_tag /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__precision_tag;
typedef uint16_t /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__size_type;
typedef T32khz /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__frequency_tag;
typedef /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__frequency_tag /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__precision_tag;
typedef uint16_t /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__size_type;
typedef TMilli /*CounterMilli32C.Transform*/TransformCounterC__0__to_precision_tag;
typedef uint32_t /*CounterMilli32C.Transform*/TransformCounterC__0__to_size_type;
typedef T32khz /*CounterMilli32C.Transform*/TransformCounterC__0__from_precision_tag;
typedef uint16_t /*CounterMilli32C.Transform*/TransformCounterC__0__from_size_type;
typedef uint32_t /*CounterMilli32C.Transform*/TransformCounterC__0__upper_count_type;
typedef /*CounterMilli32C.Transform*/TransformCounterC__0__from_precision_tag /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__precision_tag;
typedef /*CounterMilli32C.Transform*/TransformCounterC__0__from_size_type /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__size_type;
typedef /*CounterMilli32C.Transform*/TransformCounterC__0__to_precision_tag /*CounterMilli32C.Transform*/TransformCounterC__0__Counter__precision_tag;
typedef /*CounterMilli32C.Transform*/TransformCounterC__0__to_size_type /*CounterMilli32C.Transform*/TransformCounterC__0__Counter__size_type;
typedef TMilli /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_precision_tag;
typedef uint32_t /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type;
typedef T32khz /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__from_precision_tag;
typedef uint16_t /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__from_size_type;
typedef /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_precision_tag /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__precision_tag;
typedef /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__size_type;
typedef /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__from_precision_tag /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__precision_tag;
typedef /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__from_size_type /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__size_type;
typedef /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_precision_tag /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Counter__precision_tag;
typedef /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Counter__size_type;
typedef TMilli /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__precision_tag;
typedef /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__precision_tag /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__precision_tag;
typedef uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type;
typedef /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__precision_tag /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__precision_tag;
typedef TMilli /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__precision_tag;
typedef /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__precision_tag /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__precision_tag;
typedef /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__precision_tag /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__precision_tag;
typedef TMilli /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__precision_tag;
typedef /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__precision_tag /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__LocalTime__precision_tag;
typedef /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__precision_tag /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__Counter__precision_tag;
typedef uint32_t /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__Counter__size_type;
enum /*Msp430UsciB0P.UsciC*/HplMsp430UsciC__1____nesc_unnamed4292 {
  HplMsp430UsciC__1__USCI_ID = 1U
};
typedef const msp430adc12_channel_config_t *PlatformApds9007P__AdcConfigure__adc_config_t;
typedef const msp430adc12_channel_config_t *PlatformBatteryVoltageP__AdcConfigure__adc_config_t;
enum AMQueueP____nesc_unnamed4293 {
  AMQueueP__NUM_CLIENTS = 1U
};
typedef uint16_t RandomMlcgC__SeedInit__parameter;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4294 {
  Rf1aMultiPhysicalC__0__CLIENT = 0U
};
enum /*Rf1aC.HplRf1aC*/HplMsp430Rf1aC__0____nesc_unnamed4295 {
  HplMsp430Rf1aC__0__RF1A_ID = 0U
};
typedef uint16_t /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubGet__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4296 {
  Rf1aMultiPhysicalC__0__CUSTOM_HC_LOCAL_ID = 0U
};
typedef uint16_t CUSTOM_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4297 {
  Rf1aMultiPhysicalC__0__SRFS6_868_2FSK_1P2K_SENS_HC_LOCAL_ID = 1U
};
typedef uint16_t SRFS6_868_2FSK_1P2K_SENS_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4298 {
  Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_100K_CUR_HC_LOCAL_ID = 2U
};
typedef uint16_t SRFS6_868_GFSK_100K_CUR_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4299 {
  Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_100K_SENS_HC_LOCAL_ID = 3U
};
typedef uint16_t SRFS6_868_GFSK_100K_SENS_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4300 {
  Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_10K_CUR_HC_LOCAL_ID = 4U
};
typedef uint16_t SRFS6_868_GFSK_10K_CUR_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4301 {
  Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_10K_SENS_HC_LOCAL_ID = 5U
};
typedef uint16_t SRFS6_868_GFSK_10K_SENS_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4302 {
  Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_175K_CUR_HC_LOCAL_ID = 6U
};
typedef uint16_t SRFS6_868_GFSK_175K_CUR_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4303 {
  Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_175K_SENS_HC_LOCAL_ID = 7U
};
typedef uint16_t SRFS6_868_GFSK_175K_SENS_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4304 {
  Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_1P2K_CUR_HC_LOCAL_ID = 8U
};
typedef uint16_t SRFS6_868_GFSK_1P2K_CUR_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4305 {
  Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_1P2K_SENS_HC_LOCAL_ID = 9U
};
typedef uint16_t SRFS6_868_GFSK_1P2K_SENS_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4306 {
  Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_250K_CUR_HC_LOCAL_ID = 10U
};
typedef uint16_t SRFS6_868_GFSK_250K_CUR_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4307 {
  Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_250K_SENS_HC_LOCAL_ID = 11U
};
typedef uint16_t SRFS6_868_GFSK_250K_SENS_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4308 {
  Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_2P4K_CUR_HC_LOCAL_ID = 12U
};
typedef uint16_t SRFS6_868_GFSK_2P4K_CUR_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4309 {
  Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_2P4K_SENS_HC_LOCAL_ID = 13U
};
typedef uint16_t SRFS6_868_GFSK_2P4K_SENS_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4310 {
  Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_38P4K_CUR_HC_LOCAL_ID = 14U
};
typedef uint16_t SRFS6_868_GFSK_38P4K_CUR_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4311 {
  Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_38P4K_SENS_HC_LOCAL_ID = 15U
};
typedef uint16_t SRFS6_868_GFSK_38P4K_SENS_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4312 {
  Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_4P8K_CUR_HC_LOCAL_ID = 16U
};
typedef uint16_t SRFS6_868_GFSK_4P8K_CUR_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4313 {
  Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_4P8K_SENS_HC_LOCAL_ID = 17U
};
typedef uint16_t SRFS6_868_GFSK_4P8K_SENS_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4314 {
  Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_76P8K_CUR_HC_LOCAL_ID = 18U
};
typedef uint16_t SRFS6_868_GFSK_76P8K_CUR_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4315 {
  Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_76P8K_SENS_HC_LOCAL_ID = 19U
};
typedef uint16_t SRFS6_868_GFSK_76P8K_SENS_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4316 {
  Rf1aMultiPhysicalC__0__SRFS6_868_MSK_500K_HC_LOCAL_ID = 20U
};
typedef uint16_t SRFS6_868_MSK_500K_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4317 {
  Rf1aMultiPhysicalC__0__SRFS6_PRE802154G_HC_LOCAL_ID = 21U
};
typedef uint16_t SRFS6_PRE802154G_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4318 {
  Rf1aMultiPhysicalC__0__SRFS6_RESET_HC_LOCAL_ID = 22U
};
typedef uint16_t SRFS6_RESET_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4319 {
  Rf1aMultiPhysicalC__0__SRFS7_779_MSK_250K_HC_LOCAL_ID = 23U
};
typedef uint16_t SRFS7_779_MSK_250K_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4320 {
  Rf1aMultiPhysicalC__0__SRFS7_902P2_GFSK_50K_135B_HC_LOCAL_ID = 24U
};
typedef uint16_t SRFS7_902P2_GFSK_50K_135B_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4321 {
  Rf1aMultiPhysicalC__0__SRFS7_902P2_GFSK_50K_163B_HC_LOCAL_ID = 25U
};
typedef uint16_t SRFS7_902P2_GFSK_50K_163B_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4322 {
  Rf1aMultiPhysicalC__0__SRFS7_STI_902_GFSK_1P2K_HC_LOCAL_ID = 26U
};
typedef uint16_t SRFS7_STI_902_GFSK_1P2K_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4323 {
  Rf1aMultiPhysicalC__0__SRFS7_STI_902_GFSK_250K_HC_LOCAL_ID = 27U
};
typedef uint16_t SRFS7_STI_902_GFSK_250K_HC__Get__val_t;
enum /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0____nesc_unnamed4324 {
  Rf1aMultiPhysicalC__0__TINYOSRF1A_HC_LOCAL_ID = 28U
};
typedef uint16_t TINYOSRF1A_HC__Get__val_t;
typedef T32khz /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckWaitAlarm__precision_tag;
typedef uint16_t /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckWaitAlarm__size_type;
enum /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Timer*/Msp430Timer32khzC__1____nesc_unnamed4325 {
  Msp430Timer32khzC__1__ALARM_ID = 1U
};
typedef T32khz /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__frequency_tag;
typedef /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__frequency_tag /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__precision_tag;
typedef uint16_t /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__size_type;
enum /*PlatformSerialC.UartC*/Msp430UsciUartA0C__0____nesc_unnamed4326 {
  Msp430UsciUartA0C__0__CLIENT_ID = 0U
};
enum SerialAMQueueP____nesc_unnamed4327 {
  SerialAMQueueP__NUM_CLIENTS = 1U
};
# 113 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static void TestSenderP__SplitControl__startDone(error_t error);
#line 138
static void TestSenderP__SplitControl__stopDone(error_t error);
# 2 "/opt/tinyos-2.x/tos/lib/rf1a-multi/DelayedSendRf1aPhysical.nc"
static void TestSenderP__DelayedSendRf1aPhysical__sendReady(void );
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void TestSenderP__reportTask__runTask(void );
# 60 "/opt/tinyos-2.x/tos/interfaces/Boot.nc"
static void TestSenderP__Boot__booted(void );
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void TestSenderP__reportRserr__runTask(void );
# 110 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static void TestSenderP__ReportSend__sendDone(
#line 103
message_t * msg, 






error_t error);
# 68 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static void TestSenderP__SendInterrupt__fired(void );
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void TestSenderP__reportSRI__runTask(void );
#line 75
static void TestSenderP__nextConfigTask__runTask(void );
#line 75
static void TestSenderP__reportDSSR__runTask(void );
# 113 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static void TestSenderP__SerialSplitControl__startDone(error_t error);
#line 138
static void TestSenderP__SerialSplitControl__stopDone(error_t error);
# 68 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static void TestSenderP__NextInterrupt__fired(void );
# 110 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static void TestSenderP__RadioSend__sendDone(
#line 103
message_t * msg, 






error_t error);
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void TestSenderP__reportNI__runTask(void );
#line 75
static void TestSenderP__tryNextConfigTask__runTask(void );
#line 75
static void TestSenderP__reportSI__runTask(void );
#line 75
static void TestSenderP__loadNextTask__runTask(void );
# 68 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static void TestSenderP__SendReadyInterrupt__fired(void );
# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t PlatformP__Init__init(void );
#line 62
static error_t PlatformP__PeripheralInit__default__init(void );
#line 62
static error_t PlatformPinsP__Init__init(void );
#line 62
static error_t PlatformLedP__Init__init(void );
# 134 "/opt/tinyos-2.x/tos/interfaces/Leds.nc"
static void PlatformLedP__Leds__set(uint8_t val);
# 78 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void /*HplMsp430GeneralIOC.P15*/HplMsp430GeneralIORenP__5__IO__makeInput(void );






static void /*HplMsp430GeneralIOC.P15*/HplMsp430GeneralIORenP__5__IO__makeOutput(void );
#line 99
static void /*HplMsp430GeneralIOC.P15*/HplMsp430GeneralIORenP__5__IO__selectIOFunc(void );
#line 92
static void /*HplMsp430GeneralIOC.P15*/HplMsp430GeneralIORenP__5__IO__selectModuleFunc(void );
#line 85
static void /*HplMsp430GeneralIOC.P16*/HplMsp430GeneralIORenP__6__IO__makeOutput(void );
#line 99
static void /*HplMsp430GeneralIOC.P16*/HplMsp430GeneralIORenP__6__IO__selectIOFunc(void );
#line 92
static void /*HplMsp430GeneralIOC.P16*/HplMsp430GeneralIORenP__6__IO__selectModuleFunc(void );
#line 85
static void /*HplMsp430GeneralIOC.P17*/HplMsp430GeneralIORenP__7__IO__makeOutput(void );
#line 48
static void /*HplMsp430GeneralIOC.P17*/HplMsp430GeneralIORenP__7__IO__set(void );
#line 78
static void /*HplMsp430GeneralIOC.P20*/HplMsp430GeneralIORenP__8__IO__makeInput(void );
#line 78
static void /*HplMsp430GeneralIOC.P21*/HplMsp430GeneralIORenP__9__IO__makeInput(void );
#line 99
static void /*HplMsp430GeneralIOC.P21*/HplMsp430GeneralIORenP__9__IO__selectIOFunc(void );
#line 78
static void /*HplMsp430GeneralIOC.P22*/HplMsp430GeneralIORenP__10__IO__makeInput(void );






static void /*HplMsp430GeneralIOC.P23*/HplMsp430GeneralIORenP__11__IO__makeOutput(void );
#line 48
static void /*HplMsp430GeneralIOC.P23*/HplMsp430GeneralIORenP__11__IO__set(void );




static void /*HplMsp430GeneralIOC.P23*/HplMsp430GeneralIORenP__11__IO__clr(void );
#line 85
static void /*HplMsp430GeneralIOC.P24*/HplMsp430GeneralIORenP__12__IO__makeOutput(void );
#line 48
static void /*HplMsp430GeneralIOC.P24*/HplMsp430GeneralIORenP__12__IO__set(void );




static void /*HplMsp430GeneralIOC.P24*/HplMsp430GeneralIORenP__12__IO__clr(void );
#line 85
static void /*HplMsp430GeneralIOC.P33*/HplMsp430GeneralIORenP__19__IO__makeOutput(void );
#line 48
static void /*HplMsp430GeneralIOC.P33*/HplMsp430GeneralIORenP__19__IO__set(void );




static void /*HplMsp430GeneralIOC.P34*/HplMsp430GeneralIORenP__20__IO__clr(void );
#line 85
static void /*HplMsp430GeneralIOC.P35*/HplMsp430GeneralIORenP__21__IO__makeOutput(void );
#line 85
static void /*HplMsp430GeneralIOC.P36*/HplMsp430GeneralIORenP__22__IO__makeOutput(void );
#line 53
static void /*HplMsp430GeneralIOC.P36*/HplMsp430GeneralIORenP__22__IO__clr(void );
#line 85
static void /*HplMsp430GeneralIOC.P37*/HplMsp430GeneralIORenP__23__IO__makeOutput(void );
#line 48
static void /*HplMsp430GeneralIOC.P37*/HplMsp430GeneralIORenP__23__IO__set(void );




static void /*HplMsp430GeneralIOC.P37*/HplMsp430GeneralIORenP__23__IO__clr(void );
#line 85
static void /*HplMsp430GeneralIOC.PJ0*/HplMsp430GeneralIORenDsP__0__IO__makeOutput(void );
#line 53
static void /*HplMsp430GeneralIOC.PJ0*/HplMsp430GeneralIORenDsP__0__IO__clr(void );
#line 85
static void /*HplMsp430GeneralIOC.PJ2*/HplMsp430GeneralIORenDsP__2__IO__makeOutput(void );
#line 53
static void /*HplMsp430GeneralIOC.PJ2*/HplMsp430GeneralIORenDsP__2__IO__clr(void );
# 49 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Interrupts__default__interrupted(
# 53 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
uint8_t arg_0x406d6010, 
# 49 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
uint8_t iv);
# 256 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
static uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__getIv(void );
#line 123
static uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__getRxbuf(void );
#line 141
static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__setTxbuf(uint8_t v);
#line 111
static uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__getStat(void );
#line 231
static uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__getIe(void );
#line 288
static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__leaveResetMode_(void );
#line 273
static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__configure(const msp430_usci_config_t *config, 
bool leave_in_reset);
#line 237
static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__setIe(uint8_t v);
#line 281
static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__enterResetMode_(void );










static uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__currentMode(void );
# 49 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__RawInterrupts__interrupted(uint8_t iv);
# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__Init__init(void );
# 53 "/opt/tinyos-2.x/tos/interfaces/ResourceQueue.nc"
static bool /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__FcfsQueue__isEmpty(void );
#line 70
static resource_client_id_t /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__FcfsQueue__dequeue(void );
# 61 "/opt/tinyos-2.x/tos/interfaces/ResourceRequested.nc"
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceRequested__default__immediateRequested(
# 55 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x40731948);
# 65 "/opt/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__default__unconfigure(
# 60 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x40730cf8);
# 59 "/opt/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__default__configure(
# 60 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x40730cf8);
# 56 "/opt/tinyos-2.x/tos/interfaces/ResourceDefaultOwner.nc"
static error_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__release(void );
#line 46
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__default__granted(void );
#line 81
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__default__immediateRequested(void );
# 120 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
static error_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__release(
# 54 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x40716e70);
# 97 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
static error_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__immediateRequest(
# 54 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x40716e70);
# 102 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__default__granted(
# 54 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x40716e70);
# 90 "/opt/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
static bool /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ArbiterInfo__inUse(void );







static uint8_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ArbiterInfo__userId(void );
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__grantedTask__runTask(void );
# 65 "/opt/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__ResourceConfigure__unconfigure(
# 76 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
uint8_t arg_0x40766418);
# 59 "/opt/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__ResourceConfigure__configure(
# 76 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
uint8_t arg_0x40766418);
# 49 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Interrupts__interrupted(uint8_t iv);
# 48 "/opt/tinyos-2.x/tos/interfaces/UartStream.nc"
static error_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__send(
# 74 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
uint8_t arg_0x40767010, 
# 44 "/opt/tinyos-2.x/tos/interfaces/UartStream.nc"
uint8_t * buf, 



uint16_t len);
#line 79
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__default__receivedByte(
# 74 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
uint8_t arg_0x40767010, 
# 79 "/opt/tinyos-2.x/tos/interfaces/UartStream.nc"
uint8_t byte);
#line 99
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__default__receiveDone(
# 74 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
uint8_t arg_0x40767010, 
# 95 "/opt/tinyos-2.x/tos/interfaces/UartStream.nc"
uint8_t * buf, 



uint16_t len, error_t error);
#line 57
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__default__sendDone(
# 74 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
uint8_t arg_0x40767010, 
# 53 "/opt/tinyos-2.x/tos/interfaces/UartStream.nc"
uint8_t * buf, 



uint16_t len, error_t error);
# 44 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciConfigure.nc"
static const msp430_usci_config_t */*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Msp430UsciConfigure__default__getConfiguration(
# 86 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
uint8_t arg_0x40778338);
# 42 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciError.nc"
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Msp430UsciError__default__condition(
# 77 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
uint8_t arg_0x40766bb0, 
# 42 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciError.nc"
unsigned int errors);
# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__VectorTimerX0__fired(void );
#line 39
static void /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Overflow__fired(void );
#line 39
static void /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__VectorTimerX1__fired(void );
#line 39
static void /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Event__default__fired(
# 51 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
uint8_t arg_0x4080e458);
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static uint16_t /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Timer__get(void );
static bool /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Timer__isOverflowPending(void );
# 44 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static uint16_t /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Capture__getEvent(void );
#line 86
static void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Capture__default__captured(uint16_t time);
# 42 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
static msp430_compare_control_t /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Control__getControl(void );
#line 57
static void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Control__enableEvents(void );
static void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Control__disableEvents(void );
#line 44
static void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Control__clearPendingInterrupt(void );
# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Event__fired(void );
# 41 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Compare__setEvent(uint16_t time);

static void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Compare__setEventFromNow(uint16_t delta);
# 48 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Timer__overflow(void );
# 44 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static uint16_t /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Capture__getEvent(void );
#line 86
static void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Capture__default__captured(uint16_t time);
# 42 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
static msp430_compare_control_t /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Control__getControl(void );
#line 57
static void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Control__enableEvents(void );
static void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Control__disableEvents(void );
#line 44
static void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Control__clearPendingInterrupt(void );
# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Event__fired(void );
# 41 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Compare__setEvent(uint16_t time);

static void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Compare__setEventFromNow(uint16_t delta);
# 48 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Timer__overflow(void );
# 44 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static uint16_t /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Capture__getEvent(void );
#line 86
static void /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Capture__default__captured(uint16_t time);
# 42 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
static msp430_compare_control_t /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Control__getControl(void );
# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Event__fired(void );
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Compare__default__fired(void );
# 48 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Timer__overflow(void );
# 44 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static uint16_t /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Capture__getEvent(void );
#line 86
static void /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Capture__default__captured(uint16_t time);
# 42 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
static msp430_compare_control_t /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Control__getControl(void );
# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Event__fired(void );
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Compare__default__fired(void );
# 48 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Timer__overflow(void );
# 44 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static uint16_t /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Capture__getEvent(void );
#line 86
static void /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Capture__default__captured(uint16_t time);
# 42 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
static msp430_compare_control_t /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Control__getControl(void );
# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Event__fired(void );
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Compare__default__fired(void );
# 48 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Timer__overflow(void );
# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__VectorTimerX0__fired(void );
#line 39
static void /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__Overflow__fired(void );
#line 39
static void /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__VectorTimerX1__fired(void );
#line 39
static void /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__Event__default__fired(
# 51 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
uint8_t arg_0x4080e458);
# 44 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static uint16_t /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Capture__getEvent(void );
#line 86
static void /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Capture__default__captured(uint16_t time);
# 42 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
static msp430_compare_control_t /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Control__getControl(void );
# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Event__fired(void );
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Compare__default__fired(void );
# 48 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Timer__overflow(void );
# 44 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static uint16_t /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Capture__getEvent(void );
#line 86
static void /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Capture__default__captured(uint16_t time);
# 42 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
static msp430_compare_control_t /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Control__getControl(void );
# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Event__fired(void );
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Compare__default__fired(void );
# 48 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Timer__overflow(void );
# 44 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static uint16_t /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Capture__getEvent(void );
#line 86
static void /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Capture__default__captured(uint16_t time);
# 42 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
static msp430_compare_control_t /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Control__getControl(void );
# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Event__fired(void );
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Compare__default__fired(void );
# 48 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Timer__overflow(void );
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Compare__fired(void );
# 48 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Timer__overflow(void );
# 103 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__startAt(/*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__size_type t0, /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__size_type dt);
#line 73
static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__stop(void );
# 48 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__overflow(void );
# 64 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__size_type /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__get(void );






static bool /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__isOverflowPending(void );










static void /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__overflow(void );
#line 64
static /*CounterMilli32C.Transform*/TransformCounterC__0__Counter__size_type /*CounterMilli32C.Transform*/TransformCounterC__0__Counter__get(void );
# 109 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__size_type /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__getNow(void );
#line 103
static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__startAt(/*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__size_type t0, /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__size_type dt);
#line 116
static /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__size_type /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__getAlarm(void );
#line 73
static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__stop(void );




static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__fired(void );
# 82 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Counter__overflow(void );
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__runTask(void );
# 78 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__fired(void );
# 136 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
static uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__getNow(void );
#line 129
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__startOneShotAt(uint32_t t0, uint32_t dt);
#line 78
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__stop(void );
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__runTask(void );
# 83 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__fired(void );
#line 83
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__default__fired(
# 48 "/opt/tinyos-2.x/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x4090a9f0);
# 82 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__Counter__overflow(void );
# 49 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
static void /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Interrupts__default__interrupted(
# 53 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
uint8_t arg_0x406d6010, 
# 49 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
uint8_t iv);
# 256 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
static uint8_t /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__getIv(void );
#line 123
static uint8_t /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__getRxbuf(void );
#line 141
static void /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__setTxbuf(uint8_t v);
#line 231
static uint8_t /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__getIe(void );





static void /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__setIe(uint8_t v);
#line 292
static uint8_t /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__currentMode(void );
# 49 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
static void /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__RawInterrupts__interrupted(uint8_t iv);
# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t /*Msp430UsciB0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__1__Init__init(void );
# 59 "/opt/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
static void /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__ResourceConfigure__default__configure(
# 60 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x40730cf8);
# 102 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
static void /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__Resource__default__granted(
# 54 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x40716e70);
# 90 "/opt/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
static bool /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__ArbiterInfo__inUse(void );







static uint8_t /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__ArbiterInfo__userId(void );
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__grantedTask__runTask(void );
# 82 "/opt/tinyos-2.x/tos/interfaces/SpiPacket.nc"
static void /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__SpiPacket__default__sendDone(
# 41 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/usci/Msp430UsciSpiP.nc"
uint8_t arg_0x40968278, 
# 75 "/opt/tinyos-2.x/tos/interfaces/SpiPacket.nc"
uint8_t * txBuf, 
uint8_t * rxBuf, 





uint16_t len, 
error_t error);
# 49 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
static void /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__Interrupts__interrupted(uint8_t iv);
# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t Msp430PmmP__Init__init(void );
# 19 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/pmm/Pmm.nc"
static void Msp430PmmP__Pmm__setVoltage(uint8_t level);
# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t Msp430XV2ClockP__Init__init(void );
# 62 "/opt/tinyos-2.x/tos/interfaces/McuPowerOverride.nc"
static mcu_power_t Msp430XV2ClockControlP__McuPowerOverride__lowestState(void );
# 55 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/lpm/McuSleepEvents.nc"
static void Msp430XV2ClockControlP__McuSleepEvents__preSleep(mcu_power_t sleep_mode);





static void Msp430XV2ClockControlP__McuSleepEvents__postSleep(mcu_power_t sleep_mode);
# 60 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430XV2ClockControl.nc"
static void Msp430XV2ClockControlP__Msp430XV2ClockControl__configureTimers(void );
#line 54
static void Msp430XV2ClockControlP__Msp430XV2ClockControl__configureUnifiedClockSystem(int dco_config);
#line 94
static void Msp430XV2ClockControlP__Msp430XV2ClockControl__startMicroTimer(void );
#line 69
static void Msp430XV2ClockControlP__Msp430XV2ClockControl__start32khzTimer(void );
# 76 "/opt/tinyos-2.x/tos/interfaces/McuSleep.nc"
static void McuSleepP__McuSleep__sleep(void );
# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t PlatformOneWireInitP__Init__init(void );
# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void /*PlatformApds9007C.Msp430GpioC*/Msp430GpioC__0__GeneralIO__makeOutput(void );
#line 40
static void /*PlatformApds9007C.Msp430GpioC*/Msp430GpioC__0__GeneralIO__set(void );
# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t Apds9007InitP__Init__init(void );
#line 62
static error_t PlatformFlashInitP__Init__init(void );
#line 62
static error_t NoCC1190P__Init__init(void );
# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void /*PlatformCC1190C.HGMGpio*/Msp430GpioC__1__GeneralIO__makeOutput(void );
#line 41
static void /*PlatformCC1190C.HGMGpio*/Msp430GpioC__1__GeneralIO__clr(void );




static void /*PlatformCC1190C.LNA_ENGpio*/Msp430GpioC__2__GeneralIO__makeOutput(void );
#line 41
static void /*PlatformCC1190C.PA_ENGpio*/Msp430GpioC__3__GeneralIO__clr(void );




static void /*PlatformCC1190C.PowerGpio*/Msp430GpioC__4__GeneralIO__makeOutput(void );
#line 41
static void /*PlatformCC1190C.PowerGpio*/Msp430GpioC__4__GeneralIO__clr(void );
# 104 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static error_t PlatformBusPowerP__SplitControl__start(void );
#line 130
static error_t PlatformBusPowerP__SplitControl__stop(void );
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void PlatformBusPowerP__stopDoneTask__runTask(void );
# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t PlatformBusPowerP__Init__init(void );
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void PlatformBusPowerP__startDoneTask__runTask(void );
# 113 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static void BusPowerC__SplitControl__default__startDone(
# 4 "/opt/tinyos-2.x/tos/lib/busPower/BusPowerC.nc"
uint8_t arg_0x40a30e78, 
# 113 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
error_t error);
#line 113
static void BusPowerC__SubSplitControl__startDone(error_t error);
#line 138
static void BusPowerC__SubSplitControl__stopDone(error_t error);
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void BusPowerC__subStartTask__runTask(void );
#line 75
static void BusPowerC__subStopTask__runTask(void );
#line 75
static void BusPowerC__clearStartFlags__runTask(void );
#line 75
static void BusPowerC__clearStopFlags__runTask(void );
# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__GeneralIO__makeOutput(void );
#line 40
static void /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__GeneralIO__set(void );
static void /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__GeneralIO__clr(void );
# 113 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static void PlatformBatteryVoltageP__SplitControl__default__startDone(error_t error);
#line 138
static void PlatformBatteryVoltageP__SplitControl__default__stopDone(error_t error);
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void PlatformBatteryVoltageP__stopDoneTask__runTask(void );
# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t PlatformBatteryVoltageP__Init__init(void );
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void PlatformBatteryVoltageP__startDoneTask__runTask(void );
# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void /*PlatformBatteryVoltageC.Msp430GpioC*/Msp430GpioC__6__GeneralIO__makeOutput(void );
#line 41
static void /*PlatformBatteryVoltageC.Msp430GpioC*/Msp430GpioC__6__GeneralIO__clr(void );
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t SchedulerBasicP__TaskBasic__postTask(
# 56 "/opt/tinyos-2.x/tos/system/SchedulerBasicP.nc"
uint8_t arg_0x40467088);
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void SchedulerBasicP__TaskBasic__default__runTask(
# 56 "/opt/tinyos-2.x/tos/system/SchedulerBasicP.nc"
uint8_t arg_0x40467088);
# 57 "/opt/tinyos-2.x/tos/interfaces/Scheduler.nc"
static void SchedulerBasicP__Scheduler__init(void );
#line 72
static void SchedulerBasicP__Scheduler__taskLoop(void );
#line 65
static bool SchedulerBasicP__Scheduler__runNextTask(void );
# 80 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static error_t /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__AMSend__send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
#line 135
static 
#line 133
void * 

/*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__AMSend__getPayload(
#line 132
message_t * msg, 


uint8_t len);
# 100 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static void /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__Send__sendDone(
#line 96
message_t * msg, 



error_t error);
# 110 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__sendDone(
# 48 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
am_id_t arg_0x40ab51b8, 
# 103 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t * msg, 






error_t error);
# 75 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__send(
# 46 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40ab77a8, 
# 67 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t * msg, 







uint8_t len);
#line 125
static 
#line 123
void * 

/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__getPayload(
# 46 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40ab77a8, 
# 122 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t * msg, 


uint8_t len);
#line 100
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__default__sendDone(
# 46 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40ab77a8, 
# 96 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask__runTask(void );
#line 75
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__CancelTask__runTask(void );
# 65 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
static void Rf1aAMPacketP__Packet__clear(
#line 62
message_t * msg);
#line 78
static uint8_t Rf1aAMPacketP__Packet__payloadLength(
#line 74
message_t * msg);
#line 126
static 
#line 123
void * 


Rf1aAMPacketP__Packet__getPayload(
#line 121
message_t * msg, 




uint8_t len);
#line 94
static void Rf1aAMPacketP__Packet__setPayloadLength(
#line 90
message_t * msg, 



uint8_t len);
# 68 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
static am_addr_t Rf1aAMPacketP__AMPacket__address(void );









static am_addr_t Rf1aAMPacketP__AMPacket__destination(
#line 74
message_t * amsg);
#line 121
static void Rf1aAMPacketP__AMPacket__setSource(
#line 117
message_t * amsg, 



am_addr_t addr);
#line 103
static void Rf1aAMPacketP__AMPacket__setDestination(
#line 99
message_t * amsg, 



am_addr_t addr);
#line 147
static am_id_t Rf1aAMPacketP__AMPacket__type(
#line 143
message_t * amsg);
#line 162
static void Rf1aAMPacketP__AMPacket__setType(
#line 158
message_t * amsg, 



am_id_t t);
#line 136
static bool Rf1aAMPacketP__AMPacket__isForMe(
#line 133
message_t * amsg);
# 57 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aPacket.nc"
static void /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Rf1aPacket__configureAsData(message_t *msg);
#line 47
static rf1a_metadata_t */*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Rf1aPacket__metadata(message_t *msg);
# 65 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
static void /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Packet__clear(
#line 62
message_t * msg);
#line 78
static uint8_t /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Packet__payloadLength(
#line 74
message_t * msg);
#line 126
static 
#line 123
void * 


/*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Packet__getPayload(
#line 121
message_t * msg, 




uint8_t len);
#line 94
static void /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Packet__setPayloadLength(
#line 90
message_t * msg, 



uint8_t len);
# 39 "/opt/tinyos-2.x/tos/interfaces/Ieee154Packet.nc"
static ieee154_saddr_t /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__destination(message_t *msg);





static void /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__setSource(message_t *msg, ieee154_saddr_t addr);
#line 43
static void /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__setDestination(message_t *msg, ieee154_saddr_t addr);







static void /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__setPan(message_t *msg, ieee154_panid_t grp);

static ieee154_panid_t /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__localPan(void );
# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Init__init(void );
# 48 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/interfaces/Ieee154Address.nc"
static ieee154_saddr_t Ieee154AddressP__Ieee154Address__shortAddress(void );


static ieee154_panid_t Ieee154AddressP__Ieee154Address__panId(void );
# 52 "/opt/tinyos-2.x/tos/interfaces/Random.nc"
static uint16_t RandomMlcgC__Random__rand16(void );
#line 46
static uint32_t RandomMlcgC__Random__rand32(void );
# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t RandomMlcgC__Init__init(void );
# 50 "/opt/tinyos-2.x/tos/interfaces/ActiveMessageAddress.nc"
static am_addr_t Ieee154AMAddressP__ActiveMessageAddress__amAddress(void );
# 358 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIf.nc"
static uint16_t /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__getIes(void );
#line 445
static void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__readBurstRegister(uint8_t addr, 
uint8_t *buf, 
uint8_t len);
#line 438
static void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__writeRegister(uint8_t addr, uint8_t val);
#line 351
static void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__setIfg(uint16_t v);
#line 424
static uint8_t /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__strobe(uint8_t instr);
#line 370
static uint16_t /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__getIe(void );
#line 454
static void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__writeBurstRegister(uint8_t addr, 
const uint8_t *buf, 
uint8_t len);
#line 474
static void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__writeSinglePATable(uint8_t value);
#line 375
static void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__setIe(uint16_t v);
#line 334
static uint16_t /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__getIn(void );
#line 363
static void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__setIes(uint16_t v);
#line 431
static uint8_t /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__readRegister(uint8_t addr);
#line 467
static uint8_t /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__resetRadioCore(void );
# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__Init__init(void );
# 79 "/opt/tinyos-2.x/tos/interfaces/ResourceQueue.nc"
static error_t /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__FcfsQueue__enqueue(resource_client_id_t id);
#line 53
static bool /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__FcfsQueue__isEmpty(void );








static bool /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__FcfsQueue__isEnqueued(resource_client_id_t id);







static resource_client_id_t /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__FcfsQueue__dequeue(void );
# 53 "/opt/tinyos-2.x/tos/interfaces/ResourceRequested.nc"
static void /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ResourceRequested__default__requested(
# 52 "/opt/tinyos-2.x/tos/system/SimpleArbiterP.nc"
uint8_t arg_0x40c3d770);
# 120 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
static error_t /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Resource__release(
# 51 "/opt/tinyos-2.x/tos/system/SimpleArbiterP.nc"
uint8_t arg_0x40c40c68);
# 88 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
static error_t /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Resource__request(
# 51 "/opt/tinyos-2.x/tos/system/SimpleArbiterP.nc"
uint8_t arg_0x40c40c68);
# 102 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
static void /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Resource__default__granted(
# 51 "/opt/tinyos-2.x/tos/system/SimpleArbiterP.nc"
uint8_t arg_0x40c40c68);
# 90 "/opt/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
static bool /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ArbiterInfo__inUse(void );







static uint8_t /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ArbiterInfo__userId(void );
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__grantedTask__runTask(void );
# 65 "/opt/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ResourceConfigure__unconfigure(
# 58 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74328);
# 59 "/opt/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ResourceConfigure__configure(
# 58 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74328);
# 3 "/opt/tinyos-2.x/tos/lib/rf1a-multi/DelayedSendRf1aPhysical.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__DelayedSendRf1aPhysical__completeSend(
# 62 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c72e58);
# 2 "/opt/tinyos-2.x/tos/lib/rf1a-multi/DelayedSendRf1aPhysical.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__DelayedSendRf1aPhysical__default__sendReady(
# 62 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c72e58);
# 23 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__rxOverflow(
# 69 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c902a0);
# 10 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__rxFifoAvailable(
# 69 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c902a0);
# 44 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__clearChannel(
# 69 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c902a0);
# 16 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__txFifoAvailable(
# 69 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c902a0);
# 29 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__txUnderflow(
# 69 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c902a0);
# 36 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__syncWordEvent(
# 69 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c902a0);
# 51 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__carrierSense(
# 69 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c902a0);
# 54 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__coreInterrupt(
# 69 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c902a0, 
# 54 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
uint16_t iv);
# 67 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysicalMetadata.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysicalMetadata__store(rf1a_metadata_t *metadatap);
# 282 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__frameStarted(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8);
# 100 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
static error_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__send(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8, 
# 100 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
uint8_t *buffer, unsigned int length);
#line 253
static error_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__setReceiveBuffer(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8, 
# 253 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
uint8_t *buffer, 
unsigned int length, 
bool single_use);
#line 307
static unsigned int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__defaultTransmitReadyCount(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8, 
# 307 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
unsigned int count);
#line 189
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__receiveStarted(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8, 
# 189 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
unsigned int length);
#line 205
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__receiveDone(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8, 
# 205 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
uint8_t *buffer, 
unsigned int count, 
int result);
#line 289
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__clearChannel(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8);
# 316 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
static const uint8_t */*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__defaultTransmitData(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8, 
# 316 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
unsigned int count);
#line 274
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__receiveBufferFilled(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8, 
# 274 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
uint8_t *buffer, 
unsigned int count);
#line 115
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__sendDone(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8, 
# 115 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
int result);
#line 298
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__carrierSense(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8);
# 321 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__released(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8);
# 72 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTransmitFragment.nc"
static const uint8_t */*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aTransmitFragment__default__transmitData(
# 68 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c6bd70, 
# 72 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTransmitFragment.nc"
unsigned int count);
#line 55
static unsigned int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aTransmitFragment__default__transmitReadyCount(
# 68 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c6bd70, 
# 55 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTransmitFragment.nc"
unsigned int count);
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveData_task__runTask(void );
#line 75
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__sendFragment_task__runTask(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t */*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__getConfiguration(
# 67 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c6b300);
# 62 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__preConfigure(
# 67 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c6b300);
# 71 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__postConfigure(
# 67 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c6b300);
# 83 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__postUnconfigure(
# 67 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c6b300);
# 78 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__preUnconfigure(
# 67 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c6b300);
# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__GeneralIO__makeOutput(void );
#line 40
static void /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__GeneralIO__set(void );
static void /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__GeneralIO__clr(void );
# 10 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMulti.nc"
static uint8_t /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aMulti__getNumConfigs(void );










static uint8_t /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aMulti__getConfig(void );





static uint16_t /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aMulti__getConfigId(void );
#line 16
static error_t /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aMulti__setConfig(uint8_t configId);
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t */*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__getConfiguration(
# 4 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
uint8_t arg_0x40d95768);
# 62 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__preConfigure(
# 4 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
uint8_t arg_0x40d95768);
# 71 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__postConfigure(
# 4 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
uint8_t arg_0x40d95768);
# 83 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__postUnconfigure(
# 4 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
uint8_t arg_0x40d95768);
# 78 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__preUnconfigure(
# 4 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
uint8_t arg_0x40d95768);
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubGet__val_t /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubGet__default__get(
# 5 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
uint8_t arg_0x40d93da8);
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t */*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__getConfiguration(void );





static void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__preConfigure(void );








static void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__postConfigure(void );
#line 83
static void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__postUnconfigure(void );
#line 78
static void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static CUSTOM_HC__Get__val_t CUSTOM_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *CUSTOM_HC__Rf1aConfigure__getConfiguration(void );





static void CUSTOM_HC__Rf1aConfigure__preConfigure(void );








static void CUSTOM_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void CUSTOM_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void CUSTOM_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_2FSK_1P2K_SENS_HC__Get__val_t SRFS6_868_2FSK_1P2K_SENS_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_GFSK_100K_CUR_HC__Get__val_t SRFS6_868_GFSK_100K_CUR_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_GFSK_100K_SENS_HC__Get__val_t SRFS6_868_GFSK_100K_SENS_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_GFSK_10K_CUR_HC__Get__val_t SRFS6_868_GFSK_10K_CUR_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_GFSK_10K_SENS_HC__Get__val_t SRFS6_868_GFSK_10K_SENS_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_GFSK_175K_CUR_HC__Get__val_t SRFS6_868_GFSK_175K_CUR_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_GFSK_175K_SENS_HC__Get__val_t SRFS6_868_GFSK_175K_SENS_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_GFSK_1P2K_CUR_HC__Get__val_t SRFS6_868_GFSK_1P2K_CUR_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_GFSK_1P2K_SENS_HC__Get__val_t SRFS6_868_GFSK_1P2K_SENS_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_GFSK_250K_CUR_HC__Get__val_t SRFS6_868_GFSK_250K_CUR_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_GFSK_250K_SENS_HC__Get__val_t SRFS6_868_GFSK_250K_SENS_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_GFSK_2P4K_CUR_HC__Get__val_t SRFS6_868_GFSK_2P4K_CUR_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_GFSK_2P4K_SENS_HC__Get__val_t SRFS6_868_GFSK_2P4K_SENS_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_GFSK_38P4K_CUR_HC__Get__val_t SRFS6_868_GFSK_38P4K_CUR_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_GFSK_38P4K_SENS_HC__Get__val_t SRFS6_868_GFSK_38P4K_SENS_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_GFSK_4P8K_CUR_HC__Get__val_t SRFS6_868_GFSK_4P8K_CUR_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_GFSK_4P8K_SENS_HC__Get__val_t SRFS6_868_GFSK_4P8K_SENS_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_GFSK_76P8K_CUR_HC__Get__val_t SRFS6_868_GFSK_76P8K_CUR_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_GFSK_76P8K_SENS_HC__Get__val_t SRFS6_868_GFSK_76P8K_SENS_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_868_MSK_500K_HC__Get__val_t SRFS6_868_MSK_500K_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_868_MSK_500K_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_868_MSK_500K_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_868_MSK_500K_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_868_MSK_500K_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_868_MSK_500K_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_PRE802154G_HC__Get__val_t SRFS6_PRE802154G_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_PRE802154G_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_PRE802154G_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_PRE802154G_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_PRE802154G_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_PRE802154G_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS6_RESET_HC__Get__val_t SRFS6_RESET_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS6_RESET_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS6_RESET_HC__Rf1aConfigure__preConfigure(void );








static void SRFS6_RESET_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS6_RESET_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS6_RESET_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS7_779_MSK_250K_HC__Get__val_t SRFS7_779_MSK_250K_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS7_779_MSK_250K_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS7_779_MSK_250K_HC__Rf1aConfigure__preConfigure(void );








static void SRFS7_779_MSK_250K_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS7_779_MSK_250K_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS7_779_MSK_250K_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS7_902P2_GFSK_50K_135B_HC__Get__val_t SRFS7_902P2_GFSK_50K_135B_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__preConfigure(void );








static void SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS7_902P2_GFSK_50K_163B_HC__Get__val_t SRFS7_902P2_GFSK_50K_163B_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__preConfigure(void );








static void SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS7_STI_902_GFSK_1P2K_HC__Get__val_t SRFS7_STI_902_GFSK_1P2K_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__preConfigure(void );








static void SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static SRFS7_STI_902_GFSK_250K_HC__Get__val_t SRFS7_STI_902_GFSK_250K_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__getConfiguration(void );





static void SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__preConfigure(void );








static void SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__preUnconfigure(void );
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static TINYOSRF1A_HC__Get__val_t TINYOSRF1A_HC__Get__get(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t *TINYOSRF1A_HC__Rf1aConfigure__getConfiguration(void );





static void TINYOSRF1A_HC__Rf1aConfigure__preConfigure(void );








static void TINYOSRF1A_HC__Rf1aConfigure__postConfigure(void );
#line 83
static void TINYOSRF1A_HC__Rf1aConfigure__postUnconfigure(void );
#line 78
static void TINYOSRF1A_HC__Rf1aConfigure__preUnconfigure(void );
# 104 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SplitControl__start(void );
#line 130
static error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SplitControl__stop(void );
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__receiveDone_task__runTask(void );
# 75 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Send__send(
# 43 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
uint8_t arg_0x40f45d50, 
# 67 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t * msg, 







uint8_t len);
#line 100
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Send__default__sendDone(
# 43 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
uint8_t arg_0x40f45d50, 
# 96 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 282 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__frameStarted(void );
#line 189
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__receiveStarted(unsigned int length);
#line 205
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__receiveDone(uint8_t *buffer, 
unsigned int count, 
int result);
#line 289
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__clearChannel(void );
#line 274
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__receiveBufferFilled(uint8_t *buffer, 
unsigned int count);
#line 115
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__sendDone(int result);
#line 298
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__carrierSense(void );
#line 321
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__released(void );
# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Receive__default__receive(
# 44 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
uint8_t arg_0x40f42798, 
# 71 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 102 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Resource__granted(void );
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__sendDone_task__runTask(void );
#line 75
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__stopDone_task__runTask(void );
# 100 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__SubSend__sendDone(
#line 96
message_t * msg, 



error_t error);
# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__SubReceive__receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
# 75 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static error_t /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__Send__send(
#line 67
message_t * msg, 







uint8_t len);
#line 100
static void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckSend__sendDone(
#line 96
message_t * msg, 



error_t error);
# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckReceive__receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ackWaitAlarmFired_task__runTask(void );
# 78 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckWaitAlarm__fired(void );
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430Compare__fired(void );
# 48 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430Timer__overflow(void );
# 109 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__size_type /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__getNow(void );
#line 103
static void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__startAt(/*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__size_type t0, /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__size_type dt);
#line 66
static void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__start(/*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__size_type dt);
# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



UniqueReceiveP__SubReceive__receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
#line 78
static 
#line 74
message_t * 



UniqueReceiveP__DuplicateReceive__default__receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
# 48 "/opt/tinyos-2.x/tos/lib/util/keyvaluerecord/KeyValueRecord.nc"
static bool KeyValueRecordP__KeyValueRecord__hasSeen(
# 43 "/opt/tinyos-2.x/tos/lib/util/keyvaluerecord/KeyValueRecordP.nc"
uint8_t arg_0x40fe8440, 
# 48 "/opt/tinyos-2.x/tos/lib/util/keyvaluerecord/KeyValueRecord.nc"
uint16_t key, uint16_t value);







static void KeyValueRecordP__KeyValueRecord__insert(
# 43 "/opt/tinyos-2.x/tos/lib/util/keyvaluerecord/KeyValueRecordP.nc"
uint8_t arg_0x40fe8440, 
# 56 "/opt/tinyos-2.x/tos/lib/util/keyvaluerecord/KeyValueRecord.nc"
uint16_t key, uint16_t value);
# 100 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static void Rf1aActiveMessageP__SubSend__sendDone(
#line 96
message_t * msg, 



error_t error);
# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



Rf1aActiveMessageP__SubReceive__receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
# 59 "/opt/tinyos-2.x/tos/interfaces/SendNotifier.nc"
static void Rf1aActiveMessageP__SendNotifier__default__aboutToSend(
# 43 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aActiveMessageP.nc"
am_id_t arg_0x41015d78, 
# 59 "/opt/tinyos-2.x/tos/interfaces/SendNotifier.nc"
am_addr_t dest, 
#line 57
message_t * msg);
# 80 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static error_t Rf1aActiveMessageP__AMSend__send(
# 40 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aActiveMessageP.nc"
am_id_t arg_0x40ffa678, 
# 80 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
#line 135
static 
#line 133
void * 

Rf1aActiveMessageP__AMSend__getPayload(
# 40 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aActiveMessageP.nc"
am_id_t arg_0x40ffa678, 
# 132 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t * msg, 


uint8_t len);
# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



Rf1aActiveMessageP__Snoop__default__receive(
# 42 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aActiveMessageP.nc"
am_id_t arg_0x41015700, 
# 71 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
#line 78
static 
#line 74
message_t * 



Rf1aActiveMessageP__Receive__default__receive(
# 41 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aActiveMessageP.nc"
am_id_t arg_0x41015068, 
# 71 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 100 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static void /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__SubSend__sendDone(
#line 96
message_t * msg, 



error_t error);
# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



/*SerialActiveMessageC.AM*/SerialActiveMessageP__0__SubReceive__receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
# 80 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static error_t /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMSend__send(
# 47 "/opt/tinyos-2.x/tos/lib/serial/SerialActiveMessageP.nc"
am_id_t arg_0x41056e60, 
# 80 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
#line 135
static 
#line 133
void * 

/*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMSend__getPayload(
# 47 "/opt/tinyos-2.x/tos/lib/serial/SerialActiveMessageP.nc"
am_id_t arg_0x41056e60, 
# 132 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t * msg, 


uint8_t len);
# 78 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
static uint8_t /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Packet__payloadLength(
#line 74
message_t * msg);
#line 126
static 
#line 123
void * 


/*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Packet__getPayload(
#line 121
message_t * msg, 




uint8_t len);
#line 106
static uint8_t /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Packet__maxPayloadLength(void );
#line 94
static void /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Packet__setPayloadLength(
#line 90
message_t * msg, 



uint8_t len);
# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



/*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Receive__default__receive(
# 48 "/opt/tinyos-2.x/tos/lib/serial/SerialActiveMessageP.nc"
am_id_t arg_0x410538e0, 
# 71 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 78 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
static am_addr_t /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMPacket__destination(
#line 74
message_t * amsg);
#line 103
static void /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMPacket__setDestination(
#line 99
message_t * amsg, 



am_addr_t addr);
#line 147
static am_id_t /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMPacket__type(
#line 143
message_t * amsg);
#line 162
static void /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMPacket__setType(
#line 158
message_t * amsg, 



am_id_t t);
# 104 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static error_t SerialP__SplitControl__start(void );
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void SerialP__stopDoneTask__runTask(void );
#line 75
static void SerialP__RunTx__runTask(void );
# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t SerialP__Init__init(void );
# 54 "/opt/tinyos-2.x/tos/lib/serial/SerialFlush.nc"
static void SerialP__SerialFlush__flushDone(void );
#line 49
static void SerialP__SerialFlush__default__flush(void );
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void SerialP__startDoneTask__runTask(void );
# 94 "/opt/tinyos-2.x/tos/lib/serial/SerialFrameComm.nc"
static void SerialP__SerialFrameComm__dataReceived(uint8_t data);





static void SerialP__SerialFrameComm__putDone(void );
#line 85
static void SerialP__SerialFrameComm__delimiterReceived(void );
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void SerialP__defaultSerialFlushTask__runTask(void );
# 71 "/opt/tinyos-2.x/tos/lib/serial/SendBytePacket.nc"
static error_t SerialP__SendBytePacket__completeSend(void );
#line 62
static error_t SerialP__SendBytePacket__startSend(uint8_t first_byte);
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTask__runTask(void );
# 75 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static error_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__Send__send(
# 51 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
uart_id_t arg_0x4110c560, 
# 67 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t * msg, 







uint8_t len);
#line 100
static void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__Send__default__sendDone(
# 51 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
uart_id_t arg_0x4110c560, 
# 96 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__signalSendDone__runTask(void );
# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__Receive__default__receive(
# 50 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
uart_id_t arg_0x410d2e50, 
# 71 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 31 "/opt/tinyos-2.x/tos/lib/serial/SerialPacketInfo.nc"
static uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__default__upperLength(
# 54 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
uart_id_t arg_0x4110b088, 
# 31 "/opt/tinyos-2.x/tos/lib/serial/SerialPacketInfo.nc"
message_t *msg, uint8_t dataLinkLen);
#line 15
static uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__default__offset(
# 54 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
uart_id_t arg_0x4110b088);
# 23 "/opt/tinyos-2.x/tos/lib/serial/SerialPacketInfo.nc"
static uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__default__dataLinkLength(
# 54 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
uart_id_t arg_0x4110b088, 
# 23 "/opt/tinyos-2.x/tos/lib/serial/SerialPacketInfo.nc"
message_t *msg, uint8_t upperLen);
# 81 "/opt/tinyos-2.x/tos/lib/serial/SendBytePacket.nc"
static uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__SendBytePacket__nextByte(void );









static void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__SendBytePacket__sendCompleted(error_t error);
# 62 "/opt/tinyos-2.x/tos/lib/serial/ReceiveBytePacket.nc"
static error_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__ReceiveBytePacket__startPacket(void );






static void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__ReceiveBytePacket__byteReceived(uint8_t data);










static void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__ReceiveBytePacket__endPacket(error_t result);
# 79 "/opt/tinyos-2.x/tos/interfaces/UartStream.nc"
static void HdlcTranslateC__UartStream__receivedByte(uint8_t byte);
#line 99
static void HdlcTranslateC__UartStream__receiveDone(
#line 95
uint8_t * buf, 



uint16_t len, error_t error);
#line 57
static void HdlcTranslateC__UartStream__sendDone(
#line 53
uint8_t * buf, 



uint16_t len, error_t error);
# 56 "/opt/tinyos-2.x/tos/lib/serial/SerialFrameComm.nc"
static error_t HdlcTranslateC__SerialFrameComm__putDelimiter(void );
#line 79
static void HdlcTranslateC__SerialFrameComm__resetReceive(void );
#line 65
static error_t HdlcTranslateC__SerialFrameComm__putData(uint8_t data);
# 102 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
static void PlatformSerialP__Resource__granted(void );
# 95 "/opt/tinyos-2.x/tos/interfaces/StdControl.nc"
static error_t PlatformSerialP__StdControl__start(void );









static error_t PlatformSerialP__StdControl__stop(void );
# 31 "/opt/tinyos-2.x/tos/lib/serial/SerialPacketInfo.nc"
static uint8_t SerialPacketInfoActiveMessageP__Info__upperLength(message_t *msg, uint8_t dataLinkLen);
#line 15
static uint8_t SerialPacketInfoActiveMessageP__Info__offset(void );







static uint8_t SerialPacketInfoActiveMessageP__Info__dataLinkLength(message_t *msg, uint8_t upperLen);
# 80 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static error_t /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__AMSend__send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
#line 135
static 
#line 133
void * 

/*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__AMSend__getPayload(
#line 132
message_t * msg, 


uint8_t len);
# 100 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static void /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__Send__sendDone(
#line 96
message_t * msg, 



error_t error);
# 110 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__AMSend__sendDone(
# 48 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
am_id_t arg_0x40ab51b8, 
# 103 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t * msg, 






error_t error);
# 75 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static error_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Send__send(
# 46 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40ab77a8, 
# 67 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t * msg, 







uint8_t len);
#line 125
static 
#line 123
void * 

/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Send__getPayload(
# 46 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40ab77a8, 
# 122 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t * msg, 


uint8_t len);
#line 100
static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Send__default__sendDone(
# 46 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40ab77a8, 
# 96 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__errorTask__runTask(void );
#line 75
static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__CancelTask__runTask(void );
# 52 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
static void HplMsp430InterruptP__Port14__clear(void );
#line 72
static void HplMsp430InterruptP__Port14__default__fired(void );
#line 52
static void HplMsp430InterruptP__Port26__clear(void );
#line 72
static void HplMsp430InterruptP__Port26__default__fired(void );
#line 52
static void HplMsp430InterruptP__Port17__clear(void );
#line 72
static void HplMsp430InterruptP__Port17__default__fired(void );
#line 52
static void HplMsp430InterruptP__Port21__clear(void );
#line 47
static void HplMsp430InterruptP__Port21__disable(void );
#line 67
static void HplMsp430InterruptP__Port21__edge(bool low_to_high);
#line 42
static void HplMsp430InterruptP__Port21__enable(void );









static void HplMsp430InterruptP__Port12__clear(void );
#line 72
static void HplMsp430InterruptP__Port12__default__fired(void );
#line 52
static void HplMsp430InterruptP__Port24__clear(void );
#line 72
static void HplMsp430InterruptP__Port24__default__fired(void );
#line 52
static void HplMsp430InterruptP__Port15__clear(void );
#line 72
static void HplMsp430InterruptP__Port15__default__fired(void );
#line 52
static void HplMsp430InterruptP__Port27__clear(void );
#line 72
static void HplMsp430InterruptP__Port27__default__fired(void );
#line 52
static void HplMsp430InterruptP__Port10__clear(void );
#line 72
static void HplMsp430InterruptP__Port10__default__fired(void );
#line 52
static void HplMsp430InterruptP__Port22__clear(void );
#line 47
static void HplMsp430InterruptP__Port22__disable(void );
#line 67
static void HplMsp430InterruptP__Port22__edge(bool low_to_high);
#line 42
static void HplMsp430InterruptP__Port22__enable(void );









static void HplMsp430InterruptP__Port13__clear(void );
#line 72
static void HplMsp430InterruptP__Port13__default__fired(void );
#line 52
static void HplMsp430InterruptP__Port25__clear(void );
#line 72
static void HplMsp430InterruptP__Port25__default__fired(void );
#line 52
static void HplMsp430InterruptP__Port16__clear(void );
#line 72
static void HplMsp430InterruptP__Port16__default__fired(void );
#line 52
static void HplMsp430InterruptP__Port20__clear(void );
#line 47
static void HplMsp430InterruptP__Port20__disable(void );
#line 67
static void HplMsp430InterruptP__Port20__edge(bool low_to_high);
#line 42
static void HplMsp430InterruptP__Port20__enable(void );









static void HplMsp430InterruptP__Port11__clear(void );
#line 72
static void HplMsp430InterruptP__Port11__default__fired(void );
#line 52
static void HplMsp430InterruptP__Port23__clear(void );
#line 72
static void HplMsp430InterruptP__Port23__default__fired(void );
# 44 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void /*TestSenderAppC.NextPin*/Msp430GpioC__7__GeneralIO__makeInput(void );
# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
static void /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__HplInterrupt__fired(void );
# 61 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static error_t /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__Interrupt__disable(void );
#line 53
static error_t /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__Interrupt__enableRisingEdge(void );
# 44 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void /*TestSenderAppC.SendReadyPin*/Msp430GpioC__8__GeneralIO__makeInput(void );
# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
static void /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__HplInterrupt__fired(void );
# 61 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static error_t /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__Interrupt__disable(void );
#line 54
static error_t /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__Interrupt__enableFallingEdge(void );
# 44 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void /*TestSenderAppC.SendPin*/Msp430GpioC__9__GeneralIO__makeInput(void );
# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
static void /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__HplInterrupt__fired(void );
# 61 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static error_t /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__Interrupt__disable(void );
#line 53
static error_t /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__Interrupt__enableRisingEdge(void );
# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void /*TestSenderAppC.DebugPin*/Msp430GpioC__10__GeneralIO__makeOutput(void );
#line 40
static void /*TestSenderAppC.DebugPin*/Msp430GpioC__10__GeneralIO__set(void );
static void /*TestSenderAppC.DebugPin*/Msp430GpioC__10__GeneralIO__clr(void );
# 104 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static error_t TestSenderP__SplitControl__start(void );
#line 130
static error_t TestSenderP__SplitControl__stop(void );
# 3 "/opt/tinyos-2.x/tos/lib/rf1a-multi/DelayedSendRf1aPhysical.nc"
static void TestSenderP__DelayedSendRf1aPhysical__completeSend(void );
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t TestSenderP__reportTask__postTask(void );
# 44 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void TestSenderP__SendPin__makeInput(void );
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t TestSenderP__reportRserr__postTask(void );
# 80 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static error_t TestSenderP__ReportSend__send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
#line 135
static 
#line 133
void * 

TestSenderP__ReportSend__getPayload(
#line 132
message_t * msg, 


uint8_t len);
# 61 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static error_t TestSenderP__SendInterrupt__disable(void );
#line 53
static error_t TestSenderP__SendInterrupt__enableRisingEdge(void );
# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void TestSenderP__DebugPin__makeOutput(void );
#line 40
static void TestSenderP__DebugPin__set(void );
static void TestSenderP__DebugPin__clr(void );
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t TestSenderP__reportSRI__postTask(void );
#line 67
static error_t TestSenderP__nextConfigTask__postTask(void );
#line 67
static error_t TestSenderP__reportDSSR__postTask(void );
# 104 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static error_t TestSenderP__SerialSplitControl__start(void );
# 134 "/opt/tinyos-2.x/tos/interfaces/Leds.nc"
static void TestSenderP__Leds__set(uint8_t val);
# 474 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIf.nc"
static void TestSenderP__Rf1aIf__writeSinglePATable(uint8_t value);
# 53 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static error_t TestSenderP__NextInterrupt__enableRisingEdge(void );
# 80 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static error_t TestSenderP__RadioSend__send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
#line 135
static 
#line 133
void * 

TestSenderP__RadioSend__getPayload(
#line 132
message_t * msg, 


uint8_t len);
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t TestSenderP__reportNI__postTask(void );
# 10 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMulti.nc"
static uint8_t TestSenderP__Rf1aMulti__getNumConfigs(void );










static uint8_t TestSenderP__Rf1aMulti__getConfig(void );





static uint16_t TestSenderP__Rf1aMulti__getConfigId(void );
#line 16
static error_t TestSenderP__Rf1aMulti__setConfig(uint8_t configId);
# 44 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void TestSenderP__NextPin__makeInput(void );
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t TestSenderP__tryNextConfigTask__postTask(void );
#line 67
static error_t TestSenderP__reportSI__postTask(void );
#line 67
static error_t TestSenderP__loadNextTask__postTask(void );
# 61 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static error_t TestSenderP__SendReadyInterrupt__disable(void );
#line 54
static error_t TestSenderP__SendReadyInterrupt__enableFallingEdge(void );
# 99 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void TestSenderP__HplSendReadyPin__selectIOFunc(void );
# 44 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void TestSenderP__SendReadyPin__makeInput(void );
# 72 "TestSenderP.nc"
enum TestSenderP____nesc_unnamed4328 {
#line 72
  TestSenderP__tryNextConfigTask = 0U
};
#line 72
typedef int TestSenderP____nesc_sillytask_tryNextConfigTask[TestSenderP__tryNextConfigTask];
enum TestSenderP____nesc_unnamed4329 {
#line 73
  TestSenderP__nextConfigTask = 1U
};
#line 73
typedef int TestSenderP____nesc_sillytask_nextConfigTask[TestSenderP__nextConfigTask];
enum TestSenderP____nesc_unnamed4330 {
#line 74
  TestSenderP__loadNextTask = 2U
};
#line 74
typedef int TestSenderP____nesc_sillytask_loadNextTask[TestSenderP__loadNextTask];

enum TestSenderP____nesc_unnamed4331 {
#line 76
  TestSenderP__reportNI = 3U
};
#line 76
typedef int TestSenderP____nesc_sillytask_reportNI[TestSenderP__reportNI];




enum TestSenderP____nesc_unnamed4332 {
#line 81
  TestSenderP__reportSRI = 4U
};
#line 81
typedef int TestSenderP____nesc_sillytask_reportSRI[TestSenderP__reportSRI];




enum TestSenderP____nesc_unnamed4333 {
#line 86
  TestSenderP__reportSI = 5U
};
#line 86
typedef int TestSenderP____nesc_sillytask_reportSI[TestSenderP__reportSI];
#line 160
enum TestSenderP____nesc_unnamed4334 {
#line 160
  TestSenderP__reportRserr = 6U
};
#line 160
typedef int TestSenderP____nesc_sillytask_reportRserr[TestSenderP__reportRserr];
#line 207
enum TestSenderP____nesc_unnamed4335 {
#line 207
  TestSenderP__reportTask = 7U
};
#line 207
typedef int TestSenderP____nesc_sillytask_reportTask[TestSenderP__reportTask];
#line 245
enum TestSenderP____nesc_unnamed4336 {
#line 245
  TestSenderP__reportDSSR = 8U
};
#line 245
typedef int TestSenderP____nesc_sillytask_reportDSSR[TestSenderP__reportDSSR];
#line 24
enum TestSenderP____nesc_unnamed4337 {
  TestSenderP__S_STARTING = 0x01, 
  TestSenderP__S_READY = 0x02, 
  TestSenderP__S_START_NEXTCONFIG = 0x03, 
  TestSenderP__S_RADIO_STOPPING = 0x04, 
  TestSenderP__S_RADIO_STARTING = 0x05, 
  TestSenderP__S_NEED_LOAD = 0x06, 
  TestSenderP__S_LOADING = 0x07, 
  TestSenderP__S_LOADED = 0x08, 
  TestSenderP__S_WAITING_FOR_SEND = 0x09, 
  TestSenderP__S_SENDING = 0x0A, 
  TestSenderP__S_REPORTING = 0x0B, 
  TestSenderP__S_ERROR = 0x0C
};


message_t TestSenderP__rmsg;
message_t TestSenderP__smsg;

uint8_t TestSenderP__state = TestSenderP__S_STARTING;
uint8_t TestSenderP__radioOn = FALSE;
uint16_t TestSenderP__seqNum = 0;

static inline void TestSenderP__Boot__booted(void );
#line 62
static inline void TestSenderP__SerialSplitControl__startDone(error_t err);
#line 76
static inline void TestSenderP__reportNI__runTask(void );




static inline void TestSenderP__reportSRI__runTask(void );




static inline void TestSenderP__reportSI__runTask(void );




static inline void TestSenderP__NextInterrupt__fired(void );





static inline void TestSenderP__tryNextConfigTask__runTask(void );
#line 116
static inline void TestSenderP__SplitControl__stopDone(error_t err);










static inline void TestSenderP__nextConfigTask__runTask(void );
#line 140
static inline void TestSenderP__SplitControl__startDone(error_t err);
#line 158
error_t TestSenderP__rserr = 0xdc;

static inline void TestSenderP__reportRserr__runTask(void );




static inline void TestSenderP__loadNextTask__runTask(void );
#line 181
static inline void TestSenderP__SendReadyInterrupt__fired(void );
#line 193
static inline void TestSenderP__SendInterrupt__fired(void );
#line 209
static void TestSenderP__RadioSend__sendDone(message_t *msg, error_t err);
#line 223
static inline void TestSenderP__reportTask__runTask(void );









static void TestSenderP__ReportSend__sendDone(message_t *msg, error_t err);










static inline void TestSenderP__SerialSplitControl__stopDone(error_t err);
static inline void TestSenderP__reportDSSR__runTask(void );





static inline void TestSenderP__DelayedSendRf1aPhysical__sendReady(void );
# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t PlatformP__Msp430Pmm__init(void );
#line 62
static error_t PlatformP__PlatformFlash__init(void );
#line 62
static error_t PlatformP__OneWire__init(void );
#line 62
static error_t PlatformP__PlatformPins__init(void );
#line 62
static error_t PlatformP__PlatformCC1190__init(void );
#line 62
static error_t PlatformP__PlatformClock__init(void );
#line 62
static error_t PlatformP__PlatformBusPower__init(void );
#line 62
static error_t PlatformP__Apds9007__init(void );
#line 62
static error_t PlatformP__PlatformLed__init(void );
#line 62
static error_t PlatformP__PeripheralInit__init(void );
#line 62
static error_t PlatformP__BatteryVoltage__init(void );
# 58 "/opt/tinyos-2.x/tos/platforms/bacon/PlatformP.nc"
static inline void PlatformP__uwait(uint16_t u);




static inline error_t PlatformP__Init__init(void );
#line 92
static inline error_t PlatformP__PeripheralInit__default__init(void );
# 48 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/pins/PlatformPinsP.nc"
static inline error_t PlatformPinsP__Init__init(void );
# 78 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/leds/PlatformLedP.nc"
#line 71
typedef struct PlatformLedP__port_t {
  uint16_t pxin;
  uint16_t pxout;
  uint16_t pxdir;
  uint16_t pxren;
  uint16_t pxds;
  uint16_t pxsel;
} PlatformLedP__port_t;





#line 81
typedef struct PlatformLedP__led_t {
  volatile PlatformLedP__port_t *port;
  uint16_t bit;
} PlatformLedP__led_t;




static const PlatformLedP__led_t PlatformLedP__leds[3] = { 
{ (PlatformLedP__port_t *)0x0220 + 0x00, 1 << 0 }, 
{ (PlatformLedP__port_t *)0x0220 + 0x00, 1 << 1 }, 
{ (PlatformLedP__port_t *)0x0220 + 0x00, 1 << 2 } };

static const int PlatformLedP__nleds = sizeof PlatformLedP__leds / sizeof  (*PlatformLedP__leds);

static inline error_t PlatformLedP__Init__init(void );
#line 108
static inline void PlatformLedP___LEDon(uint8_t led_id);




static inline void PlatformLedP___LEDoff(uint8_t led_id);
#line 135
static void PlatformLedP___LEDwrite(unsigned int value);
#line 160
static inline void PlatformLedP__Leds__set(uint8_t v);
# 53 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P15*/HplMsp430GeneralIORenP__5__IO__makeInput(void );

static inline void /*HplMsp430GeneralIOC.P15*/HplMsp430GeneralIORenP__5__IO__makeOutput(void );

static inline void /*HplMsp430GeneralIOC.P15*/HplMsp430GeneralIORenP__5__IO__selectModuleFunc(void );

static inline void /*HplMsp430GeneralIOC.P15*/HplMsp430GeneralIORenP__5__IO__selectIOFunc(void );
#line 55
static void /*HplMsp430GeneralIOC.P16*/HplMsp430GeneralIORenP__6__IO__makeOutput(void );

static inline void /*HplMsp430GeneralIOC.P16*/HplMsp430GeneralIORenP__6__IO__selectModuleFunc(void );

static inline void /*HplMsp430GeneralIOC.P16*/HplMsp430GeneralIORenP__6__IO__selectIOFunc(void );
#line 48
static inline void /*HplMsp430GeneralIOC.P17*/HplMsp430GeneralIORenP__7__IO__set(void );






static inline void /*HplMsp430GeneralIOC.P17*/HplMsp430GeneralIORenP__7__IO__makeOutput(void );
#line 53
static inline void /*HplMsp430GeneralIOC.P20*/HplMsp430GeneralIORenP__8__IO__makeInput(void );
#line 53
static inline void /*HplMsp430GeneralIOC.P21*/HplMsp430GeneralIORenP__9__IO__makeInput(void );





static inline void /*HplMsp430GeneralIOC.P21*/HplMsp430GeneralIORenP__9__IO__selectIOFunc(void );
#line 53
static inline void /*HplMsp430GeneralIOC.P22*/HplMsp430GeneralIORenP__10__IO__makeInput(void );
#line 48
static inline void /*HplMsp430GeneralIOC.P23*/HplMsp430GeneralIORenP__11__IO__set(void );
static inline void /*HplMsp430GeneralIOC.P23*/HplMsp430GeneralIORenP__11__IO__clr(void );





static inline void /*HplMsp430GeneralIOC.P23*/HplMsp430GeneralIORenP__11__IO__makeOutput(void );
#line 48
static inline void /*HplMsp430GeneralIOC.P24*/HplMsp430GeneralIORenP__12__IO__set(void );
static void /*HplMsp430GeneralIOC.P24*/HplMsp430GeneralIORenP__12__IO__clr(void );





static inline void /*HplMsp430GeneralIOC.P24*/HplMsp430GeneralIORenP__12__IO__makeOutput(void );
#line 48
static inline void /*HplMsp430GeneralIOC.P33*/HplMsp430GeneralIORenP__19__IO__set(void );






static inline void /*HplMsp430GeneralIOC.P33*/HplMsp430GeneralIORenP__19__IO__makeOutput(void );
#line 49
static inline void /*HplMsp430GeneralIOC.P34*/HplMsp430GeneralIORenP__20__IO__clr(void );





static inline void /*HplMsp430GeneralIOC.P35*/HplMsp430GeneralIORenP__21__IO__makeOutput(void );
#line 49
static inline void /*HplMsp430GeneralIOC.P36*/HplMsp430GeneralIORenP__22__IO__clr(void );





static inline void /*HplMsp430GeneralIOC.P36*/HplMsp430GeneralIORenP__22__IO__makeOutput(void );
#line 48
static void /*HplMsp430GeneralIOC.P37*/HplMsp430GeneralIORenP__23__IO__set(void );
static void /*HplMsp430GeneralIOC.P37*/HplMsp430GeneralIORenP__23__IO__clr(void );





static inline void /*HplMsp430GeneralIOC.P37*/HplMsp430GeneralIORenP__23__IO__makeOutput(void );
# 50 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenDsP.nc"
static inline void /*HplMsp430GeneralIOC.PJ0*/HplMsp430GeneralIORenDsP__0__IO__clr(void );





static inline void /*HplMsp430GeneralIOC.PJ0*/HplMsp430GeneralIORenDsP__0__IO__makeOutput(void );
#line 50
static inline void /*HplMsp430GeneralIOC.PJ2*/HplMsp430GeneralIORenDsP__2__IO__clr(void );





static inline void /*HplMsp430GeneralIOC.PJ2*/HplMsp430GeneralIORenDsP__2__IO__makeOutput(void );
# 90 "/opt/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
static bool /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__ArbiterInfo__inUse(void );
# 49 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Interrupts__interrupted(
# 53 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
uint8_t arg_0x406d6010, 
# 49 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
uint8_t iv);
# 90 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__getStat(void );

static inline uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__getRxbuf(void );


static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__setTxbuf(uint8_t v);
#line 110
static inline uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__getIe(void );
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__setIe(uint8_t v);


static inline uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__getIv(void );

static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__enterResetMode_(void );




static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__leaveResetMode_(void );




static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__configure(const msp430_usci_config_t *config, 
bool leave_in_reset);
#line 141
static inline uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__currentMode(void );
#line 157
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__RawInterrupts__interrupted(uint8_t iv);






static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Interrupts__default__interrupted(uint8_t mode, uint8_t iv);
# 49 "/opt/tinyos-2.x/tos/system/FcfsResourceQueueC.nc"
enum /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0____nesc_unnamed4338 {
#line 49
  FcfsResourceQueueC__0__NO_ENTRY = 0xFF
};
uint8_t /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__resQ[1U];
uint8_t /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__qHead = /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__NO_ENTRY;
uint8_t /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__qTail = /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__NO_ENTRY;

static inline error_t /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__Init__init(void );




static inline bool /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__FcfsQueue__isEmpty(void );







static inline resource_client_id_t /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__FcfsQueue__dequeue(void );
# 61 "/opt/tinyos-2.x/tos/interfaces/ResourceRequested.nc"
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceRequested__immediateRequested(
# 55 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x40731948);
# 65 "/opt/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__unconfigure(
# 60 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x40730cf8);
# 59 "/opt/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__configure(
# 60 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x40730cf8);
# 53 "/opt/tinyos-2.x/tos/interfaces/ResourceQueue.nc"
static bool /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Queue__isEmpty(void );
#line 70
static resource_client_id_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Queue__dequeue(void );
# 46 "/opt/tinyos-2.x/tos/interfaces/ResourceDefaultOwner.nc"
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__granted(void );
#line 81
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__immediateRequested(void );
# 102 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__granted(
# 54 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x40716e70);
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__grantedTask__postTask(void );
# 75 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
enum /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0____nesc_unnamed4339 {
#line 75
  ArbiterP__0__grantedTask = 9U
};
#line 75
typedef int /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0____nesc_sillytask_grantedTask[/*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__grantedTask];
#line 67
enum /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0____nesc_unnamed4340 {
#line 67
  ArbiterP__0__RES_CONTROLLED, ArbiterP__0__RES_GRANTING, ArbiterP__0__RES_IMM_GRANTING, ArbiterP__0__RES_BUSY
};
#line 68
enum /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0____nesc_unnamed4341 {
#line 68
  ArbiterP__0__default_owner_id = 1U
};
#line 69
enum /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0____nesc_unnamed4342 {
#line 69
  ArbiterP__0__NO_RES = 0xFF
};
uint8_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__state = /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__RES_CONTROLLED;
uint8_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__resId = /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__default_owner_id;
uint8_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__reqResId;
#line 93
static inline error_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__immediateRequest(uint8_t id);
#line 111
static inline error_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__release(uint8_t id);
#line 133
static inline error_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__release(void );
#line 153
static inline bool /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ArbiterInfo__inUse(void );
#line 166
static uint8_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ArbiterInfo__userId(void );
#line 190
static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__grantedTask__runTask(void );
#line 202
static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__default__granted(uint8_t id);



static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceRequested__default__immediateRequested(uint8_t id);

static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__default__granted(void );




static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__default__immediateRequested(void );


static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__default__configure(uint8_t id);

static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__default__unconfigure(uint8_t id);
# 49 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
static void HplMsp430UsciInterruptsA0P__Interrupts__interrupted(uint8_t iv);
# 256 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
static uint8_t HplMsp430UsciInterruptsA0P__Usci__getIv(void );
# 17 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterruptsA0P.nc"
void sig_USCI_A0_VECTOR(void ) __attribute((wakeup)) __attribute((interrupt(0x74)))  ;
# 98 "/opt/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
static uint8_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__ArbiterInfo__userId(void );
# 78 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__URXD__makeInput(void );






static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__URXD__makeOutput(void );
#line 99
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__URXD__selectIOFunc(void );
#line 92
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__URXD__selectModuleFunc(void );
#line 85
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UTXD__makeOutput(void );
#line 99
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UTXD__selectIOFunc(void );
#line 92
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UTXD__selectModuleFunc(void );
# 79 "/opt/tinyos-2.x/tos/interfaces/UartStream.nc"
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__receivedByte(
# 74 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
uint8_t arg_0x40767010, 
# 79 "/opt/tinyos-2.x/tos/interfaces/UartStream.nc"
uint8_t byte);
#line 99
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__receiveDone(
# 74 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
uint8_t arg_0x40767010, 
# 95 "/opt/tinyos-2.x/tos/interfaces/UartStream.nc"
uint8_t * buf, 



uint16_t len, error_t error);
#line 57
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__sendDone(
# 74 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
uint8_t arg_0x40767010, 
# 53 "/opt/tinyos-2.x/tos/interfaces/UartStream.nc"
uint8_t * buf, 



uint16_t len, error_t error);
# 44 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciConfigure.nc"
static const msp430_usci_config_t */*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Msp430UsciConfigure__getConfiguration(
# 86 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
uint8_t arg_0x40778338);
# 42 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciError.nc"
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Msp430UsciError__condition(
# 77 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
uint8_t arg_0x40766bb0, 
# 42 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciError.nc"
unsigned int errors);
# 123 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
static uint8_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__getRxbuf(void );
#line 141
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__setTxbuf(uint8_t v);
#line 111
static uint8_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__getStat(void );
#line 231
static uint8_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__getIe(void );
#line 288
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__leaveResetMode_(void );
#line 273
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__configure(const msp430_usci_config_t *config, 
bool leave_in_reset);
#line 237
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__setIe(uint8_t v);
#line 281
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__enterResetMode_(void );
# 95 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
uint16_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_tx_len;
#line 95
uint16_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_rx_len;
uint8_t * /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_tx_buf;
#line 96
uint8_t * /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_rx_buf;
uint16_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_tx_pos;
#line 97
uint16_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_rx_pos;



static inline bool /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__isBusy(void );









static inline error_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__checkIsOwner(uint8_t client);
#line 134
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__unconfigure_(void );
#line 154
static error_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__configure_(const msp430_usci_config_t *config);
#line 180
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__nextStreamTransmit(uint8_t client);
#line 205
static error_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__send(uint8_t client, uint8_t *buf, uint16_t len);
#line 226
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__default__sendDone(uint8_t client, uint8_t *buf, uint16_t len, error_t error);
#line 267
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__default__receivedByte(uint8_t client, uint8_t byte);
#line 289
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__default__receiveDone(uint8_t client, uint8_t *buf, uint16_t len, error_t error);
#line 311
enum /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0____nesc_unnamed4343 {





  Msp430UsciUartP__0__ByteTimesPerMillisecond = 5, 






  Msp430UsciUartP__0__ByteTimeScaleFactor = 1
};
#line 354
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Interrupts__interrupted(uint8_t iv);
#line 388
static inline const msp430_usci_config_t *
/*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Msp430UsciConfigure__default__getConfiguration(uint8_t client);




static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__ResourceConfigure__configure(uint8_t client);




static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__ResourceConfigure__unconfigure(uint8_t client);




static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Msp430UsciError__default__condition(uint8_t client, unsigned int errors);
# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void Msp430TimerCommonP__VectorTimer0_A1__fired(void );
#line 39
static void Msp430TimerCommonP__VectorTimer1_A1__fired(void );
#line 39
static void Msp430TimerCommonP__VectorTimer0_A0__fired(void );
#line 39
static void Msp430TimerCommonP__VectorTimer1_A0__fired(void );
# 30 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430TimerCommonP.nc"
void sig_TIMER0_A0_VECTOR(void ) __attribute((wakeup)) __attribute((interrupt(0x6e)))  ;
void sig_TIMER0_A1_VECTOR(void ) __attribute((wakeup)) __attribute((interrupt(0x6c)))  ;








void sig_TIMER1_A0_VECTOR(void ) __attribute((wakeup)) __attribute((interrupt(0x66)))  ;
void sig_TIMER1_A1_VECTOR(void ) __attribute((wakeup)) __attribute((interrupt(0x64)))  ;
# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Event__fired(
# 51 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
uint8_t arg_0x4080e458);
# 48 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Timer__overflow(void );
# 62 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static inline uint16_t /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Timer__get(void );
#line 81
static inline bool /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Timer__isOverflowPending(void );
#line 126
static inline void /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__VectorTimerX0__fired(void );




static inline void /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__VectorTimerX1__fired(void );





static inline void /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Overflow__fired(void );








static void /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Event__default__fired(uint8_t n);
# 86 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Capture__captured(uint16_t time);
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Compare__fired(void );
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static uint16_t /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Timer__get(void );
# 55 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
typedef msp430_compare_control_t /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__cc_t;


static inline /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__cc_t /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__int2CC(uint16_t x)  ;
#line 85
static inline /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__cc_t /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Control__getControl(void );









static inline void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Control__clearPendingInterrupt(void );
#line 130
static inline void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Control__enableEvents(void );




static inline void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Control__disableEvents(void );
#line 150
static inline uint16_t /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Capture__getEvent(void );




static inline void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Compare__setEvent(uint16_t x);









static inline void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Compare__setEventFromNow(uint16_t x);
#line 180
static inline void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Event__fired(void );







static inline void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Capture__default__captured(uint16_t n);







static inline void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Timer__overflow(void );
# 86 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Capture__captured(uint16_t time);
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Compare__fired(void );
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static uint16_t /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Timer__get(void );
# 55 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
typedef msp430_compare_control_t /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__cc_t;


static inline /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__cc_t /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__int2CC(uint16_t x)  ;
#line 85
static inline /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__cc_t /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Control__getControl(void );









static inline void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Control__clearPendingInterrupt(void );
#line 130
static inline void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Control__enableEvents(void );




static inline void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Control__disableEvents(void );
#line 150
static inline uint16_t /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Capture__getEvent(void );




static inline void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Compare__setEvent(uint16_t x);









static inline void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Compare__setEventFromNow(uint16_t x);
#line 180
static inline void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Event__fired(void );







static inline void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Capture__default__captured(uint16_t n);







static inline void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Timer__overflow(void );
# 86 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static void /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Capture__captured(uint16_t time);
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Compare__fired(void );
# 55 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
typedef msp430_compare_control_t /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__cc_t;


static inline /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__cc_t /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__int2CC(uint16_t x)  ;
#line 85
static inline /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__cc_t /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Control__getControl(void );
#line 150
static inline uint16_t /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Capture__getEvent(void );
#line 180
static inline void /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Event__fired(void );







static inline void /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Capture__default__captured(uint16_t n);



static inline void /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Compare__default__fired(void );



static inline void /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Timer__overflow(void );
# 86 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static void /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Capture__captured(uint16_t time);
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Compare__fired(void );
# 55 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
typedef msp430_compare_control_t /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__cc_t;


static inline /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__cc_t /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__int2CC(uint16_t x)  ;
#line 85
static inline /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__cc_t /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Control__getControl(void );
#line 150
static inline uint16_t /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Capture__getEvent(void );
#line 180
static inline void /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Event__fired(void );







static inline void /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Capture__default__captured(uint16_t n);



static inline void /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Compare__default__fired(void );



static inline void /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Timer__overflow(void );
# 86 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static void /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Capture__captured(uint16_t time);
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Compare__fired(void );
# 55 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
typedef msp430_compare_control_t /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__cc_t;


static inline /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__cc_t /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__int2CC(uint16_t x)  ;
#line 85
static inline /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__cc_t /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Control__getControl(void );
#line 150
static inline uint16_t /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Capture__getEvent(void );
#line 180
static inline void /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Event__fired(void );







static inline void /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Capture__default__captured(uint16_t n);



static inline void /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Compare__default__fired(void );



static inline void /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Timer__overflow(void );
# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__Event__fired(
# 51 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
uint8_t arg_0x4080e458);
# 48 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__Timer__overflow(void );
# 126 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static inline void /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__VectorTimerX0__fired(void );




static inline void /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__VectorTimerX1__fired(void );





static inline void /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__Overflow__fired(void );








static inline void /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__Event__default__fired(uint8_t n);
# 86 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static void /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Capture__captured(uint16_t time);
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Compare__fired(void );
# 55 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
typedef msp430_compare_control_t /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__cc_t;


static inline /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__cc_t /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__int2CC(uint16_t x)  ;
#line 85
static inline /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__cc_t /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Control__getControl(void );
#line 150
static inline uint16_t /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Capture__getEvent(void );
#line 180
static void /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Event__fired(void );







static inline void /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Capture__default__captured(uint16_t n);



static inline void /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Compare__default__fired(void );



static inline void /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Timer__overflow(void );
# 86 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static void /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Capture__captured(uint16_t time);
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Compare__fired(void );
# 55 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
typedef msp430_compare_control_t /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__cc_t;


static inline /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__cc_t /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__int2CC(uint16_t x)  ;
#line 85
static inline /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__cc_t /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Control__getControl(void );
#line 150
static inline uint16_t /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Capture__getEvent(void );
#line 180
static void /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Event__fired(void );







static inline void /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Capture__default__captured(uint16_t n);



static inline void /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Compare__default__fired(void );



static inline void /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Timer__overflow(void );
# 86 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static void /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Capture__captured(uint16_t time);
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Compare__fired(void );
# 55 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
typedef msp430_compare_control_t /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__cc_t;


static inline /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__cc_t /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__int2CC(uint16_t x)  ;
#line 85
static inline /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__cc_t /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Control__getControl(void );
#line 150
static inline uint16_t /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Capture__getEvent(void );
#line 180
static void /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Event__fired(void );







static inline void /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Capture__default__captured(uint16_t n);



static inline void /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Compare__default__fired(void );



static inline void /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Timer__overflow(void );
# 41 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Compare__setEvent(uint16_t time);

static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Compare__setEventFromNow(uint16_t delta);
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static uint16_t /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Timer__get(void );
# 78 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__fired(void );
# 57 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430TimerControl__enableEvents(void );
static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430TimerControl__disableEvents(void );
#line 44
static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430TimerControl__clearPendingInterrupt(void );
# 65 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430AlarmC.nc"
static inline void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__stop(void );




static inline void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Compare__fired(void );










static inline void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__startAt(uint16_t t0, uint16_t dt);
#line 114
static inline void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Timer__overflow(void );
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static uint16_t /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__get(void );
static bool /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__isOverflowPending(void );
# 82 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static void /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__overflow(void );
# 49 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430CounterC.nc"
static inline uint16_t /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__get(void );




static inline bool /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__isOverflowPending(void );









static inline void /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__overflow(void );
# 64 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__size_type /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__get(void );






static bool /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__isOverflowPending(void );










static void /*CounterMilli32C.Transform*/TransformCounterC__0__Counter__overflow(void );
# 67 "/opt/tinyos-2.x/tos/lib/timer/TransformCounterC.nc"
/*CounterMilli32C.Transform*/TransformCounterC__0__upper_count_type /*CounterMilli32C.Transform*/TransformCounterC__0__m_upper;

enum /*CounterMilli32C.Transform*/TransformCounterC__0____nesc_unnamed4344 {

  TransformCounterC__0__LOW_SHIFT_RIGHT = 5, 
  TransformCounterC__0__HIGH_SHIFT_LEFT = 8 * sizeof(/*CounterMilli32C.Transform*/TransformCounterC__0__from_size_type ) - /*CounterMilli32C.Transform*/TransformCounterC__0__LOW_SHIFT_RIGHT, 
  TransformCounterC__0__NUM_UPPER_BITS = 8 * sizeof(/*CounterMilli32C.Transform*/TransformCounterC__0__to_size_type ) - 8 * sizeof(/*CounterMilli32C.Transform*/TransformCounterC__0__from_size_type ) + 5, 



  TransformCounterC__0__OVERFLOW_MASK = /*CounterMilli32C.Transform*/TransformCounterC__0__NUM_UPPER_BITS ? ((/*CounterMilli32C.Transform*/TransformCounterC__0__upper_count_type )2 << (/*CounterMilli32C.Transform*/TransformCounterC__0__NUM_UPPER_BITS - 1)) - 1 : 0
};

static /*CounterMilli32C.Transform*/TransformCounterC__0__to_size_type /*CounterMilli32C.Transform*/TransformCounterC__0__Counter__get(void );
#line 133
static inline void /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__overflow(void );
# 78 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__fired(void );
#line 103
static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__startAt(/*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__size_type t0, /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__size_type dt);
#line 73
static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__stop(void );
# 64 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
static /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Counter__size_type /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Counter__get(void );
# 77 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
/*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__m_t0;
/*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__m_dt;

enum /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0____nesc_unnamed4345 {

  TransformAlarmC__0__MAX_DELAY_LOG2 = 8 * sizeof(/*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__from_size_type ) - 1 - 5, 
  TransformAlarmC__0__MAX_DELAY = (/*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type )1 << /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__MAX_DELAY_LOG2
};

static inline /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__getNow(void );




static inline /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__getAlarm(void );










static inline void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__stop(void );




static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__set_alarm(void );
#line 147
static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__startAt(/*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type t0, /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type dt);
#line 162
static inline void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__fired(void );
#line 177
static inline void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Counter__overflow(void );
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__postTask(void );
# 109 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__getNow(void );
#line 103
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__startAt(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type t0, /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type dt);
#line 116
static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__getAlarm(void );
#line 73
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__stop(void );
# 83 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__fired(void );
# 74 "/opt/tinyos-2.x/tos/lib/timer/AlarmToTimerC.nc"
enum /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0____nesc_unnamed4346 {
#line 74
  AlarmToTimerC__0__fired = 10U
};
#line 74
typedef int /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0____nesc_sillytask_fired[/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired];
#line 55
uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__m_dt;
bool /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__m_oneshot;

static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__start(uint32_t t0, uint32_t dt, bool oneshot);
#line 71
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__stop(void );


static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__runTask(void );






static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__fired(void );
#line 93
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__startOneShotAt(uint32_t t0, uint32_t dt);


static inline uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__getNow(void );
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__postTask(void );
# 136 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
static uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__getNow(void );
#line 129
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__startOneShotAt(uint32_t t0, uint32_t dt);
#line 78
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__stop(void );




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__fired(
# 48 "/opt/tinyos-2.x/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x4090a9f0);
#line 71
enum /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0____nesc_unnamed4347 {
#line 71
  VirtualizeTimerC__0__updateFromTimer = 11U
};
#line 71
typedef int /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0____nesc_sillytask_updateFromTimer[/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer];
#line 53
enum /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0____nesc_unnamed4348 {

  VirtualizeTimerC__0__NUM_TIMERS = 0U, 
  VirtualizeTimerC__0__END_OF_LIST = 255
};








#line 59
typedef struct /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0____nesc_unnamed4349 {

  uint32_t t0;
  uint32_t dt;
  bool isoneshot : 1;
  bool isrunning : 1;
  bool _reserved : 6;
} /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer_t;

/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__m_timers[/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__NUM_TIMERS];




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__fireTimers(uint32_t now);
#line 100
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__runTask(void );
#line 139
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__fired(void );
#line 204
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__default__fired(uint8_t num);
# 58 "/opt/tinyos-2.x/tos/lib/timer/CounterToLocalTimeC.nc"
static inline void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__Counter__overflow(void );
# 90 "/opt/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
static bool /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__ArbiterInfo__inUse(void );
# 49 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
static void /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Interrupts__interrupted(
# 53 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
uint8_t arg_0x406d6010, 
# 49 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
uint8_t iv);
# 92 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline uint8_t /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__getRxbuf(void );


static inline void /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__setTxbuf(uint8_t v);
#line 110
static inline uint8_t /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__getIe(void );
static inline void /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__setIe(uint8_t v);


static inline uint8_t /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__getIv(void );
#line 141
static inline uint8_t /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__currentMode(void );
#line 157
static inline void /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__RawInterrupts__interrupted(uint8_t iv);






static inline void /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Interrupts__default__interrupted(uint8_t mode, uint8_t iv);
# 49 "/opt/tinyos-2.x/tos/system/FcfsResourceQueueC.nc"
enum /*Msp430UsciB0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__1____nesc_unnamed4350 {
#line 49
  FcfsResourceQueueC__1__NO_ENTRY = 0xFF
};
uint8_t /*Msp430UsciB0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__1__resQ[0U];



static inline error_t /*Msp430UsciB0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__1__Init__init(void );
# 59 "/opt/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
static void /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__ResourceConfigure__configure(
# 60 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x40730cf8);
# 102 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
static void /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__Resource__granted(
# 54 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x40716e70);
#line 75
enum /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1____nesc_unnamed4351 {
#line 75
  ArbiterP__1__grantedTask = 12U
};
#line 75
typedef int /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1____nesc_sillytask_grantedTask[/*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__grantedTask];
#line 67
enum /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1____nesc_unnamed4352 {
#line 67
  ArbiterP__1__RES_CONTROLLED, ArbiterP__1__RES_GRANTING, ArbiterP__1__RES_IMM_GRANTING, ArbiterP__1__RES_BUSY
};
#line 68
enum /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1____nesc_unnamed4353 {
#line 68
  ArbiterP__1__default_owner_id = 0U
};
#line 69
enum /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1____nesc_unnamed4354 {
#line 69
  ArbiterP__1__NO_RES = 0xFF
};
uint8_t /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__state = /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__RES_CONTROLLED;
uint8_t /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__resId = /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__default_owner_id;
uint8_t /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__reqResId;
#line 153
static bool /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__ArbiterInfo__inUse(void );
#line 166
static inline uint8_t /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__ArbiterInfo__userId(void );
#line 190
static inline void /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__grantedTask__runTask(void );
#line 202
static inline void /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__Resource__default__granted(uint8_t id);
#line 216
static inline void /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__ResourceConfigure__default__configure(uint8_t id);
# 49 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
static void HplMsp430UsciInterruptsB0P__Interrupts__interrupted(uint8_t iv);
# 256 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
static uint8_t HplMsp430UsciInterruptsB0P__Usci__getIv(void );
# 19 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterruptsB0P.nc"
void sig_USCI_B0_VECTOR(void ) __attribute((wakeup)) __attribute((interrupt(0x72)))  ;
# 90 "/opt/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
static bool /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__ArbiterInfo__inUse(void );







static uint8_t /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__ArbiterInfo__userId(void );
# 82 "/opt/tinyos-2.x/tos/interfaces/SpiPacket.nc"
static void /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__SpiPacket__sendDone(
# 41 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/usci/Msp430UsciSpiP.nc"
uint8_t arg_0x40968278, 
# 75 "/opt/tinyos-2.x/tos/interfaces/SpiPacket.nc"
uint8_t * txBuf, 
uint8_t * rxBuf, 





uint16_t len, 
error_t error);
# 123 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
static uint8_t /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__Usci__getRxbuf(void );
#line 141
static void /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__Usci__setTxbuf(uint8_t v);
#line 231
static uint8_t /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__Usci__getIe(void );





static void /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__Usci__setIe(uint8_t v);
# 62 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/usci/Msp430UsciSpiP.nc"
uint16_t /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__m_len;
uint8_t * /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__m_tx_buf;
#line 63
uint8_t * /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__m_rx_buf;
uint16_t /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__m_pos;
#line 200
static inline void /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__SpiPacket__default__sendDone(uint8_t client, uint8_t *txBuf, uint8_t *rxBuf, uint16_t len, error_t error);

static inline void /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__Interrupts__interrupted(uint8_t iv);
# 16 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/pmm/Msp430PmmP.nc"
static inline error_t Msp430PmmP__Init__init(void );
#line 31
static inline void Msp430PmmP__Pmm__setVoltage(uint8_t level);
# 60 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430XV2ClockControl.nc"
static void Msp430XV2ClockP__Msp430XV2ClockControl__configureTimers(void );
#line 54
static void Msp430XV2ClockP__Msp430XV2ClockControl__configureUnifiedClockSystem(int dco_config);
#line 94
static void Msp430XV2ClockP__Msp430XV2ClockControl__startMicroTimer(void );
#line 69
static void Msp430XV2ClockP__Msp430XV2ClockControl__start32khzTimer(void );
# 71 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430XV2ClockP.nc"
static inline error_t Msp430XV2ClockP__Init__init(void );
# 54 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430XV2ClockControlP.nc"
static inline void Msp430XV2ClockControlP__Msp430XV2ClockControl__configureUnifiedClockSystem(int dco_config);
#line 171
static inline void Msp430XV2ClockControlP__Msp430XV2ClockControl__configureTimers(void );









static inline void Msp430XV2ClockControlP__Msp430XV2ClockControl__start32khzTimer(void );
#line 196
static inline void Msp430XV2ClockControlP__Msp430XV2ClockControl__startMicroTimer(void );
#line 237
enum Msp430XV2ClockControlP____nesc_unnamed4355 {


  Msp430XV2ClockControlP__MinimumFLLActiveDuration_refclk = 3
};


bool Msp430XV2ClockControlP__inhibitUCS7_;
#line 258
uint16_t Msp430XV2ClockControlP__fllRestart_refclk;

static inline mcu_power_t Msp430XV2ClockControlP__McuPowerOverride__lowestState(void );
#line 280
static inline void Msp430XV2ClockControlP__McuSleepEvents__preSleep(mcu_power_t sleep_mode);

static inline void Msp430XV2ClockControlP__McuSleepEvents__postSleep(mcu_power_t sleep_mode);
# 62 "/opt/tinyos-2.x/tos/interfaces/McuPowerOverride.nc"
static mcu_power_t McuSleepP__McuPowerOverride__lowestState(void );
# 55 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/lpm/McuSleepEvents.nc"
static void McuSleepP__McuSleepEvents__preSleep(mcu_power_t sleep_mode);





static void McuSleepP__McuSleepEvents__postSleep(mcu_power_t sleep_mode);
# 96 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/lpm/McuSleepP.nc"
const uint16_t McuSleepP__msp430PowerBits[MSP430_POWER_LPM4 + 1] = { 
0, 
0x0010, 
0x0040 + 0x0010, 
0x0080 + 0x0010, 
0x0080 + 0x0040 + 0x0010, 
0x0080 + 0x0040 + 0x0020 + 0x0010 };


static inline void McuSleepP__McuSleep__sleep(void );
# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void PlatformOneWireInitP__OneWireIO__makeOutput(void );
#line 48
static void PlatformOneWireInitP__OneWireIO__set(void );
# 53 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/onewire/PlatformOneWireInitP.nc"
static inline error_t PlatformOneWireInitP__Init__init(void );
# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void /*PlatformApds9007C.Msp430GpioC*/Msp430GpioC__0__HplGeneralIO__makeOutput(void );
#line 48
static void /*PlatformApds9007C.Msp430GpioC*/Msp430GpioC__0__HplGeneralIO__set(void );
# 48 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformApds9007C.Msp430GpioC*/Msp430GpioC__0__GeneralIO__set(void );





static inline void /*PlatformApds9007C.Msp430GpioC*/Msp430GpioC__0__GeneralIO__makeOutput(void );
# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void Apds9007InitP__ShutdownPin__makeOutput(void );
#line 40
static void Apds9007InitP__ShutdownPin__set(void );
# 5 "/opt/tinyos-2.x/tos/chips/apds9007/Apds9007InitP.nc"
static inline error_t Apds9007InitP__Init__init(void );
# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void PlatformFlashInitP__CsnIO__makeOutput(void );
#line 48
static void PlatformFlashInitP__CsnIO__set(void );
# 53 "/opt/tinyos-2.x/tos/platforms/surf/hardware/flash/PlatformFlashInitP.nc"
static inline error_t PlatformFlashInitP__Init__init(void );
# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void NoCC1190P__LNA_ENPin__makeOutput(void );
#line 46
static void NoCC1190P__HGMPin__makeOutput(void );
#line 41
static void NoCC1190P__HGMPin__clr(void );




static void NoCC1190P__PowerPin__makeOutput(void );
#line 41
static void NoCC1190P__PowerPin__clr(void );
#line 41
static void NoCC1190P__PA_ENPin__clr(void );
# 10 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/cc1190/NoCC1190P.nc"
static inline error_t NoCC1190P__Init__init(void );
# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void /*PlatformCC1190C.HGMGpio*/Msp430GpioC__1__HplGeneralIO__makeOutput(void );
#line 53
static void /*PlatformCC1190C.HGMGpio*/Msp430GpioC__1__HplGeneralIO__clr(void );
# 49 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformCC1190C.HGMGpio*/Msp430GpioC__1__GeneralIO__clr(void );




static inline void /*PlatformCC1190C.HGMGpio*/Msp430GpioC__1__GeneralIO__makeOutput(void );
# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void /*PlatformCC1190C.LNA_ENGpio*/Msp430GpioC__2__HplGeneralIO__makeOutput(void );
# 54 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformCC1190C.LNA_ENGpio*/Msp430GpioC__2__GeneralIO__makeOutput(void );
# 53 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void /*PlatformCC1190C.PA_ENGpio*/Msp430GpioC__3__HplGeneralIO__clr(void );
# 49 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformCC1190C.PA_ENGpio*/Msp430GpioC__3__GeneralIO__clr(void );
# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void /*PlatformCC1190C.PowerGpio*/Msp430GpioC__4__HplGeneralIO__makeOutput(void );
#line 53
static void /*PlatformCC1190C.PowerGpio*/Msp430GpioC__4__HplGeneralIO__clr(void );
# 49 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformCC1190C.PowerGpio*/Msp430GpioC__4__GeneralIO__clr(void );




static inline void /*PlatformCC1190C.PowerGpio*/Msp430GpioC__4__GeneralIO__makeOutput(void );
# 113 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static void PlatformBusPowerP__SplitControl__startDone(error_t error);
#line 138
static void PlatformBusPowerP__SplitControl__stopDone(error_t error);
# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void PlatformBusPowerP__EnablePin__makeOutput(void );
#line 40
static void PlatformBusPowerP__EnablePin__set(void );
static void PlatformBusPowerP__EnablePin__clr(void );
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t PlatformBusPowerP__stopDoneTask__postTask(void );
#line 67
static error_t PlatformBusPowerP__startDoneTask__postTask(void );
# 13 "/opt/tinyos-2.x/tos/platforms/bacon/PlatformBusPowerP.nc"
enum PlatformBusPowerP____nesc_unnamed4356 {
#line 13
  PlatformBusPowerP__startDoneTask = 13U
};
#line 13
typedef int PlatformBusPowerP____nesc_sillytask_startDoneTask[PlatformBusPowerP__startDoneTask];


enum PlatformBusPowerP____nesc_unnamed4357 {
#line 16
  PlatformBusPowerP__stopDoneTask = 14U
};
#line 16
typedef int PlatformBusPowerP____nesc_sillytask_stopDoneTask[PlatformBusPowerP__stopDoneTask];
#line 6
bool PlatformBusPowerP__on = FALSE;
static inline error_t PlatformBusPowerP__Init__init(void );





static inline void PlatformBusPowerP__startDoneTask__runTask(void );


static inline void PlatformBusPowerP__stopDoneTask__runTask(void );



static inline error_t PlatformBusPowerP__SplitControl__start(void );










static inline error_t PlatformBusPowerP__SplitControl__stop(void );
# 113 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static void BusPowerC__SplitControl__startDone(
# 4 "/opt/tinyos-2.x/tos/lib/busPower/BusPowerC.nc"
uint8_t arg_0x40a30e78, 
# 113 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
error_t error);
#line 104
static error_t BusPowerC__SubSplitControl__start(void );
#line 130
static error_t BusPowerC__SubSplitControl__stop(void );
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t BusPowerC__clearStartFlags__postTask(void );
#line 67
static error_t BusPowerC__clearStopFlags__postTask(void );
# 27 "/opt/tinyos-2.x/tos/lib/busPower/BusPowerC.nc"
enum BusPowerC____nesc_unnamed4358 {
#line 27
  BusPowerC__clearStartFlags = 15U
};
#line 27
typedef int BusPowerC____nesc_sillytask_clearStartFlags[BusPowerC__clearStartFlags];









enum BusPowerC____nesc_unnamed4359 {
#line 37
  BusPowerC__subStartTask = 16U
};
#line 37
typedef int BusPowerC____nesc_sillytask_subStartTask[BusPowerC__subStartTask];
#line 61
enum BusPowerC____nesc_unnamed4360 {
#line 61
  BusPowerC__clearStopFlags = 17U
};
#line 61
typedef int BusPowerC____nesc_sillytask_clearStopFlags[BusPowerC__clearStopFlags];








enum BusPowerC____nesc_unnamed4361 {
#line 70
  BusPowerC__subStopTask = 18U
};
#line 70
typedef int BusPowerC____nesc_sillytask_subStopTask[BusPowerC__subStopTask];
#line 9
enum BusPowerC____nesc_unnamed4362 {
  BusPowerC__FLAG_STOPPED = 0, 
  BusPowerC__FLAG_PENDING_START, 
  BusPowerC__FLAG_PENDING_STOP, 
  BusPowerC__FLAG_STARTED
};

enum BusPowerC____nesc_unnamed4363 {
  BusPowerC__S_OFF, 
  BusPowerC__S_STARTING, 
  BusPowerC__S_STOPPING, 
  BusPowerC__S_ON
};


uint8_t BusPowerC__clientFlags[0U];
uint8_t BusPowerC__state = BusPowerC__S_OFF;

static inline void BusPowerC__clearStartFlags__runTask(void );









static inline void BusPowerC__subStartTask__runTask(void );
#line 61
static inline void BusPowerC__clearStopFlags__runTask(void );








static inline void BusPowerC__subStopTask__runTask(void );
#line 93
static inline void BusPowerC__SubSplitControl__startDone(error_t err);




static inline void BusPowerC__SubSplitControl__stopDone(error_t err);




static inline void BusPowerC__SplitControl__default__startDone(uint8_t id, error_t err);
# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__HplGeneralIO__makeOutput(void );
#line 48
static void /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__HplGeneralIO__set(void );




static void /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__HplGeneralIO__clr(void );
# 48 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__GeneralIO__set(void );
static inline void /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__GeneralIO__clr(void );




static inline void /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__GeneralIO__makeOutput(void );
# 113 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static void PlatformBatteryVoltageP__SplitControl__startDone(error_t error);
#line 138
static void PlatformBatteryVoltageP__SplitControl__stopDone(error_t error);
# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void PlatformBatteryVoltageP__EnablePin__makeOutput(void );
#line 41
static void PlatformBatteryVoltageP__EnablePin__clr(void );
# 33 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/batteryVoltage/PlatformBatteryVoltageP.nc"
enum PlatformBatteryVoltageP____nesc_unnamed4364 {
#line 33
  PlatformBatteryVoltageP__startDoneTask = 19U
};
#line 33
typedef int PlatformBatteryVoltageP____nesc_sillytask_startDoneTask[PlatformBatteryVoltageP__startDoneTask];


enum PlatformBatteryVoltageP____nesc_unnamed4365 {
#line 36
  PlatformBatteryVoltageP__stopDoneTask = 20U
};
#line 36
typedef int PlatformBatteryVoltageP____nesc_sillytask_stopDoneTask[PlatformBatteryVoltageP__stopDoneTask];
#line 27
static inline error_t PlatformBatteryVoltageP__Init__init(void );





static inline void PlatformBatteryVoltageP__startDoneTask__runTask(void );


static inline void PlatformBatteryVoltageP__stopDoneTask__runTask(void );
#line 62
static inline void PlatformBatteryVoltageP__SplitControl__default__startDone(error_t err);
static inline void PlatformBatteryVoltageP__SplitControl__default__stopDone(error_t err);
# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void /*PlatformBatteryVoltageC.Msp430GpioC*/Msp430GpioC__6__HplGeneralIO__makeOutput(void );
#line 53
static void /*PlatformBatteryVoltageC.Msp430GpioC*/Msp430GpioC__6__HplGeneralIO__clr(void );
# 49 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformBatteryVoltageC.Msp430GpioC*/Msp430GpioC__6__GeneralIO__clr(void );




static inline void /*PlatformBatteryVoltageC.Msp430GpioC*/Msp430GpioC__6__GeneralIO__makeOutput(void );
# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t RealMainP__SoftwareInit__init(void );
# 60 "/opt/tinyos-2.x/tos/interfaces/Boot.nc"
static void RealMainP__Boot__booted(void );
# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
static error_t RealMainP__PlatformInit__init(void );
# 57 "/opt/tinyos-2.x/tos/interfaces/Scheduler.nc"
static void RealMainP__Scheduler__init(void );
#line 72
static void RealMainP__Scheduler__taskLoop(void );
#line 65
static bool RealMainP__Scheduler__runNextTask(void );
# 63 "/opt/tinyos-2.x/tos/system/RealMainP.nc"
int main(void )   ;
# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void SchedulerBasicP__TaskBasic__runTask(
# 56 "/opt/tinyos-2.x/tos/system/SchedulerBasicP.nc"
uint8_t arg_0x40467088);
# 76 "/opt/tinyos-2.x/tos/interfaces/McuSleep.nc"
static void SchedulerBasicP__McuSleep__sleep(void );
# 61 "/opt/tinyos-2.x/tos/system/SchedulerBasicP.nc"
enum SchedulerBasicP____nesc_unnamed4366 {

  SchedulerBasicP__NUM_TASKS = 38U, 
  SchedulerBasicP__NO_TASK = 255
};

uint8_t SchedulerBasicP__m_head;
uint8_t SchedulerBasicP__m_tail;
uint8_t SchedulerBasicP__m_next[SchedulerBasicP__NUM_TASKS];








static __inline uint8_t SchedulerBasicP__popTask(void );
#line 97
static inline bool SchedulerBasicP__isWaiting(uint8_t id);




static inline bool SchedulerBasicP__pushTask(uint8_t id);
#line 124
static inline void SchedulerBasicP__Scheduler__init(void );









static bool SchedulerBasicP__Scheduler__runNextTask(void );
#line 149
static inline void SchedulerBasicP__Scheduler__taskLoop(void );
#line 170
static error_t SchedulerBasicP__TaskBasic__postTask(uint8_t id);




static void SchedulerBasicP__TaskBasic__default__runTask(uint8_t id);
# 110 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static void /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__AMSend__sendDone(
#line 103
message_t * msg, 






error_t error);
# 75 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static error_t /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__Send__send(
#line 67
message_t * msg, 







uint8_t len);
#line 125
static 
#line 123
void * 

/*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__Send__getPayload(
#line 122
message_t * msg, 


uint8_t len);
# 103 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
static void /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__AMPacket__setDestination(
#line 99
message_t * amsg, 



am_addr_t addr);
#line 162
static void /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__AMPacket__setType(
#line 158
message_t * amsg, 



am_id_t t);
# 53 "/opt/tinyos-2.x/tos/system/AMQueueEntryP.nc"
static inline error_t /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__AMSend__send(am_addr_t dest, 
message_t *msg, 
uint8_t len);









static inline void /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__Send__sendDone(message_t *m, error_t err);







static inline void */*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__AMSend__getPayload(message_t *m, uint8_t len);
# 80 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__send(
# 48 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
am_id_t arg_0x40ab51b8, 
# 80 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
#line 135
static 
#line 133
void * 

/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__getPayload(
# 48 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
am_id_t arg_0x40ab51b8, 
# 132 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t * msg, 


uint8_t len);
# 100 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__sendDone(
# 46 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40ab77a8, 
# 96 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 78 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
static uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Packet__payloadLength(
#line 74
message_t * msg);
#line 94
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Packet__setPayloadLength(
#line 90
message_t * msg, 



uint8_t len);
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask__postTask(void );
# 78 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
static am_addr_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMPacket__destination(
#line 74
message_t * amsg);
#line 147
static am_id_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMPacket__type(
#line 143
message_t * amsg);
# 126 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
enum /*AMQueueP.AMQueueImplP*/AMQueueImplP__0____nesc_unnamed4367 {
#line 126
  AMQueueImplP__0__CancelTask = 21U
};
#line 126
typedef int /*AMQueueP.AMQueueImplP*/AMQueueImplP__0____nesc_sillytask_CancelTask[/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__CancelTask];
#line 169
enum /*AMQueueP.AMQueueImplP*/AMQueueImplP__0____nesc_unnamed4368 {
#line 169
  AMQueueImplP__0__errorTask = 22U
};
#line 169
typedef int /*AMQueueP.AMQueueImplP*/AMQueueImplP__0____nesc_sillytask_errorTask[/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask];
#line 57
#line 55
typedef struct /*AMQueueP.AMQueueImplP*/AMQueueImplP__0____nesc_unnamed4369 {
  message_t * msg;
} /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue_entry_t;

uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current = 1;
/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue_entry_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[1];
uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__cancelMask[1 / 8 + 1];

static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__tryToSend(void );

static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__nextPacket(void );
#line 90
static inline error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__send(uint8_t clientId, message_t *msg, 
uint8_t len);
#line 126
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__CancelTask__runTask(void );
#line 163
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__sendDone(uint8_t last, message_t * msg, error_t err);





static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask__runTask(void );




static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__tryToSend(void );
#line 189
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__sendDone(am_id_t id, message_t *msg, error_t err);
#line 211
static inline void */*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__getPayload(uint8_t id, message_t *m, uint8_t len);



static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__default__sendDone(uint8_t id, message_t *msg, error_t err);
# 39 "/opt/tinyos-2.x/tos/interfaces/Ieee154Packet.nc"
static ieee154_saddr_t Rf1aAMPacketP__Ieee154Packet__destination(message_t *msg);





static void Rf1aAMPacketP__Ieee154Packet__setSource(message_t *msg, ieee154_saddr_t addr);
#line 43
static void Rf1aAMPacketP__Ieee154Packet__setDestination(message_t *msg, ieee154_saddr_t addr);
# 65 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
static void Rf1aAMPacketP__SubPacket__clear(
#line 62
message_t * msg);
#line 78
static uint8_t Rf1aAMPacketP__SubPacket__payloadLength(
#line 74
message_t * msg);
#line 126
static 
#line 123
void * 


Rf1aAMPacketP__SubPacket__getPayload(
#line 121
message_t * msg, 




uint8_t len);
#line 94
static void Rf1aAMPacketP__SubPacket__setPayloadLength(
#line 90
message_t * msg, 



uint8_t len);
# 50 "/opt/tinyos-2.x/tos/interfaces/ActiveMessageAddress.nc"
static am_addr_t Rf1aAMPacketP__ActiveMessageAddress__amAddress(void );
# 53 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aAMPacketP.nc"
typedef rf1a_nalp_am_t Rf1aAMPacketP__layer_header_t;


static inline Rf1aAMPacketP__layer_header_t *Rf1aAMPacketP__layerHeader(message_t *msg);

static inline void Rf1aAMPacketP__Packet__clear(message_t *msg);
#line 73
static inline void Rf1aAMPacketP__Packet__setPayloadLength(message_t *msg, uint8_t len);
static inline uint8_t Rf1aAMPacketP__Packet__payloadLength(message_t *msg);
static void *Rf1aAMPacketP__Packet__getPayload(message_t *msg, uint8_t len);

static inline am_addr_t Rf1aAMPacketP__AMPacket__address(void );
static inline am_addr_t Rf1aAMPacketP__AMPacket__destination(message_t *amsg);

static inline void Rf1aAMPacketP__AMPacket__setDestination(message_t *amsg, am_addr_t addr);
static inline void Rf1aAMPacketP__AMPacket__setSource(message_t *amsg, am_addr_t addr);
static inline bool Rf1aAMPacketP__AMPacket__isForMe(message_t *amsg);





static inline am_id_t Rf1aAMPacketP__AMPacket__type(message_t *amsg);





static void Rf1aAMPacketP__AMPacket__setType(message_t *amsg, am_id_t t);
# 52 "/opt/tinyos-2.x/tos/interfaces/Random.nc"
static uint16_t /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Random__rand16(void );
# 51 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/interfaces/Ieee154Address.nc"
static ieee154_panid_t /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Address__panId(void );
# 55 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aIeee154PacketP.nc"
enum /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0____nesc_unnamed4370 {


  Rf1aIeee154PacketP__0__FCF_PRESERVE = ((1 << IEEE154_FCF_SECURITY_ENABLED)
   | (1 << IEEE154_FCF_FRAME_PENDING))
   | (1 << IEEE154_FCF_ACK_REQ), 



  Rf1aIeee154PacketP__0__FCF_FIXED = (((IEEE154_TYPE_DATA << IEEE154_FCF_FRAME_TYPE)
   | (IEEE154_ADDR_SHORT << IEEE154_FCF_DEST_ADDR_MODE))
   | (1 << IEEE154_FCF_INTRAPAN))
   | (IEEE154_ADDR_SHORT << IEEE154_FCF_SRC_ADDR_MODE)
};


uint8_t /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__macDSN;

static inline error_t /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Init__init(void );








typedef rf1a_ieee154_t /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__header_t;


static inline /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__header_t */*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__header(message_t *msg);



typedef rf1a_metadata_t /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__metadata_t;


static inline /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__metadata_t */*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__metadata_(message_t *msg);
static inline const /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__metadata_t */*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__cmetadata_(const message_t *msg);

static inline rf1a_metadata_t */*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Rf1aPacket__metadata(message_t *msg);

static inline void /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Rf1aPacket__configureAsData(message_t *msg);
#line 124
static inline ieee154_saddr_t /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__destination(message_t *msg);

static inline void /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__setDestination(message_t *msg, ieee154_saddr_t addr);
static inline void /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__setSource(message_t *msg, ieee154_saddr_t addr);
#line 146
static inline void /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__setPan(message_t *msg, ieee154_panid_t grp);
static inline ieee154_panid_t /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__localPan(void );

static inline void /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Packet__clear(message_t *msg);





static inline void /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Packet__setPayloadLength(message_t *msg, uint8_t len);
static inline uint8_t /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Packet__payloadLength(message_t *msg);
static inline void */*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Packet__getPayload(message_t *msg, uint8_t len);
# 43 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/system/Ieee154AddressP.nc"
ieee154_saddr_t Ieee154AddressP__short_address = TOS_IEEE154_SHORT_ADDRESS;


ieee154_panid_t Ieee154AddressP__pan_id = TOS_IEEE154_PAN_ID;










static ieee154_saddr_t Ieee154AddressP__Ieee154Address__shortAddress(void );

static inline ieee154_panid_t Ieee154AddressP__Ieee154Address__panId(void );
# 52 "/opt/tinyos-2.x/tos/system/RandomMlcgC.nc"
uint32_t RandomMlcgC__seed;


static inline error_t RandomMlcgC__Init__init(void );
#line 69
static uint32_t RandomMlcgC__Random__rand32(void );
#line 89
static inline uint16_t RandomMlcgC__Random__rand16(void );
# 48 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/interfaces/Ieee154Address.nc"
static ieee154_saddr_t Ieee154AMAddressP__Ieee154Address__shortAddress(void );
# 55 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/system/Ieee154AMAddressP.nc"
static inline am_addr_t Ieee154AMAddressP__ActiveMessageAddress__amAddress(void );
# 137 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIfP.nc"
static inline uint16_t /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__getIn(void );


static inline void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__setIfg(uint16_t v);
static inline uint16_t /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__getIes(void );
static inline void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__setIes(uint16_t v);
static inline uint16_t /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__getIe(void );
static inline void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__setIe(uint16_t v);







static uint8_t /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__strobe(uint8_t instr);
#line 185
static uint8_t /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__readRegister(uint8_t addr);
#line 203
static void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__writeRegister(uint8_t addr, 
uint8_t val);
#line 220
static void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__readBurstRegister(uint8_t addr, 
uint8_t *buf, 
uint8_t len);
#line 245
static void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__writeBurstRegister(uint8_t addr, 
const uint8_t *buf, 
uint8_t len);
#line 272
static uint8_t /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__resetRadioCore(void );









static inline void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__writeSinglePATable(uint8_t value);
# 49 "/opt/tinyos-2.x/tos/system/FcfsResourceQueueC.nc"
enum /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2____nesc_unnamed4371 {
#line 49
  FcfsResourceQueueC__2__NO_ENTRY = 0xFF
};
uint8_t /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__resQ[1U];
uint8_t /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__qHead = /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__NO_ENTRY;
uint8_t /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__qTail = /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__NO_ENTRY;

static inline error_t /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__Init__init(void );




static inline bool /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__FcfsQueue__isEmpty(void );



static inline bool /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__FcfsQueue__isEnqueued(resource_client_id_t id);



static inline resource_client_id_t /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__FcfsQueue__dequeue(void );
#line 82
static inline error_t /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__FcfsQueue__enqueue(resource_client_id_t id);
# 53 "/opt/tinyos-2.x/tos/interfaces/ResourceRequested.nc"
static void /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ResourceRequested__requested(
# 52 "/opt/tinyos-2.x/tos/system/SimpleArbiterP.nc"
uint8_t arg_0x40c3d770);
# 65 "/opt/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
static void /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ResourceConfigure__unconfigure(
# 56 "/opt/tinyos-2.x/tos/system/SimpleArbiterP.nc"
uint8_t arg_0x40c67430);
# 59 "/opt/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
static void /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ResourceConfigure__configure(
# 56 "/opt/tinyos-2.x/tos/system/SimpleArbiterP.nc"
uint8_t arg_0x40c67430);
# 79 "/opt/tinyos-2.x/tos/interfaces/ResourceQueue.nc"
static error_t /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Queue__enqueue(resource_client_id_t id);
#line 53
static bool /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Queue__isEmpty(void );
#line 70
static resource_client_id_t /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Queue__dequeue(void );
# 102 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
static void /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Resource__granted(
# 51 "/opt/tinyos-2.x/tos/system/SimpleArbiterP.nc"
uint8_t arg_0x40c40c68);
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__grantedTask__postTask(void );
# 69 "/opt/tinyos-2.x/tos/system/SimpleArbiterP.nc"
enum /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0____nesc_unnamed4372 {
#line 69
  SimpleArbiterP__0__grantedTask = 23U
};
#line 69
typedef int /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0____nesc_sillytask_grantedTask[/*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__grantedTask];
#line 62
enum /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0____nesc_unnamed4373 {
#line 62
  SimpleArbiterP__0__RES_IDLE = 0, SimpleArbiterP__0__RES_GRANTING = 1, SimpleArbiterP__0__RES_BUSY = 2
};
#line 63
enum /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0____nesc_unnamed4374 {
#line 63
  SimpleArbiterP__0__NO_RES = 0xFF
};
uint8_t /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__state = /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__RES_IDLE;
uint8_t /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__resId = /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__NO_RES;
uint8_t /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__reqResId;



static inline error_t /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Resource__request(uint8_t id);
#line 97
static inline error_t /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Resource__release(uint8_t id);
#line 124
static bool /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ArbiterInfo__inUse(void );
#line 137
static uint8_t /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ArbiterInfo__userId(void );
#line 155
static inline void /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__grantedTask__runTask(void );









static inline void /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Resource__default__granted(uint8_t id);

static inline void /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ResourceRequested__default__requested(uint8_t id);
# 2 "/opt/tinyos-2.x/tos/lib/rf1a-multi/DelayedSendRf1aPhysical.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__DelayedSendRf1aPhysical__sendReady(
# 62 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c72e58);
# 282 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__frameStarted(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8);
# 189 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__receiveStarted(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8, 
# 189 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
unsigned int length);
#line 205
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__receiveDone(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8, 
# 205 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
uint8_t *buffer, 
unsigned int count, 
int result);
#line 289
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__clearChannel(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8);
# 274 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__receiveBufferFilled(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8, 
# 274 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
uint8_t *buffer, 
unsigned int count);
#line 115
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__sendDone(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8, 
# 115 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
int result);
#line 298
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__carrierSense(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8);
# 321 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__released(
# 59 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c74aa8);
# 72 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTransmitFragment.nc"
static const uint8_t */*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aTransmitFragment__transmitData(
# 68 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c6bd70, 
# 72 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTransmitFragment.nc"
unsigned int count);
#line 55
static unsigned int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aTransmitFragment__transmitReadyCount(
# 68 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c6bd70, 
# 55 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTransmitFragment.nc"
unsigned int count);
# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IndicatorPin__makeOutput(void );
#line 40
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IndicatorPin__set(void );
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IndicatorPin__clr(void );
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveData_task__postTask(void );
# 358 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIf.nc"
static uint16_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__getIes(void );
#line 445
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readBurstRegister(uint8_t addr, 
uint8_t *buf, 
uint8_t len);
#line 438
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__writeRegister(uint8_t addr, uint8_t val);
#line 351
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__setIfg(uint16_t v);
#line 424
static uint8_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(uint8_t instr);
#line 370
static uint16_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__getIe(void );
#line 454
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__writeBurstRegister(uint8_t addr, 
const uint8_t *buf, 
uint8_t len);
#line 375
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__setIe(uint16_t v);
#line 334
static uint16_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__getIn(void );
#line 363
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__setIes(uint16_t v);
#line 431
static uint8_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(uint8_t addr);
#line 467
static uint8_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__resetRadioCore(void );
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__sendFragment_task__postTask(void );
# 90 "/opt/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
static bool /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ArbiterInfo__inUse(void );







static uint8_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ArbiterInfo__userId(void );
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t */*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__getConfiguration(
# 67 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c6b300);
# 62 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__preConfigure(
# 67 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c6b300);
# 71 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__postConfigure(
# 67 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c6b300);
# 83 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__postUnconfigure(
# 67 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c6b300);
# 78 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__preUnconfigure(
# 67 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
uint8_t arg_0x40c6b300);
#line 485
enum /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0____nesc_unnamed4375 {
#line 485
  HplMsp430Rf1aP__0__sendFragment_task = 24U
};
#line 485
typedef int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0____nesc_sillytask_sendFragment_task[/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__sendFragment_task];


enum /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0____nesc_unnamed4376 {
#line 488
  HplMsp430Rf1aP__0__receiveData_task = 25U
};
#line 488
typedef int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0____nesc_sillytask_receiveData_task[/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveData_task];
#line 76
enum /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0____nesc_unnamed4377 {

  HplMsp430Rf1aP__0__IFG_rxFifoAboveThreshold = 1 << 4, 

  HplMsp430Rf1aP__0__IFG_txFifoAboveThreshold = 1 << 5, 

  HplMsp430Rf1aP__0__IFG_rxOverflow = 1 << 7, 

  HplMsp430Rf1aP__0__IFG_txUnderflow = 1 << 8, 

  HplMsp430Rf1aP__0__IFG_syncWordEvent = 1 << 9, 

  HplMsp430Rf1aP__0__IFG_clearChannel = 1 << 12, 

  HplMsp430Rf1aP__0__IFG_carrierSense = 1 << 13, 
  HplMsp430Rf1aP__0__IFG_INTERRUPT = (((((/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_rxFifoAboveThreshold | /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_txFifoAboveThreshold)
   | /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_rxOverflow) | /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_txUnderflow)
   | /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_syncWordEvent)
   | /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_clearChannel) | /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_carrierSense, 
  HplMsp430Rf1aP__0__IFG_EDGE_Negative = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_txFifoAboveThreshold, 
  HplMsp430Rf1aP__0__IFG_EDGE_Positive = ((((/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_rxFifoAboveThreshold
   | /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_rxOverflow) | /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_txUnderflow)
   | /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_syncWordEvent)
   | /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_clearChannel) | /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_carrierSense
};

enum /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0____nesc_unnamed4378 {
#line 114
  HplMsp430Rf1aP__0__RADIO_LOOP_LIMIT = 2000
};





enum /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0____nesc_unnamed4379 {
  HplMsp430Rf1aP__0__MRCSM_SLEEP = 0, 
  HplMsp430Rf1aP__0__MRCSM_IDLE = 1, 
  HplMsp430Rf1aP__0__MRCSM_XOFF = 2, 
  HplMsp430Rf1aP__0__MRCSM_VCOON_MC = 3, 
  HplMsp430Rf1aP__0__MRCSM_REGON_MC = 4, 
  HplMsp430Rf1aP__0__MRCSM_MANCAL = 5, 
  HplMsp430Rf1aP__0__MRCSM_VCOON = 6, 
  HplMsp430Rf1aP__0__MRCSM_REGON = 7, 
  HplMsp430Rf1aP__0__MRCSM_STARTCAL = 8, 
  HplMsp430Rf1aP__0__MRCSM_BWBOOST = 9, 
  HplMsp430Rf1aP__0__MRCSM_FS_LOCK = 10, 
  HplMsp430Rf1aP__0__MRCSM_IFADCON = 11, 
  HplMsp430Rf1aP__0__MRCSM_ENDCAL = 12, 
  HplMsp430Rf1aP__0__MRCSM_RX = 13, 
  HplMsp430Rf1aP__0__MRCSM_RX_END = 14, 
  HplMsp430Rf1aP__0__MRCSM_RX_RST = 15, 
  HplMsp430Rf1aP__0__MRCSM_TXRX_SWITCH = 16, 
  HplMsp430Rf1aP__0__MRCSM_RXFIFO_OVERFLOW = 17, 
  HplMsp430Rf1aP__0__MRCSM_FSTXON = 18, 
  HplMsp430Rf1aP__0__MRCSM_TX = 19, 
  HplMsp430Rf1aP__0__MRCSM_TX_END = 20, 
  HplMsp430Rf1aP__0__MRCSM_RXTX_SWITCH = 21, 
  HplMsp430Rf1aP__0__MRCSM_TXFIFO_UNDERFLOW = 22
};










enum /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0____nesc_unnamed4380 {


  HplMsp430Rf1aP__0__RX_S_inactive, 


  HplMsp430Rf1aP__0__RX_S_listening, 




  HplMsp430Rf1aP__0__RX_S_synchronized, 

  HplMsp430Rf1aP__0__RX_S_active
};

uint8_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_state;




uint8_t */*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos;


uint8_t */*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos_end;



uint8_t */*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_start;



bool /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_single_use;



unsigned int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_expected;



unsigned int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_received;




int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_result;




uint8_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_rssi_raw;



uint8_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_lqi_raw;
#line 233
enum /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0____nesc_unnamed4381 {

  HplMsp430Rf1aP__0__TX_S_inactive, 



  HplMsp430Rf1aP__0__TX_S_preparing, 

  HplMsp430Rf1aP__0__TX_S_active, 


  HplMsp430Rf1aP__0__TX_S_flushing
};


uint8_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_state;


int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_result;





uint8_t */*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_pos;



uint8_t */*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_end;





unsigned int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_remain;

enum /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0____nesc_unnamed4382 {

  HplMsp430Rf1aP__0__FIFO_FILL_LIMIT = 63
};





uint8_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_cached_fifothr;










static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__resumeIdleMode_(bool rx_if_enabled);
#line 319
static bool /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__transmitIsInactive_atomic_(void );







static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__configure_(const rf1a_config_t *config);
#line 389
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__unconfigure_(void );







static inline const rf1a_config_t *
/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__getConfiguration(uint8_t client);




static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__preConfigure(uint8_t client);
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__postConfigure(uint8_t client);
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__preUnconfigure(uint8_t client);
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__postUnconfigure(uint8_t client);

static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ResourceConfigure__configure(uint8_t client);










static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ResourceConfigure__unconfigure(uint8_t client);
#line 432
static inline unsigned int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__transmitReadyCount_(uint8_t client, 
unsigned int count);
#line 451
static inline uint8_t */*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__transmitData_(uint8_t client, 
unsigned int count);
#line 479
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__sendFragment_(void );


static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveData_(void );


static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__sendFragment_task__runTask(void );


static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveData_task__runTask(void );


static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__resetAndFlushTxFifo_(void );
#line 511
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__cancelTransmit_(void );
#line 530
static inline uint8_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__spinForValidRssi__(void );
#line 563
bool /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__wrote_data_ds;
uint8_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rc_ds;
int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__result_ds;
bool /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__send_done_ds;
bool /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__need_repost_ds;
uint8_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__client_ds;



static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__sendFragment_(void );
#line 660
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__DelayedSendRf1aPhysical__completeSend(uint8_t clientId);
#line 763
static inline int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__startTransmission_(bool with_cca, 
bool target_fstxon);
#line 834
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__startReception_(void );
#line 850
static inline error_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__send(uint8_t client, uint8_t *buffer, 
unsigned int length);
#line 964
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__sendDone(uint8_t client, int result);
#line 1057
static unsigned int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveCountAvailable_(void );
#line 1074
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__cancelReceive_(void );
#line 1092
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveData_(void );
#line 1276
static inline error_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__setReceiveBuffer(uint8_t client, uint8_t *buffer, 
unsigned int length, 
bool single_use);
#line 1339
static inline unsigned int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aTransmitFragment__default__transmitReadyCount(uint8_t client, unsigned int count);



static inline unsigned int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__defaultTransmitReadyCount(uint8_t client, unsigned int count);






static inline const uint8_t */*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aTransmitFragment__default__transmitData(uint8_t client, unsigned int count);



static inline const uint8_t */*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__defaultTransmitData(uint8_t client, unsigned int count);






static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__rxFifoAvailable(uint8_t client);
#line 1375
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__txFifoAvailable(uint8_t client);
#line 1394
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__rxOverflow(uint8_t client);






static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__txUnderflow(uint8_t client);






static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__syncWordEvent(uint8_t client);




static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__clearChannel(uint8_t client);




static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__carrierSense(uint8_t client);




static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__coreInterrupt(uint8_t client, uint16_t iv);



static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__receiveStarted(uint8_t client, unsigned int length);

static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__receiveDone(uint8_t client, uint8_t *buffer, 
unsigned int count, 
int result);

static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__receiveBufferFilled(uint8_t client, uint8_t *buffer, 
unsigned int count);

static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__frameStarted(uint8_t client);
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__clearChannel(uint8_t client);
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__carrierSense(uint8_t client);

static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__released(uint8_t client);
#line 1502
enum /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0____nesc_unnamed4383 {

  HplMsp430Rf1aP__0__RSSI_offset = 74
};
#line 1540
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysicalMetadata__store(rf1a_metadata_t *metadatap);
#line 1566
static inline 
#line 1565
void 
/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__DelayedSendRf1aPhysical__default__sendReady(uint8_t clientId);
# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__HplGeneralIO__makeOutput(void );
#line 48
static void /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__HplGeneralIO__set(void );




static void /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__HplGeneralIO__clr(void );
# 48 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__GeneralIO__set(void );
static inline void /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__GeneralIO__clr(void );




static inline void /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__GeneralIO__makeOutput(void );
# 23 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
static void HplMsp430Rf1aInterruptP__Rf1aInterrupts__rxOverflow(
# 45 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aInterruptP.nc"
uint8_t arg_0x40d35d58);
# 10 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
static void HplMsp430Rf1aInterruptP__Rf1aInterrupts__rxFifoAvailable(
# 45 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aInterruptP.nc"
uint8_t arg_0x40d35d58);
# 44 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
static void HplMsp430Rf1aInterruptP__Rf1aInterrupts__clearChannel(
# 45 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aInterruptP.nc"
uint8_t arg_0x40d35d58);
# 16 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
static void HplMsp430Rf1aInterruptP__Rf1aInterrupts__txFifoAvailable(
# 45 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aInterruptP.nc"
uint8_t arg_0x40d35d58);
# 29 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
static void HplMsp430Rf1aInterruptP__Rf1aInterrupts__txUnderflow(
# 45 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aInterruptP.nc"
uint8_t arg_0x40d35d58);
# 36 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
static void HplMsp430Rf1aInterruptP__Rf1aInterrupts__syncWordEvent(
# 45 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aInterruptP.nc"
uint8_t arg_0x40d35d58);
# 51 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
static void HplMsp430Rf1aInterruptP__Rf1aInterrupts__carrierSense(
# 45 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aInterruptP.nc"
uint8_t arg_0x40d35d58);
# 54 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
static void HplMsp430Rf1aInterruptP__Rf1aInterrupts__coreInterrupt(
# 45 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aInterruptP.nc"
uint8_t arg_0x40d35d58, 
# 54 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
uint16_t iv);
# 90 "/opt/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
static bool HplMsp430Rf1aInterruptP__ArbiterInfo__inUse(void );







static uint8_t HplMsp430Rf1aInterruptP__ArbiterInfo__userId(void );
# 60 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aInterruptP.nc"
void sig_CC1101_VECTOR(void ) __attribute((wakeup)) __attribute((interrupt(0x6a)))  ;
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static const rf1a_config_t */*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__getConfiguration(
# 4 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
uint8_t arg_0x40d95768);
# 62 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__preConfigure(
# 4 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
uint8_t arg_0x40d95768);
# 71 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__postConfigure(
# 4 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
uint8_t arg_0x40d95768);
# 83 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__postUnconfigure(
# 4 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
uint8_t arg_0x40d95768);
# 78 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
static void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__preUnconfigure(
# 4 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
uint8_t arg_0x40d95768);
# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
static /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubGet__val_t /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubGet__get(
# 5 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
uint8_t arg_0x40d93da8);

uint8_t /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__currentClient = 0;

static inline uint8_t /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aMulti__getNumConfigs(void );



static inline uint8_t /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aMulti__getConfig(void );



static inline error_t /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aMulti__setConfig(uint8_t clientId);
#line 41
static inline uint16_t /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aMulti__getConfigId(void );



static inline const rf1a_config_t */*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__getConfiguration(void );


static inline void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__preConfigure(void );


static inline void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__postConfigure(void );


static inline void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__preUnconfigure(void );


static inline void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__postUnconfigure(void );



static inline const rf1a_config_t */*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__getConfiguration(uint8_t clientId);


static inline uint16_t /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubGet__default__get(uint8_t clientId);
static inline void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__preConfigure(uint8_t clientId);
static inline void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__postConfigure(uint8_t clientId);
static inline void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__preUnconfigure(uint8_t clientId);
static inline void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__postUnconfigure(uint8_t clientId);
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/CUSTOM_HC.nc"
static inline uint16_t CUSTOM_HC__Get__get(void );



rf1a_config_t CUSTOM_HC__this_config = { 
.iocfg2 = 0x2E, 

.iocfg1 = 0x2E, 



.iocfg0 = 0x29, 
.fifothr = 0x47, 

.sync1 = 0xD3, 
.sync0 = 0x91, 




.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x45, 
.addr = 0x00, 



.channr = 0x0A, 

.fsctrl1 = 0x06, 
.fsctrl0 = 0x00, 
.freq2 = 0x22, 
.freq1 = 0xB1, 
.freq0 = 0x3B, 
.mdmcfg4 = 0xC8, 
.mdmcfg3 = 0x93, 
.mdmcfg2 = 0x13, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x34, 

.mcsm2 = 0x07, 




.mcsm1 = 0x3F, 



.mcsm0 = 0x10, 
.foccfg = 0x16, 
.bscfg = 0x6C, 
.agcctrl2 = 0x03, 
.agcctrl1 = 0x40, 
.agcctrl0 = 0x91, 

.worevt1 = 0x80, 




.worevt0 = 0x00, 






.worctrl = 0xf0, 

.frend1 = 0x56, 
.frend0 = 0x10, 
.fscal3 = 0xE9, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *CUSTOM_HC__Rf1aConfigure__getConfiguration(void );


static inline void CUSTOM_HC__Rf1aConfigure__preConfigure(void );
static inline void CUSTOM_HC__Rf1aConfigure__postConfigure(void );
static inline void CUSTOM_HC__Rf1aConfigure__preUnconfigure(void );
static inline void CUSTOM_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_2FSK_1P2K_SENS_HC.nc"
static inline uint16_t SRFS6_868_2FSK_1P2K_SENS_HC__Get__get(void );



rf1a_config_t SRFS6_868_2FSK_1P2K_SENS_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x47, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x06, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0xF5, 
.mdmcfg3 = 0x83, 
.mdmcfg2 = 0x03, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x15, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x16, 
.bscfg = 0x6C, 
.agcctrl2 = 0x03, 
.agcctrl1 = 0x40, 
.agcctrl0 = 0x91, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0x56, 
.frend0 = 0x10, 
.fscal3 = 0xE9, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_100K_CUR_HC.nc"
static inline uint16_t SRFS6_868_GFSK_100K_CUR_HC__Get__get(void );



rf1a_config_t SRFS6_868_GFSK_100K_CUR_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x47, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x0C, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0x5B, 
.mdmcfg3 = 0xF8, 
.mdmcfg2 = 0x93, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x47, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x1D, 
.bscfg = 0x1C, 
.agcctrl2 = 0xC7, 
.agcctrl1 = 0x00, 
.agcctrl0 = 0xB2, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0xB6, 
.frend0 = 0x10, 
.fscal3 = 0xEA, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_100K_SENS_HC.nc"
static inline uint16_t SRFS6_868_GFSK_100K_SENS_HC__Get__get(void );



rf1a_config_t SRFS6_868_GFSK_100K_SENS_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x47, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x08, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0x5B, 
.mdmcfg3 = 0xF8, 
.mdmcfg2 = 0x13, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x47, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x1D, 
.bscfg = 0x1C, 
.agcctrl2 = 0xC7, 
.agcctrl1 = 0x00, 
.agcctrl0 = 0xB2, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0xB6, 
.frend0 = 0x10, 
.fscal3 = 0xEA, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_10K_CUR_HC.nc"
static inline uint16_t SRFS6_868_GFSK_10K_CUR_HC__Get__get(void );



rf1a_config_t SRFS6_868_GFSK_10K_CUR_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x47, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x08, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0xC8, 
.mdmcfg3 = 0x93, 
.mdmcfg2 = 0x93, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x34, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x16, 
.bscfg = 0x6C, 
.agcctrl2 = 0x43, 
.agcctrl1 = 0x40, 
.agcctrl0 = 0x91, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0x56, 
.frend0 = 0x10, 
.fscal3 = 0xE9, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_10K_SENS_HC.nc"
static inline uint16_t SRFS6_868_GFSK_10K_SENS_HC__Get__get(void );



rf1a_config_t SRFS6_868_GFSK_10K_SENS_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x47, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x06, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0xC8, 
.mdmcfg3 = 0x93, 
.mdmcfg2 = 0x13, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x34, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x16, 
.bscfg = 0x6C, 
.agcctrl2 = 0x43, 
.agcctrl1 = 0x40, 
.agcctrl0 = 0x91, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0x56, 
.frend0 = 0x10, 
.fscal3 = 0xE9, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_175K_CUR_HC.nc"
static inline uint16_t SRFS6_868_GFSK_175K_CUR_HC__Get__get(void );



rf1a_config_t SRFS6_868_GFSK_175K_CUR_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x07, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x0C, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0x3C, 
.mdmcfg3 = 0xB9, 
.mdmcfg2 = 0x93, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x57, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x1D, 
.bscfg = 0x1C, 
.agcctrl2 = 0xC7, 
.agcctrl1 = 0x00, 
.agcctrl0 = 0xB0, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0xB6, 
.frend0 = 0x10, 
.fscal3 = 0xEA, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x88, 
.test1 = 0x31, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_175K_SENS_HC.nc"
static inline uint16_t SRFS6_868_GFSK_175K_SENS_HC__Get__get(void );



rf1a_config_t SRFS6_868_GFSK_175K_SENS_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x07, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x0C, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0x3C, 
.mdmcfg3 = 0xB9, 
.mdmcfg2 = 0x13, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x57, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x1D, 
.bscfg = 0x1C, 
.agcctrl2 = 0xC7, 
.agcctrl1 = 0x00, 
.agcctrl0 = 0xB0, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0xB6, 
.frend0 = 0x10, 
.fscal3 = 0xEA, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x88, 
.test1 = 0x31, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_1P2K_CUR_HC.nc"
static inline uint16_t SRFS6_868_GFSK_1P2K_CUR_HC__Get__get(void );



rf1a_config_t SRFS6_868_GFSK_1P2K_CUR_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x47, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x06, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0xF5, 
.mdmcfg3 = 0x83, 
.mdmcfg2 = 0x93, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x15, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x16, 
.bscfg = 0x6C, 
.agcctrl2 = 0x03, 
.agcctrl1 = 0x40, 
.agcctrl0 = 0x91, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0x56, 
.frend0 = 0x10, 
.fscal3 = 0xE9, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_1P2K_SENS_HC.nc"
static inline uint16_t SRFS6_868_GFSK_1P2K_SENS_HC__Get__get(void );



rf1a_config_t SRFS6_868_GFSK_1P2K_SENS_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x47, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x06, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0xF5, 
.mdmcfg3 = 0x83, 
.mdmcfg2 = 0x13, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x15, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x16, 
.bscfg = 0x6C, 
.agcctrl2 = 0x03, 
.agcctrl1 = 0x40, 
.agcctrl0 = 0x91, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0x56, 
.frend0 = 0x10, 
.fscal3 = 0xE9, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_250K_CUR_HC.nc"
static inline uint16_t SRFS6_868_GFSK_250K_CUR_HC__Get__get(void );



rf1a_config_t SRFS6_868_GFSK_250K_CUR_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x07, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x0C, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0x2D, 
.mdmcfg3 = 0x3B, 
.mdmcfg2 = 0x93, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x62, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x1D, 
.bscfg = 0x1C, 
.agcctrl2 = 0xC7, 
.agcctrl1 = 0x00, 
.agcctrl0 = 0xB0, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0xB6, 
.frend0 = 0x10, 
.fscal3 = 0xEA, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x88, 
.test1 = 0x31, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_250K_SENS_HC.nc"
static inline uint16_t SRFS6_868_GFSK_250K_SENS_HC__Get__get(void );



rf1a_config_t SRFS6_868_GFSK_250K_SENS_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x07, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x0C, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0x2D, 
.mdmcfg3 = 0x3B, 
.mdmcfg2 = 0x13, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x62, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x1D, 
.bscfg = 0x1C, 
.agcctrl2 = 0xC7, 
.agcctrl1 = 0x00, 
.agcctrl0 = 0xB0, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0xB6, 
.frend0 = 0x10, 
.fscal3 = 0xEA, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x88, 
.test1 = 0x31, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_2P4K_CUR_HC.nc"
static inline uint16_t SRFS6_868_GFSK_2P4K_CUR_HC__Get__get(void );



rf1a_config_t SRFS6_868_GFSK_2P4K_CUR_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x47, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x06, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0xF6, 
.mdmcfg3 = 0x83, 
.mdmcfg2 = 0x93, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x15, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x16, 
.bscfg = 0x6C, 
.agcctrl2 = 0x03, 
.agcctrl1 = 0x40, 
.agcctrl0 = 0x91, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0x56, 
.frend0 = 0x10, 
.fscal3 = 0xE9, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_2P4K_SENS_HC.nc"
static inline uint16_t SRFS6_868_GFSK_2P4K_SENS_HC__Get__get(void );



rf1a_config_t SRFS6_868_GFSK_2P4K_SENS_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x47, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x06, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0xF6, 
.mdmcfg3 = 0x83, 
.mdmcfg2 = 0x13, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x15, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x16, 
.bscfg = 0x6C, 
.agcctrl2 = 0x03, 
.agcctrl1 = 0x40, 
.agcctrl0 = 0x91, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0x56, 
.frend0 = 0x10, 
.fscal3 = 0xE9, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_38P4K_CUR_HC.nc"
static inline uint16_t SRFS6_868_GFSK_38P4K_CUR_HC__Get__get(void );



rf1a_config_t SRFS6_868_GFSK_38P4K_CUR_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x47, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x08, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0xCA, 
.mdmcfg3 = 0x83, 
.mdmcfg2 = 0x93, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x34, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x16, 
.bscfg = 0x6C, 
.agcctrl2 = 0x43, 
.agcctrl1 = 0x40, 
.agcctrl0 = 0x91, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0x56, 
.frend0 = 0x10, 
.fscal3 = 0xE9, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_38P4K_SENS_HC.nc"
static inline uint16_t SRFS6_868_GFSK_38P4K_SENS_HC__Get__get(void );



rf1a_config_t SRFS6_868_GFSK_38P4K_SENS_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x47, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x06, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0xCA, 
.mdmcfg3 = 0x83, 
.mdmcfg2 = 0x13, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x34, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x16, 
.bscfg = 0x6C, 
.agcctrl2 = 0x43, 
.agcctrl1 = 0x40, 
.agcctrl0 = 0x91, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0x56, 
.frend0 = 0x10, 
.fscal3 = 0xE9, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_4P8K_CUR_HC.nc"
static inline uint16_t SRFS6_868_GFSK_4P8K_CUR_HC__Get__get(void );



rf1a_config_t SRFS6_868_GFSK_4P8K_CUR_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x47, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x08, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0xC7, 
.mdmcfg3 = 0x83, 
.mdmcfg2 = 0x93, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x40, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x16, 
.bscfg = 0x6C, 
.agcctrl2 = 0x43, 
.agcctrl1 = 0x40, 
.agcctrl0 = 0x91, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0x56, 
.frend0 = 0x10, 
.fscal3 = 0xE9, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_4P8K_SENS_HC.nc"
static inline uint16_t SRFS6_868_GFSK_4P8K_SENS_HC__Get__get(void );



rf1a_config_t SRFS6_868_GFSK_4P8K_SENS_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x47, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x06, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0xC7, 
.mdmcfg3 = 0x83, 
.mdmcfg2 = 0x13, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x40, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x16, 
.bscfg = 0x6C, 
.agcctrl2 = 0x43, 
.agcctrl1 = 0x40, 
.agcctrl0 = 0x91, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0x56, 
.frend0 = 0x10, 
.fscal3 = 0xE9, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_76P8K_CUR_HC.nc"
static inline uint16_t SRFS6_868_GFSK_76P8K_CUR_HC__Get__get(void );



rf1a_config_t SRFS6_868_GFSK_76P8K_CUR_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x47, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x0B, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0x7B, 
.mdmcfg3 = 0x83, 
.mdmcfg2 = 0x93, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x42, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x1D, 
.bscfg = 0x1C, 
.agcctrl2 = 0xC7, 
.agcctrl1 = 0x00, 
.agcctrl0 = 0xB2, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0xB6, 
.frend0 = 0x10, 
.fscal3 = 0xEA, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_76P8K_SENS_HC.nc"
static inline uint16_t SRFS6_868_GFSK_76P8K_SENS_HC__Get__get(void );



rf1a_config_t SRFS6_868_GFSK_76P8K_SENS_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x47, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x08, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0x7B, 
.mdmcfg3 = 0x83, 
.mdmcfg2 = 0x13, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x42, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x1D, 
.bscfg = 0x1C, 
.agcctrl2 = 0xC7, 
.agcctrl1 = 0x00, 
.agcctrl0 = 0xB2, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0xB6, 
.frend0 = 0x10, 
.fscal3 = 0xEA, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_MSK_500K_HC.nc"
static inline uint16_t SRFS6_868_MSK_500K_HC__Get__get(void );



rf1a_config_t SRFS6_868_MSK_500K_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x07, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x0E, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0x0E, 
.mdmcfg3 = 0x3B, 
.mdmcfg2 = 0x73, 
.mdmcfg1 = 0x42, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x00, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x1D, 
.bscfg = 0x1C, 
.agcctrl2 = 0xC7, 
.agcctrl1 = 0x00, 
.agcctrl0 = 0xB0, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0xB6, 
.frend0 = 0x10, 
.fscal3 = 0xEA, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x88, 
.test1 = 0x31, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_868_MSK_500K_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_868_MSK_500K_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_868_MSK_500K_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_868_MSK_500K_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_868_MSK_500K_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_PRE802154G_HC.nc"
static inline uint16_t SRFS6_PRE802154G_HC__Get__get(void );



rf1a_config_t SRFS6_PRE802154G_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x47, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x08, 
.fsctrl0 = 0x00, 
.freq2 = 0x22, 
.freq1 = 0xB3, 
.freq0 = 0x33, 
.mdmcfg4 = 0x7A, 
.mdmcfg3 = 0xF8, 
.mdmcfg2 = 0x13, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x40, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x1D, 
.bscfg = 0x1C, 
.agcctrl2 = 0xC7, 
.agcctrl1 = 0x00, 
.agcctrl0 = 0xB2, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0xB6, 
.frend0 = 0x10, 
.fscal3 = 0xEA, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_PRE802154G_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_PRE802154G_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_PRE802154G_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_PRE802154G_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_PRE802154G_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_RESET_HC.nc"
static inline uint16_t SRFS6_RESET_HC__Get__get(void );



rf1a_config_t SRFS6_RESET_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x47, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x06, 
.fsctrl0 = 0x00, 
.freq2 = 0x21, 
.freq1 = 0x65, 
.freq0 = 0x6A, 
.mdmcfg4 = 0xF5, 
.mdmcfg3 = 0x83, 
.mdmcfg2 = 0x13, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x15, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x18, 
.foccfg = 0x16, 
.bscfg = 0x6C, 
.agcctrl2 = 0x03, 
.agcctrl1 = 0x40, 
.agcctrl0 = 0x91, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0x56, 
.frend0 = 0x10, 
.fscal3 = 0xE9, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS6_RESET_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS6_RESET_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS6_RESET_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS6_RESET_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS6_RESET_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_779_MSK_250K_HC.nc"
static inline uint16_t SRFS7_779_MSK_250K_HC__Get__get(void );



rf1a_config_t SRFS7_779_MSK_250K_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x07, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x0C, 
.fsctrl0 = 0x00, 
.freq2 = 0x1D, 
.freq1 = 0xF6, 
.freq0 = 0x27, 
.mdmcfg4 = 0x2D, 
.mdmcfg3 = 0x3B, 
.mdmcfg2 = 0x73, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x62, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x10, 
.foccfg = 0x1D, 
.bscfg = 0x1C, 
.agcctrl2 = 0xC7, 
.agcctrl1 = 0x00, 
.agcctrl0 = 0xB0, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0xB6, 
.frend0 = 0x10, 
.fscal3 = 0xEA, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x88, 
.test1 = 0x31, 
.test0 = 0x0B, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS7_779_MSK_250K_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS7_779_MSK_250K_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS7_779_MSK_250K_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS7_779_MSK_250K_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS7_779_MSK_250K_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_902P2_GFSK_50K_135B_HC.nc"
static inline uint16_t SRFS7_902P2_GFSK_50K_135B_HC__Get__get(void );



rf1a_config_t SRFS7_902P2_GFSK_50K_135B_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x07, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x08, 
.fsctrl0 = 0x00, 
.freq2 = 0x22, 
.freq1 = 0xB3, 
.freq0 = 0x33, 
.mdmcfg4 = 0xAA, 
.mdmcfg3 = 0xF8, 
.mdmcfg2 = 0x13, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x40, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x10, 
.foccfg = 0x1D, 
.bscfg = 0x1C, 
.agcctrl2 = 0x43, 
.agcctrl1 = 0x40, 
.agcctrl0 = 0x91, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0x56, 
.frend0 = 0x10, 
.fscal3 = 0xE9, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_902P2_GFSK_50K_163B_HC.nc"
static inline uint16_t SRFS7_902P2_GFSK_50K_163B_HC__Get__get(void );



rf1a_config_t SRFS7_902P2_GFSK_50K_163B_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x07, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x00, 

.fsctrl1 = 0x08, 
.fsctrl0 = 0x00, 
.freq2 = 0x22, 
.freq1 = 0xB3, 
.freq0 = 0x33, 
.mdmcfg4 = 0x9A, 
.mdmcfg3 = 0xF8, 
.mdmcfg2 = 0x13, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x40, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x10, 
.foccfg = 0x1D, 
.bscfg = 0x1C, 
.agcctrl2 = 0x43, 
.agcctrl1 = 0x40, 
.agcctrl0 = 0x91, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0x56, 
.frend0 = 0x10, 
.fscal3 = 0xE9, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_STI_902_GFSK_1P2K_HC.nc"
static inline uint16_t SRFS7_STI_902_GFSK_1P2K_HC__Get__get(void );



rf1a_config_t SRFS7_STI_902_GFSK_1P2K_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x47, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x14, 

.fsctrl1 = 0x06, 
.fsctrl0 = 0x00, 
.freq2 = 0x22, 
.freq1 = 0xB1, 
.freq0 = 0x3B, 
.mdmcfg4 = 0xF5, 
.mdmcfg3 = 0x83, 
.mdmcfg2 = 0x13, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x15, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x10, 
.foccfg = 0x16, 
.bscfg = 0x6C, 
.agcctrl2 = 0x03, 
.agcctrl1 = 0x40, 
.agcctrl0 = 0x91, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0x56, 
.frend0 = 0x10, 
.fscal3 = 0xE9, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_STI_902_GFSK_250K_HC.nc"
static inline uint16_t SRFS7_STI_902_GFSK_250K_HC__Get__get(void );



rf1a_config_t SRFS7_STI_902_GFSK_250K_HC__this_config = { 
.iocfg2 = 0x29, 



.iocfg1 = 0x2e, 

.iocfg0 = 0x06, 
.fifothr = 0x07, 




.sync1 = 0xd3, 
.sync0 = 0x91, 

.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x05, 
.addr = 0x00, 



.channr = 0x14, 

.fsctrl1 = 0x0C, 
.fsctrl0 = 0x00, 
.freq2 = 0x22, 
.freq1 = 0xB1, 
.freq0 = 0x3B, 
.mdmcfg4 = 0x2D, 
.mdmcfg3 = 0x3B, 
.mdmcfg2 = 0x13, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x62, 



.mcsm2 = 0x07, 




.mcsm1 = 0x30, 

.mcsm0 = 0x10, 
.foccfg = 0x1D, 
.bscfg = 0x1C, 
.agcctrl2 = 0xC7, 
.agcctrl1 = 0x00, 
.agcctrl0 = 0xB0, 



.worevt1 = 0x80, 




.worevt0 = 0x00, 




.worctrl = 0xf0, 

.frend1 = 0xB6, 
.frend0 = 0x10, 
.fscal3 = 0xEA, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x88, 
.test1 = 0x31, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__getConfiguration(void );


static inline void SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__preConfigure(void );
static inline void SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__postConfigure(void );
static inline void SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__preUnconfigure(void );
static inline void SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__postUnconfigure(void );
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/TINYOSRF1A_HC.nc"
static inline uint16_t TINYOSRF1A_HC__Get__get(void );



rf1a_config_t TINYOSRF1A_HC__this_config = { 
.iocfg2 = 0x2E, 

.iocfg1 = 0x2E, 



.iocfg0 = 0x29, 
.fifothr = 0x47, 

.sync1 = 0xD3, 
.sync0 = 0x91, 




.pktlen = 0xFF, 
.pktctrl1 = 0x04, 
.pktctrl0 = 0x45, 
.addr = 0x00, 



.channr = 0x0A, 

.fsctrl1 = 0x06, 
.fsctrl0 = 0x00, 
.freq2 = 0x22, 
.freq1 = 0xB1, 
.freq0 = 0x3B, 
.mdmcfg4 = 0xC8, 
.mdmcfg3 = 0x93, 
.mdmcfg2 = 0x13, 
.mdmcfg1 = 0x22, 
.mdmcfg0 = 0xF8, 
.deviatn = 0x34, 

.mcsm2 = 0x07, 




.mcsm1 = 0x3F, 



.mcsm0 = 0x10, 
.foccfg = 0x16, 
.bscfg = 0x6C, 
.agcctrl2 = 0x03, 
.agcctrl1 = 0x40, 
.agcctrl0 = 0x91, 

.worevt1 = 0x80, 




.worevt0 = 0x00, 






.worctrl = 0xf0, 

.frend1 = 0x56, 
.frend0 = 0x10, 
.fscal3 = 0xE9, 
.fscal2 = 0x2A, 
.fscal1 = 0x00, 
.fscal0 = 0x1F, 


.fstest = 0x59, 


.test2 = 0x81, 
.test1 = 0x35, 
.test0 = 0x09, 





.patable = { 0xc6 } };



static inline const rf1a_config_t *TINYOSRF1A_HC__Rf1aConfigure__getConfiguration(void );


static inline void TINYOSRF1A_HC__Rf1aConfigure__preConfigure(void );
static inline void TINYOSRF1A_HC__Rf1aConfigure__postConfigure(void );
static inline void TINYOSRF1A_HC__Rf1aConfigure__preUnconfigure(void );
static inline void TINYOSRF1A_HC__Rf1aConfigure__postUnconfigure(void );
# 113 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SplitControl__startDone(error_t error);
#line 138
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SplitControl__stopDone(error_t error);
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__receiveDone_task__postTask(void );
# 47 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aPacket.nc"
static rf1a_metadata_t */*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPacket__metadata(message_t *msg);
# 65 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Packet__clear(
#line 62
message_t * msg);
# 100 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Send__sendDone(
# 43 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
uint8_t arg_0x40f45d50, 
# 96 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 100 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
static error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__send(uint8_t *buffer, unsigned int length);
#line 253
static error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__setReceiveBuffer(uint8_t *buffer, 
unsigned int length, 
bool single_use);
# 67 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysicalMetadata.nc"
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysicalMetadata__store(rf1a_metadata_t *metadatap);
# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Receive__receive(
# 44 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
uint8_t arg_0x40f42798, 
# 71 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 120 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
static error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Resource__release(void );
#line 88
static error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Resource__request(void );
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__sendDone_task__postTask(void );
#line 67
static error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__stopDone_task__postTask(void );
# 201 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
enum /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0____nesc_unnamed4384 {
#line 201
  Rf1aTinyOsPhysicalP__0__stopDone_task = 26U
};
#line 201
typedef int /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0____nesc_sillytask_stopDone_task[/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__stopDone_task];
#line 249
enum /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0____nesc_unnamed4385 {
#line 249
  Rf1aTinyOsPhysicalP__0__sendDone_task = 27U
};
#line 249
typedef int /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0____nesc_sillytask_sendDone_task[/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__sendDone_task];
#line 329
enum /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0____nesc_unnamed4386 {
#line 329
  Rf1aTinyOsPhysicalP__0__receiveDone_task = 28U
};
#line 329
typedef int /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0____nesc_sillytask_receiveDone_task[/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__receiveDone_task];
#line 56
typedef rf1a_ieee154_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__phy_header_t;


static inline /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__phy_header_t */*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__header(message_t *msg);


static ieee154_fcf_t */*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__fcf(message_t *msg);


typedef rf1a_metadata_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__metadata_t;


static inline /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__metadata_t */*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__metadata(message_t *msg);


static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__setReceiveBuffer(message_t *mp);









enum /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0____nesc_unnamed4387 {


  Rf1aTinyOsPhysicalP__0__SCS_off, 



  Rf1aTinyOsPhysicalP__0__SCS_starting, 

  Rf1aTinyOsPhysicalP__0__SCS_on, 




  Rf1aTinyOsPhysicalP__0__SCS_stopping
};



uint8_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__split_control_state;


enum /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0____nesc_unnamed4388 {

  Rf1aTinyOsPhysicalP__0__TXS_idle, 

  Rf1aTinyOsPhysicalP__0__TXS_active
};


uint8_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__tx_state;


int /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__tx_result;



message_t */*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__tx_message;




message_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__rx_buffer;




message_t */*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__rx_message;




unsigned int /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__rx_count;

static inline error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SplitControl__start(void );
#line 161
static inline error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SplitControl__stop(void );
#line 187
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Resource__granted(void );
#line 201
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__stopDone_task__runTask(void );





static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__released(void );
#line 222
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__setReceiveBuffer(message_t *mp);
#line 249
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__sendDone_task__runTask(void );
#line 263
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__sendDone(int result);







static error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Send__send(uint8_t frame_type, message_t *msg, uint8_t len);
#line 312
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Send__default__sendDone(uint8_t frame_type, message_t *msg, error_t error);
#line 325
static inline message_t */*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Receive__default__receive(uint8_t frame_type, message_t *msg, void *payload, uint8_t len);

static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__receiveStarted(unsigned int length);

static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__receiveDone_task__runTask(void );
#line 365
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__receiveDone(uint8_t *buffer, 
unsigned int count, 
int result);
#line 385
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__receiveBufferFilled(uint8_t *buffer, 
unsigned int count);









static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__frameStarted(void );
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__clearChannel(void );
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__carrierSense(void );
# 75 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static error_t /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__SubSend__send(
#line 67
message_t * msg, 







uint8_t len);
# 47 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aPacket.nc"
static rf1a_metadata_t */*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__Rf1aPacket__metadata(message_t *msg);
# 100 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__Send__sendDone(
#line 96
message_t * msg, 



error_t error);
#line 75
static error_t /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckSend__send(
#line 67
message_t * msg, 







uint8_t len);
# 67 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysicalMetadata.nc"
static void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__Rf1aPhysicalMetadata__store(rf1a_metadata_t *metadatap);
# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__Receive__receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ackWaitAlarmFired_task__postTask(void );
# 66 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckWaitAlarm__start(/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckWaitAlarm__size_type dt);
# 208 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/layers/Rf1aAckP.nc"
enum /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0____nesc_unnamed4389 {
#line 208
  Rf1aAckP__0__ackWaitAlarmFired_task = 29U
};
#line 208
typedef int /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0____nesc_sillytask_ackWaitAlarmFired_task[/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ackWaitAlarmFired_task];
#line 21
typedef rf1a_ieee154_t /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__phy_header_t;


static inline /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__phy_header_t */*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__header(message_t *msg);


static ieee154_fcf_t */*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__fcf(message_t *msg);
#line 42
typedef rf1a_ieee154_t /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ack_t;
#line 57
#line 54
typedef nx_struct /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0____nesc_unnamed4390 {
  nx_uint8_t header[sizeof(message_header_t )];
  nx_uint8_t data[1];
} __attribute__((packed)) /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ack_message_t;
#line 72
enum /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0____nesc_unnamed4391 {



  Rf1aAckP__0__TX_S_idle, 





  Rf1aAckP__0__TX_S_sending, 




  Rf1aAckP__0__TX_S_waiting, 



  Rf1aAckP__0__TX_S_alarmFired, 




  Rf1aAckP__0__TX_S_MASK = 0x0F, 



  Rf1aAckP__0__TX_S_ACKED = 0x80
};


uint8_t /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_state;


uint8_t /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_attempts_remaining;



message_t */*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_message;


uint8_t /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_length;


error_t /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_result;



bool /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_acked;





enum /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0____nesc_unnamed4392 {


  Rf1aAckP__0__RX_S_idle, 



  Rf1aAckP__0__RX_S_transmitting
};

uint8_t /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__rx_state;


/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ack_message_t /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ack_message;

enum /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0____nesc_unnamed4393 {



  Rf1aAckP__0__CFG_macAckWaitDuration_32k = 3277, 




  Rf1aAckP__0__CFG_macMaxFrameRetries = 4
};



static void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__signalSendDone_(void );
#line 178
static inline void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__transitionToWaiting_atomic_(void );
#line 194
static bool /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__completeSend_atomic_(error_t result);
#line 208
static inline void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ackWaitAlarmFired_task__runTask(void );
#line 242
static inline error_t /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__Send__send(message_t *msg, uint8_t len);
#line 306
static inline void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckWaitAlarm__fired(void );










static inline void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__SubSend__sendDone(message_t *msg, error_t error);
#line 344
enum /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0____nesc_unnamed4394 {


  Rf1aAckP__0__FCF_ACK_PRESERVE = ~(((IEEE154_TYPE_MASK << IEEE154_FCF_FRAME_TYPE)
   | (1 << IEEE154_FCF_ACK_REQ))
   | (1 << IEEE154_FCF_FRAME_PENDING)), 

  Rf1aAckP__0__FCF_ACK_FIXED = IEEE154_TYPE_ACK << IEEE154_FCF_FRAME_TYPE
};

static inline message_t */*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__SubReceive__receive(message_t *msg, void *payload, uint8_t len);
#line 390
static inline message_t */*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckReceive__receive(message_t *msg, void *payload, uint8_t len);
#line 421
static inline void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckSend__sendDone(message_t *msg, error_t error);
# 41 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430Compare__setEvent(uint16_t time);

static void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430Compare__setEventFromNow(uint16_t delta);
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static uint16_t /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430Timer__get(void );
# 78 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__fired(void );
# 57 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
static void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430TimerControl__enableEvents(void );
static void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430TimerControl__disableEvents(void );
#line 44
static void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430TimerControl__clearPendingInterrupt(void );
# 60 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430AlarmC.nc"
static inline void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__start(uint16_t dt);









static inline void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430Compare__fired(void );










static void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__startAt(uint16_t t0, uint16_t dt);
#line 104
static inline uint16_t /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__getNow(void );









static inline void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430Timer__overflow(void );
# 48 "/opt/tinyos-2.x/tos/lib/util/keyvaluerecord/KeyValueRecord.nc"
static bool UniqueReceiveP__KeyValueRecord__hasSeen(uint16_t key, uint16_t value);







static void UniqueReceiveP__KeyValueRecord__insert(uint16_t key, uint16_t value);
# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



UniqueReceiveP__Receive__receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
#line 78
static 
#line 74
message_t * 



UniqueReceiveP__DuplicateReceive__receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/layers/UniqueReceiveP.nc"
typedef rf1a_ieee154_t UniqueReceiveP__header_t;


static inline UniqueReceiveP__header_t *UniqueReceiveP__header(message_t *msg);


static inline message_t *UniqueReceiveP__SubReceive__receive(message_t *msg, void *payload, 
uint8_t len);
#line 76
static inline message_t *UniqueReceiveP__DuplicateReceive__default__receive(message_t *msg, void *payload, uint8_t len);
# 54 "/opt/tinyos-2.x/tos/lib/util/keyvaluerecord/KeyValueRecordP.h"
#line 48
typedef struct KeyValueRecordP__key_value_record_t {

  uint16_t key;


  uint16_t value;
} KeyValueRecordP__key_value_record_t;









#line 57
typedef struct KeyValueRecordP__client_record_t {

  uint8_t size;

  uint8_t write_index;

  KeyValueRecordP__key_value_record_t history[5];
} KeyValueRecordP__client_record_t;
# 51 "/opt/tinyos-2.x/tos/lib/util/keyvaluerecord/KeyValueRecordP.nc"
enum KeyValueRecordP____nesc_unnamed4395 {
  KeyValueRecordP__NUM_CLIENTS = 1U
};




KeyValueRecordP__client_record_t KeyValueRecordP__client_data[KeyValueRecordP__NUM_CLIENTS];









static inline bool KeyValueRecordP__KeyValueRecord__hasSeen(uint8_t client, uint16_t key, uint16_t value);
#line 92
static inline void KeyValueRecordP__KeyValueRecord__insert(uint8_t client, uint16_t key, uint16_t value);
# 75 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static error_t Rf1aActiveMessageP__SubSend__send(
#line 67
message_t * msg, 







uint8_t len);
# 59 "/opt/tinyos-2.x/tos/interfaces/SendNotifier.nc"
static void Rf1aActiveMessageP__SendNotifier__aboutToSend(
# 43 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aActiveMessageP.nc"
am_id_t arg_0x41015d78, 
# 59 "/opt/tinyos-2.x/tos/interfaces/SendNotifier.nc"
am_addr_t dest, 
#line 57
message_t * msg);
# 110 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static void Rf1aActiveMessageP__AMSend__sendDone(
# 40 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aActiveMessageP.nc"
am_id_t arg_0x40ffa678, 
# 103 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t * msg, 






error_t error);
# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



Rf1aActiveMessageP__Snoop__receive(
# 42 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aActiveMessageP.nc"
am_id_t arg_0x41015700, 
# 71 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 57 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aPacket.nc"
static void Rf1aActiveMessageP__Rf1aPacket__configureAsData(message_t *msg);
# 51 "/opt/tinyos-2.x/tos/interfaces/Ieee154Packet.nc"
static void Rf1aActiveMessageP__Ieee154Packet__setPan(message_t *msg, ieee154_panid_t grp);

static ieee154_panid_t Rf1aActiveMessageP__Ieee154Packet__localPan(void );
# 126 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
static 
#line 123
void * 


Rf1aActiveMessageP__Packet__getPayload(
#line 121
message_t * msg, 




uint8_t len);
# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



Rf1aActiveMessageP__Receive__receive(
# 41 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aActiveMessageP.nc"
am_id_t arg_0x41015068, 
# 71 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 68 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
static am_addr_t Rf1aActiveMessageP__AMPacket__address(void );
#line 121
static void Rf1aActiveMessageP__AMPacket__setSource(
#line 117
message_t * amsg, 



am_addr_t addr);
#line 103
static void Rf1aActiveMessageP__AMPacket__setDestination(
#line 99
message_t * amsg, 



am_addr_t addr);
#line 147
static am_id_t Rf1aActiveMessageP__AMPacket__type(
#line 143
message_t * amsg);
#line 162
static void Rf1aActiveMessageP__AMPacket__setType(
#line 158
message_t * amsg, 



am_id_t t);
#line 136
static bool Rf1aActiveMessageP__AMPacket__isForMe(
#line 133
message_t * amsg);
# 57 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aActiveMessageP.nc"
typedef rf1a_nalp_am_t Rf1aActiveMessageP__layer_header_t;

static error_t Rf1aActiveMessageP__AMSend__send(am_id_t id, am_addr_t addr, 
message_t *msg, 
uint8_t len);
#line 78
static inline void *Rf1aActiveMessageP__AMSend__getPayload(am_id_t id, message_t *m, uint8_t len);









static inline void Rf1aActiveMessageP__SubSend__sendDone(message_t *msg, error_t error);




static inline message_t *Rf1aActiveMessageP__SubReceive__receive(message_t *msg, void *payload_, uint8_t len);









static inline message_t *Rf1aActiveMessageP__Receive__default__receive(am_id_t id, message_t *msg, void *payload, uint8_t len);
static inline message_t *Rf1aActiveMessageP__Snoop__default__receive(am_id_t id, message_t *msg, void *payload, uint8_t len);
static inline void Rf1aActiveMessageP__SendNotifier__default__aboutToSend(am_id_t amId, am_addr_t addr, message_t *msg);
# 75 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static error_t /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__SubSend__send(
#line 67
message_t * msg, 







uint8_t len);
# 110 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static void /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMSend__sendDone(
# 47 "/opt/tinyos-2.x/tos/lib/serial/SerialActiveMessageP.nc"
am_id_t arg_0x41056e60, 
# 103 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t * msg, 






error_t error);
# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



/*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Receive__receive(
# 48 "/opt/tinyos-2.x/tos/lib/serial/SerialActiveMessageP.nc"
am_id_t arg_0x410538e0, 
# 71 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 60 "/opt/tinyos-2.x/tos/lib/serial/SerialActiveMessageP.nc"
static inline serial_header_t * /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__getHeader(message_t * msg);







static error_t /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMSend__send(am_id_t id, am_addr_t dest, 
message_t *msg, 
uint8_t len);
#line 97
static inline void */*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMSend__getPayload(am_id_t id, message_t *m, uint8_t len);



static inline void /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__SubSend__sendDone(message_t *msg, error_t result);







static inline message_t */*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Receive__default__receive(uint8_t id, message_t *msg, void *payload, uint8_t len);



static inline message_t */*SerialActiveMessageC.AM*/SerialActiveMessageP__0__SubReceive__receive(message_t *msg, void *payload, uint8_t len);








static inline uint8_t /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Packet__payloadLength(message_t *msg);




static inline void /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Packet__setPayloadLength(message_t *msg, uint8_t len);



static inline uint8_t /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Packet__maxPayloadLength(void );



static inline void */*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Packet__getPayload(message_t *msg, uint8_t len);
#line 148
static am_addr_t /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMPacket__destination(message_t *amsg);









static inline void /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMPacket__setDestination(message_t *amsg, am_addr_t addr);
#line 172
static inline am_id_t /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMPacket__type(message_t *amsg);




static inline void /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMPacket__setType(message_t *amsg, am_id_t type);
# 113 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
static void SerialP__SplitControl__startDone(error_t error);
#line 138
static void SerialP__SplitControl__stopDone(error_t error);
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t SerialP__stopDoneTask__postTask(void );
# 95 "/opt/tinyos-2.x/tos/interfaces/StdControl.nc"
static error_t SerialP__SerialControl__start(void );









static error_t SerialP__SerialControl__stop(void );
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t SerialP__RunTx__postTask(void );
# 49 "/opt/tinyos-2.x/tos/lib/serial/SerialFlush.nc"
static void SerialP__SerialFlush__flush(void );
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t SerialP__startDoneTask__postTask(void );
# 56 "/opt/tinyos-2.x/tos/lib/serial/SerialFrameComm.nc"
static error_t SerialP__SerialFrameComm__putDelimiter(void );
#line 79
static void SerialP__SerialFrameComm__resetReceive(void );
#line 65
static error_t SerialP__SerialFrameComm__putData(uint8_t data);
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t SerialP__defaultSerialFlushTask__postTask(void );
# 81 "/opt/tinyos-2.x/tos/lib/serial/SendBytePacket.nc"
static uint8_t SerialP__SendBytePacket__nextByte(void );









static void SerialP__SendBytePacket__sendCompleted(error_t error);
# 62 "/opt/tinyos-2.x/tos/lib/serial/ReceiveBytePacket.nc"
static error_t SerialP__ReceiveBytePacket__startPacket(void );






static void SerialP__ReceiveBytePacket__byteReceived(uint8_t data);










static void SerialP__ReceiveBytePacket__endPacket(error_t result);
# 191 "/opt/tinyos-2.x/tos/lib/serial/SerialP.nc"
enum SerialP____nesc_unnamed4396 {
#line 191
  SerialP__RunTx = 30U
};
#line 191
typedef int SerialP____nesc_sillytask_RunTx[SerialP__RunTx];
#line 322
enum SerialP____nesc_unnamed4397 {
#line 322
  SerialP__startDoneTask = 31U
};
#line 322
typedef int SerialP____nesc_sillytask_startDoneTask[SerialP__startDoneTask];









enum SerialP____nesc_unnamed4398 {
#line 332
  SerialP__stopDoneTask = 32U
};
#line 332
typedef int SerialP____nesc_sillytask_stopDoneTask[SerialP__stopDoneTask];








enum SerialP____nesc_unnamed4399 {
#line 341
  SerialP__defaultSerialFlushTask = 33U
};
#line 341
typedef int SerialP____nesc_sillytask_defaultSerialFlushTask[SerialP__defaultSerialFlushTask];
#line 81
enum SerialP____nesc_unnamed4400 {
  SerialP__RX_DATA_BUFFER_SIZE = 2, 
  SerialP__TX_DATA_BUFFER_SIZE = 4, 
  SerialP__SERIAL_MTU = 255, 
  SerialP__SERIAL_VERSION = 1, 
  SerialP__ACK_QUEUE_SIZE = 5
};

enum SerialP____nesc_unnamed4401 {
  SerialP__RXSTATE_NOSYNC, 
  SerialP__RXSTATE_PROTO, 
  SerialP__RXSTATE_TOKEN, 
  SerialP__RXSTATE_INFO, 
  SerialP__RXSTATE_INACTIVE
};

enum SerialP____nesc_unnamed4402 {
  SerialP__TXSTATE_IDLE, 
  SerialP__TXSTATE_PROTO, 
  SerialP__TXSTATE_SEQNO, 
  SerialP__TXSTATE_INFO, 
  SerialP__TXSTATE_FCS1, 
  SerialP__TXSTATE_FCS2, 
  SerialP__TXSTATE_ENDFLAG, 
  SerialP__TXSTATE_ENDWAIT, 
  SerialP__TXSTATE_FINISH, 
  SerialP__TXSTATE_ERROR, 
  SerialP__TXSTATE_INACTIVE
};





#line 111
typedef enum SerialP____nesc_unnamed4403 {
  SerialP__BUFFER_AVAILABLE, 
  SerialP__BUFFER_FILLING, 
  SerialP__BUFFER_COMPLETE
} SerialP__tx_data_buffer_states_t;

enum SerialP____nesc_unnamed4404 {
  SerialP__TX_ACK_INDEX = 0, 
  SerialP__TX_DATA_INDEX = 1, 
  SerialP__TX_BUFFER_COUNT = 2
};






#line 124
typedef struct SerialP____nesc_unnamed4405 {
  uint8_t writePtr;
  uint8_t readPtr;
  uint8_t buf[SerialP__RX_DATA_BUFFER_SIZE + 1];
} SerialP__rx_buf_t;




#line 130
typedef struct SerialP____nesc_unnamed4406 {
  uint8_t state;
  uint8_t buf;
} SerialP__tx_buf_t;





#line 135
typedef struct SerialP____nesc_unnamed4407 {
  uint8_t writePtr;
  uint8_t readPtr;
  uint8_t buf[SerialP__ACK_QUEUE_SIZE + 1];
} SerialP__ack_queue_t;



SerialP__rx_buf_t SerialP__rxBuf;
SerialP__tx_buf_t SerialP__txBuf[SerialP__TX_BUFFER_COUNT];



uint8_t SerialP__rxState;
uint8_t SerialP__rxByteCnt;
uint8_t SerialP__rxProto;
uint8_t SerialP__rxSeqno;
uint16_t SerialP__rxCRC;



uint8_t SerialP__txState;
uint8_t SerialP__txByteCnt;
uint8_t SerialP__txProto;
uint8_t SerialP__txSeqno;
uint16_t SerialP__txCRC;
uint8_t SerialP__txPending;
uint8_t SerialP__txIndex;


SerialP__ack_queue_t SerialP__ackQ;

bool SerialP__offPending = FALSE;



static __inline void SerialP__txInit(void );
static __inline void SerialP__rxInit(void );
static __inline void SerialP__ackInit(void );

static __inline bool SerialP__ack_queue_is_full(void );
static __inline bool SerialP__ack_queue_is_empty(void );
static __inline void SerialP__ack_queue_push(uint8_t token);
static __inline uint8_t SerialP__ack_queue_top(void );
static inline uint8_t SerialP__ack_queue_pop(void );




static __inline void SerialP__rx_buffer_push(uint8_t data);
static __inline uint8_t SerialP__rx_buffer_top(void );
static __inline uint8_t SerialP__rx_buffer_pop(void );
static __inline uint16_t SerialP__rx_current_crc(void );

static void SerialP__rx_state_machine(bool isDelimeter, uint8_t data);
static void SerialP__MaybeScheduleTx(void );




static __inline void SerialP__txInit(void );
#line 207
static __inline void SerialP__rxInit(void );








static __inline void SerialP__ackInit(void );



static inline error_t SerialP__Init__init(void );
#line 234
static __inline bool SerialP__ack_queue_is_full(void );









static __inline bool SerialP__ack_queue_is_empty(void );





static __inline void SerialP__ack_queue_push(uint8_t token);









static __inline uint8_t SerialP__ack_queue_top(void );









static inline uint8_t SerialP__ack_queue_pop(void );
#line 297
static __inline void SerialP__rx_buffer_push(uint8_t data);



static __inline uint8_t SerialP__rx_buffer_top(void );



static __inline uint8_t SerialP__rx_buffer_pop(void );





static __inline uint16_t SerialP__rx_current_crc(void );










static inline void SerialP__startDoneTask__runTask(void );









static inline void SerialP__stopDoneTask__runTask(void );



static inline void SerialP__SerialFlush__flushDone(void );




static inline void SerialP__defaultSerialFlushTask__runTask(void );


static inline void SerialP__SerialFlush__default__flush(void );



static inline error_t SerialP__SplitControl__start(void );








static void SerialP__testOff(void );
#line 394
static inline void SerialP__SerialFrameComm__delimiterReceived(void );


static inline void SerialP__SerialFrameComm__dataReceived(uint8_t data);



static inline bool SerialP__valid_rx_proto(uint8_t proto);










static void SerialP__rx_state_machine(bool isDelimeter, uint8_t data);
#line 518
static void SerialP__MaybeScheduleTx(void );










static inline error_t SerialP__SendBytePacket__completeSend(void );








static inline error_t SerialP__SendBytePacket__startSend(uint8_t b);
#line 559
static inline void SerialP__RunTx__runTask(void );
#line 668
static inline void SerialP__SerialFrameComm__putDone(void );
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTask__postTask(void );
# 100 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__Send__sendDone(
# 51 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
uart_id_t arg_0x4110c560, 
# 96 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__signalSendDone__postTask(void );
# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__Receive__receive(
# 50 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
uart_id_t arg_0x410d2e50, 
# 71 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 31 "/opt/tinyos-2.x/tos/lib/serial/SerialPacketInfo.nc"
static uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__upperLength(
# 54 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
uart_id_t arg_0x4110b088, 
# 31 "/opt/tinyos-2.x/tos/lib/serial/SerialPacketInfo.nc"
message_t *msg, uint8_t dataLinkLen);
#line 15
static uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__offset(
# 54 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
uart_id_t arg_0x4110b088);
# 23 "/opt/tinyos-2.x/tos/lib/serial/SerialPacketInfo.nc"
static uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__dataLinkLength(
# 54 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
uart_id_t arg_0x4110b088, 
# 23 "/opt/tinyos-2.x/tos/lib/serial/SerialPacketInfo.nc"
message_t *msg, uint8_t upperLen);
# 71 "/opt/tinyos-2.x/tos/lib/serial/SendBytePacket.nc"
static error_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__SendBytePacket__completeSend(void );
#line 62
static error_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__SendBytePacket__startSend(uint8_t first_byte);
# 158 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
enum /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0____nesc_unnamed4408 {
#line 158
  SerialDispatcherP__0__signalSendDone = 34U
};
#line 158
typedef int /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0____nesc_sillytask_signalSendDone[/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__signalSendDone];
#line 275
enum /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0____nesc_unnamed4409 {
#line 275
  SerialDispatcherP__0__receiveTask = 35U
};
#line 275
typedef int /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0____nesc_sillytask_receiveTask[/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTask];
#line 66
#line 62
typedef enum /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0____nesc_unnamed4410 {
  SerialDispatcherP__0__SEND_STATE_IDLE = 0, 
  SerialDispatcherP__0__SEND_STATE_BEGIN = 1, 
  SerialDispatcherP__0__SEND_STATE_DATA = 2
} /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__send_state_t;

enum /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0____nesc_unnamed4411 {
  SerialDispatcherP__0__RECV_STATE_IDLE = 0, 
  SerialDispatcherP__0__RECV_STATE_BEGIN = 1, 
  SerialDispatcherP__0__RECV_STATE_DATA = 2
};






#line 74
typedef struct /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0____nesc_unnamed4412 {
  uint8_t which : 1;
  uint8_t bufZeroLocked : 1;
  uint8_t bufOneLocked : 1;
  uint8_t state : 2;
} /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__recv_state_t;



/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__recv_state_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveState = { 0, 0, 0, /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__RECV_STATE_IDLE };
uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__recvType = TOS_SERIAL_UNKNOWN_ID;
uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__recvIndex = 0;


message_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__messages[2];
message_t * /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__messagePtrs[2] = { &/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__messages[0], &/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__messages[1] };




uint8_t * /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveBuffer = (uint8_t * )&/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__messages[0];

uint8_t * /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendBuffer = (void *)0;
/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__send_state_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendState = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__SEND_STATE_IDLE;
uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendLen = 0;
uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendIndex = 0;
error_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendError = SUCCESS;
bool /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendCancelled = FALSE;
uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendId = 0;


uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTaskPending = FALSE;
uart_id_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTaskType = 0;
uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTaskWhich;
message_t * /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTaskBuf = (void *)0;
uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTaskSize = 0;

static inline error_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__Send__send(uint8_t id, message_t *msg, uint8_t len);
#line 158
static inline void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__signalSendDone__runTask(void );
#line 178
static inline uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__SendBytePacket__nextByte(void );
#line 194
static inline void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__SendBytePacket__sendCompleted(error_t error);




static inline bool /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__isCurrentBufferLocked(void );



static inline void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__lockCurrentBuffer(void );








static inline void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__unlockBuffer(uint8_t which);








static inline void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveBufferSwap(void );




static inline error_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__ReceiveBytePacket__startPacket(void );
#line 244
static inline void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__ReceiveBytePacket__byteReceived(uint8_t b);
#line 275
static inline void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTask__runTask(void );
#line 296
static void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__ReceiveBytePacket__endPacket(error_t result);
#line 358
static inline uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__default__offset(uart_id_t id);


static inline uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__default__dataLinkLength(uart_id_t id, message_t *msg, 
uint8_t upperLen);


static inline uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__default__upperLength(uart_id_t id, message_t *msg, 
uint8_t dataLinkLen);




static inline message_t */*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__Receive__default__receive(uart_id_t idxxx, message_t *msg, 
void *payload, 
uint8_t len);


static inline void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__Send__default__sendDone(uart_id_t idxxx, message_t *msg, error_t error);
# 48 "/opt/tinyos-2.x/tos/interfaces/UartStream.nc"
static error_t HdlcTranslateC__UartStream__send(
#line 44
uint8_t * buf, 



uint16_t len);
# 94 "/opt/tinyos-2.x/tos/lib/serial/SerialFrameComm.nc"
static void HdlcTranslateC__SerialFrameComm__dataReceived(uint8_t data);





static void HdlcTranslateC__SerialFrameComm__putDone(void );
#line 85
static void HdlcTranslateC__SerialFrameComm__delimiterReceived(void );
# 59 "/opt/tinyos-2.x/tos/lib/serial/HdlcTranslateC.nc"
#line 56
typedef struct HdlcTranslateC____nesc_unnamed4413 {
  uint8_t sendEscape : 1;
  uint8_t receiveEscape : 1;
} HdlcTranslateC__HdlcState;


HdlcTranslateC__HdlcState HdlcTranslateC__state = { 0, 0 };
uint8_t HdlcTranslateC__txTemp;
uint8_t HdlcTranslateC__m_data;


static inline void HdlcTranslateC__SerialFrameComm__resetReceive(void );





static inline void HdlcTranslateC__UartStream__receivedByte(uint8_t data);
#line 98
static error_t HdlcTranslateC__SerialFrameComm__putDelimiter(void );







static error_t HdlcTranslateC__SerialFrameComm__putData(uint8_t data);
#line 118
static inline void HdlcTranslateC__UartStream__sendDone(uint8_t *buf, uint16_t len, 
error_t error);
#line 132
static inline void HdlcTranslateC__UartStream__receiveDone(uint8_t *buf, uint16_t len, error_t error);
# 120 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
static error_t PlatformSerialP__Resource__release(void );
#line 97
static error_t PlatformSerialP__Resource__immediateRequest(void );
# 51 "/opt/tinyos-2.x/tos/platforms/surf/hardware/usci/PlatformSerialP.nc"
static inline error_t PlatformSerialP__StdControl__start(void );



static inline error_t PlatformSerialP__StdControl__stop(void );



static inline void PlatformSerialP__Resource__granted(void );
# 51 "/opt/tinyos-2.x/tos/lib/serial/SerialPacketInfoActiveMessageP.nc"
static inline uint8_t SerialPacketInfoActiveMessageP__Info__offset(void );


static inline uint8_t SerialPacketInfoActiveMessageP__Info__dataLinkLength(message_t *msg, uint8_t upperLen);


static inline uint8_t SerialPacketInfoActiveMessageP__Info__upperLength(message_t *msg, uint8_t dataLinkLen);
# 110 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static void /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__AMSend__sendDone(
#line 103
message_t * msg, 






error_t error);
# 75 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static error_t /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__Send__send(
#line 67
message_t * msg, 







uint8_t len);
#line 125
static 
#line 123
void * 

/*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__Send__getPayload(
#line 122
message_t * msg, 


uint8_t len);
# 103 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
static void /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__AMPacket__setDestination(
#line 99
message_t * amsg, 



am_addr_t addr);
#line 162
static void /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__AMPacket__setType(
#line 158
message_t * amsg, 



am_id_t t);
# 53 "/opt/tinyos-2.x/tos/system/AMQueueEntryP.nc"
static inline error_t /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__AMSend__send(am_addr_t dest, 
message_t *msg, 
uint8_t len);









static inline void /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__Send__sendDone(message_t *m, error_t err);







static inline void */*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__AMSend__getPayload(message_t *m, uint8_t len);
# 80 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
static error_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__AMSend__send(
# 48 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
am_id_t arg_0x40ab51b8, 
# 80 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
#line 135
static 
#line 133
void * 

/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__AMSend__getPayload(
# 48 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
am_id_t arg_0x40ab51b8, 
# 132 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
message_t * msg, 


uint8_t len);
# 100 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Send__sendDone(
# 46 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40ab77a8, 
# 96 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 78 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
static uint8_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Packet__payloadLength(
#line 74
message_t * msg);
#line 94
static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Packet__setPayloadLength(
#line 90
message_t * msg, 



uint8_t len);
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__errorTask__postTask(void );
# 78 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
static am_addr_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__AMPacket__destination(
#line 74
message_t * amsg);
#line 147
static am_id_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__AMPacket__type(
#line 143
message_t * amsg);
# 126 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
enum /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1____nesc_unnamed4414 {
#line 126
  AMQueueImplP__1__CancelTask = 36U
};
#line 126
typedef int /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1____nesc_sillytask_CancelTask[/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__CancelTask];
#line 169
enum /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1____nesc_unnamed4415 {
#line 169
  AMQueueImplP__1__errorTask = 37U
};
#line 169
typedef int /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1____nesc_sillytask_errorTask[/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__errorTask];
#line 57
#line 55
typedef struct /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1____nesc_unnamed4416 {
  message_t * msg;
} /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__queue_entry_t;

uint8_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__current = 1;
/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__queue_entry_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__queue[1];
uint8_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__cancelMask[1 / 8 + 1];

static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__tryToSend(void );

static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__nextPacket(void );
#line 90
static inline error_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Send__send(uint8_t clientId, message_t *msg, 
uint8_t len);
#line 126
static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__CancelTask__runTask(void );
#line 163
static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__sendDone(uint8_t last, message_t * msg, error_t err);





static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__errorTask__runTask(void );




static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__tryToSend(void );
#line 189
static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__AMSend__sendDone(am_id_t id, message_t *msg, error_t err);
#line 211
static inline void */*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Send__getPayload(uint8_t id, message_t *m, uint8_t len);



static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Send__default__sendDone(uint8_t id, message_t *msg, error_t err);
# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
static void HplMsp430InterruptP__Port14__fired(void );
#line 72
static void HplMsp430InterruptP__Port26__fired(void );
#line 72
static void HplMsp430InterruptP__Port17__fired(void );
#line 72
static void HplMsp430InterruptP__Port21__fired(void );
#line 72
static void HplMsp430InterruptP__Port12__fired(void );
#line 72
static void HplMsp430InterruptP__Port24__fired(void );
#line 72
static void HplMsp430InterruptP__Port15__fired(void );
#line 72
static void HplMsp430InterruptP__Port27__fired(void );
#line 72
static void HplMsp430InterruptP__Port10__fired(void );
#line 72
static void HplMsp430InterruptP__Port22__fired(void );
#line 72
static void HplMsp430InterruptP__Port13__fired(void );
#line 72
static void HplMsp430InterruptP__Port25__fired(void );
#line 72
static void HplMsp430InterruptP__Port16__fired(void );
#line 72
static void HplMsp430InterruptP__Port20__fired(void );
#line 72
static void HplMsp430InterruptP__Port11__fired(void );
#line 72
static void HplMsp430InterruptP__Port23__fired(void );
# 64 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
void sig_PORT1_VECTOR(void ) __attribute((wakeup)) __attribute((interrupt(0x62)))  ;
#line 78
static inline void HplMsp430InterruptP__Port10__default__fired(void );
static inline void HplMsp430InterruptP__Port11__default__fired(void );
static inline void HplMsp430InterruptP__Port12__default__fired(void );
static inline void HplMsp430InterruptP__Port13__default__fired(void );
static inline void HplMsp430InterruptP__Port14__default__fired(void );
static inline void HplMsp430InterruptP__Port15__default__fired(void );
static inline void HplMsp430InterruptP__Port16__default__fired(void );
static inline void HplMsp430InterruptP__Port17__default__fired(void );
#line 102
static inline void HplMsp430InterruptP__Port10__clear(void );
static inline void HplMsp430InterruptP__Port11__clear(void );
static inline void HplMsp430InterruptP__Port12__clear(void );
static inline void HplMsp430InterruptP__Port13__clear(void );
static inline void HplMsp430InterruptP__Port14__clear(void );
static inline void HplMsp430InterruptP__Port15__clear(void );
static inline void HplMsp430InterruptP__Port16__clear(void );
static inline void HplMsp430InterruptP__Port17__clear(void );
#line 169
void sig_PORT2_VECTOR(void ) __attribute((wakeup)) __attribute((interrupt(0x60)))  ;
#line 185
static inline void HplMsp430InterruptP__Port23__default__fired(void );
static inline void HplMsp430InterruptP__Port24__default__fired(void );
static inline void HplMsp430InterruptP__Port25__default__fired(void );
static inline void HplMsp430InterruptP__Port26__default__fired(void );
static inline void HplMsp430InterruptP__Port27__default__fired(void );
static inline void HplMsp430InterruptP__Port20__enable(void );
static inline void HplMsp430InterruptP__Port21__enable(void );
static inline void HplMsp430InterruptP__Port22__enable(void );





static inline void HplMsp430InterruptP__Port20__disable(void );
static inline void HplMsp430InterruptP__Port21__disable(void );
static inline void HplMsp430InterruptP__Port22__disable(void );





static inline void HplMsp430InterruptP__Port20__clear(void );
static inline void HplMsp430InterruptP__Port21__clear(void );
static inline void HplMsp430InterruptP__Port22__clear(void );
static inline void HplMsp430InterruptP__Port23__clear(void );
static inline void HplMsp430InterruptP__Port24__clear(void );
static inline void HplMsp430InterruptP__Port25__clear(void );
static inline void HplMsp430InterruptP__Port26__clear(void );
static inline void HplMsp430InterruptP__Port27__clear(void );








static inline void HplMsp430InterruptP__Port20__edge(bool l2h);





static inline void HplMsp430InterruptP__Port21__edge(bool l2h);





static inline void HplMsp430InterruptP__Port22__edge(bool l2h);
# 78 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void /*TestSenderAppC.NextPin*/Msp430GpioC__7__HplGeneralIO__makeInput(void );
# 52 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*TestSenderAppC.NextPin*/Msp430GpioC__7__GeneralIO__makeInput(void );
# 52 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
static void /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__HplInterrupt__clear(void );
#line 47
static void /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__HplInterrupt__disable(void );
#line 67
static void /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__HplInterrupt__edge(bool low_to_high);
#line 42
static void /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__HplInterrupt__enable(void );
# 68 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static void /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__Interrupt__fired(void );
# 52 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430InterruptC.nc"
static inline error_t /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__enable(bool rising);








static inline error_t /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__Interrupt__enableRisingEdge(void );







static inline error_t /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__Interrupt__disable(void );







static inline void /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__HplInterrupt__fired(void );
# 78 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void /*TestSenderAppC.SendReadyPin*/Msp430GpioC__8__HplGeneralIO__makeInput(void );
# 52 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*TestSenderAppC.SendReadyPin*/Msp430GpioC__8__GeneralIO__makeInput(void );
# 52 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
static void /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__HplInterrupt__clear(void );
#line 47
static void /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__HplInterrupt__disable(void );
#line 67
static void /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__HplInterrupt__edge(bool low_to_high);
#line 42
static void /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__HplInterrupt__enable(void );
# 68 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static void /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__Interrupt__fired(void );
# 52 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430InterruptC.nc"
static error_t /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__enable(bool rising);
#line 65
static inline error_t /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__Interrupt__enableFallingEdge(void );



static inline error_t /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__Interrupt__disable(void );







static inline void /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__HplInterrupt__fired(void );
# 78 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void /*TestSenderAppC.SendPin*/Msp430GpioC__9__HplGeneralIO__makeInput(void );
# 52 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*TestSenderAppC.SendPin*/Msp430GpioC__9__GeneralIO__makeInput(void );
# 52 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
static void /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__HplInterrupt__clear(void );
#line 47
static void /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__HplInterrupt__disable(void );
#line 67
static void /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__HplInterrupt__edge(bool low_to_high);
#line 42
static void /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__HplInterrupt__enable(void );
# 68 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
static void /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__Interrupt__fired(void );
# 52 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430InterruptC.nc"
static inline error_t /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__enable(bool rising);








static inline error_t /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__Interrupt__enableRisingEdge(void );







static inline error_t /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__Interrupt__disable(void );







static inline void /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__HplInterrupt__fired(void );
# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void /*TestSenderAppC.DebugPin*/Msp430GpioC__10__HplGeneralIO__makeOutput(void );
#line 48
static void /*TestSenderAppC.DebugPin*/Msp430GpioC__10__HplGeneralIO__set(void );




static void /*TestSenderAppC.DebugPin*/Msp430GpioC__10__HplGeneralIO__clr(void );
# 48 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*TestSenderAppC.DebugPin*/Msp430GpioC__10__GeneralIO__set(void );
static inline void /*TestSenderAppC.DebugPin*/Msp430GpioC__10__GeneralIO__clr(void );




static inline void /*TestSenderAppC.DebugPin*/Msp430GpioC__10__GeneralIO__makeOutput(void );
# 397 "/opt/tinyos-2.x/tos/chips/msp430/msp430hardware.h"
static inline  void __nesc_enable_interrupt(void )
{
   __asm volatile ("eint");}

# 141 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__currentMode(void )
{
  /* atomic removed: atomic calls only */
#line 143
  {
    if (!(* (volatile uint8_t * )(1472U + 0x01) & 0x01)) {
        {
          unsigned char __nesc_temp = 
#line 145
          MSP430_USCI_UART;

#line 145
          return __nesc_temp;
        }
      }
#line 147
    if (0x06 == (* (volatile uint8_t * )(1472U + 0x01) & (0x02 | 0x04))) {
        {
          unsigned char __nesc_temp = 
#line 148
          MSP430_USCI_I2C;

#line 148
          return __nesc_temp;
        }
      }
#line 150
    {
      unsigned char __nesc_temp = 
#line 150
      MSP430_USCI_SPI;

#line 150
      return __nesc_temp;
    }
  }
}

# 56 "/opt/tinyos-2.x/tos/lib/serial/SerialFrameComm.nc"
inline static error_t SerialP__SerialFrameComm__putDelimiter(void ){
#line 56
  unsigned char __nesc_result;
#line 56

#line 56
  __nesc_result = HdlcTranslateC__SerialFrameComm__putDelimiter();
#line 56

#line 56
  return __nesc_result;
#line 56
}
#line 56









inline static error_t SerialP__SerialFrameComm__putData(uint8_t data){
#line 65
  unsigned char __nesc_result;
#line 65

#line 65
  __nesc_result = HdlcTranslateC__SerialFrameComm__putData(data);
#line 65

#line 65
  return __nesc_result;
#line 65
}
#line 65
# 529 "/opt/tinyos-2.x/tos/lib/serial/SerialP.nc"
static inline error_t SerialP__SendBytePacket__completeSend(void )
#line 529
{
  bool ret = FAIL;

  /* atomic removed: atomic calls only */
#line 531
  {
    SerialP__txBuf[SerialP__TX_DATA_INDEX].state = SerialP__BUFFER_COMPLETE;
    ret = SUCCESS;
  }
  return ret;
}

# 71 "/opt/tinyos-2.x/tos/lib/serial/SendBytePacket.nc"
inline static error_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__SendBytePacket__completeSend(void ){
#line 71
  unsigned char __nesc_result;
#line 71

#line 71
  __nesc_result = SerialP__SendBytePacket__completeSend();
#line 71

#line 71
  return __nesc_result;
#line 71
}
#line 71
# 178 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
static inline uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__SendBytePacket__nextByte(void )
#line 178
{
  uint8_t b;
  uint8_t indx;

  /* atomic removed: atomic calls only */
#line 181
  {
    b = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendBuffer[/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendIndex];
    /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendIndex++;
    indx = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendIndex;
  }
  if (indx > /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendLen) {
      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__SendBytePacket__completeSend();
      return 0;
    }
  else {
      return b;
    }
}

# 81 "/opt/tinyos-2.x/tos/lib/serial/SendBytePacket.nc"
inline static uint8_t SerialP__SendBytePacket__nextByte(void ){
#line 81
  unsigned char __nesc_result;
#line 81

#line 81
  __nesc_result = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__SendBytePacket__nextByte();
#line 81

#line 81
  return __nesc_result;
#line 81
}
#line 81
# 668 "/opt/tinyos-2.x/tos/lib/serial/SerialP.nc"
static inline void SerialP__SerialFrameComm__putDone(void )
#line 668
{
  {
    error_t txResult = SUCCESS;

    /* atomic removed: atomic calls only */
#line 671
    {
      switch (SerialP__txState) {

          case SerialP__TXSTATE_PROTO: 

            txResult = SerialP__SerialFrameComm__putData(SerialP__txProto);

          SerialP__txState = SerialP__TXSTATE_INFO;



          SerialP__txCRC = crcByte(SerialP__txCRC, SerialP__txProto);
          break;

          case SerialP__TXSTATE_SEQNO: 
            txResult = SerialP__SerialFrameComm__putData(SerialP__txSeqno);
          SerialP__txState = SerialP__TXSTATE_INFO;
          SerialP__txCRC = crcByte(SerialP__txCRC, SerialP__txSeqno);
          break;

          case SerialP__TXSTATE_INFO: 
            {
              txResult = SerialP__SerialFrameComm__putData(SerialP__txBuf[SerialP__txIndex].buf);
              SerialP__txCRC = crcByte(SerialP__txCRC, SerialP__txBuf[SerialP__txIndex].buf);
              ++SerialP__txByteCnt;

              if (SerialP__txIndex == SerialP__TX_DATA_INDEX) {
                  uint8_t nextByte;

#line 699
                  nextByte = SerialP__SendBytePacket__nextByte();
                  if (SerialP__txBuf[SerialP__txIndex].state == SerialP__BUFFER_COMPLETE || SerialP__txByteCnt >= SerialP__SERIAL_MTU) {
                      SerialP__txState = SerialP__TXSTATE_FCS1;
                    }
                  else {
                      SerialP__txBuf[SerialP__txIndex].buf = nextByte;
                    }
                }
              else {
                  SerialP__txState = SerialP__TXSTATE_FCS1;
                }
            }
          break;

          case SerialP__TXSTATE_FCS1: 
            txResult = SerialP__SerialFrameComm__putData(SerialP__txCRC & 0xff);
          SerialP__txState = SerialP__TXSTATE_FCS2;
          break;

          case SerialP__TXSTATE_FCS2: 
            txResult = SerialP__SerialFrameComm__putData((SerialP__txCRC >> 8) & 0xff);
          SerialP__txState = SerialP__TXSTATE_ENDFLAG;
          break;

          case SerialP__TXSTATE_ENDFLAG: 
            txResult = SerialP__SerialFrameComm__putDelimiter();
          SerialP__txState = SerialP__TXSTATE_ENDWAIT;
          break;

          case SerialP__TXSTATE_ENDWAIT: 
            SerialP__txState = SerialP__TXSTATE_FINISH;
          case SerialP__TXSTATE_FINISH: 
            SerialP__MaybeScheduleTx();
          break;
          case SerialP__TXSTATE_ERROR: 
            default: 
              txResult = FAIL;
          break;
        }

      if (txResult != SUCCESS) {
          SerialP__txState = SerialP__TXSTATE_ERROR;
          SerialP__MaybeScheduleTx();
        }
    }
  }
}

# 100 "/opt/tinyos-2.x/tos/lib/serial/SerialFrameComm.nc"
inline static void HdlcTranslateC__SerialFrameComm__putDone(void ){
#line 100
  SerialP__SerialFrameComm__putDone();
#line 100
}
#line 100
# 48 "/opt/tinyos-2.x/tos/interfaces/UartStream.nc"
inline static error_t HdlcTranslateC__UartStream__send(uint8_t * buf, uint16_t len){
#line 48
  unsigned char __nesc_result;
#line 48

#line 48
  __nesc_result = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__send(/*PlatformSerialC.UartC*/Msp430UsciUartA0C__0__CLIENT_ID, buf, len);
#line 48

#line 48
  return __nesc_result;
#line 48
}
#line 48
# 118 "/opt/tinyos-2.x/tos/lib/serial/HdlcTranslateC.nc"
static inline void HdlcTranslateC__UartStream__sendDone(uint8_t *buf, uint16_t len, 
error_t error)
#line 119
{
  /* atomic removed: atomic calls only */
#line 120
  {
    if (HdlcTranslateC__state.sendEscape) {
        HdlcTranslateC__state.sendEscape = 0;
        HdlcTranslateC__m_data = HdlcTranslateC__txTemp;
        HdlcTranslateC__UartStream__send(&HdlcTranslateC__m_data, 1);
      }
    else {
        HdlcTranslateC__SerialFrameComm__putDone();
      }
  }
}

# 226 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__default__sendDone(uint8_t client, uint8_t *buf, uint16_t len, error_t error)
#line 226
{
}

# 57 "/opt/tinyos-2.x/tos/interfaces/UartStream.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__sendDone(uint8_t arg_0x40767010, uint8_t * buf, uint16_t len, error_t error){
#line 57
  switch (arg_0x40767010) {
#line 57
    case /*PlatformSerialC.UartC*/Msp430UsciUartA0C__0__CLIENT_ID:
#line 57
      HdlcTranslateC__UartStream__sendDone(buf, len, error);
#line 57
      break;
#line 57
    default:
#line 57
      /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__default__sendDone(arg_0x40767010, buf, len, error);
#line 57
      break;
#line 57
    }
#line 57
}
#line 57
# 95 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__setTxbuf(uint8_t v)
#line 95
{
#line 95
  * (volatile uint8_t * )(1472U + 0x0e) = v;
}

# 141 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__setTxbuf(uint8_t v){
#line 141
  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__setTxbuf(v);
#line 141
}
#line 141
# 110 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__getIe(void )
#line 110
{
#line 110
  return * (volatile uint8_t * )(1472U + 0x1c);
}

# 231 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static uint8_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__getIe(void ){
#line 231
  unsigned char __nesc_result;
#line 231

#line 231
  __nesc_result = /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__getIe();
#line 231

#line 231
  return __nesc_result;
#line 231
}
#line 231
# 111 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__setIe(uint8_t v)
#line 111
{
#line 111
  * (volatile uint8_t * )(1472U + 0x1c) = v;
}

# 237 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__setIe(uint8_t v){
#line 237
  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__setIe(v);
#line 237
}
#line 237
# 180 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__nextStreamTransmit(uint8_t client)
{
  /* atomic removed: atomic calls only */
#line 182
  {
    uint8_t ch = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_tx_buf[/*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_tx_pos++];
    bool last_char = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_tx_pos == /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_tx_len;

    if (last_char) {



        /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__setIe(/*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__getIe() & ~0x0002);
      }
    /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__setTxbuf(ch);



    if (last_char) {
        uint8_t *tx_buf = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_tx_buf;
        uint16_t tx_len = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_tx_len;

#line 199
        /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_tx_buf = 0;
        /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__sendDone(client, tx_buf, tx_len, SUCCESS);
      }
  }
}

# 397 "/opt/tinyos-2.x/tos/lib/serial/SerialP.nc"
static inline void SerialP__SerialFrameComm__dataReceived(uint8_t data)
#line 397
{
  SerialP__rx_state_machine(FALSE, data);
}

# 94 "/opt/tinyos-2.x/tos/lib/serial/SerialFrameComm.nc"
inline static void HdlcTranslateC__SerialFrameComm__dataReceived(uint8_t data){
#line 94
  SerialP__SerialFrameComm__dataReceived(data);
#line 94
}
#line 94
# 394 "/opt/tinyos-2.x/tos/lib/serial/SerialP.nc"
static inline void SerialP__SerialFrameComm__delimiterReceived(void )
#line 394
{
  SerialP__rx_state_machine(TRUE, 0);
}

# 85 "/opt/tinyos-2.x/tos/lib/serial/SerialFrameComm.nc"
inline static void HdlcTranslateC__SerialFrameComm__delimiterReceived(void ){
#line 85
  SerialP__SerialFrameComm__delimiterReceived();
#line 85
}
#line 85
# 73 "/opt/tinyos-2.x/tos/lib/serial/HdlcTranslateC.nc"
static inline void HdlcTranslateC__UartStream__receivedByte(uint8_t data)
#line 73
{






  if (data == HDLC_FLAG_BYTE) {

      HdlcTranslateC__SerialFrameComm__delimiterReceived();
      return;
    }
  else {
#line 85
    if (data == HDLC_CTLESC_BYTE) {

        HdlcTranslateC__state.receiveEscape = 1;
        return;
      }
    else {
#line 90
      if (HdlcTranslateC__state.receiveEscape) {

          HdlcTranslateC__state.receiveEscape = 0;
          data = data ^ 0x20;
        }
      }
    }
#line 95
  HdlcTranslateC__SerialFrameComm__dataReceived(data);
}

# 267 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__default__receivedByte(uint8_t client, uint8_t byte)
#line 267
{
}

# 79 "/opt/tinyos-2.x/tos/interfaces/UartStream.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__receivedByte(uint8_t arg_0x40767010, uint8_t byte){
#line 79
  switch (arg_0x40767010) {
#line 79
    case /*PlatformSerialC.UartC*/Msp430UsciUartA0C__0__CLIENT_ID:
#line 79
      HdlcTranslateC__UartStream__receivedByte(byte);
#line 79
      break;
#line 79
    default:
#line 79
      /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__default__receivedByte(arg_0x40767010, byte);
#line 79
      break;
#line 79
    }
#line 79
}
#line 79
# 132 "/opt/tinyos-2.x/tos/lib/serial/HdlcTranslateC.nc"
static inline void HdlcTranslateC__UartStream__receiveDone(uint8_t *buf, uint16_t len, error_t error)
#line 132
{
}

# 289 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__default__receiveDone(uint8_t client, uint8_t *buf, uint16_t len, error_t error)
#line 289
{
}

# 99 "/opt/tinyos-2.x/tos/interfaces/UartStream.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__receiveDone(uint8_t arg_0x40767010, uint8_t * buf, uint16_t len, error_t error){
#line 99
  switch (arg_0x40767010) {
#line 99
    case /*PlatformSerialC.UartC*/Msp430UsciUartA0C__0__CLIENT_ID:
#line 99
      HdlcTranslateC__UartStream__receiveDone(buf, len, error);
#line 99
      break;
#line 99
    default:
#line 99
      /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__default__receiveDone(arg_0x40767010, buf, len, error);
#line 99
      break;
#line 99
    }
#line 99
}
#line 99
# 404 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Msp430UsciError__default__condition(uint8_t client, unsigned int errors)
#line 404
{
}

# 42 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciError.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Msp430UsciError__condition(uint8_t arg_0x40766bb0, unsigned int errors){
#line 42
    /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Msp430UsciError__default__condition(arg_0x40766bb0, errors);
#line 42
}
#line 42
# 90 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__getStat(void )
#line 90
{
#line 90
  return * (volatile uint8_t * )(1472U + 0x0a);
}

# 111 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static uint8_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__getStat(void ){
#line 111
  unsigned char __nesc_result;
#line 111

#line 111
  __nesc_result = /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__getStat();
#line 111

#line 111
  return __nesc_result;
#line 111
}
#line 111
# 92 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__getRxbuf(void )
#line 92
{
#line 92
  return * (volatile uint8_t * )(1472U + 0x0c);
}

# 123 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static uint8_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__getRxbuf(void ){
#line 123
  unsigned char __nesc_result;
#line 123

#line 123
  __nesc_result = /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__getRxbuf();
#line 123

#line 123
  return __nesc_result;
#line 123
}
#line 123
# 98 "/opt/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
inline static uint8_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__ArbiterInfo__userId(void ){
#line 98
  unsigned char __nesc_result;
#line 98

#line 98
  __nesc_result = /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ArbiterInfo__userId();
#line 98

#line 98
  return __nesc_result;
#line 98
}
#line 98
# 354 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Interrupts__interrupted(uint8_t iv)
#line 354
{
  uint8_t current_client = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__ArbiterInfo__userId();

#line 356
  if (0xFF == current_client) {
      return;
    }
  if (0x0002 == iv) {
      uint8_t stat = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__getStat();
      uint8_t data = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__getRxbuf();






      stat = MSP430_USCI_ERR_UCxySTAT & (stat | /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__getStat());
      if (stat) {
          /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Msp430UsciError__condition(current_client, stat);
        }
      if (/*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_rx_buf) {
          /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_rx_buf[/*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_rx_pos++] = data;
          if (/*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_rx_len == /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_rx_pos) {
              uint8_t *rx_buf = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_rx_buf;
              uint16_t rx_len = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_rx_len;

#line 377
              /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_rx_buf = 0;
              /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__receiveDone(current_client, rx_buf, rx_len, SUCCESS);
            }
        }
      else 
#line 380
        {
          /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__receivedByte(current_client, data);
        }
    }
  else {
#line 383
    if (0x0004 == iv) {
        /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__nextStreamTransmit(current_client);
      }
    }
}

# 164 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Interrupts__default__interrupted(uint8_t mode, uint8_t iv)
#line 164
{
}

# 49 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
inline static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Interrupts__interrupted(uint8_t arg_0x406d6010, uint8_t iv){
#line 49
  switch (arg_0x406d6010) {
#line 49
    case MSP430_USCI_UART:
#line 49
      /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Interrupts__interrupted(iv);
#line 49
      break;
#line 49
    default:
#line 49
      /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Interrupts__default__interrupted(arg_0x406d6010, iv);
#line 49
      break;
#line 49
    }
#line 49
}
#line 49
# 153 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
static inline bool /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ArbiterInfo__inUse(void )
#line 153
{
  /* atomic removed: atomic calls only */
#line 154
  {
    if (/*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__state == /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__RES_CONTROLLED) 
      {
        unsigned char __nesc_temp = 
#line 156
        FALSE;

#line 156
        return __nesc_temp;
      }
  }
#line 158
  return TRUE;
}

# 90 "/opt/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
inline static bool /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__ArbiterInfo__inUse(void ){
#line 90
  unsigned char __nesc_result;
#line 90

#line 90
  __nesc_result = /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ArbiterInfo__inUse();
#line 90

#line 90
  return __nesc_result;
#line 90
}
#line 90
# 157 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__RawInterrupts__interrupted(uint8_t iv)
{
  if (/*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__ArbiterInfo__inUse()) {
      /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Interrupts__interrupted(/*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__currentMode(), iv);
    }
}

# 49 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
inline static void HplMsp430UsciInterruptsA0P__Interrupts__interrupted(uint8_t iv){
#line 49
  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__RawInterrupts__interrupted(iv);
#line 49
}
#line 49
# 401 "/opt/tinyos-2.x/tos/lib/serial/SerialP.nc"
static inline bool SerialP__valid_rx_proto(uint8_t proto)
#line 401
{
  switch (proto) {
      case SERIAL_PROTO_PACKET_ACK: 
        return TRUE;
      case SERIAL_PROTO_ACK: 
        case SERIAL_PROTO_PACKET_NOACK: 
          default: 
            return FALSE;
    }
}

# 203 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
static inline void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__lockCurrentBuffer(void )
#line 203
{
  if (/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveState.which) {
      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveState.bufOneLocked = 1;
    }
  else {
      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveState.bufZeroLocked = 1;
    }
}

#line 199
static inline bool /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__isCurrentBufferLocked(void )
#line 199
{
  return /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveState.which ? /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveState.bufOneLocked : /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveState.bufZeroLocked;
}

#line 226
static inline error_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__ReceiveBytePacket__startPacket(void )
#line 226
{
  error_t result = SUCCESS;

  /* atomic removed: atomic calls only */
#line 228
  {
    if (!/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__isCurrentBufferLocked()) {


        /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__lockCurrentBuffer();
        /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveState.state = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__RECV_STATE_BEGIN;
        /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__recvIndex = 0;
        /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__recvType = TOS_SERIAL_UNKNOWN_ID;
      }
    else {
        result = EBUSY;
      }
  }
  return result;
}

# 62 "/opt/tinyos-2.x/tos/lib/serial/ReceiveBytePacket.nc"
inline static error_t SerialP__ReceiveBytePacket__startPacket(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__ReceiveBytePacket__startPacket();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 311 "/opt/tinyos-2.x/tos/lib/serial/SerialP.nc"
static __inline uint16_t SerialP__rx_current_crc(void )
#line 311
{
  uint16_t crc;
  uint8_t tmp = SerialP__rxBuf.writePtr;

#line 314
  tmp = tmp == 0 ? SerialP__RX_DATA_BUFFER_SIZE : tmp - 1;
  crc = SerialP__rxBuf.buf[tmp] & 0x00ff;
  crc = (crc << 8) & 0xFF00;
  tmp = tmp == 0 ? SerialP__RX_DATA_BUFFER_SIZE : tmp - 1;
  crc |= SerialP__rxBuf.buf[tmp] & 0x00FF;
  return crc;
}

# 80 "/opt/tinyos-2.x/tos/lib/serial/ReceiveBytePacket.nc"
inline static void SerialP__ReceiveBytePacket__endPacket(error_t result){
#line 80
  /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__ReceiveBytePacket__endPacket(result);
#line 80
}
#line 80
# 221 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
static inline void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveBufferSwap(void )
#line 221
{
  /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveState.which = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveState.which ? 0 : 1;
  /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveBuffer = (uint8_t *)/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__messagePtrs[/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveState.which];
}

# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 97 "/opt/tinyos-2.x/tos/system/SchedulerBasicP.nc"
static inline bool SchedulerBasicP__isWaiting(uint8_t id)
{
  return SchedulerBasicP__m_next[id] != SchedulerBasicP__NO_TASK || SchedulerBasicP__m_tail == id;
}

static inline bool SchedulerBasicP__pushTask(uint8_t id)
{
  if (!SchedulerBasicP__isWaiting(id)) 
    {
      if (SchedulerBasicP__m_head == SchedulerBasicP__NO_TASK) 
        {
          SchedulerBasicP__m_head = id;
          SchedulerBasicP__m_tail = id;
        }
      else 
        {
          SchedulerBasicP__m_next[SchedulerBasicP__m_tail] = id;
          SchedulerBasicP__m_tail = id;
        }
      return TRUE;
    }
  else 
    {
      return FALSE;
    }
}

# 234 "/opt/tinyos-2.x/tos/lib/serial/SerialP.nc"
static __inline bool SerialP__ack_queue_is_full(void )
#line 234
{
  uint8_t tmp;
#line 235
  uint8_t tmp2;

  /* atomic removed: atomic calls only */
#line 236
  {
    tmp = SerialP__ackQ.writePtr;
    tmp2 = SerialP__ackQ.readPtr;
  }
  if (++tmp > SerialP__ACK_QUEUE_SIZE) {
#line 240
    tmp = 0;
    }
#line 241
  return tmp == tmp2;
}







static __inline void SerialP__ack_queue_push(uint8_t token)
#line 250
{
  if (!SerialP__ack_queue_is_full()) {
      /* atomic removed: atomic calls only */
#line 252
      {
        SerialP__ackQ.buf[SerialP__ackQ.writePtr] = token;
        if (++ SerialP__ackQ.writePtr > SerialP__ACK_QUEUE_SIZE) {
#line 254
          SerialP__ackQ.writePtr = 0;
          }
      }
#line 256
      SerialP__MaybeScheduleTx();
    }
}

# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t SerialP__RunTx__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(SerialP__RunTx);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 67 "/opt/tinyos-2.x/tos/lib/serial/HdlcTranslateC.nc"
static inline void HdlcTranslateC__SerialFrameComm__resetReceive(void )
#line 67
{
  HdlcTranslateC__state.receiveEscape = 0;
}

# 79 "/opt/tinyos-2.x/tos/lib/serial/SerialFrameComm.nc"
inline static void SerialP__SerialFrameComm__resetReceive(void ){
#line 79
  HdlcTranslateC__SerialFrameComm__resetReceive();
#line 79
}
#line 79
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t SerialP__stopDoneTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(SerialP__stopDoneTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 51 "/opt/tinyos-2.x/tos/lib/serial/SerialPacketInfoActiveMessageP.nc"
static inline uint8_t SerialPacketInfoActiveMessageP__Info__offset(void )
#line 51
{
  return (uint8_t )(sizeof(message_header_t ) - sizeof(serial_header_t ));
}

# 358 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
static inline uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__default__offset(uart_id_t id)
#line 358
{
  return 0;
}

# 15 "/opt/tinyos-2.x/tos/lib/serial/SerialPacketInfo.nc"
inline static uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__offset(uart_id_t arg_0x4110b088){
#line 15
  unsigned char __nesc_result;
#line 15

#line 15
  switch (arg_0x4110b088) {
#line 15
    case TOS_SERIAL_ACTIVE_MESSAGE_ID:
#line 15
      __nesc_result = SerialPacketInfoActiveMessageP__Info__offset();
#line 15
      break;
#line 15
    default:
#line 15
      __nesc_result = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__default__offset(arg_0x4110b088);
#line 15
      break;
#line 15
    }
#line 15

#line 15
  return __nesc_result;
#line 15
}
#line 15
# 244 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
static inline void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__ReceiveBytePacket__byteReceived(uint8_t b)
#line 244
{
  /* atomic removed: atomic calls only */
#line 245
  {
    switch (/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveState.state) {
        case /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__RECV_STATE_BEGIN: 
          /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveState.state = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__RECV_STATE_DATA;
        /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__recvIndex = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__offset(b);
        /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__recvType = b;
        break;

        case /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__RECV_STATE_DATA: 
          if (/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__recvIndex < sizeof(message_t )) {
              /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveBuffer[/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__recvIndex] = b;
              /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__recvIndex++;
            }
          else {
            }




        break;

        case /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__RECV_STATE_IDLE: 
          default: 
#line 266
            ;
      }
  }
}

# 69 "/opt/tinyos-2.x/tos/lib/serial/ReceiveBytePacket.nc"
inline static void SerialP__ReceiveBytePacket__byteReceived(uint8_t data){
#line 69
  /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__ReceiveBytePacket__byteReceived(data);
#line 69
}
#line 69
# 301 "/opt/tinyos-2.x/tos/lib/serial/SerialP.nc"
static __inline uint8_t SerialP__rx_buffer_top(void )
#line 301
{
  uint8_t tmp = SerialP__rxBuf.buf[SerialP__rxBuf.readPtr];

#line 303
  return tmp;
}

#line 305
static __inline uint8_t SerialP__rx_buffer_pop(void )
#line 305
{
  uint8_t tmp = SerialP__rxBuf.buf[SerialP__rxBuf.readPtr];

#line 307
  if (++ SerialP__rxBuf.readPtr > SerialP__RX_DATA_BUFFER_SIZE) {
#line 307
    SerialP__rxBuf.readPtr = 0;
    }
#line 308
  return tmp;
}

#line 297
static __inline void SerialP__rx_buffer_push(uint8_t data)
#line 297
{
  SerialP__rxBuf.buf[SerialP__rxBuf.writePtr] = data;
  if (++ SerialP__rxBuf.writePtr > SerialP__RX_DATA_BUFFER_SIZE) {
#line 299
    SerialP__rxBuf.writePtr = 0;
    }
}

# 111 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
static inline error_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__checkIsOwner(uint8_t client)
{

  const uint8_t current_client = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__ArbiterInfo__userId();

#line 115
  if (0xFF == current_client) {
      return EOFF;
    }
  if (current_client != client) {
      return EBUSY;
    }
  return SUCCESS;
}

#line 101
static inline bool /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__isBusy(void )
{
  while (0x01 & /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__getStat()) {
      ;
    }
  return 0 != /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_tx_buf || 0 != /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_rx_buf;
}

# 114 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__getIv(void )
#line 114
{
#line 114
  return * (volatile uint16_t * )(1472U + 0x1e);
}

# 256 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static uint8_t HplMsp430UsciInterruptsA0P__Usci__getIv(void ){
#line 256
  unsigned char __nesc_result;
#line 256

#line 256
  __nesc_result = /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__getIv();
#line 256

#line 256
  return __nesc_result;
#line 256
}
#line 256
# 126 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static inline void /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__VectorTimerX0__fired(void )
{
  /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Event__fired(0);
}

# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
inline static void Msp430TimerCommonP__VectorTimer0_A0__fired(void ){
#line 39
  /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__VectorTimerX0__fired();
#line 39
}
#line 39
# 196 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline void /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Timer__overflow(void )
{
}

#line 196
static inline void /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Timer__overflow(void )
{
}

#line 196
static inline void /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Timer__overflow(void )
{
}

#line 196
static inline void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Timer__overflow(void )
{
}

#line 196
static inline void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Timer__overflow(void )
{
}

# 114 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430AlarmC.nc"
static inline void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430Timer__overflow(void )
{
}

#line 114
static inline void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Timer__overflow(void )
{
}

# 58 "/opt/tinyos-2.x/tos/lib/timer/CounterToLocalTimeC.nc"
static inline void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__Counter__overflow(void )
{
}

# 177 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static inline void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Counter__overflow(void )
{
}

# 82 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
inline static void /*CounterMilli32C.Transform*/TransformCounterC__0__Counter__overflow(void ){
#line 82
  /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Counter__overflow();
#line 82
  /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__Counter__overflow();
#line 82
}
#line 82
# 133 "/opt/tinyos-2.x/tos/lib/timer/TransformCounterC.nc"
static inline void /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__overflow(void )
{
  /* atomic removed: atomic calls only */
  {
    /*CounterMilli32C.Transform*/TransformCounterC__0__m_upper++;
    if ((/*CounterMilli32C.Transform*/TransformCounterC__0__m_upper & /*CounterMilli32C.Transform*/TransformCounterC__0__OVERFLOW_MASK) == 0) {
      /*CounterMilli32C.Transform*/TransformCounterC__0__Counter__overflow();
      }
  }
}

# 82 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
inline static void /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__overflow(void ){
#line 82
  /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__overflow();
#line 82
}
#line 82
# 64 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430CounterC.nc"
static inline void /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__overflow(void )
{
  /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__overflow();
}

# 48 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
inline static void /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Timer__overflow(void ){
#line 48
  /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__overflow();
#line 48
  /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Timer__overflow();
#line 48
  /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430Timer__overflow();
#line 48
  /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Timer__overflow();
#line 48
  /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Timer__overflow();
#line 48
  /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Timer__overflow();
#line 48
  /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Timer__overflow();
#line 48
  /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Timer__overflow();
#line 48
}
#line 48
# 137 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static inline void /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Overflow__fired(void )
{
  /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Timer__overflow();
}

# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 81 "/opt/tinyos-2.x/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__fired(void )
{
#line 82
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__postTask();
}

# 78 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__fired(void ){
#line 78
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__fired();
#line 78
}
#line 78
# 162 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static inline void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__fired(void )
{
  /* atomic removed: atomic calls only */
  {
    if (/*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__m_dt == 0) 
      {
        /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__fired();
      }
    else 
      {
        /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__set_alarm();
      }
  }
}

# 78 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__fired(void ){
#line 78
  /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__fired();
#line 78
}
#line 78
# 135 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Control__disableEvents(void )
{
  * (volatile uint16_t * )834U &= ~0x0010;
}

# 58 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
inline static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430TimerControl__disableEvents(void ){
#line 58
  /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Control__disableEvents();
#line 58
}
#line 58
# 70 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430AlarmC.nc"
static inline void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Compare__fired(void )
{
  /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430TimerControl__disableEvents();
  /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__fired();
}

# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Compare__fired(void ){
#line 45
  /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Compare__fired();
#line 45
}
#line 45
# 150 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline uint16_t /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Capture__getEvent(void )
{
  return * (volatile uint16_t * )850U;
}

#line 188
static inline void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Capture__default__captured(uint16_t n)
{
}

# 86 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
inline static void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Capture__captured(uint16_t time){
#line 86
  /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Capture__default__captured(time);
#line 86
}
#line 86
# 58 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline  /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__cc_t /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__int2CC(uint16_t x)
#line 58
{
#line 58
  union /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0____nesc_unnamed4417 {
#line 58
    uint16_t f;
#line 58
    /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__cc_t t;
  } 
#line 58
  c = { .f = x };

#line 58
  return c.t;
}

#line 85
static inline /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__cc_t /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Control__getControl(void )
{
  return /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__int2CC(* (volatile uint16_t * )834U);
}

#line 180
static inline void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Event__fired(void )
{
  if (/*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Control__getControl().cap) {
    /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Capture__captured(/*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Capture__getEvent());
    }
  else {
#line 185
    /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Compare__fired();
    }
}

# 62 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static inline uint16_t /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Timer__get(void )
{




  if (0) {
      /* atomic removed: atomic calls only */
#line 69
      {
        uint16_t t0;
        uint16_t t1 = * (volatile uint16_t * )848U;

#line 72
        do {
#line 72
            t0 = t1;
#line 72
            t1 = * (volatile uint16_t * )848U;
          }
        while (
#line 72
        t0 != t1);
        {
          unsigned int __nesc_temp = 
#line 73
          t1;

#line 73
          return __nesc_temp;
        }
      }
    }
  else 
#line 76
    {
      return * (volatile uint16_t * )848U;
    }
}

# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
inline static uint16_t /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__get(void ){
#line 45
  unsigned int __nesc_result;
#line 45

#line 45
  __nesc_result = /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Timer__get();
#line 45

#line 45
  return __nesc_result;
#line 45
}
#line 45
# 49 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430CounterC.nc"
static inline uint16_t /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__get(void )
{
  return /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__get();
}

# 64 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
inline static /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__size_type /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__get(void ){
#line 64
  unsigned int __nesc_result;
#line 64

#line 64
  __nesc_result = /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__get();
#line 64

#line 64
  return __nesc_result;
#line 64
}
#line 64
# 81 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static inline bool /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Timer__isOverflowPending(void )
{
  return * (volatile uint16_t * )832U & 1U;
}

# 46 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
inline static bool /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__isOverflowPending(void ){
#line 46
  unsigned char __nesc_result;
#line 46

#line 46
  __nesc_result = /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Timer__isOverflowPending();
#line 46

#line 46
  return __nesc_result;
#line 46
}
#line 46
# 54 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430CounterC.nc"
static inline bool /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__isOverflowPending(void )
{
  return /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__isOverflowPending();
}

# 71 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
inline static bool /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__isOverflowPending(void ){
#line 71
  unsigned char __nesc_result;
#line 71

#line 71
  __nesc_result = /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__isOverflowPending();
#line 71

#line 71
  return __nesc_result;
#line 71
}
#line 71
# 130 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Control__enableEvents(void )
{
  * (volatile uint16_t * )834U |= 0x0010;
}

# 57 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
inline static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430TimerControl__enableEvents(void ){
#line 57
  /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Control__enableEvents();
#line 57
}
#line 57
# 95 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Control__clearPendingInterrupt(void )
{
  * (volatile uint16_t * )834U &= ~0x0001;
}

# 44 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
inline static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430TimerControl__clearPendingInterrupt(void ){
#line 44
  /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Control__clearPendingInterrupt();
#line 44
}
#line 44
# 155 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Compare__setEvent(uint16_t x)
{
  * (volatile uint16_t * )850U = x;
}

# 41 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Compare__setEvent(uint16_t time){
#line 41
  /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Compare__setEvent(time);
#line 41
}
#line 41
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
inline static uint16_t /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Timer__get(void ){
#line 45
  unsigned int __nesc_result;
#line 45

#line 45
  __nesc_result = /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Timer__get();
#line 45

#line 45
  return __nesc_result;
#line 45
}
#line 45
# 165 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline void /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Compare__setEventFromNow(uint16_t x)
{
  * (volatile uint16_t * )850U = /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Timer__get() + x;
}

# 43 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Compare__setEventFromNow(uint16_t delta){
#line 43
  /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Compare__setEventFromNow(delta);
#line 43
}
#line 43
# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
inline static uint16_t /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Timer__get(void ){
#line 45
  unsigned int __nesc_result;
#line 45

#line 45
  __nesc_result = /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Timer__get();
#line 45

#line 45
  return __nesc_result;
#line 45
}
#line 45
# 81 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430AlarmC.nc"
static inline void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__startAt(uint16_t t0, uint16_t dt)
{
  /* atomic removed: atomic calls only */
  {
    uint16_t now = /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Timer__get();
    uint16_t elapsed = now - t0;

#line 87
    if (elapsed >= dt) 
      {
        /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Compare__setEventFromNow(2);
      }
    else 
      {
        uint16_t remaining = dt - elapsed;

#line 94
        if (remaining <= 2) {
          /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Compare__setEventFromNow(2);
          }
        else {
#line 97
          /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Compare__setEvent(now + remaining);
          }
      }
#line 99
    /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430TimerControl__clearPendingInterrupt();
    /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430TimerControl__enableEvents();
  }
}

# 103 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__startAt(/*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__size_type t0, /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__size_type dt){
#line 103
  /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__startAt(t0, dt);
#line 103
}
#line 103
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ackWaitAlarmFired_task__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ackWaitAlarmFired_task);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 306 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/layers/Rf1aAckP.nc"
static inline void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckWaitAlarm__fired(void )
{
  /* atomic removed: atomic calls only */
#line 308
  {

    /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_state = (/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_state & ~/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__TX_S_MASK) | /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__TX_S_alarmFired;
  }
  /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ackWaitAlarmFired_task__postTask();
}

# 78 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__fired(void ){
#line 78
  /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckWaitAlarm__fired();
#line 78
}
#line 78
# 135 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Control__disableEvents(void )
{
  * (volatile uint16_t * )836U &= ~0x0010;
}

# 58 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
inline static void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430TimerControl__disableEvents(void ){
#line 58
  /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Control__disableEvents();
#line 58
}
#line 58
# 70 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430AlarmC.nc"
static inline void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430Compare__fired(void )
{
  /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430TimerControl__disableEvents();
  /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__fired();
}

# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Compare__fired(void ){
#line 45
  /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430Compare__fired();
#line 45
}
#line 45
# 150 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline uint16_t /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Capture__getEvent(void )
{
  return * (volatile uint16_t * )852U;
}

#line 188
static inline void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Capture__default__captured(uint16_t n)
{
}

# 86 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
inline static void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Capture__captured(uint16_t time){
#line 86
  /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Capture__default__captured(time);
#line 86
}
#line 86
# 58 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline  /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__cc_t /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__int2CC(uint16_t x)
#line 58
{
#line 58
  union /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1____nesc_unnamed4418 {
#line 58
    uint16_t f;
#line 58
    /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__cc_t t;
  } 
#line 58
  c = { .f = x };

#line 58
  return c.t;
}

#line 85
static inline /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__cc_t /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Control__getControl(void )
{
  return /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__int2CC(* (volatile uint16_t * )836U);
}

#line 180
static inline void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Event__fired(void )
{
  if (/*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Control__getControl().cap) {
    /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Capture__captured(/*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Capture__getEvent());
    }
  else {
#line 185
    /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Compare__fired();
    }
}




static inline void /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Compare__default__fired(void )
{
}

# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Compare__fired(void ){
#line 45
  /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Compare__default__fired();
#line 45
}
#line 45
# 150 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline uint16_t /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Capture__getEvent(void )
{
  return * (volatile uint16_t * )854U;
}

#line 188
static inline void /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Capture__default__captured(uint16_t n)
{
}

# 86 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
inline static void /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Capture__captured(uint16_t time){
#line 86
  /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Capture__default__captured(time);
#line 86
}
#line 86
# 58 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline  /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__cc_t /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__int2CC(uint16_t x)
#line 58
{
#line 58
  union /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2____nesc_unnamed4419 {
#line 58
    uint16_t f;
#line 58
    /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__cc_t t;
  } 
#line 58
  c = { .f = x };

#line 58
  return c.t;
}

#line 85
static inline /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__cc_t /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Control__getControl(void )
{
  return /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__int2CC(* (volatile uint16_t * )838U);
}

#line 180
static inline void /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Event__fired(void )
{
  if (/*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Control__getControl().cap) {
    /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Capture__captured(/*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Capture__getEvent());
    }
  else {
#line 185
    /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Compare__fired();
    }
}




static inline void /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Compare__default__fired(void )
{
}

# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Compare__fired(void ){
#line 45
  /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Compare__default__fired();
#line 45
}
#line 45
# 150 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline uint16_t /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Capture__getEvent(void )
{
  return * (volatile uint16_t * )856U;
}

#line 188
static inline void /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Capture__default__captured(uint16_t n)
{
}

# 86 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
inline static void /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Capture__captured(uint16_t time){
#line 86
  /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Capture__default__captured(time);
#line 86
}
#line 86
# 58 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline  /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__cc_t /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__int2CC(uint16_t x)
#line 58
{
#line 58
  union /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3____nesc_unnamed4420 {
#line 58
    uint16_t f;
#line 58
    /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__cc_t t;
  } 
#line 58
  c = { .f = x };

#line 58
  return c.t;
}

#line 85
static inline /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__cc_t /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Control__getControl(void )
{
  return /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__int2CC(* (volatile uint16_t * )840U);
}

#line 180
static inline void /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Event__fired(void )
{
  if (/*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Control__getControl().cap) {
    /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Capture__captured(/*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Capture__getEvent());
    }
  else {
#line 185
    /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Compare__fired();
    }
}




static inline void /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Compare__default__fired(void )
{
}

# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Compare__fired(void ){
#line 45
  /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Compare__default__fired();
#line 45
}
#line 45
# 150 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline uint16_t /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Capture__getEvent(void )
{
  return * (volatile uint16_t * )858U;
}

#line 188
static inline void /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Capture__default__captured(uint16_t n)
{
}

# 86 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
inline static void /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Capture__captured(uint16_t time){
#line 86
  /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Capture__default__captured(time);
#line 86
}
#line 86
# 58 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline  /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__cc_t /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__int2CC(uint16_t x)
#line 58
{
#line 58
  union /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4____nesc_unnamed4421 {
#line 58
    uint16_t f;
#line 58
    /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__cc_t t;
  } 
#line 58
  c = { .f = x };

#line 58
  return c.t;
}

#line 85
static inline /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__cc_t /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Control__getControl(void )
{
  return /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__int2CC(* (volatile uint16_t * )842U);
}

#line 180
static inline void /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Event__fired(void )
{
  if (/*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Control__getControl().cap) {
    /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Capture__captured(/*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Capture__getEvent());
    }
  else {
#line 185
    /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Compare__fired();
    }
}

# 131 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static inline void /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__VectorTimerX1__fired(void )
{
  uint8_t n = * (volatile uint16_t * )878U;

#line 134
  /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Event__fired(n >> 1);
}

# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
inline static void Msp430TimerCommonP__VectorTimer0_A1__fired(void ){
#line 39
  /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__VectorTimerX1__fired();
#line 39
}
#line 39
# 196 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline void /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Timer__overflow(void )
{
}

#line 196
static inline void /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Timer__overflow(void )
{
}

#line 196
static inline void /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Timer__overflow(void )
{
}

# 48 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
inline static void /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__Timer__overflow(void ){
#line 48
  /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Timer__overflow();
#line 48
  /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Timer__overflow();
#line 48
  /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Timer__overflow();
#line 48
}
#line 48
# 137 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static inline void /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__Overflow__fired(void )
{
  /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__Timer__overflow();
}





static inline void /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__Event__default__fired(uint8_t n)
{
}

# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
inline static void /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__Event__fired(uint8_t arg_0x4080e458){
#line 39
  switch (arg_0x4080e458) {
#line 39
    case 0:
#line 39
      /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Event__fired();
#line 39
      break;
#line 39
    case 1:
#line 39
      /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Event__fired();
#line 39
      break;
#line 39
    case 2:
#line 39
      /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Event__fired();
#line 39
      break;
#line 39
    case 7:
#line 39
      /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__Overflow__fired();
#line 39
      break;
#line 39
    default:
#line 39
      /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__Event__default__fired(arg_0x4080e458);
#line 39
      break;
#line 39
    }
#line 39
}
#line 39
# 126 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static inline void /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__VectorTimerX0__fired(void )
{
  /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__Event__fired(0);
}

# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
inline static void Msp430TimerCommonP__VectorTimer1_A0__fired(void ){
#line 39
  /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__VectorTimerX0__fired();
#line 39
}
#line 39
# 58 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline  /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__cc_t /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__int2CC(uint16_t x)
#line 58
{
#line 58
  union /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5____nesc_unnamed4422 {
#line 58
    uint16_t f;
#line 58
    /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__cc_t t;
  } 
#line 58
  c = { .f = x };

#line 58
  return c.t;
}

#line 85
static inline /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__cc_t /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Control__getControl(void )
{
  return /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__int2CC(* (volatile uint16_t * )898U);
}

#line 188
static inline void /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Capture__default__captured(uint16_t n)
{
}

# 86 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
inline static void /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Capture__captured(uint16_t time){
#line 86
  /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Capture__default__captured(time);
#line 86
}
#line 86
# 150 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline uint16_t /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Capture__getEvent(void )
{
  return * (volatile uint16_t * )914U;
}

#line 192
static inline void /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Compare__default__fired(void )
{
}

# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Compare__fired(void ){
#line 45
  /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Compare__default__fired();
#line 45
}
#line 45
# 58 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline  /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__cc_t /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__int2CC(uint16_t x)
#line 58
{
#line 58
  union /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6____nesc_unnamed4423 {
#line 58
    uint16_t f;
#line 58
    /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__cc_t t;
  } 
#line 58
  c = { .f = x };

#line 58
  return c.t;
}

#line 85
static inline /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__cc_t /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Control__getControl(void )
{
  return /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__int2CC(* (volatile uint16_t * )900U);
}

#line 188
static inline void /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Capture__default__captured(uint16_t n)
{
}

# 86 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
inline static void /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Capture__captured(uint16_t time){
#line 86
  /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Capture__default__captured(time);
#line 86
}
#line 86
# 150 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline uint16_t /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Capture__getEvent(void )
{
  return * (volatile uint16_t * )916U;
}

#line 192
static inline void /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Compare__default__fired(void )
{
}

# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Compare__fired(void ){
#line 45
  /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Compare__default__fired();
#line 45
}
#line 45
# 58 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline  /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__cc_t /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__int2CC(uint16_t x)
#line 58
{
#line 58
  union /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7____nesc_unnamed4424 {
#line 58
    uint16_t f;
#line 58
    /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__cc_t t;
  } 
#line 58
  c = { .f = x };

#line 58
  return c.t;
}

#line 85
static inline /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__cc_t /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Control__getControl(void )
{
  return /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__int2CC(* (volatile uint16_t * )902U);
}

#line 188
static inline void /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Capture__default__captured(uint16_t n)
{
}

# 86 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
inline static void /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Capture__captured(uint16_t time){
#line 86
  /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Capture__default__captured(time);
#line 86
}
#line 86
# 150 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline uint16_t /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Capture__getEvent(void )
{
  return * (volatile uint16_t * )918U;
}

#line 192
static inline void /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Compare__default__fired(void )
{
}

# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Compare__fired(void ){
#line 45
  /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Compare__default__fired();
#line 45
}
#line 45
# 131 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static inline void /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__VectorTimerX1__fired(void )
{
  uint8_t n = * (volatile uint16_t * )942U;

#line 134
  /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__Event__fired(n >> 1);
}

# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
inline static void Msp430TimerCommonP__VectorTimer1_A1__fired(void ){
#line 39
  /*Msp430TimerC.Msp430Timer1_A*/Msp430TimerP__1__VectorTimerX1__fired();
#line 39
}
#line 39
# 141 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline uint8_t /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__currentMode(void )
{
  /* atomic removed: atomic calls only */
#line 143
  {
    if (!(* (volatile uint8_t * )(1504U + 0x01) & 0x01)) {
        {
          unsigned char __nesc_temp = 
#line 145
          MSP430_USCI_UART;

#line 145
          return __nesc_temp;
        }
      }
#line 147
    if (0x06 == (* (volatile uint8_t * )(1504U + 0x01) & (0x02 | 0x04))) {
        {
          unsigned char __nesc_temp = 
#line 148
          MSP430_USCI_I2C;

#line 148
          return __nesc_temp;
        }
      }
#line 150
    {
      unsigned char __nesc_temp = 
#line 150
      MSP430_USCI_SPI;

#line 150
      return __nesc_temp;
    }
  }
}

#line 95
static inline void /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__setTxbuf(uint8_t v)
#line 95
{
#line 95
  * (volatile uint8_t * )(1504U + 0x0e) = v;
}

# 141 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static void /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__Usci__setTxbuf(uint8_t v){
#line 141
  /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__setTxbuf(v);
#line 141
}
#line 141
# 200 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/usci/Msp430UsciSpiP.nc"
static inline void /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__SpiPacket__default__sendDone(uint8_t client, uint8_t *txBuf, uint8_t *rxBuf, uint16_t len, error_t error)
#line 200
{
}

# 82 "/opt/tinyos-2.x/tos/interfaces/SpiPacket.nc"
inline static void /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__SpiPacket__sendDone(uint8_t arg_0x40968278, uint8_t * txBuf, uint8_t * rxBuf, uint16_t len, error_t error){
#line 82
    /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__SpiPacket__default__sendDone(arg_0x40968278, txBuf, rxBuf, len, error);
#line 82
}
#line 82
# 166 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
static inline uint8_t /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__ArbiterInfo__userId(void )
#line 166
{
  /* atomic removed: atomic calls only */
#line 167
  {
    if (/*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__state != /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__RES_BUSY) 
      {
        unsigned char __nesc_temp = 
#line 169
        /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__NO_RES;

#line 169
        return __nesc_temp;
      }
#line 170
    {
      unsigned char __nesc_temp = 
#line 170
      /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__resId;

#line 170
      return __nesc_temp;
    }
  }
}

# 98 "/opt/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
inline static uint8_t /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__ArbiterInfo__userId(void ){
#line 98
  unsigned char __nesc_result;
#line 98

#line 98
  __nesc_result = /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__ArbiterInfo__userId();
#line 98

#line 98
  return __nesc_result;
#line 98
}
#line 98
# 110 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline uint8_t /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__getIe(void )
#line 110
{
#line 110
  return * (volatile uint8_t * )(1504U + 0x1c);
}

# 231 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static uint8_t /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__Usci__getIe(void ){
#line 231
  unsigned char __nesc_result;
#line 231

#line 231
  __nesc_result = /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__getIe();
#line 231

#line 231
  return __nesc_result;
#line 231
}
#line 231
# 111 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline void /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__setIe(uint8_t v)
#line 111
{
#line 111
  * (volatile uint8_t * )(1504U + 0x1c) = v;
}

# 237 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static void /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__Usci__setIe(uint8_t v){
#line 237
  /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__setIe(v);
#line 237
}
#line 237
# 92 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline uint8_t /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__getRxbuf(void )
#line 92
{
#line 92
  return * (volatile uint8_t * )(1504U + 0x0c);
}

# 123 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static uint8_t /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__Usci__getRxbuf(void ){
#line 123
  unsigned char __nesc_result;
#line 123

#line 123
  __nesc_result = /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__getRxbuf();
#line 123

#line 123
  return __nesc_result;
#line 123
}
#line 123
# 90 "/opt/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
inline static bool /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__ArbiterInfo__inUse(void ){
#line 90
  unsigned char __nesc_result;
#line 90

#line 90
  __nesc_result = /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__ArbiterInfo__inUse();
#line 90

#line 90
  return __nesc_result;
#line 90
}
#line 90
# 202 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/usci/Msp430UsciSpiP.nc"
static inline void /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__Interrupts__interrupted(uint8_t iv)
{
  uint8_t current_client;

  if (!/*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__ArbiterInfo__inUse()) {
      return;
    }



  if (0x0002 == iv) 
    {

      if (/*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__m_rx_buf) {
        /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__m_rx_buf[/*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__m_pos] = /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__Usci__getRxbuf();
        }
      else {
#line 218
        /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__Usci__getRxbuf();
        }
      if (/*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__m_pos + 1 == /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__m_len) 
        {
          /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__Usci__setIe(/*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__Usci__getIe() & ~0x0001);

          current_client = /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__ArbiterInfo__userId();
          /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__SpiPacket__sendDone(current_client, /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__m_tx_buf, /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__m_rx_buf, /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__m_len, SUCCESS);
        }
      else 

        {
          /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__m_pos++;


          /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__Usci__setTxbuf(/*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__m_tx_buf ? /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__m_tx_buf[/*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__m_pos] : 0x00);
        }
    }
  else {
    if (0x0004 == iv) {
#line 237
        ;
      }
    }
}

# 164 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline void /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Interrupts__default__interrupted(uint8_t mode, uint8_t iv)
#line 164
{
}

# 49 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
inline static void /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Interrupts__interrupted(uint8_t arg_0x406d6010, uint8_t iv){
#line 49
  switch (arg_0x406d6010) {
#line 49
    case MSP430_USCI_SPI:
#line 49
      /*Msp430UsciSpiB0P.SpiC*/Msp430UsciSpiP__0__Interrupts__interrupted(iv);
#line 49
      break;
#line 49
    default:
#line 49
      /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Interrupts__default__interrupted(arg_0x406d6010, iv);
#line 49
      break;
#line 49
    }
#line 49
}
#line 49
# 90 "/opt/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
inline static bool /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__ArbiterInfo__inUse(void ){
#line 90
  unsigned char __nesc_result;
#line 90

#line 90
  __nesc_result = /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__ArbiterInfo__inUse();
#line 90

#line 90
  return __nesc_result;
#line 90
}
#line 90
# 157 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline void /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__RawInterrupts__interrupted(uint8_t iv)
{
  if (/*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__ArbiterInfo__inUse()) {
      /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Interrupts__interrupted(/*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__currentMode(), iv);
    }
}

# 49 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
inline static void HplMsp430UsciInterruptsB0P__Interrupts__interrupted(uint8_t iv){
#line 49
  /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__RawInterrupts__interrupted(iv);
#line 49
}
#line 49
# 114 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline uint8_t /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__getIv(void )
#line 114
{
#line 114
  return * (volatile uint16_t * )(1504U + 0x1e);
}

# 256 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static uint8_t HplMsp430UsciInterruptsB0P__Usci__getIv(void ){
#line 256
  unsigned char __nesc_result;
#line 256

#line 256
  __nesc_result = /*Msp430UsciB0P.UsciC.HplUsciP*/HplMsp430UsciP__1__Usci__getIv();
#line 256

#line 256
  return __nesc_result;
#line 256
}
#line 256
# 124 "/opt/tinyos-2.x/tos/system/SchedulerBasicP.nc"
static inline void SchedulerBasicP__Scheduler__init(void )
{
  /* atomic removed: atomic calls only */
  {
    memset((void *)SchedulerBasicP__m_next, SchedulerBasicP__NO_TASK, sizeof SchedulerBasicP__m_next);
    SchedulerBasicP__m_head = SchedulerBasicP__NO_TASK;
    SchedulerBasicP__m_tail = SchedulerBasicP__NO_TASK;
  }
}

# 57 "/opt/tinyos-2.x/tos/interfaces/Scheduler.nc"
inline static void RealMainP__Scheduler__init(void ){
#line 57
  SchedulerBasicP__Scheduler__init();
#line 57
}
#line 57
# 58 "/opt/tinyos-2.x/tos/platforms/bacon/PlatformP.nc"
static inline void PlatformP__uwait(uint16_t u)
#line 58
{
  uint16_t t0 = TA0R;

#line 60
  while (TA0R - t0 <= u) ;
}

#line 92
static inline error_t PlatformP__PeripheralInit__default__init(void )
#line 92
{
  return SUCCESS;
}

# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t PlatformP__PeripheralInit__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = PlatformP__PeripheralInit__default__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 55 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P17*/HplMsp430GeneralIORenP__7__IO__makeOutput(void )
#line 55
{
  /* atomic removed: atomic calls only */
#line 55
  * (volatile uint8_t * )516U |= 0x01 << 7;
}

# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void PlatformFlashInitP__CsnIO__makeOutput(void ){
#line 85
  /*HplMsp430GeneralIOC.P17*/HplMsp430GeneralIORenP__7__IO__makeOutput();
#line 85
}
#line 85
# 48 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P17*/HplMsp430GeneralIORenP__7__IO__set(void )
#line 48
{
  /* atomic removed: atomic calls only */
#line 48
  * (volatile uint8_t * )514U |= 0x01 << 7;
}

# 48 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void PlatformFlashInitP__CsnIO__set(void ){
#line 48
  /*HplMsp430GeneralIOC.P17*/HplMsp430GeneralIORenP__7__IO__set();
#line 48
}
#line 48
# 53 "/opt/tinyos-2.x/tos/platforms/surf/hardware/flash/PlatformFlashInitP.nc"
static inline error_t PlatformFlashInitP__Init__init(void )
#line 53
{
  PlatformFlashInitP__CsnIO__set();
  PlatformFlashInitP__CsnIO__makeOutput();



  return SUCCESS;
}

# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t PlatformP__PlatformFlash__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = PlatformFlashInitP__Init__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 50 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenDsP.nc"
static inline void /*HplMsp430GeneralIOC.PJ2*/HplMsp430GeneralIORenDsP__2__IO__clr(void )
#line 50
{
  /* atomic removed: atomic calls only */
#line 50
  * (volatile uint8_t * )802U &= ~(0x01 << 2);
}

# 53 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*PlatformBatteryVoltageC.Msp430GpioC*/Msp430GpioC__6__HplGeneralIO__clr(void ){
#line 53
  /*HplMsp430GeneralIOC.PJ2*/HplMsp430GeneralIORenDsP__2__IO__clr();
#line 53
}
#line 53
# 49 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformBatteryVoltageC.Msp430GpioC*/Msp430GpioC__6__GeneralIO__clr(void )
#line 49
{
#line 49
  /*PlatformBatteryVoltageC.Msp430GpioC*/Msp430GpioC__6__HplGeneralIO__clr();
}

# 41 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void PlatformBatteryVoltageP__EnablePin__clr(void ){
#line 41
  /*PlatformBatteryVoltageC.Msp430GpioC*/Msp430GpioC__6__GeneralIO__clr();
#line 41
}
#line 41
# 56 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenDsP.nc"
static inline void /*HplMsp430GeneralIOC.PJ2*/HplMsp430GeneralIORenDsP__2__IO__makeOutput(void )
#line 56
{
  /* atomic removed: atomic calls only */
#line 56
  * (volatile uint8_t * )804U |= 0x01 << 2;
}

# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*PlatformBatteryVoltageC.Msp430GpioC*/Msp430GpioC__6__HplGeneralIO__makeOutput(void ){
#line 85
  /*HplMsp430GeneralIOC.PJ2*/HplMsp430GeneralIORenDsP__2__IO__makeOutput();
#line 85
}
#line 85
# 54 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformBatteryVoltageC.Msp430GpioC*/Msp430GpioC__6__GeneralIO__makeOutput(void )
#line 54
{
#line 54
  /*PlatformBatteryVoltageC.Msp430GpioC*/Msp430GpioC__6__HplGeneralIO__makeOutput();
}

# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void PlatformBatteryVoltageP__EnablePin__makeOutput(void ){
#line 46
  /*PlatformBatteryVoltageC.Msp430GpioC*/Msp430GpioC__6__GeneralIO__makeOutput();
#line 46
}
#line 46
# 27 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/batteryVoltage/PlatformBatteryVoltageP.nc"
static inline error_t PlatformBatteryVoltageP__Init__init(void )
#line 27
{
  PlatformBatteryVoltageP__EnablePin__makeOutput();
  PlatformBatteryVoltageP__EnablePin__clr();
  return SUCCESS;
}

# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t PlatformP__BatteryVoltage__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = PlatformBatteryVoltageP__Init__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 48 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P33*/HplMsp430GeneralIORenP__19__IO__set(void )
#line 48
{
  /* atomic removed: atomic calls only */
#line 48
  * (volatile uint8_t * )546U |= 0x01 << 3;
}

# 48 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*PlatformApds9007C.Msp430GpioC*/Msp430GpioC__0__HplGeneralIO__set(void ){
#line 48
  /*HplMsp430GeneralIOC.P33*/HplMsp430GeneralIORenP__19__IO__set();
#line 48
}
#line 48
# 48 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformApds9007C.Msp430GpioC*/Msp430GpioC__0__GeneralIO__set(void )
#line 48
{
#line 48
  /*PlatformApds9007C.Msp430GpioC*/Msp430GpioC__0__HplGeneralIO__set();
}

# 40 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void Apds9007InitP__ShutdownPin__set(void ){
#line 40
  /*PlatformApds9007C.Msp430GpioC*/Msp430GpioC__0__GeneralIO__set();
#line 40
}
#line 40
# 55 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P33*/HplMsp430GeneralIORenP__19__IO__makeOutput(void )
#line 55
{
  /* atomic removed: atomic calls only */
#line 55
  * (volatile uint8_t * )548U |= 0x01 << 3;
}

# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*PlatformApds9007C.Msp430GpioC*/Msp430GpioC__0__HplGeneralIO__makeOutput(void ){
#line 85
  /*HplMsp430GeneralIOC.P33*/HplMsp430GeneralIORenP__19__IO__makeOutput();
#line 85
}
#line 85
# 54 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformApds9007C.Msp430GpioC*/Msp430GpioC__0__GeneralIO__makeOutput(void )
#line 54
{
#line 54
  /*PlatformApds9007C.Msp430GpioC*/Msp430GpioC__0__HplGeneralIO__makeOutput();
}

# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void Apds9007InitP__ShutdownPin__makeOutput(void ){
#line 46
  /*PlatformApds9007C.Msp430GpioC*/Msp430GpioC__0__GeneralIO__makeOutput();
#line 46
}
#line 46
# 5 "/opt/tinyos-2.x/tos/chips/apds9007/Apds9007InitP.nc"
static inline error_t Apds9007InitP__Init__init(void )
#line 5
{
  Apds9007InitP__ShutdownPin__makeOutput();
  Apds9007InitP__ShutdownPin__set();
  return SUCCESS;
}

# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t PlatformP__Apds9007__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = Apds9007InitP__Init__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 48 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void PlatformOneWireInitP__OneWireIO__set(void ){
#line 48
  /*HplMsp430GeneralIOC.P37*/HplMsp430GeneralIORenP__23__IO__set();
#line 48
}
#line 48
# 55 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P37*/HplMsp430GeneralIORenP__23__IO__makeOutput(void )
#line 55
{
  /* atomic removed: atomic calls only */
#line 55
  * (volatile uint8_t * )548U |= 0x01 << 7;
}

# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void PlatformOneWireInitP__OneWireIO__makeOutput(void ){
#line 85
  /*HplMsp430GeneralIOC.P37*/HplMsp430GeneralIORenP__23__IO__makeOutput();
#line 85
}
#line 85
# 53 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/onewire/PlatformOneWireInitP.nc"
static inline error_t PlatformOneWireInitP__Init__init(void )
#line 53
{

  PlatformOneWireInitP__OneWireIO__makeOutput();
  PlatformOneWireInitP__OneWireIO__set();
  return SUCCESS;
}

# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t PlatformP__OneWire__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = PlatformOneWireInitP__Init__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 49 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P36*/HplMsp430GeneralIORenP__22__IO__clr(void )
#line 49
{
  /* atomic removed: atomic calls only */
#line 49
  * (volatile uint8_t * )546U &= ~(0x01 << 6);
}

# 53 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*PlatformCC1190C.PowerGpio*/Msp430GpioC__4__HplGeneralIO__clr(void ){
#line 53
  /*HplMsp430GeneralIOC.P36*/HplMsp430GeneralIORenP__22__IO__clr();
#line 53
}
#line 53
# 49 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformCC1190C.PowerGpio*/Msp430GpioC__4__GeneralIO__clr(void )
#line 49
{
#line 49
  /*PlatformCC1190C.PowerGpio*/Msp430GpioC__4__HplGeneralIO__clr();
}

# 41 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void NoCC1190P__PowerPin__clr(void ){
#line 41
  /*PlatformCC1190C.PowerGpio*/Msp430GpioC__4__GeneralIO__clr();
#line 41
}
#line 41
# 55 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P36*/HplMsp430GeneralIORenP__22__IO__makeOutput(void )
#line 55
{
  /* atomic removed: atomic calls only */
#line 55
  * (volatile uint8_t * )548U |= 0x01 << 6;
}

# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*PlatformCC1190C.PowerGpio*/Msp430GpioC__4__HplGeneralIO__makeOutput(void ){
#line 85
  /*HplMsp430GeneralIOC.P36*/HplMsp430GeneralIORenP__22__IO__makeOutput();
#line 85
}
#line 85
# 54 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformCC1190C.PowerGpio*/Msp430GpioC__4__GeneralIO__makeOutput(void )
#line 54
{
#line 54
  /*PlatformCC1190C.PowerGpio*/Msp430GpioC__4__HplGeneralIO__makeOutput();
}

# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void NoCC1190P__PowerPin__makeOutput(void ){
#line 46
  /*PlatformCC1190C.PowerGpio*/Msp430GpioC__4__GeneralIO__makeOutput();
#line 46
}
#line 46
# 49 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P34*/HplMsp430GeneralIORenP__20__IO__clr(void )
#line 49
{
  /* atomic removed: atomic calls only */
#line 49
  * (volatile uint8_t * )546U &= ~(0x01 << 4);
}

# 53 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*PlatformCC1190C.PA_ENGpio*/Msp430GpioC__3__HplGeneralIO__clr(void ){
#line 53
  /*HplMsp430GeneralIOC.P34*/HplMsp430GeneralIORenP__20__IO__clr();
#line 53
}
#line 53
# 49 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformCC1190C.PA_ENGpio*/Msp430GpioC__3__GeneralIO__clr(void )
#line 49
{
#line 49
  /*PlatformCC1190C.PA_ENGpio*/Msp430GpioC__3__HplGeneralIO__clr();
}

# 41 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void NoCC1190P__PA_ENPin__clr(void ){
#line 41
  /*PlatformCC1190C.PA_ENGpio*/Msp430GpioC__3__GeneralIO__clr();
#line 41
}
#line 41
# 55 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P35*/HplMsp430GeneralIORenP__21__IO__makeOutput(void )
#line 55
{
  /* atomic removed: atomic calls only */
#line 55
  * (volatile uint8_t * )548U |= 0x01 << 5;
}

# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*PlatformCC1190C.LNA_ENGpio*/Msp430GpioC__2__HplGeneralIO__makeOutput(void ){
#line 85
  /*HplMsp430GeneralIOC.P35*/HplMsp430GeneralIORenP__21__IO__makeOutput();
#line 85
}
#line 85
# 54 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformCC1190C.LNA_ENGpio*/Msp430GpioC__2__GeneralIO__makeOutput(void )
#line 54
{
#line 54
  /*PlatformCC1190C.LNA_ENGpio*/Msp430GpioC__2__HplGeneralIO__makeOutput();
}

# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void NoCC1190P__LNA_ENPin__makeOutput(void ){
#line 46
  /*PlatformCC1190C.LNA_ENGpio*/Msp430GpioC__2__GeneralIO__makeOutput();
#line 46
}
#line 46
# 50 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenDsP.nc"
static inline void /*HplMsp430GeneralIOC.PJ0*/HplMsp430GeneralIORenDsP__0__IO__clr(void )
#line 50
{
  /* atomic removed: atomic calls only */
#line 50
  * (volatile uint8_t * )802U &= ~(0x01 << 0);
}

# 53 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*PlatformCC1190C.HGMGpio*/Msp430GpioC__1__HplGeneralIO__clr(void ){
#line 53
  /*HplMsp430GeneralIOC.PJ0*/HplMsp430GeneralIORenDsP__0__IO__clr();
#line 53
}
#line 53
# 49 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformCC1190C.HGMGpio*/Msp430GpioC__1__GeneralIO__clr(void )
#line 49
{
#line 49
  /*PlatformCC1190C.HGMGpio*/Msp430GpioC__1__HplGeneralIO__clr();
}

# 41 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void NoCC1190P__HGMPin__clr(void ){
#line 41
  /*PlatformCC1190C.HGMGpio*/Msp430GpioC__1__GeneralIO__clr();
#line 41
}
#line 41
# 56 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenDsP.nc"
static inline void /*HplMsp430GeneralIOC.PJ0*/HplMsp430GeneralIORenDsP__0__IO__makeOutput(void )
#line 56
{
  /* atomic removed: atomic calls only */
#line 56
  * (volatile uint8_t * )804U |= 0x01 << 0;
}

# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*PlatformCC1190C.HGMGpio*/Msp430GpioC__1__HplGeneralIO__makeOutput(void ){
#line 85
  /*HplMsp430GeneralIOC.PJ0*/HplMsp430GeneralIORenDsP__0__IO__makeOutput();
#line 85
}
#line 85
# 54 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformCC1190C.HGMGpio*/Msp430GpioC__1__GeneralIO__makeOutput(void )
#line 54
{
#line 54
  /*PlatformCC1190C.HGMGpio*/Msp430GpioC__1__HplGeneralIO__makeOutput();
}

# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void NoCC1190P__HGMPin__makeOutput(void ){
#line 46
  /*PlatformCC1190C.HGMGpio*/Msp430GpioC__1__GeneralIO__makeOutput();
#line 46
}
#line 46
# 10 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/cc1190/NoCC1190P.nc"
static inline error_t NoCC1190P__Init__init(void )
#line 10
{
  NoCC1190P__HGMPin__makeOutput();
  NoCC1190P__HGMPin__clr();
  NoCC1190P__LNA_ENPin__makeOutput();
  NoCC1190P__LNA_ENPin__makeOutput();
  NoCC1190P__PA_ENPin__clr();
  NoCC1190P__PA_ENPin__clr();
  NoCC1190P__PowerPin__makeOutput();
  NoCC1190P__PowerPin__clr();
  return SUCCESS;
}

# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t PlatformP__PlatformCC1190__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = NoCC1190P__Init__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 53 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__HplGeneralIO__clr(void ){
#line 53
  /*HplMsp430GeneralIOC.P37*/HplMsp430GeneralIORenP__23__IO__clr();
#line 53
}
#line 53
# 49 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__GeneralIO__clr(void )
#line 49
{
#line 49
  /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__HplGeneralIO__clr();
}

# 41 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void PlatformBusPowerP__EnablePin__clr(void ){
#line 41
  /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__GeneralIO__clr();
#line 41
}
#line 41
# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__HplGeneralIO__makeOutput(void ){
#line 85
  /*HplMsp430GeneralIOC.P37*/HplMsp430GeneralIORenP__23__IO__makeOutput();
#line 85
}
#line 85
# 54 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__GeneralIO__makeOutput(void )
#line 54
{
#line 54
  /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__HplGeneralIO__makeOutput();
}

# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void PlatformBusPowerP__EnablePin__makeOutput(void ){
#line 46
  /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__GeneralIO__makeOutput();
#line 46
}
#line 46
# 7 "/opt/tinyos-2.x/tos/platforms/bacon/PlatformBusPowerP.nc"
static inline error_t PlatformBusPowerP__Init__init(void )
#line 7
{
  PlatformBusPowerP__EnablePin__makeOutput();
  PlatformBusPowerP__EnablePin__clr();
  return SUCCESS;
}

# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t PlatformP__PlatformBusPower__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = PlatformBusPowerP__Init__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 196 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430XV2ClockControlP.nc"
static inline void Msp430XV2ClockControlP__Msp430XV2ClockControl__startMicroTimer(void )
{
  /* atomic removed: atomic calls only */
#line 198
  TA1CTL = (2 << 4) | (TA1CTL & ~(0x0010 | 0x0020));
}

# 94 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430XV2ClockControl.nc"
inline static void Msp430XV2ClockP__Msp430XV2ClockControl__startMicroTimer(void ){
#line 94
  Msp430XV2ClockControlP__Msp430XV2ClockControl__startMicroTimer();
#line 94
}
#line 94
# 181 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430XV2ClockControlP.nc"
static inline void Msp430XV2ClockControlP__Msp430XV2ClockControl__start32khzTimer(void )
{
  /* atomic removed: atomic calls only */
#line 183
  TA0CTL = (2 << 4) | (TA0CTL & ~(0x0010 | 0x0020));
}

# 69 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430XV2ClockControl.nc"
inline static void Msp430XV2ClockP__Msp430XV2ClockControl__start32khzTimer(void ){
#line 69
  Msp430XV2ClockControlP__Msp430XV2ClockControl__start32khzTimer();
#line 69
}
#line 69
# 171 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430XV2ClockControlP.nc"
static inline void Msp430XV2ClockControlP__Msp430XV2ClockControl__configureTimers(void )
{
  /* atomic removed: atomic calls only */
#line 173
  {
    TA0CTL = (((1 << 8) | 0x0004) | (0 << 4)) | 0x0002;
    TA0R = 0;
    TA1CTL = (((2 << 8) | 0x0004) | (0 << 4)) | 0x0002;
    TA1R = 0;
  }
}

# 60 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430XV2ClockControl.nc"
inline static void Msp430XV2ClockP__Msp430XV2ClockControl__configureTimers(void ){
#line 60
  Msp430XV2ClockControlP__Msp430XV2ClockControl__configureTimers();
#line 60
}
#line 60
# 54 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430XV2ClockControlP.nc"
static inline void Msp430XV2ClockControlP__Msp430XV2ClockControl__configureUnifiedClockSystem(int dco_config)
{
  uint16_t divs;

  /* atomic removed: atomic calls only */
#line 58
  {
#line 73
     __asm volatile ("bis	%0, r2" :  : "ir"((uint16_t )0x0040));




    UCSCTL3 = 0x0000;





    UCSCTL0 = 0x0000;

    switch (dco_config) {

        case MSP430XV2_DCO_2MHz_RSEL2: 
          default: 
            UCSCTL1 = 0x0020;
        UCSCTL2 = 0x1000 + 31;
        divs = 0x0000;
        break;
        case MSP430XV2_DCO_4MHz_RSEL3: 
          UCSCTL1 = 0x0030;
        UCSCTL2 = 0x1000 + 63;
        divs = 0x0010;
        break;
        case MSP430XV2_DCO_8MHz_RSEL3: 
          UCSCTL1 = 0x0030;
        UCSCTL2 = 0x1000 + 127;
        divs = 0x0020;
        break;
        case MSP430XV2_DCO_8MHz_RSEL4: 
          UCSCTL1 = 0x0040;
        UCSCTL2 = 0x1000 + 127;
        divs = 0x0020;
        break;
        case MSP430XV2_DCO_16MHz_RSEL4: 
          UCSCTL1 = 0x0040;
        UCSCTL2 = 0x1000 + 255;
        divs = 0x0030;
        break;
        case MSP430XV2_DCO_16MHz_RSEL5: 
          UCSCTL1 = 0x0050;
        UCSCTL2 = 0x1000 + 255;
        divs = 0x0030;
        break;
        case MSP430XV2_DCO_32MHz_RSEL5: 
          UCSCTL1 = 0x0050;
        UCSCTL2 = 0x1000 + 511;
        divs = 0x0040;
        break;
        case MSP430XV2_DCO_32MHz_RSEL6: 
          UCSCTL1 = 0x0060;
        UCSCTL2 = 0x1000 + 511;
        divs = 0x0040;
        break;
        case MSP430XV2_DCO_64MHz_RSEL6: 
          UCSCTL1 = 0x0060;
        UCSCTL2 = 0x1000 + 1023;
        divs = 0x0050;
        break;
        case MSP430XV2_DCO_64MHz_RSEL7: 
          UCSCTL1 = 0x0070;
        UCSCTL2 = 0x1000 + 1023;
        divs = 0x0050;
        break;
      }

     __asm volatile ("bic	%0, r2" :  : "ir"((uint16_t )0x0040));
#line 153
    do {
        UCSCTL7 &= ~(0x0008 + 0x0002 + 0x0004 + 0x0001);

        SFRIFG1 &= ~0x0002;
      }
    while (
#line 157
    UCSCTL7 & 0x0001);


    UCSCTL4 = (0x0200 | 0x0040) | 0x0004;






    UCSCTL5 = ((0x0000 | 0x0000) | divs) | 0x0000;
  }
}

# 54 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430XV2ClockControl.nc"
inline static void Msp430XV2ClockP__Msp430XV2ClockControl__configureUnifiedClockSystem(int dco_config){
#line 54
  Msp430XV2ClockControlP__Msp430XV2ClockControl__configureUnifiedClockSystem(dco_config);
#line 54
}
#line 54
# 71 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430XV2ClockP.nc"
static inline error_t Msp430XV2ClockP__Init__init(void )
{
  /* atomic removed: atomic calls only */
#line 73
  {
    Msp430XV2ClockP__Msp430XV2ClockControl__configureUnifiedClockSystem(MSP430XV2_DCO_64MHz_RSEL7);
    Msp430XV2ClockP__Msp430XV2ClockControl__configureTimers();
    Msp430XV2ClockP__Msp430XV2ClockControl__start32khzTimer();
    Msp430XV2ClockP__Msp430XV2ClockControl__startMicroTimer();
  }
  return SUCCESS;
}

# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t PlatformP__PlatformClock__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = Msp430XV2ClockP__Init__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 31 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/pmm/Msp430PmmP.nc"
static inline void Msp430PmmP__Pmm__setVoltage(uint8_t level)
#line 31
{

  PMMCTL0_H = 0xA5;

  SVSMHCTL = 0x0400 + 0x0100 * level + 0x4000 + 0x0001 * level;

  SVSMLCTL = 0x0400 + 0x4000 + 0x0001 * level;

  while ((PMMIFG & 0x0001) == 0) ;

  PMMIFG &= ~(0x0004 + 0x0002);

  PMMCTL0_L = 0x01 * level;

  if (PMMIFG & 0x0002) {
    while ((PMMIFG & 0x0004) == 0) ;
    }
  SVSMLCTL = 0x0400 + 0x0100 * level + 0x4000 + 0x0001 * level;

  PMMCTL0_H = 0x00;
}

#line 16
static inline error_t Msp430PmmP__Init__init(void )
#line 16
{
  Msp430PmmP__Pmm__setVoltage(0x2);
  return SUCCESS;
}

# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t PlatformP__Msp430Pmm__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = Msp430PmmP__Init__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 96 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/leds/PlatformLedP.nc"
static inline error_t PlatformLedP__Init__init(void )
#line 96
{
  /* atomic removed: atomic calls only */
#line 97
  {
    int li;

#line 99
    for (li = 0; li < PlatformLedP__nleds; ++li) {
        const PlatformLedP__led_t *lp = PlatformLedP__leds + li;

#line 101
        lp->port->pxout |= lp->bit;
        lp->port->pxdir |= lp->bit;
      }
  }
  return SUCCESS;
}

# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t PlatformP__PlatformLed__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = PlatformLedP__Init__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 48 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/pins/PlatformPinsP.nc"
static inline error_t PlatformPinsP__Init__init(void )
#line 48
{
  /* atomic removed: atomic calls only */
#line 49
  {


    P1DIR = 0xFF;


    P1OUT = 0x80;







    P2DIR = 0xDA;
    P2OUT = 0x00;



    P3DIR = 0xFF;



    P3OUT = 0x0F;








    P5DIR = 0xFF;

    P5OUT = 0x03;
#line 118
    PJDIR = 0xFF;
    PJOUT = 0x00;
  }









  return SUCCESS;
}

# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t PlatformP__PlatformPins__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = PlatformPinsP__Init__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 63 "/opt/tinyos-2.x/tos/platforms/bacon/PlatformP.nc"
static inline error_t PlatformP__Init__init(void )
#line 63
{
  WDTCTL = (0x5A << 8) + (1 << 7);
  SFRRPCR1 = 0x0004 | 0x0008;

  PlatformP__PlatformPins__init();
  PlatformP__PlatformLed__init();
  PlatformP__Msp430Pmm__init();
  PlatformP__PlatformClock__init();

  PlatformP__PlatformBusPower__init();
  PlatformP__PlatformCC1190__init();
  PlatformP__OneWire__init();
  PlatformP__Apds9007__init();
  PlatformP__BatteryVoltage__init();


  PlatformP__PlatformFlash__init();


  PlatformP__PeripheralInit__init();



  PlatformP__uwait(1024 * 10);

  return SUCCESS;
}

# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t RealMainP__PlatformInit__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = PlatformP__Init__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 65 "/opt/tinyos-2.x/tos/interfaces/Scheduler.nc"
inline static bool RealMainP__Scheduler__runNextTask(void ){
#line 65
  unsigned char __nesc_result;
#line 65

#line 65
  __nesc_result = SchedulerBasicP__Scheduler__runNextTask();
#line 65

#line 65
  return __nesc_result;
#line 65
}
#line 65
# 110 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static void /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__AMSend__sendDone(message_t * msg, error_t error){
#line 110
  TestSenderP__ReportSend__sendDone(msg, error);
#line 110
}
#line 110
# 65 "/opt/tinyos-2.x/tos/system/AMQueueEntryP.nc"
static inline void /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__Send__sendDone(message_t *m, error_t err)
#line 65
{
  /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__AMSend__sendDone(m, err);
}

# 215 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Send__default__sendDone(uint8_t id, message_t *msg, error_t err)
#line 215
{
}

# 100 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
inline static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Send__sendDone(uint8_t arg_0x40ab77a8, message_t * msg, error_t error){
#line 100
  switch (arg_0x40ab77a8) {
#line 100
    case 0U:
#line 100
      /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__Send__sendDone(msg, error);
#line 100
      break;
#line 100
    default:
#line 100
      /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Send__default__sendDone(arg_0x40ab77a8, msg, error);
#line 100
      break;
#line 100
    }
#line 100
}
#line 100
# 126 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__CancelTask__runTask(void )
#line 126
{
  uint8_t i;
#line 127
  uint8_t j;
#line 127
  uint8_t mask;
#line 127
  uint8_t last;
  message_t *msg;

#line 129
  for (i = 0; i < 1 / 8 + 1; i++) {
      if (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__cancelMask[i]) {
          for (mask = 1, j = 0; j < 8; j++) {
              if (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__cancelMask[i] & mask) {
                  last = i * 8 + j;
                  msg = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__queue[last].msg;
                  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__queue[last].msg = (void *)0;
                  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__cancelMask[i] &= ~mask;
                  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Send__sendDone(last, msg, ECANCEL);
                }
              mask <<= 1;
            }
        }
    }
}

# 228 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port21__edge(bool l2h)
#line 228
{
  /* atomic removed: atomic calls only */
#line 229
  {
    if (l2h) {
#line 230
      P2IES &= ~(1 << 1);
      }
    else {
#line 231
      P2IES |= 1 << 1;
      }
  }
}

# 67 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__HplInterrupt__edge(bool low_to_high){
#line 67
  HplMsp430InterruptP__Port21__edge(low_to_high);
#line 67
}
#line 67
# 191 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port21__enable(void )
#line 191
{
#line 191
  P2IE |= 1 << 1;
}

# 42 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__HplInterrupt__enable(void ){
#line 42
  HplMsp430InterruptP__Port21__enable();
#line 42
}
#line 42
# 169 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__errorTask__runTask(void )
#line 169
{
  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__sendDone(/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__current, /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__queue[/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__current].msg, FAIL);
}

# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__errorTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__errorTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 80 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static error_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__AMSend__send(am_id_t arg_0x40ab51b8, am_addr_t addr, message_t * msg, uint8_t len){
#line 80
  unsigned char __nesc_result;
#line 80

#line 80
  __nesc_result = /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMSend__send(arg_0x40ab51b8, addr, msg, len);
#line 80

#line 80
  return __nesc_result;
#line 80
}
#line 80
# 235 "/usr/lib/ncc/nesc_nx.h"
static __inline  uint8_t __nesc_ntoh_uint8(const void * source)
#line 235
{
  const uint8_t *base = source;

#line 237
  return base[0];
}

# 60 "/opt/tinyos-2.x/tos/lib/serial/SerialActiveMessageP.nc"
static inline serial_header_t * /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__getHeader(message_t * msg)
#line 60
{
  return (serial_header_t * )((uint8_t *)msg + (unsigned short )& ((message_t *)0)->data - sizeof(serial_header_t ));
}

#line 122
static inline uint8_t /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Packet__payloadLength(message_t *msg)
#line 122
{
  serial_header_t *header = /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__getHeader(msg);

#line 124
  return __nesc_ntoh_uint8(header->length.data);
}

# 78 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
inline static uint8_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Packet__payloadLength(message_t * msg){
#line 78
  unsigned char __nesc_result;
#line 78

#line 78
  __nesc_result = /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Packet__payloadLength(msg);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 78 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
inline static am_addr_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__AMPacket__destination(message_t * amsg){
#line 78
  unsigned int __nesc_result;
#line 78

#line 78
  __nesc_result = /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMPacket__destination(amsg);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 172 "/opt/tinyos-2.x/tos/lib/serial/SerialActiveMessageP.nc"
static inline am_id_t /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMPacket__type(message_t *amsg)
#line 172
{
  serial_header_t *header = /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__getHeader(amsg);

#line 174
  return __nesc_ntoh_uint8(header->type.data);
}

# 147 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
inline static am_id_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__AMPacket__type(message_t * amsg){
#line 147
  unsigned char __nesc_result;
#line 147

#line 147
  __nesc_result = /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMPacket__type(amsg);
#line 147

#line 147
  return __nesc_result;
#line 147
}
#line 147
# 65 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__nextPacket(void )
#line 65
{
  uint8_t i;

#line 67
  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__current = (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__current + 1) % 1;
  for (i = 0; i < 1; i++) {
      if (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__queue[/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__current].msg == (void *)0 || 
      /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__cancelMask[/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__current / 8] & (1 << /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__current % 8)) 
        {
          /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__current = (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__current + 1) % 1;
        }
      else {
          break;
        }
    }
  if (i >= 1) {
#line 78
    /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__current = 1;
    }
}

#line 174
static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__tryToSend(void )
#line 174
{
  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__nextPacket();
  if (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__current < 1) {
      error_t nextErr;
      message_t *nextMsg = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__queue[/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__current].msg;
      am_id_t nextId = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__AMPacket__type(nextMsg);
      am_addr_t nextDest = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__AMPacket__destination(nextMsg);
      uint8_t len = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Packet__payloadLength(nextMsg);

#line 182
      nextErr = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__AMSend__send(nextId, nextDest, nextMsg, len);
      if (nextErr != SUCCESS) {
          /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__errorTask__postTask();
        }
    }
}

# 264 "/usr/lib/ncc/nesc_nx.h"
static __inline  uint16_t __nesc_ntoh_uint16(const void * source)
#line 264
{
  const uint8_t *base = source;

#line 266
  return ((uint16_t )base[0] << 8) | base[1];
}

# 538 "/opt/tinyos-2.x/tos/lib/serial/SerialP.nc"
static inline error_t SerialP__SendBytePacket__startSend(uint8_t b)
#line 538
{
  bool not_busy = FALSE;

#line 540
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 540
    {
      if (SerialP__txState == SerialP__TXSTATE_INACTIVE) 
        {
          unsigned char __nesc_temp = 
#line 542
          EOFF;

          {
#line 542
            __nesc_atomic_end(__nesc_atomic); 
#line 542
            return __nesc_temp;
          }
        }
    }
#line 545
    __nesc_atomic_end(__nesc_atomic); }
#line 544
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 544
    {
      if (SerialP__txBuf[SerialP__TX_DATA_INDEX].state == SerialP__BUFFER_AVAILABLE) {
          SerialP__txBuf[SerialP__TX_DATA_INDEX].state = SerialP__BUFFER_FILLING;
          SerialP__txBuf[SerialP__TX_DATA_INDEX].buf = b;
          not_busy = TRUE;
        }
    }
#line 550
    __nesc_atomic_end(__nesc_atomic); }
  if (not_busy) {
      SerialP__MaybeScheduleTx();
      return SUCCESS;
    }
  return EBUSY;
}

# 62 "/opt/tinyos-2.x/tos/lib/serial/SendBytePacket.nc"
inline static error_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__SendBytePacket__startSend(uint8_t first_byte){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = SerialP__SendBytePacket__startSend(first_byte);
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 54 "/opt/tinyos-2.x/tos/lib/serial/SerialPacketInfoActiveMessageP.nc"
static inline uint8_t SerialPacketInfoActiveMessageP__Info__dataLinkLength(message_t *msg, uint8_t upperLen)
#line 54
{
  return upperLen + sizeof(serial_header_t );
}

# 361 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
static inline uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__default__dataLinkLength(uart_id_t id, message_t *msg, 
uint8_t upperLen)
#line 362
{
  return 0;
}

# 23 "/opt/tinyos-2.x/tos/lib/serial/SerialPacketInfo.nc"
inline static uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__dataLinkLength(uart_id_t arg_0x4110b088, message_t *msg, uint8_t upperLen){
#line 23
  unsigned char __nesc_result;
#line 23

#line 23
  switch (arg_0x4110b088) {
#line 23
    case TOS_SERIAL_ACTIVE_MESSAGE_ID:
#line 23
      __nesc_result = SerialPacketInfoActiveMessageP__Info__dataLinkLength(msg, upperLen);
#line 23
      break;
#line 23
    default:
#line 23
      __nesc_result = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__default__dataLinkLength(arg_0x4110b088, msg, upperLen);
#line 23
      break;
#line 23
    }
#line 23

#line 23
  return __nesc_result;
#line 23
}
#line 23
# 111 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
static inline error_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__Send__send(uint8_t id, message_t *msg, uint8_t len)
#line 111
{
  if (/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendState != /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__SEND_STATE_IDLE) {
      return EBUSY;
    }

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 116
    {
      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendIndex = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__offset(id);
      if (/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendIndex > sizeof(message_header_t )) {
          {
            unsigned char __nesc_temp = 
#line 119
            ESIZE;

            {
#line 119
              __nesc_atomic_end(__nesc_atomic); 
#line 119
              return __nesc_temp;
            }
          }
        }
#line 122
      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendError = SUCCESS;
      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendBuffer = (uint8_t *)msg;
      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendState = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__SEND_STATE_DATA;
      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendId = id;
      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendCancelled = FALSE;






      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendLen = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__dataLinkLength(id, msg, len) + /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendIndex;
    }
#line 134
    __nesc_atomic_end(__nesc_atomic); }
  if (/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__SendBytePacket__startSend(id) == SUCCESS) {
      return SUCCESS;
    }
  else {
      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendState = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__SEND_STATE_IDLE;
      return FAIL;
    }
}

# 75 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
inline static error_t /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__SubSend__send(message_t * msg, uint8_t len){
#line 75
  unsigned char __nesc_result;
#line 75

#line 75
  __nesc_result = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__Send__send(TOS_SERIAL_ACTIVE_MESSAGE_ID, msg, len);
#line 75

#line 75
  return __nesc_result;
#line 75
}
#line 75
# 189 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static inline void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__AMSend__sendDone(am_id_t id, message_t *msg, error_t err)
#line 189
{





  if (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__current >= 1) {
      return;
    }
  if (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__queue[/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__current].msg == msg) {
      /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__sendDone(/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__current, msg, err);
    }
  else {
      ;
    }
}

# 110 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static void /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMSend__sendDone(am_id_t arg_0x41056e60, message_t * msg, error_t error){
#line 110
  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__AMSend__sendDone(arg_0x41056e60, msg, error);
#line 110
}
#line 110
# 101 "/opt/tinyos-2.x/tos/lib/serial/SerialActiveMessageP.nc"
static inline void /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__SubSend__sendDone(message_t *msg, error_t result)
#line 101
{
  /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMSend__sendDone(/*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMPacket__type(msg), msg, result);
}

# 376 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
static inline void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__Send__default__sendDone(uart_id_t idxxx, message_t *msg, error_t error)
#line 376
{
  return;
}

# 100 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
inline static void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__Send__sendDone(uart_id_t arg_0x4110c560, message_t * msg, error_t error){
#line 100
  switch (arg_0x4110c560) {
#line 100
    case TOS_SERIAL_ACTIVE_MESSAGE_ID:
#line 100
      /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__SubSend__sendDone(msg, error);
#line 100
      break;
#line 100
    default:
#line 100
      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__Send__default__sendDone(arg_0x4110c560, msg, error);
#line 100
      break;
#line 100
    }
#line 100
}
#line 100
# 158 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
static inline void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__signalSendDone__runTask(void )
#line 158
{
  error_t error;

  /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendState = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__SEND_STATE_IDLE;
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 162
    error = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendError;
#line 162
    __nesc_atomic_end(__nesc_atomic); }

  if (/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendCancelled) {
#line 164
    error = ECANCEL;
    }
#line 165
  /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__Send__sendDone(/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendId, (message_t *)/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendBuffer, error);
}

#line 212
static inline void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__unlockBuffer(uint8_t which)
#line 212
{
  if (which) {
      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveState.bufOneLocked = 0;
    }
  else {
      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveState.bufZeroLocked = 0;
    }
}

# 109 "/opt/tinyos-2.x/tos/lib/serial/SerialActiveMessageP.nc"
static inline message_t */*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Receive__default__receive(uint8_t id, message_t *msg, void *payload, uint8_t len)
#line 109
{
  return msg;
}

# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
inline static message_t * /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Receive__receive(am_id_t arg_0x410538e0, message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
    __nesc_result = /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Receive__default__receive(arg_0x410538e0, msg, payload, len);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 113 "/opt/tinyos-2.x/tos/lib/serial/SerialActiveMessageP.nc"
static inline message_t */*SerialActiveMessageC.AM*/SerialActiveMessageP__0__SubReceive__receive(message_t *msg, void *payload, uint8_t len)
#line 113
{
  return /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Receive__receive(/*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMPacket__type(msg), msg, msg->data, len);
}

# 371 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
static inline message_t */*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__Receive__default__receive(uart_id_t idxxx, message_t *msg, 
void *payload, 
uint8_t len)
#line 373
{
  return msg;
}

# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
inline static message_t * /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__Receive__receive(uart_id_t arg_0x410d2e50, message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
  switch (arg_0x410d2e50) {
#line 78
    case TOS_SERIAL_ACTIVE_MESSAGE_ID:
#line 78
      __nesc_result = /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__SubReceive__receive(msg, payload, len);
#line 78
      break;
#line 78
    default:
#line 78
      __nesc_result = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__Receive__default__receive(arg_0x410d2e50, msg, payload, len);
#line 78
      break;
#line 78
    }
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 57 "/opt/tinyos-2.x/tos/lib/serial/SerialPacketInfoActiveMessageP.nc"
static inline uint8_t SerialPacketInfoActiveMessageP__Info__upperLength(message_t *msg, uint8_t dataLinkLen)
#line 57
{
  return dataLinkLen - sizeof(serial_header_t );
}

# 365 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
static inline uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__default__upperLength(uart_id_t id, message_t *msg, 
uint8_t dataLinkLen)
#line 366
{
  return 0;
}

# 31 "/opt/tinyos-2.x/tos/lib/serial/SerialPacketInfo.nc"
inline static uint8_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__upperLength(uart_id_t arg_0x4110b088, message_t *msg, uint8_t dataLinkLen){
#line 31
  unsigned char __nesc_result;
#line 31

#line 31
  switch (arg_0x4110b088) {
#line 31
    case TOS_SERIAL_ACTIVE_MESSAGE_ID:
#line 31
      __nesc_result = SerialPacketInfoActiveMessageP__Info__upperLength(msg, dataLinkLen);
#line 31
      break;
#line 31
    default:
#line 31
      __nesc_result = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__default__upperLength(arg_0x4110b088, msg, dataLinkLen);
#line 31
      break;
#line 31
    }
#line 31

#line 31
  return __nesc_result;
#line 31
}
#line 31
# 275 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
static inline void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTask__runTask(void )
#line 275
{
  uart_id_t myType;
  message_t *myBuf;
  uint8_t mySize;
  uint8_t myWhich;

#line 280
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 280
    {
      myType = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTaskType;
      myBuf = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTaskBuf;
      mySize = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTaskSize;
      myWhich = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTaskWhich;
    }
#line 285
    __nesc_atomic_end(__nesc_atomic); }
  mySize -= /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__offset(myType);
  mySize = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__PacketInfo__upperLength(myType, myBuf, mySize);
  myBuf = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__Receive__receive(myType, myBuf, myBuf, mySize);
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 289
    {
      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__messagePtrs[myWhich] = myBuf;
      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__unlockBuffer(myWhich);
      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTaskPending = FALSE;
    }
#line 293
    __nesc_atomic_end(__nesc_atomic); }
}

# 244 "TestSenderP.nc"
static inline void TestSenderP__SerialSplitControl__stopDone(error_t err)
#line 244
{
}

# 138 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static void SerialP__SplitControl__stopDone(error_t error){
#line 138
  TestSenderP__SerialSplitControl__stopDone(error);
#line 138
}
#line 138
# 208 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__default__granted(void )
#line 208
{
}

# 46 "/opt/tinyos-2.x/tos/interfaces/ResourceDefaultOwner.nc"
inline static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__granted(void ){
#line 46
  /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__default__granted();
#line 46
}
#line 46
# 399 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__ResourceConfigure__unconfigure(uint8_t client)
{
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__unconfigure_();
}

# 218 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__default__unconfigure(uint8_t id)
#line 218
{
}

# 65 "/opt/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
inline static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__unconfigure(uint8_t arg_0x40730cf8){
#line 65
  switch (arg_0x40730cf8) {
#line 65
    case /*PlatformSerialC.UartC*/Msp430UsciUartA0C__0__CLIENT_ID:
#line 65
      /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__ResourceConfigure__unconfigure(/*PlatformSerialC.UartC*/Msp430UsciUartA0C__0__CLIENT_ID);
#line 65
      break;
#line 65
    default:
#line 65
      /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__default__unconfigure(arg_0x40730cf8);
#line 65
      break;
#line 65
    }
#line 65
}
#line 65
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__grantedTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__grantedTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 68 "/opt/tinyos-2.x/tos/system/FcfsResourceQueueC.nc"
static inline resource_client_id_t /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__FcfsQueue__dequeue(void )
#line 68
{
  /* atomic removed: atomic calls only */
#line 69
  {
    if (/*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__qHead != /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__NO_ENTRY) {
        uint8_t id = /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__qHead;

#line 72
        /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__qHead = /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__resQ[/*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__qHead];
        if (/*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__qHead == /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__NO_ENTRY) {
          /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__qTail = /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__NO_ENTRY;
          }
#line 75
        /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__resQ[id] = /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__NO_ENTRY;
        {
          unsigned char __nesc_temp = 
#line 76
          id;

#line 76
          return __nesc_temp;
        }
      }
#line 78
    {
      unsigned char __nesc_temp = 
#line 78
      /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__NO_ENTRY;

#line 78
      return __nesc_temp;
    }
  }
}

# 70 "/opt/tinyos-2.x/tos/interfaces/ResourceQueue.nc"
inline static resource_client_id_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Queue__dequeue(void ){
#line 70
  unsigned char __nesc_result;
#line 70

#line 70
  __nesc_result = /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__FcfsQueue__dequeue();
#line 70

#line 70
  return __nesc_result;
#line 70
}
#line 70
# 60 "/opt/tinyos-2.x/tos/system/FcfsResourceQueueC.nc"
static inline bool /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__FcfsQueue__isEmpty(void )
#line 60
{
  /* atomic removed: atomic calls only */
#line 61
  {
    unsigned char __nesc_temp = 
#line 61
    /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__qHead == /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__NO_ENTRY;

#line 61
    return __nesc_temp;
  }
}

# 53 "/opt/tinyos-2.x/tos/interfaces/ResourceQueue.nc"
inline static bool /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Queue__isEmpty(void ){
#line 53
  unsigned char __nesc_result;
#line 53

#line 53
  __nesc_result = /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__FcfsQueue__isEmpty();
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53
# 111 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
static inline error_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__release(uint8_t id)
#line 111
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 112
    {
      if (/*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__state == /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__RES_BUSY && /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__resId == id) {
          if (/*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Queue__isEmpty() == FALSE) {
              /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__reqResId = /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Queue__dequeue();
              /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__resId = /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__NO_RES;
              /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__state = /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__RES_GRANTING;
              /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__grantedTask__postTask();
              /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__unconfigure(id);
            }
          else {
              /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__resId = /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__default_owner_id;
              /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__state = /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__RES_CONTROLLED;
              /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__unconfigure(id);
              /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__granted();
            }
          {
            unsigned char __nesc_temp = 
#line 127
            SUCCESS;

            {
#line 127
              __nesc_atomic_end(__nesc_atomic); 
#line 127
              return __nesc_temp;
            }
          }
        }
    }
#line 131
    __nesc_atomic_end(__nesc_atomic); }
#line 130
  return FAIL;
}

# 120 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
inline static error_t PlatformSerialP__Resource__release(void ){
#line 120
  unsigned char __nesc_result;
#line 120

#line 120
  __nesc_result = /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__release(/*PlatformSerialC.UartC*/Msp430UsciUartA0C__0__CLIENT_ID);
#line 120

#line 120
  return __nesc_result;
#line 120
}
#line 120
# 55 "/opt/tinyos-2.x/tos/platforms/surf/hardware/usci/PlatformSerialP.nc"
static inline error_t PlatformSerialP__StdControl__stop(void )
#line 55
{
  return PlatformSerialP__Resource__release();
}

# 105 "/opt/tinyos-2.x/tos/interfaces/StdControl.nc"
inline static error_t SerialP__SerialControl__stop(void ){
#line 105
  unsigned char __nesc_result;
#line 105

#line 105
  __nesc_result = PlatformSerialP__StdControl__stop();
#line 105

#line 105
  return __nesc_result;
#line 105
}
#line 105
# 336 "/opt/tinyos-2.x/tos/lib/serial/SerialP.nc"
static inline void SerialP__SerialFlush__flushDone(void )
#line 336
{
  SerialP__SerialControl__stop();
  SerialP__SplitControl__stopDone(SUCCESS);
}

static inline void SerialP__defaultSerialFlushTask__runTask(void )
#line 341
{
  SerialP__SerialFlush__flushDone();
}

# 116 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__enterResetMode_(void )
#line 116
{
   __asm volatile ("bis %0, %1" :  : "i"(0x01), "m"(* (volatile uint8_t * )(1472U + 0x00)));}

# 281 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__enterResetMode_(void ){
#line 281
  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__enterResetMode_();
#line 281
}
#line 281
# 55 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P15*/HplMsp430GeneralIORenP__5__IO__makeOutput(void )
#line 55
{
  /* atomic removed: atomic calls only */
#line 55
  * (volatile uint8_t * )516U |= 0x01 << 5;
}

# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__URXD__makeOutput(void ){
#line 85
  /*HplMsp430GeneralIOC.P15*/HplMsp430GeneralIORenP__5__IO__makeOutput();
#line 85
}
#line 85
# 59 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P15*/HplMsp430GeneralIORenP__5__IO__selectIOFunc(void )
#line 59
{
  /* atomic removed: atomic calls only */
#line 59
  * (volatile uint8_t * )522U &= ~(0x01 << 5);
}

# 99 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__URXD__selectIOFunc(void ){
#line 99
  /*HplMsp430GeneralIOC.P15*/HplMsp430GeneralIORenP__5__IO__selectIOFunc();
#line 99
}
#line 99
#line 85
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UTXD__makeOutput(void ){
#line 85
  /*HplMsp430GeneralIOC.P16*/HplMsp430GeneralIORenP__6__IO__makeOutput();
#line 85
}
#line 85
# 59 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P16*/HplMsp430GeneralIORenP__6__IO__selectIOFunc(void )
#line 59
{
  /* atomic removed: atomic calls only */
#line 59
  * (volatile uint8_t * )522U &= ~(0x01 << 6);
}

# 99 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UTXD__selectIOFunc(void ){
#line 99
  /*HplMsp430GeneralIOC.P16*/HplMsp430GeneralIORenP__6__IO__selectIOFunc();
#line 99
}
#line 99
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t SerialP__defaultSerialFlushTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(SerialP__defaultSerialFlushTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 344 "/opt/tinyos-2.x/tos/lib/serial/SerialP.nc"
static inline void SerialP__SerialFlush__default__flush(void )
#line 344
{
  SerialP__defaultSerialFlushTask__postTask();
}

# 49 "/opt/tinyos-2.x/tos/lib/serial/SerialFlush.nc"
inline static void SerialP__SerialFlush__flush(void ){
#line 49
  SerialP__SerialFlush__default__flush();
#line 49
}
#line 49
# 332 "/opt/tinyos-2.x/tos/lib/serial/SerialP.nc"
static inline void SerialP__stopDoneTask__runTask(void )
#line 332
{
  SerialP__SerialFlush__flush();
}

# 160 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/leds/PlatformLedP.nc"
static inline void PlatformLedP__Leds__set(uint8_t v)
#line 160
{
#line 160
  PlatformLedP___LEDwrite(v);
}

# 134 "/opt/tinyos-2.x/tos/interfaces/Leds.nc"
inline static void TestSenderP__Leds__set(uint8_t val){
#line 134
  PlatformLedP__Leds__set(val);
#line 134
}
#line 134
# 62 "TestSenderP.nc"
static inline void TestSenderP__SerialSplitControl__startDone(error_t err)
#line 62
{
  TestSenderP__Leds__set(0);
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 64
    {
      TestSenderP__state = TestSenderP__S_READY;
    }
#line 66
    __nesc_atomic_end(__nesc_atomic); }
}

# 113 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static void SerialP__SplitControl__startDone(error_t error){
#line 113
  TestSenderP__SerialSplitControl__startDone(error);
#line 113
}
#line 113
# 388 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
static inline const msp430_usci_config_t *
/*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Msp430UsciConfigure__default__getConfiguration(uint8_t client)
{
  return &msp430_usci_uart_default_config;
}

# 44 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciConfigure.nc"
inline static const msp430_usci_config_t */*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Msp430UsciConfigure__getConfiguration(uint8_t arg_0x40778338){
#line 44
  struct msp430_usci_config_t const *__nesc_result;
#line 44

#line 44
    __nesc_result = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Msp430UsciConfigure__default__getConfiguration(arg_0x40778338);
#line 44

#line 44
  return __nesc_result;
#line 44
}
#line 44
# 394 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__ResourceConfigure__configure(uint8_t client)
{
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__configure_(/*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Msp430UsciConfigure__getConfiguration(client));
}

# 216 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__default__configure(uint8_t id)
#line 216
{
}

# 59 "/opt/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
inline static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__configure(uint8_t arg_0x40730cf8){
#line 59
  switch (arg_0x40730cf8) {
#line 59
    case /*PlatformSerialC.UartC*/Msp430UsciUartA0C__0__CLIENT_ID:
#line 59
      /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__ResourceConfigure__configure(/*PlatformSerialC.UartC*/Msp430UsciUartA0C__0__CLIENT_ID);
#line 59
      break;
#line 59
    default:
#line 59
      /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__default__configure(arg_0x40730cf8);
#line 59
      break;
#line 59
    }
#line 59
}
#line 59
# 133 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
static inline error_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__release(void )
#line 133
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 134
    {
      if (/*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__resId == /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__default_owner_id) {
          if (/*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__state == /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__RES_GRANTING) {
              /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__grantedTask__postTask();
              {
                unsigned char __nesc_temp = 
#line 138
                SUCCESS;

                {
#line 138
                  __nesc_atomic_end(__nesc_atomic); 
#line 138
                  return __nesc_temp;
                }
              }
            }
          else {
#line 140
            if (/*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__state == /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__RES_IMM_GRANTING) {
                /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__resId = /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__reqResId;
                /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__state = /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__RES_BUSY;
                {
                  unsigned char __nesc_temp = 
#line 143
                  SUCCESS;

                  {
#line 143
                    __nesc_atomic_end(__nesc_atomic); 
#line 143
                    return __nesc_temp;
                  }
                }
              }
            }
        }
    }
#line 149
    __nesc_atomic_end(__nesc_atomic); }
#line 147
  return FAIL;
}

#line 213
static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__default__immediateRequested(void )
#line 213
{
  /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__release();
}

# 81 "/opt/tinyos-2.x/tos/interfaces/ResourceDefaultOwner.nc"
inline static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__immediateRequested(void ){
#line 81
  /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__default__immediateRequested();
#line 81
}
#line 81
# 206 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceRequested__default__immediateRequested(uint8_t id)
#line 206
{
}

# 61 "/opt/tinyos-2.x/tos/interfaces/ResourceRequested.nc"
inline static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceRequested__immediateRequested(uint8_t arg_0x40731948){
#line 61
    /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceRequested__default__immediateRequested(arg_0x40731948);
#line 61
}
#line 61
# 93 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
static inline error_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__immediateRequest(uint8_t id)
#line 93
{
  /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceRequested__immediateRequested(/*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__resId);
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 95
    {
      if (/*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__state == /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__RES_CONTROLLED) {
          /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__state = /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__RES_IMM_GRANTING;
          /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__reqResId = id;
        }
      else {
          unsigned char __nesc_temp = 
#line 100
          FAIL;

          {
#line 100
            __nesc_atomic_end(__nesc_atomic); 
#line 100
            return __nesc_temp;
          }
        }
    }
#line 103
    __nesc_atomic_end(__nesc_atomic); }
#line 102
  /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__immediateRequested();
  if (/*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__resId == id) {
      /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__configure(/*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__resId);
      return SUCCESS;
    }
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 107
    /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__state = /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__RES_CONTROLLED;
#line 107
    __nesc_atomic_end(__nesc_atomic); }
  return FAIL;
}

# 97 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
inline static error_t PlatformSerialP__Resource__immediateRequest(void ){
#line 97
  unsigned char __nesc_result;
#line 97

#line 97
  __nesc_result = /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__immediateRequest(/*PlatformSerialC.UartC*/Msp430UsciUartA0C__0__CLIENT_ID);
#line 97

#line 97
  return __nesc_result;
#line 97
}
#line 97
# 51 "/opt/tinyos-2.x/tos/platforms/surf/hardware/usci/PlatformSerialP.nc"
static inline error_t PlatformSerialP__StdControl__start(void )
#line 51
{
  return PlatformSerialP__Resource__immediateRequest();
}

# 95 "/opt/tinyos-2.x/tos/interfaces/StdControl.nc"
inline static error_t SerialP__SerialControl__start(void ){
#line 95
  unsigned char __nesc_result;
#line 95

#line 95
  __nesc_result = PlatformSerialP__StdControl__start();
#line 95

#line 95
  return __nesc_result;
#line 95
}
#line 95
# 322 "/opt/tinyos-2.x/tos/lib/serial/SerialP.nc"
static inline void SerialP__startDoneTask__runTask(void )
#line 322
{
  SerialP__SerialControl__start();
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 324
    {
      SerialP__txState = SerialP__TXSTATE_IDLE;
      SerialP__rxState = SerialP__RXSTATE_NOSYNC;
    }
#line 327
    __nesc_atomic_end(__nesc_atomic); }
  SerialP__SplitControl__startDone(SUCCESS);
}

# 121 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciP.nc"
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__leaveResetMode_(void )
#line 121
{
   __asm volatile ("bic %0, %1" :  : "i"(0x01), "m"(* (volatile uint8_t * )(1472U + 0x00)));}



static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__configure(const msp430_usci_config_t *config, 
bool leave_in_reset)
{
  if (!config) {
      return;
    }
  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__enterResetMode_();
  * (volatile uint16_t * )1472U = config->ctlw0 + 0x01;
  * (volatile uint16_t * )(1472U + 0x06) = config->brw;
  * (volatile uint8_t * )(1472U + 0x08) = config->mctl;
  if (!leave_in_reset) {
      /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__leaveResetMode_();
    }
}

# 273 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__configure(const msp430_usci_config_t *config, bool leave_in_reset){
#line 273
  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__configure(config, leave_in_reset);
#line 273
}
#line 273
# 53 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P15*/HplMsp430GeneralIORenP__5__IO__makeInput(void )
#line 53
{
#line 53
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 53
    * (volatile uint8_t * )516U &= ~(0x01 << 5);
#line 53
    __nesc_atomic_end(__nesc_atomic); }
}

# 78 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__URXD__makeInput(void ){
#line 78
  /*HplMsp430GeneralIOC.P15*/HplMsp430GeneralIORenP__5__IO__makeInput();
#line 78
}
#line 78
# 57 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P15*/HplMsp430GeneralIORenP__5__IO__selectModuleFunc(void )
#line 57
{
#line 57
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 57
    * (volatile uint8_t * )522U |= 0x01 << 5;
#line 57
    __nesc_atomic_end(__nesc_atomic); }
}

# 92 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__URXD__selectModuleFunc(void ){
#line 92
  /*HplMsp430GeneralIOC.P15*/HplMsp430GeneralIORenP__5__IO__selectModuleFunc();
#line 92
}
#line 92
# 57 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P16*/HplMsp430GeneralIORenP__6__IO__selectModuleFunc(void )
#line 57
{
#line 57
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 57
    * (volatile uint8_t * )522U |= 0x01 << 6;
#line 57
    __nesc_atomic_end(__nesc_atomic); }
}

# 92 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UTXD__selectModuleFunc(void ){
#line 92
  /*HplMsp430GeneralIOC.P16*/HplMsp430GeneralIORenP__6__IO__selectModuleFunc();
#line 92
}
#line 92
# 288 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__leaveResetMode_(void ){
#line 288
  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciP__0__Usci__leaveResetMode_();
#line 288
}
#line 288
# 108 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/leds/PlatformLedP.nc"
static inline void PlatformLedP___LEDon(uint8_t led_id)
{
  const PlatformLedP__led_t *lp = PlatformLedP__leds + led_id;

#line 111
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 111
    lp->port->pxout &= ~ lp->bit;
#line 111
    __nesc_atomic_end(__nesc_atomic); }
}

#line 113
static inline void PlatformLedP___LEDoff(uint8_t led_id)
{
  const PlatformLedP__led_t *lp = PlatformLedP__leds + led_id;

#line 116
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 116
    lp->port->pxout |= lp->bit;
#line 116
    __nesc_atomic_end(__nesc_atomic); }
}

# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__signalSendDone__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__signalSendDone);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 194 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
static inline void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__SendBytePacket__sendCompleted(error_t error)
#line 194
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 195
    /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__sendError = error;
#line 195
    __nesc_atomic_end(__nesc_atomic); }
  /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__signalSendDone__postTask();
}

# 91 "/opt/tinyos-2.x/tos/lib/serial/SendBytePacket.nc"
inline static void SerialP__SendBytePacket__sendCompleted(error_t error){
#line 91
  /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__SendBytePacket__sendCompleted(error);
#line 91
}
#line 91
# 244 "/opt/tinyos-2.x/tos/lib/serial/SerialP.nc"
static __inline bool SerialP__ack_queue_is_empty(void )
#line 244
{
  bool ret;

#line 246
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 246
    ret = SerialP__ackQ.writePtr == SerialP__ackQ.readPtr;
#line 246
    __nesc_atomic_end(__nesc_atomic); }
  return ret;
}











static __inline uint8_t SerialP__ack_queue_top(void )
#line 260
{
  uint8_t tmp = 0;

  /* atomic removed: atomic calls only */
#line 262
  {
    if (!SerialP__ack_queue_is_empty()) {
        tmp = SerialP__ackQ.buf[SerialP__ackQ.readPtr];
      }
  }
  return tmp;
}

static inline uint8_t SerialP__ack_queue_pop(void )
#line 270
{
  uint8_t retval = 0;

  /* atomic removed: atomic calls only */
#line 272
  {
    if (SerialP__ackQ.writePtr != SerialP__ackQ.readPtr) {
        retval = SerialP__ackQ.buf[SerialP__ackQ.readPtr];
        if (++ SerialP__ackQ.readPtr > SerialP__ACK_QUEUE_SIZE) {
#line 275
          SerialP__ackQ.readPtr = 0;
          }
      }
  }
#line 278
  return retval;
}

#line 559
static inline void SerialP__RunTx__runTask(void )
#line 559
{
  uint8_t idle;
  uint8_t done;
  uint8_t fail;









  error_t result = SUCCESS;
  bool send_completed = FALSE;
  bool start_it = FALSE;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 576
    {
      SerialP__txPending = 0;
      idle = SerialP__txState == SerialP__TXSTATE_IDLE;
      done = SerialP__txState == SerialP__TXSTATE_FINISH;
      fail = SerialP__txState == SerialP__TXSTATE_ERROR;
      if (done || fail) {
          SerialP__txState = SerialP__TXSTATE_IDLE;
          SerialP__txBuf[SerialP__txIndex].state = SerialP__BUFFER_AVAILABLE;
        }
    }
#line 585
    __nesc_atomic_end(__nesc_atomic); }


  if (done || fail) {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 589
        {
          SerialP__txSeqno++;
          if (SerialP__txProto == SERIAL_PROTO_ACK) {
              SerialP__ack_queue_pop();
            }
          else {
              result = done ? SUCCESS : FAIL;
              send_completed = TRUE;
            }
        }
#line 598
        __nesc_atomic_end(__nesc_atomic); }
      idle = TRUE;
    }


  if (idle) {
      bool goInactive;

#line 605
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 605
        goInactive = SerialP__offPending;
#line 605
        __nesc_atomic_end(__nesc_atomic); }
      if (goInactive) {
          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 607
            SerialP__txState = SerialP__TXSTATE_INACTIVE;
#line 607
            __nesc_atomic_end(__nesc_atomic); }
        }
      else {

          uint8_t myAckState;
          uint8_t myDataState;

#line 613
          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 613
            {
              myAckState = SerialP__txBuf[SerialP__TX_ACK_INDEX].state;
              myDataState = SerialP__txBuf[SerialP__TX_DATA_INDEX].state;
            }
#line 616
            __nesc_atomic_end(__nesc_atomic); }
          if (!SerialP__ack_queue_is_empty() && myAckState == SerialP__BUFFER_AVAILABLE) {
              { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 618
                {
                  SerialP__txBuf[SerialP__TX_ACK_INDEX].state = SerialP__BUFFER_COMPLETE;
                  SerialP__txBuf[SerialP__TX_ACK_INDEX].buf = SerialP__ack_queue_top();

                  SerialP__txProto = SERIAL_PROTO_ACK;
                  SerialP__txIndex = SerialP__TX_ACK_INDEX;
                  start_it = TRUE;
                }
#line 625
                __nesc_atomic_end(__nesc_atomic); }
            }
          else {
#line 627
            if (myDataState == SerialP__BUFFER_FILLING || myDataState == SerialP__BUFFER_COMPLETE) {
                { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 628
                  {
                    SerialP__txProto = SERIAL_PROTO_PACKET_NOACK;
                    SerialP__txIndex = SerialP__TX_DATA_INDEX;
                    start_it = TRUE;
                  }
#line 632
                  __nesc_atomic_end(__nesc_atomic); }
              }
            else {
              }
            }
        }
    }
  else {
    }


  if (send_completed) {
      SerialP__SendBytePacket__sendCompleted(result);
    }
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 646
    {
      if (SerialP__txState == SerialP__TXSTATE_INACTIVE) {
          SerialP__testOff();
          {
#line 649
            __nesc_atomic_end(__nesc_atomic); 
#line 649
            return;
          }
        }
    }
#line 652
    __nesc_atomic_end(__nesc_atomic); }
  if (start_it) {

      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 655
        {
          SerialP__txCRC = 0;
          SerialP__txByteCnt = 0;
          SerialP__txState = SerialP__TXSTATE_PROTO;
        }
#line 659
        __nesc_atomic_end(__nesc_atomic); }
      if (SerialP__SerialFrameComm__putDelimiter() != SUCCESS) {
          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 661
            SerialP__txState = SerialP__TXSTATE_ERROR;
#line 661
            __nesc_atomic_end(__nesc_atomic); }
          SerialP__MaybeScheduleTx();
        }
    }
}

# 75 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
inline static error_t /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__SubSend__send(message_t * msg, uint8_t len){
#line 75
  unsigned char __nesc_result;
#line 75

#line 75
  __nesc_result = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Send__send(IEEE154_TYPE_DATA, msg, len);
#line 75

#line 75
  return __nesc_result;
#line 75
}
#line 75
# 208 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/layers/Rf1aAckP.nc"
static inline void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ackWaitAlarmFired_task__runTask(void )
{
  bool signal_done = FALSE;

#line 211
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 211
    {
      signal_done = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_acked = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__TX_S_ACKED & /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_state;
      if (!/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_acked) {



          if (0 == /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_attempts_remaining--) {
              /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_result = ENOACK;
              signal_done = TRUE;
            }
        }
      if (!signal_done) {
          /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_state = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__TX_S_sending;
        }
    }
#line 225
    __nesc_atomic_end(__nesc_atomic); }
  if (!signal_done) {
      error_t rv = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__SubSend__send(/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_message, /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_length);

#line 228
      if (SUCCESS != rv) {
          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 229
            {



              signal_done = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__completeSend_atomic_(rv);
            }
#line 234
            __nesc_atomic_end(__nesc_atomic); }
        }
    }
  if (signal_done) {
      /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__signalSendDone_();
    }
}

# 59 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
static inline /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__phy_header_t */*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__header(message_t *msg)
#line 59
{
#line 59
  return (/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__phy_header_t *)(msg->data - sizeof(/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__phy_header_t ));
}

# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__sendFragment_task__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__sendFragment_task);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 424 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIf.nc"
inline static uint8_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(uint8_t instr){
#line 424
  unsigned char __nesc_result;
#line 424

#line 424
  __nesc_result = /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__strobe(instr);
#line 424

#line 424
  return __nesc_result;
#line 424
}
#line 424
# 137 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIfP.nc"
static inline uint16_t /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__getIn(void )
#line 137
{
  /* atomic removed: atomic calls only */
#line 137
  {
    unsigned int __nesc_temp = 
#line 137
    * (volatile uint16_t * )(3840U + 0x30);

#line 137
    return __nesc_temp;
  }
}

# 334 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIf.nc"
inline static uint16_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__getIn(void ){
#line 334
  unsigned int __nesc_result;
#line 334

#line 334
  __nesc_result = /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__getIn();
#line 334

#line 334
  return __nesc_result;
#line 334
}
#line 334
#line 438
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__writeRegister(uint8_t addr, uint8_t val){
#line 438
  /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__writeRegister(addr, val);
#line 438
}
#line 438
#line 431
inline static uint8_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(uint8_t addr){
#line 431
  unsigned char __nesc_result;
#line 431

#line 431
  __nesc_result = /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__readRegister(addr);
#line 431

#line 431
  return __nesc_result;
#line 431
}
#line 431
# 530 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline uint8_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__spinForValidRssi__(void )
{
  uint8_t rc;
  uint8_t mcsm1 = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(0x17);

#line 549
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__writeRegister(0x17, 0x10 | (0x0f & mcsm1));
  do {
      rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x3D);
    }
  while (
#line 552
  RF1A_S_RX == (RF1A_S_MASK & rc)
   && !((/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_clearChannel | /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_carrierSense) & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__getIn()));


  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__writeRegister(0x17, mcsm1);
  return rc;
}

#line 763
static inline int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__startTransmission_(bool with_cca, 
bool target_fstxon)
{
  int rv = SUCCESS;

  /* atomic removed: atomic calls only */
#line 767
  {
    uint8_t strobe = 0x35;
    uint8_t state = RF1A_S_TX;
    uint8_t rc;
    bool entered_rx = FALSE;
    register int16_t loop_limit = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__RADIO_LOOP_LIMIT;

    if (target_fstxon) {
        strobe = 0x31;
        state = RF1A_S_FSTXON;
      }

    rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x3D);
    if (with_cca) {

        if (RF1A_S_RX != (RF1A_S_MASK & rc)) {
            entered_rx = TRUE;
            rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x34);

            while (RF1A_S_RX != (RF1A_S_MASK & rc)
             && 0 <= --loop_limit) {
                rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x3D);
              }
          }

        if (RF1A_S_RX == (RF1A_S_MASK & rc)) {
            rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__spinForValidRssi__();
          }



        if (RF1A_S_RX != (RF1A_S_MASK & rc)) {
            rv = ERETRY;
          }
      }

    if (SUCCESS == rv) {





        (void )/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(strobe);
        do {
            rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x3D);


            if (
#line 812
            with_cca
             && RF1A_S_RX == (RF1A_S_MASK & rc)
             && !(/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_clearChannel & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__getIn())) {
                if (entered_rx) {
                    /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__resumeIdleMode_(TRUE);
                  }
                break;
              }
          }
        while (
#line 820
        RF1A_S_RX != (RF1A_S_MASK & rc)
         && RF1A_S_IDLE != (RF1A_S_MASK & rc)
         && state != (RF1A_S_MASK & rc)
         && 0 <= --loop_limit);
        if (state != (RF1A_S_MASK & rc)) {
            rv = ERETRY;
          }
      }
  }
  return rv;
}

# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveData_task__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveData_task);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 98 "/opt/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
inline static uint8_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ArbiterInfo__userId(void ){
#line 98
  unsigned char __nesc_result;
#line 98

#line 98
  __nesc_result = /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ArbiterInfo__userId();
#line 98

#line 98
  return __nesc_result;
#line 98
}
#line 98
#line 90
inline static bool /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ArbiterInfo__inUse(void ){
#line 90
  unsigned char __nesc_result;
#line 90

#line 90
  __nesc_result = /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ArbiterInfo__inUse();
#line 90

#line 90
  return __nesc_result;
#line 90
}
#line 90
# 850 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline error_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__send(uint8_t client, uint8_t *buffer, 
unsigned int length)
{
  uint8_t rc;


  if (!/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ArbiterInfo__inUse()) {
      return EOFF;
    }

  if (client != /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ArbiterInfo__userId()) {
      return EBUSY;
    }

  if (0 == length) {
      return EINVAL;
    }
  /* atomic removed: atomic calls only */
#line 867
  {
    bool variable_packet_length_mode;


    if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__RX_S_listening < /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_state) {
        rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x80 | 0x3D);









        if (
#line 880
        RF1A_S_IDLE == (RF1A_S_MASK & rc)
         && /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_received < /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_expected
         && 0 == (rc & RF1A_S_FIFOMASK)) {
            /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_result = FAIL;
            /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveData_task__postTask();
          }
        {
          unsigned char __nesc_temp = 
#line 886
          EBUSY;

#line 886
          return __nesc_temp;
        }
      }

    if (0 < /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_remain) {
        {
          unsigned char __nesc_temp = 
#line 891
          EBUSY;

#line 891
          return __nesc_temp;
        }
      }
#line 914
    if (
#line 912
    RF1A_S_RX == (RF1A_S_MASK & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x3D))
     && /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__TX_S_inactive == /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_state
     && 0 < /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(0x3A)) {

        /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__resetAndFlushTxFifo_();
      }



    if (!/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__transmitIsInactive_atomic_()) {
        {
          unsigned char __nesc_temp = 
#line 922
          ERETRY;

#line 922
          return __nesc_temp;
        }
      }


    variable_packet_length_mode = 0x01 == (0x03 & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(0x08));
    if (variable_packet_length_mode) {

        if (255 < length) {
            {
              unsigned char __nesc_temp = 
#line 931
              EINVAL;

#line 931
              return __nesc_temp;
            }
          }
      }





    rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x3D);
    if (RF1A_S_FSTXON != (rc & RF1A_S_MASK) && RF1A_S_TX != (rc & RF1A_S_MASK)) {

        int rv = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__startTransmission_(TRUE, TRUE);

#line 944
        if (SUCCESS != rv) {
            {
              unsigned char __nesc_temp = 
#line 945
              rv;

#line 945
              return __nesc_temp;
            }
          }
#line 947
        rc = RF1A_S_MASK & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x3D);
      }

    /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_remain = length;
    /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_result = SUCCESS;
    /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_state = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__TX_S_preparing;
    if (buffer) {
        /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_pos = buffer;
        /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_end = buffer + length;
      }
    else 
#line 956
      {
        /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_pos = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_end = 0;
      }
  }
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__sendFragment_task__postTask();
  return SUCCESS;
}

# 100 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
inline static error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__send(uint8_t *buffer, unsigned int length){
#line 100
  unsigned char __nesc_result;
#line 100

#line 100
  __nesc_result = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__send(/*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT, buffer, length);
#line 100

#line 100
  return __nesc_result;
#line 100
}
#line 100
# 289 "/usr/lib/ncc/nesc_nx.h"
static inline  void __nesc_bfle_encode16(uint8_t *msg, unsigned offset, uint8_t length, uint16_t x)
#line 289
{
#line 289
  unsigned byte_offset = offset >> 3;
#line 289
  unsigned bit_offset = offset & 7;
#line 289
  unsigned count = 0;

#line 289
  x = x & ((1 << length) - 1);
#line 289
  if (length + bit_offset <= 8) {
#line 289
      unsigned mask = ((1 << length) - 1) << bit_offset;

#line 289
      msg[byte_offset] = (msg[byte_offset] & ~mask) | (x << bit_offset);
#line 289
      return;
    }
#line 289
  if (bit_offset > 0) {
#line 289
      unsigned mask = (1 << bit_offset) - 1;

#line 289
      msg[byte_offset] = (msg[byte_offset] & mask) | (x << bit_offset);
#line 289
      count += 8 - bit_offset;
#line 289
      byte_offset++;
    }
#line 289
  while (count + 8 <= length) {
#line 289
      msg[byte_offset++] = x >> count;
#line 289
      count += 8;
    }
#line 289
  if (count < length) {
#line 289
      unsigned remaining = length - count;
#line 289
      unsigned mask = ~((1 << remaining) - 1);

#line 289
      msg[byte_offset] = (msg[byte_offset] & mask) | (x >> count);
    }
}

#line 289
static __inline  uint16_t __nesc_htonbf_leuint16(void *target, unsigned offset, uint8_t length, uint16_t value)
#line 289
{
#line 289
  __nesc_bfle_encode16(target, offset, length, value);
#line 289
  return value;
}

# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
inline static uint16_t /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430Timer__get(void ){
#line 45
  unsigned int __nesc_result;
#line 45

#line 45
  __nesc_result = /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Timer__get();
#line 45

#line 45
  return __nesc_result;
#line 45
}
#line 45
# 104 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430AlarmC.nc"
static inline uint16_t /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__getNow(void )
{
  return /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430Timer__get();
}

#line 60
static inline void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__start(uint16_t dt)
{
  /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__startAt(/*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__getNow(), dt);
}

# 66 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckWaitAlarm__start(/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckWaitAlarm__size_type dt){
#line 66
  /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__start(dt);
#line 66
}
#line 66
# 178 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/layers/Rf1aAckP.nc"
static inline void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__transitionToWaiting_atomic_(void )
{
  /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckWaitAlarm__start(/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__CFG_macAckWaitDuration_32k);
  /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_state = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__TX_S_waiting;
}

# 45 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
inline static uint16_t /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Timer__get(void ){
#line 45
  unsigned int __nesc_result;
#line 45

#line 45
  __nesc_result = /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Timer__get();
#line 45

#line 45
  return __nesc_result;
#line 45
}
#line 45
# 165 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Compare__setEventFromNow(uint16_t x)
{
  * (volatile uint16_t * )852U = /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Timer__get() + x;
}

# 43 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430Compare__setEventFromNow(uint16_t delta){
#line 43
  /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Compare__setEventFromNow(delta);
#line 43
}
#line 43
# 155 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Compare__setEvent(uint16_t x)
{
  * (volatile uint16_t * )852U = x;
}

# 41 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430Compare__setEvent(uint16_t time){
#line 41
  /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Compare__setEvent(time);
#line 41
}
#line 41
# 95 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Control__clearPendingInterrupt(void )
{
  * (volatile uint16_t * )836U &= ~0x0001;
}

# 44 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
inline static void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430TimerControl__clearPendingInterrupt(void ){
#line 44
  /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Control__clearPendingInterrupt();
#line 44
}
#line 44
# 130 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline void /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Control__enableEvents(void )
{
  * (volatile uint16_t * )836U |= 0x0010;
}

# 57 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
inline static void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430TimerControl__enableEvents(void ){
#line 57
  /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Control__enableEvents();
#line 57
}
#line 57
# 65 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__nextPacket(void )
#line 65
{
  uint8_t i;

#line 67
  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current = (/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current + 1) % 1;
  for (i = 0; i < 1; i++) {
      if (/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current].msg == (void *)0 || 
      /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__cancelMask[/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current / 8] & (1 << /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current % 8)) 
        {
          /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current = (/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current + 1) % 1;
        }
      else {
          break;
        }
    }
  if (i >= 1) {
#line 78
    /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current = 1;
    }
}

# 276 "/usr/lib/ncc/nesc_nx.h"
static __inline  uint16_t __nesc_ntoh_leuint16(const void * source)
#line 276
{
  const uint8_t *base = source;

#line 278
  return ((uint16_t )base[1] << 8) | base[0];
}

# 93 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aIeee154PacketP.nc"
static inline const /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__metadata_t */*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__cmetadata_(const message_t *msg)
#line 93
{
#line 93
  return (const rf1a_metadata_t *)msg->metadata;
}

#line 156
static inline uint8_t /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Packet__payloadLength(message_t *msg)
#line 156
{
#line 156
  return __nesc_ntoh_leuint16(/*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__cmetadata_(msg)->payload_length.data) - sizeof(/*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__header_t );
}

# 78 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
inline static uint8_t Rf1aAMPacketP__SubPacket__payloadLength(message_t * msg){
#line 78
  unsigned char __nesc_result;
#line 78

#line 78
  __nesc_result = /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Packet__payloadLength(msg);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 74 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aAMPacketP.nc"
static inline uint8_t Rf1aAMPacketP__Packet__payloadLength(message_t *msg)
#line 74
{
#line 74
  return Rf1aAMPacketP__SubPacket__payloadLength(msg) - sizeof(Rf1aAMPacketP__layer_header_t );
}

# 78 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
inline static uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Packet__payloadLength(message_t * msg){
#line 78
  unsigned char __nesc_result;
#line 78

#line 78
  __nesc_result = Rf1aAMPacketP__Packet__payloadLength(msg);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 251 "/usr/lib/ncc/nesc_nx.h"
static __inline  uint8_t __nesc_hton_leuint8(void * target, uint8_t value)
#line 251
{
  uint8_t *base = target;

#line 253
  base[0] = value;
  return value;
}

#line 281
static __inline  uint16_t __nesc_hton_leuint16(void * target, uint16_t value)
#line 281
{
  uint8_t *base = target;

#line 283
  base[0] = value;
  base[1] = value >> 8;
  return value;
}

# 92 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aIeee154PacketP.nc"
static inline /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__metadata_t */*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__metadata_(message_t *msg)
#line 92
{
#line 92
  return (rf1a_metadata_t *)msg->metadata;
}

#line 85
static inline /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__header_t */*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__header(message_t *msg)
#line 85
{
#line 85
  return (/*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__header_t *)(msg->data - sizeof(/*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__header_t ));
}










static inline void /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Rf1aPacket__configureAsData(message_t *msg)
{
  /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__header_t *hp = /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__header(msg);
  /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__metadata_t *mp = /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__metadata_(msg);




  __nesc_hton_leuint16(hp->fcf.data, (__nesc_ntoh_leuint16(hp->fcf.data) & /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__FCF_PRESERVE) | /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__FCF_FIXED);
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 106
    {
      __nesc_hton_leuint8(hp->dsn.data, /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__macDSN++);
    }
#line 108
    __nesc_atomic_end(__nesc_atomic); }



  __nesc_hton_leuint8(mp->rssi.data, __nesc_hton_leuint8(mp->lqi.data, 0));
}

# 57 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aPacket.nc"
inline static void Rf1aActiveMessageP__Rf1aPacket__configureAsData(message_t *msg){
#line 57
  /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Rf1aPacket__configureAsData(msg);
#line 57
}
#line 57
# 127 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aIeee154PacketP.nc"
static inline void /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__setSource(message_t *msg, ieee154_saddr_t addr)
#line 127
{
#line 127
  __nesc_hton_leuint16(/*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__header(msg)->src.data, addr);
}

# 45 "/opt/tinyos-2.x/tos/interfaces/Ieee154Packet.nc"
inline static void Rf1aAMPacketP__Ieee154Packet__setSource(message_t *msg, ieee154_saddr_t addr){
#line 45
  /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__setSource(msg, addr);
#line 45
}
#line 45
# 81 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aAMPacketP.nc"
static inline void Rf1aAMPacketP__AMPacket__setSource(message_t *amsg, am_addr_t addr)
#line 81
{
#line 81
  Rf1aAMPacketP__Ieee154Packet__setSource(amsg, addr);
}

# 121 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
inline static void Rf1aActiveMessageP__AMPacket__setSource(message_t * amsg, am_addr_t addr){
#line 121
  Rf1aAMPacketP__AMPacket__setSource(amsg, addr);
#line 121
}
#line 121
# 48 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/interfaces/Ieee154Address.nc"
inline static ieee154_saddr_t Ieee154AMAddressP__Ieee154Address__shortAddress(void ){
#line 48
  unsigned int __nesc_result;
#line 48

#line 48
  __nesc_result = Ieee154AddressP__Ieee154Address__shortAddress();
#line 48

#line 48
  return __nesc_result;
#line 48
}
#line 48
# 55 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/system/Ieee154AMAddressP.nc"
static inline am_addr_t Ieee154AMAddressP__ActiveMessageAddress__amAddress(void )
{
  return (am_addr_t )Ieee154AMAddressP__Ieee154Address__shortAddress();
}

# 50 "/opt/tinyos-2.x/tos/interfaces/ActiveMessageAddress.nc"
inline static am_addr_t Rf1aAMPacketP__ActiveMessageAddress__amAddress(void ){
#line 50
  unsigned int __nesc_result;
#line 50

#line 50
  __nesc_result = Ieee154AMAddressP__ActiveMessageAddress__amAddress();
#line 50

#line 50
  return __nesc_result;
#line 50
}
#line 50
# 77 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aAMPacketP.nc"
static inline am_addr_t Rf1aAMPacketP__AMPacket__address(void )
#line 77
{
#line 77
  return Rf1aAMPacketP__ActiveMessageAddress__amAddress();
}

# 68 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
inline static am_addr_t Rf1aActiveMessageP__AMPacket__address(void ){
#line 68
  unsigned int __nesc_result;
#line 68

#line 68
  __nesc_result = Rf1aAMPacketP__AMPacket__address();
#line 68

#line 68
  return __nesc_result;
#line 68
}
#line 68
# 146 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aIeee154PacketP.nc"
static inline void /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__setPan(message_t *msg, ieee154_panid_t grp)
#line 146
{
#line 146
  __nesc_hton_leuint16(/*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__header(msg)->destpan.data, grp);
}

# 51 "/opt/tinyos-2.x/tos/interfaces/Ieee154Packet.nc"
inline static void Rf1aActiveMessageP__Ieee154Packet__setPan(message_t *msg, ieee154_panid_t grp){
#line 51
  /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__setPan(msg, grp);
#line 51
}
#line 51
# 59 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/system/Ieee154AddressP.nc"
static inline ieee154_panid_t Ieee154AddressP__Ieee154Address__panId(void )
#line 59
{
#line 59
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 59
    {
      unsigned int __nesc_temp = 
#line 59
      Ieee154AddressP__pan_id;

      {
#line 59
        __nesc_atomic_end(__nesc_atomic); 
#line 59
        return __nesc_temp;
      }
    }
#line 61
    __nesc_atomic_end(__nesc_atomic); }
}

# 51 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/interfaces/Ieee154Address.nc"
inline static ieee154_panid_t /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Address__panId(void ){
#line 51
  unsigned int __nesc_result;
#line 51

#line 51
  __nesc_result = Ieee154AddressP__Ieee154Address__panId();
#line 51

#line 51
  return __nesc_result;
#line 51
}
#line 51
# 147 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aIeee154PacketP.nc"
static inline ieee154_panid_t /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__localPan(void )
#line 147
{
#line 147
  return /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Address__panId();
}

# 53 "/opt/tinyos-2.x/tos/interfaces/Ieee154Packet.nc"
inline static ieee154_panid_t Rf1aActiveMessageP__Ieee154Packet__localPan(void ){
#line 53
  unsigned int __nesc_result;
#line 53

#line 53
  __nesc_result = /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__localPan();
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53
# 126 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aIeee154PacketP.nc"
static inline void /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__setDestination(message_t *msg, ieee154_saddr_t addr)
#line 126
{
#line 126
  __nesc_hton_leuint16(/*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__header(msg)->dest.data, addr);
}

# 43 "/opt/tinyos-2.x/tos/interfaces/Ieee154Packet.nc"
inline static void Rf1aAMPacketP__Ieee154Packet__setDestination(message_t *msg, ieee154_saddr_t addr){
#line 43
  /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__setDestination(msg, addr);
#line 43
}
#line 43
# 80 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aAMPacketP.nc"
static inline void Rf1aAMPacketP__AMPacket__setDestination(message_t *amsg, am_addr_t addr)
#line 80
{
#line 80
  Rf1aAMPacketP__Ieee154Packet__setDestination(amsg, addr);
}

# 103 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
inline static void Rf1aActiveMessageP__AMPacket__setDestination(message_t * amsg, am_addr_t addr){
#line 103
  Rf1aAMPacketP__AMPacket__setDestination(amsg, addr);
#line 103
}
#line 103
#line 162
inline static void Rf1aActiveMessageP__AMPacket__setType(message_t * amsg, am_id_t t){
#line 162
  Rf1aAMPacketP__AMPacket__setType(amsg, t);
#line 162
}
#line 162
# 105 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aActiveMessageP.nc"
static inline void Rf1aActiveMessageP__SendNotifier__default__aboutToSend(am_id_t amId, am_addr_t addr, message_t *msg)
#line 105
{
}

# 59 "/opt/tinyos-2.x/tos/interfaces/SendNotifier.nc"
inline static void Rf1aActiveMessageP__SendNotifier__aboutToSend(am_id_t arg_0x41015d78, am_addr_t dest, message_t * msg){
#line 59
    Rf1aActiveMessageP__SendNotifier__default__aboutToSend(arg_0x41015d78, dest, msg);
#line 59
}
#line 59
# 289 "/usr/lib/ncc/nesc_nx.h"
static inline  uint16_t __nesc_bfle_decode16(const uint8_t *msg, unsigned offset, uint8_t length)
#line 289
{
#line 289
  uint16_t x = 0;
#line 289
  unsigned byte_offset = offset >> 3;
#line 289
  unsigned bit_offset = offset & 7;
#line 289
  unsigned count = 0;

#line 289
  if (length + bit_offset <= 8) {
#line 289
    return (msg[byte_offset] >> bit_offset) & ((1 << length) - 1);
    }
#line 289
  if (bit_offset > 0) {
#line 289
      x = msg[byte_offset++] >> bit_offset;
#line 289
      count += 8 - bit_offset;
    }
#line 289
  while (count + 8 <= length) {
#line 289
      x |= (uint16_t )(msg[byte_offset++] << count);
#line 289
      count += 8;
    }
#line 289
  if (count < length) {
#line 289
    x |= (uint16_t )(msg[byte_offset] & ((1 << (length - count)) - 1)) << count;
    }
#line 289
  return x;
}

#line 289
static __inline  uint16_t __nesc_ntohbf_leuint16(const void *source, unsigned offset, uint8_t length)
#line 289
{
#line 289
  return __nesc_bfle_decode16(source, offset, length);
}

# 24 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/layers/Rf1aAckP.nc"
static inline /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__phy_header_t */*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__header(message_t *msg)
#line 24
{
#line 24
  return (/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__phy_header_t *)(msg->data - sizeof(/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__phy_header_t ));
}

#line 242
static inline error_t /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__Send__send(message_t *msg, uint8_t len)
{
  error_t rv = SUCCESS;
  bool need_ack = FALSE;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 247
    {
      /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__phy_header_t *hp = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__header(msg);
      ieee154_fcf_t *fcfp = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__fcf(msg);



      if (/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__TX_S_idle != /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_state) {
          {
            unsigned char __nesc_temp = 
#line 254
            EBUSY;

            {
#line 254
              __nesc_atomic_end(__nesc_atomic); 
#line 254
              return __nesc_temp;
            }
          }
        }






      if (
#line 262
      IEEE154_TYPE_DATA == __nesc_ntohbf_leuint16((unsigned char *)&(*fcfp), 0, 3)
       && __nesc_ntohbf_leuint16((unsigned char *)&(*fcfp), 5, 1)
       && IEEE154_BROADCAST_ADDR != __nesc_ntoh_leuint16(hp->dest.data)) {

          need_ack = TRUE;
          /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_state = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__TX_S_sending;
        }


      /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_acked = FALSE;
    }
#line 272
    __nesc_atomic_end(__nesc_atomic); }
  rv = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__SubSend__send(msg, len);



  if (need_ack) {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 278
        {
          if (SUCCESS == rv) {



              /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_attempts_remaining = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__CFG_macMaxFrameRetries;
              /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_message = msg;
              /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_length = len;
              /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_result = SUCCESS;
            }
          else 
#line 287
            {


              /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_state = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__TX_S_idle;
            }
        }
#line 292
        __nesc_atomic_end(__nesc_atomic); }
    }

  return rv;
}

# 75 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
inline static error_t Rf1aActiveMessageP__SubSend__send(message_t * msg, uint8_t len){
#line 75
  unsigned char __nesc_result;
#line 75

#line 75
  __nesc_result = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__Send__send(msg, len);
#line 75

#line 75
  return __nesc_result;
#line 75
}
#line 75
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
inline static error_t TestSenderP__reportTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(TestSenderP__reportTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
inline static error_t TestSenderP__nextConfigTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(TestSenderP__nextConfigTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 116 "TestSenderP.nc"
static inline void TestSenderP__SplitControl__stopDone(error_t err)
#line 116
{



  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 120
    {
      TestSenderP__radioOn = FALSE;
      TestSenderP__state = TestSenderP__S_START_NEXTCONFIG;
      TestSenderP__nextConfigTask__postTask();
    }
#line 124
    __nesc_atomic_end(__nesc_atomic); }
}

# 138 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SplitControl__stopDone(error_t error){
#line 138
  TestSenderP__SplitControl__stopDone(error);
#line 138
}
#line 138
# 201 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__stopDone_task__runTask(void )
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 203
    /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__split_control_state = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SCS_off;
#line 203
    __nesc_atomic_end(__nesc_atomic); }
  /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SplitControl__stopDone(SUCCESS);
}

# 421 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/layers/Rf1aAckP.nc"
static inline void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckSend__sendDone(message_t *msg, error_t error)
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 423
    {



      if (/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__RX_S_transmitting == /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__rx_state) {
          /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__rx_state = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__RX_S_idle;
        }
    }
#line 430
    __nesc_atomic_end(__nesc_atomic); }
}

# 110 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static void Rf1aActiveMessageP__AMSend__sendDone(am_id_t arg_0x40ffa678, message_t * msg, error_t error){
#line 110
  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__sendDone(arg_0x40ffa678, msg, error);
#line 110
}
#line 110
# 88 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aActiveMessageP.nc"
static inline void Rf1aActiveMessageP__SubSend__sendDone(message_t *msg, error_t error)
{
  Rf1aActiveMessageP__AMSend__sendDone(Rf1aActiveMessageP__AMPacket__type(msg), msg, error);
}

# 100 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
inline static void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__Send__sendDone(message_t * msg, error_t error){
#line 100
  Rf1aActiveMessageP__SubSend__sendDone(msg, error);
#line 100
}
#line 100
# 317 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/layers/Rf1aAckP.nc"
static inline void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__SubSend__sendDone(message_t *msg, error_t error)
{
  bool do_bypass_signal = TRUE;
  bool do_state_signal = FALSE;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 322
    {
      uint8_t bare_state = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__TX_S_MASK & /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_state;



      if (/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__TX_S_sending == bare_state) {



          do_bypass_signal = FALSE;
          do_state_signal = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__completeSend_atomic_(error);
        }
    }
#line 334
    __nesc_atomic_end(__nesc_atomic); }
  if (do_state_signal) {
      /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__signalSendDone_();
    }
  else {
#line 337
    if (do_bypass_signal) {
        /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__Send__sendDone(msg, error);
      }
    }
}

# 312 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Send__default__sendDone(uint8_t frame_type, message_t *msg, error_t error)
#line 312
{
}

# 100 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
inline static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Send__sendDone(uint8_t arg_0x40f45d50, message_t * msg, error_t error){
#line 100
  switch (arg_0x40f45d50) {
#line 100
    case IEEE154_TYPE_DATA:
#line 100
      /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__SubSend__sendDone(msg, error);
#line 100
      break;
#line 100
    case IEEE154_TYPE_ACK:
#line 100
      /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckSend__sendDone(msg, error);
#line 100
      break;
#line 100
    default:
#line 100
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Send__default__sendDone(arg_0x40f45d50, msg, error);
#line 100
      break;
#line 100
    }
#line 100
}
#line 100
# 249 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__sendDone_task__runTask(void )
{
  message_t *msg;
  int result;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 254
    {
      result = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__tx_result;
      msg = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__tx_message;
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__tx_message = 0;
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__tx_state = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__TXS_idle;
    }
#line 259
    __nesc_atomic_end(__nesc_atomic); }
  /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Send__sendDone(__nesc_ntohbf_leuint16((unsigned char *)&(*/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__fcf(msg)), 0, 3), msg, result);
}

# 246 "/usr/lib/ncc/nesc_nx.h"
static __inline  uint8_t __nesc_ntoh_leuint8(const void * source)
#line 246
{
  const uint8_t *base = source;

#line 248
  return base[0];
}

# 95 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aIeee154PacketP.nc"
static inline rf1a_metadata_t */*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Rf1aPacket__metadata(message_t *msg)
#line 95
{
#line 95
  return /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__metadata_(msg);
}

# 47 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aPacket.nc"
inline static rf1a_metadata_t */*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__Rf1aPacket__metadata(message_t *msg){
#line 47
  nx_struct rf1a_metadata_t *__nesc_result;
#line 47

#line 47
  __nesc_result = /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Rf1aPacket__metadata(msg);
#line 47

#line 47
  return __nesc_result;
#line 47
}
#line 47
# 67 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysicalMetadata.nc"
inline static void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__Rf1aPhysicalMetadata__store(rf1a_metadata_t *metadatap){
#line 67
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysicalMetadata__store(metadatap);
#line 67
}
#line 67
# 390 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/layers/Rf1aAckP.nc"
static inline message_t */*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckReceive__receive(message_t *msg, void *payload, uint8_t len)
{
  /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__phy_header_t *hp = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__header(msg);

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 394
    {
      uint8_t bare_state = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__TX_S_MASK & /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_state;

#line 396
      if (/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__TX_S_idle != bare_state && !(/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__TX_S_ACKED & /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_state)) {
          /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ack_t *ap = (/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ack_t *)/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__header(/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_message);
          bool acked = __nesc_ntoh_leuint16(hp->src.data) == __nesc_ntoh_leuint16(ap->dest.data)
           && __nesc_ntoh_leuint16(hp->dest.data) == __nesc_ntoh_leuint16(ap->src.data)
           && __nesc_ntoh_leuint8(hp->dsn.data) == __nesc_ntoh_leuint8(ap->dsn.data);

#line 401
          if (acked) {





              /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_state |= /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__TX_S_ACKED;
              /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_result = SUCCESS;
              if (/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__TX_S_waiting == bare_state) {
                  /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckWaitAlarm__start(0);
                }

              /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__Rf1aPhysicalMetadata__store(/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__Rf1aPacket__metadata(/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_message));
            }
        }
    }
#line 416
    __nesc_atomic_end(__nesc_atomic); }
  return msg;
}

# 104 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aActiveMessageP.nc"
static inline message_t *Rf1aActiveMessageP__Snoop__default__receive(am_id_t id, message_t *msg, void *payload, uint8_t len)
#line 104
{
#line 104
  return msg;
}

# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
inline static message_t * Rf1aActiveMessageP__Snoop__receive(am_id_t arg_0x41015700, message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
    __nesc_result = Rf1aActiveMessageP__Snoop__default__receive(arg_0x41015700, msg, payload, len);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 103 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aActiveMessageP.nc"
static inline message_t *Rf1aActiveMessageP__Receive__default__receive(am_id_t id, message_t *msg, void *payload, uint8_t len)
#line 103
{
#line 103
  return msg;
}

# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
inline static message_t * Rf1aActiveMessageP__Receive__receive(am_id_t arg_0x41015068, message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
    __nesc_result = Rf1aActiveMessageP__Receive__default__receive(arg_0x41015068, msg, payload, len);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 124 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aIeee154PacketP.nc"
static inline ieee154_saddr_t /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__destination(message_t *msg)
#line 124
{
#line 124
  return __nesc_ntoh_leuint16(/*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__header(msg)->dest.data);
}

# 39 "/opt/tinyos-2.x/tos/interfaces/Ieee154Packet.nc"
inline static ieee154_saddr_t Rf1aAMPacketP__Ieee154Packet__destination(message_t *msg){
#line 39
  unsigned int __nesc_result;
#line 39

#line 39
  __nesc_result = /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Ieee154Packet__destination(msg);
#line 39

#line 39
  return __nesc_result;
#line 39
}
#line 39
# 78 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aAMPacketP.nc"
static inline am_addr_t Rf1aAMPacketP__AMPacket__destination(message_t *amsg)
#line 78
{
#line 78
  return Rf1aAMPacketP__Ieee154Packet__destination(amsg);
}


static inline bool Rf1aAMPacketP__AMPacket__isForMe(message_t *amsg)
{
  return Rf1aAMPacketP__AMPacket__destination(amsg) == Rf1aAMPacketP__AMPacket__address() || 
  Rf1aAMPacketP__AMPacket__destination(amsg) == AM_BROADCAST_ADDR;
}

# 136 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
inline static bool Rf1aActiveMessageP__AMPacket__isForMe(message_t * amsg){
#line 136
  unsigned char __nesc_result;
#line 136

#line 136
  __nesc_result = Rf1aAMPacketP__AMPacket__isForMe(amsg);
#line 136

#line 136
  return __nesc_result;
#line 136
}
#line 136
# 93 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aActiveMessageP.nc"
static inline message_t *Rf1aActiveMessageP__SubReceive__receive(message_t *msg, void *payload_, uint8_t len)
{
  uint8_t *payload = (uint8_t *)payload_ + sizeof(Rf1aActiveMessageP__layer_header_t );

#line 96
  len -= sizeof(Rf1aActiveMessageP__layer_header_t );
  if (Rf1aActiveMessageP__AMPacket__isForMe(msg)) {
      return Rf1aActiveMessageP__Receive__receive(Rf1aActiveMessageP__AMPacket__type(msg), msg, payload, len);
    }
  return Rf1aActiveMessageP__Snoop__receive(Rf1aActiveMessageP__AMPacket__type(msg), msg, payload, len);
}

# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
inline static message_t * UniqueReceiveP__Receive__receive(message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
  __nesc_result = Rf1aActiveMessageP__SubReceive__receive(msg, payload, len);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 92 "/opt/tinyos-2.x/tos/lib/util/keyvaluerecord/KeyValueRecordP.nc"
static inline void KeyValueRecordP__KeyValueRecord__insert(uint8_t client, uint16_t key, uint16_t value)
#line 92
{
  KeyValueRecordP__client_record_t *crp = KeyValueRecordP__client_data + client;


  if (client >= KeyValueRecordP__NUM_CLIENTS) {
      return;
    }
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 99
    {
      KeyValueRecordP__key_value_record_t *rp = crp->history + crp->write_index;

#line 101
      rp->key = key;
      rp->value = value;

      if (crp->size < sizeof  crp->history / sizeof  (* crp->history)) {
          crp->size += 1;
          if (crp->size < sizeof  crp->history / sizeof  (* crp->history)) {
              crp->write_index += 1;
            }
          else 
#line 108
            {
              crp->write_index = 0;
            }
        }
      else 
#line 111
        {
          crp->write_index = (crp->write_index + 1) % crp->size;
        }
    }
#line 114
    __nesc_atomic_end(__nesc_atomic); }
}

# 56 "/opt/tinyos-2.x/tos/lib/util/keyvaluerecord/KeyValueRecord.nc"
inline static void UniqueReceiveP__KeyValueRecord__insert(uint16_t key, uint16_t value){
#line 56
  KeyValueRecordP__KeyValueRecord__insert(0U, key, value);
#line 56
}
#line 56
# 76 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/layers/UniqueReceiveP.nc"
static inline message_t *UniqueReceiveP__DuplicateReceive__default__receive(message_t *msg, void *payload, uint8_t len)
#line 76
{
  return msg;
}

# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
inline static message_t * UniqueReceiveP__DuplicateReceive__receive(message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
  __nesc_result = UniqueReceiveP__DuplicateReceive__default__receive(msg, payload, len);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 68 "/opt/tinyos-2.x/tos/lib/util/keyvaluerecord/KeyValueRecordP.nc"
static inline bool KeyValueRecordP__KeyValueRecord__hasSeen(uint8_t client, uint16_t key, uint16_t value)
#line 68
{
  int i;
  KeyValueRecordP__client_record_t *crp = KeyValueRecordP__client_data + client;


  if (client >= KeyValueRecordP__NUM_CLIENTS) {
      return FALSE;
    }
  for (i = 0; i < crp->size; ++i) {
      KeyValueRecordP__key_value_record_t *rp = crp->history + i;

#line 78
      if (rp->key == key && rp->value == value) {

          return TRUE;
        }
    }

  return FALSE;
}

# 48 "/opt/tinyos-2.x/tos/lib/util/keyvaluerecord/KeyValueRecord.nc"
inline static bool UniqueReceiveP__KeyValueRecord__hasSeen(uint16_t key, uint16_t value){
#line 48
  unsigned char __nesc_result;
#line 48

#line 48
  __nesc_result = KeyValueRecordP__KeyValueRecord__hasSeen(0U, key, value);
#line 48

#line 48
  return __nesc_result;
#line 48
}
#line 48
# 59 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/layers/UniqueReceiveP.nc"
static inline UniqueReceiveP__header_t *UniqueReceiveP__header(message_t *msg)
#line 59
{
#line 59
  return -1 + (UniqueReceiveP__header_t *)msg->data;
}

static inline message_t *UniqueReceiveP__SubReceive__receive(message_t *msg, void *payload, 
uint8_t len)
#line 63
{
  UniqueReceiveP__header_t *hp = UniqueReceiveP__header(msg);
  uint16_t msgSource = __nesc_ntoh_leuint16(hp->src.data);
  uint8_t msgDsn = __nesc_ntoh_leuint8(hp->dsn.data);

  if (UniqueReceiveP__KeyValueRecord__hasSeen(msgSource, msgDsn)) {
      return UniqueReceiveP__DuplicateReceive__receive(msg, payload, len);
    }
  UniqueReceiveP__KeyValueRecord__insert(msgSource, msgDsn);
  return UniqueReceiveP__Receive__receive(msg, payload, len);
}

# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
inline static message_t * /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__Receive__receive(message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
  __nesc_result = UniqueReceiveP__SubReceive__receive(msg, payload, len);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 75 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
inline static error_t /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckSend__send(message_t * msg, uint8_t len){
#line 75
  unsigned char __nesc_result;
#line 75

#line 75
  __nesc_result = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Send__send(IEEE154_TYPE_ACK, msg, len);
#line 75

#line 75
  return __nesc_result;
#line 75
}
#line 75
# 354 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/layers/Rf1aAckP.nc"
static inline message_t */*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__SubReceive__receive(message_t *msg, void *payload, uint8_t len)
{
  /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__phy_header_t *hp = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__header(msg);
  ieee154_fcf_t *fcfp = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__fcf(msg);

  if (__nesc_ntohbf_leuint16((unsigned char *)&(*fcfp), 5, 1)) {


      bool invoke_send = FALSE;

#line 363
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 363
        {
          if (/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__RX_S_idle == /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__rx_state) {
              /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ack_t *ap = (/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ack_t *)/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__header((message_t *)&/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ack_message);

#line 366
              *ap = *hp;


              __nesc_hton_leuint16(ap->fcf.data, (__nesc_ntoh_leuint16(ap->fcf.data) & /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__FCF_ACK_PRESERVE) | /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__FCF_ACK_FIXED);
              __nesc_hton_leuint16(ap->dest.data, __nesc_ntoh_leuint16(hp->src.data));
              __nesc_hton_leuint16(ap->src.data, __nesc_ntoh_leuint16(hp->dest.data));
              /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__rx_state = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__RX_S_transmitting;
              invoke_send = TRUE;
            }
        }
#line 375
        __nesc_atomic_end(__nesc_atomic); }
      if (invoke_send) {
          error_t rv = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckSend__send((message_t *)&/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ack_message, 0);

#line 378
          if (SUCCESS != rv) {


              { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 381
                {
                  /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__rx_state = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__RX_S_idle;
                }
#line 383
                __nesc_atomic_end(__nesc_atomic); }
            }
        }
    }
  return /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__Receive__receive(msg, payload, len);
}

# 325 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
static inline message_t */*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Receive__default__receive(uint8_t frame_type, message_t *msg, void *payload, uint8_t len)
#line 325
{
#line 325
  return msg;
}

# 78 "/opt/tinyos-2.x/tos/interfaces/Receive.nc"
inline static message_t * /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Receive__receive(uint8_t arg_0x40f42798, message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
  switch (arg_0x40f42798) {
#line 78
    case IEEE154_TYPE_DATA:
#line 78
      __nesc_result = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__SubReceive__receive(msg, payload, len);
#line 78
      break;
#line 78
    case IEEE154_TYPE_ACK:
#line 78
      __nesc_result = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__AckReceive__receive(msg, payload, len);
#line 78
      break;
#line 78
    default:
#line 78
      __nesc_result = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Receive__default__receive(arg_0x40f42798, msg, payload, len);
#line 78
      break;
#line 78
    }
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 67 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysicalMetadata.nc"
inline static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysicalMetadata__store(rf1a_metadata_t *metadatap){
#line 67
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysicalMetadata__store(metadatap);
#line 67
}
#line 67
# 47 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aPacket.nc"
inline static rf1a_metadata_t */*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPacket__metadata(message_t *msg){
#line 47
  nx_struct rf1a_metadata_t *__nesc_result;
#line 47

#line 47
  __nesc_result = /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Rf1aPacket__metadata(msg);
#line 47

#line 47
  return __nesc_result;
#line 47
}
#line 47
# 68 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
static inline /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__metadata_t */*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__metadata(message_t *msg)
#line 68
{
#line 68
  return /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPacket__metadata(msg);
}

#line 329
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__receiveDone_task__runTask(void )
{
  unsigned int count;
  unsigned int payload_length;
  message_t *mp;
  uint8_t frame_type;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 336
    {
      mp = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__rx_message;
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__rx_message = 0;
      count = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__rx_count;
    }
#line 340
    __nesc_atomic_end(__nesc_atomic); }
  frame_type = __nesc_ntohbf_leuint16((unsigned char *)&(*/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__fcf(mp)), 0, 3);


  payload_length = count - sizeof(/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__phy_header_t );
  if (IEEE154_TYPE_DATA == frame_type) {
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__metadata_t *mdp = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__metadata(mp);

#line 347
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysicalMetadata__store(mdp);
      __nesc_hton_leuint16(mdp->payload_length.data, count);
    }
#line 362
  /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__setReceiveBuffer(/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Receive__receive(frame_type, mp, mp->data, payload_length));
}

# 834 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__startReception_(void )
{
  uint8_t rc;

  /* atomic removed: atomic calls only */
#line 838
  {
    /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_state = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__RX_S_listening;

    if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__transmitIsInactive_atomic_()) {
        rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x34);
        while (RF1A_S_RX != (RF1A_S_MASK & rc)) {
            rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x3D);
          }
      }
  }
}

#line 1276
static inline error_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__setReceiveBuffer(uint8_t client, uint8_t *buffer, 
unsigned int length, 
bool single_use)
{

  if (!/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ArbiterInfo__inUse()) {
      return EOFF;
    }

  if (client != /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ArbiterInfo__userId()) {
      return EBUSY;
    }


  if (!buffer || 0 == length) {
      buffer = 0;
      length = 0;
    }
  /* atomic removed: atomic calls only */
#line 1294
  {


    if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos && /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__RX_S_listening < /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_state) {
        {
          unsigned char __nesc_temp = 
#line 1298
          EBUSY;

#line 1298
          return __nesc_temp;
        }
      }
    /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos = buffer;
    /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos_end = buffer + length;
    /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_start = 0;
    /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_single_use = single_use;

    if (0 == /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos) {

        /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__writeRegister(0x17, 0xf0 & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(0x17));



        if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__RX_S_listening < /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_state) {
            /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_result = ECANCEL;
            /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveData_task__postTask();
          }
        else 
#line 1315
          {
            /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_state = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__RX_S_inactive;

            if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__transmitIsInactive_atomic_()) {
                /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__resumeIdleMode_(TRUE);
              }
          }
      }
    else {
#line 1322
      if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__RX_S_inactive == /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_state) {
          uint8_t off_mode;

          if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_single_use) {

              off_mode = 0x03;
            }
          else 
#line 1328
            {

              off_mode = 0x0F;
            }
          /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__writeRegister(0x17, off_mode | (0xf0 & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(0x17)));
          /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__startReception_();
        }
      }
  }
#line 1336
  return SUCCESS;
}

# 253 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
inline static error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__setReceiveBuffer(uint8_t *buffer, unsigned int length, bool single_use){
#line 253
  unsigned char __nesc_result;
#line 253

#line 253
  __nesc_result = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__setReceiveBuffer(/*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT, buffer, length, single_use);
#line 253

#line 253
  return __nesc_result;
#line 253
}
#line 253
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t TestSenderP__reportDSSR__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(TestSenderP__reportDSSR);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 3 "/opt/tinyos-2.x/tos/lib/rf1a-multi/DelayedSendRf1aPhysical.nc"
inline static void TestSenderP__DelayedSendRf1aPhysical__completeSend(void ){
#line 3
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__DelayedSendRf1aPhysical__completeSend(/*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT);
#line 3
}
#line 3
# 192 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port22__enable(void )
#line 192
{
#line 192
  P2IE |= 1 << 2;
}

# 42 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__HplInterrupt__enable(void ){
#line 42
  HplMsp430InterruptP__Port22__enable();
#line 42
}
#line 42
# 234 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port22__edge(bool l2h)
#line 234
{
  /* atomic removed: atomic calls only */
#line 235
  {
    if (l2h) {
#line 236
      P2IES &= ~(1 << 2);
      }
    else {
#line 237
      P2IES |= 1 << 2;
      }
  }
}

# 67 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__HplInterrupt__edge(bool low_to_high){
#line 67
  HplMsp430InterruptP__Port22__edge(low_to_high);
#line 67
}
#line 67
# 208 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port22__clear(void )
#line 208
{
#line 208
  P2IFG &= ~(1 << 2);
}

# 52 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__HplInterrupt__clear(void ){
#line 52
  HplMsp430InterruptP__Port22__clear();
#line 52
}
#line 52
# 200 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port22__disable(void )
#line 200
{
#line 200
  P2IE &= ~(1 << 2);
}

# 47 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__HplInterrupt__disable(void ){
#line 47
  HplMsp430InterruptP__Port22__disable();
#line 47
}
#line 47
# 69 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430InterruptC.nc"
static inline error_t /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__Interrupt__disable(void )
#line 69
{
  /* atomic removed: atomic calls only */
#line 70
  {
    /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__HplInterrupt__disable();
    /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__HplInterrupt__clear();
  }
  return SUCCESS;
}

#line 52
static inline error_t /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__enable(bool rising)
#line 52
{
  /* atomic removed: atomic calls only */
#line 53
  {
    /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__Interrupt__disable();
    /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__HplInterrupt__edge(rising);
    /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__HplInterrupt__enable();
  }
  return SUCCESS;
}

static inline error_t /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__Interrupt__enableRisingEdge(void )
#line 61
{
  return /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__enable(TRUE);
}

# 53 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
inline static error_t TestSenderP__SendInterrupt__enableRisingEdge(void ){
#line 53
  unsigned char __nesc_result;
#line 53

#line 53
  __nesc_result = /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__Interrupt__enableRisingEdge();
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53
# 53 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*TestSenderAppC.DebugPin*/Msp430GpioC__10__HplGeneralIO__clr(void ){
#line 53
  /*HplMsp430GeneralIOC.P24*/HplMsp430GeneralIORenP__12__IO__clr();
#line 53
}
#line 53
# 49 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*TestSenderAppC.DebugPin*/Msp430GpioC__10__GeneralIO__clr(void )
#line 49
{
#line 49
  /*TestSenderAppC.DebugPin*/Msp430GpioC__10__HplGeneralIO__clr();
}

# 41 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void TestSenderP__DebugPin__clr(void ){
#line 41
  /*TestSenderAppC.DebugPin*/Msp430GpioC__10__GeneralIO__clr();
#line 41
}
#line 41
# 251 "TestSenderP.nc"
static inline void TestSenderP__DelayedSendRf1aPhysical__sendReady(void )
#line 251
{
  TestSenderP__DebugPin__clr();
  if (TestSenderP__state == TestSenderP__S_LOADING) {
      TestSenderP__state = TestSenderP__S_LOADED;





      TestSenderP__SendInterrupt__enableRisingEdge();
    }
  else {

      TestSenderP__DelayedSendRf1aPhysical__completeSend();
    }
  TestSenderP__reportDSSR__postTask();
}

# 1566 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline 
#line 1565
void 
/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__DelayedSendRf1aPhysical__default__sendReady(uint8_t clientId)
#line 1566
{
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__DelayedSendRf1aPhysical__completeSend(clientId);
}

# 2 "/opt/tinyos-2.x/tos/lib/rf1a-multi/DelayedSendRf1aPhysical.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__DelayedSendRf1aPhysical__sendReady(uint8_t arg_0x40c72e58){
#line 2
  switch (arg_0x40c72e58) {
#line 2
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT:
#line 2
      TestSenderP__DelayedSendRf1aPhysical__sendReady();
#line 2
      break;
#line 2
    default:
#line 2
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__DelayedSendRf1aPhysical__default__sendReady(arg_0x40c72e58);
#line 2
      break;
#line 2
    }
#line 2
}
#line 2
# 454 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIf.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__writeBurstRegister(uint8_t addr, const uint8_t *buf, uint8_t len){
#line 454
  /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__writeBurstRegister(addr, buf, len);
#line 454
}
#line 454
# 511 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__cancelTransmit_(void )
{



  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_remain = 0;
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_state = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__TX_S_active;

  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__resetAndFlushTxFifo_();
}

#line 451
static inline uint8_t */*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__transmitData_(uint8_t client, 
unsigned int count)
{
  uint8_t *rp;

  /* atomic removed: atomic calls only */
#line 456
  {
    rp = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_pos;
    if (rp) {
        unsigned int remaining = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_end - /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_pos;

#line 460
        if (remaining >= count) {



            /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_pos += count;
            if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_pos == /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_end) {
                /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_pos = 0;
              }
          }
        else 
#line 468
          {


            rp = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_pos = 0;
          }
      }
  }
  return rp;
}

#line 1354
static inline const uint8_t */*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__defaultTransmitData(uint8_t client, unsigned int count)
{
  /* atomic removed: atomic calls only */
#line 1356
  {
    {
      unsigned char const *__nesc_temp = 
#line 1357
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__transmitData_(client, count);

#line 1357
      return __nesc_temp;
    }
  }
}

#line 1350
static inline const uint8_t */*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aTransmitFragment__default__transmitData(uint8_t client, unsigned int count)
{
  return /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__defaultTransmitData(client, count);
}

# 72 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTransmitFragment.nc"
inline static const uint8_t */*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aTransmitFragment__transmitData(uint8_t arg_0x40c6bd70, unsigned int count){
#line 72
  unsigned char const *__nesc_result;
#line 72

#line 72
    __nesc_result = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aTransmitFragment__default__transmitData(arg_0x40c6bd70, count);
#line 72

#line 72
  return __nesc_result;
#line 72
}
#line 72
# 432 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline unsigned int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__transmitReadyCount_(uint8_t client, 
unsigned int count)
{
  unsigned int rv = count;

  /* atomic removed: atomic calls only */
#line 436
  {
    if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_pos) {
        unsigned int remaining = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_end - /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_pos;

#line 439
        if (remaining < rv) {
            rv = remaining;
          }
      }
    else 
#line 442
      {
        rv = 0;
      }
  }
  return rv;
}

#line 1343
static inline unsigned int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__defaultTransmitReadyCount(uint8_t client, unsigned int count)
{
  /* atomic removed: atomic calls only */
#line 1345
  {
    {
      unsigned int __nesc_temp = 
#line 1346
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__transmitReadyCount_(client, count);

#line 1346
      return __nesc_temp;
    }
  }
}

#line 1339
static inline unsigned int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aTransmitFragment__default__transmitReadyCount(uint8_t client, unsigned int count)
{
  return /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__defaultTransmitReadyCount(client, count);
}

# 55 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTransmitFragment.nc"
inline static unsigned int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aTransmitFragment__transmitReadyCount(uint8_t arg_0x40c6bd70, unsigned int count){
#line 55
  unsigned int __nesc_result;
#line 55

#line 55
    __nesc_result = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aTransmitFragment__default__transmitReadyCount(arg_0x40c6bd70, count);
#line 55

#line 55
  return __nesc_result;
#line 55
}
#line 55
# 572 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__sendFragment_(void )
{
  bool need_to_write_length = FALSE;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 576
    {
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__client_ds = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ArbiterInfo__userId();
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__result_ds = SUCCESS;
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__wrote_data_ds = FALSE;
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__send_done_ds = FALSE;
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__need_repost_ds = FALSE;
      do {
          const uint8_t *data;
          unsigned int count;
          unsigned int inuse;


          if (SUCCESS != /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_result) {
              /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__cancelTransmit_();
              break;
            }


          if (0 >= /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_remain) {
              break;
            }



          inuse = 0x7f & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(0x3A);
          if (inuse >= /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__FIFO_FILL_LIMIT) {
              break;
            }




          need_to_write_length = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__TX_S_preparing == /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_state && 0x01 == (0x03 & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(0x08));




          count = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__FIFO_FILL_LIMIT - inuse;
          if (need_to_write_length) {
              count -= 1;
            }
          if (count > /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_remain) {
              count = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_remain;
            }


          count = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aTransmitFragment__transmitReadyCount(/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__client_ds, count);
          if (0 == count) {
              break;
            }




          data = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aTransmitFragment__transmitData(/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__client_ds, count);
          if (0 == data) {
              /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__cancelTransmit_();
              break;
            }



          if (need_to_write_length) {
              uint8_t len8 = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_remain;

#line 640
              /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__writeBurstRegister(0x40 + 0x3F, &len8, sizeof len8);
            }
          /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__writeBurstRegister(0x40 + 0x3F, data, count);
          /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_state = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__TX_S_active;
          /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__wrote_data_ds = TRUE;


          /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_remain -= count;
        }
      while (
#line 648
      0);



      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__need_repost_ds = 0 < /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_remain && !(/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_txFifoAboveThreshold & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__getIn());



      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__DelayedSendRf1aPhysical__sendReady(/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__client_ds);
    }
#line 657
    __nesc_atomic_end(__nesc_atomic); }
}

#line 485
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__sendFragment_task__runTask(void )
#line 485
{
#line 485
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__sendFragment_();
}

# 48 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P23*/HplMsp430GeneralIORenP__11__IO__set(void )
#line 48
{
  /* atomic removed: atomic calls only */
#line 48
  * (volatile uint8_t * )515U |= 0x01 << 3;
}

# 48 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__HplGeneralIO__set(void ){
#line 48
  /*HplMsp430GeneralIOC.P23*/HplMsp430GeneralIORenP__11__IO__set();
#line 48
}
#line 48
# 48 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__GeneralIO__set(void )
#line 48
{
#line 48
  /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__HplGeneralIO__set();
}

# 40 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IndicatorPin__set(void ){
#line 40
  /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__GeneralIO__set();
#line 40
}
#line 40
# 49 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P23*/HplMsp430GeneralIORenP__11__IO__clr(void )
#line 49
{
  /* atomic removed: atomic calls only */
#line 49
  * (volatile uint8_t * )515U &= ~(0x01 << 3);
}

# 53 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__HplGeneralIO__clr(void ){
#line 53
  /*HplMsp430GeneralIOC.P23*/HplMsp430GeneralIORenP__11__IO__clr();
#line 53
}
#line 53
# 49 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__GeneralIO__clr(void )
#line 49
{
#line 49
  /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__HplGeneralIO__clr();
}

# 41 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IndicatorPin__clr(void ){
#line 41
  /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__GeneralIO__clr();
#line 41
}
#line 41
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__sendDone_task__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__sendDone_task);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 263 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__sendDone(int result)
{
  /* atomic removed: atomic calls only */
#line 265
  {
    /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__tx_result = result;
  }
  /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__sendDone_task__postTask();
}

# 964 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__sendDone(uint8_t client, int result)
#line 964
{
}

# 115 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__sendDone(uint8_t arg_0x40c74aa8, int result){
#line 115
  switch (arg_0x40c74aa8) {
#line 115
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT:
#line 115
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__sendDone(result);
#line 115
      break;
#line 115
    default:
#line 115
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__sendDone(arg_0x40c74aa8, result);
#line 115
      break;
#line 115
    }
#line 115
}
#line 115
# 385 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__receiveBufferFilled(uint8_t *buffer, 
unsigned int count)
{
}

# 1433 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__receiveBufferFilled(uint8_t client, uint8_t *buffer, 
unsigned int count)
#line 1434
{
}

# 274 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__receiveBufferFilled(uint8_t arg_0x40c74aa8, uint8_t *buffer, unsigned int count){
#line 274
  switch (arg_0x40c74aa8) {
#line 274
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT:
#line 274
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__receiveBufferFilled(buffer, count);
#line 274
      break;
#line 274
    default:
#line 274
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__receiveBufferFilled(arg_0x40c74aa8, buffer, count);
#line 274
      break;
#line 274
    }
#line 274
}
#line 274
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__receiveDone_task__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__receiveDone_task);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 365 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__receiveDone(uint8_t *buffer, 
unsigned int count, 
int result)
{
  if (SUCCESS == result) {


      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 372
        {
          /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__rx_count = count;
          /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__receiveDone_task__postTask();
        }
#line 375
        __nesc_atomic_end(__nesc_atomic); }
    }
  else 
#line 376
    {




      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__setReceiveBuffer(0);
    }
}

# 1429 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__receiveDone(uint8_t client, uint8_t *buffer, 
unsigned int count, 
int result)
#line 1431
{
}

# 205 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__receiveDone(uint8_t arg_0x40c74aa8, uint8_t *buffer, unsigned int count, int result){
#line 205
  switch (arg_0x40c74aa8) {
#line 205
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT:
#line 205
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__receiveDone(buffer, count, result);
#line 205
      break;
#line 205
    default:
#line 205
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__receiveDone(arg_0x40c74aa8, buffer, count, result);
#line 205
      break;
#line 205
    }
#line 205
}
#line 205
# 327 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__receiveStarted(unsigned int length)
#line 327
{
}

# 1427 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__receiveStarted(uint8_t client, unsigned int length)
#line 1427
{
}

# 189 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__receiveStarted(uint8_t arg_0x40c74aa8, unsigned int length){
#line 189
  switch (arg_0x40c74aa8) {
#line 189
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT:
#line 189
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__receiveStarted(length);
#line 189
      break;
#line 189
    default:
#line 189
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__receiveStarted(arg_0x40c74aa8, length);
#line 189
      break;
#line 189
    }
#line 189
}
#line 189
# 445 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIf.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readBurstRegister(uint8_t addr, uint8_t *buf, uint8_t len){
#line 445
  /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__readBurstRegister(addr, buf, len);
#line 445
}
#line 445
# 1074 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__cancelReceive_(void )
{
  uint8_t rc;


  rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x36);
  while (RF1A_S_IDLE != (RF1A_S_MASK & rc)) {
      rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x3D);
    }
  rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x3A);
  while (RF1A_S_IDLE != (RF1A_S_MASK & rc)) {
      rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x3D);
    }
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__resumeIdleMode_(TRUE);
}



static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveData_(void )
{
  unsigned int avail;
  uint8_t client = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ArbiterInfo__userId();
  bool need_post = TRUE;
  bool signal_start = FALSE;
  bool signal_filled = FALSE;
  bool signal_complete = FALSE;
  uint8_t *start;
  unsigned int expected;
  unsigned int received;
  int result;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 1105
    {
      do {
          unsigned int need;
          unsigned int consume;



          if (SUCCESS != /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_result) {
              signal_complete = TRUE;
              /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__cancelReceive_();
              break;
            }


          avail = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveCountAvailable_();
          if (0 == avail) {
              break;
            }


          if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__RX_S_active > /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_state) {
              bool variable_packet_length_mode = 0x01 == (0x03 & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(0x08));

              if (variable_packet_length_mode) {
                  uint8_t len8;

#line 1130
                  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readBurstRegister(0xC0 + 0x3F, &len8, sizeof len8);
                  avail -= 1;
                  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_expected = len8;
                }



              /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_state = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__RX_S_active;


              /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_start = 0;
              /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_received = 0;


              signal_start = TRUE;
              expected = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_expected;
            }
          need = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_expected - /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_received;


          if (0 == /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos) {
              signal_filled = TRUE;
              /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_start = 0;
              received = 0;
              break;
            }





          if (0 == /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_start) {
              /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_start = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos;
            }



          if (avail < need) {
              --avail;
            }


          consume = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos_end - /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos;
          if (consume > need) {
              consume = need;
            }
          if (consume > avail) {
              consume = avail;
            }
          /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readBurstRegister(0xC0 + 0x3F, /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos, consume);
          /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos += consume;
          /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_received += consume;
          avail -= consume;


          if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_received == /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_expected) {

              if (0x04 & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(0x07)) {


                  while (2 > avail) {
                      avail = 0x7f & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(0x3B);
                    }
                  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readBurstRegister(0xC0 + 0x3F, &/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_rssi_raw, sizeof /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_rssi_raw);
                  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readBurstRegister(0xC0 + 0x3F, &/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_lqi_raw, sizeof /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_lqi_raw);
                  avail -= 2;
                }

              signal_complete = TRUE;



              received = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos - /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_start;


              if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_single_use) {
                  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos_end = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos;
                }
            }


          if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos_end == /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos) {
              signal_filled = TRUE;
              received = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos - /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_start;
              /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos = 0;


              if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_single_use && !signal_complete) {
                  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_result = ENOMEM;
                }
            }
        }
      while (0);



      need_post = 0 < /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveCountAvailable_();


      if (signal_filled) {
          start = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_start;
        }

      if (signal_complete) {
          result = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_result;
          if (SUCCESS == result) {
              start = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_start;
            }
          else 
#line 1237
            {
              start = 0;
              received = 0;
            }



          /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_result = SUCCESS;
          if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_single_use) {
              /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos = 0;
            }
          if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos) {
              /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_state = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__RX_S_listening;
            }
          else 
#line 1250
            {
              /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_state = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__RX_S_inactive;
            }
        }
    }
#line 1254
    __nesc_atomic_end(__nesc_atomic); }


  if (need_post) {
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveData_task__postTask();
    }




  if (signal_start) {
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__receiveStarted(client, expected);
    }
  if (signal_complete) {
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__receiveDone(client, start, received, result);
    }
  if (signal_filled) {
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__receiveBufferFilled(client, start, received);
    }
}

#line 488
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveData_task__runTask(void )
#line 488
{
#line 488
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveData_();
}

# 282 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIfP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__writeSinglePATable(uint8_t value)
{
  /* atomic removed: atomic calls only */
#line 284
  {
    while (!(RF1AIFCTL1 & 0x0010)) ;
    RF1AINSTRW = 0x3E00 + value;
    while (!(RF1AIFCTL1 & 0x0010)) ;
    RF1AINSTRW_H = 0x3D;
  }
}

# 474 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIf.nc"
inline static void TestSenderP__Rf1aIf__writeSinglePATable(uint8_t value){
#line 474
  /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__writeSinglePATable(value);
#line 474
}
#line 474
# 65 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430InterruptC.nc"
static inline error_t /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__Interrupt__enableFallingEdge(void )
#line 65
{
  return /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__enable(FALSE);
}

# 54 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
inline static error_t TestSenderP__SendReadyInterrupt__enableFallingEdge(void ){
#line 54
  unsigned char __nesc_result;
#line 54

#line 54
  __nesc_result = /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__Interrupt__enableFallingEdge();
#line 54

#line 54
  return __nesc_result;
#line 54
}
#line 54
# 140 "TestSenderP.nc"
static inline void TestSenderP__SplitControl__startDone(error_t err)
#line 140
{



  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 144
    {
      TestSenderP__state = TestSenderP__S_NEED_LOAD;
      TestSenderP__SendReadyInterrupt__enableFallingEdge();
      TestSenderP__radioOn = TRUE;





      TestSenderP__Rf1aIf__writeSinglePATable(0x8D);
    }
#line 154
    __nesc_atomic_end(__nesc_atomic); }
}

# 113 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SplitControl__startDone(error_t error){
#line 113
  TestSenderP__SplitControl__startDone(error);
#line 113
}
#line 113
# 157 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aIeee154PacketP.nc"
static inline void */*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Packet__getPayload(message_t *msg, uint8_t len)
{
  return len + sizeof(/*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__header_t ) <= 127 - sizeof(rf1a_ieee154_t ) ? (void *)msg->data : 0;
}

# 126 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
inline static void * Rf1aAMPacketP__SubPacket__getPayload(message_t * msg, uint8_t len){
#line 126
  void *__nesc_result;
#line 126

#line 126
  __nesc_result = /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Packet__getPayload(msg, len);
#line 126

#line 126
  return __nesc_result;
#line 126
}
#line 126
# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aAMPacketP.nc"
static inline Rf1aAMPacketP__layer_header_t *Rf1aAMPacketP__layerHeader(message_t *msg)
#line 56
{
#line 56
  return (Rf1aAMPacketP__layer_header_t *)Rf1aAMPacketP__SubPacket__getPayload(msg, 0);
}

# 149 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aIeee154PacketP.nc"
static inline void /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Packet__clear(message_t *msg)
{
  memset(msg, 0, sizeof  (*msg));
}

# 65 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
inline static void Rf1aAMPacketP__SubPacket__clear(message_t * msg){
#line 65
  /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Packet__clear(msg);
#line 65
}
#line 65
# 58 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aAMPacketP.nc"
static inline void Rf1aAMPacketP__Packet__clear(message_t *msg)
{
  Rf1aAMPacketP__layer_header_t *lhp;


  Rf1aAMPacketP__SubPacket__clear(msg);


  lhp = Rf1aAMPacketP__layerHeader(msg);
  __nesc_hton_leuint8(lhp->nalp_tinyos.data, LOWPAN_NALP_TINYOS);
}

# 65 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
inline static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Packet__clear(message_t * msg){
#line 65
  Rf1aAMPacketP__Packet__clear(msg);
#line 65
}
#line 65
# 187 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Resource__granted(void )
{



  /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Packet__clear(&/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__rx_buffer);
  /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__setReceiveBuffer(&/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__rx_buffer);
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 194
    {
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__split_control_state = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SCS_on;
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__tx_state = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__TXS_idle;
    }
#line 197
    __nesc_atomic_end(__nesc_atomic); }
  /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SplitControl__startDone(SUCCESS);
}

# 165 "/opt/tinyos-2.x/tos/system/SimpleArbiterP.nc"
static inline void /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Resource__default__granted(uint8_t id)
#line 165
{
}

# 102 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
inline static void /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Resource__granted(uint8_t arg_0x40c40c68){
#line 102
  switch (arg_0x40c40c68) {
#line 102
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT:
#line 102
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Resource__granted();
#line 102
      break;
#line 102
    default:
#line 102
      /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Resource__default__granted(arg_0x40c40c68);
#line 102
      break;
#line 102
    }
#line 102
}
#line 102
# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/CUSTOM_HC.nc"
static inline void CUSTOM_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_2FSK_1P2K_SENS_HC.nc"
static inline void SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_100K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_100K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_10K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_10K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_175K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_175K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_1P2K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_1P2K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_250K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_250K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_2P4K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_2P4K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_38P4K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_38P4K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_4P8K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_4P8K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_76P8K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_76P8K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_MSK_500K_HC.nc"
static inline void SRFS6_868_MSK_500K_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_PRE802154G_HC.nc"
static inline void SRFS6_PRE802154G_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_RESET_HC.nc"
static inline void SRFS6_RESET_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_779_MSK_250K_HC.nc"
static inline void SRFS7_779_MSK_250K_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_902P2_GFSK_50K_135B_HC.nc"
static inline void SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_902P2_GFSK_50K_163B_HC.nc"
static inline void SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_STI_902_GFSK_1P2K_HC.nc"
static inline void SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_STI_902_GFSK_250K_HC.nc"
static inline void SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 109 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/TINYOSRF1A_HC.nc"
static inline void TINYOSRF1A_HC__Rf1aConfigure__postConfigure(void )
#line 109
{
}

# 66 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__postConfigure(uint8_t clientId)
#line 66
{
}

# 71 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
inline static void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__postConfigure(uint8_t arg_0x40d95768){
#line 71
  switch (arg_0x40d95768) {
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CUSTOM_HC_LOCAL_ID:
#line 71
      CUSTOM_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_2FSK_1P2K_SENS_HC_LOCAL_ID:
#line 71
      SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_100K_CUR_HC_LOCAL_ID:
#line 71
      SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_100K_SENS_HC_LOCAL_ID:
#line 71
      SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_10K_CUR_HC_LOCAL_ID:
#line 71
      SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_10K_SENS_HC_LOCAL_ID:
#line 71
      SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_175K_CUR_HC_LOCAL_ID:
#line 71
      SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_175K_SENS_HC_LOCAL_ID:
#line 71
      SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_1P2K_CUR_HC_LOCAL_ID:
#line 71
      SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_1P2K_SENS_HC_LOCAL_ID:
#line 71
      SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_250K_CUR_HC_LOCAL_ID:
#line 71
      SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_250K_SENS_HC_LOCAL_ID:
#line 71
      SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_2P4K_CUR_HC_LOCAL_ID:
#line 71
      SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_2P4K_SENS_HC_LOCAL_ID:
#line 71
      SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_38P4K_CUR_HC_LOCAL_ID:
#line 71
      SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_38P4K_SENS_HC_LOCAL_ID:
#line 71
      SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_4P8K_CUR_HC_LOCAL_ID:
#line 71
      SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_4P8K_SENS_HC_LOCAL_ID:
#line 71
      SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_76P8K_CUR_HC_LOCAL_ID:
#line 71
      SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_76P8K_SENS_HC_LOCAL_ID:
#line 71
      SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_MSK_500K_HC_LOCAL_ID:
#line 71
      SRFS6_868_MSK_500K_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_PRE802154G_HC_LOCAL_ID:
#line 71
      SRFS6_PRE802154G_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_RESET_HC_LOCAL_ID:
#line 71
      SRFS6_RESET_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_779_MSK_250K_HC_LOCAL_ID:
#line 71
      SRFS7_779_MSK_250K_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_902P2_GFSK_50K_135B_HC_LOCAL_ID:
#line 71
      SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_902P2_GFSK_50K_163B_HC_LOCAL_ID:
#line 71
      SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_STI_902_GFSK_1P2K_HC_LOCAL_ID:
#line 71
      SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_STI_902_GFSK_250K_HC_LOCAL_ID:
#line 71
      SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__TINYOSRF1A_HC_LOCAL_ID:
#line 71
      TINYOSRF1A_HC__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    default:
#line 71
      /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__postConfigure(arg_0x40d95768);
#line 71
      break;
#line 71
    }
#line 71
}
#line 71
# 51 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__postConfigure(void )
#line 51
{
  /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__postConfigure(/*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__currentClient);
}

# 404 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__postConfigure(uint8_t client)
#line 404
{
}

# 71 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__postConfigure(uint8_t arg_0x40c6b300){
#line 71
  switch (arg_0x40c6b300) {
#line 71
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT:
#line 71
      /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__postConfigure();
#line 71
      break;
#line 71
    default:
#line 71
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__postConfigure(arg_0x40c6b300);
#line 71
      break;
#line 71
    }
#line 71
}
#line 71
# 55 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P23*/HplMsp430GeneralIORenP__11__IO__makeOutput(void )
#line 55
{
#line 55
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 55
    * (volatile uint8_t * )517U |= 0x01 << 3;
#line 55
    __nesc_atomic_end(__nesc_atomic); }
}

# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__HplGeneralIO__makeOutput(void ){
#line 85
  /*HplMsp430GeneralIOC.P23*/HplMsp430GeneralIORenP__11__IO__makeOutput();
#line 85
}
#line 85
# 54 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__GeneralIO__makeOutput(void )
#line 54
{
#line 54
  /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__HplGeneralIO__makeOutput();
}

# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IndicatorPin__makeOutput(void ){
#line 46
  /*Rf1aC.HplRf1aC.IndicatorPin*/Msp430GpioC__11__GeneralIO__makeOutput();
#line 46
}
#line 46
# 143 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIfP.nc"
static inline uint16_t /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__getIe(void )
#line 143
{
  /* atomic removed: atomic calls only */
#line 143
  {
    unsigned int __nesc_temp = 
#line 143
    * (volatile uint16_t * )(3840U + 0x36);

#line 143
    return __nesc_temp;
  }
}

# 370 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIf.nc"
inline static uint16_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__getIe(void ){
#line 370
  unsigned int __nesc_result;
#line 370

#line 370
  __nesc_result = /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__getIe();
#line 370

#line 370
  return __nesc_result;
#line 370
}
#line 370
# 144 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIfP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__setIe(uint16_t v)
#line 144
{
  /* atomic removed: atomic calls only */
#line 144
  * (volatile uint16_t * )(3840U + 0x36) = v;
}

# 375 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIf.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__setIe(uint16_t v){
#line 375
  /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__setIe(v);
#line 375
}
#line 375
# 141 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIfP.nc"
static inline uint16_t /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__getIes(void )
#line 141
{
  /* atomic removed: atomic calls only */
#line 141
  {
    unsigned int __nesc_temp = 
#line 141
    * (volatile uint16_t * )(3840U + 0x34);

#line 141
    return __nesc_temp;
  }
}

# 358 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIf.nc"
inline static uint16_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__getIes(void ){
#line 358
  unsigned int __nesc_result;
#line 358

#line 358
  __nesc_result = /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__getIes();
#line 358

#line 358
  return __nesc_result;
#line 358
}
#line 358
# 142 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIfP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__setIes(uint16_t v)
#line 142
{
  /* atomic removed: atomic calls only */
#line 142
  * (volatile uint16_t * )(3840U + 0x34) = v;
}

# 363 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIf.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__setIes(uint16_t v){
#line 363
  /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__setIes(v);
#line 363
}
#line 363
# 140 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIfP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__setIfg(uint16_t v)
#line 140
{
  /* atomic removed: atomic calls only */
#line 140
  * (volatile uint16_t * )(3840U + 0x32) = v;
}

# 351 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIf.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__setIfg(uint16_t v){
#line 351
  /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__setIfg(v);
#line 351
}
#line 351
#line 467
inline static uint8_t /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__resetRadioCore(void ){
#line 467
  unsigned char __nesc_result;
#line 467

#line 467
  __nesc_result = /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__resetRadioCore();
#line 467

#line 467
  return __nesc_result;
#line 467
}
#line 467
# 327 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__configure_(const rf1a_config_t *config)
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 329
    {
      const uint8_t *cp = (const uint8_t *)config;




      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__resetRadioCore();


      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__resumeIdleMode_(FALSE);




      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__writeBurstRegister(0x3E, config->patable, sizeof  config->patable);
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__writeBurstRegister(0, cp, 1 + 0x26);






      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__setIfg(0);
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__setIes(/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_EDGE_Negative | (~/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_EDGE_Positive & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__getIes()));
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__setIe(/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_INTERRUPT | /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__getIe());







      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__writeRegister(0x17, 0xf0 & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(0x17));


      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_state = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__RX_S_inactive;
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos_end = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_start = 0;
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_expected = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_received = 0;
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_state = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__TX_S_inactive;
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_pos = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_end = 0;
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_remain = 0;
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_result = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_result = SUCCESS;
    }
#line 371
    __nesc_atomic_end(__nesc_atomic); }

  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IndicatorPin__makeOutput();
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/CUSTOM_HC.nc"
static inline void CUSTOM_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_2FSK_1P2K_SENS_HC.nc"
static inline void SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_100K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_100K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_10K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_10K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_175K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_175K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_1P2K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_1P2K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_250K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_250K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_2P4K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_2P4K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_38P4K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_38P4K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_4P8K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_4P8K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_76P8K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_76P8K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_MSK_500K_HC.nc"
static inline void SRFS6_868_MSK_500K_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_PRE802154G_HC.nc"
static inline void SRFS6_PRE802154G_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_RESET_HC.nc"
static inline void SRFS6_RESET_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_779_MSK_250K_HC.nc"
static inline void SRFS7_779_MSK_250K_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_902P2_GFSK_50K_135B_HC.nc"
static inline void SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_902P2_GFSK_50K_163B_HC.nc"
static inline void SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_STI_902_GFSK_1P2K_HC.nc"
static inline void SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_STI_902_GFSK_250K_HC.nc"
static inline void SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 108 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/TINYOSRF1A_HC.nc"
static inline void TINYOSRF1A_HC__Rf1aConfigure__preConfigure(void )
#line 108
{
}

# 65 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__preConfigure(uint8_t clientId)
#line 65
{
}

# 62 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
inline static void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__preConfigure(uint8_t arg_0x40d95768){
#line 62
  switch (arg_0x40d95768) {
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CUSTOM_HC_LOCAL_ID:
#line 62
      CUSTOM_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_2FSK_1P2K_SENS_HC_LOCAL_ID:
#line 62
      SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_100K_CUR_HC_LOCAL_ID:
#line 62
      SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_100K_SENS_HC_LOCAL_ID:
#line 62
      SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_10K_CUR_HC_LOCAL_ID:
#line 62
      SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_10K_SENS_HC_LOCAL_ID:
#line 62
      SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_175K_CUR_HC_LOCAL_ID:
#line 62
      SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_175K_SENS_HC_LOCAL_ID:
#line 62
      SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_1P2K_CUR_HC_LOCAL_ID:
#line 62
      SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_1P2K_SENS_HC_LOCAL_ID:
#line 62
      SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_250K_CUR_HC_LOCAL_ID:
#line 62
      SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_250K_SENS_HC_LOCAL_ID:
#line 62
      SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_2P4K_CUR_HC_LOCAL_ID:
#line 62
      SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_2P4K_SENS_HC_LOCAL_ID:
#line 62
      SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_38P4K_CUR_HC_LOCAL_ID:
#line 62
      SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_38P4K_SENS_HC_LOCAL_ID:
#line 62
      SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_4P8K_CUR_HC_LOCAL_ID:
#line 62
      SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_4P8K_SENS_HC_LOCAL_ID:
#line 62
      SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_76P8K_CUR_HC_LOCAL_ID:
#line 62
      SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_76P8K_SENS_HC_LOCAL_ID:
#line 62
      SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_MSK_500K_HC_LOCAL_ID:
#line 62
      SRFS6_868_MSK_500K_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_PRE802154G_HC_LOCAL_ID:
#line 62
      SRFS6_PRE802154G_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_RESET_HC_LOCAL_ID:
#line 62
      SRFS6_RESET_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_779_MSK_250K_HC_LOCAL_ID:
#line 62
      SRFS7_779_MSK_250K_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_902P2_GFSK_50K_135B_HC_LOCAL_ID:
#line 62
      SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_902P2_GFSK_50K_163B_HC_LOCAL_ID:
#line 62
      SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_STI_902_GFSK_1P2K_HC_LOCAL_ID:
#line 62
      SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_STI_902_GFSK_250K_HC_LOCAL_ID:
#line 62
      SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__TINYOSRF1A_HC_LOCAL_ID:
#line 62
      TINYOSRF1A_HC__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    default:
#line 62
      /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__preConfigure(arg_0x40d95768);
#line 62
      break;
#line 62
    }
#line 62
}
#line 62
# 48 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__preConfigure(void )
#line 48
{
  /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__preConfigure(/*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__currentClient);
}

# 403 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__preConfigure(uint8_t client)
#line 403
{
}

# 62 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__preConfigure(uint8_t arg_0x40c6b300){
#line 62
  switch (arg_0x40c6b300) {
#line 62
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT:
#line 62
      /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__preConfigure();
#line 62
      break;
#line 62
    default:
#line 62
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__preConfigure(arg_0x40c6b300);
#line 62
      break;
#line 62
    }
#line 62
}
#line 62
# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/CUSTOM_HC.nc"
static inline const rf1a_config_t *CUSTOM_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &CUSTOM_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_2FSK_1P2K_SENS_HC.nc"
static inline const rf1a_config_t *SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_2FSK_1P2K_SENS_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_100K_CUR_HC.nc"
static inline const rf1a_config_t *SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_GFSK_100K_CUR_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_100K_SENS_HC.nc"
static inline const rf1a_config_t *SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_GFSK_100K_SENS_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_10K_CUR_HC.nc"
static inline const rf1a_config_t *SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_GFSK_10K_CUR_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_10K_SENS_HC.nc"
static inline const rf1a_config_t *SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_GFSK_10K_SENS_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_175K_CUR_HC.nc"
static inline const rf1a_config_t *SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_GFSK_175K_CUR_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_175K_SENS_HC.nc"
static inline const rf1a_config_t *SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_GFSK_175K_SENS_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_1P2K_CUR_HC.nc"
static inline const rf1a_config_t *SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_GFSK_1P2K_CUR_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_1P2K_SENS_HC.nc"
static inline const rf1a_config_t *SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_GFSK_1P2K_SENS_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_250K_CUR_HC.nc"
static inline const rf1a_config_t *SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_GFSK_250K_CUR_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_250K_SENS_HC.nc"
static inline const rf1a_config_t *SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_GFSK_250K_SENS_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_2P4K_CUR_HC.nc"
static inline const rf1a_config_t *SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_GFSK_2P4K_CUR_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_2P4K_SENS_HC.nc"
static inline const rf1a_config_t *SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_GFSK_2P4K_SENS_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_38P4K_CUR_HC.nc"
static inline const rf1a_config_t *SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_GFSK_38P4K_CUR_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_38P4K_SENS_HC.nc"
static inline const rf1a_config_t *SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_GFSK_38P4K_SENS_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_4P8K_CUR_HC.nc"
static inline const rf1a_config_t *SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_GFSK_4P8K_CUR_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_4P8K_SENS_HC.nc"
static inline const rf1a_config_t *SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_GFSK_4P8K_SENS_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_76P8K_CUR_HC.nc"
static inline const rf1a_config_t *SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_GFSK_76P8K_CUR_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_76P8K_SENS_HC.nc"
static inline const rf1a_config_t *SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_GFSK_76P8K_SENS_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_MSK_500K_HC.nc"
static inline const rf1a_config_t *SRFS6_868_MSK_500K_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_868_MSK_500K_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_PRE802154G_HC.nc"
static inline const rf1a_config_t *SRFS6_PRE802154G_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_PRE802154G_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_RESET_HC.nc"
static inline const rf1a_config_t *SRFS6_RESET_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS6_RESET_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_779_MSK_250K_HC.nc"
static inline const rf1a_config_t *SRFS7_779_MSK_250K_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS7_779_MSK_250K_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_902P2_GFSK_50K_135B_HC.nc"
static inline const rf1a_config_t *SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS7_902P2_GFSK_50K_135B_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_902P2_GFSK_50K_163B_HC.nc"
static inline const rf1a_config_t *SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS7_902P2_GFSK_50K_163B_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_STI_902_GFSK_1P2K_HC.nc"
static inline const rf1a_config_t *SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS7_STI_902_GFSK_1P2K_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_STI_902_GFSK_250K_HC.nc"
static inline const rf1a_config_t *SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &SRFS7_STI_902_GFSK_250K_HC__this_config;
}

# 105 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/TINYOSRF1A_HC.nc"
static inline const rf1a_config_t *TINYOSRF1A_HC__Rf1aConfigure__getConfiguration(void )
#line 105
{
  return &TINYOSRF1A_HC__this_config;
}

# 61 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
static inline const rf1a_config_t */*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__getConfiguration(uint8_t clientId)
#line 61
{
  return (void *)0;
}

# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
inline static const rf1a_config_t */*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__getConfiguration(uint8_t arg_0x40d95768){
#line 56
  struct rf1a_config_t const *__nesc_result;
#line 56

#line 56
  switch (arg_0x40d95768) {
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CUSTOM_HC_LOCAL_ID:
#line 56
      __nesc_result = CUSTOM_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_2FSK_1P2K_SENS_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_100K_CUR_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_100K_SENS_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_10K_CUR_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_10K_SENS_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_175K_CUR_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_175K_SENS_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_1P2K_CUR_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_1P2K_SENS_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_250K_CUR_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_250K_SENS_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_2P4K_CUR_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_2P4K_SENS_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_38P4K_CUR_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_38P4K_SENS_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_4P8K_CUR_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_4P8K_SENS_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_76P8K_CUR_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_76P8K_SENS_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_MSK_500K_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_868_MSK_500K_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_PRE802154G_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_PRE802154G_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_RESET_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS6_RESET_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_779_MSK_250K_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS7_779_MSK_250K_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_902P2_GFSK_50K_135B_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_902P2_GFSK_50K_163B_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_STI_902_GFSK_1P2K_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_STI_902_GFSK_250K_HC_LOCAL_ID:
#line 56
      __nesc_result = SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__TINYOSRF1A_HC_LOCAL_ID:
#line 56
      __nesc_result = TINYOSRF1A_HC__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    default:
#line 56
      __nesc_result = /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__getConfiguration(arg_0x40d95768);
#line 56
      break;
#line 56
    }
#line 56

#line 56
  return __nesc_result;
#line 56
}
#line 56
# 45 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
static inline const rf1a_config_t */*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__getConfiguration(void )
#line 45
{
  return /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__getConfiguration(/*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__currentClient);
}

# 397 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline const rf1a_config_t *
/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__getConfiguration(uint8_t client)
{
  return &rf1a_default_config;
}

# 56 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
inline static const rf1a_config_t */*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__getConfiguration(uint8_t arg_0x40c6b300){
#line 56
  struct rf1a_config_t const *__nesc_result;
#line 56

#line 56
  switch (arg_0x40c6b300) {
#line 56
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT:
#line 56
      __nesc_result = /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__getConfiguration();
#line 56
      break;
#line 56
    default:
#line 56
      __nesc_result = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__getConfiguration(arg_0x40c6b300);
#line 56
      break;
#line 56
    }
#line 56

#line 56
  return __nesc_result;
#line 56
}
#line 56
# 408 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ResourceConfigure__configure(uint8_t client)
{
  const rf1a_config_t *cp = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__getConfiguration(client);

#line 411
  if (0 == cp) {
      cp = &rf1a_default_config;
    }
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__preConfigure(client);
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__configure_(cp);
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__postConfigure(client);
}

# 59 "/opt/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
inline static void /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ResourceConfigure__configure(uint8_t arg_0x40c67430){
#line 59
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ResourceConfigure__configure(arg_0x40c67430);
#line 59
}
#line 59
# 155 "/opt/tinyos-2.x/tos/system/SimpleArbiterP.nc"
static inline void /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__grantedTask__runTask(void )
#line 155
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 156
    {
      /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__resId = /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__reqResId;
      /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__state = /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__RES_BUSY;
    }
#line 159
    __nesc_atomic_end(__nesc_atomic); }
  /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ResourceConfigure__configure(/*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__resId);
  /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Resource__granted(/*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__resId);
}

# 110 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static void /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__AMSend__sendDone(message_t * msg, error_t error){
#line 110
  TestSenderP__RadioSend__sendDone(msg, error);
#line 110
}
#line 110
# 65 "/opt/tinyos-2.x/tos/system/AMQueueEntryP.nc"
static inline void /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__Send__sendDone(message_t *m, error_t err)
#line 65
{
  /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__AMSend__sendDone(m, err);
}

# 215 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__default__sendDone(uint8_t id, message_t *msg, error_t err)
#line 215
{
}

# 100 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
inline static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__sendDone(uint8_t arg_0x40ab77a8, message_t * msg, error_t error){
#line 100
  switch (arg_0x40ab77a8) {
#line 100
    case 0U:
#line 100
      /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__Send__sendDone(msg, error);
#line 100
      break;
#line 100
    default:
#line 100
      /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__default__sendDone(arg_0x40ab77a8, msg, error);
#line 100
      break;
#line 100
    }
#line 100
}
#line 100
# 126 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__CancelTask__runTask(void )
#line 126
{
  uint8_t i;
#line 127
  uint8_t j;
#line 127
  uint8_t mask;
#line 127
  uint8_t last;
  message_t *msg;

#line 129
  for (i = 0; i < 1 / 8 + 1; i++) {
      if (/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__cancelMask[i]) {
          for (mask = 1, j = 0; j < 8; j++) {
              if (/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__cancelMask[i] & mask) {
                  last = i * 8 + j;
                  msg = /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[last].msg;
                  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[last].msg = (void *)0;
                  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__cancelMask[i] &= ~mask;
                  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__sendDone(last, msg, ECANCEL);
                }
              mask <<= 1;
            }
        }
    }
}

#line 163
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__sendDone(uint8_t last, message_t * msg, error_t err)
#line 163
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[last].msg = (void *)0;
  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__tryToSend();
  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__sendDone(last, msg, err);
}

static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask__runTask(void )
#line 169
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__sendDone(/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current, /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current].msg, FAIL);
}

# 63 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/batteryVoltage/PlatformBatteryVoltageP.nc"
static inline void PlatformBatteryVoltageP__SplitControl__default__stopDone(error_t err)
#line 63
{
}

# 138 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static void PlatformBatteryVoltageP__SplitControl__stopDone(error_t error){
#line 138
  PlatformBatteryVoltageP__SplitControl__default__stopDone(error);
#line 138
}
#line 138
# 36 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/batteryVoltage/PlatformBatteryVoltageP.nc"
static inline void PlatformBatteryVoltageP__stopDoneTask__runTask(void )
#line 36
{
  PlatformBatteryVoltageP__SplitControl__stopDone(SUCCESS);
}

#line 62
static inline void PlatformBatteryVoltageP__SplitControl__default__startDone(error_t err)
#line 62
{
}

# 113 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static void PlatformBatteryVoltageP__SplitControl__startDone(error_t error){
#line 113
  PlatformBatteryVoltageP__SplitControl__default__startDone(error);
#line 113
}
#line 113
# 33 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/batteryVoltage/PlatformBatteryVoltageP.nc"
static inline void PlatformBatteryVoltageP__startDoneTask__runTask(void )
#line 33
{
  PlatformBatteryVoltageP__SplitControl__startDone(SUCCESS);
}

# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t PlatformBusPowerP__stopDoneTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(PlatformBusPowerP__stopDoneTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 31 "/opt/tinyos-2.x/tos/platforms/bacon/PlatformBusPowerP.nc"
static inline error_t PlatformBusPowerP__SplitControl__stop(void )
#line 31
{
  if (PlatformBusPowerP__on) {
      PlatformBusPowerP__on = FALSE;
      PlatformBusPowerP__EnablePin__clr();
      PlatformBusPowerP__stopDoneTask__postTask();
      return SUCCESS;
    }
  else 
#line 37
    {
      return EALREADY;
    }
}

# 130 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static error_t BusPowerC__SubSplitControl__stop(void ){
#line 130
  unsigned char __nesc_result;
#line 130

#line 130
  __nesc_result = PlatformBusPowerP__SplitControl__stop();
#line 130

#line 130
  return __nesc_result;
#line 130
}
#line 130
# 70 "/opt/tinyos-2.x/tos/lib/busPower/BusPowerC.nc"
static inline void BusPowerC__subStopTask__runTask(void )
#line 70
{
  BusPowerC__SubSplitControl__stop();
}

#line 61
static inline void BusPowerC__clearStopFlags__runTask(void )
#line 61
{
  uint8_t k;

#line 63
  for (k = 0; k < 0U; k++) {
      if (BusPowerC__clientFlags[k] == BusPowerC__FLAG_PENDING_STOP) {
          BusPowerC__clientFlags[k] = BusPowerC__FLAG_STOPPED;
        }
    }
}

# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t PlatformBusPowerP__startDoneTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(PlatformBusPowerP__startDoneTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 48 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__HplGeneralIO__set(void ){
#line 48
  /*HplMsp430GeneralIOC.P37*/HplMsp430GeneralIORenP__23__IO__set();
#line 48
}
#line 48
# 48 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__GeneralIO__set(void )
#line 48
{
#line 48
  /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__HplGeneralIO__set();
}

# 40 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void PlatformBusPowerP__EnablePin__set(void ){
#line 40
  /*PlatformBusPowerC.EnablePin*/Msp430GpioC__5__GeneralIO__set();
#line 40
}
#line 40
# 20 "/opt/tinyos-2.x/tos/platforms/bacon/PlatformBusPowerP.nc"
static inline error_t PlatformBusPowerP__SplitControl__start(void )
#line 20
{
  if (PlatformBusPowerP__on) {
      return EALREADY;
    }
  else 
#line 23
    {
      PlatformBusPowerP__on = TRUE;
      PlatformBusPowerP__EnablePin__set();
      PlatformBusPowerP__startDoneTask__postTask();
      return SUCCESS;
    }
}

# 104 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static error_t BusPowerC__SubSplitControl__start(void ){
#line 104
  unsigned char __nesc_result;
#line 104

#line 104
  __nesc_result = PlatformBusPowerP__SplitControl__start();
#line 104

#line 104
  return __nesc_result;
#line 104
}
#line 104
# 37 "/opt/tinyos-2.x/tos/lib/busPower/BusPowerC.nc"
static inline void BusPowerC__subStartTask__runTask(void )
#line 37
{
  BusPowerC__SubSplitControl__start();
}

#line 103
static inline void BusPowerC__SplitControl__default__startDone(uint8_t id, error_t err)
#line 103
{
}

# 113 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static void BusPowerC__SplitControl__startDone(uint8_t arg_0x40a30e78, error_t error){
#line 113
    BusPowerC__SplitControl__default__startDone(arg_0x40a30e78, error);
#line 113
}
#line 113
# 27 "/opt/tinyos-2.x/tos/lib/busPower/BusPowerC.nc"
static inline void BusPowerC__clearStartFlags__runTask(void )
#line 27
{
  uint8_t k;

#line 29
  for (k = 0; k < 0U; k++) {
      if (BusPowerC__clientFlags[k] == BusPowerC__FLAG_PENDING_START) {
          BusPowerC__clientFlags[k] = BusPowerC__FLAG_STARTED;
          BusPowerC__SplitControl__startDone(k, SUCCESS);
        }
    }
}

# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t BusPowerC__clearStopFlags__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(BusPowerC__clearStopFlags);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 98 "/opt/tinyos-2.x/tos/lib/busPower/BusPowerC.nc"
static inline void BusPowerC__SubSplitControl__stopDone(error_t err)
#line 98
{
  BusPowerC__state = BusPowerC__S_OFF;
  BusPowerC__clearStopFlags__postTask();
}

# 138 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static void PlatformBusPowerP__SplitControl__stopDone(error_t error){
#line 138
  BusPowerC__SubSplitControl__stopDone(error);
#line 138
}
#line 138
# 16 "/opt/tinyos-2.x/tos/platforms/bacon/PlatformBusPowerP.nc"
static inline void PlatformBusPowerP__stopDoneTask__runTask(void )
#line 16
{
  PlatformBusPowerP__SplitControl__stopDone(SUCCESS);
}

# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t BusPowerC__clearStartFlags__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(BusPowerC__clearStartFlags);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 93 "/opt/tinyos-2.x/tos/lib/busPower/BusPowerC.nc"
static inline void BusPowerC__SubSplitControl__startDone(error_t err)
#line 93
{
  BusPowerC__state = BusPowerC__S_ON;
  BusPowerC__clearStartFlags__postTask();
}

# 113 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static void PlatformBusPowerP__SplitControl__startDone(error_t error){
#line 113
  BusPowerC__SubSplitControl__startDone(error);
#line 113
}
#line 113
# 13 "/opt/tinyos-2.x/tos/platforms/bacon/PlatformBusPowerP.nc"
static inline void PlatformBusPowerP__startDoneTask__runTask(void )
#line 13
{
  PlatformBusPowerP__SplitControl__startDone(SUCCESS);
}

# 202 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
static inline void /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__Resource__default__granted(uint8_t id)
#line 202
{
}

# 102 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
inline static void /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__Resource__granted(uint8_t arg_0x40716e70){
#line 102
    /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__Resource__default__granted(arg_0x40716e70);
#line 102
}
#line 102
# 216 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
static inline void /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__ResourceConfigure__default__configure(uint8_t id)
#line 216
{
}

# 59 "/opt/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
inline static void /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__ResourceConfigure__configure(uint8_t arg_0x40730cf8){
#line 59
    /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__ResourceConfigure__default__configure(arg_0x40730cf8);
#line 59
}
#line 59
# 190 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
static inline void /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__grantedTask__runTask(void )
#line 190
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 191
    {
      /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__resId = /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__reqResId;
      /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__state = /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__RES_BUSY;
    }
#line 194
    __nesc_atomic_end(__nesc_atomic); }
  /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__ResourceConfigure__configure(/*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__resId);
  /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__Resource__granted(/*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__resId);
}

# 103 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__startAt(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type t0, /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type dt){
#line 103
  /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__startAt(t0, dt);
#line 103
}
#line 103
# 58 "/opt/tinyos-2.x/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__start(uint32_t t0, uint32_t dt, bool oneshot)
{
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__m_dt = dt;
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__m_oneshot = oneshot;
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__startAt(t0, dt);
}

#line 93
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__startOneShotAt(uint32_t t0, uint32_t dt)
{
#line 94
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__start(t0, dt, TRUE);
}

# 129 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__startOneShotAt(uint32_t t0, uint32_t dt){
#line 129
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__startOneShotAt(t0, dt);
#line 129
}
#line 129
# 65 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430AlarmC.nc"
static inline void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__stop(void )
{
  /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430TimerControl__disableEvents();
}

# 73 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__stop(void ){
#line 73
  /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__stop();
#line 73
}
#line 73
# 102 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static inline void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__stop(void )
{
  /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__stop();
}

# 73 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__stop(void ){
#line 73
  /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__stop();
#line 73
}
#line 73
# 71 "/opt/tinyos-2.x/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__stop(void )
{
#line 72
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__stop();
}

# 78 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__stop(void ){
#line 78
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__stop();
#line 78
}
#line 78
# 64 "/opt/tinyos-2.x/tos/lib/timer/Counter.nc"
inline static /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Counter__size_type /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Counter__get(void ){
#line 64
  unsigned long __nesc_result;
#line 64

#line 64
  __nesc_result = /*CounterMilli32C.Transform*/TransformCounterC__0__Counter__get();
#line 64

#line 64
  return __nesc_result;
#line 64
}
#line 64
# 86 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static inline /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__getNow(void )
{
  return /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Counter__get();
}

# 109 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__getNow(void ){
#line 109
  unsigned long __nesc_result;
#line 109

#line 109
  __nesc_result = /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__getNow();
#line 109

#line 109
  return __nesc_result;
#line 109
}
#line 109
# 96 "/opt/tinyos-2.x/tos/lib/timer/AlarmToTimerC.nc"
static inline uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__getNow(void )
{
#line 97
  return /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__getNow();
}

# 136 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
inline static uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__getNow(void ){
#line 136
  unsigned long __nesc_result;
#line 136

#line 136
  __nesc_result = /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__getNow();
#line 136

#line 136
  return __nesc_result;
#line 136
}
#line 136
# 100 "/opt/tinyos-2.x/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__runTask(void )
{




  uint32_t now = /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__getNow();
  int32_t min_remaining = (1UL << 31) - 1;
  bool min_remaining_isset = FALSE;
  uint16_t num;

  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__stop();

  for (num = 0; num < /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__NUM_TIMERS; num++) 
    {
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer_t *timer = &/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__m_timers[num];

      if (timer->isrunning) 
        {
          uint32_t elapsed = now - timer->t0;
          int32_t remaining = timer->dt - elapsed;

          if (remaining < min_remaining) 
            {
              min_remaining = remaining;
              min_remaining_isset = TRUE;
            }
        }
    }

  if (min_remaining_isset) 
    {
      if (min_remaining <= 0) {
        /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__fireTimers(now);
        }
      else {
#line 135
        /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__startOneShotAt(now, min_remaining);
        }
    }
}

#line 204
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__default__fired(uint8_t num)
{
}

# 83 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__fired(uint8_t arg_0x4090a9f0){
#line 83
    /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__default__fired(arg_0x4090a9f0);
#line 83
}
#line 83
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 139 "/opt/tinyos-2.x/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__fired(void )
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__fireTimers(/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__getNow());
}

# 83 "/opt/tinyos-2.x/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__fired(void ){
#line 83
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__fired();
#line 83
}
#line 83
# 91 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static inline /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__getAlarm(void )
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 93
    {
      /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type __nesc_temp = 
#line 93
      /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__m_t0 + /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__m_dt;

      {
#line 93
        __nesc_atomic_end(__nesc_atomic); 
#line 93
        return __nesc_temp;
      }
    }
#line 95
    __nesc_atomic_end(__nesc_atomic); }
}

# 116 "/opt/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__getAlarm(void ){
#line 116
  unsigned long __nesc_result;
#line 116

#line 116
  __nesc_result = /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__getAlarm();
#line 116

#line 116
  return __nesc_result;
#line 116
}
#line 116
# 74 "/opt/tinyos-2.x/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__runTask(void )
{
  if (/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__m_oneshot == FALSE) {
    /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__start(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__getAlarm(), /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__m_dt, FALSE);
    }
#line 78
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__fired();
}

# 59 "/opt/tinyos-2.x/tos/platforms/surf/hardware/usci/PlatformSerialP.nc"
static inline void PlatformSerialP__Resource__granted(void )
#line 59
{
}

# 202 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__default__granted(uint8_t id)
#line 202
{
}

# 102 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
inline static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__granted(uint8_t arg_0x40716e70){
#line 102
  switch (arg_0x40716e70) {
#line 102
    case /*PlatformSerialC.UartC*/Msp430UsciUartA0C__0__CLIENT_ID:
#line 102
      PlatformSerialP__Resource__granted();
#line 102
      break;
#line 102
    default:
#line 102
      /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__default__granted(arg_0x40716e70);
#line 102
      break;
#line 102
    }
#line 102
}
#line 102
# 190 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__grantedTask__runTask(void )
#line 190
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 191
    {
      /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__resId = /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__reqResId;
      /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__state = /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__RES_BUSY;
    }
#line 194
    __nesc_atomic_end(__nesc_atomic); }
  /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__configure(/*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__resId);
  /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__granted(/*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__resId);
}

# 245 "TestSenderP.nc"
static inline void TestSenderP__reportDSSR__runTask(void )
#line 245
{
}

# 269 "/usr/lib/ncc/nesc_nx.h"
static __inline  uint16_t __nesc_hton_uint16(void * target, uint16_t value)
#line 269
{
  uint8_t *base = target;

#line 271
  base[1] = value;
  base[0] = value >> 8;
  return value;
}

#line 240
static __inline  uint8_t __nesc_hton_uint8(void * target, uint8_t value)
#line 240
{
  uint8_t *base = target;

#line 242
  base[0] = value;
  return value;
}

# 127 "/opt/tinyos-2.x/tos/lib/serial/SerialActiveMessageP.nc"
static inline void /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Packet__setPayloadLength(message_t *msg, uint8_t len)
#line 127
{
  __nesc_hton_uint8(/*SerialActiveMessageC.AM*/SerialActiveMessageP__0__getHeader(msg)->length.data, len);
}

# 94 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
inline static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Packet__setPayloadLength(message_t * msg, uint8_t len){
#line 94
  /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Packet__setPayloadLength(msg, len);
#line 94
}
#line 94
# 90 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static inline error_t /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Send__send(uint8_t clientId, message_t *msg, 
uint8_t len)
#line 91
{
  if (clientId >= 1) {
      return FAIL;
    }
  if (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__queue[clientId].msg != (void *)0) {
      return EBUSY;
    }
  ;

  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__queue[clientId].msg = msg;
  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Packet__setPayloadLength(msg, len);

  if (/*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__current >= 1) {
      error_t err;
      am_id_t amId = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__AMPacket__type(msg);
      am_addr_t dest = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__AMPacket__destination(msg);

      ;
      /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__current = clientId;

      err = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__AMSend__send(amId, dest, msg, len);
      if (err != SUCCESS) {
          ;
          /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__current = 1;
          /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__queue[clientId].msg = (void *)0;
        }

      return err;
    }
  else {
      ;
    }
  return SUCCESS;
}

# 75 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
inline static error_t /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__Send__send(message_t * msg, uint8_t len){
#line 75
  unsigned char __nesc_result;
#line 75

#line 75
  __nesc_result = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Send__send(0U, msg, len);
#line 75

#line 75
  return __nesc_result;
#line 75
}
#line 75
# 177 "/opt/tinyos-2.x/tos/lib/serial/SerialActiveMessageP.nc"
static inline void /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMPacket__setType(message_t *amsg, am_id_t type)
#line 177
{
  serial_header_t *header = /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__getHeader(amsg);

#line 179
  __nesc_hton_uint8(header->type.data, type);
}

# 162 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
inline static void /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__AMPacket__setType(message_t * amsg, am_id_t t){
#line 162
  /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMPacket__setType(amsg, t);
#line 162
}
#line 162
# 158 "/opt/tinyos-2.x/tos/lib/serial/SerialActiveMessageP.nc"
static inline void /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMPacket__setDestination(message_t *amsg, am_addr_t addr)
#line 158
{
  serial_header_t *header = /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__getHeader(amsg);

#line 160
  __nesc_hton_uint16(header->dest.data, addr);
}

# 103 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
inline static void /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__AMPacket__setDestination(message_t * amsg, am_addr_t addr){
#line 103
  /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMPacket__setDestination(amsg, addr);
#line 103
}
#line 103
# 53 "/opt/tinyos-2.x/tos/system/AMQueueEntryP.nc"
static inline error_t /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__AMSend__send(am_addr_t dest, 
message_t *msg, 
uint8_t len)
#line 55
{
  /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__AMPacket__setDestination(msg, dest);
  /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__AMPacket__setType(msg, 222U);
  return /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__Send__send(msg, len);
}

# 80 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static error_t TestSenderP__ReportSend__send(am_addr_t addr, message_t * msg, uint8_t len){
#line 80
  unsigned char __nesc_result;
#line 80

#line 80
  __nesc_result = /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__AMSend__send(addr, msg, len);
#line 80

#line 80
  return __nesc_result;
#line 80
}
#line 80
# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/CUSTOM_HC.nc"
static inline uint16_t CUSTOM_HC__Get__get(void )
#line 11
{
  return 0;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_2FSK_1P2K_SENS_HC.nc"
static inline uint16_t SRFS6_868_2FSK_1P2K_SENS_HC__Get__get(void )
#line 11
{
  return 1;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_100K_CUR_HC.nc"
static inline uint16_t SRFS6_868_GFSK_100K_CUR_HC__Get__get(void )
#line 11
{
  return 2;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_100K_SENS_HC.nc"
static inline uint16_t SRFS6_868_GFSK_100K_SENS_HC__Get__get(void )
#line 11
{
  return 3;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_10K_CUR_HC.nc"
static inline uint16_t SRFS6_868_GFSK_10K_CUR_HC__Get__get(void )
#line 11
{
  return 4;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_10K_SENS_HC.nc"
static inline uint16_t SRFS6_868_GFSK_10K_SENS_HC__Get__get(void )
#line 11
{
  return 5;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_175K_CUR_HC.nc"
static inline uint16_t SRFS6_868_GFSK_175K_CUR_HC__Get__get(void )
#line 11
{
  return 6;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_175K_SENS_HC.nc"
static inline uint16_t SRFS6_868_GFSK_175K_SENS_HC__Get__get(void )
#line 11
{
  return 7;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_1P2K_CUR_HC.nc"
static inline uint16_t SRFS6_868_GFSK_1P2K_CUR_HC__Get__get(void )
#line 11
{
  return 8;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_1P2K_SENS_HC.nc"
static inline uint16_t SRFS6_868_GFSK_1P2K_SENS_HC__Get__get(void )
#line 11
{
  return 9;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_250K_CUR_HC.nc"
static inline uint16_t SRFS6_868_GFSK_250K_CUR_HC__Get__get(void )
#line 11
{
  return 10;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_250K_SENS_HC.nc"
static inline uint16_t SRFS6_868_GFSK_250K_SENS_HC__Get__get(void )
#line 11
{
  return 11;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_2P4K_CUR_HC.nc"
static inline uint16_t SRFS6_868_GFSK_2P4K_CUR_HC__Get__get(void )
#line 11
{
  return 12;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_2P4K_SENS_HC.nc"
static inline uint16_t SRFS6_868_GFSK_2P4K_SENS_HC__Get__get(void )
#line 11
{
  return 13;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_38P4K_CUR_HC.nc"
static inline uint16_t SRFS6_868_GFSK_38P4K_CUR_HC__Get__get(void )
#line 11
{
  return 14;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_38P4K_SENS_HC.nc"
static inline uint16_t SRFS6_868_GFSK_38P4K_SENS_HC__Get__get(void )
#line 11
{
  return 15;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_4P8K_CUR_HC.nc"
static inline uint16_t SRFS6_868_GFSK_4P8K_CUR_HC__Get__get(void )
#line 11
{
  return 16;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_4P8K_SENS_HC.nc"
static inline uint16_t SRFS6_868_GFSK_4P8K_SENS_HC__Get__get(void )
#line 11
{
  return 17;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_76P8K_CUR_HC.nc"
static inline uint16_t SRFS6_868_GFSK_76P8K_CUR_HC__Get__get(void )
#line 11
{
  return 18;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_76P8K_SENS_HC.nc"
static inline uint16_t SRFS6_868_GFSK_76P8K_SENS_HC__Get__get(void )
#line 11
{
  return 19;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_MSK_500K_HC.nc"
static inline uint16_t SRFS6_868_MSK_500K_HC__Get__get(void )
#line 11
{
  return 20;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_PRE802154G_HC.nc"
static inline uint16_t SRFS6_PRE802154G_HC__Get__get(void )
#line 11
{
  return 21;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_RESET_HC.nc"
static inline uint16_t SRFS6_RESET_HC__Get__get(void )
#line 11
{
  return 22;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_779_MSK_250K_HC.nc"
static inline uint16_t SRFS7_779_MSK_250K_HC__Get__get(void )
#line 11
{
  return 23;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_902P2_GFSK_50K_135B_HC.nc"
static inline uint16_t SRFS7_902P2_GFSK_50K_135B_HC__Get__get(void )
#line 11
{
  return 24;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_902P2_GFSK_50K_163B_HC.nc"
static inline uint16_t SRFS7_902P2_GFSK_50K_163B_HC__Get__get(void )
#line 11
{
  return 25;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_STI_902_GFSK_1P2K_HC.nc"
static inline uint16_t SRFS7_STI_902_GFSK_1P2K_HC__Get__get(void )
#line 11
{
  return 26;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_STI_902_GFSK_250K_HC.nc"
static inline uint16_t SRFS7_STI_902_GFSK_250K_HC__Get__get(void )
#line 11
{
  return 27;
}

# 11 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/TINYOSRF1A_HC.nc"
static inline uint16_t TINYOSRF1A_HC__Get__get(void )
#line 11
{
  return 28;
}

# 64 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
static inline uint16_t /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubGet__default__get(uint8_t clientId)
#line 64
{
#line 64
  return 0xFFFF;
}

# 55 "/opt/tinyos-2.x/tos/interfaces/Get.nc"
inline static /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubGet__val_t /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubGet__get(uint8_t arg_0x40d93da8){
#line 55
  unsigned int __nesc_result;
#line 55

#line 55
  switch (arg_0x40d93da8) {
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CUSTOM_HC_LOCAL_ID:
#line 55
      __nesc_result = CUSTOM_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_2FSK_1P2K_SENS_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_2FSK_1P2K_SENS_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_100K_CUR_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_GFSK_100K_CUR_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_100K_SENS_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_GFSK_100K_SENS_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_10K_CUR_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_GFSK_10K_CUR_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_10K_SENS_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_GFSK_10K_SENS_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_175K_CUR_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_GFSK_175K_CUR_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_175K_SENS_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_GFSK_175K_SENS_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_1P2K_CUR_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_GFSK_1P2K_CUR_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_1P2K_SENS_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_GFSK_1P2K_SENS_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_250K_CUR_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_GFSK_250K_CUR_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_250K_SENS_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_GFSK_250K_SENS_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_2P4K_CUR_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_GFSK_2P4K_CUR_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_2P4K_SENS_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_GFSK_2P4K_SENS_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_38P4K_CUR_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_GFSK_38P4K_CUR_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_38P4K_SENS_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_GFSK_38P4K_SENS_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_4P8K_CUR_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_GFSK_4P8K_CUR_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_4P8K_SENS_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_GFSK_4P8K_SENS_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_76P8K_CUR_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_GFSK_76P8K_CUR_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_76P8K_SENS_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_GFSK_76P8K_SENS_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_MSK_500K_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_868_MSK_500K_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_PRE802154G_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_PRE802154G_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_RESET_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS6_RESET_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_779_MSK_250K_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS7_779_MSK_250K_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_902P2_GFSK_50K_135B_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS7_902P2_GFSK_50K_135B_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_902P2_GFSK_50K_163B_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS7_902P2_GFSK_50K_163B_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_STI_902_GFSK_1P2K_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS7_STI_902_GFSK_1P2K_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_STI_902_GFSK_250K_HC_LOCAL_ID:
#line 55
      __nesc_result = SRFS7_STI_902_GFSK_250K_HC__Get__get();
#line 55
      break;
#line 55
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__TINYOSRF1A_HC_LOCAL_ID:
#line 55
      __nesc_result = TINYOSRF1A_HC__Get__get();
#line 55
      break;
#line 55
    default:
#line 55
      __nesc_result = /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubGet__default__get(arg_0x40d93da8);
#line 55
      break;
#line 55
    }
#line 55

#line 55
  return __nesc_result;
#line 55
}
#line 55
# 41 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
static inline uint16_t /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aMulti__getConfigId(void )
#line 41
{
  return /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubGet__get(/*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__currentClient);
}

# 27 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMulti.nc"
inline static uint16_t TestSenderP__Rf1aMulti__getConfigId(void ){
#line 27
  unsigned int __nesc_result;
#line 27

#line 27
  __nesc_result = /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aMulti__getConfigId();
#line 27

#line 27
  return __nesc_result;
#line 27
}
#line 27
# 131 "/opt/tinyos-2.x/tos/lib/serial/SerialActiveMessageP.nc"
static inline uint8_t /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Packet__maxPayloadLength(void )
#line 131
{
  return 127 - sizeof(rf1a_ieee154_t );
}

static inline void */*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Packet__getPayload(message_t *msg, uint8_t len)
#line 135
{
  if (len > /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Packet__maxPayloadLength()) {
      return (void *)0;
    }
  else {
      return (void * )msg->data;
    }
}

#line 97
static inline void */*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMSend__getPayload(am_id_t id, message_t *m, uint8_t len)
#line 97
{
  return /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Packet__getPayload(m, len);
}

# 135 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static void * /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__AMSend__getPayload(am_id_t arg_0x40ab51b8, message_t * msg, uint8_t len){
#line 135
  void *__nesc_result;
#line 135

#line 135
  __nesc_result = /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMSend__getPayload(arg_0x40ab51b8, msg, len);
#line 135

#line 135
  return __nesc_result;
#line 135
}
#line 135
# 211 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static inline void */*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Send__getPayload(uint8_t id, message_t *m, uint8_t len)
#line 211
{
  return /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__AMSend__getPayload(0, m, len);
}

# 125 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
inline static void * /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__Send__getPayload(message_t * msg, uint8_t len){
#line 125
  void *__nesc_result;
#line 125

#line 125
  __nesc_result = /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Send__getPayload(0U, msg, len);
#line 125

#line 125
  return __nesc_result;
#line 125
}
#line 125
# 73 "/opt/tinyos-2.x/tos/system/AMQueueEntryP.nc"
static inline void */*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__AMSend__getPayload(message_t *m, uint8_t len)
#line 73
{
  return /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__Send__getPayload(m, len);
}

# 135 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static void * TestSenderP__ReportSend__getPayload(message_t * msg, uint8_t len){
#line 135
  void *__nesc_result;
#line 135

#line 135
  __nesc_result = /*TestSenderAppC.ReportSend.AMQueueEntryP*/AMQueueEntryP__1__AMSend__getPayload(msg, len);
#line 135

#line 135
  return __nesc_result;
#line 135
}
#line 135
# 223 "TestSenderP.nc"
static inline void TestSenderP__reportTask__runTask(void )
#line 223
{
  sender_report_t *rpt = TestSenderP__ReportSend__getPayload(&TestSenderP__smsg, sizeof(sender_report_t ));



  __nesc_hton_uint16(rpt->configId.data, TestSenderP__Rf1aMulti__getConfigId());
  __nesc_hton_uint16(rpt->seqNum.data, TestSenderP__seqNum);
  TestSenderP__ReportSend__send(AM_BROADCAST_ADDR, &TestSenderP__smsg, sizeof(sender_report_t ));
}

#line 160
static inline void TestSenderP__reportRserr__runTask(void )
#line 160
{
}

#line 86
static inline void TestSenderP__reportSI__runTask(void )
#line 86
{
}

#line 81
static inline void TestSenderP__reportSRI__runTask(void )
#line 81
{
}

#line 76
static inline void TestSenderP__reportNI__runTask(void )
#line 76
{
}

# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t TestSenderP__reportRserr__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(TestSenderP__reportRserr);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 80 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__send(am_id_t arg_0x40ab51b8, am_addr_t addr, message_t * msg, uint8_t len){
#line 80
  unsigned char __nesc_result;
#line 80

#line 80
  __nesc_result = Rf1aActiveMessageP__AMSend__send(arg_0x40ab51b8, addr, msg, len);
#line 80

#line 80
  return __nesc_result;
#line 80
}
#line 80
# 78 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
inline static am_addr_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMPacket__destination(message_t * amsg){
#line 78
  unsigned int __nesc_result;
#line 78

#line 78
  __nesc_result = Rf1aAMPacketP__AMPacket__destination(amsg);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 88 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aAMPacketP.nc"
static inline am_id_t Rf1aAMPacketP__AMPacket__type(message_t *amsg)
{
  Rf1aAMPacketP__layer_header_t *lhp = Rf1aAMPacketP__layerHeader(amsg);

#line 91
  return __nesc_ntoh_leuint8(lhp->am_type.data);
}

# 147 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
inline static am_id_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMPacket__type(message_t * amsg){
#line 147
  unsigned char __nesc_result;
#line 147

#line 147
  __nesc_result = Rf1aAMPacketP__AMPacket__type(amsg);
#line 147

#line 147
  return __nesc_result;
#line 147
}
#line 147
# 155 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aIeee154PacketP.nc"
static inline void /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Packet__setPayloadLength(message_t *msg, uint8_t len)
#line 155
{
#line 155
  __nesc_hton_leuint16(/*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__metadata_(msg)->payload_length.data, len + sizeof(/*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__header_t ));
}

# 94 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
inline static void Rf1aAMPacketP__SubPacket__setPayloadLength(message_t * msg, uint8_t len){
#line 94
  /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Packet__setPayloadLength(msg, len);
#line 94
}
#line 94
# 73 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aAMPacketP.nc"
static inline void Rf1aAMPacketP__Packet__setPayloadLength(message_t *msg, uint8_t len)
#line 73
{
#line 73
  Rf1aAMPacketP__SubPacket__setPayloadLength(msg, len + sizeof(Rf1aAMPacketP__layer_header_t ));
}

# 94 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
inline static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Packet__setPayloadLength(message_t * msg, uint8_t len){
#line 94
  Rf1aAMPacketP__Packet__setPayloadLength(msg, len);
#line 94
}
#line 94
# 90 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static inline error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__send(uint8_t clientId, message_t *msg, 
uint8_t len)
#line 91
{
  if (clientId >= 1) {
      return FAIL;
    }
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[clientId].msg != (void *)0) {
      return EBUSY;
    }
  ;

  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[clientId].msg = msg;
  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Packet__setPayloadLength(msg, len);

  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current >= 1) {
      error_t err;
      am_id_t amId = /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMPacket__type(msg);
      am_addr_t dest = /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMPacket__destination(msg);

      ;
      /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current = clientId;

      err = /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__send(amId, dest, msg, len);
      if (err != SUCCESS) {
          ;
          /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current = 1;
          /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[clientId].msg = (void *)0;
        }

      return err;
    }
  else {
      ;
    }
  return SUCCESS;
}

# 75 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
inline static error_t /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__Send__send(message_t * msg, uint8_t len){
#line 75
  unsigned char __nesc_result;
#line 75

#line 75
  __nesc_result = /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__send(0U, msg, len);
#line 75

#line 75
  return __nesc_result;
#line 75
}
#line 75
# 162 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
inline static void /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__AMPacket__setType(message_t * amsg, am_id_t t){
#line 162
  Rf1aAMPacketP__AMPacket__setType(amsg, t);
#line 162
}
#line 162
#line 103
inline static void /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__AMPacket__setDestination(message_t * amsg, am_addr_t addr){
#line 103
  Rf1aAMPacketP__AMPacket__setDestination(amsg, addr);
#line 103
}
#line 103
# 53 "/opt/tinyos-2.x/tos/system/AMQueueEntryP.nc"
static inline error_t /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__AMSend__send(am_addr_t dest, 
message_t *msg, 
uint8_t len)
#line 55
{
  /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__AMPacket__setDestination(msg, dest);
  /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__AMPacket__setType(msg, 220U);
  return /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__Send__send(msg, len);
}

# 80 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static error_t TestSenderP__RadioSend__send(am_addr_t addr, message_t * msg, uint8_t len){
#line 80
  unsigned char __nesc_result;
#line 80

#line 80
  __nesc_result = /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__AMSend__send(addr, msg, len);
#line 80

#line 80
  return __nesc_result;
#line 80
}
#line 80
# 126 "/opt/tinyos-2.x/tos/interfaces/Packet.nc"
inline static void * Rf1aActiveMessageP__Packet__getPayload(message_t * msg, uint8_t len){
#line 126
  void *__nesc_result;
#line 126

#line 126
  __nesc_result = Rf1aAMPacketP__Packet__getPayload(msg, len);
#line 126

#line 126
  return __nesc_result;
#line 126
}
#line 126
# 78 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aActiveMessageP.nc"
static inline void *Rf1aActiveMessageP__AMSend__getPayload(am_id_t id, message_t *m, uint8_t len)
{
  return Rf1aActiveMessageP__Packet__getPayload(m, len);
}

# 135 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static void * /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__getPayload(am_id_t arg_0x40ab51b8, message_t * msg, uint8_t len){
#line 135
  void *__nesc_result;
#line 135

#line 135
  __nesc_result = Rf1aActiveMessageP__AMSend__getPayload(arg_0x40ab51b8, msg, len);
#line 135

#line 135
  return __nesc_result;
#line 135
}
#line 135
# 211 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static inline void */*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__getPayload(uint8_t id, message_t *m, uint8_t len)
#line 211
{
  return /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__getPayload(0, m, len);
}

# 125 "/opt/tinyos-2.x/tos/interfaces/Send.nc"
inline static void * /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__Send__getPayload(message_t * msg, uint8_t len){
#line 125
  void *__nesc_result;
#line 125

#line 125
  __nesc_result = /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Send__getPayload(0U, msg, len);
#line 125

#line 125
  return __nesc_result;
#line 125
}
#line 125
# 73 "/opt/tinyos-2.x/tos/system/AMQueueEntryP.nc"
static inline void */*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__AMSend__getPayload(message_t *m, uint8_t len)
#line 73
{
  return /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__Send__getPayload(m, len);
}

# 135 "/opt/tinyos-2.x/tos/interfaces/AMSend.nc"
inline static void * TestSenderP__RadioSend__getPayload(message_t * msg, uint8_t len){
#line 135
  void *__nesc_result;
#line 135

#line 135
  __nesc_result = /*TestSenderAppC.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP__0__AMSend__getPayload(msg, len);
#line 135

#line 135
  return __nesc_result;
#line 135
}
#line 135
# 165 "TestSenderP.nc"
static inline void TestSenderP__loadNextTask__runTask(void )
#line 165
{
  test_packet_t *pl = (test_packet_t *)TestSenderP__RadioSend__getPayload(&TestSenderP__rmsg, sizeof(test_packet_t ));



  __nesc_hton_uint16(pl->seqNum.data, TestSenderP__seqNum);
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 171
    {
      TestSenderP__state = TestSenderP__S_LOADING;
    }
#line 173
    __nesc_atomic_end(__nesc_atomic); }



  TestSenderP__rserr = TestSenderP__RadioSend__send(AM_BROADCAST_ADDR, &TestSenderP__rmsg, sizeof(test_packet_t ));
  TestSenderP__reportRserr__postTask();
}

# 64 "/opt/tinyos-2.x/tos/system/FcfsResourceQueueC.nc"
static inline bool /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__FcfsQueue__isEnqueued(resource_client_id_t id)
#line 64
{
  /* atomic removed: atomic calls only */
#line 65
  {
    unsigned char __nesc_temp = 
#line 65
    /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__resQ[id] != /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__NO_ENTRY || /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__qTail == id;

#line 65
    return __nesc_temp;
  }
}

#line 82
static inline error_t /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__FcfsQueue__enqueue(resource_client_id_t id)
#line 82
{
  /* atomic removed: atomic calls only */
#line 83
  {
    if (!/*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__FcfsQueue__isEnqueued(id)) {
        if (/*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__qHead == /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__NO_ENTRY) {
          /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__qHead = id;
          }
        else {
#line 88
          /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__resQ[/*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__qTail] = id;
          }
#line 89
        /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__qTail = id;
        {
          unsigned char __nesc_temp = 
#line 90
          SUCCESS;

#line 90
          return __nesc_temp;
        }
      }
#line 92
    {
      unsigned char __nesc_temp = 
#line 92
      EBUSY;

#line 92
      return __nesc_temp;
    }
  }
}

# 79 "/opt/tinyos-2.x/tos/interfaces/ResourceQueue.nc"
inline static error_t /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Queue__enqueue(resource_client_id_t id){
#line 79
  unsigned char __nesc_result;
#line 79

#line 79
  __nesc_result = /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__FcfsQueue__enqueue(id);
#line 79

#line 79
  return __nesc_result;
#line 79
}
#line 79
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__grantedTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__grantedTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 167 "/opt/tinyos-2.x/tos/system/SimpleArbiterP.nc"
static inline void /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ResourceRequested__default__requested(uint8_t id)
#line 167
{
}

# 53 "/opt/tinyos-2.x/tos/interfaces/ResourceRequested.nc"
inline static void /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ResourceRequested__requested(uint8_t arg_0x40c3d770){
#line 53
    /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ResourceRequested__default__requested(arg_0x40c3d770);
#line 53
}
#line 53
# 71 "/opt/tinyos-2.x/tos/system/SimpleArbiterP.nc"
static inline error_t /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Resource__request(uint8_t id)
#line 71
{
  /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ResourceRequested__requested(/*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__resId);
  /* atomic removed: atomic calls only */
#line 73
  {
    if (/*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__state == /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__RES_IDLE) {
        /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__state = /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__RES_GRANTING;
        /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__reqResId = id;
        /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__grantedTask__postTask();
        {
          unsigned char __nesc_temp = 
#line 78
          SUCCESS;

#line 78
          return __nesc_temp;
        }
      }
#line 80
    {
      unsigned char __nesc_temp = 
#line 80
      /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Queue__enqueue(id);

#line 80
      return __nesc_temp;
    }
  }
}

# 88 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
inline static error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Resource__request(void ){
#line 88
  unsigned char __nesc_result;
#line 88

#line 88
  __nesc_result = /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Resource__request(/*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT);
#line 88

#line 88
  return __nesc_result;
#line 88
}
#line 88
# 135 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
static inline error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SplitControl__start(void )
{
  /* atomic removed: atomic calls only */
#line 137
  {

    switch (/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__split_control_state) {
        case /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SCS_on: 
          {
            unsigned char __nesc_temp = 
#line 141
            EALREADY;

#line 141
            return __nesc_temp;
          }
#line 142
        break;
        case /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SCS_starting: 
          {
            unsigned char __nesc_temp = 
#line 144
            SUCCESS;

#line 144
            return __nesc_temp;
          }
#line 145
        break;
        case /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SCS_stopping: 
          {
            unsigned char __nesc_temp = 
#line 147
            EBUSY;

#line 147
            return __nesc_temp;
          }
#line 148
        break;
        case /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SCS_off: 
          if (SUCCESS == /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Resource__request()) {
              /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__split_control_state = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SCS_starting;
              {
                unsigned char __nesc_temp = 
#line 152
                SUCCESS;

#line 152
                return __nesc_temp;
              }
            }
        default: 
          {
            unsigned char __nesc_temp = 
#line 156
            FAIL;

#line 156
            return __nesc_temp;
          }
      }
  }
}

# 104 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static error_t TestSenderP__SplitControl__start(void ){
#line 104
  unsigned char __nesc_result;
#line 104

#line 104
  __nesc_result = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SplitControl__start();
#line 104

#line 104
  return __nesc_result;
#line 104
}
#line 104
# 9 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
static inline uint8_t /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aMulti__getNumConfigs(void )
#line 9
{
  return 29U;
}

# 10 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMulti.nc"
inline static uint8_t TestSenderP__Rf1aMulti__getNumConfigs(void ){
#line 10
  unsigned char __nesc_result;
#line 10

#line 10
  __nesc_result = /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aMulti__getNumConfigs();
#line 10

#line 10
  return __nesc_result;
#line 10
}
#line 10
# 13 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
static inline uint8_t /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aMulti__getConfig(void )
#line 13
{
  return /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__currentClient;
}

# 21 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMulti.nc"
inline static uint8_t TestSenderP__Rf1aMulti__getConfig(void ){
#line 21
  unsigned char __nesc_result;
#line 21

#line 21
  __nesc_result = /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aMulti__getConfig();
#line 21

#line 21
  return __nesc_result;
#line 21
}
#line 21
# 17 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
static inline error_t /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aMulti__setConfig(uint8_t clientId)
#line 17
{
  if (clientId > 29U) {
      return EINVAL;
    }
  else 
#line 20
    {
      /* atomic removed: atomic calls only */
#line 21
      {
        /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__currentClient = clientId;
      }

      return SUCCESS;
    }
}

# 16 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMulti.nc"
inline static error_t TestSenderP__Rf1aMulti__setConfig(uint8_t configId){
#line 16
  unsigned char __nesc_result;
#line 16

#line 16
  __nesc_result = /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aMulti__setConfig(configId);
#line 16

#line 16
  return __nesc_result;
#line 16
}
#line 16
# 127 "TestSenderP.nc"
static inline void TestSenderP__nextConfigTask__runTask(void )
#line 127
{



  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 131
    {
      TestSenderP__Rf1aMulti__setConfig((TestSenderP__Rf1aMulti__getConfig() + 1) % TestSenderP__Rf1aMulti__getNumConfigs());
      TestSenderP__SplitControl__start();
      TestSenderP__seqNum = 0;
      TestSenderP__state = TestSenderP__S_RADIO_STARTING;
      TestSenderP__Leds__set(1);
    }
#line 137
    __nesc_atomic_end(__nesc_atomic); }
}

# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__stopDone_task__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__stopDone_task);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 207 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__released(void )
{
  /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__stopDone_task__postTask();
}

# 1440 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__released(uint8_t client)
#line 1440
{
}

# 321 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__released(uint8_t arg_0x40c74aa8){
#line 321
  switch (arg_0x40c74aa8) {
#line 321
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT:
#line 321
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__released();
#line 321
      break;
#line 321
    default:
#line 321
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__released(arg_0x40c74aa8);
#line 321
      break;
#line 321
    }
#line 321
}
#line 321
# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/CUSTOM_HC.nc"
static inline void CUSTOM_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_2FSK_1P2K_SENS_HC.nc"
static inline void SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_100K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_100K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_10K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_10K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_175K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_175K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_1P2K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_1P2K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_250K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_250K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_2P4K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_2P4K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_38P4K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_38P4K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_4P8K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_4P8K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_76P8K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_76P8K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_MSK_500K_HC.nc"
static inline void SRFS6_868_MSK_500K_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_PRE802154G_HC.nc"
static inline void SRFS6_PRE802154G_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_RESET_HC.nc"
static inline void SRFS6_RESET_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_779_MSK_250K_HC.nc"
static inline void SRFS7_779_MSK_250K_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_902P2_GFSK_50K_135B_HC.nc"
static inline void SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_902P2_GFSK_50K_163B_HC.nc"
static inline void SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_STI_902_GFSK_1P2K_HC.nc"
static inline void SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_STI_902_GFSK_250K_HC.nc"
static inline void SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 111 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/TINYOSRF1A_HC.nc"
static inline void TINYOSRF1A_HC__Rf1aConfigure__postUnconfigure(void )
#line 111
{
}

# 68 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__postUnconfigure(uint8_t clientId)
#line 68
{
}

# 83 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
inline static void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__postUnconfigure(uint8_t arg_0x40d95768){
#line 83
  switch (arg_0x40d95768) {
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CUSTOM_HC_LOCAL_ID:
#line 83
      CUSTOM_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_2FSK_1P2K_SENS_HC_LOCAL_ID:
#line 83
      SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_100K_CUR_HC_LOCAL_ID:
#line 83
      SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_100K_SENS_HC_LOCAL_ID:
#line 83
      SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_10K_CUR_HC_LOCAL_ID:
#line 83
      SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_10K_SENS_HC_LOCAL_ID:
#line 83
      SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_175K_CUR_HC_LOCAL_ID:
#line 83
      SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_175K_SENS_HC_LOCAL_ID:
#line 83
      SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_1P2K_CUR_HC_LOCAL_ID:
#line 83
      SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_1P2K_SENS_HC_LOCAL_ID:
#line 83
      SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_250K_CUR_HC_LOCAL_ID:
#line 83
      SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_250K_SENS_HC_LOCAL_ID:
#line 83
      SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_2P4K_CUR_HC_LOCAL_ID:
#line 83
      SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_2P4K_SENS_HC_LOCAL_ID:
#line 83
      SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_38P4K_CUR_HC_LOCAL_ID:
#line 83
      SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_38P4K_SENS_HC_LOCAL_ID:
#line 83
      SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_4P8K_CUR_HC_LOCAL_ID:
#line 83
      SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_4P8K_SENS_HC_LOCAL_ID:
#line 83
      SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_76P8K_CUR_HC_LOCAL_ID:
#line 83
      SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_76P8K_SENS_HC_LOCAL_ID:
#line 83
      SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_MSK_500K_HC_LOCAL_ID:
#line 83
      SRFS6_868_MSK_500K_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_PRE802154G_HC_LOCAL_ID:
#line 83
      SRFS6_PRE802154G_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_RESET_HC_LOCAL_ID:
#line 83
      SRFS6_RESET_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_779_MSK_250K_HC_LOCAL_ID:
#line 83
      SRFS7_779_MSK_250K_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_902P2_GFSK_50K_135B_HC_LOCAL_ID:
#line 83
      SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_902P2_GFSK_50K_163B_HC_LOCAL_ID:
#line 83
      SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_STI_902_GFSK_1P2K_HC_LOCAL_ID:
#line 83
      SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_STI_902_GFSK_250K_HC_LOCAL_ID:
#line 83
      SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__TINYOSRF1A_HC_LOCAL_ID:
#line 83
      TINYOSRF1A_HC__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    default:
#line 83
      /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__postUnconfigure(arg_0x40d95768);
#line 83
      break;
#line 83
    }
#line 83
}
#line 83
# 57 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__postUnconfigure(void )
#line 57
{
  /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__postUnconfigure(/*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__currentClient);
}

# 406 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__postUnconfigure(uint8_t client)
#line 406
{
}

# 83 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__postUnconfigure(uint8_t arg_0x40c6b300){
#line 83
  switch (arg_0x40c6b300) {
#line 83
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT:
#line 83
      /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__postUnconfigure();
#line 83
      break;
#line 83
    default:
#line 83
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__postUnconfigure(arg_0x40c6b300);
#line 83
      break;
#line 83
    }
#line 83
}
#line 83
# 389 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__unconfigure_(void )
{
  /* atomic removed: atomic calls only */
#line 391
  {
    /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__setIe(~/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IFG_INTERRUPT & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__getIe());
    /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__resetRadioCore();
  }
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/CUSTOM_HC.nc"
static inline void CUSTOM_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_2FSK_1P2K_SENS_HC.nc"
static inline void SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_100K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_100K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_10K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_10K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_175K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_175K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_1P2K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_1P2K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_250K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_250K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_2P4K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_2P4K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_38P4K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_38P4K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_4P8K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_4P8K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_76P8K_CUR_HC.nc"
static inline void SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_GFSK_76P8K_SENS_HC.nc"
static inline void SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_868_MSK_500K_HC.nc"
static inline void SRFS6_868_MSK_500K_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_PRE802154G_HC.nc"
static inline void SRFS6_PRE802154G_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS6_RESET_HC.nc"
static inline void SRFS6_RESET_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_779_MSK_250K_HC.nc"
static inline void SRFS7_779_MSK_250K_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_902P2_GFSK_50K_135B_HC.nc"
static inline void SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_902P2_GFSK_50K_163B_HC.nc"
static inline void SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_STI_902_GFSK_1P2K_HC.nc"
static inline void SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/SRFS7_STI_902_GFSK_250K_HC.nc"
static inline void SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 110 "/opt/tinyos-2.x/tos/lib/rf1a-multi/configs/generated/TINYOSRF1A_HC.nc"
static inline void TINYOSRF1A_HC__Rf1aConfigure__preUnconfigure(void )
#line 110
{
}

# 67 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__preUnconfigure(uint8_t clientId)
#line 67
{
}

# 78 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
inline static void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__preUnconfigure(uint8_t arg_0x40d95768){
#line 78
  switch (arg_0x40d95768) {
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CUSTOM_HC_LOCAL_ID:
#line 78
      CUSTOM_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_2FSK_1P2K_SENS_HC_LOCAL_ID:
#line 78
      SRFS6_868_2FSK_1P2K_SENS_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_100K_CUR_HC_LOCAL_ID:
#line 78
      SRFS6_868_GFSK_100K_CUR_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_100K_SENS_HC_LOCAL_ID:
#line 78
      SRFS6_868_GFSK_100K_SENS_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_10K_CUR_HC_LOCAL_ID:
#line 78
      SRFS6_868_GFSK_10K_CUR_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_10K_SENS_HC_LOCAL_ID:
#line 78
      SRFS6_868_GFSK_10K_SENS_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_175K_CUR_HC_LOCAL_ID:
#line 78
      SRFS6_868_GFSK_175K_CUR_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_175K_SENS_HC_LOCAL_ID:
#line 78
      SRFS6_868_GFSK_175K_SENS_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_1P2K_CUR_HC_LOCAL_ID:
#line 78
      SRFS6_868_GFSK_1P2K_CUR_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_1P2K_SENS_HC_LOCAL_ID:
#line 78
      SRFS6_868_GFSK_1P2K_SENS_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_250K_CUR_HC_LOCAL_ID:
#line 78
      SRFS6_868_GFSK_250K_CUR_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_250K_SENS_HC_LOCAL_ID:
#line 78
      SRFS6_868_GFSK_250K_SENS_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_2P4K_CUR_HC_LOCAL_ID:
#line 78
      SRFS6_868_GFSK_2P4K_CUR_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_2P4K_SENS_HC_LOCAL_ID:
#line 78
      SRFS6_868_GFSK_2P4K_SENS_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_38P4K_CUR_HC_LOCAL_ID:
#line 78
      SRFS6_868_GFSK_38P4K_CUR_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_38P4K_SENS_HC_LOCAL_ID:
#line 78
      SRFS6_868_GFSK_38P4K_SENS_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_4P8K_CUR_HC_LOCAL_ID:
#line 78
      SRFS6_868_GFSK_4P8K_CUR_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_4P8K_SENS_HC_LOCAL_ID:
#line 78
      SRFS6_868_GFSK_4P8K_SENS_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_76P8K_CUR_HC_LOCAL_ID:
#line 78
      SRFS6_868_GFSK_76P8K_CUR_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_GFSK_76P8K_SENS_HC_LOCAL_ID:
#line 78
      SRFS6_868_GFSK_76P8K_SENS_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_868_MSK_500K_HC_LOCAL_ID:
#line 78
      SRFS6_868_MSK_500K_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_PRE802154G_HC_LOCAL_ID:
#line 78
      SRFS6_PRE802154G_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS6_RESET_HC_LOCAL_ID:
#line 78
      SRFS6_RESET_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_779_MSK_250K_HC_LOCAL_ID:
#line 78
      SRFS7_779_MSK_250K_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_902P2_GFSK_50K_135B_HC_LOCAL_ID:
#line 78
      SRFS7_902P2_GFSK_50K_135B_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_902P2_GFSK_50K_163B_HC_LOCAL_ID:
#line 78
      SRFS7_902P2_GFSK_50K_163B_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_STI_902_GFSK_1P2K_HC_LOCAL_ID:
#line 78
      SRFS7_STI_902_GFSK_1P2K_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__SRFS7_STI_902_GFSK_250K_HC_LOCAL_ID:
#line 78
      SRFS7_STI_902_GFSK_250K_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__TINYOSRF1A_HC_LOCAL_ID:
#line 78
      TINYOSRF1A_HC__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    default:
#line 78
      /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__default__preUnconfigure(arg_0x40d95768);
#line 78
      break;
#line 78
    }
#line 78
}
#line 78
# 54 "/opt/tinyos-2.x/tos/lib/rf1a-multi/Rf1aMultiPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__preUnconfigure(void )
#line 54
{
  /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__SubConfigure__preUnconfigure(/*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__currentClient);
}

# 405 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__preUnconfigure(uint8_t client)
#line 405
{
}

# 78 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aConfigure.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__preUnconfigure(uint8_t arg_0x40c6b300){
#line 78
  switch (arg_0x40c6b300) {
#line 78
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT:
#line 78
      /*Rf1aActiveMessageC.PhysicalC.Rf1aMultiPhysicalP*/Rf1aMultiPhysicalP__0__Rf1aConfigure__preUnconfigure();
#line 78
      break;
#line 78
    default:
#line 78
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__default__preUnconfigure(arg_0x40c6b300);
#line 78
      break;
#line 78
    }
#line 78
}
#line 78
# 419 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ResourceConfigure__unconfigure(uint8_t client)
{
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__preUnconfigure(client);
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__unconfigure_();
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aConfigure__postUnconfigure(client);
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__released(client);
}

# 65 "/opt/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
inline static void /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ResourceConfigure__unconfigure(uint8_t arg_0x40c67430){
#line 65
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ResourceConfigure__unconfigure(arg_0x40c67430);
#line 65
}
#line 65
# 68 "/opt/tinyos-2.x/tos/system/FcfsResourceQueueC.nc"
static inline resource_client_id_t /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__FcfsQueue__dequeue(void )
#line 68
{
  /* atomic removed: atomic calls only */
#line 69
  {
    if (/*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__qHead != /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__NO_ENTRY) {
        uint8_t id = /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__qHead;

#line 72
        /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__qHead = /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__resQ[/*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__qHead];
        if (/*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__qHead == /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__NO_ENTRY) {
          /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__qTail = /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__NO_ENTRY;
          }
#line 75
        /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__resQ[id] = /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__NO_ENTRY;
        {
          unsigned char __nesc_temp = 
#line 76
          id;

#line 76
          return __nesc_temp;
        }
      }
#line 78
    {
      unsigned char __nesc_temp = 
#line 78
      /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__NO_ENTRY;

#line 78
      return __nesc_temp;
    }
  }
}

# 70 "/opt/tinyos-2.x/tos/interfaces/ResourceQueue.nc"
inline static resource_client_id_t /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Queue__dequeue(void ){
#line 70
  unsigned char __nesc_result;
#line 70

#line 70
  __nesc_result = /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__FcfsQueue__dequeue();
#line 70

#line 70
  return __nesc_result;
#line 70
}
#line 70
# 60 "/opt/tinyos-2.x/tos/system/FcfsResourceQueueC.nc"
static inline bool /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__FcfsQueue__isEmpty(void )
#line 60
{
  /* atomic removed: atomic calls only */
#line 61
  {
    unsigned char __nesc_temp = 
#line 61
    /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__qHead == /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__NO_ENTRY;

#line 61
    return __nesc_temp;
  }
}

# 53 "/opt/tinyos-2.x/tos/interfaces/ResourceQueue.nc"
inline static bool /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Queue__isEmpty(void ){
#line 53
  unsigned char __nesc_result;
#line 53

#line 53
  __nesc_result = /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__FcfsQueue__isEmpty();
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53
# 97 "/opt/tinyos-2.x/tos/system/SimpleArbiterP.nc"
static inline error_t /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Resource__release(uint8_t id)
#line 97
{
  bool released = FALSE;

  /* atomic removed: atomic calls only */
#line 99
  {
    if (/*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__state == /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__RES_BUSY && /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__resId == id) {
        if (/*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Queue__isEmpty() == FALSE) {
            /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__resId = /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__NO_RES;
            /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__reqResId = /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Queue__dequeue();
            /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__state = /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__RES_GRANTING;
            /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__grantedTask__postTask();
          }
        else {
            /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__resId = /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__NO_RES;
            /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__state = /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__RES_IDLE;
          }
        released = TRUE;
      }
  }
  if (released == TRUE) {
      /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ResourceConfigure__unconfigure(id);
      return SUCCESS;
    }
  return FAIL;
}

# 120 "/opt/tinyos-2.x/tos/interfaces/Resource.nc"
inline static error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Resource__release(void ){
#line 120
  unsigned char __nesc_result;
#line 120

#line 120
  __nesc_result = /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__Resource__release(/*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT);
#line 120

#line 120
  return __nesc_result;
#line 120
}
#line 120
# 161 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
static inline error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SplitControl__stop(void )
{
  /* atomic removed: atomic calls only */
#line 163
  {

    switch (/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__split_control_state) {
        case /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SCS_off: 
          {
            unsigned char __nesc_temp = 
#line 167
            EALREADY;

#line 167
            return __nesc_temp;
          }
#line 168
        break;
        case /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SCS_stopping: 
          {
            unsigned char __nesc_temp = 
#line 170
            SUCCESS;

#line 170
            return __nesc_temp;
          }
#line 171
        break;
        case /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SCS_starting: 
          {
            unsigned char __nesc_temp = 
#line 173
            EBUSY;

#line 173
            return __nesc_temp;
          }
#line 174
        break;
        case /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SCS_on: 
          if (SUCCESS == /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Resource__release()) {
              /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__split_control_state = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SCS_stopping;
              {
                unsigned char __nesc_temp = 
#line 178
                SUCCESS;

#line 178
                return __nesc_temp;
              }
            }
        default: 
          {
            unsigned char __nesc_temp = 
#line 182
            FAIL;

#line 182
            return __nesc_temp;
          }
      }
  }
}

# 130 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static error_t TestSenderP__SplitControl__stop(void ){
#line 130
  unsigned char __nesc_result;
#line 130

#line 130
  __nesc_result = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SplitControl__stop();
#line 130

#line 130
  return __nesc_result;
#line 130
}
#line 130
# 97 "TestSenderP.nc"
static inline void TestSenderP__tryNextConfigTask__runTask(void )
#line 97
{



  if (TestSenderP__radioOn) {


      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 104
        {
          TestSenderP__state = TestSenderP__S_RADIO_STOPPING;
          TestSenderP__SplitControl__stop();
        }
#line 107
        __nesc_atomic_end(__nesc_atomic); }
    }
  else 
#line 108
    {
      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 109
        {
          TestSenderP__state = TestSenderP__S_START_NEXTCONFIG;
          TestSenderP__nextConfigTask__postTask();
        }
#line 112
        __nesc_atomic_end(__nesc_atomic); }
    }
}

# 69 "/opt/tinyos-2.x/tos/types/TinyError.h"
static inline  error_t ecombine(error_t r1, error_t r2)




{
  return r1 == r2 ? r1 : FAIL;
}

# 55 "/opt/tinyos-2.x/tos/system/FcfsResourceQueueC.nc"
static inline error_t /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__Init__init(void )
#line 55
{
  memset(/*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__resQ, /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__NO_ENTRY, sizeof /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__resQ);
  return SUCCESS;
}

#line 55
static inline error_t /*Msp430UsciB0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__1__Init__init(void )
#line 55
{
  memset(/*Msp430UsciB0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__1__resQ, /*Msp430UsciB0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__1__NO_ENTRY, sizeof /*Msp430UsciB0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__1__resQ);
  return SUCCESS;
}

# 89 "/opt/tinyos-2.x/tos/system/RandomMlcgC.nc"
static inline uint16_t RandomMlcgC__Random__rand16(void )
#line 89
{
  return (uint16_t )RandomMlcgC__Random__rand32();
}

# 52 "/opt/tinyos-2.x/tos/interfaces/Random.nc"
inline static uint16_t /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Random__rand16(void ){
#line 52
  unsigned int __nesc_result;
#line 52

#line 52
  __nesc_result = RandomMlcgC__Random__rand16();
#line 52

#line 52
  return __nesc_result;
#line 52
}
#line 52
# 73 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/ieee154/Rf1aIeee154PacketP.nc"
static inline error_t /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Init__init(void )
{

  /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__macDSN = (uint8_t )/*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Random__rand16();
  return SUCCESS;
}

# 55 "/opt/tinyos-2.x/tos/system/RandomMlcgC.nc"
static inline error_t RandomMlcgC__Init__init(void )
#line 55
{
  /* atomic removed: atomic calls only */
#line 56
  RandomMlcgC__seed = (uint32_t )(TOS_NODE_ID + 1);

  return SUCCESS;
}

# 55 "/opt/tinyos-2.x/tos/system/FcfsResourceQueueC.nc"
static inline error_t /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__Init__init(void )
#line 55
{
  memset(/*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__resQ, /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__NO_ENTRY, sizeof /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__resQ);
  return SUCCESS;
}

# 216 "/opt/tinyos-2.x/tos/lib/serial/SerialP.nc"
static __inline void SerialP__ackInit(void )
#line 216
{
  SerialP__ackQ.writePtr = SerialP__ackQ.readPtr = 0;
}

#line 207
static __inline void SerialP__rxInit(void )
#line 207
{
  SerialP__rxBuf.writePtr = SerialP__rxBuf.readPtr = 0;
  SerialP__rxState = SerialP__RXSTATE_INACTIVE;
  SerialP__rxByteCnt = 0;
  SerialP__rxProto = 0;
  SerialP__rxSeqno = 0;
  SerialP__rxCRC = 0;
}

#line 195
static __inline void SerialP__txInit(void )
#line 195
{
  uint8_t i;

  /* atomic removed: atomic calls only */
#line 197
  for (i = 0; i < SerialP__TX_BUFFER_COUNT; i++) SerialP__txBuf[i].state = SerialP__BUFFER_AVAILABLE;
  SerialP__txState = SerialP__TXSTATE_INACTIVE;
  SerialP__txByteCnt = 0;
  SerialP__txProto = 0;
  SerialP__txSeqno = 0;
  SerialP__txCRC = 0;
  SerialP__txPending = FALSE;
  SerialP__txIndex = 0;
}

#line 220
static inline error_t SerialP__Init__init(void )
#line 220
{

  SerialP__txInit();
  SerialP__rxInit();
  SerialP__ackInit();

  return SUCCESS;
}

# 62 "/opt/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t RealMainP__SoftwareInit__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = SerialP__Init__init();
#line 62
  __nesc_result = ecombine(__nesc_result, /*Rf1aC.HplRf1aC.ArbiterC.Queue*/FcfsResourceQueueC__2__Init__init());
#line 62
  __nesc_result = ecombine(__nesc_result, RandomMlcgC__Init__init());
#line 62
  __nesc_result = ecombine(__nesc_result, /*Rf1aActiveMessageC.PhyPacketC.PacketP*/Rf1aIeee154PacketP__0__Init__init());
#line 62
  __nesc_result = ecombine(__nesc_result, /*Msp430UsciB0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__1__Init__init());
#line 62
  __nesc_result = ecombine(__nesc_result, /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__Init__init());
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t SerialP__startDoneTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(SerialP__startDoneTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 348 "/opt/tinyos-2.x/tos/lib/serial/SerialP.nc"
static inline error_t SerialP__SplitControl__start(void )
#line 348
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 349
    {
      if (SerialP__txState != SerialP__TXSTATE_INACTIVE && SerialP__rxState != SerialP__RXSTATE_INACTIVE) 
        {
          unsigned char __nesc_temp = 
#line 351
          EALREADY;

          {
#line 351
            __nesc_atomic_end(__nesc_atomic); 
#line 351
            return __nesc_temp;
          }
        }
    }
#line 354
    __nesc_atomic_end(__nesc_atomic); }
#line 353
  SerialP__startDoneTask__postTask();
  return SUCCESS;
}

# 104 "/opt/tinyos-2.x/tos/interfaces/SplitControl.nc"
inline static error_t TestSenderP__SerialSplitControl__start(void ){
#line 104
  unsigned char __nesc_result;
#line 104

#line 104
  __nesc_result = SerialP__SplitControl__start();
#line 104

#line 104
  return __nesc_result;
#line 104
}
#line 104
# 55 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P24*/HplMsp430GeneralIORenP__12__IO__makeOutput(void )
#line 55
{
#line 55
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 55
    * (volatile uint8_t * )517U |= 0x01 << 4;
#line 55
    __nesc_atomic_end(__nesc_atomic); }
}

# 85 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*TestSenderAppC.DebugPin*/Msp430GpioC__10__HplGeneralIO__makeOutput(void ){
#line 85
  /*HplMsp430GeneralIOC.P24*/HplMsp430GeneralIORenP__12__IO__makeOutput();
#line 85
}
#line 85
# 54 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*TestSenderAppC.DebugPin*/Msp430GpioC__10__GeneralIO__makeOutput(void )
#line 54
{
#line 54
  /*TestSenderAppC.DebugPin*/Msp430GpioC__10__HplGeneralIO__makeOutput();
}

# 46 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void TestSenderP__DebugPin__makeOutput(void ){
#line 46
  /*TestSenderAppC.DebugPin*/Msp430GpioC__10__GeneralIO__makeOutput();
#line 46
}
#line 46
# 53 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P22*/HplMsp430GeneralIORenP__10__IO__makeInput(void )
#line 53
{
#line 53
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 53
    * (volatile uint8_t * )517U &= ~(0x01 << 2);
#line 53
    __nesc_atomic_end(__nesc_atomic); }
}

# 78 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*TestSenderAppC.SendPin*/Msp430GpioC__9__HplGeneralIO__makeInput(void ){
#line 78
  /*HplMsp430GeneralIOC.P22*/HplMsp430GeneralIORenP__10__IO__makeInput();
#line 78
}
#line 78
# 52 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*TestSenderAppC.SendPin*/Msp430GpioC__9__GeneralIO__makeInput(void )
#line 52
{
#line 52
  /*TestSenderAppC.SendPin*/Msp430GpioC__9__HplGeneralIO__makeInput();
}

# 44 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void TestSenderP__SendPin__makeInput(void ){
#line 44
  /*TestSenderAppC.SendPin*/Msp430GpioC__9__GeneralIO__makeInput();
#line 44
}
#line 44
# 53 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P21*/HplMsp430GeneralIORenP__9__IO__makeInput(void )
#line 53
{
#line 53
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 53
    * (volatile uint8_t * )517U &= ~(0x01 << 1);
#line 53
    __nesc_atomic_end(__nesc_atomic); }
}

# 78 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*TestSenderAppC.SendReadyPin*/Msp430GpioC__8__HplGeneralIO__makeInput(void ){
#line 78
  /*HplMsp430GeneralIOC.P21*/HplMsp430GeneralIORenP__9__IO__makeInput();
#line 78
}
#line 78
# 52 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*TestSenderAppC.SendReadyPin*/Msp430GpioC__8__GeneralIO__makeInput(void )
#line 52
{
#line 52
  /*TestSenderAppC.SendReadyPin*/Msp430GpioC__8__HplGeneralIO__makeInput();
}

# 44 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void TestSenderP__SendReadyPin__makeInput(void ){
#line 44
  /*TestSenderAppC.SendReadyPin*/Msp430GpioC__8__GeneralIO__makeInput();
#line 44
}
#line 44
# 59 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P21*/HplMsp430GeneralIORenP__9__IO__selectIOFunc(void )
#line 59
{
#line 59
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 59
    * (volatile uint8_t * )523U &= ~(0x01 << 1);
#line 59
    __nesc_atomic_end(__nesc_atomic); }
}

# 99 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void TestSenderP__HplSendReadyPin__selectIOFunc(void ){
#line 99
  /*HplMsp430GeneralIOC.P21*/HplMsp430GeneralIORenP__9__IO__selectIOFunc();
#line 99
}
#line 99
# 53 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P20*/HplMsp430GeneralIORenP__8__IO__makeInput(void )
#line 53
{
#line 53
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 53
    * (volatile uint8_t * )517U &= ~(0x01 << 0);
#line 53
    __nesc_atomic_end(__nesc_atomic); }
}

# 78 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*TestSenderAppC.NextPin*/Msp430GpioC__7__HplGeneralIO__makeInput(void ){
#line 78
  /*HplMsp430GeneralIOC.P20*/HplMsp430GeneralIORenP__8__IO__makeInput();
#line 78
}
#line 78
# 52 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*TestSenderAppC.NextPin*/Msp430GpioC__7__GeneralIO__makeInput(void )
#line 52
{
#line 52
  /*TestSenderAppC.NextPin*/Msp430GpioC__7__HplGeneralIO__makeInput();
}

# 44 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void TestSenderP__NextPin__makeInput(void ){
#line 44
  /*TestSenderAppC.NextPin*/Msp430GpioC__7__GeneralIO__makeInput();
#line 44
}
#line 44
# 190 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port20__enable(void )
#line 190
{
#line 190
  P2IE |= 1 << 0;
}

# 42 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__HplInterrupt__enable(void ){
#line 42
  HplMsp430InterruptP__Port20__enable();
#line 42
}
#line 42
# 222 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port20__edge(bool l2h)
#line 222
{
  /* atomic removed: atomic calls only */
#line 223
  {
    if (l2h) {
#line 224
      P2IES &= ~(1 << 0);
      }
    else {
#line 225
      P2IES |= 1 << 0;
      }
  }
}

# 67 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__HplInterrupt__edge(bool low_to_high){
#line 67
  HplMsp430InterruptP__Port20__edge(low_to_high);
#line 67
}
#line 67
# 206 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port20__clear(void )
#line 206
{
#line 206
  P2IFG &= ~(1 << 0);
}

# 52 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__HplInterrupt__clear(void ){
#line 52
  HplMsp430InterruptP__Port20__clear();
#line 52
}
#line 52
# 198 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port20__disable(void )
#line 198
{
#line 198
  P2IE &= ~(1 << 0);
}

# 47 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__HplInterrupt__disable(void ){
#line 47
  HplMsp430InterruptP__Port20__disable();
#line 47
}
#line 47
# 69 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430InterruptC.nc"
static inline error_t /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__Interrupt__disable(void )
#line 69
{
  /* atomic removed: atomic calls only */
#line 70
  {
    /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__HplInterrupt__disable();
    /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__HplInterrupt__clear();
  }
  return SUCCESS;
}

#line 52
static inline error_t /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__enable(bool rising)
#line 52
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 53
    {
      /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__Interrupt__disable();
      /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__HplInterrupt__edge(rising);
      /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__HplInterrupt__enable();
    }
#line 57
    __nesc_atomic_end(__nesc_atomic); }
  return SUCCESS;
}

static inline error_t /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__Interrupt__enableRisingEdge(void )
#line 61
{
  return /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__enable(TRUE);
}

# 53 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
inline static error_t TestSenderP__NextInterrupt__enableRisingEdge(void ){
#line 53
  unsigned char __nesc_result;
#line 53

#line 53
  __nesc_result = /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__Interrupt__enableRisingEdge();
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53
# 47 "TestSenderP.nc"
static inline void TestSenderP__Boot__booted(void )
#line 47
{
  TestSenderP__Leds__set(3);
  TestSenderP__NextInterrupt__enableRisingEdge();
  TestSenderP__NextPin__makeInput();

  TestSenderP__HplSendReadyPin__selectIOFunc();
  TestSenderP__SendReadyPin__makeInput();

  TestSenderP__SendPin__makeInput();
  TestSenderP__DebugPin__makeOutput();
  TestSenderP__DebugPin__clr();

  TestSenderP__SerialSplitControl__start();
}

# 60 "/opt/tinyos-2.x/tos/interfaces/Boot.nc"
inline static void RealMainP__Boot__booted(void ){
#line 60
  TestSenderP__Boot__booted();
#line 60
}
#line 60
# 282 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430XV2ClockControlP.nc"
static inline void Msp430XV2ClockControlP__McuSleepEvents__postSleep(mcu_power_t sleep_mode)
{
  if (sleep_mode >= MSP430_POWER_LPM1) {
      /* atomic removed: atomic calls only */
#line 285
      Msp430XV2ClockControlP__fllRestart_refclk = TA0R;
    }
}

# 61 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/lpm/McuSleepEvents.nc"
inline static void McuSleepP__McuSleepEvents__postSleep(mcu_power_t sleep_mode){
#line 61
  Msp430XV2ClockControlP__McuSleepEvents__postSleep(sleep_mode);
#line 61
}
#line 61
# 391 "/opt/tinyos-2.x/tos/chips/msp430/msp430hardware.h"
static inline  void __nesc_disable_interrupt(void )
{
   __asm volatile ("dint");
   __asm volatile ("nop");}

# 280 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430XV2ClockControlP.nc"
static inline void Msp430XV2ClockControlP__McuSleepEvents__preSleep(mcu_power_t sleep_mode)
#line 280
{
}

# 55 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/lpm/McuSleepEvents.nc"
inline static void McuSleepP__McuSleepEvents__preSleep(mcu_power_t sleep_mode){
#line 55
  Msp430XV2ClockControlP__McuSleepEvents__preSleep(sleep_mode);
#line 55
}
#line 55
# 260 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430XV2ClockControlP.nc"
static inline mcu_power_t Msp430XV2ClockControlP__McuPowerOverride__lowestState(void )
{
  mcu_power_t rv = MSP430_POWER_LPM4;

  if (!Msp430XV2ClockControlP__inhibitUCS7_) {
      uint16_t now_refclk;
      uint16_t fll_active_refclk;

      /* atomic removed: atomic calls only */
#line 267
      now_refclk = TA0R;
      if (now_refclk >= Msp430XV2ClockControlP__fllRestart_refclk) {
          fll_active_refclk = now_refclk - Msp430XV2ClockControlP__fllRestart_refclk;
        }
      else 
#line 270
        {
          fll_active_refclk = Msp430XV2ClockControlP__fllRestart_refclk - now_refclk;
        }
      if (Msp430XV2ClockControlP__MinimumFLLActiveDuration_refclk > fll_active_refclk) {
          rv = MSP430_POWER_LPM0;
        }
    }
  return rv;
}

# 62 "/opt/tinyos-2.x/tos/interfaces/McuPowerOverride.nc"
inline static mcu_power_t McuSleepP__McuPowerOverride__lowestState(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = Msp430XV2ClockControlP__McuPowerOverride__lowestState();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 105 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/lpm/McuSleepP.nc"
static inline void McuSleepP__McuSleep__sleep(void )
#line 105
{
  uint16_t temp;
  mcu_power_t power_state;

  power_state = McuSleepP__McuPowerOverride__lowestState();
  McuSleepP__McuSleepEvents__preSleep(power_state);
  temp = McuSleepP__msp430PowerBits[power_state] | 0x0008;
   __asm volatile ("bis  %0, r2" :  : "m"(temp));

   __asm volatile ("" :  :  : "memory");
  __nesc_disable_interrupt();
  McuSleepP__McuSleepEvents__postSleep(power_state);
}

# 76 "/opt/tinyos-2.x/tos/interfaces/McuSleep.nc"
inline static void SchedulerBasicP__McuSleep__sleep(void ){
#line 76
  McuSleepP__McuSleep__sleep();
#line 76
}
#line 76
# 78 "/opt/tinyos-2.x/tos/system/SchedulerBasicP.nc"
static __inline uint8_t SchedulerBasicP__popTask(void )
{
  if (SchedulerBasicP__m_head != SchedulerBasicP__NO_TASK) 
    {
      uint8_t id = SchedulerBasicP__m_head;

#line 83
      SchedulerBasicP__m_head = SchedulerBasicP__m_next[SchedulerBasicP__m_head];
      if (SchedulerBasicP__m_head == SchedulerBasicP__NO_TASK) 
        {
          SchedulerBasicP__m_tail = SchedulerBasicP__NO_TASK;
        }
      SchedulerBasicP__m_next[id] = SchedulerBasicP__NO_TASK;
      return id;
    }
  else 
    {
      return SchedulerBasicP__NO_TASK;
    }
}

#line 149
static inline void SchedulerBasicP__Scheduler__taskLoop(void )
{
  for (; ; ) 
    {
      uint8_t nextTask;

      { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
        {
          while ((nextTask = SchedulerBasicP__popTask()) == SchedulerBasicP__NO_TASK) 
            {
              SchedulerBasicP__McuSleep__sleep();
            }
        }
#line 161
        __nesc_atomic_end(__nesc_atomic); }
      SchedulerBasicP__TaskBasic__runTask(nextTask);
    }
}

# 72 "/opt/tinyos-2.x/tos/interfaces/Scheduler.nc"
inline static void RealMainP__Scheduler__taskLoop(void ){
#line 72
  SchedulerBasicP__Scheduler__taskLoop();
#line 72
}
#line 72
# 98 "/opt/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
inline static uint8_t HplMsp430Rf1aInterruptP__ArbiterInfo__userId(void ){
#line 98
  unsigned char __nesc_result;
#line 98

#line 98
  __nesc_result = /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ArbiterInfo__userId();
#line 98

#line 98
  return __nesc_result;
#line 98
}
#line 98
#line 90
inline static bool HplMsp430Rf1aInterruptP__ArbiterInfo__inUse(void ){
#line 90
  unsigned char __nesc_result;
#line 90

#line 90
  __nesc_result = /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ArbiterInfo__inUse();
#line 90

#line 90
  return __nesc_result;
#line 90
}
#line 90
# 1423 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__coreInterrupt(uint8_t client, uint16_t iv)
{
}

# 54 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
inline static void HplMsp430Rf1aInterruptP__Rf1aInterrupts__coreInterrupt(uint8_t arg_0x40d35d58, uint16_t iv){
#line 54
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__coreInterrupt(arg_0x40d35d58, iv);
#line 54
}
#line 54
# 1361 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__rxFifoAvailable(uint8_t client)
{
  if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__RX_S_inactive < /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_state) {




      if (
#line 1367
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__RX_S_listening == /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_state
       && 0 < /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveCountAvailable_()) {
          /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_state = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__RX_S_synchronized;
        }
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveData_task__postTask();
    }
}

# 10 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
inline static void HplMsp430Rf1aInterruptP__Rf1aInterrupts__rxFifoAvailable(uint8_t arg_0x40d35d58){
#line 10
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__rxFifoAvailable(arg_0x40d35d58);
#line 10
}
#line 10
# 1375 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__txFifoAvailable(uint8_t client)
{
  if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__TX_S_inactive != /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_state) {
      uint8_t txbytes = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(0x3A);









      if (0x3F <= (0x7F & txbytes)) {
          /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_result = ECANCEL;
        }
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__sendFragment_task__postTask();
    }
}

# 16 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
inline static void HplMsp430Rf1aInterruptP__Rf1aInterrupts__txFifoAvailable(uint8_t arg_0x40d35d58){
#line 16
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__txFifoAvailable(arg_0x40d35d58);
#line 16
}
#line 16
# 1394 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__rxOverflow(uint8_t client)
{
  /* atomic removed: atomic calls only */
#line 1396
  {
    /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_result = ECANCEL;
    /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveData_task__postTask();
  }
}

# 23 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
inline static void HplMsp430Rf1aInterruptP__Rf1aInterrupts__rxOverflow(uint8_t arg_0x40d35d58){
#line 23
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__rxOverflow(arg_0x40d35d58);
#line 23
}
#line 23
# 1401 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__txUnderflow(uint8_t client)
{
  /* atomic removed: atomic calls only */
#line 1403
  {
    /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_result = FAIL;
    /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__sendFragment_task__postTask();
  }
}

# 29 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
inline static void HplMsp430Rf1aInterruptP__Rf1aInterrupts__txUnderflow(uint8_t arg_0x40d35d58){
#line 29
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__txUnderflow(arg_0x40d35d58);
#line 29
}
#line 29
# 396 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__frameStarted(void )
#line 396
{
}

# 1436 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__frameStarted(uint8_t client)
#line 1436
{
}

# 282 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__frameStarted(uint8_t arg_0x40c74aa8){
#line 282
  switch (arg_0x40c74aa8) {
#line 282
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT:
#line 282
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__frameStarted();
#line 282
      break;
#line 282
    default:
#line 282
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__frameStarted(arg_0x40c74aa8);
#line 282
      break;
#line 282
    }
#line 282
}
#line 282
# 1408 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__syncWordEvent(uint8_t client)
{
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__frameStarted(/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ArbiterInfo__userId());
}

# 36 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
inline static void HplMsp430Rf1aInterruptP__Rf1aInterrupts__syncWordEvent(uint8_t arg_0x40d35d58){
#line 36
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__syncWordEvent(arg_0x40d35d58);
#line 36
}
#line 36
# 397 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__clearChannel(void )
#line 397
{
}

# 1437 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__clearChannel(uint8_t client)
#line 1437
{
}

# 289 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__clearChannel(uint8_t arg_0x40c74aa8){
#line 289
  switch (arg_0x40c74aa8) {
#line 289
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT:
#line 289
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__clearChannel();
#line 289
      break;
#line 289
    default:
#line 289
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__clearChannel(arg_0x40c74aa8);
#line 289
      break;
#line 289
    }
#line 289
}
#line 289
# 1413 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__clearChannel(uint8_t client)
{
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__clearChannel(/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ArbiterInfo__userId());
}

# 44 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
inline static void HplMsp430Rf1aInterruptP__Rf1aInterrupts__clearChannel(uint8_t arg_0x40d35d58){
#line 44
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__clearChannel(arg_0x40d35d58);
#line 44
}
#line 44
# 398 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
static inline void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__carrierSense(void )
#line 398
{
}

# 1438 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__carrierSense(uint8_t client)
#line 1438
{
}

# 298 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aPhysical.nc"
inline static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__carrierSense(uint8_t arg_0x40c74aa8){
#line 298
  switch (arg_0x40c74aa8) {
#line 298
    case /*Rf1aActiveMessageC.PhysicalC*/Rf1aMultiPhysicalC__0__CLIENT:
#line 298
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__carrierSense();
#line 298
      break;
#line 298
    default:
#line 298
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__default__carrierSense(arg_0x40c74aa8);
#line 298
      break;
#line 298
    }
#line 298
}
#line 298
# 1418 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static inline void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__carrierSense(uint8_t client)
{
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__carrierSense(/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__ArbiterInfo__userId());
}

# 51 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aInterrupts.nc"
inline static void HplMsp430Rf1aInterruptP__Rf1aInterrupts__carrierSense(uint8_t arg_0x40d35d58){
#line 51
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aInterrupts__carrierSense(arg_0x40d35d58);
#line 51
}
#line 51
# 102 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port10__clear(void )
#line 102
{
#line 102
  P1IFG &= ~(1 << 0);
}

#line 78
static inline void HplMsp430InterruptP__Port10__default__fired(void )
#line 78
{
#line 78
  HplMsp430InterruptP__Port10__clear();
}

# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void HplMsp430InterruptP__Port10__fired(void ){
#line 72
  HplMsp430InterruptP__Port10__default__fired();
#line 72
}
#line 72
# 103 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port11__clear(void )
#line 103
{
#line 103
  P1IFG &= ~(1 << 1);
}

#line 79
static inline void HplMsp430InterruptP__Port11__default__fired(void )
#line 79
{
#line 79
  HplMsp430InterruptP__Port11__clear();
}

# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void HplMsp430InterruptP__Port11__fired(void ){
#line 72
  HplMsp430InterruptP__Port11__default__fired();
#line 72
}
#line 72
# 104 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port12__clear(void )
#line 104
{
#line 104
  P1IFG &= ~(1 << 2);
}

#line 80
static inline void HplMsp430InterruptP__Port12__default__fired(void )
#line 80
{
#line 80
  HplMsp430InterruptP__Port12__clear();
}

# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void HplMsp430InterruptP__Port12__fired(void ){
#line 72
  HplMsp430InterruptP__Port12__default__fired();
#line 72
}
#line 72
# 105 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port13__clear(void )
#line 105
{
#line 105
  P1IFG &= ~(1 << 3);
}

#line 81
static inline void HplMsp430InterruptP__Port13__default__fired(void )
#line 81
{
#line 81
  HplMsp430InterruptP__Port13__clear();
}

# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void HplMsp430InterruptP__Port13__fired(void ){
#line 72
  HplMsp430InterruptP__Port13__default__fired();
#line 72
}
#line 72
# 106 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port14__clear(void )
#line 106
{
#line 106
  P1IFG &= ~(1 << 4);
}

#line 82
static inline void HplMsp430InterruptP__Port14__default__fired(void )
#line 82
{
#line 82
  HplMsp430InterruptP__Port14__clear();
}

# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void HplMsp430InterruptP__Port14__fired(void ){
#line 72
  HplMsp430InterruptP__Port14__default__fired();
#line 72
}
#line 72
# 107 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port15__clear(void )
#line 107
{
#line 107
  P1IFG &= ~(1 << 5);
}

#line 83
static inline void HplMsp430InterruptP__Port15__default__fired(void )
#line 83
{
#line 83
  HplMsp430InterruptP__Port15__clear();
}

# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void HplMsp430InterruptP__Port15__fired(void ){
#line 72
  HplMsp430InterruptP__Port15__default__fired();
#line 72
}
#line 72
# 108 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port16__clear(void )
#line 108
{
#line 108
  P1IFG &= ~(1 << 6);
}

#line 84
static inline void HplMsp430InterruptP__Port16__default__fired(void )
#line 84
{
#line 84
  HplMsp430InterruptP__Port16__clear();
}

# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void HplMsp430InterruptP__Port16__fired(void ){
#line 72
  HplMsp430InterruptP__Port16__default__fired();
#line 72
}
#line 72
# 109 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port17__clear(void )
#line 109
{
#line 109
  P1IFG &= ~(1 << 7);
}

#line 85
static inline void HplMsp430InterruptP__Port17__default__fired(void )
#line 85
{
#line 85
  HplMsp430InterruptP__Port17__clear();
}

# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void HplMsp430InterruptP__Port17__fired(void ){
#line 72
  HplMsp430InterruptP__Port17__default__fired();
#line 72
}
#line 72
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t TestSenderP__tryNextConfigTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(TestSenderP__tryNextConfigTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
inline static error_t TestSenderP__reportNI__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(TestSenderP__reportNI);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 91 "TestSenderP.nc"
static inline void TestSenderP__NextInterrupt__fired(void )
#line 91
{
  TestSenderP__reportNI__postTask();
  TestSenderP__tryNextConfigTask__postTask();
}

# 68 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
inline static void /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__Interrupt__fired(void ){
#line 68
  TestSenderP__NextInterrupt__fired();
#line 68
}
#line 68
# 77 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430InterruptC.nc"
static inline void /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__HplInterrupt__fired(void )
#line 77
{
  /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__HplInterrupt__clear();
  /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__Interrupt__fired();
}

# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void HplMsp430InterruptP__Port20__fired(void ){
#line 72
  /*TestSenderAppC.NextInterrupt*/Msp430InterruptC__0__HplInterrupt__fired();
#line 72
}
#line 72
# 207 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port21__clear(void )
#line 207
{
#line 207
  P2IFG &= ~(1 << 1);
}

# 52 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__HplInterrupt__clear(void ){
#line 52
  HplMsp430InterruptP__Port21__clear();
#line 52
}
#line 52
# 199 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port21__disable(void )
#line 199
{
#line 199
  P2IE &= ~(1 << 1);
}

# 47 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__HplInterrupt__disable(void ){
#line 47
  HplMsp430InterruptP__Port21__disable();
#line 47
}
#line 47
# 69 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430InterruptC.nc"
static inline error_t /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__Interrupt__disable(void )
#line 69
{
  /* atomic removed: atomic calls only */
#line 70
  {
    /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__HplInterrupt__disable();
    /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__HplInterrupt__clear();
  }
  return SUCCESS;
}

# 61 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
inline static error_t TestSenderP__SendReadyInterrupt__disable(void ){
#line 61
  unsigned char __nesc_result;
#line 61

#line 61
  __nesc_result = /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__Interrupt__disable();
#line 61

#line 61
  return __nesc_result;
#line 61
}
#line 61
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t TestSenderP__loadNextTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(TestSenderP__loadNextTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
inline static error_t TestSenderP__reportSRI__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(TestSenderP__reportSRI);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 48 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P24*/HplMsp430GeneralIORenP__12__IO__set(void )
#line 48
{
  /* atomic removed: atomic calls only */
#line 48
  * (volatile uint8_t * )515U |= 0x01 << 4;
}

# 48 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*TestSenderAppC.DebugPin*/Msp430GpioC__10__HplGeneralIO__set(void ){
#line 48
  /*HplMsp430GeneralIOC.P24*/HplMsp430GeneralIORenP__12__IO__set();
#line 48
}
#line 48
# 48 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430GpioC.nc"
static inline void /*TestSenderAppC.DebugPin*/Msp430GpioC__10__GeneralIO__set(void )
#line 48
{
#line 48
  /*TestSenderAppC.DebugPin*/Msp430GpioC__10__HplGeneralIO__set();
}

# 40 "/opt/tinyos-2.x/tos/interfaces/GeneralIO.nc"
inline static void TestSenderP__DebugPin__set(void ){
#line 40
  /*TestSenderAppC.DebugPin*/Msp430GpioC__10__GeneralIO__set();
#line 40
}
#line 40
# 181 "TestSenderP.nc"
static inline void TestSenderP__SendReadyInterrupt__fired(void )
#line 181
{
  TestSenderP__DebugPin__set();
  TestSenderP__reportSRI__postTask();
  TestSenderP__Leds__set(2);
  if (TestSenderP__state == TestSenderP__S_NEED_LOAD) {
      TestSenderP__loadNextTask__postTask();
      TestSenderP__SendReadyInterrupt__disable();
    }
  else 
#line 188
    {
      TestSenderP__state = TestSenderP__S_ERROR;
    }
}

# 68 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
inline static void /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__Interrupt__fired(void ){
#line 68
  TestSenderP__SendReadyInterrupt__fired();
#line 68
}
#line 68
# 77 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430InterruptC.nc"
static inline void /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__HplInterrupt__fired(void )
#line 77
{
  /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__HplInterrupt__clear();
  /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__Interrupt__fired();
}

# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void HplMsp430InterruptP__Port21__fired(void ){
#line 72
  /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__HplInterrupt__fired();
#line 72
}
#line 72
# 67 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t TestSenderP__reportSI__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(TestSenderP__reportSI);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 61 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
inline static error_t TestSenderP__SendInterrupt__disable(void ){
#line 61
  unsigned char __nesc_result;
#line 61

#line 61
  __nesc_result = /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__Interrupt__disable();
#line 61

#line 61
  return __nesc_result;
#line 61
}
#line 61
# 193 "TestSenderP.nc"
static inline void TestSenderP__SendInterrupt__fired(void )
#line 193
{


  TestSenderP__SendInterrupt__disable();
  if (TestSenderP__state == TestSenderP__S_LOADED) {
      TestSenderP__state = TestSenderP__S_SENDING;
      TestSenderP__DelayedSendRf1aPhysical__completeSend();
    }
  else 
#line 200
    {
      TestSenderP__state = TestSenderP__S_ERROR;
    }
  TestSenderP__reportSI__postTask();
  TestSenderP__Leds__set(3);
}

# 68 "/opt/tinyos-2.x/tos/interfaces/GpioInterrupt.nc"
inline static void /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__Interrupt__fired(void ){
#line 68
  TestSenderP__SendInterrupt__fired();
#line 68
}
#line 68
# 77 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430InterruptC.nc"
static inline void /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__HplInterrupt__fired(void )
#line 77
{
  /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__HplInterrupt__clear();
  /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__Interrupt__fired();
}

# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void HplMsp430InterruptP__Port22__fired(void ){
#line 72
  /*TestSenderAppC.SendInterrupt*/Msp430InterruptC__2__HplInterrupt__fired();
#line 72
}
#line 72
# 209 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port23__clear(void )
#line 209
{
#line 209
  P2IFG &= ~(1 << 3);
}

#line 185
static inline void HplMsp430InterruptP__Port23__default__fired(void )
#line 185
{
#line 185
  HplMsp430InterruptP__Port23__clear();
}

# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void HplMsp430InterruptP__Port23__fired(void ){
#line 72
  HplMsp430InterruptP__Port23__default__fired();
#line 72
}
#line 72
# 210 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port24__clear(void )
#line 210
{
#line 210
  P2IFG &= ~(1 << 4);
}

#line 186
static inline void HplMsp430InterruptP__Port24__default__fired(void )
#line 186
{
#line 186
  HplMsp430InterruptP__Port24__clear();
}

# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void HplMsp430InterruptP__Port24__fired(void ){
#line 72
  HplMsp430InterruptP__Port24__default__fired();
#line 72
}
#line 72
# 211 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port25__clear(void )
#line 211
{
#line 211
  P2IFG &= ~(1 << 5);
}

#line 187
static inline void HplMsp430InterruptP__Port25__default__fired(void )
#line 187
{
#line 187
  HplMsp430InterruptP__Port25__clear();
}

# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void HplMsp430InterruptP__Port25__fired(void ){
#line 72
  HplMsp430InterruptP__Port25__default__fired();
#line 72
}
#line 72
# 212 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port26__clear(void )
#line 212
{
#line 212
  P2IFG &= ~(1 << 6);
}

#line 188
static inline void HplMsp430InterruptP__Port26__default__fired(void )
#line 188
{
#line 188
  HplMsp430InterruptP__Port26__clear();
}

# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void HplMsp430InterruptP__Port26__fired(void ){
#line 72
  HplMsp430InterruptP__Port26__default__fired();
#line 72
}
#line 72
# 213 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
static inline void HplMsp430InterruptP__Port27__clear(void )
#line 213
{
#line 213
  P2IFG &= ~(1 << 7);
}

#line 189
static inline void HplMsp430InterruptP__Port27__default__fired(void )
#line 189
{
#line 189
  HplMsp430InterruptP__Port27__clear();
}

# 72 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430Interrupt.nc"
inline static void HplMsp430InterruptP__Port27__fired(void ){
#line 72
  HplMsp430InterruptP__Port27__default__fired();
#line 72
}
#line 72
# 411 "/opt/tinyos-2.x/tos/chips/msp430/msp430hardware.h"
  __nesc_atomic_t __nesc_atomic_start(void )
{
  __nesc_atomic_t result = (({
#line 413
    uint16_t __x;

#line 413
     __asm volatile ("mov	r2, %0" : "=r"((uint16_t )__x));__x;
  }
  )
#line 413
   & 0x0008) != 0;

#line 414
  __nesc_disable_interrupt();
   __asm volatile ("" :  :  : "memory");
  return result;
}

  void __nesc_atomic_end(__nesc_atomic_t reenable_interrupts)
{
   __asm volatile ("" :  :  : "memory");
  if (reenable_interrupts) {
    __nesc_enable_interrupt();
    }
}

# 17 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterruptsA0P.nc"
__attribute((wakeup)) __attribute((interrupt(0x74)))  void sig_USCI_A0_VECTOR(void )
#line 17
{
  HplMsp430UsciInterruptsA0P__Interrupts__interrupted(HplMsp430UsciInterruptsA0P__Usci__getIv());
}

# 166 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
static uint8_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ArbiterInfo__userId(void )
#line 166
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 167
    {
      if (/*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__state != /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__RES_BUSY) 
        {
          unsigned char __nesc_temp = 
#line 169
          /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__NO_RES;

          {
#line 169
            __nesc_atomic_end(__nesc_atomic); 
#line 169
            return __nesc_temp;
          }
        }
#line 170
      {
        unsigned char __nesc_temp = 
#line 170
        /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__resId;

        {
#line 170
          __nesc_atomic_end(__nesc_atomic); 
#line 170
          return __nesc_temp;
        }
      }
    }
#line 173
    __nesc_atomic_end(__nesc_atomic); }
}

# 412 "/opt/tinyos-2.x/tos/lib/serial/SerialP.nc"
static void SerialP__rx_state_machine(bool isDelimeter, uint8_t data)
#line 412
{

  switch (SerialP__rxState) {

      case SerialP__RXSTATE_NOSYNC: 
        if (isDelimeter) {
            SerialP__rxInit();
            SerialP__rxState = SerialP__RXSTATE_PROTO;
          }
      break;

      case SerialP__RXSTATE_PROTO: 
        if (!isDelimeter) {
            SerialP__rxCRC = crcByte(SerialP__rxCRC, data);
            SerialP__rxState = SerialP__RXSTATE_TOKEN;
            SerialP__rxProto = data;
            if (!SerialP__valid_rx_proto(SerialP__rxProto)) {
              goto nosync;
              }
            if (SerialP__rxProto != SERIAL_PROTO_PACKET_ACK) {
                goto nosync;
              }
            if (SerialP__ReceiveBytePacket__startPacket() != SUCCESS) {
                goto nosync;
              }
          }
      break;

      case SerialP__RXSTATE_TOKEN: 
        if (isDelimeter) {
            goto nosync;
          }
        else {
            SerialP__rxSeqno = data;
            SerialP__rxCRC = crcByte(SerialP__rxCRC, SerialP__rxSeqno);
            SerialP__rxState = SerialP__RXSTATE_INFO;
          }
      break;

      case SerialP__RXSTATE_INFO: 
        if (SerialP__rxByteCnt < SerialP__SERIAL_MTU) {
            if (isDelimeter) {
                if (SerialP__rxByteCnt >= 2) {
                    if (SerialP__rx_current_crc() == SerialP__rxCRC) {
                        SerialP__ReceiveBytePacket__endPacket(SUCCESS);
                        SerialP__ack_queue_push(SerialP__rxSeqno);
                        SerialP__rxInit();
                        SerialP__SerialFrameComm__resetReceive();
                        if (SerialP__offPending) {
                            SerialP__rxState = SerialP__RXSTATE_INACTIVE;
                            SerialP__testOff();
                          }
                        goto done;
                      }
                    else {
                        goto nosync;
                      }
                  }
                else {
                    goto nosync;
                  }
              }
            else {
                if (SerialP__rxByteCnt >= 2) {
                    SerialP__ReceiveBytePacket__byteReceived(SerialP__rx_buffer_top());
                    SerialP__rxCRC = crcByte(SerialP__rxCRC, SerialP__rx_buffer_pop());
                  }
                SerialP__rx_buffer_push(data);
                SerialP__rxByteCnt++;
              }
          }
        else 

          {
            goto nosync;
          }
      break;

      default: 
        goto nosync;
    }
  goto done;

  nosync: 

    SerialP__rxInit();
  SerialP__SerialFrameComm__resetReceive();
  SerialP__ReceiveBytePacket__endPacket(FAIL);
  if (SerialP__offPending) {
      SerialP__rxState = SerialP__RXSTATE_INACTIVE;
      SerialP__testOff();
    }
  else {
    if (isDelimeter) {
        SerialP__rxState = SerialP__RXSTATE_PROTO;
      }
    }
  done: ;
}

# 91 "/opt/tinyos-2.x/tos/system/crc.h"
static uint16_t crcByte(uint16_t crc, uint8_t b)
#line 91
{
  crc = (uint8_t )(crc >> 8) | (crc << 8);
  crc ^= b;
  crc ^= (uint8_t )(crc & 0xff) >> 4;
  crc ^= crc << 12;
  crc ^= (crc & 0xff) << 5;
  return crc;
}

# 296 "/opt/tinyos-2.x/tos/lib/serial/SerialDispatcherP.nc"
static void /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__ReceiveBytePacket__endPacket(error_t result)
#line 296
{
  uint8_t postsignalreceive = FALSE;

  /* atomic removed: atomic calls only */
#line 298
  {
    if (!/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTaskPending && result == SUCCESS) {
        postsignalreceive = TRUE;
        /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTaskPending = TRUE;
        /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTaskType = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__recvType;
        /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTaskWhich = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveState.which;
        /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTaskBuf = (message_t *)/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveBuffer;
        /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTaskSize = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__recvIndex;
        /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveBufferSwap();
        /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveState.state = /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__RECV_STATE_IDLE;
      }
    else 
#line 308
      {

        /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__unlockBuffer(/*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveState.which);
      }
  }
  if (postsignalreceive) {
      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTask__postTask();
    }
}

# 170 "/opt/tinyos-2.x/tos/system/SchedulerBasicP.nc"
static error_t SchedulerBasicP__TaskBasic__postTask(uint8_t id)
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 172
    {
#line 172
      {
        unsigned char __nesc_temp = 
#line 172
        SchedulerBasicP__pushTask(id) ? SUCCESS : EBUSY;

        {
#line 172
          __nesc_atomic_end(__nesc_atomic); 
#line 172
          return __nesc_temp;
        }
      }
    }
#line 175
    __nesc_atomic_end(__nesc_atomic); }
}

# 518 "/opt/tinyos-2.x/tos/lib/serial/SerialP.nc"
static void SerialP__MaybeScheduleTx(void )
#line 518
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 519
    {
      if (SerialP__txPending == 0) {
          if (SerialP__RunTx__postTask() == SUCCESS) {
              SerialP__txPending = 1;
            }
        }
    }
#line 525
    __nesc_atomic_end(__nesc_atomic); }
}

#line 357
static void SerialP__testOff(void )
#line 357
{
  bool turnOff = FALSE;

  /* atomic removed: atomic calls only */
#line 359
  {
    if (SerialP__txState == SerialP__TXSTATE_INACTIVE && 
    SerialP__rxState == SerialP__RXSTATE_INACTIVE) {
        turnOff = TRUE;
      }
  }
  if (turnOff) {
      SerialP__stopDoneTask__postTask();
      /* atomic removed: atomic calls only */
#line 367
      SerialP__offPending = FALSE;
    }
  else {
      /* atomic removed: atomic calls only */
#line 370
      SerialP__offPending = TRUE;
    }
}

# 205 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
static error_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UartStream__send(uint8_t client, uint8_t *buf, uint16_t len)
{
  error_t rv = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__checkIsOwner(client);

#line 208
  if (SUCCESS != rv) {
      return rv;
    }
  if (/*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__isBusy()) {
      return EBUSY;
    }
  if (0 == len || 0 == buf) {
      return FAIL;
    }
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_tx_buf = buf;
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_tx_len = len;
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_tx_pos = 0;


  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__setIe(/*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__getIe() | 0x0002);

  return SUCCESS;
}

# 106 "/opt/tinyos-2.x/tos/lib/serial/HdlcTranslateC.nc"
static error_t HdlcTranslateC__SerialFrameComm__putData(uint8_t data)
#line 106
{
  if (data == HDLC_CTLESC_BYTE || data == HDLC_FLAG_BYTE) {
      HdlcTranslateC__state.sendEscape = 1;
      HdlcTranslateC__txTemp = data ^ 0x20;
      HdlcTranslateC__m_data = HDLC_CTLESC_BYTE;
    }
  else {
      HdlcTranslateC__m_data = data;
    }
  return HdlcTranslateC__UartStream__send(&HdlcTranslateC__m_data, 1);
}

#line 98
static error_t HdlcTranslateC__SerialFrameComm__putDelimiter(void )
#line 98
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 99
    {
      HdlcTranslateC__state.sendEscape = 0;
      HdlcTranslateC__m_data = HDLC_FLAG_BYTE;
    }
#line 102
    __nesc_atomic_end(__nesc_atomic); }
  return HdlcTranslateC__UartStream__send(&HdlcTranslateC__m_data, 1);
}

# 30 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430TimerCommonP.nc"
__attribute((wakeup)) __attribute((interrupt(0x6e)))  void sig_TIMER0_A0_VECTOR(void )
#line 30
{
#line 30
  Msp430TimerCommonP__VectorTimer0_A0__fired();
}

# 146 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static void /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Event__default__fired(uint8_t n)
{
}

# 39 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Event__fired(uint8_t arg_0x4080e458){
#line 39
  switch (arg_0x4080e458) {
#line 39
    case 0:
#line 39
      /*Msp430TimerC.Msp430Timer0_A0*/Msp430TimerCapComP__0__Event__fired();
#line 39
      break;
#line 39
    case 1:
#line 39
      /*Msp430TimerC.Msp430Timer0_A1*/Msp430TimerCapComP__1__Event__fired();
#line 39
      break;
#line 39
    case 2:
#line 39
      /*Msp430TimerC.Msp430Timer0_A2*/Msp430TimerCapComP__2__Event__fired();
#line 39
      break;
#line 39
    case 3:
#line 39
      /*Msp430TimerC.Msp430Timer0_A3*/Msp430TimerCapComP__3__Event__fired();
#line 39
      break;
#line 39
    case 4:
#line 39
      /*Msp430TimerC.Msp430Timer0_A4*/Msp430TimerCapComP__4__Event__fired();
#line 39
      break;
#line 39
    case 7:
#line 39
      /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Overflow__fired();
#line 39
      break;
#line 39
    default:
#line 39
      /*Msp430TimerC.Msp430Timer0_A*/Msp430TimerP__0__Event__default__fired(arg_0x4080e458);
#line 39
      break;
#line 39
    }
#line 39
}
#line 39
# 107 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__set_alarm(void )
{
  /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type now = /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Counter__get();
#line 109
  /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type expires;
#line 109
  /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type remaining;




  expires = /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__m_t0 + /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__m_dt;


  remaining = (/*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type )(expires - now);


  if (/*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__m_t0 <= now) 
    {
      if (expires >= /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__m_t0 && 
      expires <= now) {
        remaining = 0;
        }
    }
  else {
      if (expires >= /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__m_t0 || 
      expires <= now) {
        remaining = 0;
        }
    }
#line 132
  if (remaining > /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__MAX_DELAY) 
    {
      /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__m_t0 = now + /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__MAX_DELAY;
      /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__m_dt = remaining - /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__MAX_DELAY;
      remaining = /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__MAX_DELAY;
    }
  else 
    {
      /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__m_t0 += /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__m_dt;
      /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__m_dt = 0;
    }
  /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__startAt((/*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__from_size_type )now << 5, 
  (/*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__from_size_type )remaining << 5);
}

# 80 "/opt/tinyos-2.x/tos/lib/timer/TransformCounterC.nc"
static /*CounterMilli32C.Transform*/TransformCounterC__0__to_size_type /*CounterMilli32C.Transform*/TransformCounterC__0__Counter__get(void )
{
  /*CounterMilli32C.Transform*/TransformCounterC__0__to_size_type rv = 0;

#line 83
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      /*CounterMilli32C.Transform*/TransformCounterC__0__upper_count_type high = /*CounterMilli32C.Transform*/TransformCounterC__0__m_upper;
      /*CounterMilli32C.Transform*/TransformCounterC__0__from_size_type low = /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__get();

#line 87
      if (/*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__isOverflowPending()) 
        {






          high++;
          low = /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__get();
        }
      {
        /*CounterMilli32C.Transform*/TransformCounterC__0__to_size_type high_to = high;
        /*CounterMilli32C.Transform*/TransformCounterC__0__to_size_type low_to = low >> /*CounterMilli32C.Transform*/TransformCounterC__0__LOW_SHIFT_RIGHT;

#line 101
        rv = (high_to << /*CounterMilli32C.Transform*/TransformCounterC__0__HIGH_SHIFT_LEFT) | low_to;
      }
    }
#line 103
    __nesc_atomic_end(__nesc_atomic); }
  return rv;
}

# 31 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430TimerCommonP.nc"
__attribute((wakeup)) __attribute((interrupt(0x6c)))  void sig_TIMER0_A1_VECTOR(void )
#line 31
{
#line 31
  Msp430TimerCommonP__VectorTimer0_A1__fired();
}







__attribute((wakeup)) __attribute((interrupt(0x66)))  void sig_TIMER1_A0_VECTOR(void )
#line 40
{
#line 40
  Msp430TimerCommonP__VectorTimer1_A0__fired();
}

# 180 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static void /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Event__fired(void )
{
  if (/*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Control__getControl().cap) {
    /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Capture__captured(/*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Capture__getEvent());
    }
  else {
#line 185
    /*Msp430TimerC.Msp430Timer1_A0*/Msp430TimerCapComP__5__Compare__fired();
    }
}

#line 180
static void /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Event__fired(void )
{
  if (/*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Control__getControl().cap) {
    /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Capture__captured(/*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Capture__getEvent());
    }
  else {
#line 185
    /*Msp430TimerC.Msp430Timer1_A1*/Msp430TimerCapComP__6__Compare__fired();
    }
}

#line 180
static void /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Event__fired(void )
{
  if (/*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Control__getControl().cap) {
    /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Capture__captured(/*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Capture__getEvent());
    }
  else {
#line 185
    /*Msp430TimerC.Msp430Timer1_A2*/Msp430TimerCapComP__7__Compare__fired();
    }
}

# 41 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/timer/Msp430TimerCommonP.nc"
__attribute((wakeup)) __attribute((interrupt(0x64)))  void sig_TIMER1_A1_VECTOR(void )
#line 41
{
#line 41
  Msp430TimerCommonP__VectorTimer1_A1__fired();
}

# 19 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterruptsB0P.nc"
__attribute((wakeup)) __attribute((interrupt(0x72)))  void sig_USCI_B0_VECTOR(void )
#line 19
{
  HplMsp430UsciInterruptsB0P__Interrupts__interrupted(HplMsp430UsciInterruptsB0P__Usci__getIv());
}

# 153 "/opt/tinyos-2.x/tos/system/ArbiterP.nc"
static bool /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__ArbiterInfo__inUse(void )
#line 153
{
  /* atomic removed: atomic calls only */
#line 154
  {
    if (/*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__state == /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__RES_CONTROLLED) 
      {
        unsigned char __nesc_temp = 
#line 156
        FALSE;

#line 156
        return __nesc_temp;
      }
  }
#line 158
  return TRUE;
}

# 63 "/opt/tinyos-2.x/tos/system/RealMainP.nc"
  int main(void )
#line 63
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {





      {
      }
#line 71
      ;

      RealMainP__Scheduler__init();





      RealMainP__PlatformInit__init();
      while (RealMainP__Scheduler__runNextTask()) ;





      RealMainP__SoftwareInit__init();
      while (RealMainP__Scheduler__runNextTask()) ;
    }
#line 88
    __nesc_atomic_end(__nesc_atomic); }


  __nesc_enable_interrupt();

  RealMainP__Boot__booted();


  RealMainP__Scheduler__taskLoop();




  return -1;
}

# 49 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static void /*HplMsp430GeneralIOC.P37*/HplMsp430GeneralIORenP__23__IO__clr(void )
#line 49
{
#line 49
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 49
    * (volatile uint8_t * )546U &= ~(0x01 << 7);
#line 49
    __nesc_atomic_end(__nesc_atomic); }
}

#line 48
static void /*HplMsp430GeneralIOC.P37*/HplMsp430GeneralIORenP__23__IO__set(void )
#line 48
{
#line 48
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 48
    * (volatile uint8_t * )546U |= 0x01 << 7;
#line 48
    __nesc_atomic_end(__nesc_atomic); }
}

# 134 "/opt/tinyos-2.x/tos/system/SchedulerBasicP.nc"
static bool SchedulerBasicP__Scheduler__runNextTask(void )
{
  uint8_t nextTask;

  /* atomic removed: atomic calls only */
#line 138
  {
    nextTask = SchedulerBasicP__popTask();
    if (nextTask == SchedulerBasicP__NO_TASK) 
      {
        {
          unsigned char __nesc_temp = 
#line 142
          FALSE;

#line 142
          return __nesc_temp;
        }
      }
  }
#line 145
  SchedulerBasicP__TaskBasic__runTask(nextTask);
  return TRUE;
}

#line 175
static void SchedulerBasicP__TaskBasic__default__runTask(uint8_t id)
{
}

# 75 "/opt/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void SchedulerBasicP__TaskBasic__runTask(uint8_t arg_0x40467088){
#line 75
  switch (arg_0x40467088) {
#line 75
    case TestSenderP__tryNextConfigTask:
#line 75
      TestSenderP__tryNextConfigTask__runTask();
#line 75
      break;
#line 75
    case TestSenderP__nextConfigTask:
#line 75
      TestSenderP__nextConfigTask__runTask();
#line 75
      break;
#line 75
    case TestSenderP__loadNextTask:
#line 75
      TestSenderP__loadNextTask__runTask();
#line 75
      break;
#line 75
    case TestSenderP__reportNI:
#line 75
      TestSenderP__reportNI__runTask();
#line 75
      break;
#line 75
    case TestSenderP__reportSRI:
#line 75
      TestSenderP__reportSRI__runTask();
#line 75
      break;
#line 75
    case TestSenderP__reportSI:
#line 75
      TestSenderP__reportSI__runTask();
#line 75
      break;
#line 75
    case TestSenderP__reportRserr:
#line 75
      TestSenderP__reportRserr__runTask();
#line 75
      break;
#line 75
    case TestSenderP__reportTask:
#line 75
      TestSenderP__reportTask__runTask();
#line 75
      break;
#line 75
    case TestSenderP__reportDSSR:
#line 75
      TestSenderP__reportDSSR__runTask();
#line 75
      break;
#line 75
    case /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__grantedTask:
#line 75
      /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__grantedTask__runTask();
#line 75
      break;
#line 75
    case /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired:
#line 75
      /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__runTask();
#line 75
      break;
#line 75
    case /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer:
#line 75
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__runTask();
#line 75
      break;
#line 75
    case /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__grantedTask:
#line 75
      /*Msp430UsciB0P.UsciC.ArbiterC.Arbiter*/ArbiterP__1__grantedTask__runTask();
#line 75
      break;
#line 75
    case PlatformBusPowerP__startDoneTask:
#line 75
      PlatformBusPowerP__startDoneTask__runTask();
#line 75
      break;
#line 75
    case PlatformBusPowerP__stopDoneTask:
#line 75
      PlatformBusPowerP__stopDoneTask__runTask();
#line 75
      break;
#line 75
    case BusPowerC__clearStartFlags:
#line 75
      BusPowerC__clearStartFlags__runTask();
#line 75
      break;
#line 75
    case BusPowerC__subStartTask:
#line 75
      BusPowerC__subStartTask__runTask();
#line 75
      break;
#line 75
    case BusPowerC__clearStopFlags:
#line 75
      BusPowerC__clearStopFlags__runTask();
#line 75
      break;
#line 75
    case BusPowerC__subStopTask:
#line 75
      BusPowerC__subStopTask__runTask();
#line 75
      break;
#line 75
    case PlatformBatteryVoltageP__startDoneTask:
#line 75
      PlatformBatteryVoltageP__startDoneTask__runTask();
#line 75
      break;
#line 75
    case PlatformBatteryVoltageP__stopDoneTask:
#line 75
      PlatformBatteryVoltageP__stopDoneTask__runTask();
#line 75
      break;
#line 75
    case /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__CancelTask:
#line 75
      /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__CancelTask__runTask();
#line 75
      break;
#line 75
    case /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask:
#line 75
      /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask__runTask();
#line 75
      break;
#line 75
    case /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__grantedTask:
#line 75
      /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__grantedTask__runTask();
#line 75
      break;
#line 75
    case /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__sendFragment_task:
#line 75
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__sendFragment_task__runTask();
#line 75
      break;
#line 75
    case /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveData_task:
#line 75
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveData_task__runTask();
#line 75
      break;
#line 75
    case /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__stopDone_task:
#line 75
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__stopDone_task__runTask();
#line 75
      break;
#line 75
    case /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__sendDone_task:
#line 75
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__sendDone_task__runTask();
#line 75
      break;
#line 75
    case /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__receiveDone_task:
#line 75
      /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__receiveDone_task__runTask();
#line 75
      break;
#line 75
    case /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ackWaitAlarmFired_task:
#line 75
      /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__ackWaitAlarmFired_task__runTask();
#line 75
      break;
#line 75
    case SerialP__RunTx:
#line 75
      SerialP__RunTx__runTask();
#line 75
      break;
#line 75
    case SerialP__startDoneTask:
#line 75
      SerialP__startDoneTask__runTask();
#line 75
      break;
#line 75
    case SerialP__stopDoneTask:
#line 75
      SerialP__stopDoneTask__runTask();
#line 75
      break;
#line 75
    case SerialP__defaultSerialFlushTask:
#line 75
      SerialP__defaultSerialFlushTask__runTask();
#line 75
      break;
#line 75
    case /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__signalSendDone:
#line 75
      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__signalSendDone__runTask();
#line 75
      break;
#line 75
    case /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTask:
#line 75
      /*SerialDispatcherC.SerialDispatcherP*/SerialDispatcherP__0__receiveTask__runTask();
#line 75
      break;
#line 75
    case /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__CancelTask:
#line 75
      /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__CancelTask__runTask();
#line 75
      break;
#line 75
    case /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__errorTask:
#line 75
      /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__errorTask__runTask();
#line 75
      break;
#line 75
    default:
#line 75
      SchedulerBasicP__TaskBasic__default__runTask(arg_0x40467088);
#line 75
      break;
#line 75
    }
#line 75
}
#line 75
# 233 "TestSenderP.nc"
static void TestSenderP__ReportSend__sendDone(message_t *msg, error_t err)
#line 233
{



  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 237
    {
      TestSenderP__state = TestSenderP__S_NEED_LOAD;
      TestSenderP__SendReadyInterrupt__enableFallingEdge();
      TestSenderP__seqNum++;
    }
#line 241
    __nesc_atomic_end(__nesc_atomic); }
}

# 52 "/opt/tinyos-2.x/tos/chips/msp430/pins/Msp430InterruptC.nc"
static error_t /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__enable(bool rising)
#line 52
{
  /* atomic removed: atomic calls only */
#line 53
  {
    /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__Interrupt__disable();
    /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__HplInterrupt__edge(rising);
    /*TestSenderAppC.SendReadyInterrupt*/Msp430InterruptC__1__HplInterrupt__enable();
  }
  return SUCCESS;
}

# 163 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static void /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__sendDone(uint8_t last, message_t * msg, error_t err)
#line 163
{
  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__queue[last].msg = (void *)0;
  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__tryToSend();
  /*SerialAMQueueP.AMQueueImplP*/AMQueueImplP__1__Send__sendDone(last, msg, err);
}

# 148 "/opt/tinyos-2.x/tos/lib/serial/SerialActiveMessageP.nc"
static am_addr_t /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMPacket__destination(message_t *amsg)
#line 148
{
  serial_header_t *header = /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__getHeader(amsg);

#line 150
  return __nesc_ntoh_uint16(header->dest.data);
}

#line 68
static error_t /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__AMSend__send(am_id_t id, am_addr_t dest, 
message_t *msg, 
uint8_t len)
#line 70
{
  serial_header_t *header = /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__getHeader(msg);

  if (len > /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__Packet__maxPayloadLength()) {
      return ESIZE;
    }

  __nesc_hton_uint16(header->dest.data, dest);





  __nesc_hton_uint8(header->type.data, id);
  __nesc_hton_uint8(header->length.data, len);

  return /*SerialActiveMessageC.AM*/SerialActiveMessageP__0__SubSend__send(msg, len);
}

# 134 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__unconfigure_(void )
{
  while (0x01 & /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__getStat()) {
      ;
    }
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__setIe(/*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__getIe() & ~(0x0002 | 0x0001));
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__enterResetMode_();
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__URXD__makeOutput();
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__URXD__selectIOFunc();
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UTXD__makeOutput();
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UTXD__selectIOFunc();
}

# 55 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static void /*HplMsp430GeneralIOC.P16*/HplMsp430GeneralIORenP__6__IO__makeOutput(void )
#line 55
{
#line 55
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 55
    * (volatile uint8_t * )516U |= 0x01 << 6;
#line 55
    __nesc_atomic_end(__nesc_atomic); }
}

# 154 "/opt/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciUartP.nc"
static error_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__configure_(const msp430_usci_config_t *config)
{
  if (!config) {
      return FAIL;
    }



  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__configure(config, TRUE);
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__URXD__makeInput();
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__URXD__selectModuleFunc();
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UTXD__makeOutput();
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__UTXD__selectModuleFunc();
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__leaveResetMode_();
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__setIe((0x0001 | /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__Usci__getIe()) & ~0x0002);
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_tx_buf = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartP__0__m_rx_buf = 0;

  return SUCCESS;
}

# 135 "/opt/tinyos-2.x/tos/platforms/bacon/hardware/leds/PlatformLedP.nc"
static void PlatformLedP___LEDwrite(unsigned int value)
{
  int li;

#line 138
  for (li = 0; li < PlatformLedP__nleds; ++li) {
      if (value & (1 << li)) {
          PlatformLedP___LEDon(li);
        }
      else 
#line 141
        {
          PlatformLedP___LEDoff(li);
        }
    }
}

# 271 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
static error_t /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Send__send(uint8_t frame_type, message_t *msg, uint8_t len)
{
  int rv = SUCCESS;
  uint8_t *packet_start = (uint8_t *)/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__header(msg);
  unsigned int packet_length = sizeof(/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__phy_header_t ) + len;
  ieee154_fcf_t *fcfp = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__fcf(msg);

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 278
    {
      if (/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__SCS_on != /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__split_control_state) {
          rv = EOFF;
        }
      else {
#line 281
        if (/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__TXS_idle != /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__tx_state) {
            rv = EBUSY;
          }
        else 
#line 283
          {
            __nesc_htonbf_leuint16((unsigned char *)&(*fcfp), 0, 3, frame_type);
            rv = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__send(packet_start, packet_length);
            if (SUCCESS == rv) {
                /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__tx_message = msg;
                /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__tx_state = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__TXS_active;
                /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__tx_result = SUCCESS;
              }
          }
        }
    }
#line 293
    __nesc_atomic_end(__nesc_atomic); }










  return rv;
}

#line 62
static ieee154_fcf_t */*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__fcf(message_t *msg)
#line 62
{
#line 62
  return (ieee154_fcf_t *)& /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__header(msg)->fcf;
}

# 124 "/opt/tinyos-2.x/tos/system/SimpleArbiterP.nc"
static bool /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ArbiterInfo__inUse(void )
#line 124
{
  /* atomic removed: atomic calls only */
#line 125
  {
    if (/*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__state == /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__RES_IDLE) 
      {
        unsigned char __nesc_temp = 
#line 127
        FALSE;

#line 127
        return __nesc_temp;
      }
  }
#line 129
  return TRUE;
}






static uint8_t /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__ArbiterInfo__userId(void )
#line 137
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 138
    {
      if (/*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__state != /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__RES_BUSY) 
        {
          unsigned char __nesc_temp = 
#line 140
          /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__NO_RES;

          {
#line 140
            __nesc_atomic_end(__nesc_atomic); 
#line 140
            return __nesc_temp;
          }
        }
#line 141
      {
        unsigned char __nesc_temp = 
#line 141
        /*Rf1aC.HplRf1aC.ArbiterC.Arbiter*/SimpleArbiterP__0__resId;

        {
#line 141
          __nesc_atomic_end(__nesc_atomic); 
#line 141
          return __nesc_temp;
        }
      }
    }
#line 144
    __nesc_atomic_end(__nesc_atomic); }
}

# 152 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIfP.nc"
static uint8_t /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__strobe(uint8_t instr)
{
  unsigned char rv = 0xFF;

  /* atomic removed: atomic calls only */
#line 155
  {
    uint8_t base_instr = instr & ~0x80;

#line 157
    if (0x30 <= base_instr && base_instr <= 0x3D) {
        rv = 0;
        RF1AIFCTL1 &= ~0x0040;

        while (!(RF1AIFCTL1 & 0x0010)) {
            ;
          }
        RF1AINSTRW_H = instr;


        if (0x30 != base_instr) {
            while (!(RF1AIFCTL1 & 0x0040)) {
                if (RF1AIFCTL1 & 0x0004) {
                    (void )RF1AIFERRV;
                    rv = 0xff;
                    break;
                  }
                ;
              }
            if (RF1AIFCTL1 & 0x0040) {
                rv = RF1ASTAT0W_H;
              }
          }
      }
  }
  return rv;
}

static uint8_t /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__readRegister(uint8_t addr)
{
  /* atomic removed: atomic calls only */
#line 187
  {
    while (!(RF1AIFCTL1 & 0x0010)) {
        ;
      }
    if (0x2E >= addr || 0x3E == addr) {
        RF1AINSTR1W_H = 0x80 | addr;
      }
    else 
#line 193
      {
        RF1AINSTR1W_H = 0xC0 | addr;
      }
    while (!(RF1AIFCTL1 & 0x0080)) {
        ;
      }
    {
      unsigned char __nesc_temp = 
#line 199
      RF1ASTAT0W_L;

#line 199
      return __nesc_temp;
    }
  }
}

# 491 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__resetAndFlushTxFifo_(void )
{
  uint8_t rc;



  rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x36);
  while (RF1A_S_IDLE != (RF1A_S_MASK & rc)) {
      rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x3D);
    }
  rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x3B);
  while (RF1A_S_IDLE != (RF1A_S_MASK & rc)) {
      rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x3D);
    }
  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__resumeIdleMode_(TRUE);
}

#line 289
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__resumeIdleMode_(bool rx_if_enabled)
{
  /* atomic removed: atomic calls only */
#line 291
  {
    uint8_t strobe = 0x36;
    uint8_t state = RF1A_S_IDLE;
    uint8_t rc;


    rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x3D);
    if (0x80 & rc) {
        while (0x80 & rc) {
            rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x36);
          }
        while (RF1A_S_IDLE != (RF1A_S_MASK & rc)) {
            rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x3D);
          }
      }
    if (rx_if_enabled && ! !/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_pos) {
        strobe = 0x34;
        state = RF1A_S_RX;
      }
    (void )/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(strobe);
    do {
        rc = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x3D);
      }
    while (
#line 313
    state != (RF1A_S_MASK & rc));
  }
}



static bool /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__transmitIsInactive_atomic_(void )
{
  return /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__TX_S_inactive == /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_state && 0 == /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(0x3A);
}

# 203 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIfP.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__writeRegister(uint8_t addr, 
uint8_t val)
{
  /* atomic removed: atomic calls only */
#line 206
  {
    while (!(RF1AIFCTL1 & 0x0010)) {
        ;
      }
    if (0x2E >= addr) {
        RF1AINSTRW_H = 0x40 | addr;
      }
    else 
#line 212
      {
        RF1AINSTRW_H = 0x00 | addr;
      }
    RF1AINSTRW_L = val;
     __asm volatile ("nop");}
}

# 194 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/layers/Rf1aAckP.nc"
static bool /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__completeSend_atomic_(error_t result)
{
  bool rv = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_acked = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__TX_S_ACKED & /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_state;

#line 197
  if (!/*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_acked) {
      if (SUCCESS != result && 0 == /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_attempts_remaining) {
          rv = TRUE;
        }
      else 
#line 200
        {
          /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__transitionToWaiting_atomic_();
        }
    }
  return rv;
}

# 81 "/opt/tinyos-2.x/tos/chips/msp430/timer/Msp430AlarmC.nc"
static void /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Alarm__startAt(uint16_t t0, uint16_t dt)
{
  /* atomic removed: atomic calls only */
  {
    uint16_t now = /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430Timer__get();
    uint16_t elapsed = now - t0;

#line 87
    if (elapsed >= dt) 
      {
        /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430Compare__setEventFromNow(2);
      }
    else 
      {
        uint16_t remaining = dt - elapsed;

#line 94
        if (remaining <= 2) {
          /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430Compare__setEventFromNow(2);
          }
        else {
#line 97
          /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430Compare__setEvent(now + remaining);
          }
      }
#line 99
    /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430TimerControl__clearPendingInterrupt();
    /*Rf1aActiveMessageC.AckC.Alarm32khz16C.Msp430Alarm*/Msp430AlarmC__1__Msp430TimerControl__enableEvents();
  }
}

# 156 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/layers/Rf1aAckP.nc"
static void /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__signalSendDone_(void )
{
  message_t *msg;
  error_t rv;




  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 164
    {
      /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_state = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__TX_S_idle;
      msg = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_message;
      /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_message = 0;
      rv = /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__tx_result;
    }
#line 169
    __nesc_atomic_end(__nesc_atomic); }
  if (msg) {
      /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__Send__sendDone(msg, rv);
    }
}

# 189 "/opt/tinyos-2.x/tos/system/AMQueueImplP.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__sendDone(am_id_t id, message_t *msg, error_t err)
#line 189
{





  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current >= 1) {
      return;
    }
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current].msg == msg) {
      /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__sendDone(/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current, msg, err);
    }
  else {
      ;
    }
}

#line 174
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__tryToSend(void )
#line 174
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__nextPacket();
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current < 1) {
      error_t nextErr;
      message_t *nextMsg = /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__queue[/*AMQueueP.AMQueueImplP*/AMQueueImplP__0__current].msg;
      am_id_t nextId = /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMPacket__type(nextMsg);
      am_addr_t nextDest = /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMPacket__destination(nextMsg);
      uint8_t len = /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__Packet__payloadLength(nextMsg);

#line 182
      nextErr = /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__AMSend__send(nextId, nextDest, nextMsg, len);
      if (nextErr != SUCCESS) {
          /*AMQueueP.AMQueueImplP*/AMQueueImplP__0__errorTask__postTask();
        }
    }
}

# 59 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aActiveMessageP.nc"
static error_t Rf1aActiveMessageP__AMSend__send(am_id_t id, am_addr_t addr, 
message_t *msg, 
uint8_t len)
{
  Rf1aActiveMessageP__Rf1aPacket__configureAsData(msg);
  Rf1aActiveMessageP__AMPacket__setSource(msg, Rf1aActiveMessageP__AMPacket__address());
  Rf1aActiveMessageP__Ieee154Packet__setPan(msg, Rf1aActiveMessageP__Ieee154Packet__localPan());
  Rf1aActiveMessageP__AMPacket__setDestination(msg, addr);
  Rf1aActiveMessageP__AMPacket__setType(msg, id);
  Rf1aActiveMessageP__SendNotifier__aboutToSend(id, addr, msg);

  return Rf1aActiveMessageP__SubSend__send(msg, len + sizeof(Rf1aActiveMessageP__layer_header_t ));
}

# 57 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/system/Ieee154AddressP.nc"
static ieee154_saddr_t Ieee154AddressP__Ieee154Address__shortAddress(void )
#line 57
{
#line 57
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 57
    {
      unsigned int __nesc_temp = 
#line 57
      Ieee154AddressP__short_address;

      {
#line 57
        __nesc_atomic_end(__nesc_atomic); 
#line 57
        return __nesc_temp;
      }
    }
#line 59
    __nesc_atomic_end(__nesc_atomic); }
}

# 94 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aAMPacketP.nc"
static void Rf1aAMPacketP__AMPacket__setType(message_t *amsg, am_id_t t)
{
  Rf1aAMPacketP__layer_header_t *lhp = Rf1aAMPacketP__layerHeader(amsg);

  __nesc_hton_leuint8(lhp->nalp_tinyos.data, LOWPAN_NALP_TINYOS);
  __nesc_hton_leuint8(lhp->am_type.data, t);
}

# 27 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/layers/Rf1aAckP.nc"
static ieee154_fcf_t */*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__fcf(message_t *msg)
#line 27
{
#line 27
  return (ieee154_fcf_t *)& /*Rf1aActiveMessageC.AckC.Rf1aAckP*/Rf1aAckP__0__header(msg)->fcf;
}

# 209 "TestSenderP.nc"
static void TestSenderP__RadioSend__sendDone(message_t *msg, error_t err)
#line 209
{



  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 213
    {
      if (TestSenderP__state == TestSenderP__S_SENDING) {
          TestSenderP__state = TestSenderP__S_REPORTING;
        }
      else 
#line 216
        {
          TestSenderP__state = TestSenderP__S_ERROR;
        }
      TestSenderP__reportTask__postTask();
    }
#line 220
    __nesc_atomic_end(__nesc_atomic); }
}

# 147 "/opt/tinyos-2.x/tos/interfaces/AMPacket.nc"
static am_id_t Rf1aActiveMessageP__AMPacket__type(message_t * amsg){
#line 147
  unsigned char __nesc_result;
#line 147

#line 147
  __nesc_result = Rf1aAMPacketP__AMPacket__type(amsg);
#line 147

#line 147
  return __nesc_result;
#line 147
}
#line 147
# 1540 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysicalMetadata__store(rf1a_metadata_t *metadatap)
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 1542
    {
      __nesc_hton_leuint8(metadatap->rssi.data, /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_rssi_raw);
      __nesc_hton_leuint8(metadatap->lqi.data, /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rx_lqi_raw);
    }
#line 1545
    __nesc_atomic_end(__nesc_atomic); }
}

# 222 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/Rf1aTinyOsPhysicalP.nc"
static void /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__setReceiveBuffer(message_t *mp)
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 224
    {
      int rv;
      uint8_t *hp;

      if (mp) {
          /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__rx_message = mp;
        }


      hp = (uint8_t *)/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__header(/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__rx_message);



      rv = /*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__Rf1aPhysical__setReceiveBuffer(hp, (uint8_t *)(/*Rf1aActiveMessageC.TinyOsPhysicalC.Rf1aTinyOsPhysicalP*/Rf1aTinyOsPhysicalP__0__rx_message + 1) - hp, TRUE);
    }
#line 238
    __nesc_atomic_end(__nesc_atomic); }
}

# 245 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIfP.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__writeBurstRegister(uint8_t addr, 
const uint8_t *buf, 
uint8_t len)
{
  const uint8_t *be = buf + len;

  if (0 == len) {
      return;
    }
  /* atomic removed: atomic calls only */
#line 254
  {
    while (!(RF1AIFCTL1 & 0x0010)) {
        ;
      }


    RF1AINSTRW = ((addr | 0x40) << 8) + * buf++;

    while (buf < be) {
        RF1AINSTRW_L = * buf++;
        while (!(RF1AIFCTL1 & 0x0020)) {
            ;
          }
      }
    (void )RF1ASTAT0W_L;
  }
}

# 49 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static void /*HplMsp430GeneralIOC.P24*/HplMsp430GeneralIORenP__12__IO__clr(void )
#line 49
{
#line 49
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 49
    * (volatile uint8_t * )515U &= ~(0x01 << 4);
#line 49
    __nesc_atomic_end(__nesc_atomic); }
}

# 660 "/opt/tinyos-2.x/tos/lib/rf1a-multi/HplMsp430Rf1aP.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__DelayedSendRf1aPhysical__completeSend(uint8_t clientId)
#line 660
{
  /* atomic removed: atomic calls only */
  {


    if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__wrote_data_ds && RF1A_S_TX != (RF1A_S_MASK & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x3D))) {
        register int loop_limit = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__RADIO_LOOP_LIMIT;





        /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IndicatorPin__set();
        /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rc_ds = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x35);
        while (RF1A_S_TX != (RF1A_S_MASK & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rc_ds)
         && RF1A_S_RX != (RF1A_S_MASK & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rc_ds)
         && RF1A_S_IDLE != (RF1A_S_MASK & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rc_ds)
         && 0 <= --loop_limit) {
            /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rc_ds = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__strobe(0x3D);
          }
        /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__IndicatorPin__clr();
        if (RF1A_S_TX != (RF1A_S_MASK & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__rc_ds)) {
            /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_result = ERETRY;
            /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__cancelTransmit_();
          }
      }


    if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__TX_S_active <= /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_state) {




        if (0 == /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_remain) {
            if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__TX_S_active == /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_state) {
                /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_state = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__TX_S_flushing;
                /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_cached_fifothr = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(0x03);
                /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__writeRegister(0x03, 0x0F | /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_cached_fifothr);
              }
            if (0 == /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(0x3A)) {
                /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__result_ds = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_result;
                /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__writeRegister(0x03, /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_cached_fifothr);
#line 732
                {
                  uint8_t ms;

#line 734
                  do {
                      ms = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(0x35);
                    }
                  while (
#line 736
                  /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__MRCSM_TX == ms);
                }

                /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__tx_state = /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__TX_S_inactive;
                /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__send_done_ds = TRUE;
              }
          }
      }
  }

  if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__need_repost_ds) {
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__sendFragment_task__postTask();
    }
  if (/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__send_done_ds) {
      /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aPhysical__sendDone(/*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__client_ds, /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__result_ds);
    }
}

#line 1057
static unsigned int /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__receiveCountAvailable_(void )
{
  unsigned int avail;
  unsigned int avail2;

  avail2 = 0x7f & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(0x3B);
  avail = ~avail2;
  while (avail != avail2) {
      avail = avail2;
      avail2 = 0x7f & /*Rf1aC.HplRf1aC.HplRf1aP*/HplMsp430Rf1aP__0__Rf1aIf__readRegister(0x3B);
    }
  return avail;
}

# 220 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aIfP.nc"
static void /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__readBurstRegister(uint8_t addr, 
uint8_t *buf, 
uint8_t len)
{
  uint8_t *b1e = buf + len - 1;

  if (0 == len) {
      return;
    }
  /* atomic removed: atomic calls only */
#line 229
  {
    while (!(RF1AIFCTL1 & 0x0010)) {
        ;
      }

    RF1AINSTR1W_H = addr | 0xC0;
    while (buf < b1e) {
        while (!(RF1AIFCTL1 & 0x0080)) {
            ;
          }
        * buf++ = RF1ASTAT1W_L;
      }
    * buf++ = RF1ASTAT0W_L;
  }
}

#line 272
static uint8_t /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__resetRadioCore(void )
{
  uint8_t rv;

  /* atomic removed: atomic calls only */
#line 275
  {
    /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__strobe(0x30);
    rv = /*Rf1aC.HplRf1aC.HplRf1aIfP*/HplMsp430Rf1aIfP__0__HplMsp430Rf1aIf__strobe(0x3D);
  }
  return rv;
}

# 73 "/opt/tinyos-2.x/tos/lib/timer/VirtualizeTimerC.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__fireTimers(uint32_t now)
{
  uint16_t num;

  for (num = 0; num < /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__NUM_TIMERS; num++) 
    {
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer_t *timer = &/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__m_timers[num];

      if (timer->isrunning) 
        {
          uint32_t elapsed = now - timer->t0;

          if (elapsed >= timer->dt) 
            {
              if (timer->isoneshot) {
                timer->isrunning = FALSE;
                }
              else {
#line 90
                timer->t0 += timer->dt;
                }
              /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__fired(num);
              break;
            }
        }
    }
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__postTask();
}

# 147 "/opt/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__startAt(/*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type t0, /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type dt)
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__m_t0 = t0;
      /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__m_dt = dt;
      /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__set_alarm();
    }
#line 154
    __nesc_atomic_end(__nesc_atomic); }
}

# 75 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/am/Rf1aAMPacketP.nc"
static void *Rf1aAMPacketP__Packet__getPayload(message_t *msg, uint8_t len)
#line 75
{
#line 75
  return (void *)(1 + Rf1aAMPacketP__layerHeader(msg));
}

# 69 "/opt/tinyos-2.x/tos/system/RandomMlcgC.nc"
static uint32_t RandomMlcgC__Random__rand32(void )
#line 69
{
  uint32_t mlcg;
#line 70
  uint32_t p;
#line 70
  uint32_t q;
  uint64_t tmpseed;

  /* atomic removed: atomic calls only */
#line 73
  {
    tmpseed = (uint64_t )33614U * (uint64_t )RandomMlcgC__seed;
    q = tmpseed;
    q = q >> 1;
    p = tmpseed >> 32;
    mlcg = p + q;
    if (mlcg & 0x80000000) {
        mlcg = mlcg & 0x7FFFFFFF;
        mlcg++;
      }
    RandomMlcgC__seed = mlcg;
  }
  return mlcg;
}

# 60 "/opt/tinyos-2.x/tos/chips/msp430/rf1a/physical/HplMsp430Rf1aInterruptP.nc"
__attribute((wakeup)) __attribute((interrupt(0x6a)))  void sig_CC1101_VECTOR(void )
#line 60
{
  uint16_t coreInterrupt = RF1AIV;
  uint8_t client = HplMsp430Rf1aInterruptP__ArbiterInfo__userId();


  if (!HplMsp430Rf1aInterruptP__ArbiterInfo__inUse()) {
      return;
    }




  __bic_sr_irq(0x0080 + 0x0040 + 0x0020 + 0x0010);



  if (coreInterrupt) {
#line 95
      switch (coreInterrupt) {
          default: 
            HplMsp430Rf1aInterruptP__Rf1aInterrupts__coreInterrupt(client, coreInterrupt);
          break;
          case 0x000A: 
            HplMsp430Rf1aInterruptP__Rf1aInterrupts__rxFifoAvailable(client);
          break;
          case 0x000C: 
            HplMsp430Rf1aInterruptP__Rf1aInterrupts__txFifoAvailable(client);
          break;
          case 0x0010: 
            HplMsp430Rf1aInterruptP__Rf1aInterrupts__rxOverflow(client);
          break;
          case 0x0012: 
            HplMsp430Rf1aInterruptP__Rf1aInterrupts__txUnderflow(client);
          break;
          case 0x0014: 
            HplMsp430Rf1aInterruptP__Rf1aInterrupts__syncWordEvent(client);
          break;
          case 0x001A: 
            HplMsp430Rf1aInterruptP__Rf1aInterrupts__clearChannel(client);
          break;
          case 0x001C: 
            HplMsp430Rf1aInterruptP__Rf1aInterrupts__carrierSense(client);
          break;
        }
    }
}

# 64 "/opt/tinyos-2.x/tos/chips/msp430/pins/HplMsp430InterruptP.nc"
__attribute((wakeup)) __attribute((interrupt(0x62)))  void sig_PORT1_VECTOR(void )
{
  volatile int n = P1IFG & P1IE;

  if (n & (1 << 0)) {
#line 68
      HplMsp430InterruptP__Port10__fired();
#line 68
      return;
    }
#line 69
  if (n & (1 << 1)) {
#line 69
      HplMsp430InterruptP__Port11__fired();
#line 69
      return;
    }
#line 70
  if (n & (1 << 2)) {
#line 70
      HplMsp430InterruptP__Port12__fired();
#line 70
      return;
    }
#line 71
  if (n & (1 << 3)) {
#line 71
      HplMsp430InterruptP__Port13__fired();
#line 71
      return;
    }
#line 72
  if (n & (1 << 4)) {
#line 72
      HplMsp430InterruptP__Port14__fired();
#line 72
      return;
    }
#line 73
  if (n & (1 << 5)) {
#line 73
      HplMsp430InterruptP__Port15__fired();
#line 73
      return;
    }
#line 74
  if (n & (1 << 6)) {
#line 74
      HplMsp430InterruptP__Port16__fired();
#line 74
      return;
    }
#line 75
  if (n & (1 << 7)) {
#line 75
      HplMsp430InterruptP__Port17__fired();
#line 75
      return;
    }
}

#line 169
__attribute((wakeup)) __attribute((interrupt(0x60)))  void sig_PORT2_VECTOR(void )
{
  volatile int n = P2IFG & P2IE;

  if (n & (1 << 0)) {
#line 173
      HplMsp430InterruptP__Port20__fired();
#line 173
      return;
    }
#line 174
  if (n & (1 << 1)) {
#line 174
      HplMsp430InterruptP__Port21__fired();
#line 174
      return;
    }
#line 175
  if (n & (1 << 2)) {
#line 175
      HplMsp430InterruptP__Port22__fired();
#line 175
      return;
    }
#line 176
  if (n & (1 << 3)) {
#line 176
      HplMsp430InterruptP__Port23__fired();
#line 176
      return;
    }
#line 177
  if (n & (1 << 4)) {
#line 177
      HplMsp430InterruptP__Port24__fired();
#line 177
      return;
    }
#line 178
  if (n & (1 << 5)) {
#line 178
      HplMsp430InterruptP__Port25__fired();
#line 178
      return;
    }
#line 179
  if (n & (1 << 6)) {
#line 179
      HplMsp430InterruptP__Port26__fired();
#line 179
      return;
    }
#line 180
  if (n & (1 << 7)) {
#line 180
      HplMsp430InterruptP__Port27__fired();
#line 180
      return;
    }
}

