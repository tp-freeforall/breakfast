#define nx_struct struct
#define nx_union union
# 149 "/usr/bin/../lib/gcc/msp430/4.5.3/include/stddef.h" 3
typedef long int ptrdiff_t;
#line 211
typedef unsigned int size_t;
#line 323
typedef int wchar_t;
# 8 "/usr/lib/ncc/deputy_nodeputy.h"
struct __nesc_attr_nonnull {
#line 8
  int dummy;
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
#line 13
  int dummy;
}  ;
#line 14
struct __nesc_attr_one_nok {
#line 14
  int dummy;
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
#line 17
  int dummy;
}  ;
# 38 "/usr/bin/../lib/gcc/msp430/4.5.3/../../../../msp430/include/stdint.h" 3
typedef signed char int8_t;
typedef int int16_t;
typedef long int int32_t;
__extension__ 
#line 41
typedef long long int int64_t;

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
__extension__ 
#line 46
typedef unsigned long long int uint64_t;





typedef signed char int_least8_t;
typedef int int_least16_t;
typedef long int int_least32_t;
__extension__ 
#line 55
typedef long long int int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
__extension__ 
#line 61
typedef unsigned long long int uint_least64_t;





typedef signed char int_fast8_t;
typedef int int_fast16_t;
typedef long int int_fast32_t;
__extension__ 
#line 70
typedef long long int int_fast64_t;


typedef unsigned char uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
__extension__ 
#line 76
typedef unsigned long long int uint_fast64_t;









typedef int16_t intptr_t;
typedef uint16_t uintptr_t;





__extension__ 
#line 93
typedef long long int intmax_t;
__extension__ 
#line 94
typedef unsigned long long int uintmax_t;
# 431 "/usr/lib/ncc/nesc_nx.h"
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nx_int8_t;typedef int8_t __nesc_nxbase_nx_int8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nx_int16_t;typedef int16_t __nesc_nxbase_nx_int16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nx_int32_t;typedef int32_t __nesc_nxbase_nx_int32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nx_int64_t;typedef int64_t __nesc_nxbase_nx_int64_t  ;
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nx_uint8_t;typedef uint8_t __nesc_nxbase_nx_uint8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nx_uint16_t;typedef uint16_t __nesc_nxbase_nx_uint16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nx_uint32_t;typedef uint32_t __nesc_nxbase_nx_uint32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nx_uint64_t;typedef uint64_t __nesc_nxbase_nx_uint64_t  ;


typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nxle_int8_t;typedef int8_t __nesc_nxbase_nxle_int8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nxle_int16_t;typedef int16_t __nesc_nxbase_nxle_int16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nxle_int32_t;typedef int32_t __nesc_nxbase_nxle_int32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nxle_int64_t;typedef int64_t __nesc_nxbase_nxle_int64_t  ;
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nxle_uint8_t;typedef uint8_t __nesc_nxbase_nxle_uint8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nxle_uint16_t;typedef uint16_t __nesc_nxbase_nxle_uint16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nxle_uint32_t;typedef uint32_t __nesc_nxbase_nxle_uint32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nxle_uint64_t;typedef uint64_t __nesc_nxbase_nxle_uint64_t  ;
# 48 "/usr/bin/../lib/gcc/msp430/4.5.3/../../../../msp430/include/sys/types.h" 3
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
# 40 "/usr/bin/../lib/gcc/msp430/4.5.3/../../../../msp430/include/string.h" 3
extern void *memset(void *arg_0x2b74e189e5d8, int arg_0x2b74e189e840, size_t arg_0x2b74e189eae8);
#line 61
extern void *memset(void *arg_0x2b74e18b7868, int arg_0x2b74e18b7ad0, size_t arg_0x2b74e18b7d78);
# 59 "/usr/bin/../lib/gcc/msp430/4.5.3/../../../../msp430/include/stdlib.h" 3
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
# 122 "/usr/bin/../lib/gcc/msp430/4.5.3/../../../../msp430/include/sys/config.h" 3
typedef long int __int32_t;
typedef unsigned long int __uint32_t;
# 12 "/usr/bin/../lib/gcc/msp430/4.5.3/../../../../msp430/include/sys/_types.h" 3
typedef long _off_t;
typedef long _ssize_t;
# 19 "/usr/bin/../lib/gcc/msp430/4.5.3/../../../../msp430/include/sys/reent.h" 3
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

  void (*__cleanup)(struct _reent *arg_0x2b74e18f7b58);


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


  void (**_sig_func)(int arg_0x2b74e18fcc10);




  struct _glue __sglue;
  struct __sFILE __sf[3];
};
#line 273
struct _reent;
# 18 "/usr/bin/../lib/gcc/msp430/4.5.3/../../../../msp430/include/math.h" 3
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
# 25 "/home/carlson/local/src/tinyos-2.x/tos/system/tos.h"
typedef uint8_t bool;
enum __nesc_unnamed4247 {
#line 26
  FALSE = 0, TRUE = 1
};
typedef nx_int8_t nx_bool;







struct __nesc_attr_atmostonce {
};
#line 37
struct __nesc_attr_atleastonce {
};
#line 38
struct __nesc_attr_exactlyonce {
};
# 51 "/home/carlson/local/src/tinyos-2.x/tos/types/TinyError.h"
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
# 30 "/usr/bin/../lib/gcc/msp430/4.5.3/../../../../msp430/include/msp430.h" 3
#line 24
typedef enum msp430_cpu_e {

  MSP430_CPU_MSP430 = 0x0000, 
  MSP430_CPU_MSP430X = 0x0002, 
  MSP430_CPU_MSP430XV2 = 0x0003, 
  MSP430_CPU = 0x0003
} msp430_cpu_e;
#line 46
#line 34
typedef enum msp430_mpy_e {

  MSP430_MPY_NONE = 0x0000, 
  MSP430_MPY_TYPE_16 = 0x0010, 
  MSP430_MPY_TYPE_32 = 0x0020, 
  MSP430_MPY_TYPE_ANY = 0x0030, 
  MSP430_MPY_HAS_SE = 0x0001, 
  MSP430_MPY_HAS_DW = 0x0002, 
  MSP430_MPY_16 = MSP430_MPY_TYPE_16, 
  MSP430_MPY_16SE = MSP430_MPY_16 | MSP430_MPY_HAS_SE, 
  MSP430_MPY_32 = MSP430_MPY_TYPE_32 | MSP430_MPY_HAS_SE, 
  MSP430_MPY_32DW = MSP430_MPY_32 | MSP430_MPY_HAS_DW
} msp430_mpy_e;
# 43 "/usr/bin/../lib/gcc/msp430/4.5.3/../../../../msp430/include/in430.h" 3
void __nop(void );



void __dint(void );



void __eint(void );


unsigned int __read_status_register(void );
# 152 "/usr/bin/../lib/gcc/msp430/4.5.3/../../../../msp430/include/msp430f235.h" 3
extern volatile unsigned char IE2 __asm ("__""IE2");








extern volatile unsigned char IFG2 __asm ("__""IFG2");
#line 175
extern volatile unsigned int ADC12CTL0 __asm ("__""ADC12CTL0");

extern volatile unsigned int ADC12CTL1 __asm ("__""ADC12CTL1");
#line 434
extern volatile unsigned char DCOCTL __asm ("__""DCOCTL");

extern volatile unsigned char BCSCTL1 __asm ("__""BCSCTL1");

extern volatile unsigned char BCSCTL2 __asm ("__""BCSCTL2");

extern volatile unsigned char BCSCTL3 __asm ("__""BCSCTL3");
#line 563
extern volatile unsigned int FCTL1 __asm ("__""FCTL1");

extern volatile unsigned int FCTL2 __asm ("__""FCTL2");

extern volatile unsigned int FCTL3 __asm ("__""FCTL3");
#line 646
extern volatile unsigned char P1OUT __asm ("__""P1OUT");

extern volatile unsigned char P1DIR __asm ("__""P1DIR");
#line 663
extern volatile unsigned char P2OUT __asm ("__""P2OUT");

extern volatile unsigned char P2DIR __asm ("__""P2DIR");
#line 686
extern volatile unsigned char P3OUT __asm ("__""P3OUT");

extern volatile unsigned char P3DIR __asm ("__""P3DIR");








extern volatile unsigned char P4OUT __asm ("__""P4OUT");

extern volatile unsigned char P4DIR __asm ("__""P4DIR");
#line 714
extern volatile unsigned char P5OUT __asm ("__""P5OUT");

extern volatile unsigned char P5DIR __asm ("__""P5DIR");








extern volatile unsigned char P6OUT __asm ("__""P6OUT");

extern volatile unsigned char P6DIR __asm ("__""P6DIR");
#line 761
extern volatile unsigned int TACTL __asm ("__""TACTL");

extern volatile unsigned int TACCTL0 __asm ("__""TACCTL0");

extern volatile unsigned int TACCTL1 __asm ("__""TACCTL1");

extern volatile unsigned int TACCTL2 __asm ("__""TACCTL2");







extern volatile unsigned int TACCR2 __asm ("__""TACCR2");
#line 863
extern volatile unsigned int TBCTL __asm ("__""TBCTL");
#line 953
extern volatile unsigned char UCA0STAT __asm ("__""UCA0STAT");

extern const volatile unsigned char UCA0RXBUF __asm ("__""UCA0RXBUF");

extern volatile unsigned char UCA0TXBUF __asm ("__""UCA0TXBUF");
#line 978
extern volatile unsigned char UCB0STAT __asm ("__""UCB0STAT");

extern const volatile unsigned char UCB0RXBUF __asm ("__""UCB0RXBUF");
#line 1160
extern volatile unsigned int WDTCTL __asm ("__""WDTCTL");
#line 1249
extern const volatile unsigned char CALDCO_16MHZ __asm ("__""CALDCO_16MHZ");

extern const volatile unsigned char CALBC1_16MHZ __asm ("__""CALBC1_16MHZ");
# 378 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430hardware.h"
typedef uint8_t mcu_power_t  ;
static inline mcu_power_t mcombine(mcu_power_t m1, mcu_power_t m2)  ;


enum __nesc_unnamed4249 {
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
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nx_float;typedef float __nesc_nxbase_nx_float  ;
#line 448
enum __nesc_unnamed4250 {
  MSP430_PORT_RESISTOR_INVALID, 
  MSP430_PORT_RESISTOR_OFF, 
  MSP430_PORT_RESISTOR_PULLDOWN, 
  MSP430_PORT_RESISTOR_PULLUP
};


enum __nesc_unnamed4251 {
  MSP430_PORT_DRIVE_STRENGTH_INVALID, 
  MSP430_PORT_DRIVE_STRENGTH_REDUCED, 
  MSP430_PORT_DRIVE_STRENGTH_FULL
};
# 17 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/msp430usci.h"
enum __nesc_unnamed4252 {
  MSP430_USCI_Inactive, 
  MSP430_USCI_UART, 
  MSP430_USCI_SPI, 
  MSP430_USCI_I2C
};










#line 27
typedef struct msp430_usci_config_t {
  uint8_t ctl0;
  uint8_t ctl1;
  uint8_t br0;
  uint8_t br1;
  uint8_t mctl;
} msp430_usci_config_t;





msp430_usci_config_t msp430_usci_uart_default_config = { 

.ctl1 = 0x80, 
#line 70
.br0 = 0x02, 
.mctl = 0x40 + 0x06 + 0x01 };
#line 94
enum __nesc_unnamed4253 {



  MSP430_USCI_ERR_Framing = 0x40, 



  MSP430_USCI_ERR_Overrun = 0x20, 


  MSP430_USCI_ERR_Parity = 0x10, 

