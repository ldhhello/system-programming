#!/bin/bash

function introduce() {
	if [ $# -ne 2 ]; then
		return 1
	fi	

	STD_ID=$1
	STD_NAME=$2

	echo "안녕하세요, 저는 $STD_ID $STD_NAME입니다."
}

introduce $1 $2

if [ $? -ne 0 ]; then
	echo "error"
fi

export STD_ID=$STD_ID
export STD_NAME=$STD_NAME
