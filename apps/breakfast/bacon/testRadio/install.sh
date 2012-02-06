#!/bin/bash
if [ $# -lt 1 ]
then
cat 1>&2 <<EOF
Usage: $0 <dev>
Options: 
  -s        : node will be sender (default: receiver)
  -h        : turn on high-gain mode (default: off)
  -r        : turn on serial printf reporting. will also increase 
              interpacket interval to 32 ms. 
              (default: off)
  -c <0-255>: channel (default: 16)
  -p <0-3>  : set tx power level: 
                0 ~= -12 dbm 
                1 ~= -6 dbm
                2 ~= 0 dbm
                3 ~= 10 dbm
              (default: 2)
EOF
  exit 1
fi

dev=$1
shift 1

isSender=FALSE
hgm=FALSE
report=FALSE
useLongIpi=FALSE
channel=16
power=2

while [ $# -gt 0 ]
do
  case $1 in 
    -s)
      isSender=TRUE
      shift 1
    ;;
    -h)
      hgm=TRUE
      shift 1
    ;;
    -r)
      report=TRUE
      useLongIpi=TRUE
      shift 1
    ;;
    -c)
      shift 1
      channel=$1
      shift 1
    ;;
    -p)
      shift 1
      power=$1
      shift 1
    ;;
    *)
      echo "unrecognized"
      shift 1
    ;;
  esac
done
set -x 
make bacon IS_SENDER=$isSender POWER_INDEX=$power HGM=$hgm \
  CHANNEL=$channel REPORT=$report USE_LONG_IPI=$useLongIpi \
  install bsl,$dev
