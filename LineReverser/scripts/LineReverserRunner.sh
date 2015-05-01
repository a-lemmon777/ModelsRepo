#!/bin/bash

TEST_FILES=(file10000.txt file20000.txt file40000.txt file80000.txt file160000.txt)
echo ${TEST_FILES[*]}

cd ../bin
for file in "${TEST_FILES[@]}"
do
	time java reverser.Main ../testFiles/$file < /dev/zero
done
