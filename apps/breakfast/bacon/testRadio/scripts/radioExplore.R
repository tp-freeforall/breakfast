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

library(RODBC)

ma <- function(series, width){
  filter(series, rep(1/width, width), sides=1)
}

#Link stability over time
linkStability <- function(dbName, rssiMin=0, rssiMax=0, maS=0, ipi=64){
  connString <- paste("Driver=SQLite3;Database=", dbName, sep="")
  ch <- odbcDriverConnect(connString)
  if(maS != 0){
    maWindow <- maS*(1024/ipi)
    ylabText <- paste('RSSI ( ~', maS,' S m.a.)', sep='')
  }else{
    maWindow <- 1
    ylabText <- 'RSSI'
  }
   
  testNums <- sqlQuery(ch, "SELECT DISTINCT testNum FROM setup WHERE isSender=1 AND ((fe=1 AND hgm=1) OR (fe=0))")
  for (testNum in testNums$testNum){
    #print(testNum)
    txInfoQuery <- paste('SELECT * FROM setup WHERE',
      ' testNum=', testNum, ' AND isSender=1', 
      ' AND ((fe=1 AND hgm=1) OR (fe=0))', sep='')
    testDurationQuery <- paste('SELECT min(unixTS) as start, max(unixTS)-min(unixTS) AS duration', 
      ' FROM TX WHERE testNum=', testNum, sep='')
    rssiLimitsQuery <- paste('SELECT max(rssi) as rssiMax,',
     ' min(rssi) as rssiMin FROM RX WHERE testNum=', testNum, sep='')
    rxInfoQuery <- paste('SELECT * FROM setup WHERE testNum=', 
      testNum,' AND isSender=0', sep="")
  
    txInfo <- sqlQuery(ch, txInfoQuery)
    testDuration <- sqlQuery(ch, testDurationQuery)
    rssiLimits <- sqlQuery(ch, rssiLimitsQuery)
    rxInfos <- sqlQuery(ch, rxInfoQuery)
    yLimits=c(rssiLimits$rssiMin, rssiLimits$rssiMax)
    if (rssiMin!=0 && rssiMax!=0){
      yLimits=c(rssiMin, rssiMax)
    }
    plot(c(-10), c(-10), xlim=c(0, testDuration$duration),
      ylim=yLimits,
      xlab="Time(s)",
      ylab="RSSI")
    title(paste(txInfo$testNum,' ',txInfo$testDesc,': ', txInfo$power, 
      'dBm FE: ', txInfo$fe))
    
    for (rxInfoIndex in seq_along(rxInfos[,1])){
      rxInfo <- rxInfos[rxInfoIndex,]
      rssiQuery <- paste('SELECT unixTS - ', testDuration$start, ' as time,',
        ' rssi',
        ' FROM RX WHERE testNum=', testNum,
        ' AND receiver=', rxInfo$nodeId,
        ' AND crcPassed=1',
        sep='')
      rssi <- sqlQuery(ch, rssiQuery)
      #print(rssiQuery)
      if (rxInfo$fe == 1){
        lineCol <- 'blue'
      }else{
        lineCol <- 'red'
      }
      if (maWindow > 1){
        rssi$MA <- ma(rssi$rssi, maWindow)
        lines(rssi$time, rssi$MA, col=lineCol, lwd=2)
        points(rssi$time, rssi$rssi, col=lineCol, pch='.')
      }else{
        lines(rssi$time, rssi$rssi, col=lineCol)
      }
    }
    legend('bottomleft',legend=c('FE','ANT'),
      lty=c(1,1), col=c('blue','red'))
    devAskNewPage(T)
    #print(rssiDeltaQuery)

  }
  close(ch)
}

