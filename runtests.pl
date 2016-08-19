#!/usr/bin/perl
use strict;
use warnings;

my $exitval = 0;

system('./Morpheus_Vector_normTest.exe');
$exitval = $exitval | $?;
system('./Morpheus_Vector_addScaleTest.exe');
$exitval = $exitval | $?;
system('./Morpheus_Matrix_Tests.exe');
$exitval = $exitval | $?;

exit $exitval;
