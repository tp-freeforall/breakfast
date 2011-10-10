I2C testing
Install this application, then fire up your favorite terminal program
and connect to each board. With ubuntu 11.04 desktop, picocom worked
for me and minicom didn't. connect with `picocom -b 115200
/dev/ttyUSBX'. If all is well, you should see a '.' printed out every
2 seconds. send commands with the keyboard:

Commands:
q - reset
m - increment my address (starts at 'A')
s - increment slave address (starts at 'A')
e - enable general-call
d - disable general-call
c - increment data-to-send (starts at 'a')
a - enable arbitration-test
t - send start-arbitration-test signal
w - write to slave
r - read from slave
g - write to general-call

The tests should all be conducted with at least three boards. 
keys: OA = own-address, SA=slave address, AE= arbitration-test enabled
GC = general-call enabled

Testing basic read/write:
USB  OA  SA  data
0    -   B   x
1    B   -   y
2    -   -   - 

on USB0: r (expect y on 0), w (expect x on 1)

Testing general call
USB  OA  SA  GC  data
0    -   -   -   x
1    -   -   1   -
2    -   -   1   -

on USB0: g (expect x on 1 and 2)

Testing multi-master arbitration: fail on address
USB  OA  SA  AE  data
0    B   C   1   x
1    B   D   1   y
2    C   -   0   -

on USB2: t (expect x on 2, "ARBITRATION LOST" on 1, "WRITE DONE" on 0)

Testing multi-master arbitration: fail on data
USB  OA  SA  AE  data
0    B   D   1   x
1    C   D   1   y (y<x)
2    D   -   0   -

on USB2: t (expect x on 2, "ARBITRATION LOST" on 1, "WRITE DONE" on 0)

Testing multi-master arbitration: fail on address, addressed as slave
USB  OA  SA  AE  data
0    B   C   1   x
1    C   D   1   y
2    D   -   0   -

on USB2: t (expect x on 1, "ARBITRATION LOST" on 1, "WRITE DONE" on 0) 


