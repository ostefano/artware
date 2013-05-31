#!/bin/bash
 
tmpfile="tmpfile"
 
if [ -z $1 ]; then echo "I need something to work on!" 1>&2; exit 1; fi
 
xxd -c1 -ps "$1" > "$tmpfile"
 
cntr=0
for i in $(cat "$tmpfile"); do
    echo "$cntr $((0x$i))"
    let "cntr++"
done
 
rm "$tmpfile"

