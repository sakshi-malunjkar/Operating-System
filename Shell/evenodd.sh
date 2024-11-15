
echo "Enter the Number" 
read n

if [ $(expr $n % 2) -eq 0 ]
then
  echo "$n is Even number"
else
  echo "$n is Odd number"
fi

 
<<com
Enter the Number
4
4 is Even number
com

