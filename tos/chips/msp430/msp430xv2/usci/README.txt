This directory contains support for the Universal Serial Controller
Interface as implemented on MSP430 chips in families 4xx, 5xx, and some
chips in the 2xx family.

==============================

@TODO@ There are at least three USCI implementations supported over the
MSP430 family.  The implementations are distinguished by the functional
presence preproprocessor macro as defined in the TI standard headers from
Code Composer Studio distribution:

 __MSP430_HAS_USCI__ -- indicates the original USCI implementation on chips:
     msp430x21x2 msp430x22x2 msp430x22x4 msp430x23x msp430x23x0 msp430x241x
     msp430x24x msp430x24x1 msp430x26x msp430x41x2 msp430x471x6 msp430x471x7
     msp430x47x msp430x47x3 msp430x47x4 msp430xG46x msp430xG47x

 __MSP430_HAS_USCI_AB0__ -- second generation USCI implementation on chips:
     msp430x241x msp430x24x msp430x24x1 msp430x26x msp430x471x6 msp430x471x7
     msp430x47x3 msp430x47x4 msp430x241x msp430x24x msp430x24x1 msp430x26x
     msp430x471x6 msp430x471x7 msp430x47x3 msp430x47x4

 __MSP430_HAS_USCI_A0__, __MSP430_HAS_USCI_B0__ -- third generation USCI
   implementation on chips:
     cc430x513x cc430x612x cc430x613x msp430x54x msp430x54xA msp430x551x
     msp430x552x

It was once hypothesized that all USCI implementations could be supported by
this module by creating alternative HplMSP430UsciInterrupts*P components.  A
second look implies this is not the case, but the appropriate abstractions
and architecture have not been identified.

==============================

There is a generic concept of a USCI module.  Different chip families
support different types of module; these are denoted by a suffix letter
(e.g., USCI_Ax or USCI_Bx).  The types of module differ by the functional
modes they support: USCI_Ax supports UART and SPI, while USCI_Bx supports
SPI and I2C.  There can be any number of instances of a given module type on
a given chip; the MSP430x54xx chips support up to four each of USCI_Ax and
USCI_Bx.

The legacy of the earliest MSP430 chips, and the need to support arbitrary
numbers of different modules, had made the original USART module a
maintenance nightmare, and the USCI module has been reworked from the ground
up.  The driver for the refactoring was elimination of duplicated code.
Since NesC does not support the level of genericity required to do this
within the language, one characteristic instance of each capability is
maintained, and the others are generated from it using the generate.sh
script.

The list of files that are derived are maintained in the file generated.lst,
which itself is generated as a side effect of running generate.sh.  When
attempting to understand the system and do basic maintainance, it may be
worth running:

   cat generated.lst | xargs rm

to clear the clutter out of the way.

Common USCI Support
-------------------

The interface HplMsp430Usci supports the common control registers present
in both A and B modules.  A corresponding HplMsp430UsciP provides a
generic implementation that is derived from the module base register
address.  HplMsp430UsciC bundles this with TEP108-style resource
management, which is done on a whole-module basis rather than the per-mode
approach used in the original implementation.

HplMsp430UsciInterrupts.nc specifies the USCI interrupts interface for
the MSP430XV2.  Because interrupt handlers cannot be defined in generic
modules, HplMsp430UsciA0P.nc is a maintained non-generic module that
defines the interrupt vector.

Msp430UsciA0P.nc is the maintained configuration implementation for
top-level USCI instances, linking the instantiated generic USCI
implementation with proper the non-generic interrupt implementation.

Uart Mode Support
-----------------

Msp430UsciUartP.nc is a maintained generic module that supports parameterized
versions of the standard UART interfaces, relative to an externally provided
USCI interface.

Msp430UsciUartA0P.nc is the maintained non-generic configuration for the UART
capability on a specific module instance.  Platform-specific configurations
should wire up the appropriate chip pins for URXD and UTXD.

Msp430UsciUartA0C.nc is the maintained generic configuration that is used
by applications that need a UART client.

SPI Mode Support
----------------

Msp430UsciSpiP.nc is a maintained generic module that supports
parameterized versions of the standard SPI interfaces, relative to an
externally provided USCI interface.

For historical reasons, the maintained implementation for SPI is in files
Msp430UsciSpiB0P.nc and Msp430UsciSpiB0C.nc.  Platform-specific
configurations should wire the appropriate chip pins to Msp430UsciSpiB0P.

I2C Mode Support
----------------

Due to lack of I2C support on a platform based on an MSP430XV2 chip, I2C
support has not yet been implemented.  Adding support for this should be a
straightforward extension from that for the other USCI modes.

