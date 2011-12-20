Due to some very thorny limitations in the lower layers of the I2C
stack, applications combining both I2C discovery and other I2C-using
code will treat I2CDiscoverableC as a layer in the I2C stack (rather
than as a separate application). 

I2CDiscoverableC will be as transparent as possible so that
applications not using it won't have to take special consideration. 

 - It will pass through the Resource interface
 - When the discovery process is ongoing, it 


The basic issue is that a single client has control of the lower
levels of the I2C stack at any given time (e.g. at Msp430UsciI2CP),
but changing control of the lower levels to another client makes a
mess of the state therein.  For example, if the discoverable module is
using it, but then we get directly addressed as a slave (which should
go to a client since it's not general-call) and a data byte is pending
in the RXBUF, there's no clean way to switch to the new client and
retain the current state (already started, rx pending).  We could
defer reading the RX buffer, yield the resource, and find the relevant
component and inform it that it should request the I2C, but this is
also kind of messy and makes it hard to reason about the state of the
I2C stack's lowest levels. 


Additionally, we don't know ahead of time whether the device will be
addressed with its last assigned address or whether we're going to do
discovery.  So, we can't really know ahead of time which component
should get control of the I2C.  This way, discovery is always
available but won't interfere with other applications.
