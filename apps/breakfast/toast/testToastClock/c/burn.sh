#!/bin/sh

if [ $# -lt 2 ]
then
  echo "usage: $0 comport file"
  exit 1
fi

comport=$1
file=$2
shift 2

/opt/osian/tinyos/tools/platforms/msp430/msp430-bsl/msp430-bsl.py \
  --invert-reset --invert-test -c $comport -r $@ $file

##to read the calibration values out of memory:
#msp430-bsl.py -c /dev/ttyUSB0 --upload=0x10F8 --size=8 --invert-test --invert-reset --password <your_file.o>
##where <your_file.o> is the binary you used to program it with the dco calibration program.
