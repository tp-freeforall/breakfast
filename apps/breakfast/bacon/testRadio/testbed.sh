#!/bin/bash
set -x 
#around 800 packets per minute, 150 seconds is about 2000 packets
testDuration=1600

ltx=62
lrx=71
rtx=63
rrx=66

function prepareBinary(){
  isSender=$1
  hgm=$2
  report=$3
  useLongIpi=$4
  channel=$5
  power=$6
  make bacon IS_SENDER=$isSender POWER_INDEX=$power HGM=$hgm CHANNEL=$channel REPORT=$report USE_LONG_IPI=$useLongIpi
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
  sleep 60
}

function install(){
  while [ $# -gt 0 ]
  do
    #read line
    make bacon reinstall,$1 wpt,map.breakfast
    shift 1
  done
}

for power in 0 1 2 3
#for power in 0 3
do
  for rxHgm in "TRUE" "FALSE"
  #for rxHgm in "TRUE"
  do
    for sender in $rtx $ltx
    do 
      echo "PROGRESS Power $power RXHgm $rxHgm sender $sender"
      if [ "$sender" == "$rtx" ]
      then 
        echo "PROGRESS HGM TX"
        blink $ltx $lrx $rtx $rrx
        prepareBinary FALSE $rxHgm TRUE TRUE 0 $power
        install $lrx $rrx
        prepareBinary TRUE TRUE TRUE TRUE 0 $power
        install $sender
        sleep $testDuration
      fi

      echo "PROGRESS standard TX"
      blink $ltx $lrx $rtx $rrx
      prepareBinary FALSE $rxHgm TRUE TRUE 0 $power
      install $lrx $rrx
      prepareBinary TRUE FALSE TRUE TRUE 0 $power
      install $sender
      sleep $testDuration
        
    done
  done
done
blink $ltx $lrx $rtx $rrx
