#!/bin/bash
while [ $# -gt 0 ]
do
  rxFile=$(tempfile)
  txFile=$(tempfile)
  dbName=$1.db
#cat > $rxFile <<EOF
#unixts RX receiver rx_fe rssi lqi hgm_rx sender sn power hgm_tx channel tx_fe
#EOF

  awk '/^[0-9]+.[0-9]+ RX [0-9]+ (0|1) (-)[0-9]+ [0-9]+ [0-9]+ [0-9]+ [0-9]+ (-)[0-9]+ (0|1) [0-9]+ (0|1)$/{print $0}' $1 | cut -d ' ' -f 2 --complement >> $rxFile

#cat >$txFile <<EOF
#unixts TX sender sn power hgm_tx channel tx_fe
#EOF

  awk '/^[0-9]+.[0-9]+ TX [0-9]+ [0-9]+ (-)[0-9]+ (0|1) [0-9]+ (0|1)$/{print $0}' $1 | cut -d ' ' -f 2 --complement >> $txFile


sqlite3 $dbName <<EOF
CREATE TABLE TX (
  unixTS REAL,
  sender INTEGER,
  sn INTEGER,
  power INTEGER,
  hgmTX INTEGER,
  channel INTEGER,
  txFE INTEGER
);
CREATE TABLE RX (
  unixTS REAL,
  receiver INTEGER,
  rxFE INTEGER,
  rssi REAL,
  lqi INTEGER,
  hgmRX INTEGER,
  sender INTEGER,
  sn INTEGER,
  power INTEGER,
  hgmTX INTEGER,
  channel INTEGER,
  txFE INTEGER
);
.separator ' '
.import $rxFile RX
.import $txFile TX
EOF
  rm $txFile
  rm $rxFile
  shift 1
done


