#!/bin/bash
if [ $# -lt 2 ]
then
    echo "Usage: $0 <duration> <label>" 1>&2
    exit 1
fi

duration=$1
prefix=$2
numMotes=$(motelist | grep -c "/dev/ttyUSB")
mkdir -p $(dirname $prefix)
echo "Logging for $numMotes devices for $duration seconds"

if [ -f logjobs ]
then
    echo "Killing old jobs"
    for pid in $(cat logjobs)
    do
        kill $pid
    done
    rm logjobs
fi

date +%s > $prefix.startTime

for dev in $(motelist | awk '/USB/{print $2}')
do
    python $(dirname $0)/rawSerialTS.py $dev > $prefix.$(basename $dev).rx &
    echo "$!" >> logjobs
done
stopTime=$(( $(date +%s) + $duration))
while [ $(date +%s) -lt $stopTime ]
do
  echo "$(($stopTime - $(date +%s))) seconds left: "
  wc -l $prefix.*
  sleep 5
  echo "-----"
done

for pid in $(cat logjobs)
do
    kill $pid
done
rm logjobs
