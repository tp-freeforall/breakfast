dbName <- 'data/0209.hwlab.db'

library(RODBC)

ma <- function(series, width){
  filter(series, rep(1/width, width), sides=1)
}

rssiTimeSeries <- function(dbName, txPower, testLabel='Untitled', pdfOutput=F, maS=30,
    ipi=64, feLwd=3, antLwd=1, feCol='blue', antCol='red'){
  if (pdfOutput != ''){
    pdf(pdfOutput)
  }
  connString <- paste("Driver=SQLite3;Database=", dbName, sep="")
  ch <- odbcDriverConnect(connString)
  maWindow <- maS*(1024/ipi)

  #rssi time series for given power: includes all 4 radio combinations
  rssiQuery <- paste('SELECT rxSetup.fe as rxFe, txSetup.fe as txFe, txSetup.power,',
   ' rxAlign.time, rxAlign.rssi',
   ' FROM rxAlign', 
   ' JOIN txSetup ON rxAlign.testNum=txSetup.testNum',
   ' JOIN rxSetup on rxAlign.testNum=rxSetup.testNum AND rxAlign.receiver = rxSetup.nodeId',
   ' WHERE txSetup.power=', txPower,
   ' ORDER BY rxAlign.time',
   sep='')
  #print(rssiQuery)
  rssiData <- sqlQuery(ch, rssiQuery)
  #print(summary(rssiData))
  plot(c(-10), c(0), xlim=c(0, max(rssiData$time)),
    ylim=c(min(rssiData$rssi), max(rssiData$rssi)),
    #ylim=c(-65, -30),
    xlab="Time(s)", ylab=paste("RSSI (", maS, " S m.a.)", sep=''))
  for (rxFe in c(0,1)){
    if(rxFe){
      lineCol <- feCol
    } else {
      lineCol <- antCol
    }
    for (txFe in c(0,1)){
      if (txFe){
        lineLwd <- feLwd
      }else{
        lineLwd <- antLwd
      }
      seriesData <- rssiData[((rssiData$rxFe == rxFe) & (rssiData$txFe == txFe)),]
      seriesData$MA <- ma(seriesData$rssi, maWindow)
      lines(seriesData$time, seriesData$MA, col=lineCol, lwd=lineLwd)
    }
  }
  legend("bottomright", col=c(feCol, antCol, feCol, antCol),
    lwd=c(feLwd,feLwd,antLwd,antLwd), 
    legend=c('FE->FE', 'FE->ANT', 'ANT->FE', 'ANT->ANT'))
  title(paste(testLabel,': ',txPower,' dBm'))
  close(ch)
  if(pdfOutput != ''){
    garbage<-dev.off()
  }
}

prrTimeSeries <- function(dbName, txPower, testLabel='Untitled', 
    pdfOutput='', maS=30, ipi=64, feLwd=3, antLwd=1, feCol='blue', antCol='red'){
  if (pdfOutput != ''){
    pdf(pdfOutput)
  }
  connString <- paste("Driver=SQLite3;Database=", dbName, sep="")
  ch <- odbcDriverConnect(connString)
  maWindow <- maS*(1024/ipi)

  prrQuery <- paste('SELECT rxSetup.fe as rxFe, txSetup.fe as txFe,',
    ' txSetup.power, receptions.time, receptions.received',
    ' FROM receptions',
    ' JOIN txSetup on receptions.testNum = txSetup.testNum',
    ' JOIN rxSetup on receptions.testNum = rxSetup.testNum',
    '   AND receptions.receiver = rxSetup.nodeId',
    ' WHERE txSetup.power=', txPower,
    ' ORDER BY receptions.time',
    sep='')

  prrData<-sqlQuery(ch, prrQuery)

  plot(c(-10), c(0), xlim=c(0, max(prrData$time)),
    #ylim=c(-0.1, 1.1),
    ylim=c(0.9, 1.0),
    xlab="Time(s)", ylab=paste("PRR (", maS, " S m.a.)", sep=''))

  for (rxFe in c(0,1)){
    if(rxFe){
      lineCol <- feCol
    } else {
      lineCol <- antCol
    }
    for (txFe in c(0,1)){
      if (txFe){
        lineLwd <- feLwd
      }else{
        lineLwd <- antLwd
      }
      seriesData <- prrData[((prrData$rxFe == rxFe) & (prrData$txFe == txFe)),]
      seriesData$MA <- ma(seriesData$received, maWindow)
      lines(seriesData$time, seriesData$MA, col=lineCol, lwd=lineLwd)
    }
  }
  legend("bottomright", col=c(feCol, antCol, feCol, antCol),
    lwd=c(feLwd,feLwd,antLwd,antLwd), 
    legend=c('FE->FE', 'FE->ANT', 'ANT->FE', 'ANT->ANT'))
  title(paste(testLabel,': ',txPower,' dBm'))
    
  close(ch)
  if(pdfOutput != ''){
    garbage<-dev.off()
  }
}


rssiGain <- function(dbName, txPower, testLabel='Untitled',
    pdfOutput=''){
  if (pdfOutput != ''){
    pdf(pdfOutput)
  }
  connString <- paste("Driver=SQLite3;Database=", dbName, sep="")
  ch <- odbcDriverConnect(connString)
  rssiGainQuery <- paste('SELECT rssiGain.sn, rssiGain.time, ',
    ' rssiGain.feGain, txSetup.fe',
    ' FROM rssiGain ',
    ' JOIN txSetup ON rssiGain.testNum=txSetup.testNum ',
    ' WHERE txSetup.power = ', txPower,
    sep='')
  rssiGainData <-sqlQuery(ch, rssiGainQuery)
  boxplot(feGain ~ fe, data=rssiGainData, ylab="FE Gain",
    xlab="Sender FE")
  title(paste(testLabel,': ', txPower,' dBm'))
  close(ch)
  if(pdfOutput != ''){
    garbage<-dev.off()
  }
}

rssiTimeSeries(dbName, testLabel='HW Lab', txPower=0,
  pdfOutput=paste('figures/', dbName,'.rssi.0.pdf', sep=''))
rssiTimeSeries(dbName, testLabel='HW Lab', txPower=10,
  pdfOutput=paste('figures/', dbName,'.rssi.10.pdf', sep=''))
rssiGain(dbName, testLabel='HW Lab', txPower=0,
  pdfOutput=paste('figures/', dbName,'.gain.0.pdf', sep=''))
rssiGain(dbName, testLabel='HW Lab', txPower=10,
  pdfOutput=paste('figures/', dbName,'.gain.10.pdf', sep=''))
prrTimeSeries(dbName, testLabel='HW Lab', txPower=0,
  pdfOutput=paste('figures/', dbName,'.prr.0.pdf', sep=''))
prrTimeSeries(dbName, testLabel='HW Lab', txPower=10,
  pdfOutput=paste('figures/', dbName,'.prr.10.pdf', sep=''))
