#!/bin/bash

BOLD="\033[1m"
CYAN="\033[36m"
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
	"3.0001220703125"
	"25"
	"Error (Division by zero)"
	"1.2"
	"-2"
	"9"
	"Error (Division by zero)"
)

subject=(
	"8 9 * 9 - 9 - 9 - 4 - 1 +"
	"7 7 * 7 -"
	"1 2 * 2 / 2 * 2 4 - +"
	"(1 + 1)"
)

subjectResults=(
	"42"
	"42"
	"0"
	"Error"
)

# Determine which set of expressions to use
if [ "$D" == "0" ]; then
    expressions=("${subject[@]}")
    expectedResults=("${subjectResults[@]}")
fi

# Execute each expression and print the result along with the expected result
for i in "${!expressions[@]}"; do
	expr="${expressions[$i]}"
	expected="${expectedResults[$i]}"
	echo -e "\n ${BOLD}${CYAN} ./RPN \"$expr\" ${E_NC}"
	result=$(./RPN "$expr")
	echo "$result (Expected: $expected)"
done