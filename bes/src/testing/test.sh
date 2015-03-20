#!/bin/bash

## Read input from stdin (given as parameter during execution)
EXEC=${1:-/dev/stdin}
TEST=${2:-0}

## Eye candy!
printf "<><><><><><><><><><><><><><><><><><><><><><>\n\n"
if [ $TEST -eq 0 ]; then
	for i in `seq 1 8`; do
		printf "Executing test no. $i\n"
		## Start the clock!
		START=$(($(date +%s%N)/1000000))
		
		## Run the test
		$EXEC < test0$i.in > test0$i.myout
		
		## Stop the clock!
		END=$(($(date +%s%N)/1000000))
		
		## Calculate the differences and output to terminal
		diff test0$i.out test0$i.myout
		
		## Calculate time difference
		DIFF=$(( $END - $START ))
		
		printf "Test no. $i took $DIFF milliseconds\n\n"
		printf "<><><><><><><><><><><><><><><><><><><><><><>\n\n"
	done
	exit 0
	
else
	printf "Executing test no. $TEST\n"
	## Start the clock!
	START=$(($(date +%s%N)/1000000))
	
	## Run the test
	$EXEC < test0$TEST.in > test0$TEST.myout
	
	## Stop the clock!
	END=$(($(date +%s%N)/1000000))
	
	## Calculate the differences and output to terminal
	diff test0$TEST.out test0$TEST.myout
	
	## Calculate time difference
	DIFF=$(( $END - $START ))
	
	printf "Test no. $TEST took $DIFF milliseconds\n\n"
	printf "<><><><><><><><><><><><><><><><><><><><><><>\n\n"
	exit 0
fi