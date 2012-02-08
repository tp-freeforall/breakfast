#!/bin/bash
while [ $# -gt 0 ]
do
  rxFile=$(tempfile)
  txFile=$(tempfile)
  setupFile=$(tempfile)
  dbName=$1.db
#cat > $rxFile <<EOF
#unixts RX receiver rx_fe rssi lqi hgm_rx sender sn power hgm_tx channel tx_fe
#EOF

  awk '/^[0-9]+\.[0-9]+ RX [0-9]+ (0|1) (-)[0-9]+ [0-9]+ [0-9]+ [0-9]+ [0-9]+ [0-9]+ (-)[0-9]+ (0|1) [0-9]+ (0|1)$/{print $0}' $1 | cut -d ' ' -f 2 --complement >> $rxFile

#cat >$txFile <<EOF
#unixts TX sender sn power hgm_tx channel tx_fe
#EOF


  awk '/^[0-9]+\.[0-9]+ TX [0-9]+ [0-9]+ [0-9]+ (-)[0-9]+ (0|1) [0-9]+ (0|1)$/{print $0}' $1 | cut -d ' ' -f 2 --complement >> $txFile


  awk '/^[0-9]+\.[0-9]+ SETUP [0-9]+ [0-9]+ (0|1) (0|1) (0|1) [0-9]+ (-)[0-9]+ .+$/{print $0}' $1 | cut -d ' ' -f 2 --complement > $setupFile

#delete if it already exists
[ -f $dbName ] && rm $dbName
sqlite3 $dbName <<EOF
CREATE TABLE TX (
  unixTS REAL,
  sender INTEGER,
  testNum INTEGER,
  sn INTEGER,
  power INTEGER,
  txHGM INTEGER,
  channel INTEGER,
  txFE INTEGER
);
CREATE TABLE RX (
  unixTS REAL,
  receiver INTEGER,
  rxFE INTEGER,
  rssi REAL,
  lqi INTEGER,
  rxHGM INTEGER,
  sender INTEGER,
  testNum INTEGER,
  sn INTEGER,
  power INTEGER,
  txHGM INTEGER,
  channel INTEGER,
  txFE INTEGER
);
CREATE TABLE SETUP (
  unixTS REAL,
  testNum INTEGER,
  nodeId INTEGER,
  isSender INTEGER,
  hgm INTEGER,
  fe INTEGER,
  channel INTEGER,
  power INTEGER,
  testDesc TEXT
);
.separator ' '
.import $rxFile RX
.import $txFile TX
.import $setupFile SETUP
EOF
  rm $txFile
  rm $rxFile
  rm $setupFile
  shift 1
done


