args <- c()

#This iterates through the stuff on the command line after --args and
# for every key=value pair, assigns value to key (multiple appearances
# get stored as list)
for (e in commandArgs()[(which(commandArgs() == "--args")+1):length(commandArgs())]){
  ep = strsplit(e,"=",fixed=TRUE)
  name=ep[[1]][1]
  val=ep[[1]][2]
  if(exists(name)){
      assign(name, c(get(name), val))
  } else{
      assign(name, val)
  }
  args <- c(args, name)
}

#dbName <- 'data/0211.hwlab.db'

library(RODBC)

ma <- function(series, width){
  filter(series, rep(1/width, width), sides=1)
}

rssiTimeSeries <- function(dbName, txPower, testLabel='Untitled',
    pdfOutput='', pngOutput='', maS=30, ipi=64, 
    feLwd=3, antLwd=1, feCol='blue', antCol='red'){
  if (pdfOutput != ''){
    pdf(pdfOutput)
  } else if(pngOutput != ''){
    png(pngOutput)
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
  if(pngOutput != ''){
    garbage<-dev.off()
  }
}

prrTimeSeries <- function(dbName, txPower, testLabel='Untitled', 
    pdfOutput='', pngOutput='', maS=30, ipi=64, feLwd=3, antLwd=1, feCol='blue', antCol='red'){
  if (pdfOutput != ''){
    pdf(pdfOutput)
  } else if(pngOutput != ''){
    png(pngOutput)
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
  if(pngOutput != ''){
    garbage<-dev.off()
  }
}


rssiGain <- function(dbName, txPower, testLabel='Untitled',
    pdfOutput='', pngOutput=''){
  if (pdfOutput != ''){
    pdf(pdfOutput)
  } else if(pngOutput != ''){
    png(pngOutput)
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
  if(pngOutput != ''){
    garbage<-dev.off()
  }
}

rssiTimeSeries(dbName, testLabel=testLabel, txPower=0, maS=60,
  pngOutput=paste('figures/', dbName,'.rssi.0.png', sep=''))
rssiTimeSeries(dbName, testLabel=testLabel, txPower=10, maS=60,
  pngOutput=paste('figures/', dbName,'.rssi.10.png', sep=''))
rssiGain(dbName, testLabel=testLabel, txPower=0, 
  pngOutput=paste('figures/', dbName,'.gain.0.png', sep=''))
rssiGain(dbName, testLabel=testLabel, txPower=10, 
  pngOutput=paste('figures/', dbName,'.gain.10.png', sep=''))
prrTimeSeries(dbName, testLabel=testLabel, txPower=0, maS=60,
  pngOutput=paste('figures/', dbName,'.prr.0.png', sep=''))
prrTimeSeries(dbName, testLabel=testLabel, txPower=10, maS=60,
  pngOutput=paste('figures/', dbName,'.prr.10.png', sep=''))
