#!/bin/bash

# Accept a number as input
read -p "Enter a number: " num

# Check if the number is even or odd
if ((num % 2 == 0)); then
  echo "$num is even."
else
  echo "$num is odd."
fi