rssiDelta <- function(dbName, feReceiver=66, antReceiver=71){
  connString <- paste("Driver=SQLite3;Database=", dbName, sep="")
  ch <- odbcDriverConnect(connString)
  devAskNewPage(T)
  testNums <- sqlQuery(ch, "SELECT DISTINCT testNum FROM setup WHERE isSender=1 AND ((fe=1 AND hgm=1) OR (fe=0))")
  for (testNum in testNums$testNum){
    txInfoQuery <- paste('SELECT * FROM setup WHERE',
      ' testNum=', testNum, ' AND isSender=1', 
      ' AND ((fe=1 AND hgm=1) OR (fe=0))',sep='')
    testDurationQuery <- paste('SELECT min(unixTS) as start, max(unixTS)-min(unixTS) AS duration', 
      ' FROM TX WHERE testNum=', testNum, sep='')

    txInfo <- sqlQuery(ch, txInfoQuery)
    testDuration <- sqlQuery(ch, testDurationQuery)

    rssiDeltaQuery <- paste('SELECT feRX.unixTS - ',
      testDuration$start,' as time,',
      ' feRX.rssi - antRX.rssi as delta',
      ' FROM RX feRX JOIN RX antRX ON feRX.sn=antRX.sn',
      ' WHERE feRX.testNum=', testNum,
      ' AND antRX.testNum=', testNum,
      ' AND feRX.receiver=', feReceiver,
      ' AND antRX.receiver=', antReceiver,
      ' ORDER by feRX.unixTS - ',testDuration$start,
      sep='')
    rssiDelta <- sqlQuery(ch, rssiDeltaQuery)
    #plot(rssiDelta$time, rssiDelta$delta, ylim=c(-30,10), type='l')
    boxplot(rssiDelta$delta, ylim=c(-40, 40))
    title(paste(txInfo$testNum,' ',txInfo$testDesc, ' ',txInfo$power,
      ' dBm fe:',txInfo$fe, sep=' '))
  }
  close(ch)
}

prr <- function(dbName, maS, ipi){
  maWindow <- maS*(1024/ipi)
  connString <- paste("Driver=SQLite3;Database=", dbName, sep="")
  ch <- odbcDriverConnect(connString)
  testNums <- sqlQuery(ch, "SELECT DISTINCT testNum FROM setup WHERE isSender=1 AND ((fe=1 AND hgm=1) OR (fe=0))")
  for (testNum in testNums$testNum){
    txInfoQuery <- paste('SELECT * FROM setup WHERE',
      ' testNum=', testNum, ' AND isSender=1', 
      ' AND ((fe=1 AND hgm=1) OR (fe=0))',sep='')
    testDurationQuery <- paste('SELECT min(unixTS) as start, max(unixTS)-min(unixTS) AS duration', 
      ' FROM TX WHERE testNum=', testNum, sep='')
    rxInfoQuery <- paste('SELECT * FROM setup WHERE testNum=', 
      testNum,' AND isSender=0', sep="")

    txInfo <- sqlQuery(ch, txInfoQuery)
    testDuration <- sqlQuery(ch, testDurationQuery)
    rxInfos <- sqlQuery(ch, rxInfoQuery)
    
    plot(c(-10), c(-10), xlim=c(0, testDuration$duration),
      ylim=c(-0.1, 1.1), 
      xlab="Time(s)",
      ylab=paste("PRR (window: ", maS, ' s )', sep=''))
    title(paste(txInfo$testNum,' ',txInfo$testDesc,': ', txInfo$power, 
      'dBm HGM: ', txInfo$hgm, ' FE: ', txInfo$fe))
    for (rxInfoIndex in seq_along(rxInfos[,1])){
      rxInfo <- rxInfos[rxInfoIndex,]
      receptionQuery <- paste('SELECT TX.unixTS - ',
          testDuration$start, ' as time,',
        ' coalesce(RX.received, 0) as received FROM TX LEFT JOIN RX ON (',
        '   RX.testNum = TX.testNum AND RX.sn = TX.sn ',
        '   AND RX.receiver=',rxInfo$nodeId,
        '   AND crcPassed=1',
        ' ) ', 
        ' WHERE TX.testNum =', testNum,
        ' ORDER BY TX.unixTS',
        sep='')
      #print(receptionQuery)
      receptions <- sqlQuery(ch, receptionQuery)
      receptions$MA <- ma(receptions$received, maWindow)
      if (rxInfo$fe == 1){
        lineCol <- 'blue'
      }else{
        lineCol <- 'red'
      }
      lines(receptions$time, receptions$MA, col=lineCol)
      #TODO: add points for receptions?
    }
    legend('bottomleft',legend=c('FE','ANT'),
      lty=c(1,1), col=c('blue','red'))
    devAskNewPage(T)
  } 
  close(ch)
}

#prr(dbName, 5, 64)
#linkStability(dbName, maS=5)
devAskNewPage(F)
