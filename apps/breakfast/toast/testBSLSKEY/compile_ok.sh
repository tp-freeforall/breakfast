#!/bin/bash
set -x
msp430-gcc -mmcu=msp430f235 -T msp430.x -DBSLSKEY_VAL=0xffff -o bin/toggle.bin toggle.c bslskey.S
msp430-objcopy -I elf32-msp430 -O ihex bin/toggle.bin bin/toggle.ihex
