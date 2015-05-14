#!/bin/bash

RUNS=10000
TMPFILE=$(mktemp /tmp/${tempfoo}.XXXXXX)

function countTurns { # ai name
	./build/lode <<EOF | tail -4 | head -1 | awk '{print $4}'
$1
$1
EOF
}

function benchmark { # ai name, number of runs
	echo -en "\033[s" # save cursor position
	:> "$TMPFILE";
	for i in $(seq 1 $2); do
		countTurns "$1" >> "$TMPFILE";
		if [[ $(($i % 100)) -eq "0" ]]; then
			echo -n "."
		fi
	done;
	echo -en "\033[u" # restore cursor position
	echo -en "\033[0K" # clear line
	cat "$TMPFILE" | awk '{sum += $1; count += 1} END {print sum/count}'
}

echo "Sample of $RUNS runs"
for AI in "ai"{1,2,3}; do
	echo -n "$AI: "
	benchmark "$AI" "$RUNS"
done

rm "$TMPFILE"
