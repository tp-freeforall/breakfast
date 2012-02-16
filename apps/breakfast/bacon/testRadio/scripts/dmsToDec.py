#!/usr/bin/env python
import sys

for line in sys.stdin:
    (ns, d, m, s) = line.strip().split()
    (d, m, s) = map(float, (d, m, s))
    if ns in [ "S", "W"]:
        d *= -1
    print d+(m/60) + (s/3600)
