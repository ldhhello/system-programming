#!/bin/bash

if (( $1 <= $2 && $1 <= $3 )); then
	echo "최소값: $1"
elif (( $2 <= $1 && $2 <= $3 )); then
	echo "최소값: $2"
else
	echo "최소값: $3"
fi

if (( $1 >= $2 && $1 >= $3 )); then
	echo "최대값: $1"
elif (( $2 >= $1 && $2 >= $3 )); then
	echo "최대값: $2"
else
	echo "최대값: $3"
fi
