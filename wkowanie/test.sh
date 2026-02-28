#!/bin/bash
for((i=1;;i++))
do
	echo $i > seed
	./generator < seed > test.in 
	./wzor < test.in > wzor.out  
	./brut < test.in > brut.out 
	if diff -b wzor.out brut.out > /dev/null
	then
		echo "OK" $i 
	else 
		echo "ZLE" $i 
		break 
	fi
done