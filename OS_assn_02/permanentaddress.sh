#!/bin/bash

# Define the path to the input file
input_file="address.txt"

# Check if the input file exists
if [ ! -e "$input_file" ]; then
  echo "Error: The input file '$input_file' does not exist."
  exit 1
fi

# Display the contents of the input file (your permanent address)
cat "$input_file"
