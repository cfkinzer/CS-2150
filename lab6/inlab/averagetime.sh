#!/bin/bash
# Christian Kinzer
# cfk5ax
# 10/23/18
# 9:30 AM Lab
# averagetime.sh

echo "Enter dictionary file."
read d
echo "Enter grid file."
read g

RUNTIME=`./a.out $d $g | tail -1`
total=0
total=`expr $total + $RUNTIME`

RUNTIME2=`./a.out $d $g | tail -1`
total=`expr $total + $RUNTIME2`

RUNTIME3=`./a.out $d $g | tail -1`
total=`expr $total + $RUNTIME3`

RUNTIME4=`./a.out $d $g | tail -1`
total=`expr $total + $RUNTIME4`

RUNTIME5=`./a.out $d $g | tail -1`
total=`expr $total + $RUNTIME5`
total=`expr $total / 5`

echo "average runtime: " $total

