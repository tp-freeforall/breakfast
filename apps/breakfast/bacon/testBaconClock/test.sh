#!/bin/bash

if [ $# -lt 2 ]
then
  echo "usage: $0 XCAP_setting comport [ti]" 1>&2
  exit 1
fi
xcap=$1
comport=$2

if [ "$3" == ti ]
then
  echo "using TI test app"
  app=cc430x513x_UCS_4
else
  echo "using Doug's wacky test app"
  app=testclocks
fi

make clean && make CFLAGS=-DXCAP_SETTING=$xcap && ./burn.sh $comport bin/$app.hex 
echo "hit enter to start test"
read line
picocom -b 9600 $comport
