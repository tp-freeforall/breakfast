make telosb IS_SENDER=1 POWER_INDEX=0 HGM=0 CHANNEL=26 REPORT=TRUE USE_LONG_IPI=FALSE && make telosb id.1
mv build/telosb/main.ihex.out-1 build/telosb/tx.ihex
make telosb IS_SENDER=0 POWER_INDEX=0 HGM=0 CHANNEL=26 REPORT=TRUE USE_LONG_IPI=FALSE && make telosb id.2
mv build/telosb/main.ihex.out-2 build/telosb/rx.ihex
