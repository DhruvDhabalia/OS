#!/bin/bash

# Accept the number of arrays to sort
read -p "Enter the number of arrays to sort: " num_arrays

# Initialize an empty array to store the sorted arrays
sorted_arrays=()

# Loop through each array
for ((array_num = 1; array_num <= num_arrays; array_num++)); do
  # Accept the number of elements in the array
  read -p "Enter the number of elements in array $array_num: " n
  
  # Initialize an empty array
  arr=()

  # Accept elements from the user
  for ((i = 0; i < n; i++)); do
    read -p "Enter element $((i+1)) of array $array_num: " element
    arr+=("$element")
  done

  # Get the length of the array
  length=${#arr[@]}

  # Perform Bubble Sort
  for ((i = 0; i < length - 1; i++)); do
    for ((j = 0; j < length - i - 1; j++)); do
      if [ ${arr[j]} -gt ${arr[j + 1]} ]; then
        # Swap arr[j] and arr[j+1]
        temp=${arr[j]}
        arr[j]=${arr[j + 1]}
        arr[j + 1]=$temp
      fi
    done
  done

  # Append the sorted array to the list of sorted arrays
  sorted_arrays+=("${arr[*]}")
done

# Print the sorted arrays
echo "Sorted Arrays: ${sorted_arrays[@]}"

