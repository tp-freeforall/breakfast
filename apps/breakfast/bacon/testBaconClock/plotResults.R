csvFileName <- 'data/all.csv'
colNames <- c("BoardType", "Board", "XCAP", "Duration", "Midpoint", "Frequency")
rawData <- read.csv(csvFileName, header = FALSE, sep=",", col.names=colNames) 

means <- aggregate(x=list(Frequency=rawData$Frequency),
  by=list(BoardType=rawData$BoardType, Board=rawData$Board, 
    XCAP=rawData$XCAP), 
  FUN=mean)

merged <- merge(means, rawData, by=c("BoardType", "Board", "XCAP"),
  suffixes=c(".m", ".s"))

merged$Frequency.centered <- merged$Frequency.s - merged$Frequency.m
merged$ErrorPPM <- ((merged$Frequency.s - 32768)/32768)*1000000

#boxplot of frequency per device/XCAP setting
boxplot(Frequency ~ BoardType*Board*XCAP, data=rawData, show.names=TRUE)
title("Frequency v. BoardType.Board.XCAP")

devAskNewPage(TRUE)

#trend
XCAPSetting <- 0
usePPM <- TRUE
if (usePPM){
  yCol <- "ErrorPPM"
  ylab <- "Error (PPM)"
} else {
  yCol <- "Frequency.centered"
  ylab <- "Hz from mean"
}

ylim <- range(merged[yCol])
xlim <- c(0, max((merged$Midpoint)))
plot(c(0),c(0), pch="", ylim=ylim, xlim=xlim, xlab="Seconds",
ylab=ylab)

legendName <- c()
legendLty <- c()
legendCol <- c()

lcols <- rainbow(length(unique(merged$BoardType)))
lcolIndex <- 1
for( bt in unique(merged$BoardType)){
  print(bt)
  boardVals <- merged[merged$BoardType==bt && merged$XCAP==XCAPSetting,]
  llty <- 1
  lcol <- lcols[lcolIndex]
  for (board in unique(boardVals$Board)){
    legendName <- c(legendName, board)
    legendLty <- c(legendLty, llty)
    legendCol <- c(legendCol, lcol)
    lines(boardVals[boardVals$Board == board, "Midpoint"], 
      boardVals[boardVals$Board == board, yCol], lty=llty, col=lcol)
    llty <- llty + 1
  }
  lcolIndex <- lcolIndex + 1
}
legend("topright", legend=legendName, lty=legendLty, col=legendCol)
title(paste("Stability v. time (XCAP=", as.character(XCAPSetting),")"))
