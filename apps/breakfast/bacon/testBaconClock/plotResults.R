csvFileName <- 'data/all.csv'
outdir <- 'figs/'
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

bpSet <- rawData

##compare different board type/xcap settings
#pdf(paste(outdir,'freq_vs_type_xcap.pdf', sep=""))
#boxplot(Frequency ~ BoardType*XCAP, data=bpSet, show.names=TRUE, las=2)
#title("Frequency v. BoardType.XCAP")
#garbage <- dev.off()
#
#compare different boards of same type
pdf(paste(outdir,'freq_dist_asb_xcap.pdf', sep=""))
boxplot(Frequency~Board*XCAP, data=droplevels(bpSet[bpSet$BoardType == "asb",]), show.names=TRUE, las=2)
title("Frequency v. Board.XCAP (asb)")
garbage <- dev.off()

pdf(paste(outdir,'freq_dist_sn_xcap.pdf',sep=""))
boxplot(Frequency~Board*XCAP, data=droplevels(bpSet[bpSet$BoardType == "sn",]), show.names=TRUE, las=2)
title("Frequency v. Board.XCAP (sn)")
garbage <- dev.off()

#only look at xcap = 0
bpSet <- rawData[rawData$XCAP == 0,]

pdf(paste(outdir,'freq_vs_type.pdf', sep=""))
boxplot(Frequency ~ BoardType, data=bpSet, show.names=TRUE, las=2)
title("Frequency v. BoardType (xcap=0)")
garbage <- dev.off()

#compare different boards of same type
pdf(paste(outdir,'freq_dist_asb.pdf', sep=""))
boxplot(Frequency~Board, data=droplevels(bpSet[bpSet$BoardType == "asb",]), show.names=TRUE, las=2)
title("Frequency v. Board (xcap=0) (asb)")
garbage <- dev.off()

pdf(paste(outdir,'freq_dist_sn.pdf',sep=""))
boxplot(Frequency~Board, data=droplevels(bpSet[bpSet$BoardType == "sn",]), show.names=TRUE, las=2)
title("Frequency v. Board (xcap=0) (sn)")
garbage <- dev.off()



#trend
XCAPSetting <- 0
yCol <- "Frequency.s"
if (yCol == "ErrorPPM"){
  ylab <- "Error (PPM)"
  centerGuide <- 0
  upperGuide <- 20
  lowerGuide <- - 20
} else if (yCol == "Frequency.centered"){
  ylab <- "Hz from mean"
  centerGuide <- 0
  lowerGuide <- 0
  upperGuide <- 0
} else if (yCol == "Frequency.s"){
  ylab <- "Hz"
  centerGuide <- 32768
  maxErr <- (20/1000000)*32768
  lowerGuide <- 32768 - maxErr
  upperGuide <- 32768 + maxErr
}

pdf(paste(outdir, 'stability_hz.pdf', sep=""))
ylim <- range(c(lowerGuide, upperGuide, merged[yCol]))
xlim <- c(0, max((merged$Midpoint)))
plot(c(0),c(0), pch="", ylim=ylim, xlim=xlim, xlab="Seconds",
ylab=ylab)

legendName <- c()
legendLty <- c()
legendCol <- c()

#lcols <- rainbow(length(unique(merged$BoardType)))
lcols <- c("red", "blue")
lcolIndex <- 1

for( bt in unique(merged$BoardType)){
  boardVals <- merged[(merged$BoardType==bt),]
  boardVals <- boardVals[(boardVals$XCAP==XCAPSetting),]
  llty <- 1
  lcol <- lcols[lcolIndex]
  for (board in unique(boardVals$Board)){
    legendName <- c(legendName, paste(bt, ".", board))
    legendLty <- c(legendLty, llty)
    legendCol <- c(legendCol, lcol)
    s <- boardVals[boardVals$Board == board, c("Midpoint", yCol)]
    s <- s[order(s$Midpoint),]
    lines(s$Midpoint, s[,yCol], lty=llty, col=lcol)
    llty <- llty + 1
  }
  lcolIndex <- lcolIndex + 1
}

abline(h=centerGuide, col="gray", lty=2)
abline(h=lowerGuide, col="gray")
abline(h=upperGuide, col="gray")


legend("topright", legend=legendName, lty=legendLty, col=legendCol)
title(paste("Stability v. time (XCAP=", as.character(XCAPSetting),")"))
dev.off()
