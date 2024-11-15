
echo "Enter the marks of first subject:"
read a
echo "Enter the marks of second subject:"
read b
echo "Enter the marks of third subject:"
read c 

sum=$((a + b + c))
p=$(( (sum * 100) / 300 ))


echo "Sum: $sum"
echo "Percentage: $p"


if (( p >= 90 )); then
    echo "Grade is A" > result.txt
elif (( p >= 75 && p < 90 )); then
    echo "Grade is B" >> result.txt
elif (( p >= 50 && p < 75 )); then
    echo "Grade is C" >> result.txt
else
    echo "Fail" >> result.txt
fi
