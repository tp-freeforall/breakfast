#!/bin/bash
while [ $# -gt 0 ]
do
  rxFile=$(tempfile)
  txFile=$(tempfile)
  setupFile=$(tempfile)
#  rxFile=$1.rx
#  txFile=$1.tx
#  setupFile=$1.setup
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


--These queries only keep data where there's no FE, or there is an FE
--  and it's in HGM
DROP TABLE IF EXISTS txSetup;
CREATE TABLE txSetup AS SELECT * FROM setup WHERE isSender=1
AND (fe=0 OR (fe=1 AND hgm=1))
;

DROP TABLE IF EXISTS testDuration;
CREATE TEMP TABLE testDuration AS 
  SELECT testNum, min(unixTS) as start,
    max(unixTS) - min(unixTS) as duration 
  FROM TX 
  WHERE testNum in (SELECT testNum from txSetup) 
  GROUP BY testNum 
  ORDER BY testNum;

DROP TABLE IF EXISTS rxAlign;
CREATE TABLE rxAlign AS
  SELECT RX.testNum, RX.sn, 
  RX.unixTS - testDuration.start AS time, 
  RX.receiver, RX.rssi, RX.lqi, RX.received
  FROM RX
  JOIN testDuration on RX.testNum = testDuration.testNum
  WHERE RX.crcPassed= 1 AND RX.received=1
  ORDER BY RX.testNum, RX.sn, time, RX.receiver;

DROP TABLE IF EXISTS txAlign;
CREATE TABLE txAlign AS
  SELECT TX.unixTS - testDuration.start as time, 
    TX.testNum, TX.sn, TX.sender
  FROM TX
  JOIN testDUration on TX.testNum = testDuration.testNum
  ORDER by TX.testNum, time;

DROP TABLE IF EXISTS rxSetup;
CREATE TABLE rxSetup AS
  SELECT setup.testNum, setup.nodeId, setup.fe, setup.hgm
  FROM setup 
  WHERE isSender=0
  AND (fe=0 OR (fe=1 AND hgm=1))
  ;

DROP TABLE IF EXISTS rssiGain;
CREATE TABLE rssiGain AS
  SELECT feRX.testNum, feRX.sn, feRX.time, 
    feRX.rssi - antRX.rssi as feGain
  FROM rxAlign as feRX
  JOIN rxAlign as antRX ON 
    (feRX.testNum = antRX.testNum AND feRX.sn = antRX.sn)
  JOIN rxSetup feRxSetup ON
    (feRX.receiver = feRxSetup.nodeId AND
      feRX.testNum = feRxSetup.testNum)
  JOIN rxSetup antRxSetup ON
    (antRX.receiver = antRxSetup.nodeId AND
      antRX.testNum = antRxSetup.testNum)
  WHERE antRxSetup.fe = 0 AND feRxSetup.fe=1;

DROP TABLE IF EXISTS losses;
CREATE TABLE losses as 
  SELECT rxSetup.testNum, rxSetup.nodeId, txAlign.sn
  FROM rxSetup
  JOIN txAlign on rxSetup.testNum = txAlign.testNum
  EXCEPT
  SELECT rxAlign.testNum, rxAlign.receiver, rxAlign.sn
  FROM rxAlign;

 DROP TABLE IF EXISTS receptions;
 CREATE TABLE receptions AS
   SELECT rxAlign.testNum, rxAlign.sn, rxAlign.time, rxAlign.receiver,
     1 as received
   FROM rxAlign
   UNION
   SELECT losses.testNum, losses.sn, txAlign.time, 
     losses.nodeId as receiver, 0 as received
   FROM losses 
   JOIN txAlign on losses.testNum=txAlign.testNum 
     AND losses.sn = txAlign.sn;

--   SELECT txAlign.testNum, txAlign.sn, txAlign.time, rxAlign.receiver,
--     coalesce(rxAlign.received, 0) AS received
--   FROM txAlign
--   LEFT JOIN rxAlign ON 
--     rxAlign.testNum = txAlign.testNum AND rxAlign.sn = txAlign.sn
--   ORDER BY txAlign.testNum, txAlign.sn, txAlign.time;


--de-normalized for easy plottin'
DROP TABLE IF EXISTS rssiGainBoxplot;
CREATE TABLE rssiGainBoxplot AS
  SELECT rssiGain.testNum, rssiGain.time, rssiGain.feGain, 
    txSetup.fe, txSetup.power
  FROM rssiGain
  JOIN txSetup ON txSetup.testNum=rssiGain.testNum;

EOF
  rm $txFile
  rm $rxFile
  rm $setupFile
  shift 1
done


