#!/bin/bash

# Read the number from the user
echo "Enter the number:"
read a

# Prime check
is_prime=true

# Loop to check if the number is divisible by any number from 2 to a/2
for (( i=2; i<=a/2; i++ ))
do
    if (( a % i == 0 )); then
        is_prime=false
        break
    fi
done

# Display result based on prime check
if $is_prime; then
    echo "$a is a prime number"
else
    echo "$a is not a prime number"
fi
