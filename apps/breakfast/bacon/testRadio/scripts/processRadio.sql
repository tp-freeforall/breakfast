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