  MSP430_USCI_ERR_UCxySTAT = (MSP430_USCI_ERR_Framing | MSP430_USCI_ERR_Overrun) | MSP430_USCI_ERR_Parity
};
# 43 "/home/carlson/local/src/tinyos-2.x/tos/types/Leds.h"
enum __nesc_unnamed4254 {
  LEDS_LED0 = 1 << 0, 
  LEDS_LED1 = 1 << 1, 
  LEDS_LED2 = 1 << 2, 
  LEDS_LED3 = 1 << 3, 
  LEDS_LED4 = 1 << 4, 
  LEDS_LED5 = 1 << 5, 
  LEDS_LED6 = 1 << 6, 
  LEDS_LED7 = 1 << 7
};
# 33 "/home/carlson/local/src/tinyos-2.x/tos/types/Resource.h"
typedef uint8_t resource_client_id_t;
# 41 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Timer.h"
typedef struct __nesc_unnamed4255 {
#line 41
  int notUsed;
} 
#line 41
TSecond;
typedef struct __nesc_unnamed4256 {
#line 42
  int notUsed;
} 
#line 42
TMilli;
typedef struct __nesc_unnamed4257 {
#line 43
  int notUsed;
} 
#line 43
T32khz;
typedef struct __nesc_unnamed4258 {
#line 44
  int notUsed;
} 
#line 44
TMicro;
# 39 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.h"
enum __nesc_unnamed4259 {
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
typedef struct __nesc_unnamed4260 {

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
typedef struct __nesc_unnamed4261 {

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
typedef struct __nesc_unnamed4262 {

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
# 40 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/I2C.h"
typedef struct __nesc_unnamed4263 {
} 
#line 40
TI2CExtdAddr;
typedef struct __nesc_unnamed4264 {
} 
#line 41
TI2CBasicAddr;

typedef uint8_t i2c_flags_t;

enum __nesc_unnamed4265 {
  I2C_START = 0x01, 
  I2C_STOP = 0x02, 
  I2C_ACK_END = 0x04, 
  I2C_RESTART = 0x08
};
enum /*Msp430UsciA0P.UsciC*/HplMsp430UsciA0C__0____nesc_unnamed4266 {
  HplMsp430UsciA0C__0__USCI_ID = 0U
};
typedef TMilli /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__LocalTime_bms__precision_tag;
enum /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Timer*/Msp430Timer32khzC__0____nesc_unnamed4267 {
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
typedef TI2CBasicAddr ToastC__I2CBasicAddr__addr_size;
enum /*ToastAppC.I2CC*/Msp430I2CC__0____nesc_unnamed4268 {
  Msp430I2CC__0__CLIENT_ID = 0U
};
typedef TI2CBasicAddr Msp430I2CP__I2CBasicAddr__addr_size;
enum /*PlatformSerialC.UartC*/Msp430UsciUartA0C__0____nesc_unnamed4269 {
  Msp430UsciUartA0C__0__CLIENT_ID = 0U
};
# 62 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Init.nc"
static error_t PlatformP__Init__init(void );
#line 62
static error_t PlatformP__PeripheralInit__default__init(void );
#line 62
static error_t PlatformPinsP__Init__init(void );
#line 62
static error_t PlatformClockP__SubInit__default__init(void );
#line 62
static error_t PlatformClockP__Init__init(void );
# 85 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void /*HplMsp430GeneralIOC.P31*/HplMsp430GeneralIORenP__17__IO__makeOutput(void );






static void /*HplMsp430GeneralIOC.P31*/HplMsp430GeneralIORenP__17__IO__selectModuleFunc(void );
#line 85
static void /*HplMsp430GeneralIOC.P32*/HplMsp430GeneralIORenP__18__IO__makeOutput(void );






static void /*HplMsp430GeneralIOC.P32*/HplMsp430GeneralIORenP__18__IO__selectModuleFunc(void );
#line 85
static void /*HplMsp430GeneralIOC.P34*/HplMsp430GeneralIORenP__20__IO__makeOutput(void );






static void /*HplMsp430GeneralIOC.P34*/HplMsp430GeneralIORenP__20__IO__selectModuleFunc(void );
#line 78
static void /*HplMsp430GeneralIOC.P35*/HplMsp430GeneralIORenP__21__IO__makeInput(void );
#line 92
static void /*HplMsp430GeneralIOC.P35*/HplMsp430GeneralIORenP__21__IO__selectModuleFunc(void );
# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__RawInterruptsTx__interrupted(uint8_t iv);
#line 49
static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__InterruptsTx__default__interrupted(
# 52 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/HplMsp430UsciA0P.nc"
uint8_t arg_0x2b74e1d3fd10, 
# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
uint8_t iv);
#line 49
static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__RawInterruptsRx__interrupted(uint8_t iv);
# 123 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
static uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__getRxbuf(void );
#line 141
static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__setTxbuf(uint8_t v);
#line 111
static uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__getStat(void );
#line 231
static uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__getIe(void );
#line 288
static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__leaveResetMode_(void );
#line 273
static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__configure(const msp430_usci_config_t *config, 
bool leave_in_reset);
#line 237
static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__setIe(uint8_t v);
#line 281
static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__enterResetMode_(void );










static uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__currentMode(void );
# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__InterruptsRx__default__interrupted(
# 51 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/HplMsp430UsciA0P.nc"
uint8_t arg_0x2b74e1d3f0c8, 
# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
uint8_t iv);
# 62 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Init.nc"
static error_t /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__Init__init(void );
# 61 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/ResourceRequested.nc"
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceRequested__default__immediateRequested(
# 55 "/home/carlson/local/src/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x2b74e1dd67e8);
# 59 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__default__configure(
# 60 "/home/carlson/local/src/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x2b74e1dd39b8);
# 56 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/ResourceDefaultOwner.nc"
static error_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__release(void );
#line 81
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__default__immediateRequested(void );
# 97 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Resource.nc"
static error_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__immediateRequest(
# 54 "/home/carlson/local/src/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x2b74e1dd7658);
# 102 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Resource.nc"
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__default__granted(
# 54 "/home/carlson/local/src/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x2b74e1dd7658);
# 90 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
static bool /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ArbiterInfo__inUse(void );







static uint8_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ArbiterInfo__userId(void );
# 75 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__grantedTask__runTask(void );
# 59 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__ResourceConfigure__configure(
# 76 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
uint8_t arg_0x2b74e1e83960);
# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__InterruptsRx__interrupted(uint8_t iv);
#line 49
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__InterruptsTx__interrupted(uint8_t iv);
# 48 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/UartStream.nc"
static error_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__send(
# 74 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
uint8_t arg_0x2b74e1e85710, 
# 44 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/UartStream.nc"
uint8_t * buf, 



uint16_t len);
#line 79
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__default__receivedByte(
# 74 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
uint8_t arg_0x2b74e1e85710, 
# 79 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/UartStream.nc"
uint8_t byte);
#line 99
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__default__receiveDone(
# 74 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
uint8_t arg_0x2b74e1e85710, 
# 95 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/UartStream.nc"
uint8_t * buf, 



uint16_t len, error_t error);
#line 57
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__default__sendDone(
# 74 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
uint8_t arg_0x2b74e1e85710, 
# 53 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/UartStream.nc"
uint8_t * buf, 



uint16_t len, error_t error);
# 44 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciConfigure.nc"
static const msp430_usci_config_t */*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Msp430UsciConfigure__default__getConfiguration(
# 87 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
uint8_t arg_0x2b74e1e979a8);
# 42 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciError.nc"
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Msp430UsciError__default__condition(
# 77 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
uint8_t arg_0x2b74e1e82670, 
# 42 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciError.nc"
unsigned int errors);
# 39 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__VectorTimerX0__fired(void );
#line 39
static void /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__Overflow__fired(void );
#line 39
static void /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__VectorTimerX1__fired(void );
#line 39
static void /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__Event__default__fired(
# 51 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
uint8_t arg_0x2b74e1f81a88);
# 39 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__VectorTimerX0__fired(void );
#line 39
static void /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Overflow__fired(void );
#line 39
static void /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__VectorTimerX1__fired(void );
#line 39
static void /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Event__default__fired(
# 51 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
uint8_t arg_0x2b74e1f81a88);
# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static uint16_t /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Timer__get(void );
static bool /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Timer__isOverflowPending(void );
# 44 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static uint16_t /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Capture__getEvent(void );
#line 86
static void /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Capture__default__captured(uint16_t time);
# 42 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
static msp430_compare_control_t /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Control__getControl(void );
# 39 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Event__fired(void );
# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Compare__default__fired(void );
# 48 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Timer__overflow(void );
# 44 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static uint16_t /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Capture__getEvent(void );
#line 86
static void /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Capture__default__captured(uint16_t time);
# 42 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
static msp430_compare_control_t /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Control__getControl(void );
# 39 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Event__fired(void );
# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Compare__default__fired(void );
# 48 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Timer__overflow(void );
# 44 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static uint16_t /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Capture__getEvent(void );
#line 86
static void /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Capture__default__captured(uint16_t time);
# 42 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
static msp430_compare_control_t /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Control__getControl(void );
# 39 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Event__fired(void );
# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Compare__default__fired(void );
# 48 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Timer__overflow(void );
# 44 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static uint16_t /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Capture__getEvent(void );
#line 86
static void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Capture__default__captured(uint16_t time);
# 42 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
static msp430_compare_control_t /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Control__getControl(void );
#line 57
static void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Control__enableEvents(void );
static void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Control__disableEvents(void );
#line 44
static void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Control__clearPendingInterrupt(void );
# 39 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Event__fired(void );
# 41 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Compare__setEvent(uint16_t time);

static void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Compare__setEventFromNow(uint16_t delta);
# 48 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Timer__overflow(void );
# 44 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static uint16_t /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Capture__getEvent(void );
#line 86
static void /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Capture__default__captured(uint16_t time);
# 42 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
static msp430_compare_control_t /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Control__getControl(void );
# 39 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Event__fired(void );
# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Compare__default__fired(void );
# 48 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Timer__overflow(void );
# 44 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static uint16_t /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Capture__getEvent(void );
#line 86
static void /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Capture__default__captured(uint16_t time);
# 42 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
static msp430_compare_control_t /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Control__getControl(void );
# 39 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Event__fired(void );
# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Compare__default__fired(void );
# 48 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Timer__overflow(void );
# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Compare__fired(void );
# 48 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Timer__overflow(void );
# 103 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__startAt(/*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__size_type t0, /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__size_type dt);
#line 73
static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__stop(void );
# 48 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__overflow(void );
# 64 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Counter.nc"
static /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__size_type /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__get(void );






static bool /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__isOverflowPending(void );










static void /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__overflow(void );
#line 64
static /*CounterMilli32C.Transform*/TransformCounterC__0__Counter__size_type /*CounterMilli32C.Transform*/TransformCounterC__0__Counter__get(void );
# 109 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Alarm.nc"
static /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__size_type /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__getNow(void );
#line 103
static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__startAt(/*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__size_type t0, /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__size_type dt);
#line 116
static /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__size_type /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__getAlarm(void );
#line 73
static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__stop(void );




static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__fired(void );
# 82 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Counter.nc"
static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Counter__overflow(void );
# 75 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__runTask(void );
# 78 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__fired(void );
# 136 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Timer.nc"
static uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__getNow(void );
#line 129
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__startOneShotAt(uint32_t t0, uint32_t dt);
#line 78
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__stop(void );
# 75 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__runTask(void );
# 83 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__fired(void );
#line 83
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__default__fired(
# 48 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x2b74e213d5d8);
# 82 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Counter.nc"
static void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__Counter__overflow(void );
# 67 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t SchedulerBasicP__TaskBasic__postTask(
# 56 "/home/carlson/local/src/tinyos-2.x/tos/system/SchedulerBasicP.nc"
uint8_t arg_0x2b74e1a47ae8);
# 75 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void SchedulerBasicP__TaskBasic__default__runTask(
# 56 "/home/carlson/local/src/tinyos-2.x/tos/system/SchedulerBasicP.nc"
uint8_t arg_0x2b74e1a47ae8);
# 57 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Scheduler.nc"
static void SchedulerBasicP__Scheduler__init(void );
#line 72
static void SchedulerBasicP__Scheduler__taskLoop(void );
#line 65
static bool SchedulerBasicP__Scheduler__runNextTask(void );
# 62 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/McuPowerOverride.nc"
static mcu_power_t McuSleepC__McuPowerOverride__default__lowestState(void );
# 76 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/McuSleep.nc"
static void McuSleepC__McuSleep__sleep(void );
# 60 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Boot.nc"
static void ToastC__Boot__booted(void );
# 75 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void ToastC__slaveStartTask__runTask(void );
#line 75
static void ToastC__slaveReceiveTask__runTask(void );
# 160 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/I2CPacket.nc"
static void ToastC__I2CBasicAddr__slaveStop(void );
#line 114
static void ToastC__I2CBasicAddr__writeDone(error_t error, uint16_t addr, uint8_t length, 
#line 110
uint8_t * data);
#line 148
static 
#line 146
uint8_t 

ToastC__I2CBasicAddr__slaveTransmit(void );





static void ToastC__I2CBasicAddr__slaveStart(void );
#line 141
static error_t ToastC__I2CBasicAddr__slaveReceive(
#line 137
uint8_t data);
#line 103
static void ToastC__I2CBasicAddr__readDone(error_t error, uint16_t addr, uint8_t length, 
#line 100
uint8_t * data);
# 79 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/UartStream.nc"
static void ToastC__UartStream__receivedByte(uint8_t byte);
#line 99
static void ToastC__UartStream__receiveDone(
#line 95
uint8_t * buf, 



uint16_t len, error_t error);
#line 57
static void ToastC__UartStream__sendDone(
#line 53
uint8_t * buf, 



uint16_t len, error_t error);
# 75 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void ToastC__StdOutTask__runTask(void );
#line 75
static void ToastC__slaveStopTask__runTask(void );
#line 75
static void ToastC__transmitTask__runTask(void );
#line 75
static void ToastC__slaveTransmitTask__runTask(void );
# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
static void Msp430I2CP__InterruptsState__interrupted(uint8_t iv);
#line 49
static void Msp430I2CP__InterruptsTx__interrupted(uint8_t iv);
# 76 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/I2CPacket.nc"
static error_t Msp430I2CP__I2CBasicAddr__read(i2c_flags_t flags, uint16_t addr, uint8_t length, 
#line 71
uint8_t * data);
#line 56
static error_t Msp430I2CP__I2CBasicAddr__setOwnAddress(uint16_t addr);
#line 93
static error_t Msp430I2CP__I2CBasicAddr__write(i2c_flags_t flags, uint16_t addr, uint8_t length, 
#line 88
uint8_t * data);
#line 123
static error_t Msp430I2CP__I2CBasicAddr__enableSlave(void );
# 88 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Resource.nc"
static error_t Msp430I2CP__Resource__request(
# 41 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430I2CP.nc"
uint8_t arg_0x2b74e2234ce8);
# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
static void Msp430I2CP__InterruptsRx__interrupted(uint8_t iv);
# 102 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Resource.nc"
static void PlatformSerialP__Resource__granted(void );
# 95 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/StdControl.nc"
static error_t PlatformSerialP__StdControl__start(void );
# 62 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Init.nc"
static error_t PlatformP__PlatformPins__init(void );
#line 62
static error_t PlatformP__PlatformClock__init(void );
#line 62
static error_t PlatformP__PeripheralInit__init(void );
# 52 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/PlatformP.nc"
static inline error_t PlatformP__Init__init(void );
#line 73
static inline error_t PlatformP__PeripheralInit__default__init(void );
# 48 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/pins/PlatformPinsP.nc"
static inline error_t PlatformPinsP__Init__init(void );
# 62 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Init.nc"
static error_t PlatformClockP__SubInit__init(void );
# 45 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/clock/PlatformClockP.nc"
static inline error_t PlatformClockP__SubInit__default__init(void );
#line 59
static inline void PlatformClockP__set_dco(uint16_t delta);
#line 112
static inline void PlatformClockP__initClocks(void );
#line 152
static inline void PlatformClockP__initTimers(void );







static inline void PlatformClockP__startTimers(void );




static inline error_t PlatformClockP__Init__init(void );
# 55 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static void /*HplMsp430GeneralIOC.P31*/HplMsp430GeneralIORenP__17__IO__makeOutput(void );

static void /*HplMsp430GeneralIOC.P31*/HplMsp430GeneralIORenP__17__IO__selectModuleFunc(void );
#line 55
static void /*HplMsp430GeneralIOC.P32*/HplMsp430GeneralIORenP__18__IO__makeOutput(void );

static void /*HplMsp430GeneralIOC.P32*/HplMsp430GeneralIORenP__18__IO__selectModuleFunc(void );
#line 55
static inline void /*HplMsp430GeneralIOC.P34*/HplMsp430GeneralIORenP__20__IO__makeOutput(void );

static inline void /*HplMsp430GeneralIOC.P34*/HplMsp430GeneralIORenP__20__IO__selectModuleFunc(void );
#line 53
static inline void /*HplMsp430GeneralIOC.P35*/HplMsp430GeneralIORenP__21__IO__makeInput(void );



static inline void /*HplMsp430GeneralIOC.P35*/HplMsp430GeneralIORenP__21__IO__selectModuleFunc(void );
# 90 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
static bool /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__ArbiterInfo__inUse(void );
# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__InterruptsTx__interrupted(
# 52 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/HplMsp430UsciA0P.nc"
uint8_t arg_0x2b74e1d3fd10, 
# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
uint8_t iv);
#line 49
static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__InterruptsRx__interrupted(
# 51 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/HplMsp430UsciA0P.nc"
uint8_t arg_0x2b74e1d3f0c8, 
# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
uint8_t iv);
# 84 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/HplMsp430UsciA0P.nc"
volatile unsigned char /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__UCA0CTL0 __asm ("0x0060");
volatile unsigned char /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__UCA0CTL1 __asm ("0x0061");
volatile unsigned char /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__UCA0BR0 __asm ("0x0062");
volatile unsigned char /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__UCA0BR1 __asm ("0x0063");
volatile unsigned char /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__UCA0MCTL __asm ("0x0064");
volatile unsigned char /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__IE2 __asm ("0x0001");
#line 127
static inline uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__getStat(void );

static inline uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__getRxbuf(void );






static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__setTxbuf(uint8_t v);
#line 176
static inline uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__getIe(void );
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__setIe(uint8_t v);
#line 200
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__enterResetMode_(void );




static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__leaveResetMode_(void );




static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__configure(const msp430_usci_config_t *config, 
bool leave_in_reset);
#line 231
static uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__currentMode(void );
#line 247
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__RawInterruptsRx__interrupted(uint8_t iv);






static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__RawInterruptsTx__interrupted(uint8_t iv);






static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__InterruptsRx__default__interrupted(uint8_t mode, uint8_t iv);
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__InterruptsTx__default__interrupted(uint8_t mode, uint8_t iv);
# 49 "/home/carlson/local/src/tinyos-2.x/tos/system/FcfsResourceQueueC.nc"
enum /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0____nesc_unnamed4270 {
#line 49
  FcfsResourceQueueC__0__NO_ENTRY = 0xFF
};
uint8_t /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__resQ[1U];



static inline error_t /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__Init__init(void );
# 61 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/ResourceRequested.nc"
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceRequested__immediateRequested(
# 55 "/home/carlson/local/src/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x2b74e1dd67e8);
# 59 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__configure(
# 60 "/home/carlson/local/src/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x2b74e1dd39b8);
# 81 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/ResourceDefaultOwner.nc"
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__immediateRequested(void );
# 102 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Resource.nc"
static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__granted(
# 54 "/home/carlson/local/src/tinyos-2.x/tos/system/ArbiterP.nc"
uint8_t arg_0x2b74e1dd7658);
# 67 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__grantedTask__postTask(void );
# 75 "/home/carlson/local/src/tinyos-2.x/tos/system/ArbiterP.nc"
enum /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0____nesc_unnamed4271 {
#line 75
  ArbiterP__0__grantedTask = 0U
};
#line 75
typedef int /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0____nesc_sillytask_grantedTask[/*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__grantedTask];
#line 67
enum /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0____nesc_unnamed4272 {
#line 67
  ArbiterP__0__RES_CONTROLLED, ArbiterP__0__RES_GRANTING, ArbiterP__0__RES_IMM_GRANTING, ArbiterP__0__RES_BUSY
};
#line 68
enum /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0____nesc_unnamed4273 {
#line 68
  ArbiterP__0__default_owner_id = 1U
};
#line 69
enum /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0____nesc_unnamed4274 {
#line 69
  ArbiterP__0__NO_RES = 0xFF
};
uint8_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__state = /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__RES_CONTROLLED;
uint8_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__resId = /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__default_owner_id;
uint8_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__reqResId;
#line 93
static inline error_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__immediateRequest(uint8_t id);
#line 133
static inline error_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__release(void );
#line 153
static bool /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ArbiterInfo__inUse(void );
#line 166
static uint8_t /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ArbiterInfo__userId(void );
#line 190
static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__grantedTask__runTask(void );
#line 202
static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__default__granted(uint8_t id);



static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceRequested__default__immediateRequested(uint8_t id);






static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__default__immediateRequested(void );


static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__default__configure(uint8_t id);
# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
static void HplMsp430UsciInterruptsAB0P__InterruptsUCB0Tx__interrupted(uint8_t iv);
#line 49
static void HplMsp430UsciInterruptsAB0P__InterruptsUCA0Tx__interrupted(uint8_t iv);
#line 49
static void HplMsp430UsciInterruptsAB0P__InterruptsUCB0State__interrupted(uint8_t iv);
#line 49
static void HplMsp430UsciInterruptsAB0P__InterruptsUCB0Rx__interrupted(uint8_t iv);
#line 49
static void HplMsp430UsciInterruptsAB0P__InterruptsUCA0Rx__interrupted(uint8_t iv);
# 21 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/HplMsp430UsciInterruptsAB0P.nc"
void sig_USCIAB0RX_VECTOR(void ) __attribute((wakeup)) __attribute((interrupt(0x000E)))  ;
#line 34
void sig_USCIAB0TX_VECTOR(void ) __attribute((wakeup)) __attribute((interrupt(0x000C)))  ;
# 98 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
static uint8_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__ArbiterInfo__userId(void );
# 78 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__URXD__makeInput(void );
#line 92
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__URXD__selectModuleFunc(void );
#line 85
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UTXD__makeOutput(void );






static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UTXD__selectModuleFunc(void );
# 79 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/UartStream.nc"
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__receivedByte(
# 74 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
uint8_t arg_0x2b74e1e85710, 
# 79 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/UartStream.nc"
uint8_t byte);
#line 99
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__receiveDone(
# 74 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
uint8_t arg_0x2b74e1e85710, 
# 95 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/UartStream.nc"
uint8_t * buf, 



uint16_t len, error_t error);
#line 57
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__sendDone(
# 74 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
uint8_t arg_0x2b74e1e85710, 
# 53 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/UartStream.nc"
uint8_t * buf, 



uint16_t len, error_t error);
# 44 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciConfigure.nc"
static const msp430_usci_config_t */*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Msp430UsciConfigure__getConfiguration(
# 87 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
uint8_t arg_0x2b74e1e979a8);
# 42 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciError.nc"
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Msp430UsciError__condition(
# 77 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
uint8_t arg_0x2b74e1e82670, 
# 42 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciError.nc"
unsigned int errors);
# 123 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
static uint8_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__getRxbuf(void );
#line 141
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__setTxbuf(uint8_t v);
#line 111
static uint8_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__getStat(void );
#line 231
static uint8_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__getIe(void );
#line 288
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__leaveResetMode_(void );
#line 273
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__configure(const msp430_usci_config_t *config, 
bool leave_in_reset);
#line 237
static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__setIe(uint8_t v);
# 96 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
uint16_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_tx_len;
#line 96
uint16_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_rx_len;
uint8_t * /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_tx_buf;
#line 97
uint8_t * /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_rx_buf;
uint16_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_tx_pos;
#line 98
uint16_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_rx_pos;



static inline bool /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__isBusy(void );









static inline error_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__checkIsOwner(uint8_t client);
#line 155
static error_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__configure_(const msp430_usci_config_t *config);
#line 181
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__nextStreamTransmit(uint8_t client);
#line 206
static error_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__send(uint8_t client, uint8_t *buf, uint16_t len);
#line 227
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__default__sendDone(uint8_t client, uint8_t *buf, uint16_t len, error_t error);
#line 268
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__default__receivedByte(uint8_t client, uint8_t byte);
#line 290
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__default__receiveDone(uint8_t client, uint8_t *buf, uint16_t len, error_t error);
#line 312
enum /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0____nesc_unnamed4275 {





  Msp430UsciUartA0P1__0__ByteTimesPerMillisecond = 5, 






  Msp430UsciUartA0P1__0__ByteTimeScaleFactor = 1
};
#line 355
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__InterruptsRx__interrupted(uint8_t iv);
#line 388
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__InterruptsTx__interrupted(uint8_t iv);
#line 400
static inline const msp430_usci_config_t *
/*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Msp430UsciConfigure__default__getConfiguration(uint8_t client);




static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__ResourceConfigure__configure(uint8_t client);









static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Msp430UsciError__default__condition(uint8_t client, unsigned int errors);
# 39 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__Event__fired(
# 51 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
uint8_t arg_0x2b74e1f81a88);
# 48 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__Timer__overflow(void );
# 126 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static inline void /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__VectorTimerX0__fired(void );




static inline void /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__VectorTimerX1__fired(void );





static inline void /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__Overflow__fired(void );








static inline void /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__Event__default__fired(uint8_t n);
# 39 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Event__fired(
# 51 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
uint8_t arg_0x2b74e1f81a88);
# 48 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static void /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Timer__overflow(void );
# 62 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static uint16_t /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Timer__get(void );
#line 81
static inline bool /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Timer__isOverflowPending(void );
#line 126
static inline void /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__VectorTimerX0__fired(void );




static inline void /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__VectorTimerX1__fired(void );





static inline void /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Overflow__fired(void );








static inline void /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Event__default__fired(uint8_t n);
# 86 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static void /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Capture__captured(uint16_t time);
# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Compare__fired(void );
# 55 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
typedef msp430_compare_control_t /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__cc_t;


static inline /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__cc_t /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__int2CC(uint16_t x)  ;
#line 85
static inline /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__cc_t /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Control__getControl(void );
#line 150
static inline uint16_t /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Capture__getEvent(void );
#line 180
static void /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Event__fired(void );







static inline void /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Capture__default__captured(uint16_t n);



static inline void /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Compare__default__fired(void );



static inline void /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Timer__overflow(void );
# 86 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static void /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Capture__captured(uint16_t time);
# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Compare__fired(void );
# 55 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
typedef msp430_compare_control_t /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__cc_t;


static inline /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__cc_t /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__int2CC(uint16_t x)  ;
#line 85
static inline /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__cc_t /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Control__getControl(void );
#line 150
static inline uint16_t /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Capture__getEvent(void );
#line 180
static void /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Event__fired(void );







static inline void /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Capture__default__captured(uint16_t n);



static inline void /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Compare__default__fired(void );



static inline void /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Timer__overflow(void );
# 86 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static void /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Capture__captured(uint16_t time);
# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Compare__fired(void );
# 55 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
typedef msp430_compare_control_t /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__cc_t;


static inline /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__cc_t /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__int2CC(uint16_t x)  ;
#line 85
static inline /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__cc_t /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Control__getControl(void );
#line 150
static inline uint16_t /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Capture__getEvent(void );
#line 180
static void /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Event__fired(void );







static inline void /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Capture__default__captured(uint16_t n);



static inline void /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Compare__default__fired(void );



static inline void /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Timer__overflow(void );
# 86 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Capture__captured(uint16_t time);
# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Compare__fired(void );
# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static uint16_t /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Timer__get(void );
# 55 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
typedef msp430_compare_control_t /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__cc_t;


static inline /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__cc_t /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__int2CC(uint16_t x)  ;
#line 85
static inline /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__cc_t /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Control__getControl(void );









static inline void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Control__clearPendingInterrupt(void );
#line 130
static inline void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Control__enableEvents(void );




static inline void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Control__disableEvents(void );
#line 150
static inline uint16_t /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Capture__getEvent(void );




static inline void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Compare__setEvent(uint16_t x);









static inline void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Compare__setEventFromNow(uint16_t x);
#line 180
static void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Event__fired(void );







static inline void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Capture__default__captured(uint16_t n);







static inline void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Timer__overflow(void );
# 86 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static void /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Capture__captured(uint16_t time);
# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Compare__fired(void );
# 55 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
typedef msp430_compare_control_t /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__cc_t;


static inline /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__cc_t /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__int2CC(uint16_t x)  ;
#line 85
static inline /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__cc_t /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Control__getControl(void );
#line 150
static inline uint16_t /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Capture__getEvent(void );
#line 180
static void /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Event__fired(void );







static inline void /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Capture__default__captured(uint16_t n);



static inline void /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Compare__default__fired(void );



static inline void /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Timer__overflow(void );
# 86 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
static void /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Capture__captured(uint16_t time);
# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Compare__fired(void );
# 55 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
typedef msp430_compare_control_t /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__cc_t;


static inline /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__cc_t /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__int2CC(uint16_t x)  ;
#line 85
static inline /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__cc_t /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Control__getControl(void );
#line 150
static inline uint16_t /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Capture__getEvent(void );
#line 180
static void /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Event__fired(void );







static inline void /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Capture__default__captured(uint16_t n);



static inline void /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Compare__default__fired(void );



static inline void /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Timer__overflow(void );
# 39 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
static void Msp430TimerCommonP__VectorTimerB1__fired(void );
#line 39
static void Msp430TimerCommonP__VectorTimerA0__fired(void );
#line 39
static void Msp430TimerCommonP__VectorTimerA1__fired(void );
#line 39
static void Msp430TimerCommonP__VectorTimerB0__fired(void );
# 11 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCommonP.nc"
void sig_TIMERA0_VECTOR(void ) __attribute((wakeup)) __attribute((interrupt(0x0012)))  ;
void sig_TIMERA1_VECTOR(void ) __attribute((wakeup)) __attribute((interrupt(0x0010)))  ;
void sig_TIMERB0_VECTOR(void ) __attribute((wakeup)) __attribute((interrupt(0x001A)))  ;
void sig_TIMERB1_VECTOR(void ) __attribute((wakeup)) __attribute((interrupt(0x0018)))  ;
# 41 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Compare__setEvent(uint16_t time);

static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Compare__setEventFromNow(uint16_t delta);
# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static uint16_t /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Timer__get(void );
# 78 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__fired(void );
# 57 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430TimerControl__enableEvents(void );
static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430TimerControl__disableEvents(void );
#line 44
static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430TimerControl__clearPendingInterrupt(void );
# 65 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430AlarmC.nc"
static inline void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__stop(void );




static inline void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Compare__fired(void );










static inline void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__startAt(uint16_t t0, uint16_t dt);
#line 114
static inline void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Timer__overflow(void );
# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
static uint16_t /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__get(void );
static bool /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__isOverflowPending(void );
# 82 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Counter.nc"
static void /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__overflow(void );
# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430CounterC.nc"
static inline uint16_t /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__get(void );




static inline bool /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__isOverflowPending(void );









static inline void /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__overflow(void );
# 64 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Counter.nc"
static /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__size_type /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__get(void );






static bool /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__isOverflowPending(void );










static void /*CounterMilli32C.Transform*/TransformCounterC__0__Counter__overflow(void );
# 67 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/TransformCounterC.nc"
/*CounterMilli32C.Transform*/TransformCounterC__0__upper_count_type /*CounterMilli32C.Transform*/TransformCounterC__0__m_upper;

enum /*CounterMilli32C.Transform*/TransformCounterC__0____nesc_unnamed4276 {

  TransformCounterC__0__LOW_SHIFT_RIGHT = 5, 
  TransformCounterC__0__HIGH_SHIFT_LEFT = 8 * sizeof(/*CounterMilli32C.Transform*/TransformCounterC__0__from_size_type ) - /*CounterMilli32C.Transform*/TransformCounterC__0__LOW_SHIFT_RIGHT, 
  TransformCounterC__0__NUM_UPPER_BITS = 8 * sizeof(/*CounterMilli32C.Transform*/TransformCounterC__0__to_size_type ) - 8 * sizeof(/*CounterMilli32C.Transform*/TransformCounterC__0__from_size_type ) + 5, 



  TransformCounterC__0__OVERFLOW_MASK = /*CounterMilli32C.Transform*/TransformCounterC__0__NUM_UPPER_BITS ? ((/*CounterMilli32C.Transform*/TransformCounterC__0__upper_count_type )2 << (/*CounterMilli32C.Transform*/TransformCounterC__0__NUM_UPPER_BITS - 1)) - 1 : 0
};

static /*CounterMilli32C.Transform*/TransformCounterC__0__to_size_type /*CounterMilli32C.Transform*/TransformCounterC__0__Counter__get(void );
#line 133
static void /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__overflow(void );
# 78 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Alarm.nc"
static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__fired(void );
#line 103
static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__startAt(/*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__size_type t0, /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__size_type dt);
#line 73
static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__stop(void );
# 64 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Counter.nc"
static /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Counter__size_type /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Counter__get(void );
# 77 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
/*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__m_t0;
/*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__m_dt;

enum /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0____nesc_unnamed4277 {

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
# 67 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__postTask(void );
# 109 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Alarm.nc"
static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__getNow(void );
#line 103
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__startAt(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type t0, /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type dt);
#line 116
static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__getAlarm(void );
#line 73
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__stop(void );
# 83 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__fired(void );
# 74 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/AlarmToTimerC.nc"
enum /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0____nesc_unnamed4278 {
#line 74
  AlarmToTimerC__0__fired = 1U
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
# 67 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer__postTask(void );
# 136 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Timer.nc"
static uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__getNow(void );
#line 129
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__startOneShotAt(uint32_t t0, uint32_t dt);
#line 78
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__stop(void );




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__fired(
# 48 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x2b74e213d5d8);
#line 71
enum /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0____nesc_unnamed4279 {
#line 71
  VirtualizeTimerC__0__updateFromTimer = 2U
};
#line 71
typedef int /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0____nesc_sillytask_updateFromTimer[/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__updateFromTimer];
#line 53
enum /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0____nesc_unnamed4280 {

  VirtualizeTimerC__0__NUM_TIMERS = 0U, 
  VirtualizeTimerC__0__END_OF_LIST = 255
};








#line 59
typedef struct /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0____nesc_unnamed4281 {

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
# 58 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/CounterToLocalTimeC.nc"
static inline void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__Counter__overflow(void );
# 62 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Init.nc"
static error_t RealMainP__SoftwareInit__init(void );
# 60 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Boot.nc"
static void RealMainP__Boot__booted(void );
# 62 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Init.nc"
static error_t RealMainP__PlatformInit__init(void );
# 57 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Scheduler.nc"
static void RealMainP__Scheduler__init(void );
#line 72
static void RealMainP__Scheduler__taskLoop(void );
#line 65
static bool RealMainP__Scheduler__runNextTask(void );
# 63 "/home/carlson/local/src/tinyos-2.x/tos/system/RealMainP.nc"
int main(void )   ;
# 75 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void SchedulerBasicP__TaskBasic__runTask(
# 56 "/home/carlson/local/src/tinyos-2.x/tos/system/SchedulerBasicP.nc"
uint8_t arg_0x2b74e1a47ae8);
# 76 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/McuSleep.nc"
static void SchedulerBasicP__McuSleep__sleep(void );
# 61 "/home/carlson/local/src/tinyos-2.x/tos/system/SchedulerBasicP.nc"
enum SchedulerBasicP____nesc_unnamed4282 {

  SchedulerBasicP__NUM_TASKS = 9U, 
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
# 62 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/McuPowerOverride.nc"
static mcu_power_t McuSleepC__McuPowerOverride__lowestState(void );
# 53 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/lpm/McuSleepC.nc"
bool McuSleepC__dirty = TRUE;
mcu_power_t McuSleepC__powerState = MSP430_POWER_ACTIVE;




const uint16_t McuSleepC__msp430PowerBits[MSP430_POWER_LPM4 + 1] = { 
0, 
0x0010, 
0x0040 + 0x0010, 
0x0080 + 0x0010, 
0x0080 + 0x0040 + 0x0010, 
0x0080 + 0x0040 + 0x0020 + 0x0010 };


static inline mcu_power_t McuSleepC__getPowerState(void );
#line 162
static inline void McuSleepC__computePowerState(void );




static inline void McuSleepC__McuSleep__sleep(void );
#line 184
static inline mcu_power_t McuSleepC__McuPowerOverride__default__lowestState(void );
# 67 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t ToastC__slaveStartTask__postTask(void );
#line 67
static error_t ToastC__slaveReceiveTask__postTask(void );
# 76 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/I2CPacket.nc"
static error_t ToastC__I2CBasicAddr__read(i2c_flags_t flags, uint16_t addr, uint8_t length, 
#line 71
uint8_t * data);
#line 56
static error_t ToastC__I2CBasicAddr__setOwnAddress(uint16_t addr);
#line 93
static error_t ToastC__I2CBasicAddr__write(i2c_flags_t flags, uint16_t addr, uint8_t length, 
#line 88
uint8_t * data);
#line 123
static error_t ToastC__I2CBasicAddr__enableSlave(void );
# 48 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/UartStream.nc"
static error_t ToastC__UartStream__send(
#line 44
uint8_t * buf, 



uint16_t len);
# 67 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t ToastC__StdOutTask__postTask(void );
# 88 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Resource.nc"
static error_t ToastC__I2CResource__request(void );
# 67 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t ToastC__slaveStopTask__postTask(void );
# 95 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/StdControl.nc"
static error_t ToastC__UartControl__start(void );
# 67 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static error_t ToastC__transmitTask__postTask(void );
#line 67
static error_t ToastC__slaveTransmitTask__postTask(void );
# 24 "ToastC.nc"
enum ToastC____nesc_unnamed4283 {
#line 24
  ToastC__transmitTask = 3U
};
#line 24
typedef int ToastC____nesc_sillytask_transmitTask[ToastC__transmitTask];
#line 105
enum ToastC____nesc_unnamed4284 {
#line 105
  ToastC__slaveReceiveTask = 4U
};
#line 105
typedef int ToastC____nesc_sillytask_slaveReceiveTask[ToastC__slaveReceiveTask];




enum ToastC____nesc_unnamed4285 {
#line 110
  ToastC__slaveTransmitTask = 5U
};
#line 110
typedef int ToastC____nesc_sillytask_slaveTransmitTask[ToastC__slaveTransmitTask];




enum ToastC____nesc_unnamed4286 {
#line 115
  ToastC__slaveStartTask = 6U
};
#line 115
typedef int ToastC____nesc_sillytask_slaveStartTask[ToastC__slaveStartTask];




enum ToastC____nesc_unnamed4287 {
#line 120
  ToastC__slaveStopTask = 7U
};
#line 120
typedef int ToastC____nesc_sillytask_slaveStopTask[ToastC__slaveStopTask];
#line 170
enum ToastC____nesc_unnamed4288 {
#line 170
  ToastC__StdOutTask = 8U
};
#line 170
typedef int ToastC____nesc_sillytask_StdOutTask[ToastC__StdOutTask];
#line 21
uint8_t ToastC__welcome_string[23] = "I2C Test Application\n\r";


static inline void ToastC__transmitTask__runTask(void );




static inline void ToastC__Boot__booted(void );
#line 72
uint8_t ToastC__str_i2c_read_fail_nl[16] = "I2C read fail\n\r";
uint8_t ToastC__i2c_length;
uint8_t ToastC__i2c_buffer[100];

static inline void ToastC__I2CBasicAddr__readDone(error_t error, uint16_t addr, uint8_t length, uint8_t *data);










uint8_t ToastC__str_i2c_write_done_nl[17] = "I2C write done\n\r";
uint8_t ToastC__str_i2c_write_fail_nl[17] = "I2C write fail\n\r";

static inline void ToastC__I2CBasicAddr__writeDone(error_t error, uint16_t addr, uint8_t length, uint8_t *data);









uint8_t ToastC__str_i2c_slave_receive_nl[20] = "I2C slave receive\n\r";
uint8_t ToastC__str_i2c_slave_transmit_nl[21] = "I2C slave transmit\n\r";
uint8_t ToastC__str_i2c_slave_start_nl[18] = "I2C slave start\n\r";
uint8_t ToastC__str_i2c_slave_stop_nl[17] = "I2C slave stop\n\r";

static inline void ToastC__slaveReceiveTask__runTask(void );




static inline void ToastC__slaveTransmitTask__runTask(void );




static inline void ToastC__slaveStartTask__runTask(void );




static inline void ToastC__slaveStopTask__runTask(void );




static inline error_t ToastC__I2CBasicAddr__slaveReceive(uint8_t data);








uint8_t ToastC__counter;

static inline uint8_t ToastC__I2CBasicAddr__slaveTransmit(void );






static inline void ToastC__I2CBasicAddr__slaveStart(void );




static inline void ToastC__I2CBasicAddr__slaveStop(void );









static inline void ToastC__UartStream__sendDone(uint8_t *buf, uint16_t len, error_t error);




static inline void ToastC__UartStream__receiveDone(uint8_t *buf, uint16_t len, error_t error);




uint8_t ToastC__tmpchar;

static inline void ToastC__StdOutTask__runTask(void );
#line 212
static inline void ToastC__UartStream__receivedByte(uint8_t byte);
# 85 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void Msp430I2CP__SDA__makeOutput(void );






static void Msp430I2CP__SDA__selectModuleFunc(void );
# 160 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/I2CPacket.nc"
static void Msp430I2CP__I2CBasicAddr__slaveStop(void );
#line 114
static void Msp430I2CP__I2CBasicAddr__writeDone(error_t error, uint16_t addr, uint8_t length, 
#line 110
uint8_t * data);
#line 148
static 
#line 146
uint8_t 

Msp430I2CP__I2CBasicAddr__slaveTransmit(void );





static void Msp430I2CP__I2CBasicAddr__slaveStart(void );
#line 141
static error_t Msp430I2CP__I2CBasicAddr__slaveReceive(
#line 137
uint8_t data);
#line 103
static void Msp430I2CP__I2CBasicAddr__readDone(error_t error, uint16_t addr, uint8_t length, 
#line 100
uint8_t * data);
# 85 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
static void Msp430I2CP__SCL__makeOutput(void );






static void Msp430I2CP__SCL__selectModuleFunc(void );
# 63 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430I2CP.nc"
static volatile uint8_t Msp430I2CP__IE2 __asm ("0x0001");

volatile unsigned char Msp430I2CP__UCB0CTL0 __asm ("0x0068");
volatile unsigned char Msp430I2CP__UCB0CTL1 __asm ("0x0069");
volatile unsigned char Msp430I2CP__UCB0BR0 __asm ("0x006A");
volatile unsigned char Msp430I2CP__UCB0BR1 __asm ("0x006B");
volatile unsigned char Msp430I2CP__UCB0TXBUF __asm ("0x006F");
volatile unsigned char Msp430I2CP__UCB0I2COA __asm ("0x0118");
volatile unsigned char Msp430I2CP__UCB0I2CSA __asm ("0x011A");

volatile unsigned char Msp430I2CP__UCB0I2CIE __asm ("0x006C");

enum Msp430I2CP____nesc_unnamed4289 {
  Msp430I2CP__TIMEOUT = 64
};

uint8_t *Msp430I2CP__m_buf;
uint8_t Msp430I2CP__m_len;
uint8_t Msp430I2CP__m_pos;
i2c_flags_t Msp430I2CP__m_flags;
uint16_t Msp430I2CP__m_ownaddress = 0x0000;

static inline void Msp430I2CP__resetUCB0(void );
static void Msp430I2CP__nextRead(void );
static void Msp430I2CP__nextWrite(void );







static inline error_t Msp430I2CP__Resource__request(uint8_t id);
#line 135
static inline error_t Msp430I2CP__I2CBasicAddr__setOwnAddress(uint16_t addr);






static inline error_t Msp430I2CP__I2CBasicAddr__enableSlave(void );
#line 202
static inline error_t Msp430I2CP__I2CBasicAddr__read(i2c_flags_t flags, 
uint16_t addr, uint8_t len, 
uint8_t *buf);
#line 305
static void Msp430I2CP__nextRead(void );
#line 337
static inline error_t Msp430I2CP__I2CBasicAddr__write(i2c_flags_t flags, 
uint16_t addr, uint8_t len, 
uint8_t *buf);
#line 414
static void Msp430I2CP__nextWrite(void );
#line 448
static inline void Msp430I2CP__InterruptsTx__interrupted(uint8_t iv);








static inline void Msp430I2CP__InterruptsRx__interrupted(uint8_t iv);
#line 469
static inline void Msp430I2CP__InterruptsState__interrupted(uint8_t iv);
#line 513
static inline void Msp430I2CP__resetUCB0(void );
# 97 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Resource.nc"
static error_t PlatformSerialP__Resource__immediateRequest(void );
# 51 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/PlatformSerialP.nc"
static inline error_t PlatformSerialP__StdControl__start(void );







static inline void PlatformSerialP__Resource__granted(void );
# 397 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430hardware.h"
static inline  void __nesc_enable_interrupt(void )
{
  __eint();
}

# 67 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t ToastC__StdOutTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(ToastC__StdOutTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 212 "ToastC.nc"
static inline void ToastC__UartStream__receivedByte(uint8_t byte)
{
  ToastC__tmpchar = byte;

  ToastC__StdOutTask__postTask();
}

# 268 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__default__receivedByte(uint8_t client, uint8_t byte)
#line 268
{
}

# 79 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/UartStream.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__receivedByte(uint8_t arg_0x2b74e1e85710, uint8_t byte){
#line 79
  switch (arg_0x2b74e1e85710) {
#line 79
    case /*PlatformSerialC.UartC*/Msp430UsciUartA0C__0__CLIENT_ID:
#line 79
      ToastC__UartStream__receivedByte(byte);
#line 79
      break;
#line 79
    default:
#line 79
      /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__default__receivedByte(arg_0x2b74e1e85710, byte);
#line 79
      break;
#line 79
    }
#line 79
}
#line 79
# 163 "ToastC.nc"
static inline void ToastC__UartStream__receiveDone(uint8_t *buf, uint16_t len, error_t error)
{
  return;
}

# 290 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__default__receiveDone(uint8_t client, uint8_t *buf, uint16_t len, error_t error)
#line 290
{
}

# 99 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/UartStream.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__receiveDone(uint8_t arg_0x2b74e1e85710, uint8_t * buf, uint16_t len, error_t error){
#line 99
  switch (arg_0x2b74e1e85710) {
#line 99
    case /*PlatformSerialC.UartC*/Msp430UsciUartA0C__0__CLIENT_ID:
#line 99
      ToastC__UartStream__receiveDone(buf, len, error);
#line 99
      break;
#line 99
    default:
#line 99
      /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__default__receiveDone(arg_0x2b74e1e85710, buf, len, error);
#line 99
      break;
#line 99
    }
#line 99
}
#line 99
# 416 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Msp430UsciError__default__condition(uint8_t client, unsigned int errors)
#line 416
{
}

# 42 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciError.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Msp430UsciError__condition(uint8_t arg_0x2b74e1e82670, unsigned int errors){
#line 42
    /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Msp430UsciError__default__condition(arg_0x2b74e1e82670, errors);
#line 42
}
#line 42
# 127 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/HplMsp430UsciA0P.nc"
static inline uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__getStat(void )
#line 127
{
#line 127
  return UCA0STAT;
}

# 111 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static uint8_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__getStat(void ){
#line 111
  unsigned char __nesc_result;
#line 111

#line 111
  __nesc_result = /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__getStat();
#line 111

#line 111
  return __nesc_result;
#line 111
}
#line 111
# 129 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/HplMsp430UsciA0P.nc"
static inline uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__getRxbuf(void )
#line 129
{
#line 129
  return UCA0RXBUF;
}

# 123 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static uint8_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__getRxbuf(void ){
#line 123
  unsigned char __nesc_result;
#line 123

#line 123
  __nesc_result = /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__getRxbuf();
#line 123

#line 123
  return __nesc_result;
#line 123
}
#line 123
# 98 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
inline static uint8_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__ArbiterInfo__userId(void ){
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
# 355 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__InterruptsRx__interrupted(uint8_t iv)
#line 355
{
  uint8_t current_client = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__ArbiterInfo__userId();

#line 357
  if (0xFF == current_client) {
      return;
    }
  if (iv & 0x01) {
      uint8_t stat = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__getStat();
      uint8_t data = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__getRxbuf();






      stat = MSP430_USCI_ERR_UCxySTAT & (stat | /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__getStat());
      if (stat) {
          /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Msp430UsciError__condition(current_client, stat);
        }
      if (/*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_rx_buf) {
          /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_rx_buf[/*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_rx_pos++] = data;
          if (/*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_rx_len == /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_rx_pos) {
              uint8_t *rx_buf = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_rx_buf;
              uint16_t rx_len = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_rx_len;

#line 378
              /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_rx_buf = 0;
              /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__receiveDone(current_client, rx_buf, rx_len, SUCCESS);
            }
        }
      else 
#line 381
        {
          /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__receivedByte(current_client, data);
        }
    }
}

# 261 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/HplMsp430UsciA0P.nc"
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__InterruptsRx__default__interrupted(uint8_t mode, uint8_t iv)
#line 261
{
}

# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
inline static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__InterruptsRx__interrupted(uint8_t arg_0x2b74e1d3f0c8, uint8_t iv){
#line 49
  switch (arg_0x2b74e1d3f0c8) {
#line 49
    case MSP430_USCI_UART:
#line 49
      /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__InterruptsRx__interrupted(iv);
#line 49
      break;
#line 49
    default:
#line 49
      /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__InterruptsRx__default__interrupted(arg_0x2b74e1d3f0c8, iv);
#line 49
      break;
#line 49
    }
#line 49
}
#line 49
# 90 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/ArbiterInfo.nc"
inline static bool /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__ArbiterInfo__inUse(void ){
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
# 247 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/HplMsp430UsciA0P.nc"
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__RawInterruptsRx__interrupted(uint8_t iv)
{
  if (/*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__ArbiterInfo__inUse()) {
      /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__InterruptsRx__interrupted(/*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__currentMode(), iv);
    }
}

# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
inline static void HplMsp430UsciInterruptsAB0P__InterruptsUCA0Rx__interrupted(uint8_t iv){
#line 49
  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__RawInterruptsRx__interrupted(iv);
#line 49
}
#line 49
# 97 "/home/carlson/local/src/tinyos-2.x/tos/system/SchedulerBasicP.nc"
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

# 67 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t ToastC__slaveStartTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(ToastC__slaveStartTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 143 "ToastC.nc"
static inline void ToastC__I2CBasicAddr__slaveStart(void )
{
  ToastC__slaveStartTask__postTask();
}

# 154 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/I2CPacket.nc"
inline static void Msp430I2CP__I2CBasicAddr__slaveStart(void ){
#line 154
  ToastC__I2CBasicAddr__slaveStart();
#line 154
}
#line 154
# 67 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t ToastC__slaveStopTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(ToastC__slaveStopTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 148 "ToastC.nc"
static inline void ToastC__I2CBasicAddr__slaveStop(void )
{
  ToastC__slaveStopTask__postTask();
}

# 160 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/I2CPacket.nc"
inline static void Msp430I2CP__I2CBasicAddr__slaveStop(void ){
#line 160
  ToastC__I2CBasicAddr__slaveStop();
#line 160
}
#line 160
# 48 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/UartStream.nc"
inline static error_t ToastC__UartStream__send(uint8_t * buf, uint16_t len){
#line 48
  unsigned char __nesc_result;
#line 48

#line 48
  __nesc_result = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__send(/*PlatformSerialC.UartC*/Msp430UsciUartA0C__0__CLIENT_ID, buf, len);
#line 48

#line 48
  return __nesc_result;
#line 48
}
#line 48
# 90 "ToastC.nc"
static inline void ToastC__I2CBasicAddr__writeDone(error_t error, uint16_t addr, uint8_t length, uint8_t *data)
{
  if (error == SUCCESS) 
    {
      ToastC__UartStream__send(ToastC__str_i2c_write_done_nl, 16);
    }
  else 
#line 95
    {
      ToastC__UartStream__send(ToastC__str_i2c_write_fail_nl, 16);
    }
}

# 114 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/I2CPacket.nc"
inline static void Msp430I2CP__I2CBasicAddr__writeDone(error_t error, uint16_t addr, uint8_t length, uint8_t * data){
#line 114
  ToastC__I2CBasicAddr__writeDone(error, addr, length, data);
#line 114
}
#line 114
# 513 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430I2CP.nc"
static inline void Msp430I2CP__resetUCB0(void )
{







  Msp430I2CP__UCB0CTL1 = 0x01;
}

#line 469
static inline void Msp430I2CP__InterruptsState__interrupted(uint8_t iv)
{
  uint8_t counter = 0xFF;


  if (UCB0STAT & 0x08) 
    {

      Msp430I2CP__UCB0CTL1 |= 0x04;


      while (Msp430I2CP__UCB0CTL1 & 0x04 && counter > 0x01) 
        counter--;

      Msp430I2CP__resetUCB0();
      Msp430I2CP__I2CBasicAddr__writeDone(ENOACK, Msp430I2CP__UCB0I2CSA, Msp430I2CP__m_len, Msp430I2CP__m_buf);
    }
  else {
    if (UCB0STAT & 0x01) 
      {
        Msp430I2CP__resetUCB0();
        Msp430I2CP__I2CBasicAddr__writeDone(EBUSY, Msp430I2CP__UCB0I2CSA, Msp430I2CP__m_len, Msp430I2CP__m_buf);
      }
    else {
      if (UCB0STAT & 0x04) 
        {

          Msp430I2CP__UCB0I2CIE &= ~0x04;
          Msp430I2CP__UCB0I2CIE |= 0x02;

          Msp430I2CP__I2CBasicAddr__slaveStop();
        }
      else {
        if (UCB0STAT & 0x02) 
          {

            Msp430I2CP__UCB0I2CIE &= ~0x02;
            Msp430I2CP__UCB0I2CIE |= 0x04;

            Msp430I2CP__I2CBasicAddr__slaveStart();
          }
        }
      }
    }
}

# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
inline static void HplMsp430UsciInterruptsAB0P__InterruptsUCB0State__interrupted(uint8_t iv){
#line 49
  Msp430I2CP__InterruptsState__interrupted(iv);
#line 49
}
#line 49
# 112 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
static inline error_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__checkIsOwner(uint8_t client)
{

  const uint8_t current_client = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__ArbiterInfo__userId();

#line 116
  if (0xFF == current_client) {
      return EOFF;
    }
  if (current_client != client) {
      return EBUSY;
    }
  return SUCCESS;
}

#line 102
static inline bool /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__isBusy(void )
{
  while (0x01 & /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__getStat()) {
      ;
    }
  return 0 != /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_tx_buf || 0 != /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_rx_buf;
}

# 158 "ToastC.nc"
static inline void ToastC__UartStream__sendDone(uint8_t *buf, uint16_t len, error_t error)
{
  return;
}

# 227 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__default__sendDone(uint8_t client, uint8_t *buf, uint16_t len, error_t error)
#line 227
{
}

# 57 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/UartStream.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__sendDone(uint8_t arg_0x2b74e1e85710, uint8_t * buf, uint16_t len, error_t error){
#line 57
  switch (arg_0x2b74e1e85710) {
#line 57
    case /*PlatformSerialC.UartC*/Msp430UsciUartA0C__0__CLIENT_ID:
#line 57
      ToastC__UartStream__sendDone(buf, len, error);
#line 57
      break;
#line 57
    default:
#line 57
      /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__default__sendDone(arg_0x2b74e1e85710, buf, len, error);
#line 57
      break;
#line 57
    }
#line 57
}
#line 57
# 136 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/HplMsp430UsciA0P.nc"
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__setTxbuf(uint8_t v)
#line 136
{
#line 136
  UCA0TXBUF = v;
}

# 141 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__setTxbuf(uint8_t v){
#line 141
  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__setTxbuf(v);
#line 141
}
#line 141
# 176 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/HplMsp430UsciA0P.nc"
static inline uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__getIe(void )
#line 176
{
#line 176
  return /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__IE2;
}

# 231 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static uint8_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__getIe(void ){
#line 231
  unsigned char __nesc_result;
#line 231

#line 231
  __nesc_result = /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__getIe();
#line 231

#line 231
  return __nesc_result;
#line 231
}
#line 231
# 177 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/HplMsp430UsciA0P.nc"
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__setIe(uint8_t v)
#line 177
{
#line 177
  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__IE2 = v;
}

# 237 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__setIe(uint8_t v){
#line 237
  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__setIe(v);
#line 237
}
#line 237
# 181 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__nextStreamTransmit(uint8_t client)
{
  /* atomic removed: atomic calls only */
#line 183
  {
    uint8_t ch = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_tx_buf[/*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_tx_pos++];
    bool last_char = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_tx_pos == /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_tx_len;

    if (last_char) {



        /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__setIe(/*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__getIe() & ~0x02);
      }
    /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__setTxbuf(ch);



    if (last_char) {
        uint8_t *tx_buf = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_tx_buf;
        uint16_t tx_len = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_tx_len;

#line 200
        /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_tx_buf = 0;
        /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__sendDone(client, tx_buf, tx_len, SUCCESS);
      }
  }
}

#line 388
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__InterruptsTx__interrupted(uint8_t iv)
{
  uint8_t current_client = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__ArbiterInfo__userId();

#line 391
  if (0xFF == current_client) {
      return;
    }

  if (iv & 0x02) {
      /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__nextStreamTransmit(current_client);
    }
}

# 262 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/HplMsp430UsciA0P.nc"
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__InterruptsTx__default__interrupted(uint8_t mode, uint8_t iv)
#line 262
{
}

# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
inline static void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__InterruptsTx__interrupted(uint8_t arg_0x2b74e1d3fd10, uint8_t iv){
#line 49
  switch (arg_0x2b74e1d3fd10) {
#line 49
    case MSP430_USCI_UART:
#line 49
      /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__InterruptsTx__interrupted(iv);
#line 49
      break;
#line 49
    default:
#line 49
      /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__InterruptsTx__default__interrupted(arg_0x2b74e1d3fd10, iv);
#line 49
      break;
#line 49
    }
#line 49
}
#line 49
# 254 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/HplMsp430UsciA0P.nc"
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__RawInterruptsTx__interrupted(uint8_t iv)
{
  if (/*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__ArbiterInfo__inUse()) {
      /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__InterruptsTx__interrupted(/*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__currentMode(), iv);
    }
}

# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
inline static void HplMsp430UsciInterruptsAB0P__InterruptsUCA0Tx__interrupted(uint8_t iv){
#line 49
  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__RawInterruptsTx__interrupted(iv);
#line 49
}
#line 49
# 67 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t ToastC__slaveReceiveTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(ToastC__slaveReceiveTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 125 "ToastC.nc"
static inline error_t ToastC__I2CBasicAddr__slaveReceive(uint8_t data)
{
  ToastC__UartStream__send(&data, 1);

  ToastC__slaveReceiveTask__postTask();

  return SUCCESS;
}

# 141 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/I2CPacket.nc"
inline static error_t Msp430I2CP__I2CBasicAddr__slaveReceive(uint8_t data){
#line 141
  unsigned char __nesc_result;
#line 141

#line 141
  __nesc_result = ToastC__I2CBasicAddr__slaveReceive(data);
#line 141

#line 141
  return __nesc_result;
#line 141
}
#line 141
# 457 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430I2CP.nc"
static inline void Msp430I2CP__InterruptsRx__interrupted(uint8_t iv)
{

  if (Msp430I2CP__UCB0CTL0 & 0x08) {
    Msp430I2CP__nextRead();
    }
  else {
      if (Msp430I2CP__I2CBasicAddr__slaveReceive(UCB0RXBUF) != SUCCESS) {
        Msp430I2CP__UCB0CTL1 |= 0x08;
        }
    }
}

# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
inline static void HplMsp430UsciInterruptsAB0P__InterruptsUCB0Rx__interrupted(uint8_t iv){
#line 49
  Msp430I2CP__InterruptsRx__interrupted(iv);
#line 49
}
#line 49
# 76 "ToastC.nc"
static inline void ToastC__I2CBasicAddr__readDone(error_t error, uint16_t addr, uint8_t length, uint8_t *data)
{
  if (error == SUCCESS) 
    {

      ToastC__UartStream__send(data, length);
    }
  else 
#line 82
    {
      ToastC__UartStream__send(ToastC__str_i2c_read_fail_nl, 15);
    }
}

# 103 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/I2CPacket.nc"
inline static void Msp430I2CP__I2CBasicAddr__readDone(error_t error, uint16_t addr, uint8_t length, uint8_t * data){
#line 103
  ToastC__I2CBasicAddr__readDone(error, addr, length, data);
#line 103
}
#line 103
# 67 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t ToastC__slaveTransmitTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(ToastC__slaveTransmitTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 136 "ToastC.nc"
static inline uint8_t ToastC__I2CBasicAddr__slaveTransmit(void )
{
  ToastC__slaveTransmitTask__postTask();

  return ToastC__counter++;
}

# 148 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/I2CPacket.nc"
inline static uint8_t Msp430I2CP__I2CBasicAddr__slaveTransmit(void ){
#line 148
  unsigned char __nesc_result;
#line 148

#line 148
  __nesc_result = ToastC__I2CBasicAddr__slaveTransmit();
#line 148

#line 148
  return __nesc_result;
#line 148
}
#line 148
# 448 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430I2CP.nc"
static inline void Msp430I2CP__InterruptsTx__interrupted(uint8_t iv)
{

  if (Msp430I2CP__UCB0CTL0 & 0x08) {
    Msp430I2CP__nextWrite();
    }
  else {
#line 454
    Msp430I2CP__UCB0TXBUF = Msp430I2CP__I2CBasicAddr__slaveTransmit();
    }
}

# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430UsciInterrupts.nc"
inline static void HplMsp430UsciInterruptsAB0P__InterruptsUCB0Tx__interrupted(uint8_t iv){
#line 49
  Msp430I2CP__InterruptsTx__interrupted(iv);
#line 49
}
#line 49
# 196 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline void /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Timer__overflow(void )
{
}

#line 196
static inline void /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Timer__overflow(void )
{
}

#line 196
static inline void /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Timer__overflow(void )
{
}

# 48 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
inline static void /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__Timer__overflow(void ){
#line 48
  /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Timer__overflow();
#line 48
  /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Timer__overflow();
#line 48
  /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Timer__overflow();
#line 48
}
#line 48
# 137 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static inline void /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__Overflow__fired(void )
{
  /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__Timer__overflow();
}





static inline void /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__Event__default__fired(uint8_t n)
{
}

# 39 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
inline static void /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__Event__fired(uint8_t arg_0x2b74e1f81a88){
#line 39
  switch (arg_0x2b74e1f81a88) {
#line 39
    case 0:
#line 39
      /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Event__fired();
#line 39
      break;
#line 39
    case 1:
#line 39
      /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Event__fired();
#line 39
      break;
#line 39
    case 2:
#line 39
      /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Event__fired();
#line 39
      break;
#line 39
    case 5:
#line 39
      /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__Overflow__fired();
#line 39
      break;
#line 39
    default:
#line 39
      /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__Event__default__fired(arg_0x2b74e1f81a88);
#line 39
      break;
#line 39
    }
#line 39
}
#line 39
# 126 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static inline void /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__VectorTimerX0__fired(void )
{
  /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__Event__fired(0);
}

# 39 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
inline static void Msp430TimerCommonP__VectorTimerA0__fired(void ){
#line 39
  /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__VectorTimerX0__fired();
#line 39
}
#line 39
# 58 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline  /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__cc_t /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__int2CC(uint16_t x)
#line 58
{
#line 58
  union /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0____nesc_unnamed4290 {
#line 58
    uint16_t f;
#line 58
    /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__cc_t t;
  } 
#line 58
  c = { .f = x };

#line 58
  return c.t;
}

#line 85
static inline /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__cc_t /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Control__getControl(void )
{
  return /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__int2CC(* (volatile uint16_t * )354U);
}

#line 188
static inline void /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Capture__default__captured(uint16_t n)
{
}

# 86 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
inline static void /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Capture__captured(uint16_t time){
#line 86
  /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Capture__default__captured(time);
#line 86
}
#line 86
# 150 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline uint16_t /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Capture__getEvent(void )
{
  return * (volatile uint16_t * )370U;
}

#line 192
static inline void /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Compare__default__fired(void )
{
}

# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Compare__fired(void ){
#line 45
  /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Compare__default__fired();
#line 45
}
#line 45
# 58 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline  /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__cc_t /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__int2CC(uint16_t x)
#line 58
{
#line 58
  union /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1____nesc_unnamed4291 {
#line 58
    uint16_t f;
#line 58
    /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__cc_t t;
  } 
#line 58
  c = { .f = x };

#line 58
  return c.t;
}

#line 85
static inline /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__cc_t /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Control__getControl(void )
{
  return /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__int2CC(* (volatile uint16_t * )356U);
}

#line 188
static inline void /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Capture__default__captured(uint16_t n)
{
}

# 86 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
inline static void /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Capture__captured(uint16_t time){
#line 86
  /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Capture__default__captured(time);
#line 86
}
#line 86
# 150 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline uint16_t /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Capture__getEvent(void )
{
  return * (volatile uint16_t * )372U;
}

#line 192
static inline void /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Compare__default__fired(void )
{
}

# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Compare__fired(void ){
#line 45
  /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Compare__default__fired();
#line 45
}
#line 45
# 58 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline  /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__cc_t /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__int2CC(uint16_t x)
#line 58
{
#line 58
  union /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2____nesc_unnamed4292 {
#line 58
    uint16_t f;
#line 58
    /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__cc_t t;
  } 
#line 58
  c = { .f = x };

#line 58
  return c.t;
}

#line 85
static inline /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__cc_t /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Control__getControl(void )
{
  return /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__int2CC(* (volatile uint16_t * )358U);
}

#line 188
static inline void /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Capture__default__captured(uint16_t n)
{
}

# 86 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
inline static void /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Capture__captured(uint16_t time){
#line 86
  /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Capture__default__captured(time);
#line 86
}
#line 86
# 150 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline uint16_t /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Capture__getEvent(void )
{
  return * (volatile uint16_t * )374U;
}

#line 192
static inline void /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Compare__default__fired(void )
{
}

# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Compare__fired(void ){
#line 45
  /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Compare__default__fired();
#line 45
}
#line 45
# 131 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static inline void /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__VectorTimerX1__fired(void )
{
  uint8_t n = * (volatile uint16_t * )302U;

#line 134
  /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__Event__fired(n >> 1);
}

# 39 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
inline static void Msp430TimerCommonP__VectorTimerA1__fired(void ){
#line 39
  /*Msp430TimerC.Msp430TimerA*/Msp430TimerP__0__VectorTimerX1__fired();
#line 39
}
#line 39
# 196 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline void /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Timer__overflow(void )
{
}

#line 196
static inline void /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Timer__overflow(void )
{
}

#line 196
static inline void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Timer__overflow(void )
{
}

# 114 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430AlarmC.nc"
static inline void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Timer__overflow(void )
{
}

# 82 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Counter.nc"
inline static void /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__overflow(void ){
#line 82
  /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__overflow();
#line 82
}
#line 82
# 64 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430CounterC.nc"
static inline void /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__overflow(void )
{
  /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__overflow();
}

# 48 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
inline static void /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Timer__overflow(void ){
#line 48
  /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__overflow();
#line 48
  /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Timer__overflow();
#line 48
  /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Timer__overflow();
#line 48
  /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Timer__overflow();
#line 48
  /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Timer__overflow();
#line 48
}
#line 48
# 137 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static inline void /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Overflow__fired(void )
{
  /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Timer__overflow();
}





static inline void /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Event__default__fired(uint8_t n)
{
}

# 39 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
inline static void /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Event__fired(uint8_t arg_0x2b74e1f81a88){
#line 39
  switch (arg_0x2b74e1f81a88) {
#line 39
    case 0:
#line 39
      /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Event__fired();
#line 39
      break;
#line 39
    case 1:
#line 39
      /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Event__fired();
#line 39
      break;
#line 39
    case 2:
#line 39
      /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Event__fired();
#line 39
      break;
#line 39
    case 7:
#line 39
      /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Overflow__fired();
#line 39
      break;
#line 39
    default:
#line 39
      /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Event__default__fired(arg_0x2b74e1f81a88);
#line 39
      break;
#line 39
    }
#line 39
}
#line 39
# 126 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static inline void /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__VectorTimerX0__fired(void )
{
  /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Event__fired(0);
}

# 39 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
inline static void Msp430TimerCommonP__VectorTimerB0__fired(void ){
#line 39
  /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__VectorTimerX0__fired();
#line 39
}
#line 39
# 58 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/CounterToLocalTimeC.nc"
static inline void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__Counter__overflow(void )
{
}

# 177 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static inline void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Counter__overflow(void )
{
}

# 82 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Counter.nc"
inline static void /*CounterMilli32C.Transform*/TransformCounterC__0__Counter__overflow(void ){
#line 82
  /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Counter__overflow();
#line 82
  /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC__0__Counter__overflow();
#line 82
}
#line 82
# 58 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline  /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__cc_t /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__int2CC(uint16_t x)
#line 58
{
#line 58
  union /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3____nesc_unnamed4293 {
#line 58
    uint16_t f;
#line 58
    /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__cc_t t;
  } 
#line 58
  c = { .f = x };

#line 58
  return c.t;
}

#line 85
static inline /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__cc_t /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Control__getControl(void )
{
  return /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__int2CC(* (volatile uint16_t * )386U);
}

#line 188
static inline void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Capture__default__captured(uint16_t n)
{
}

# 86 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
inline static void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Capture__captured(uint16_t time){
#line 86
  /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Capture__default__captured(time);
#line 86
}
#line 86
# 150 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline uint16_t /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Capture__getEvent(void )
{
  return * (volatile uint16_t * )402U;
}

# 67 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
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
# 81 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__fired(void )
{
#line 82
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__postTask();
}

# 78 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__fired(void ){
#line 78
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__fired();
#line 78
}
#line 78
# 162 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
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

# 78 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__fired(void ){
#line 78
  /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__fired();
#line 78
}
#line 78
# 135 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Control__disableEvents(void )
{
  * (volatile uint16_t * )386U &= ~0x0010;
}

# 58 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
inline static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430TimerControl__disableEvents(void ){
#line 58
  /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Control__disableEvents();
#line 58
}
#line 58
# 70 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430AlarmC.nc"
static inline void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Compare__fired(void )
{
  /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430TimerControl__disableEvents();
  /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__fired();
}

# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Compare__fired(void ){
#line 45
  /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Compare__fired();
#line 45
}
#line 45
# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
inline static uint16_t /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__get(void ){
#line 45
  unsigned int __nesc_result;
#line 45

#line 45
  __nesc_result = /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Timer__get();
#line 45

#line 45
  return __nesc_result;
#line 45
}
#line 45
# 49 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430CounterC.nc"
static inline uint16_t /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__get(void )
{
  return /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__get();
}

# 64 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Counter.nc"
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
# 81 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static inline bool /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Timer__isOverflowPending(void )
{
  return * (volatile uint16_t * )384U & 1U;
}

# 46 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
inline static bool /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__isOverflowPending(void ){
#line 46
  unsigned char __nesc_result;
#line 46

#line 46
  __nesc_result = /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Timer__isOverflowPending();
#line 46

#line 46
  return __nesc_result;
#line 46
}
#line 46
# 54 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430CounterC.nc"
static inline bool /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Counter__isOverflowPending(void )
{
  return /*Msp430Counter32khzC.Counter*/Msp430CounterC__0__Msp430Timer__isOverflowPending();
}

# 71 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Counter.nc"
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
# 130 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Control__enableEvents(void )
{
  * (volatile uint16_t * )386U |= 0x0010;
}

# 57 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
inline static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430TimerControl__enableEvents(void ){
#line 57
  /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Control__enableEvents();
#line 57
}
#line 57
# 95 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Control__clearPendingInterrupt(void )
{
  * (volatile uint16_t * )386U &= ~0x0001;
}

# 44 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerControl.nc"
inline static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430TimerControl__clearPendingInterrupt(void ){
#line 44
  /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Control__clearPendingInterrupt();
#line 44
}
#line 44
# 155 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Compare__setEvent(uint16_t x)
{
  * (volatile uint16_t * )402U = x;
}

# 41 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Compare__setEvent(uint16_t time){
#line 41
  /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Compare__setEvent(time);
#line 41
}
#line 41
# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
inline static uint16_t /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Timer__get(void ){
#line 45
  unsigned int __nesc_result;
#line 45

#line 45
  __nesc_result = /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Timer__get();
#line 45

#line 45
  return __nesc_result;
#line 45
}
#line 45
# 165 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Compare__setEventFromNow(uint16_t x)
{
  * (volatile uint16_t * )402U = /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Timer__get() + x;
}

