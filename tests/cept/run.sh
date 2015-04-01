#!/bin/bash

function invoke { // $1 stdin
	echo "$1" | $BIN & PID=$! && sleep .1 && kill -9 "$PID"
	echo ""
}
export -f invoke


export DIR=$(dirname $0)
export BIN="$DIR/../../build/lode"
find "$DIR/cases" -type f -iname "*.sh" -print0 | while IFS= read -r -d $'\0' TESTCASE; do
	echo ">$TESTCASE<"
	bash "$TESTCASE"
	RES=$?

	echo -n "- ["
	[[ "$RES" -ne 0 ]] && echo -n " " || echo -n "x"
	echo "] $TESTCASE"
done
