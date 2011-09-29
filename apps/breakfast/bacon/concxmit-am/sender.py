#!/usr/bin/env python
import tos
import sys

AM_CMD = 0xDC
AM_RECEIVER_REPORT = 0xDD
AM_SENDER_REPORT = 0xDE

CMD_NEXT=0x01
CMD_SEND=0x02

class SenderReportPacket(tos.Packet):
    def __init__(self, packet):
        tos.Packet.__init__(self,
                            [('configId',       'int', 2),
                             ('seqNum',         'int', 2)],
                            packet)

s = tos.Serial(sys.argv[1], 115200, debug=False)
am = tos.AM(s)

while True:
    p = am.read()
    if p and p.data and p.type == AM_SENDER_REPORT:
        rpt = SenderReportPacket(p.data)
        print rpt
    elif p:
        print p

