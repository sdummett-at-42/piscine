cat /etc/passwd | sed '/^#/d' | awk 'NR % 2' | cut -f1 -d: | rev | sort | sed -n " $FT_LINE1 , $FT_LINE2 p " | sed '$!s/$/,/' | tr '\n' ' ' | sed '$ s/.$/./'
