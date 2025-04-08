#!/bin/bash
#summarize.sh
#Mithun Rameshkumar
#April 7, 2025
#This script prints a markdown formatted summary of files ending in .sh, .c, or .h
#Run by doing : "./summarize.sh {insert file names}"

#loop through every file in list
for file in "$@"; do
  
  #flag representing first line of file
  first=true 

  #If file not readable, print error
  if [[ ! -r "$file" ]]; then
    echo 1>&2 "ERROR READING FILE" 
  
  #If file ends in .sh, .c, .h continue
  elif [[ "$file" == *.sh || "$file" == *.c || "$file" == *.h ]]; then

    #Print subheader giving file's basename
    echo "## $(basename "$file")"
    
    #Based on file type, print proper markdown triple tick notation
    if [[ "$file" == *.sh ]]; then
      echo '``` bash'
    else
      echo '``` c'
    fi
    
    #Read each line of the file
    while read line; do
      #If first line starts with #!, skip line
      if [[ "$first" == true && "$line" = \#\!* ]]; then
       continue
      fi 
      
      #Set flag to false since passed the first line of file
      first=false
      
      #If the line is empty break out of the loop
      if [[ -z "$line" ]]; then
        break
      fi 

      #Print contencts of line
      echo "$line" 
    done < "$file" 

    #Print closing triple ticks
    echo '```'
  fi
done 

