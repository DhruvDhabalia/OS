#!/bin/bash

# Prompt the user to enter a character
read -p "Enter a character: " char

# Convert the character to lowercase (for case-insensitive check)
char=$(echo "$char" | tr '[:upper:]' '[:lower:]')

# Check if the input is a single character
if [ ${#char} -ne 1 ]; then
  echo "Invalid input. Please enter a single character."
  exit 1
fi

# Use a case control statement to check if the character is a vowel
case $char in
  "a" | "e" | "i" | "o" | "u")
    echo "$char is a vowel."
    ;;
  *)
    echo "$char is not a vowel."
    ;;
esac
