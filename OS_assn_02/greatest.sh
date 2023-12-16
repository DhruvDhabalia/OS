#!/bin/bash

# Accept three numbers as input
read -p "Enter first number: " num1
read -p "Enter second number: " num2
read -p "Enter third number: " num3

# Find the greatest number
if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]; then
  echo "$num1 is the greatest number."
elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]; then
  echo "$num2 is the greatest number."
else
  echo "$num3 is the greatest number."
fi
