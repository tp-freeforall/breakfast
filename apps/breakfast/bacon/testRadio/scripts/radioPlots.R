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

connString <- paste("Driver=SQLite3;Database=", dbName, sep="")
library(RODBC)
ch <- odbcDriverConnect(connString)

#Link stability over time
#TODO: plot RSSI vs. time  (moving average + raw)
#TODO: plot moving average of PRR vs. time (left join TX to RX)

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

  #TODO: set up plot
  #TODO: label with TX info
  #print(txInfoQuery)
  #print(txInfo)

  #print(testDurationQuery)
  #print(testDuration)
  
  #print(rssiLimitsQuery)
  #print(rssiLimits)

  #print(rxInfoQuery)
  #print(rxInfos)
  for (rxInfoIndex in seq_along(rxInfos[,1])){
    rxInfo <- rxInfos[rxInfoIndex,]
    #TODO: record RX setup for legend
    rssiQuery <- paste('SELECT unixTS - ', testDuration$start, ',',
      ' rssi',
      ' FROM RX WHERE testNum=', testNum,
      ' AND receiver=', rxInfo$nodeId,
      sep='')
    #TODO: plot rssi vs. t
    #print(rssiQuery)
  }
}
close(ch)
