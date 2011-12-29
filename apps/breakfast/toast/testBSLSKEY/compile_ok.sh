#!/bin/bash
msp430-gcc -mmcu=msp430f235 -T msp430.x -o bin/toggle.bin toggle.c bslskey.S
