#!/bin/sh

NUM_ITER=$1
N=$2
Q=$3
TOTAL=0

for i in $(seq 1 $NUM_ITER)
do
  R=`./main $N $Q`
  TOTAL=$((TOTAL+R))
done

echo $TOTAL
echo $NUM_ITER
echo "scale=3 ; $TOTAL / $NUM_ITER" | bc
