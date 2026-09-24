#!/bin/bash
#testing.sh
#Mithun Rameshkumar 
#April 12
#Testing chill.c

#zero arguments
./chill

#one arguments
./chill 20
./chill 30
./chill 40

#two arguments
./chill 10 10
./chill 15 10
./chill 35 78

#temp out of range
./chill 55
./chill 90

#wind out of range
./chill 10 0
./chill 10 0.4
