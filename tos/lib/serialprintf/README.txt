Add a bare-serial printf component.

This component links the platform-specific UartByte implementation into a
global putchar function, where it will be used by the C runtime system as
the destination for printf(3c).  It allows easy access to a read-only stream
of information from the application without the overhead of using
SerialActiveMessage.  In lineage, it is a horribly emasculated derivative of
tos/lib/printf/PrintfP, removing the buffering capability along with active
message support.

Use hyperterminal, minicom, or on Linux just cat /dev/mote/0 to see the
output.
