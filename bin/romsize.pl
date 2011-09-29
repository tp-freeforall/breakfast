#!/usr/bin/perl

# Usage: romsize.pl build/telosb/main.exe

$FNAME = $ARGV[0];

$cmd = "msp430-objdump -x $FNAME";
open(CMD, "$cmd|") || die "Cannot run $cmd\n";

while (<CMD>) {
 ($off, $k1, $k2, $type, $size, $name) = split;
 @nameparts = split('\$', $name);
 if ($type eq ".text") {
   $romsize{$nameparts[0]} += hex($size);
   $ramsize{$nameparts[0]} += 0;
   $totalromsize += hex($size);
 }
 if ($type eq ".bss" || $type eq ".data") {
   $romsize{$nameparts[0]} += 0;
   $ramsize{$nameparts[0]} += hex($size);
   $totalramsize += hex($size);
 }
}

print "# ROM size\t\tRAM size\t\tComponent name\n";

foreach $comp (keys(%romsize)) {
 print "$romsize{$comp}\t\t$ramsize{$comp}\t\t$comp\n";
}

print "$totalromsize\t\t$totalramsize\t\tTOTAL ******************\n";
