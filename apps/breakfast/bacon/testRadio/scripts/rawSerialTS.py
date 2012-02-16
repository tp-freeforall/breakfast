#!/usr/bin/env python
import serial
import time
import sys

def usage():
    print >> sys.stderr, """Usage: python %s <port> [baud=115200]"""

if __name__ == '__main__':
    if len(sys.argv) < 2:
        usage()
        sys.exit(1)
    port = sys.argv[1]
    if len(sys.argv) > 2:
        baud = int(sys.argv[2])
    else:
        baud = 115200
    s = serial.Serial(port, baud)
    line = s.readline()
    while line:
        print time.time(), line,
        line = s.readline()
