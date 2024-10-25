#!/bin/bash

BOLD="\033[1m"
COLOR="\033[36m"
VCOLOR="\033[35m"
RED="\033[1;31m"
GREEN="\033[1;32m"
E_NC="\033[0m"


# List of RPN expressions and their expected results
expressions=(
	"3 4 +"
	"5 1 2 + 4 * + 3 -"
	"2 3 1 * + 9 -"
	"4 2 /"
	"7 2 3 * -"
	"10 2 8 * + 3 -"
	"15 7 1 1 + - / 3 * 2 1 1 + + -"
	"5 9 8 + 4 6 * * 7 + *"
	"3 4 2 * 1 5 - 2 3 ^ ^ / +"
	"2 3 + 5 *"
	"4 0 /"
	"6 2 3 + /"
	"8 0 4 - /"
	"9 3 3 / /"
	"5 1 2 + 4 * + 3 - 0 /"
	"3 4 + 2 * 7 /"
	"3 4 + 2 * -5 +"
	"5 1 2 + 4 * + 3 -"
	"9 4 6 + 2 * 3 / 7 2 - 1 + *"
	"29 7 6 * - 5 + 92 + 2 /"
	"0 0 /"
)


expectedResults=(
	"7"
	"14"
	"-4"
	"2"
	"1"
	"23"
	"5"
	"2075"
	"3.00012"
	"25"
	"ERROR"
	"1.2"
	"-2"
	"9"
	"ERROR"
	"2"
	"9"
	"14"
	"ERROR"
	"42"
	"ERROR"
)

subject=(
	"4 2 ^ 3 *"
	"8 9 * 9 - 9 - 9 - 4 - 1 +"
	"7 7 * 7 -"
	"1 2 * 2 / 2 * 2 4 - +"
	"(1 + 1)"
)

subjectResults=(
	"ERROR"
	"42"
	"42"
	"0"
	"ERROR"
)

# Determine which set of expressions to use
if [ "$D" == "0" ]; then
	expressions=("${subject[@]}")
	expectedResults=("${subjectResults[@]}")
fi

if [ "$S" == "0" ]; then
	VALGRIND="${VAL}"
	COLOR="${VCOLOR}"
fi

test="\033[1;31mERROR: Invalid token in expression: ^ "
testE="ERROR"


	# Output the boolean variable


# Execute each expression and print the result along with the expected result
for i in "${!expressions[@]}"; do
	expr="${expressions[$i]}"
	expected="${expectedResults[$i]}"
	echo -e "Test $i ${BOLD}${COLOR} $VALGRIND ./RPN \"$expr\" ${E_NC}\n"
	resultStr=$($VALGRIND ./RPN "$expr")
	resultBool=$?
	if [ $resultBool -eq 1 ]; then
		evaluate="ERROR"
	else
		echo -n -e "r: $resultStr"
		evaluate="${resultStr}"
	fi
	
	if [ "$evaluate" == "$expected" ] ; then
		echo -e " ---> ${GREEN} OK${E_NC}"
	else
		echo -e " ---> ${RED} K0 ${E_NC} $evaluate ($expected)"
	fi
	echo -e "---------------------------------------------\n"
done