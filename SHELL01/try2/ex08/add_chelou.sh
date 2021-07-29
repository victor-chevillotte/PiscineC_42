$FT_NBR1 + $FT_NBR2 | tr "\’\\\"\?\!" 01234 | tr "mrdoc" 01234 | tr "gtaio luSnemf" 0123456789ABC | bc | xargs echo "ibase=5; obase=13;"
