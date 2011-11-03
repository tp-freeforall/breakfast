#!/bin/sh
#set -x
if [ $# -lt 2 ]
then
  echo "usage: $0 <device> <file> [extraArg ...]"
  exit 1
fi
dev=$1
file=$2
shift 2
set -x
~/tinyos-2.x/bin/cc430-bsl --invertRTS --noadg715 -S 115200 -c $dev -e $@ $file
