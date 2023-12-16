#!/bin/bash

# Accept the number of elements in the array
read -p "Enter the number of elements in the array: " n

# Initialize an empty array
arr=()

# Accept elements from the user
for ((i = 0; i < n; i++)); do
  read -p "Enter element $((i+1)): " element
  arr+=("$element")
done

# Accept an element to search for
read -p "Enter an element to search for: " target

# Search for the element
found=false
for element in "${arr[@]}"; do
  if [ "$element" -eq "$target" ]; then
    found=true
    break
  fi
done

# Display the result
if [ "$found" = true ]; then
  echo "$target found in the array."
else
  echo "$target not found in the array."
fi
