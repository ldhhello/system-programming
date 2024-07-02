#!/bin/bash

for ((i=2; i<=9; i++))
do
	for ((j=1; j<=9; j++))
	do
		k=$((i*j))

		if [ $k -gt 50 ]; then
			continue
		fi
		echo "$i * $j = $k"
	done

	echo
done
