#!/bin/bash
for f in $(find $1 -type f -name '*.ia')
do
  if [ $(grep -c 'GPS_FIX_AVAIL=1' $f) -gt 0 ]
  then
    #awk '/GPS_FIX_TIME=02/{print $0}' $f
    gpsTime=$(dos2unix < $f | grep GPS_FIX_TIME | tr '=' ' ' | awk '($2 != 0){print $2,$3,$4,(($5)-5),$6,$7}' )
    gpsTimeStamp=$(dos2unix < $f | awk -F '=' '/GPS_FIX_VALUE_TIME/{print $2}' )
    rssi=$(dos2unix < $f | awk -F '=' '/RSSI_AVG/{print $2}' )
    #echo "$f $gpsTime $rssi"
    echo -n "$f "
    echo -n "$gpsTimeStamp "
    echo -n "$gpsTime "
    echo "$rssi"
  else
    echo "$f NO_GPS"
  fi
done
