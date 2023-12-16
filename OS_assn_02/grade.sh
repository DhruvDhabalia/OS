#!/bin/bash

# Accept marks as input
read -p "Enter marks: " marks

# Determine the grade
if [ $marks -ge 90 ]; then
  echo "Grade: O"
elif [ $marks -ge 80 ]; then
  echo "Grade: A"
elif [ $marks -ge 70 ]; then
  echo "Grade: B"
elif [ $marks -ge 60 ]; then
  echo "Grade: C"
elif [ $marks -ge 50 ]; then
  echo "Grade: D"
else
  echo "Grade: Fail"
fi
