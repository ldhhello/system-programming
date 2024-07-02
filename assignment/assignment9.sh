#!/bin/bash

if [ $# -ne 3 ]; then
	echo "Oh no"
	exit 1
fi

guker=$1
suhak=$2
yonger=$3
chongjeom=$((guker+suhak+yonger))
pyeongyun=$((chongjeom/3))

echo "국어: $guker"
echo "수학: $suhak"
echo "영어: $yonger"
echo "총점: $chongjeom"
echo "평균: $pyeongyun"