# 43 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Compare__setEventFromNow(uint16_t delta){
#line 43
  /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Compare__setEventFromNow(delta);
#line 43
}
#line 43
# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Timer.nc"
inline static uint16_t /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430Timer__get(void ){
#line 45
  unsigned int __nesc_result;
#line 45

#line 45
  __nesc_result = /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Timer__get();
#line 45

#line 45
  return __nesc_result;
#line 45
}
#line 45
# 81 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430AlarmC.nc"
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

# 103 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__startAt(/*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__size_type t0, /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__size_type dt){
#line 103
  /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__startAt(t0, dt);
#line 103
}
#line 103
# 58 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline  /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__cc_t /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__int2CC(uint16_t x)
#line 58
{
#line 58
  union /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4____nesc_unnamed4294 {
#line 58
    uint16_t f;
#line 58
    /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__cc_t t;
  } 
#line 58
  c = { .f = x };

#line 58
  return c.t;
}

#line 85
static inline /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__cc_t /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Control__getControl(void )
{
  return /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__int2CC(* (volatile uint16_t * )388U);
}

#line 188
static inline void /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Capture__default__captured(uint16_t n)
{
}

# 86 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
inline static void /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Capture__captured(uint16_t time){
#line 86
  /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Capture__default__captured(time);
#line 86
}
#line 86
# 150 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline uint16_t /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Capture__getEvent(void )
{
  return * (volatile uint16_t * )404U;
}

