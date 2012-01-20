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

cc430-bsl --invert-reset --noadg715 -S 115200 -c $dev -e $@ $file
