This repository results from a manual merge of three git repositories.

The most notable features are:
- Incorporation of People Power Co's work on TI's CC430 chips 
- Revisions to people power's cc430-bsl (and C implementation based on
  cppbsl) to handle different BSL hardware
- Implementation of I2C master/slave for the cc430 line and the x2xxx
  line (tested on the cc430f5137 and msp430f235).
- Extensions of tos-stm25p header-file generation scripts to support
  models other than the stm25p80
- Dallas/Maxim Onewire device enumeration and dynamic bus management
- Drivers for the following chips:
  - Mcp9700: Analog thermistor (
    http://ww1.microchip.com/downloads/en/DeviceDoc/21942e.pdf )
  - APDS9007: Analog photo sensor (
    http://www.avagotech.com/docs/AV02-0512EN )
  - DS1825: One-wire digital thermistor (
    http://datasheets.maxim-ic.com/en/ds/DS1825.pdf )
  - CC1190: 850-950 MHz RF Front end (
    http://www.ti.com/lit/ds/symlink/cc1190.pdf )

The repositories from People Power Co (http://www.peoplepowerco.com)
(mainly by Peter Bigot and David Moss) included the RF1A radio stack,
implementation of some of the MSP430xv2 USCI module, and a number of
other elements necessary to working with the cc430 platform.  However,
these did not share a common commit point with the de facto main tinyos-2.x
svn-git mirror (http://git.hinrg.cs.jhu.edu/git/tinyos-2.x.svn). In
September of 2011, I manually merged their changes with the main
tinyos repo.

The original repos can be found at osian.git.sourceforge.net:
- osian from People Power Co
  http://osian.git.sourceforge.net/git/gitweb.cgi?p=osian/osian;a=summary 
- The tinyos-2.x repository from People Power Co.
  http://osian.git.sourceforge.net/git/gitweb.cgi?p=osian/tinyos-2.x;a=summary

This repository has more-or-less forked the work in the
tos/chips/msp430/x2xxx/usci directory into tos/chips/msp430/usci_gen1
. This is geared towards supporting a project in which cc430 and
msp430f235 chips need to communicate with each other over I2C (as
master/slave).  The existing structure in the tinyos core made it very
cumbersome to implement the I2C slave mode properly (behavior such as
holding the I2C clock line to pause transmission, for instance, was
impossible).  Using a USCI implementation on the msp430f235 which is
relatively similar to that in use on the cc430f5137 makes it easier
for us to develop for our current project.  At some undetermined point
in the future, I would like it if we could clean up the USCI
implementations to leverage code reuse wherever possible, but the most
important thing for us at the moment is ensuring that we have robust
I2C master and slave implementations for these chips, and code
minimization is a distant second. That being said, I've included some
preliminary notes that explain how some degree of compatibility with
the x2xxx code could be achieved in the usci_gen1 directory.


