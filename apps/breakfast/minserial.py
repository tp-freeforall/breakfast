#!/usr/bin/env python
import serial
import sys

class MinPort(object):
    def __init__(self, port, baud):
        self.sp = serial.Serial(port, 
            9600, 
            parity=serial.PARITY_EVEN,
            timeout=None)

    def flushInput(self):
        print "flush in"
        self.sp.flushInput()

    def flushOutput(self):
        print "flush out"
        self.sp.flushOutput()

    def setRSTn(self, value=1):
        print "setting RSTn to %d"%value
        self.sp.setRTS(not value)

    def read(self, numbytes=1):
        print "reading %d"%numbytes
        return self.sp.read(numbytes)

    def write(self, data):
        print "writing %s"%data
        return self.sp.write(data)

def flushAndStart(mp):
    mp.flushInput()
    mp.flushOutput()
    mp.setRSTn(1)

if __name__ == '__main__':
    port = "/dev/ttyUSB0"
    baud = 115200
    if len(sys.argv) > 1:
        port = sys.argv[1]
    if len(sys.argv) > 2:
        baud = sys.argv[2]
    mp = MinPort(port, int(baud))
    flushAndStart(mp)
    print mp.read(1)
    print mp.write("hi")
    #in this config, read works, we can stop/start by writing to RSTn
    #unfortunately, connecting *will* cause it to restart
