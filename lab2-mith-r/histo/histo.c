#include <stdio.h>
#include <math.h>

/*
 * histo.c  Mithun Rameshkumar April 15, 2025
 *
 * This program reads a series of non-negative integers from stdin and prints a histogram
 * with 16 bins, scaling the bin size dynamically to ensure range is accomodated
 */

const int NUM_BINS = 16; //Constant for number of bins (fixed by assignment spec)


/* 
 * Function main
 * First reads numbers one at a time. If greater than max, refactors numbers and increases size.
 * Once done, prints out histogram.
 * 
 * returns: exit status (always 0)
*/

int main(void) 
{
    //Initalizes bins as an array of integers and sets to 0
    int binsValue[NUM_BINS]; 
    for (int i = 0; i < NUM_BINS; i ++){
        binsValue[i] = 0;
    }

    int timesDoubled = 0; //Number of times bin sizes doubled
    int binsRange = pow(2, timesDoubled); //Range of bins calculated as 2 to power of timesDoubled
    int binsMax = NUM_BINS * binsRange; //Max bin size calculated as Number of Bins (16) and bins Range
    int value;

    while(scanf("%d", &value) != EOF) { 
    //If in range continue, else skip
        if (value >= 0){
            while (value >= binsMax){
                timesDoubled ++; 

                // Combine bins
                for (int i = 0; i < NUM_BINS / 2; i ++){
                    binsValue[i] = binsValue[2 * i] + binsValue[2 * i + 1];
                }
                
                // 0 out remaining
                for (int i = NUM_BINS / 2; i < NUM_BINS; i ++) {
                    binsValue[i] = 0;
                }

                //update variables
                binsRange = pow(2, timesDoubled);
                binsMax = NUM_BINS * binsRange;

                printf("%d bins of size %d for range[0, %d)\n", NUM_BINS, binsRange, binsMax);
            }
            
            //Calculate index to insert in
            int binsIndex = value / binsRange;
            binsValue[binsIndex] ++;
        }
    }

    //Calculate digits of largest number to make pretty
    int binsDigits = (int)(log10(NUM_BINS * binsRange) + 1); 

    //Loop through and print every box
    for (int i = 0; i < NUM_BINS; i++) {
        int firstNumber = i * binsRange; 
        int lastNumber =  firstNumber + (binsRange - 1);

        printf("[%*d:%*d]", binsDigits, firstNumber, binsDigits, lastNumber);
        for (int j = 0; j < binsValue[i]; j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}