#line 192
static inline void /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Compare__default__fired(void )
{
}

# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Compare__fired(void ){
#line 45
  /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Compare__default__fired();
#line 45
}
#line 45
# 58 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline  /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__cc_t /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__int2CC(uint16_t x)
#line 58
{
#line 58
  union /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5____nesc_unnamed4295 {
#line 58
    uint16_t f;
#line 58
    /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__cc_t t;
  } 
#line 58
  c = { .f = x };

#line 58
  return c.t;
}

#line 85
static inline /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__cc_t /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Control__getControl(void )
{
  return /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__int2CC(* (volatile uint16_t * )390U);
}

#line 188
static inline void /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Capture__default__captured(uint16_t n)
{
}

# 86 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Capture.nc"
inline static void /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Capture__captured(uint16_t time){
#line 86
  /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Capture__default__captured(time);
#line 86
}
#line 86
# 150 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static inline uint16_t /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Capture__getEvent(void )
{
  return * (volatile uint16_t * )406U;
}

#line 192
static inline void /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Compare__default__fired(void )
{
}

# 45 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430Compare.nc"
inline static void /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Compare__fired(void ){
#line 45
  /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Compare__default__fired();
#line 45
}
#line 45
# 131 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static inline void /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__VectorTimerX1__fired(void )
{
  uint8_t n = * (volatile uint16_t * )286U;

#line 134
  /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Event__fired(n >> 1);
}

