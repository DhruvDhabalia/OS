#!/bin/bash

# Prompt the user to enter the number of elements in the array
read -p "Enter the number of elements in the array: " num_elements

# Check if the input is not a positive integer
if ! [[ "$num_elements" =~ ^[1-9][0-9]*$ ]]; then
  echo "Invalid input. Please enter a positive integer."
  exit 1
fi

# Declare an array to store the numbers
declare -a numbers

# Prompt the user to input the numbers
echo "Please enter $num_elements numbers:"
for ((i = 0; i < num_elements; i++)); do
  read -p "Enter number $((i + 1)): " num
  numbers[$i]=$num
done

# Check if the number of elements is less than 2
if [ "$num_elements" -lt 2 ]; then
  echo "There are not enough elements to find the second largest number."
  exit 1
fi

# Initialize variables to store the largest and second largest numbers
largest=${numbers[0]}
second_largest=${numbers[0]}

# Loop through the array to find the largest and second largest numbers
for ((i = 0; i < num_elements; i++)); do
  if [ ${numbers[$i]} -gt $largest ]; then
    second_largest=$largest
    largest=${numbers[$i]}
  elif [ ${numbers[$i]} -gt $second_largest ] && [ ${numbers[$i]} -ne $largest ]; then
    second_largest=${numbers[$i]}
  fi
done

# Display the second largest number
echo "The second largest number is: $second_largest"
