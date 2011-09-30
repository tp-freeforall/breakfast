#ifndef HARDWARE_H
#define HARDWARE_H

#include "msp430hardware.h"

//Backwards compatibility with mspgcc4
// also, these are easier to read.
#define TASSEL_TACLK TASSEL_0
#define TASSEL_ACLK  TASSEL_1
#define TASSEL_SMCLK TASSEL_2
#define TASSEL_INCLK TASSEL_3

#define TBSSEL_TBCLK TBSSEL_0
#define TBSSEL_ACLK  TBSSEL_1
#define TBSSEL_SMCLK TBSSEL_2
#define TBSSEL_INCLK TBSSEL_3

#define ID_DIV1 ID_0
#define ID_DIV2 ID_1
#define ID_DIV4 ID_2
#define ID_DIV8 ID_3

#define UCSSEL_UCLK  UCSSEL_0
#define UCSSEL_UCLKI UCSSEL_0
#define UCSSEL_ACLK  UCSSEL_1
#define UCSSEL_SMCLK UCSSEL_2

#define UCMODE_UART UCMODE_0
#define UCMODE_SPI3 UCMODE_0
#define UCMODE_SPI4H UCMODE_1
#define UCMODE_SPI4L UCMODE_2
#define UCMODE_I2C UCMODE_3

#endif
