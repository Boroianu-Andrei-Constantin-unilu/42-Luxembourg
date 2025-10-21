#!/bin/sh
nbr1=$(echo "$FT_NBR1" | tr "\'\\\"?!\\" "01234")
nbr2=$(echo "$FT_NBR2" | tr "mrdoc" "01234")
sum=$(echo "ibase=5; $nbr1 + $nbr2" | bc)
echo "obase=13; $sum" | bc | tr "0123456789ABC" "gtaio luSnemf"
