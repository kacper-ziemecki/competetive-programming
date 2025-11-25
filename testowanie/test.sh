#!/bin/bash 
g++ -std=c++20 -O2 -fsanitize=undefined,bounds -fstack-protector-strong -Wall -Wextra -pedantic -fno-omit-frame-pointer wzor.cpp -o wzor
if [ $? -ne 0 ]; then 
	echo "BLAD BLAD BLAD KOMPILACJI"
	exit 0 
fi 
g++ -std=c++20 -O2 -fsanitize=undefined,bounds -fstack-protector-strong -Wall -Wextra -pedantic -fno-omit-frame-pointer brut.cpp -o brut
if [ $? -ne 0 ]; then 
	echo "BLAD BLAD BLAD KOMPILACJI"
	exit 0 
fi
g++ -std=c++20 -O2 -fsanitize=undefined,bounds -fstack-protector-strong -Wall -Wextra -pedantic -fno-omit-frame-pointer generator.cpp -o generator
if [ $? -ne 0 ]; then 
	echo "BLAD BLAD BLAD KOMPILACJI"
	exit 0 
fi

for((i=1;;i++))
do
	echo $i > seed
	./generator < seed > test.in 
	./brut < test.in > brut.out 
	./wzor < test.in > wzor.out 
	if diff -b brut.out wzor.out > /dev/null 
	then
		echo "OK" $i 
	else 
		echo "ZLE" $i 
		break 
	fi 
done