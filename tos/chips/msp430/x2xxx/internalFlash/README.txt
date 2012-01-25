See comments in the top of each file for usage. The InternalFlashC
component will "just work" like the previous one (under
lib/net/Deluge/extra/msp), with the notable difference that only 63
bytes are available (instead of 127).

The TLVStorage interface defines a set of commands that can be used to
manipulate the "tag-length-value" structure that is generally found in
segment A (containing DCO and ADC12 calibration constants, plus some
extra space).

!!!PLEASE NOTE!!!!
All of these components assume that the flash module's clock generator
is already set up (e.g. in the platform initialization process).  If
this is not the case, then the system defaults will be used, which may
or may not work.

See the relevant datasheet for your MCU to find out the acceptable
range for the "Flash timing generator frequency."  If you use the
default settings for the SMCLK, then it should "just work," but if you
increase or decrease the SMCLK, then you'll need to modify FCTL2
appropriately to select the clock source and set the divider.

For example, on the F235, if SMCLK is running at 4 mhz then you need
to divide it down by ~12 to get it right in the middle of the
acceptable range (257-476 khz). Faster or slower than this and the
flash operations are not reliable.
