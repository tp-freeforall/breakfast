Connections:
- Port 1.1 J7.1 of all connected together (send pin)
- Port 1.4 J7.4 of all connected together (enable pin)
- Port 2.4 J7.7 of all connected together (pseduo-reset pin)

Install on senders with:

#first sender
make -f Makefile.sender bacon CFLAGS+=-DSENDER1 install bsl,/dev/ttyUSBXXX

#second sender
make -f Makefile.sender bacon install bsl,/dev/ttyUSBXXX



Install on receiver with:

make -f Makefile.receiver bacon SEND_1_OFFSET=XXX install bsl,/dev/ttyUSBXXX

...where XXX is the offset between the sends, in 32 BINARY Mhz ticks (e.g.
SEND_1_OFFSET=32 -> 1 binary microsecond).

Running the test:
- Fire up serial connections to the senders (e.g. picocom -b 115200
  /dev/ttyUSBXXX)
- Fire up a serial connection to the receiver (e.g. picocom -b 115200
  /dev/ttyUSBYYY). The receiver will log data in the format:
  RX <sn> <rssi> <lqi> <sender-offset>
  e.g.
  RX 125 -20 8 128
- It will also log TIMEOUT if it issues the send command but gets no
  packet.
- The senders will log TX <sn> every time they send, this can be used
  to verify that they're in sync. 
- Other stuff might get printed if something goes wrong, so do a grep
  before parsing the data.
