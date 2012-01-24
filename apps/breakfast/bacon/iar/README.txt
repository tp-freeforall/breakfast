This directory contains IAR projects for restoring TI's bootstrap
loader via a JTAG debugger (e.g. MSP-FET430UIF)

CC430F613x_00.05.04.52_img  : Just the released images from TI
CC430F613x_00.05.04.52_src  : Source code/workspace for building the
                              BSL. Not tested.

In order to restore the BSL, open the workspace file in
CC430F613x_00.05.04.52_src . The Release settings are configured for
the cc430f5137, and the relevant settings have been made so that it
will unlock the BSL memory.  

Use Project -> Download -> Download File... and select the .txt file
under the CC430F613x_00.05.04.52_img directory. If all goes well, this
will restore the BSL to the released version from TI. It seems like
IAR doesn't know how to verify the installation (reads back 0x3fff for
each word it tries to verify), but it does seem to work OK. 

The physical connection for SBW can be seen in the .JPG file in this
directory.

+------^------+
|1 3 5 7 9 b d|
|2 4 6 8 a c e|
+-------------+

Bacon V1: 
1 -> ID     (RST#)
2 -> VBUS   (3V0)
7 -> GND    (TEST/SBWTCK)
9 -> SHLD   (GND)

Bacon V2:
1 -> ID     (RST#)
2 -> VBUS   (3V0)
7 -> SHLD   (TEST/SBWTCK)
9 -> GND    (GND)
