#!/bin/bash
while [ $# -gt 0 ]
do
#  rxFile=$(tempfile)
#  txFile=$(tempfile)
#  setupFile=$(tempfile)
  rxFile=$1.rx
  txFile=$1.tx
  setupFile=$1.setup
  dbName=$1.db
#cat > $rxFile <<EOF
#unixts RX receiver rx_fe rssi lqi hgm_rx sender sn power hgm_tx channel tx_fe
#EOF
  awk '/^[0-9]+\.[0-9]+ RX [0-9]+ (0|1) (-)?[0-9]+ [0-9]+ (0|1) [0-9]+ [0-9]+ [0-9]+ (-)?[0-9]+ (0|1) [0-9]+ (0|1) (0|1)$/{print $0,1}' $1 | cut -d ' ' -f 2 --complement >> $rxFile

#cat >$txFile <<EOF
#unixts TX sender sn power hgm_tx channel tx_fe
#EOF


  awk '/^[0-9]+\.[0-9]+ TX [0-9]+ [0-9]+ [0-9]+ (-)?[0-9]+ (0|1) [0-9]+ (0|1)$/{print $0}' $1 | cut -d ' ' -f 2 --complement >> $txFile


  awk '/^[0-9]+\.[0-9]+ SETUP [0-9]+ [0-9]+ (0|1) (0|1) (0|1) [0-9]+ (-)?[0-9]+ .+$/{print $0}' $1 | cut -d ' ' -f 2 --complement > $setupFile

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
  txFE INTEGER,
  crcPassed INTEGER,
  received INTEGER
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
--Identify orphaned RX's
CREATE TEMP TABLE rxTests as
  SELECT receiver, testNum 
    FROM RX WHERE crcPassed = 1
  EXCEPT
  SELECT nodeId, testNum FROM setup WHERE isSender=0;

--pull the relevant setup info from the first one
CREATE TEMP TABLE rxTestSetups as
  SELECT RX.unixTS as start, RX.testNum, RX.receiver, 0 as isSender,
    RX.rxHGM, RX.rxFE, RX.channel, RX.power, "UNKNOWN"
  FROM RX JOIN rxTests ON 
    (RX.receiver = rxTests.receiver AND RX.testNum = rxTests.testNum)
  JOIN (
    SELECT receiver, testNum, min(unixTS) as start 
    FROM RX GROUP BY receiver, testNum
  ) RXFirst ON (
    RXFirst.receiver = RX.receiver AND RXFirst.start = RX.unixTS
  );

--append to setup table
INSERT INTO setup SELECT * FROM rxTestSetups;

--identify orphaned TX's
CREATE TEMP TABLE txTests as
  SELECT sender, testNum 
    FROM TX 
  EXCEPT
  SELECT nodeId, testNum FROM setup WHERE isSender=1;

--pull the relevant setup info from the first one
CREATE TEMP TABLE txTestSetups as
  SELECT TX.unixTS as start, TX.testNum, TX.sender, 1 as isSender,
    TX.txHGM, TX.txFE, TX.channel, TX.power, "UNKNOWN"
  FROM TX JOIN txTests ON 
    (TX.sender = txTests.sender AND TX.testNum = txTests.testNum)
  JOIN (
    SELECT sender, testNum, min(unixTS) as start 
    FROM TX GROUP BY sender, testNum
  ) TXFirst ON (
    TXFirst.sender = TX.sender AND TXFirst.start = TX.unixTS
  );
--append to setup table
INSERT INTO setup SELECT * FROM txTestSetups;
EOF
#  rm $txFile
#  rm $rxFile
#  rm $setupFile
  shift 1
done


