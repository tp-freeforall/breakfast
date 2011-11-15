#!/bin/sh
addr=$1
as=$2
am=$3
dev=$4
set -x
make toast install GLOBAL_ADDR_LSB=$addr AUTO_SLAVE=$as AUTO_MASTER=$am bsl,$dev
