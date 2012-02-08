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
linkStability <- function(dbName){
  connString <- paste("Driver=SQLite3;Database=", dbName, sep="")
  ch <- odbcDriverConnect(connString)
  #TODO: moving average?
  #TODO: since we switch the rx behavior between tests, but assume
  # that we can group by testNum, we can't easily compare in one
  # figure all setups.
  devAskNewPage(T)
  
  testNums <- sqlQuery(ch, "SELECT DISTINCT testNum FROM setup")
  for (testNum in testNums$testNum){
    #print(testNum)
    txInfoQuery <- paste('SELECT * FROM setup WHERE',
      ' testNum=', testNum, ' AND isSender=1', sep='')
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
  
    plot(c(-10), c(-10), xlim=c(0, testDuration$duration),
      ylim=c(rssiLimits$rssiMin, rssiLimits$rssiMax), 
      xlab="Time(s)",
      ylab="RSSI")
    title(paste(txInfo$testDesc,': ', txInfo$power, 
      'dBm HGM: ', txInfo$hgm, ' FE: ', txInfo$fe))
  
    
    for (rxInfoIndex in seq_along(rxInfos[,1])){
      rxInfo <- rxInfos[rxInfoIndex,]
      rssiQuery <- paste('SELECT unixTS - ', testDuration$start, ' as time,',
        ' rssi',
        ' FROM RX WHERE testNum=', testNum,
        ' AND receiver=', rxInfo$nodeId,
        sep='')
      rssi <- sqlQuery(ch, rssiQuery)
      #print(rssiQuery)
      if (rxInfo$fe == 1){
        lineCol <- 'blue'
      }else{
        lineCol <- 'red'
      }
      if (rxInfo$hgm == 1){
        linePch <- 1
      } else{
        linePch <- ''
      }
      lines(rssi$time, rssi$rssi, col=lineCol, pch=linePch, type='o')
    }
    legend('bottomleft',legend=c('FE','ANT','HGM'),
      lty=c(1,1,0), pch=c(1), pt.cex=c(0,0,1), col=c('blue','red','blue'))
  }
  devAskNewPage(F)
}


#TODO: plot moving average of PRR vs. time (left join TX to RX)
prr <- function(dbName, maS, ipi){
  maWindow <- maS*(1024/ipi)
  devAskNewPage(T)
  connString <- paste("Driver=SQLite3;Database=", dbName, sep="")
  ch <- odbcDriverConnect(connString)
  testNums <- sqlQuery(ch, "SELECT DISTINCT testNum FROM setup")
  for (testNum in testNums$testNum){
    txInfoQuery <- paste('SELECT * FROM setup WHERE',
      ' testNum=', testNum, ' AND isSender=1', sep='')
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
      ylab=paste("PRR (window: ", (maWindow*64)/1024, ' s )', sep=''))
    title(paste(txInfo$testDesc,': ', txInfo$power, 
      'dBm HGM: ', txInfo$hgm, ' FE: ', txInfo$fe))
    for (rxInfoIndex in seq_along(rxInfos[,1])){
      rxInfo <- rxInfos[rxInfoIndex,]
      receptionQuery <- paste('SELECT TX.unixTS - ',
          testDuration$start, ' as time,',
        ' coalesce(RX.received, 0) as received FROM TX LEFT JOIN RX ON (',
        '   RX.testNum = TX.testNum AND RX.sn = TX.sn ',
        '   AND RX.receiver=',rxInfo$nodeId,
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
      if (rxInfo$hgm == 1){
        linePch <- 1
      } else{
        linePch <- ''
      }
      lines(receptions$time, receptions$MA, col=lineCol, pch=linePch, type='o')
      #TODO: add points for receptions?
    }
    legend('bottomleft',legend=c('FE','ANT','HGM'),
      lty=c(1,1,0), pch=c(1), pt.cex=c(0,0,1), col=c('blue','red','blue'))
  } 
  devAskNewPage(F)
  close(ch)
}

prr(dbName, 5, 64)
