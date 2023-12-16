#!/bin/bash

# Prompt the user to enter a pattern to search for
read -p "Enter the pattern to search for: " pattern

# Prompt the user to enter the name of the file to search within
read -p "Enter the name of the file to search within: " filename

# Check if the specified file exists
if [ ! -f "$filename" ]; then
  echo "File '$filename' does not exist."
  exit 1
fi

# Use `grep` to search for the pattern in the file
grep "$pattern" "$filename"

# Check the exit code of `grep` to determine if any matches were found
if [ $? -eq 0 ]; then
  echo "Pattern found in '$filename'."
else
  echo "Pattern not found in '$filename'."
fi
