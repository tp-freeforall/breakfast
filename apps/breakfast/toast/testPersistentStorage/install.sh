#!/bin/bash
if [ $# -lt 3 ]
then
  echo "Usage: $0 dev password-file exe-file" 1>&2 
  exit 1
fi

dev=$1
pw=$2
exe=$3
set -x
/home/carlson/local/src/tinyos-2.x/tools/platforms/msp430/msp430-bsl/msp430-bsl.py -D -D -D --invert-reset --invert-test -c $dev -r --mainerase -I -P $pw -p $exe 
