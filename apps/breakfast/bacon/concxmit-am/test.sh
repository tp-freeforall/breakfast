#!/bin/sh
index=$1
make -f Makefile.receiver surf CFLAGS+=-DTEST_CONFIG_$index \
  install bsl,/dev/ttyUSB0
make -f Makefile.sender em430 CFLAGS+=-DTEST_CONFIG_$index \
  install bsl,/dev/ttyUSB1

python receiver.py /dev/ttyUSB0 42 1 1 1 > results/$index
