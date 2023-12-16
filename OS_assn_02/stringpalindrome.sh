#!/bin/bash

# Accept a string as input
read -p "Enter a string: " str

# Reverse the string
reverse=$(echo "$str" | rev)

# Check if the string is a palindrome
if [ "$str" = "$reverse" ]; then
  echo "$str is a palindrome."
else
  echo "$str is not a palindrome."
fi
