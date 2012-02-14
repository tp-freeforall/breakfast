#!/bin/bash
set -x 
#around 800 packets per minute, 150 seconds is about 2000 packets
#testDuration=1600
#testDuration=150
testDuration=21600

ltx=62
lrx=71
rtx=63
rrx=66
if [ $# -lt 2 ]
then
  echo "Usage: $0 <first_test_id> <test_desc>"
  exit 1
fi
#start numbering at this 
testNum=$1
testDesc=\\\"$2\\\"

function prepareBinary(){
  isSender=$1
  hgm=$2
  report=$3
  useLongIpi=$4
  channel=$5
  power=$6
  hasFe=$7
  make bacon IS_SENDER=$isSender POWER_INDEX=$power HGM=$hgm CHANNEL=$channel REPORT=$report USE_LONG_IPI=$useLongIpi HAS_FE=$hasFe TEST_NUM=$testNum TEST_DESC=$testDesc
}

function blink(){
  pushd . 
  cd ~/tinyos-2.x/apps/Blink
  make bacon
  while [ $# -gt 0 ]
  do
    make bacon reinstall,$1 wpt,map.bacon
    shift 1
  done
  popd
  sleep 10
}

function install(){
  while [ $# -gt 0 ]
  do
    #read line
    make bacon reinstall,$1 wpt,map.breakfast
    shift 1
  done
}

#for power in 0 1 2 3
for power in 2 3
do
  #for rxHgm in "TRUE" "FALSE"
  for rxHgm in "TRUE"
  do
    #for sender in $rtx $ltx
    for sender in $rtx $ltx
    do 
      echo "PROGRESS Power $power RXHgm $rxHgm sender $sender"

      if [ "$sender" == "$rtx" ]
      then
        testNum=$(($testNum + 1))
        echo "PROGRESS FE HGM TX: $testNum"
        blink $ltx $lrx $rtx $rrx
        prepareBinary FALSE FALSE TRUE TRUE 0 $power FALSE
        install $lrx 
        prepareBinary FALSE $rxHgm TRUE TRUE 0 $power TRUE
        install $rrx
        prepareBinary TRUE TRUE TRUE TRUE 0 $power TRUE
        install $sender
        sleep $testDuration
        
#        testNum=$(($testNum + 1))
#        echo "PROGRESS FE standard TX: $testNum"
#        blink $ltx $lrx $rtx $rrx
#        prepareBinary FALSE FALSE TRUE TRUE 0 $power FALSE
#        install $lrx 
#        prepareBinary FALSE $rxHgm TRUE TRUE 0 $power TRUE
#        install $rrx
#        prepareBinary TRUE FALSE TRUE TRUE 0 $power TRUE
#        install $sender
#        sleep $testDuration

      else
        testNum=$(($testNum + 1))
        echo "PROGRESS ANT standard TX: $testNum"
        blink $ltx $lrx $rtx $rrx
        prepareBinary FALSE FALSE TRUE TRUE 0 $power FALSE
        install $lrx 
        prepareBinary FALSE $rxHgm TRUE TRUE 0 $power TRUE
        install $rrx
        prepareBinary TRUE FALSE TRUE TRUE 0 $power FALSE
        install $sender
        sleep $testDuration

      fi
    done
  done
done
blink $ltx $lrx $rtx $rrx
echo $testNum > lastTestNum