# 39 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerEvent.nc"
inline static void Msp430TimerCommonP__VectorTimerB1__fired(void ){
#line 39
  /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__VectorTimerX1__fired();
#line 39
}
#line 39
# 124 "/home/carlson/local/src/tinyos-2.x/tos/system/SchedulerBasicP.nc"
static inline void SchedulerBasicP__Scheduler__init(void )
{
  /* atomic removed: atomic calls only */
  {
    memset((void *)SchedulerBasicP__m_next, SchedulerBasicP__NO_TASK, sizeof SchedulerBasicP__m_next);
    SchedulerBasicP__m_head = SchedulerBasicP__NO_TASK;
    SchedulerBasicP__m_tail = SchedulerBasicP__NO_TASK;
  }
}

# 57 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Scheduler.nc"
inline static void RealMainP__Scheduler__init(void ){
#line 57
  SchedulerBasicP__Scheduler__init();
#line 57
}
#line 57
# 73 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/PlatformP.nc"
static inline error_t PlatformP__PeripheralInit__default__init(void )
#line 73
{
  return SUCCESS;
}

# 62 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Init.nc"
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
# 45 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/clock/PlatformClockP.nc"
static inline error_t PlatformClockP__SubInit__default__init(void )
#line 45
{
  return SUCCESS;
}

