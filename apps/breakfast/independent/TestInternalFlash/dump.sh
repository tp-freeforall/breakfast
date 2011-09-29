#!/bin/sh
usage () {
  echo "$0 pwFile dev outputFile"
  exit 1
}

dump () {
  label=$1
  start=$2
  length=$3
  echo -n "$label ..." 
  cc430-bsl -S 9600 -c $dev -u $start -s $length -x -P $pwFile >> $outputFile 2> /dev/null
  if [ $? -eq 0 ]
  then
    echo OK
  else
    echo ERROR
    exit 1
  fi
}

[ $# -eq 3 ] || usage 
pwFile=$1
dev=$2
outputFile=$3
[ -e $outputFile ] && rm $outputFile

dump "bsl, info, dd" 0x1000 0xa80
#dump "program_1" 0x5c00 0xa400 
#dump "program_2" 0x10000 0x35000 

echo "output in $outputFile"
