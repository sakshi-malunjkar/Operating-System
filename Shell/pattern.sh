
echo "Enter the numbers"
for i in {1..25}
do
 read a
done

for i in {1..4}
do
line=" "

oddn= 1;
for j in $(seq 1 $i)
do
line+="$oddn"
odd=$((oddn + 2))
done

echo "$line"
done 
<<com
#!/bin/bash

# Read the first 25 marks (though we don't use them in the pattern)
echo "Enter the first 25 marks (one at a time):"
for i in {1..25}
do
  read mark
done

# File to store the result
output_file="pattern_output.txt"

# Initialize the starting number (first odd number is 1)
odd_number=1

# Loop to print the pattern and write it to the file
for i in {1..4}  # Loop 4 times to print 4 rows
do
  # Initialize the current line (empty string)
  line=""

  # Loop to print the first 'i' odd numbers for the current row
  for j in $(seq 1 $i)
  do
    line+="$odd_number "  # Append the odd number to the line
    odd_number=$((odd_number + 2))  # Move to the next odd number
  done

  # Write the line to the output file
  echo "$line" >> $output_file
done

# Notify the user that the result is written to the file
echo "Pattern has been written to $output_file."
com