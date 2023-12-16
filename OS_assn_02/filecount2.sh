#!/bin/bash

# Prompt the user to enter the name of the file to create
read -p "Enter the name of the file to create: " filename

# Check if the file already exists and ask if it should be overwritten
if [ -e "$filename" ]; then
  read -p "File '$filename' already exists. Do you want to overwrite it? (y/n): " overwrite
  if [ "$overwrite" != "y" ]; then
    echo "File not created."
    exit 1
  fi
fi

# Prompt the user to input the contents of the file
echo "Enter the contents of the file (Press Ctrl+D to save and exit):"
cat > "$filename"

# Count the number of lines, words, and characters in the file
lines=$(wc -l < "$filename")
words=$(wc -w < "$filename")
characters=$(wc -m < "$filename")

# Display the results in a proper format
echo "File '$filename' created successfully."
echo "Number of lines: $lines"
echo "Number of words: $words"
echo "Number of characters: $characters"
