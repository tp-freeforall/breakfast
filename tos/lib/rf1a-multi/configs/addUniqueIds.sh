#!/bin/sh

id=0
for f in includes/*.h
do
  defName="$(basename $f | tr [[:lower:]] [[:upper:]] | tr '.' '_')_GLOBAL_ID"
  tmpFile=mktemp
  grep -v $defName $f > $tmpFile
  echo "#define $defName $id" >> $tmpFile
  mv $tmpFile $f

  id=$(expr $id + 1)
done
