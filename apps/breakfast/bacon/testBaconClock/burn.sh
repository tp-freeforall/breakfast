#!/bin/sh

if [ $# -lt 2 ]
then
  echo "usage: $0 comport file"
  exit 1
fi

comport=$1
file=$2
shift 2
set -x
/home/carlson/local/src/tinyos-2.x/bin/cc430-bsl --noadg715 --invert-reset  -S 115200 -c $comport -r -e -I -p $file
