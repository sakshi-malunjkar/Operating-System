#!/bin/bash

# Reading marks for 5 subjects
echo "Enter marks for 5 subjects:"

echo "Enter marks for Subject 1:"
read subject1
echo "Enter marks for Subject 2:"
read subject2
echo "Enter marks for Subject 3:"
read subject3
echo "Enter marks for Subject 4:"
read subject4
echo "Enter marks for Subject 5:"
read subject5

# Calculate total
total=$(( subject1 + subject2 + subject3 + subject4 + subject5 ))

average=$(( total / 5 ))
echo "$average"

if (( $average >= 60)) ;
then
 echo "FIRST CLASS "

else
    echo "FAIL"
fi
