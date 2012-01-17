The nodes that will send almost-concurrently get built with 

make -f Makefile.sender

and the one that will trigger them/record results with

make -f Makefile.receiver

It will run their DCOs at 64 MHz, and I believe that MCLK is 1/2 that and SMCLK is 1 MHz (binary). 

The receiver is controlled by receiver.py. It will cycle through all of the
valid radio modulation schemes that I was able to find in TI's provided files.
For each setting, it will trigger a number of concurrent-ish transmissions,
controlled with a negative pulse of the provided width (specified in SMCLK
cycles). 

The senders are controlled by three pins: 
 - the "next-config" pin (P2.0), which means "switch to the next radio
   modulation scheme"

 - the "send-ready" pin (P2.1), which means "load the next packet into
   the TX registers and enable the 'send' interrupt"

 - The "send" pin (P2.2), which triggers the loaded packet to be sent. 
   - If the SENDER1 variable is defined, it will send with TX_POWER_1
     (~-12 dBm) at the start of the pulse (falling edge)
   - If it's not defined, it will send with TX_POWER_2 (~ 0 dBm) at
     the end of the pulse (rising edge)

The senders will send a message to serial (readable with sender.py)
whenever they send a packet, which can be used to make sure that
everything's working as expected.

The Rf1aMulti interface has a setConfigId method which can be used to
give it a specific configuration, which may be better than using the
"next-config" command to cycle through all of them. The ID's in
question are on the last line of each of the files found in
tos/lib/rf1a-multi/configs/includes/*.h. 
