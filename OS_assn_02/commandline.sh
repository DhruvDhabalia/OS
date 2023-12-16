#!/bin/bash

# Check if there are any command-line arguments
if [ $# -eq 0 ]; then
  echo "Usage: $0 <arg1> <arg2> ..."
  echo "Please provide one or more command-line arguments."
  exit 1
fi

# Get the total number of arguments
num_args=$#

# Display the total number of arguments
echo "Total number of command-line arguments: $num_args"

# Loop through and display each argument
for ((i = 1; i <= num_args; i++)); do
  arg="${!i}"  # Retrieve the argument using indirect expansion
  echo "Argument $i: $arg"
done

