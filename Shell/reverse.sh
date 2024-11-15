read -p "Enter the string :" name
reverse=" "
for (( i=${#name}-1;i>=0;i-- ))
do
    reverse+=${name:$i:1}
done
echo "$reverse"
