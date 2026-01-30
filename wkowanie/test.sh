#!/bin/bash
for((i=1;;i++))
	echo $i > seed
	./generator < seed > test.in 
	./brut < test.in > brut.out 
	./wzor < test.in > wzor.out 
	if diff -b wzor.out brut.out > /dev/null
	then
		echo "OK" $i 
	else
		echo "ZLE" $i 
		break 
	fi 
done