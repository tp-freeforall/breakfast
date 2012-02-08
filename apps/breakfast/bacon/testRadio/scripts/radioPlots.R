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

txSetupsQuery <- "SELECT DISTINCT sender,power,channel,txHGM,txFE FROM TX"

txSetups <- sqlQuery(ch, txSetupsQuery)
for (txSetupIndex in seq_along(txSetups[,1])){
  txSetup <- txSetups[txSetupIndex,]
  print(txSetup)

  rxSetupsQuery <- paste("SELECT DISTINCT receiver,rxHGM,rxFE ",
    "FROM RX WHERE (",
    " RX.sender=", txSetup$sender,
    " AND RX.power=", txSetup$power,
    " AND RX.txFE=", txSetup$txFE,
    " AND RX.txHGM=", txSetup$txHGM,
    " )", sep="")
  rxSetups <- sqlQuery(ch, rxSetupsQuery)

  for (rxSetupIndex in seq_along(rxSetups[,1])){
    rxSetup <- rxSetups[rxSetupIndex,]
    rssiQuery <- paste("SELECT unixTS, rssi FROM RX WHERE (",
      "RX.receiver=", rxSetup$receiver,
      " AND RX.rxHGM=", rxSetup$rxHGM,
      " AND RX.rxFE=", rxSetup$rxFE,
      " AND RX.sender=", txSetup$sender,
      " AND RX.power=", txSetup$power,
      " AND RX.txFE=", txSetup$txFE,
      " AND RX.txHGM=", txSetup$txHGM,
      ") ORDER BY unixTS", sep="")
    print(rssiQuery)
  }
}
close(ch)
