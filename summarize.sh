#!/bin/bash
#summarize.sh
#Mithun Rameshkumar
#April 7, 2025
#This script prints a markdown formatted summary of files ending in .sh, .c, or .h
#Run by doing : "./summarize.sh {insert file names}"

for file in "$@"; do

  first=true

  if [[ ! -r "$file" ]]; then
    echo 1>&2 "ERROR READING FILE" 

  elif [[ "$file" == *.sh || "$file" == *.c || "$file" == *.h ]]; then
    echo "## $(basename "$file")"

    if [[ "$file" == *.sh ]]; then
      echo '``` bash'
    else
      echo '``` c'
    fi

    while read line; do
      if [[ "$first" == true && "$line" = \#\!* ]]; then
       continue
       first=false
      fi 

      if [[ -z "$line" ]]; then
        break
      fi 

      echo "$line" 
    done < "$file" 
    echo '```'
  fi
done 

