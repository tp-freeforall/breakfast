#!/usr/bin/env python
import sys

if __name__ == '__main__':
    for line in sys.stdin:
        if 'DATA' in line:
            print int(line.strip().split()[-1], 16)
