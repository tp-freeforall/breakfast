#TODO: read dbName from args
dbName <- "test.db"

connString <- paste("Driver=SQLite3;Database=", dbName, sep="")
library(RODBC)
ch <- odbcDriverConnect(connString)

#Link stability over time
#TODO: plot RSSI vs. time  (moving average + raw)
#TODO: plot moving average of PRR vs. time

