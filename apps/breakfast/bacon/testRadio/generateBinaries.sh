for channel in 0
do
  make bacon TEST_DESC=\\\"outdoor\\\" IS_SENDER=0 HGM=0 HAS_FE=FALSE CHANNEL=$channel REPORT=TRUE USE_LONG_IPI=FALSE && make bacon id.4 && mv build/bacon/main.ihex.out-4 build/bacon/p104ant.rx.$channel.ihex 
  make bacon TEST_DESC=\\\"outdoor\\\" IS_SENDER=0 HGM=1 HAS_FE=TRUE CHANNEL=$channel REPORT=TRUE USE_LONG_IPI=FALSE && make bacon id.18 && mv build/bacon/main.ihex.out-18 build/bacon/p108fe.rx.$channel.ihex 

  for power in 2 3
  do
    make bacon TEST_DESC=\\\"outdoor\\\" IS_SENDER=1 HGM=1 HAS_FE=TRUE CHANNEL=$channel POWER_INDEX=$power REPORT=TRUE USE_LONG_IPI=FALSE && make bacon id.14 && mv build/bacon/main.ihex.out-14 build/bacon/p104fe.tx.$channel.$power.ihex 
    make bacon TEST_DESC=\\\"outdoor\\\" IS_SENDER=1 HGM=0 HAS_FE=FALSE CHANNEL=$channel POWER_INDEX=$power REPORT=TRUE USE_LONG_IPI=FALSE && make bacon id.5 && mv build/bacon/main.ihex.out-5 build/bacon/p105ant.tx.$channel.$power.ihex 
  done
done
