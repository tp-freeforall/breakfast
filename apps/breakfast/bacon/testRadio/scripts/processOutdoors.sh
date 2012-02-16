#!/bin/bash
if [ $# -lt 1 ]
then 
  echo "Usage: $0 <prefix> dir..." 1>&2
  exit 1
fi
prefix=$1
rssiFile=$prefix.rssi
receptionFile=$prefix.reception
shift 1

while [ $# -gt 0 ]
do
  dir=$1
  if [ $(ls *.ia | wc -l) -ne 1 ]
  then
    echo "more or fewer than one .ia file in $dir" 1>&2
    shift 1
    break 
  fi
  iaFile=$1/*.ia
  if [ $(grep -c 'GPS_FIX_AVAIL=1' $iaFile) -eq 0 ]
  then
    echo "no GPS fix for $dir" 1>&2
    shift 1
    break
  fi

  rxFile=$(tempfile)
  lat=$(grep LATITUDE $iaFile | head -1 | tr '=' ' ' | cut -d ' ' -f 1 --complement)
  latDec=$(echo "$lat" | python $(dirname $0)/dmsToDec.py)
  lon=$(grep LONGITUDE $dir/*.ia | head -1 | tr '=' ' ' | cut -d ' ' -f 1 --complement)
  lonDec=$(echo "$lat" | python $(dirname $0)/dmsToDec.py)
  
  awk '/^[0-9]+\.[0-9]+ RX [0-9]+ (0|1) (-)?[0-9]+ [0-9]+ (0|1) [0-9]+ [0-9]+ [0-9]+ (-)?[0-9]+ (0|1) [0-9]+ (0|1) 1$/{print $0}' $dir/*.rx | cut -d ' ' -f 2 --complement > $rxFile
  
  txPower=$(head -1 $rxFile | cut -d ' ' -f 10)
  txFe=$(head -1 $rxFile | cut -d ' ' -f 13)
  awk --assign lat=$latDec --assign lon=$lonDec \
    --assign power=$txPower --assign txFe=$txFe \
    '{print lon, lat, $3, txFe, power, $4}' $rxFile >> $rssiFile
  awk --assign lat=$latDec --assign lon=$lonDec \
    --assign power=$txPower --assign txFe=$txFe \
    '{print lon, lat, 2,  txFe, power, $2}' $rxFile >> $rssiFile
  awk --assign lat=$latDec --assign lon=$lonDec \
    --assign power=$txPower --assign txFe=$txFe \
    '{print lon, lat, $3, txFe, power, $9}' $rxFile >> $receptionFile

  shift 1
done

sqlite3 $prefix.db <<EOF
CREATE TABLE RSSI (
  lon REAL,
  lat REAL,
  rxType INTEGER,
  txType INTEGER,
  rssi INTEGER);
CREATE TABLE RECEPTION(
   lon REAL,
   lat REAL,
   rxType INTEGER,
   txType INTEGER,
   sn INTEGER);
.separator ' '
.import $rssiFile RSSI
.import $receptionFile RECEPTION
CREATE TABLE PRR AS
  SELECT lon, lat, rxType, txType, count(*)/(max(sn) - min(sn) + 1) as PRR
  FROM RECEPTION
  GROUP BY lon, lat, rxType, txType;
EOF
