#!/bin/sh
[ $# -eq 2 ] || exit 1
cc430-bsl -D -D -c $1 -S 9600 -P pw.ihex -I -p $2
