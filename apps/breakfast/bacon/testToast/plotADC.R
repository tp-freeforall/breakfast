x <- read.csv('adc_v_delay.csv', sep=',', header=F, col.names=c('channel', 'time', 'adc', 'delay'))


#x$voltage <- (x$adc/4096)*2.5
x$voltage <- x$adc
x$ts <- x$time / 32768.0

plotGT <- FALSE
if(plotGT){
  gt <- 1.674
}else{
  gt <- min(x$voltage)
}

plot(c(min(x$ts), max(x$ts)),
  c( min(gt, x$voltage), max(gt, x$voltage)),
  pch='')

delayCols <- rainbow(length(unique(x$delay)))
legendText <- c()
legendCols <- c()

i <- 1
for (delay in unique(x$delay)){
  d <- x[x$delay == delay,]
  print(summary(d))
  points(d$ts, d$voltage, col=delayCols[i])
  legendText <- c(legendText, as.character(delay))
  legendCols <- c(legendCols, delayCols[i])
  i <- i+1
}
if (plotGT){
  abline(h=gt, lty=2)
}
print("loop done")
legend('topleft',legend=legendText, col=legendCols, pch=1)

devAskNewPage(T)

#boxplot(voltage ~ delay, x)

devAskNewPage(F)
