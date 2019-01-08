#!/bin/bash
# Christian Kinzer
# cfk5ax
# 11/1/18
# 9:30 AM
# averagetime.sh

total=0
average=0
time=0

echo "Enter the exponent for counter.cpp: "
read n

for (( i=1; i<=5; i++ ))
do
    echo "Running iteration $i"
    time=`./a.out $n`
    total=`expr $total + $time`
    echo "Time taken: $time ms"
done

echo "5 iterations took $total ms"

average=`expr $total / 5`
echo "Average time was $average ms"