# 62 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t PlatformClockP__SubInit__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = PlatformClockP__SubInit__default__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 160 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/clock/PlatformClockP.nc"
static inline void PlatformClockP__startTimers(void )
#line 160
{
  TACTL = 0x0020 | (TACTL & ~(0x0020 | 0x0010));
  TBCTL = 0x0020 | (TBCTL & ~(0x0020 | 0x0010));
}

#line 152
static inline void PlatformClockP__initTimers(void )
#line 152
{

  TACTL = (0x0200 | 0x0080) | 0x0002;


  TBCTL = 0x0100 | 0x0002;
}

#line 59
static inline void PlatformClockP__set_dco(uint16_t delta)
#line 59
{
  uint8_t *Flash_ptrA;
  uint16_t Compare;
#line 61
  uint16_t Oldcapture = 0;

  BCSCTL1 |= 0x30;
  TACCTL2 = 0x4000 + 0x1000 + 0x0100;
  TACTL = 0x0200 + 0x0020 + 0x0004;

  while (1) 
    {
      while (!(0x0001 & TACCTL2)) ;
      TACCTL2 &= ~0x0001;
      Compare = TACCR2;
      Compare = Compare - Oldcapture;
      Oldcapture = TACCR2;

      if (delta == Compare) {
        break;
        }
      else {
#line 77
        if (delta < Compare) 
          {
            DCOCTL--;
            if (DCOCTL == 0xFF) {
              if (BCSCTL1 & 0x0f) {
                BCSCTL1--;
                }
              }
          }
        else 
#line 85
          {
            DCOCTL++;
            if (DCOCTL == 0x00) {
              if ((BCSCTL1 & 0x0f) != 0x0f) {
                BCSCTL1++;
                }
              }
          }
        }
    }
#line 92
  TACCTL2 = 0;
  TACTL = 0;
  BCSCTL1 &= ~0x30;



  Flash_ptrA = (uint8_t *)0x10C0;
  FCTL2 = 0xA500 + 0x0040 + 0x0002;
  FCTL1 = 0xA500 + 0x0002;
  FCTL3 = 0xA500 + 0x0040;
  *Flash_ptrA = 0x00;
  FCTL1 = 0xA500 + 0x0040;
  Flash_ptrA = (uint8_t *)0x10F8;
  *Flash_ptrA = DCOCTL;
  Flash_ptrA++;
  *Flash_ptrA = BCSCTL1;
  FCTL1 = 0xA500;
  FCTL3 = 0xA500 + 0x0040 + 0x0010;
}

static inline void PlatformClockP__initClocks(void )
#line 112
{
  if (CALBC1_16MHZ == 0xff || CALDCO_16MHZ == 0xff) {






      BCSCTL3 = 0x04;
      PlatformClockP__set_dco(1024);
    }
  else 







    {

      BCSCTL1 = CALBC1_16MHZ;
      DCOCTL = CALDCO_16MHZ;
    }



  BCSCTL1 |= 0x80;
  BCSCTL1 &= ~0x00;







  BCSCTL2 = 0x00;
}

#line 165
static inline error_t PlatformClockP__Init__init(void )
{
  PlatformClockP__initClocks();
  PlatformClockP__initTimers();
  PlatformClockP__startTimers();
  return PlatformClockP__SubInit__init();
}

# 62 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t PlatformP__PlatformClock__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = PlatformClockP__Init__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 48 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/pins/PlatformPinsP.nc"
static inline error_t PlatformPinsP__Init__init(void )
#line 48
{
  /* atomic removed: atomic calls only */
#line 49
  {


    P1DIR = 0xFF;

    P1OUT = 0x04;



    P2DIR = 0xFF;
    P2OUT = 0x00;



    P3DIR = 0xFF;

    P3OUT = 0x06;



    P4DIR = 0xFF;
    P4OUT = 0x00;



    P5DIR = 0xFF;
    P5OUT = 0x00;



    P6DIR = 0xFF;
    P6OUT = 0x00;
  }
#line 114
  return SUCCESS;
}

# 62 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Init.nc"
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
# 52 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/PlatformP.nc"
static inline error_t PlatformP__Init__init(void )
#line 52
{
  WDTCTL = 0x5A00 + 0x0080;



  PlatformP__PlatformPins__init();
  PlatformP__PlatformClock__init();


  PlatformP__PeripheralInit__init();







  return SUCCESS;
}

# 62 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Init.nc"
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
# 65 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Scheduler.nc"
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
# 92 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void Msp430I2CP__SCL__selectModuleFunc(void ){
#line 92
  /*HplMsp430GeneralIOC.P32*/HplMsp430GeneralIORenP__18__IO__selectModuleFunc();
#line 92
}
#line 92
#line 85
inline static void Msp430I2CP__SCL__makeOutput(void ){
#line 85
  /*HplMsp430GeneralIOC.P32*/HplMsp430GeneralIORenP__18__IO__makeOutput();
#line 85
}
#line 85







inline static void Msp430I2CP__SDA__selectModuleFunc(void ){
#line 92
  /*HplMsp430GeneralIOC.P31*/HplMsp430GeneralIORenP__17__IO__selectModuleFunc();
#line 92
}
#line 92
#line 85
inline static void Msp430I2CP__SDA__makeOutput(void ){
#line 85
  /*HplMsp430GeneralIOC.P31*/HplMsp430GeneralIORenP__17__IO__makeOutput();
#line 85
}
#line 85
# 202 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430I2CP.nc"
static inline error_t Msp430I2CP__I2CBasicAddr__read(i2c_flags_t flags, 
uint16_t addr, uint8_t len, 
uint8_t *buf)
{
  uint8_t counter = 0xFF;

  if (UCB0STAT & 0x10) {
    return EBUSY;
    }

  Msp430I2CP__m_buf = buf;
  Msp430I2CP__m_len = len;
  Msp430I2CP__m_flags = flags;
  Msp430I2CP__m_pos = 0;



  if (Msp430I2CP__m_flags & I2C_START) 
    {

      Msp430I2CP__UCB0CTL1 = 0x01;
#line 236
      Msp430I2CP__UCB0CTL0 = ((0x20 | 0x08) | 0x06) | 0x01;
      Msp430I2CP__UCB0CTL1 = 0x80 | 0x01;


      Msp430I2CP__UCB0BR0 = 0x28;

      Msp430I2CP__UCB0BR1 = 0x00;

      Msp430I2CP__SDA__makeOutput();
      Msp430I2CP__SDA__selectModuleFunc();
      Msp430I2CP__SCL__makeOutput();
      Msp430I2CP__SCL__selectModuleFunc();

      Msp430I2CP__UCB0CTL1 &= ~0x01;

      Msp430I2CP__UCB0I2CIE = 0x08 | 0x01;
      Msp430I2CP__IE2 |= 0x04 | 0x08;




      Msp430I2CP__UCB0I2COA = Msp430I2CP__m_ownaddress;


      Msp430I2CP__UCB0I2CSA = addr;


      Msp430I2CP__UCB0CTL1 |= 0x02;


      if (Msp430I2CP__m_len == 1 && Msp430I2CP__m_flags & I2C_STOP) 
        {

          while (Msp430I2CP__UCB0CTL1 & 0x02 && counter > 0x01) 
            counter--;


          Msp430I2CP__UCB0CTL1 |= 0x04;
        }
    }
  else {
#line 276
    if (Msp430I2CP__m_flags & I2C_RESTART) 
      {

        Msp430I2CP__UCB0I2CSA = addr;


        Msp430I2CP__UCB0CTL1 |= 0x02;


        if (Msp430I2CP__m_len == 1 && Msp430I2CP__m_flags & I2C_STOP) 
          {

            while (Msp430I2CP__UCB0CTL1 & 0x02 && counter > 0x01) 
              counter--;


            Msp430I2CP__UCB0CTL1 |= 0x04;
          }
      }
    else {
      Msp430I2CP__nextRead();
      }
    }
#line 298
  if (counter > 0x01) {
    return SUCCESS;
    }
  else {
#line 301
    return FAIL;
    }
}

# 76 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/I2CPacket.nc"
inline static error_t ToastC__I2CBasicAddr__read(i2c_flags_t flags, uint16_t addr, uint8_t length, uint8_t * data){
#line 76
  unsigned char __nesc_result;
#line 76

#line 76
  __nesc_result = Msp430I2CP__I2CBasicAddr__read(flags, addr, length, data);
#line 76

#line 76
  return __nesc_result;
#line 76
}
#line 76
# 337 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430I2CP.nc"
static inline error_t Msp430I2CP__I2CBasicAddr__write(i2c_flags_t flags, 
uint16_t addr, uint8_t len, 
uint8_t *buf)
#line 339
{

  if (UCB0STAT & 0x10) {
    return EBUSY;
    }
  Msp430I2CP__m_buf = buf;
  Msp430I2CP__m_len = len;
  Msp430I2CP__m_flags = flags;
  Msp430I2CP__m_pos = 0;


  if (Msp430I2CP__m_flags & I2C_START) 
    {

      Msp430I2CP__UCB0CTL1 = 0x01;
#line 367
      Msp430I2CP__UCB0CTL0 = ((0x20 | 0x08) | 0x06) | 0x01;
      Msp430I2CP__UCB0CTL1 = 0x80 | 0x01;


      Msp430I2CP__UCB0BR0 = 0x28;

      Msp430I2CP__UCB0BR1 = 0x00;

      Msp430I2CP__SDA__makeOutput();
      Msp430I2CP__SDA__selectModuleFunc();
      Msp430I2CP__SCL__makeOutput();
      Msp430I2CP__SCL__selectModuleFunc();

      Msp430I2CP__UCB0CTL1 &= ~0x01;

      Msp430I2CP__UCB0I2CIE = 0x08 | 0x01;
      Msp430I2CP__IE2 |= 0x04 | 0x08;




      Msp430I2CP__UCB0I2COA = Msp430I2CP__m_ownaddress;


      Msp430I2CP__UCB0I2CSA = addr;


      Msp430I2CP__UCB0CTL1 |= 0x10 | 0x02;
    }
  else {
    if (Msp430I2CP__m_flags & I2C_RESTART) 
      {

        Msp430I2CP__UCB0I2CSA = addr;



        Msp430I2CP__UCB0CTL1 |= 0x10 | 0x02;
      }
    else {

      Msp430I2CP__nextWrite();
      }
    }
#line 410
  return SUCCESS;
}

