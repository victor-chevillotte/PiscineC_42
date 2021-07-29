cat /etc/passwd | sed '/^#/d' | sed -n 'n;p' | sed "s/:*:.*//g" | rev | sort -r | awk -v s="$FT_LINE1" -v e="$FT_LINE2" 'NR>=s&&NR<=e' | tr '\n' "," | sed 's/,/, /g' | sed 's/, $/./g' | tr -d '\n'
