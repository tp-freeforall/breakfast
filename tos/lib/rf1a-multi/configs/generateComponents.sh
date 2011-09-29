#!/bin/sh
for f in includes/*.h
do
  CONFIGNAME=$(basename $f | tr '.' '_' | tr '[:lower:]' '[:upper:]')
  sed "s/INCLUDENAME/$(basename $f)/" templates/templateC.nc | sed "s/CONFIGNAME/${CONFIGNAME}/" > generated/${CONFIGNAME}C.nc
done
