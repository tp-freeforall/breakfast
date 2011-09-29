#!/bin/sh

index=0
for f in configs/generated/*C.nc
do 
  cname=$(basename $f | cut -d '.' -f 1)
  working=$(grep -c "^$index\$" ok_configs)
  if [ $working -eq 0 ]
  then
    echo "/* Non-working config! $cname"
  fi

  cat <<EOF

  enum{
    ${cname}_LOCAL_ID=unique(UQ_RF1A_MULTI_CONFIG_CLIENT),
  };
  components ${cname};
  Rf1aMultiPhysicalP.SubConfigure[${cname}_LOCAL_ID]
    -> ${cname};
  Rf1aMultiPhysicalP.SubGet[${cname}_LOCAL_ID] 
    -> ${cname};

EOF
  if [ $working -eq 0 ]
  then
    echo "*/"
  fi
  index=$(expr 1 + $index)
done
