
numbers=()


echo "Please enter 25 numbers:"
for i in {1..25}; do
    read -p "Enter number $i: " num
    numbers+=($num)
done

is_prime() {
    num=$1
    if [ $num -le 1 ]; then
        return 1
    fi
    for ((i = 2; i * i <= num; i++)); do
        if [ $((num % i)) -eq 0 ]; then
            return 1
        fi
    done
    return 0
}


result_file="result.txt"
echo "Results:" > $result_file


even_count=0
echo "First 5 even numbers:" >> $result_file  
for num in "${numbers[@]}"; do
    if [ $((num % 2)) -eq 0 ]; then
        echo $num >> $result_file
        ((even_count++))
    fi
    if [ $even_count -eq 5 ]; then
        break
    fi
done


odd_count=0
echo "First 5 odd numbers:" >> $result_file  
for num in "${numbers[@]}"; do
    if [ $((num % 2)) -ne 0 ]; then
        echo $num >> $result_file
        ((odd_count++))
    fi
    if [ $odd_count -eq 5 ]; then
        break
    fi
done


echo "First prime number:" >> $result_file  
for num in "${numbers[@]}"; do
    if is_prime $num; then
        echo $num >> $result_file
        break
    fi
done

echo "Results have been written to $result_file"
cat $result_file
