#!/bin/bash
SEGMENT_SECONDS=10

if [ "$1" == "--segmentLen" ]
then
  SEGMENT_SECONDS=$2
  shift 2
fi

segmentLen=$(( 2 * 32768 * $SEGMENT_SECONDS ))
while [ $# -gt 0 ]
do
  td=$(mktemp -d)
  #break up file into chunks, each chunk *roughly* SEGMENT_SECONDS
  #  long
  echo "processing $1" 1>&2
  tail --lines=+10 $1 | split -l $segmentLen - $td/frag
  for f in $td/frag*
  do 
    if [ $(wc -l < $f) -eq $segmentLen ]
    then
      #pull out first/last RE timestamps
      firstRE=$(head -2 $f | awk -F ',' '($2 == 1){print $1}')
      lastRE=$(tail -2 $f | awk -F ',' '($2 == 1){print $1}')
  
      #count the number of cycles (starting at RE)
      cycles=$(( $(tail --lines=+9 $f | tr -d ' '| grep -c ',1') - 1))
  
      frequency=$(python -c "print (float($cycles)/($lastRE - $firstRE))")
  
      #collect the results to display
      boardType=$(basename $1 | cut -d '.' -f 1)
      board=$(basename $1 | cut -d '.' -f 2)
      xcap=$(basename $1 | cut -d '.' -f 3)
      testNum=$(basename $1 | cut -d '.' -f 4)
      duration=$(echo "$lastRE - $firstRE" | bc)
      midpoint=$(python -c "print (float($lastRE) + float($firstRE))/2.0")
      echo "$boardType,$board,$xcap,$duration,$midpoint,$frequency"
    fi
    rm $f
  done
  rmdir $td
  #move to next file
  shift 1
done
