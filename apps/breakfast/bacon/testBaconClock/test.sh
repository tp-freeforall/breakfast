#!/bin/bash

if [ $# -lt 4 ]
then
  echo "usage: $0 XCAP_setting XT1_INITIAL_DRIVE XT1_FINAL_DRIVE comport [ti]" 1>&2
  exit 1
fi
xcap=$1
xtInitial=$2
xtFinal=$3
comport=$4

if [ "$5" == ti ]
then
  echo "using TI test app"
  app=cc430x513x_UCS_4
else
  echo "using Doug's wacky test app"
  app=testclocks
fi

make clean && make CFLAGS="-DXCAP_SETTING=$xcap -DXT1_INITIAL_DRIVE=$xtInitial -DXT1_FINAL_DRIVE=$xtFinal" && ./burn.sh $comport bin/$app.hex 
echo "hit enter to start test"
read line
picocom -b 9600 $comport
