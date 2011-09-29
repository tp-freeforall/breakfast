#!/bin/sh
if [ $# -lt 1 ]
then
  echo "usage: $0 test-results-dir"
  echo "  If dir doesn't exist, test each config individually.
  Otherwise, generate compile flags based on contents of result
  directory"
  exit 1
fi

numSurfs=$(motelist | grep -c 'SuRF')
numEMs=$(motelist | grep -c 'FTDI')
if [ $numEMs -ne 1 -o $numSurfs -ne 1 ]
then
  echo "You must plug in a SuRF board and one em430 (connected via FTDI chip)"
  exit 1
fi
em430dev=$(motelist | awk '/FTDI/{print $2}')
surfdev=$(motelist | awk '/SuRF/{print $2}')

resultsDir=$1
if [ ! -d $resultsDir ]
then
  if [ ! -e $resultsDir ]
  then
    mkdir -p $resultsDir
    #config ids are in range from 0 to 41
    for index in $(seq 0 41)
    do
      make -f Makefile.receiver surf CFLAGS+=-DTEST_CONFIG_$index \
        install bsl,$surfdev
      make -f Makefile.sender em430 CFLAGS+=-DTEST_CONFIG_$index \
        install bsl,$em430dev
      python receiver.py $surfdev 42 1 1 1 > $(resultsDir)/$index.out
    done
  fi
fi

set -x
cat $resultsDir/*.out | grep 'received\: 1' \
  | cut -d ' ' -f 2 | sort -g | uniq \
  | awk '{printf "CFLAGS+=-DRF1A_USE_CONFIG_%d ",$1}' \
  > working_cflags
make -f Makefile.receiver surf $(cat working_cflags) \
  install bsl,$surfdev
make -f Makefile.sender em430 $(cat working_cflags) \
  install bsl,$em430dev
sleep 10
python receiver.py $surfdev $(awk '{print NF}' working_cflags) 1 1 1
