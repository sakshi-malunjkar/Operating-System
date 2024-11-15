read -p "Enter the month:" month
read -p "Enter the year:" year

if [ $month -gt 0 ] && [ $month -lt 13 ]
then 
    cal "$month" "$year"
else
   echo "Invalid month and year"
fi 