#!/usr/bin/env python

import tos
import sys

AM_REPORT = 0xef

class ReportPacket(tos.Packet):
    def __init__(self, packet):
        tos.Packet.__init__(self,
                            [('node_id',    'int', 1),
                             ('sn',         'int', 4),
                             ('powerLevel', 'sint', 1),
                             ('hgmTx',      'int', 1),
                             ('hgmRx',      'int', 1),
                             ('rssi',       'sint', 1),
                             ('lqi',        'int', 1)],
                            packet)

if __name__ == '__main__':
    dev = "/dev/ttyUSB0"
    if len(sys.argv) >= 2:
        dev = sys.argv[1]

    s = tos.Serial(dev, 115200, debug=False)
    am = tos.AM(s)
    p = am.read()
    while p:
        rpt = ReportPacket(p.data)
        print rpt
        p = am.read()
