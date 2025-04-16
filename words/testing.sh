#!/bin/bash

#Test 1: Read from stdin
echo "This is reading from stdin" | ./words

#Test 2: Read from one file
./words test1.txt

#Test 3: Read from two files
./ words test1.txt test2.txt

#Test 4: Mix of file and stdin using "-"
echo "stdin should be called in the middle" | ./words test1.txt - test2.txt

#Test 5: File that does not exist
./words test3.txt

#Test 6: Input with no words
echo "1234 !@#$" | ./words

#test 7: Empty file
./words empty.txt