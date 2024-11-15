echo "Enter the first number:"
read a
echo "Enter the second number:"
read b
echo "Enter the third number:"
read c

if [ $a -gt $b ] && [ $a -gt $c ]
then
  echo "a is greater among the three" >result.txt
elif [ $b -gt $a ] && [ $b -gt $c ]
then
  echo "b is greater among the three"  >result.txt
else
  echo "c is greater among the three"  >result.txt
fi 

cat result.txt