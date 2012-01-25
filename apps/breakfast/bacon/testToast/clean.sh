grep -a 'MEASURE' $1 | grep -a -v 'end' | awk '{print $(NF-3), $(NF-2), $(NF- 1), $(NF)}' | tr ' ' ',' 
