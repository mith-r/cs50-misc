#!/bin/bash
#testing.sh
#Test file for histo.c
#Mithun Rameshkumar

# Test 1: All values within first bin range
echo "0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15" | ./histo

# Test 2: Values just beyond initial range to trigger one bin doubling
echo "0 16 31" | ./histo

# Test 3: Values that require multiple doublings
echo "32 64 128 199" | ./histo

# Test 3: Values that require multiple doublings + low value
echo "-57382579 64 128 199" | ./histo

# Test 4: Contains negative values and new lines
echo "-1 -20  10 20 " | ./histo

# Test 5: Empty input 
echo | ./histo