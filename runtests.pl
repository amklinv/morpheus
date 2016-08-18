#!/usr/bin/perl
use strict;
use warnings;

system('./Morpheus_Vector_normTest.exe | grep -q FAILED');
system('./Morpheus_Vector_addScaleTest.exe');
system('./Morpheus_Matrix_Tests.exe');
