#!/bin/bash

if [ $# -lt 2 ]
then
  echo "usage: $0 XCAP_setting comport" 1>&2
  exit 1
fi
xcap=$1
comport=$2
make clean && make CFLAGS=-DXCAP_SETTING=$xcap && ./burn.sh $comport bin/testclocks.hex
