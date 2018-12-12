#!/bin/bash

mkdir results

rm results/* 2> /dev/null

for i in `seq 0 39` ; do
	echo `./acgt status/status$i &` > results/$i
done;


while [ `wc -w results/* | grep -c 1` -ne 40 ] ; do 
	sleep 1
done;

sum=0
squaredsum=0

for i in `seq 0 39` ; do
	var=$(cat results/$i)
	sum=`expr "$sum" + "$var"`
	square=`expr "$var" "*" "$var"`
	squaredsum=$(echo "$square" + "$squaredsum" | bc -l)
done;


moyenne=`expr "$sum" / 40`
moyennecarre=$(echo "$moyenne * $moyenne " | bc)
divider=$(echo "scale = 3; 1 / 40" | bc)
divided=$(echo "$divider * $squaredsum" | bc)
variance=$(echo "$divided - $moyennecarre" | bc)
ecarttype=$(echo "sqrt($variance)" | bc)

echo "nombre moyen d itérations : $moyenne"
echo "écart-type : $ecarttype"


rm results -r