# 93 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/I2CPacket.nc"
inline static error_t ToastC__I2CBasicAddr__write(i2c_flags_t flags, uint16_t addr, uint8_t length, uint8_t * data){
#line 93
  unsigned char __nesc_result;
#line 93

#line 93
  __nesc_result = Msp430I2CP__I2CBasicAddr__write(flags, addr, length, data);
#line 93

#line 93
  return __nesc_result;
#line 93
}
#line 93
# 170 "ToastC.nc"
static inline void ToastC__StdOutTask__runTask(void )
{
  uint8_t str[2];

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 174
    str[0] = ToastC__tmpchar;
#line 174
    __nesc_atomic_end(__nesc_atomic); }

  switch (str[0]) {


      case 'w': 
        ToastC__i2c_length = 10;
      ToastC__i2c_buffer[0] = 0x00;
      ToastC__i2c_buffer[1] = 0x01;
      ToastC__i2c_buffer[2] = 0x02;
      ToastC__i2c_buffer[3] = 0x03;
      ToastC__i2c_buffer[4] = 0x04;
      ToastC__i2c_buffer[5] = 0x05;
      ToastC__i2c_buffer[6] = 0x06;
      ToastC__i2c_buffer[7] = 0x07;
      ToastC__i2c_buffer[8] = 0x08;
      ToastC__i2c_buffer[9] = 0x09;
      ToastC__I2CBasicAddr__write(I2C_START | I2C_STOP, 0x42, ToastC__i2c_length, ToastC__i2c_buffer);
      break;

      case 'r': 
        ToastC__i2c_length = 10;
      ToastC__I2CBasicAddr__read(I2C_START | I2C_STOP, 0x42, ToastC__i2c_length, ToastC__i2c_buffer);
      break;

      case '\r': 
        str[0] = '\n';
      str[1] = '\r';
      ToastC__UartStream__send(str, 2);
      break;

      default: 
        ToastC__UartStream__send(str, 1);
      break;
    }
}

#line 120
static inline void ToastC__slaveStopTask__runTask(void )
{
  ToastC__UartStream__send(ToastC__str_i2c_slave_stop_nl, 17);
}

#line 115
static inline void ToastC__slaveStartTask__runTask(void )
{
  ToastC__UartStream__send(ToastC__str_i2c_slave_start_nl, 17);
}

#line 110
static inline void ToastC__slaveTransmitTask__runTask(void )
{
  ToastC__UartStream__send(ToastC__str_i2c_slave_transmit_nl, 20);
}

#line 105
static inline void ToastC__slaveReceiveTask__runTask(void )
{
  ToastC__UartStream__send(ToastC__str_i2c_slave_receive_nl, 19);
}

#line 24
static inline void ToastC__transmitTask__runTask(void )
{
  ToastC__UartStream__send(ToastC__welcome_string, 22);
}

# 103 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__startAt(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type t0, /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__size_type dt){
#line 103
  /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__startAt(t0, dt);
#line 103
}
#line 103
# 58 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/AlarmToTimerC.nc"
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

# 129 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__startOneShotAt(uint32_t t0, uint32_t dt){
#line 129
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__startOneShotAt(t0, dt);
#line 129
}
#line 129
# 65 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430AlarmC.nc"
static inline void /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__stop(void )
{
  /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Msp430TimerControl__disableEvents();
}

# 73 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__stop(void ){
#line 73
  /*HilTimerMilliC.AlarmMilli32C.AlarmFrom.Msp430Alarm*/Msp430AlarmC__0__Alarm__stop();
#line 73
}
#line 73
# 102 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static inline void /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__stop(void )
{
  /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__AlarmFrom__stop();
}

# 73 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Alarm.nc"
inline static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__stop(void ){
#line 73
  /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__stop();
#line 73
}
#line 73
# 71 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__stop(void )
{
#line 72
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__stop();
}

# 78 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__stop(void ){
#line 78
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__stop();
#line 78
}
#line 78
# 64 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Counter.nc"
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
# 86 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
static inline /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__to_size_type /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Alarm__getNow(void )
{
  return /*HilTimerMilliC.AlarmMilli32C.Transform*/TransformAlarmC__0__Counter__get();
}

# 109 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Alarm.nc"
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
# 96 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/AlarmToTimerC.nc"
static inline uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__getNow(void )
{
#line 97
  return /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__getNow();
}

# 136 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Timer.nc"
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
# 100 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/VirtualizeTimerC.nc"
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

# 83 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__fired(uint8_t arg_0x2b74e213d5d8){
#line 83
    /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__Timer__default__fired(arg_0x2b74e213d5d8);
#line 83
}
#line 83
# 67 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
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
# 139 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__fired(void )
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__fireTimers(/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__getNow());
}

# 83 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__fired(void ){
#line 83
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC__0__TimerFrom__fired();
#line 83
}
#line 83
# 91 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
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

# 116 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/Alarm.nc"
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
# 74 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__fired__runTask(void )
{
  if (/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__m_oneshot == FALSE) {
    /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__start(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Alarm__getAlarm(), /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__m_dt, FALSE);
    }
#line 78
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC__0__Timer__fired();
}

# 59 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/PlatformSerialP.nc"
static inline void PlatformSerialP__Resource__granted(void )
#line 59
{
}

# 202 "/home/carlson/local/src/tinyos-2.x/tos/system/ArbiterP.nc"
static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__default__granted(uint8_t id)
#line 202
{
}

# 102 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Resource.nc"
inline static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__granted(uint8_t arg_0x2b74e1dd7658){
#line 102
  switch (arg_0x2b74e1dd7658) {
#line 102
    case /*PlatformSerialC.UartC*/Msp430UsciUartA0C__0__CLIENT_ID:
#line 102
      PlatformSerialP__Resource__granted();
#line 102
      break;
#line 102
    default:
#line 102
      /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__Resource__default__granted(arg_0x2b74e1dd7658);
#line 102
      break;
#line 102
    }
#line 102
}
#line 102
# 400 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
static inline const msp430_usci_config_t *
/*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Msp430UsciConfigure__default__getConfiguration(uint8_t client)
{
  return &msp430_usci_uart_default_config;
}

# 44 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/Msp430UsciConfigure.nc"
inline static const msp430_usci_config_t */*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Msp430UsciConfigure__getConfiguration(uint8_t arg_0x2b74e1e979a8){
#line 44
  struct msp430_usci_config_t const *__nesc_result;
#line 44

#line 44
    __nesc_result = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Msp430UsciConfigure__default__getConfiguration(arg_0x2b74e1e979a8);
#line 44

#line 44
  return __nesc_result;
#line 44
}
#line 44
# 406 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
static inline void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__ResourceConfigure__configure(uint8_t client)
{
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__configure_(/*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Msp430UsciConfigure__getConfiguration(client));
}

# 216 "/home/carlson/local/src/tinyos-2.x/tos/system/ArbiterP.nc"
static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__default__configure(uint8_t id)
#line 216
{
}

# 59 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/ResourceConfigure.nc"
inline static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__configure(uint8_t arg_0x2b74e1dd39b8){
#line 59
  switch (arg_0x2b74e1dd39b8) {
#line 59
    case /*PlatformSerialC.UartC*/Msp430UsciUartA0C__0__CLIENT_ID:
#line 59
      /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__ResourceConfigure__configure(/*PlatformSerialC.UartC*/Msp430UsciUartA0C__0__CLIENT_ID);
#line 59
      break;
#line 59
    default:
#line 59
      /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceConfigure__default__configure(arg_0x2b74e1dd39b8);
#line 59
      break;
#line 59
    }
#line 59
}
#line 59
# 190 "/home/carlson/local/src/tinyos-2.x/tos/system/ArbiterP.nc"
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

# 205 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/HplMsp430UsciA0P.nc"
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__leaveResetMode_(void )
#line 205
{

  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__UCA0CTL1 &= ~0x01;
}

#line 200
static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__enterResetMode_(void )
#line 200
{

  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__UCA0CTL1 |= 0x01;
}






static inline void /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__configure(const msp430_usci_config_t *config, 
bool leave_in_reset)
{
  if (!config) {
      return;
    }
  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__enterResetMode_();

  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__UCA0CTL0 = config->ctl0;
  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__UCA0CTL1 = config->ctl1 + 0x01;

  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__UCA0BR0 = config->br0;
  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__UCA0BR1 = config->br1;

  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__UCA0MCTL = config->mctl;

  if (!leave_in_reset) {
      /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__leaveResetMode_();
    }
}

# 273 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__configure(const msp430_usci_config_t *config, bool leave_in_reset){
#line 273
  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__configure(config, leave_in_reset);
#line 273
}
#line 273
# 53 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P35*/HplMsp430GeneralIORenP__21__IO__makeInput(void )
#line 53
{
#line 53
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 53
    * (volatile uint8_t * )26U &= ~(0x01 << 5);
#line 53
    __nesc_atomic_end(__nesc_atomic); }
}

# 78 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__URXD__makeInput(void ){
#line 78
  /*HplMsp430GeneralIOC.P35*/HplMsp430GeneralIORenP__21__IO__makeInput();
#line 78
}
#line 78
# 57 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P35*/HplMsp430GeneralIORenP__21__IO__selectModuleFunc(void )
#line 57
{
#line 57
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 57
    * (volatile uint8_t * )27U |= 0x01 << 5;
#line 57
    __nesc_atomic_end(__nesc_atomic); }
}

# 92 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__URXD__selectModuleFunc(void ){
#line 92
  /*HplMsp430GeneralIOC.P35*/HplMsp430GeneralIORenP__21__IO__selectModuleFunc();
#line 92
}
#line 92
# 55 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P34*/HplMsp430GeneralIORenP__20__IO__makeOutput(void )
#line 55
{
#line 55
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 55
    * (volatile uint8_t * )26U |= 0x01 << 4;
#line 55
    __nesc_atomic_end(__nesc_atomic); }
}

# 85 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UTXD__makeOutput(void ){
#line 85
  /*HplMsp430GeneralIOC.P34*/HplMsp430GeneralIORenP__20__IO__makeOutput();
#line 85
}
#line 85
# 57 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static inline void /*HplMsp430GeneralIOC.P34*/HplMsp430GeneralIORenP__20__IO__selectModuleFunc(void )
#line 57
{
#line 57
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 57
    * (volatile uint8_t * )27U |= 0x01 << 4;
#line 57
    __nesc_atomic_end(__nesc_atomic); }
}

# 92 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIO.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UTXD__selectModuleFunc(void ){
#line 92
  /*HplMsp430GeneralIOC.P34*/HplMsp430GeneralIORenP__20__IO__selectModuleFunc();
