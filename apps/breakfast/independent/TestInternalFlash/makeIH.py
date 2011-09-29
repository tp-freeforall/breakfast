#!/usr/bin/env python
import sys

def convertAndChecksum(addr, rt, data):
    s = (addr + ('%X'%rt).zfill(2) + data).upper()
    recordLen = len(data)/2
    s = ('%X'%recordLen).zfill(2) + s
    bs = [ s[i:i+2] for i in range(len(s))[::2]]
    bv = [ int(b, 16) for b in bs]
    lsb = sum(bv) & 0xFF
    checksum = 0x100 - lsb
    checksum = ('%X'%(checksum)).zfill(2)
    return ':%s%s'%(s, checksum)

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print "usage: %s address recordType data"%sys.argv[0]
        exit(1)
    addr = sys.argv[1]
    rt = int (sys.argv[2])
    dataS = sys.argv[3]
    print convertAndChecksum(addr, rt, dataS)
