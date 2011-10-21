#!/bin/sh
mkdir -p master
set +x
for i2c_div in $(seq 8 8 8192)
do
  make -f Makefile.bacon.internal CFLAGS+=-DI2C_DIV=${i2c_div} --always-make
  mv bin/bacon_master.hex master/bacon_master.internal.${i2c_div}.hex
done