#line 92
}
#line 92
# 288 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430xv2/usci/HplMsp430Usci.nc"
inline static void /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__leaveResetMode_(void ){
#line 288
  /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__leaveResetMode_();
#line 288
}
#line 288
# 55 "/home/carlson/local/src/tinyos-2.x/tos/system/FcfsResourceQueueC.nc"
static inline error_t /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__Init__init(void )
#line 55
{
  memset(/*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__resQ, /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__NO_ENTRY, sizeof /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__resQ);
  return SUCCESS;
}

# 62 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Init.nc"
inline static error_t RealMainP__SoftwareInit__init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = /*Msp430UsciA0P.UsciC.ArbiterC.Queue*/FcfsResourceQueueC__0__Init__init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 142 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430I2CP.nc"
static inline error_t Msp430I2CP__I2CBasicAddr__enableSlave(void )
{

  Msp430I2CP__UCB0CTL1 = 0x01;
#line 159
  Msp430I2CP__UCB0CTL0 = 0x06 | 0x01;

  Msp430I2CP__SDA__makeOutput();
  Msp430I2CP__SDA__selectModuleFunc();
  Msp430I2CP__SCL__makeOutput();
  Msp430I2CP__SCL__selectModuleFunc();

  Msp430I2CP__UCB0CTL1 &= ~0x01;

  Msp430I2CP__UCB0I2CIE = 0x02;
  Msp430I2CP__IE2 |= 0x04 | 0x08;



  if (Msp430I2CP__m_ownaddress != 0x0000) 
    {

      Msp430I2CP__UCB0I2COA = Msp430I2CP__m_ownaddress;

      return SUCCESS;
    }
  else {
    return FAIL;
    }
}

# 123 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/I2CPacket.nc"
inline static error_t ToastC__I2CBasicAddr__enableSlave(void ){
#line 123
  unsigned char __nesc_result;
#line 123

#line 123
  __nesc_result = Msp430I2CP__I2CBasicAddr__enableSlave();
#line 123

#line 123
  return __nesc_result;
#line 123
}
#line 123
# 135 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430I2CP.nc"
static inline error_t Msp430I2CP__I2CBasicAddr__setOwnAddress(uint16_t addr)
{
  Msp430I2CP__m_ownaddress = addr;

  return SUCCESS;
}

# 56 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/I2CPacket.nc"
inline static error_t ToastC__I2CBasicAddr__setOwnAddress(uint16_t addr){
#line 56
  unsigned char __nesc_result;
#line 56

#line 56
  __nesc_result = Msp430I2CP__I2CBasicAddr__setOwnAddress(addr);
#line 56

#line 56
  return __nesc_result;
#line 56
}
#line 56
# 95 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430I2CP.nc"
static inline error_t Msp430I2CP__Resource__request(uint8_t id)
#line 95
{

  return SUCCESS;
}

# 88 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Resource.nc"
inline static error_t ToastC__I2CResource__request(void ){
#line 88
  unsigned char __nesc_result;
#line 88

#line 88
  __nesc_result = Msp430I2CP__Resource__request(/*ToastAppC.I2CC*/Msp430I2CC__0__CLIENT_ID);
#line 88

#line 88
  return __nesc_result;
#line 88
}
#line 88
# 67 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
inline static error_t ToastC__transmitTask__postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SchedulerBasicP__TaskBasic__postTask(ToastC__transmitTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
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
# 133 "/home/carlson/local/src/tinyos-2.x/tos/system/ArbiterP.nc"
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

# 81 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/ResourceDefaultOwner.nc"
inline static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__immediateRequested(void ){
#line 81
  /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceDefaultOwner__default__immediateRequested();
#line 81
}
#line 81
# 206 "/home/carlson/local/src/tinyos-2.x/tos/system/ArbiterP.nc"
static inline void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceRequested__default__immediateRequested(uint8_t id)
#line 206
{
}

# 61 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/ResourceRequested.nc"
inline static void /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceRequested__immediateRequested(uint8_t arg_0x2b74e1dd67e8){
#line 61
    /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ResourceRequested__default__immediateRequested(arg_0x2b74e1dd67e8);
#line 61
}
#line 61
# 93 "/home/carlson/local/src/tinyos-2.x/tos/system/ArbiterP.nc"
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

# 97 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Resource.nc"
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
# 51 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/PlatformSerialP.nc"
static inline error_t PlatformSerialP__StdControl__start(void )
#line 51
{
  return PlatformSerialP__Resource__immediateRequest();
}

# 95 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/StdControl.nc"
inline static error_t ToastC__UartControl__start(void ){
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
# 29 "ToastC.nc"
static inline void ToastC__Boot__booted(void )
{
  ToastC__UartControl__start();

  ToastC__transmitTask__postTask();

  ToastC__I2CResource__request();

  ToastC__I2CBasicAddr__setOwnAddress(0x0042);
  ToastC__I2CBasicAddr__enableSlave();
}

# 60 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Boot.nc"
inline static void RealMainP__Boot__booted(void ){
#line 60
  ToastC__Boot__booted();
#line 60
}
#line 60
# 391 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430hardware.h"
static inline  void __nesc_disable_interrupt(void )
{
  __dint();
  __nop();
}

# 184 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/lpm/McuSleepC.nc"
static inline mcu_power_t McuSleepC__McuPowerOverride__default__lowestState(void )
#line 184
{
  return MSP430_POWER_LPM4;
}

# 62 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/McuPowerOverride.nc"
inline static mcu_power_t McuSleepC__McuPowerOverride__lowestState(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = McuSleepC__McuPowerOverride__default__lowestState();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 68 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/lpm/McuSleepC.nc"
static inline mcu_power_t McuSleepC__getPowerState(void )
#line 68
{
  mcu_power_t pState = MSP430_POWER_LPM4;
  bool smclk_from_dco = !(BCSCTL2 & 0x08);

#line 83
  if ((TBCTL & 0x0300) == 0x0100 && 
  TBCTL & 0x0002) {
      pState = MSP430_POWER_LPM3;
    }








  if (
#line 93
  smclk_from_dco && ((
  TACTL & 0x0300) == 0x0200 && ((
  TACCTL0 & 0x0010) | (TACCTL1 & 0x0010)) | (TACCTL2 & 0x0010)) && 
  TACTL & 0x0002) 
    {
      pState = MSP430_POWER_LPM1;
    }
#line 133
  if (ADC12CTL0 & 0x010) {
      if (ADC12CTL1 & 0x0010) {

          if (ADC12CTL1 & 0x0008) {



              pState = MSP430_POWER_LPM1;
            }
          else 
#line 141
            {

              pState = MSP430_POWER_ACTIVE;
            }
        }
      else {
#line 145
        if (ADC12CTL1 & 0x0400 && (TACTL & 0x0300) == 0x0200) {








            pState = MSP430_POWER_LPM1;
          }
        }
    }

  return pState;
}

# 379 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430hardware.h"
static inline  mcu_power_t mcombine(mcu_power_t m1, mcu_power_t m2)
#line 379
{
  return m1 < m2 ? m1 : m2;
}

# 162 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/lpm/McuSleepC.nc"
static inline void McuSleepC__computePowerState(void )
#line 162
{
  McuSleepC__powerState = mcombine(McuSleepC__getPowerState(), 
  McuSleepC__McuPowerOverride__lowestState());
}

static inline void McuSleepC__McuSleep__sleep(void )
#line 167
{
  uint16_t temp;

#line 169
  if (McuSleepC__dirty) {
      McuSleepC__computePowerState();
    }

  temp = McuSleepC__msp430PowerBits[McuSleepC__powerState] | 0x0008;
   __asm volatile ("bis  %0, r2" :  : "m"(temp));

   __asm volatile ("" :  :  : "memory");
  __nesc_disable_interrupt();
}

# 76 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/McuSleep.nc"
inline static void SchedulerBasicP__McuSleep__sleep(void ){
#line 76
  McuSleepC__McuSleep__sleep();
#line 76
}
#line 76
# 78 "/home/carlson/local/src/tinyos-2.x/tos/system/SchedulerBasicP.nc"
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

# 72 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/Scheduler.nc"
inline static void RealMainP__Scheduler__taskLoop(void ){
#line 72
  SchedulerBasicP__Scheduler__taskLoop();
#line 72
}
#line 72
# 411 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/msp430hardware.h"
  __nesc_atomic_t __nesc_atomic_start(void )
{
  __nesc_atomic_t result = (__read_status_register() & 0x0008) != 0;

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

# 21 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/HplMsp430UsciInterruptsAB0P.nc"
__attribute((wakeup)) __attribute((interrupt(0x000E)))  void sig_USCIAB0RX_VECTOR(void )
{

  if (IFG2 & 0x01 && IE2 & 0x01) 
    {
      HplMsp430UsciInterruptsAB0P__InterruptsUCA0Rx__interrupted(IFG2);
    }
  else 
    {
      HplMsp430UsciInterruptsAB0P__InterruptsUCB0State__interrupted(IFG2);
    }
}

# 153 "/home/carlson/local/src/tinyos-2.x/tos/system/ArbiterP.nc"
static bool /*Msp430UsciA0P.UsciC.ArbiterC.Arbiter*/ArbiterP__0__ArbiterInfo__inUse(void )
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

# 170 "/home/carlson/local/src/tinyos-2.x/tos/system/SchedulerBasicP.nc"
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

# 231 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/HplMsp430UsciA0P.nc"
static uint8_t /*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__Usci__currentMode(void )
{
  /* atomic removed: atomic calls only */
#line 233
  {
    if (!(/*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__UCA0CTL0 & 0x01)) {
        {
          unsigned char __nesc_temp = 
#line 235
          MSP430_USCI_UART;

#line 235
          return __nesc_temp;
        }
      }
#line 237
    if (0x06 == (/*Msp430UsciA0P.UsciC.HplUsciP*/HplMsp430UsciA0P__0__UCA0CTL0 & (0x02 | 0x04))) {
        {
          unsigned char __nesc_temp = 
#line 238
          MSP430_USCI_I2C;

#line 238
          return __nesc_temp;
        }
      }
#line 240
    {
      unsigned char __nesc_temp = 
#line 240
      MSP430_USCI_SPI;

#line 240
      return __nesc_temp;
    }
  }
}

# 206 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
static error_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UartStream__send(uint8_t client, uint8_t *buf, uint16_t len)
{
  error_t rv = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__checkIsOwner(client);

#line 209
  if (SUCCESS != rv) {
      return rv;
    }
  if (/*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__isBusy()) {
      return EBUSY;
    }
  if (0 == len || 0 == buf) {
      return FAIL;
    }
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_tx_buf = buf;
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_tx_len = len;
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_tx_pos = 0;


  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__setIe(/*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__getIe() | 0x02);

  return SUCCESS;
}

# 34 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/HplMsp430UsciInterruptsAB0P.nc"
__attribute((wakeup)) __attribute((interrupt(0x000C)))  void sig_USCIAB0TX_VECTOR(void )
{

  if (IFG2 & 0x02 && IE2 & 0x02) 
    {
      HplMsp430UsciInterruptsAB0P__InterruptsUCA0Tx__interrupted(IFG2);
    }
  else {

    if (IFG2 & 0x04 && IE2 & 0x04) 
      {
        HplMsp430UsciInterruptsAB0P__InterruptsUCB0Rx__interrupted(IFG2);
      }
    else {

      if (IFG2 & 0x08 && IE2 & 0x08) 
        {
          HplMsp430UsciInterruptsAB0P__InterruptsUCB0Tx__interrupted(IFG2);
        }
      }
    }
}

# 305 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430I2CP.nc"
static void Msp430I2CP__nextRead(void )
{
  uint8_t counter = 0xFF;


  Msp430I2CP__m_buf[Msp430I2CP__m_pos++] = UCB0RXBUF;


  if (Msp430I2CP__m_pos == Msp430I2CP__m_len) {


      if (Msp430I2CP__m_len > 1) {

          Msp430I2CP__UCB0CTL1 |= 0x04;


          while (Msp430I2CP__UCB0CTL1 & 0x04 && counter > 0x01) 
            counter--;
        }

      Msp430I2CP__resetUCB0();
      if (counter > 0x01) {
        Msp430I2CP__I2CBasicAddr__readDone(SUCCESS, Msp430I2CP__UCB0I2CSA, Msp430I2CP__m_len, Msp430I2CP__m_buf);
        }
      else {
#line 329
        Msp430I2CP__I2CBasicAddr__readDone(FAIL, Msp430I2CP__UCB0I2CSA, Msp430I2CP__m_len, Msp430I2CP__m_buf);
        }
    }
}

#line 414
static void Msp430I2CP__nextWrite(void )
{
  uint8_t counter = 0xFF;


  if (Msp430I2CP__m_pos == Msp430I2CP__m_len) {


      if (Msp430I2CP__m_flags & I2C_STOP) 
        {

          Msp430I2CP__UCB0CTL1 |= 0x04;


          while (Msp430I2CP__UCB0CTL1 & 0x04 && counter > 0x01) 
            counter--;

          Msp430I2CP__resetUCB0();
        }


      if (counter > 0x01) {
        Msp430I2CP__I2CBasicAddr__writeDone(SUCCESS, Msp430I2CP__UCB0I2CSA, Msp430I2CP__m_len, Msp430I2CP__m_buf);
        }
      else {
#line 438
        Msp430I2CP__I2CBasicAddr__writeDone(FAIL, Msp430I2CP__UCB0I2CSA, Msp430I2CP__m_len, Msp430I2CP__m_buf);
        }
    }
  else {
#line 441
    Msp430I2CP__UCB0TXBUF = Msp430I2CP__m_buf[Msp430I2CP__m_pos++];
    }
}

# 11 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCommonP.nc"
__attribute((wakeup)) __attribute((interrupt(0x0012)))  void sig_TIMERA0_VECTOR(void )
#line 11
{
#line 11
  Msp430TimerCommonP__VectorTimerA0__fired();
}

# 180 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static void /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Event__fired(void )
{
  if (/*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Control__getControl().cap) {
    /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Capture__captured(/*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Capture__getEvent());
    }
  else {
#line 185
    /*Msp430TimerC.Msp430TimerA0*/Msp430TimerCapComP__0__Compare__fired();
    }
}

#line 180
static void /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Event__fired(void )
{
  if (/*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Control__getControl().cap) {
    /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Capture__captured(/*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Capture__getEvent());
    }
  else {
#line 185
    /*Msp430TimerC.Msp430TimerA1*/Msp430TimerCapComP__1__Compare__fired();
    }
}

#line 180
static void /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Event__fired(void )
{
  if (/*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Control__getControl().cap) {
    /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Capture__captured(/*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Capture__getEvent());
    }
  else {
#line 185
    /*Msp430TimerC.Msp430TimerA2*/Msp430TimerCapComP__2__Compare__fired();
    }
}

# 12 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCommonP.nc"
__attribute((wakeup)) __attribute((interrupt(0x0010)))  void sig_TIMERA1_VECTOR(void )
#line 12
{
#line 12
  Msp430TimerCommonP__VectorTimerA1__fired();
}

#line 13
__attribute((wakeup)) __attribute((interrupt(0x001A)))  void sig_TIMERB0_VECTOR(void )
#line 13
{
#line 13
  Msp430TimerCommonP__VectorTimerB0__fired();
}

# 133 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/TransformCounterC.nc"
static void /*CounterMilli32C.Transform*/TransformCounterC__0__CounterFrom__overflow(void )
{
  /* atomic removed: atomic calls only */
  {
    /*CounterMilli32C.Transform*/TransformCounterC__0__m_upper++;
    if ((/*CounterMilli32C.Transform*/TransformCounterC__0__m_upper & /*CounterMilli32C.Transform*/TransformCounterC__0__OVERFLOW_MASK) == 0) {
      /*CounterMilli32C.Transform*/TransformCounterC__0__Counter__overflow();
      }
  }
}

# 180 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static void /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Event__fired(void )
{
  if (/*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Control__getControl().cap) {
    /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Capture__captured(/*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Capture__getEvent());
    }
  else {
#line 185
    /*Msp430TimerC.Msp430TimerB0*/Msp430TimerCapComP__3__Compare__fired();
    }
}

# 107 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
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

# 80 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/TransformCounterC.nc"
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

# 62 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerP.nc"
static uint16_t /*Msp430TimerC.Msp430TimerB*/Msp430TimerP__1__Timer__get(void )
{




  if (1) {
      /* atomic removed: atomic calls only */
#line 69
      {
        uint16_t t0;
        uint16_t t1 = * (volatile uint16_t * )400U;

#line 72
        do {
#line 72
            t0 = t1;
#line 72
            t1 = * (volatile uint16_t * )400U;
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
      return * (volatile uint16_t * )400U;
    }
}

# 180 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCapComP.nc"
static void /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Event__fired(void )
{
  if (/*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Control__getControl().cap) {
    /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Capture__captured(/*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Capture__getEvent());
    }
  else {
#line 185
    /*Msp430TimerC.Msp430TimerB1*/Msp430TimerCapComP__4__Compare__fired();
    }
}

#line 180
static void /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Event__fired(void )
{
  if (/*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Control__getControl().cap) {
    /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Capture__captured(/*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Capture__getEvent());
    }
  else {
#line 185
    /*Msp430TimerC.Msp430TimerB2*/Msp430TimerCapComP__5__Compare__fired();
    }
}

# 14 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/timer/Msp430TimerCommonP.nc"
__attribute((wakeup)) __attribute((interrupt(0x0018)))  void sig_TIMERB1_VECTOR(void )
#line 14
{
#line 14
  Msp430TimerCommonP__VectorTimerB1__fired();
}

# 63 "/home/carlson/local/src/tinyos-2.x/tos/system/RealMainP.nc"
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

# 134 "/home/carlson/local/src/tinyos-2.x/tos/system/SchedulerBasicP.nc"
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

# 75 "/home/carlson/local/src/tinyos-2.x/tos/interfaces/TaskBasic.nc"
static void SchedulerBasicP__TaskBasic__runTask(uint8_t arg_0x2b74e1a47ae8){
#line 75
  switch (arg_0x2b74e1a47ae8) {
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
    case ToastC__transmitTask:
#line 75
      ToastC__transmitTask__runTask();
#line 75
      break;
#line 75
    case ToastC__slaveReceiveTask:
#line 75
      ToastC__slaveReceiveTask__runTask();
#line 75
      break;
#line 75
    case ToastC__slaveTransmitTask:
#line 75
      ToastC__slaveTransmitTask__runTask();
#line 75
      break;
#line 75
    case ToastC__slaveStartTask:
#line 75
      ToastC__slaveStartTask__runTask();
#line 75
      break;
#line 75
    case ToastC__slaveStopTask:
#line 75
      ToastC__slaveStopTask__runTask();
#line 75
      break;
#line 75
    case ToastC__StdOutTask:
#line 75
      ToastC__StdOutTask__runTask();
#line 75
      break;
#line 75
    default:
#line 75
      SchedulerBasicP__TaskBasic__default__runTask(arg_0x2b74e1a47ae8);
#line 75
      break;
#line 75
    }
#line 75
}
#line 75
# 55 "/home/carlson/local/src/tinyos-2.x/tos/chips/msp430/pins/HplMsp430GeneralIORenP.nc"
static void /*HplMsp430GeneralIOC.P31*/HplMsp430GeneralIORenP__17__IO__makeOutput(void )
#line 55
{
#line 55
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 55
    * (volatile uint8_t * )26U |= 0x01 << 1;
#line 55
    __nesc_atomic_end(__nesc_atomic); }
}

#line 57
static void /*HplMsp430GeneralIOC.P31*/HplMsp430GeneralIORenP__17__IO__selectModuleFunc(void )
#line 57
{
#line 57
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 57
    * (volatile uint8_t * )27U |= 0x01 << 1;
#line 57
    __nesc_atomic_end(__nesc_atomic); }
}

#line 55
static void /*HplMsp430GeneralIOC.P32*/HplMsp430GeneralIORenP__18__IO__makeOutput(void )
#line 55
{
#line 55
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 55
    * (volatile uint8_t * )26U |= 0x01 << 2;
#line 55
    __nesc_atomic_end(__nesc_atomic); }
}

#line 57
static void /*HplMsp430GeneralIOC.P32*/HplMsp430GeneralIORenP__18__IO__selectModuleFunc(void )
#line 57
{
#line 57
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 57
    * (volatile uint8_t * )27U |= 0x01 << 2;
#line 57
    __nesc_atomic_end(__nesc_atomic); }
}

# 73 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/VirtualizeTimerC.nc"
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

# 147 "/home/carlson/local/src/tinyos-2.x/tos/lib/timer/TransformAlarmC.nc"
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

# 155 "/home/carlson/local/src/tinyos-2.x/tos/platforms/toast/hardware/usci/Msp430UsciUartA0P1.nc"
static error_t /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__configure_(const msp430_usci_config_t *config)
{
  if (!config) {
      return FAIL;
    }



  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__configure(config, TRUE);
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__URXD__makeInput();
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__URXD__selectModuleFunc();
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UTXD__makeOutput();
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__UTXD__selectModuleFunc();
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__leaveResetMode_();
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__setIe((0x01 | /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__Usci__getIe()) & ~0x02);
  /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_tx_buf = /*Msp430UsciUartA0P.UartC*/Msp430UsciUartA0P1__0__m_rx_buf = 0;

  return SUCCESS;
}

