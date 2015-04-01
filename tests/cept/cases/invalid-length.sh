COUNT=$(invoke "
human
human
0 0
0 0
" | grep 'Carrier' | wc -l | awk '{print $1}')

[[ "$COUNT" -ne 2 ]] && exit 1
exit 0
