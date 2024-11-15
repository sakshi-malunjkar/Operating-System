
while true ;do
echo "Enter the number 1"
read a 
echo "Enter the number 2 "
read b

echo "Select below option "
echo "1.Addition"
echo "2.Subtraction"
echo "3.Multiplication"
echo "4.Division"
echo "5.Exist"

echo "Enter the choice"
read choice

case $choice in

1) result=$(( a + b ))
   echo " Result is $result"
   ;;

2) result=$(( a - b ))
  echo "Result is $result"
  ;;

3) result=$(( a * b ))
  echo "Result is $result"
  ;;

4) result=$(( a / b ))
   echo "Result is $result"
   ;;

5) echo "Existing the menu!"
   break
   ;;
*)
  echo "Invalid Choice "
  ;;
esac

echo "Do You want to perform operation(yes/no)"
read l;
if [ "$l" != "yes" ];
  then 
   echo "existing the program "
   break
fi
done
echo "Output to " > txt.txt
