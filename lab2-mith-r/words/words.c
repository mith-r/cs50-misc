#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* words.c Mithun Rameshkumar April 11, 2025
 *
 *This program prints each word from the input (both stdin or given list of files)
 *on its own line. A word is a maximal sequence of one or more alphabetic characters.
 *Non-letter characters separate words. If a file cannot be opened an error is written 
 *to stderr.
 *
 */

/*
 * writeWords
 *
 * Reads characters from the given FILE pointer and prints each word (a maximal
 * sequence of alphabetic characters) on a separate line. Non-alphabetic characters
 * are treated as word boundaries. Handles the final word at EOF if necessary.
 *
 * Parameters:
 *   file - A FILE pointer to read input from (e.g., stdin or a file opened with fopen).
 */
void writeWords(FILE *file) {
    int c; //integer storing byte value
    char word[999]; //variable to build up word
    int i = 0; //index of letter
        
    //Until EOF, add to word. If EOF print
    while ((c = fgetc(file)) != EOF){
        if (isalpha(c)){
            word[i] = c;
            i ++;
        } else {
            //Ensure word present
            if (i > 0){
                word[i] = '\0'; //Setting end value 
                i = 0;
                printf("%s\n", word);
            }
        }
    }

    //If word being built, print it
    if (i > 0){
        printf("%s\n", word);
    }
}

/*
 * main
 *
 * Handles command-line arguments to determine whether to read from stdin or from one or 
 * more input files. If "-" is specified as a filename, input is read from stdin at that 
 * point. Invalid files generate an error message to stderr.
 *
 * Parameters:
 *   argc - Argument count
 *   argv - Argument vector (list of input filenames or "-" for stdin)
 *
 * Returns:
 *   0 on successful execution.
 */
int main(int argc, char *argv[])
{
    //Flag to determine exit status
    bool error = false;
    //Function to read from files if more arguments given
    if (argc > 1) {
        //looping through all files
        for (int i = 1; i < argc; i ++){

            FILE *file = fopen(argv[i], "r");

            //If file name has special character "-" print from stdin and return.
            if (strcmp(argv[i], "-") == 0) {

                writeWords(stdin);

            } 
            //If file cannot be opened print error and skip
            else if (file == NULL) {

                fprintf(stderr, "Cannot open file %s\n", argv[i]);
                error = true;

            } else {

                writeWords(file); //Call function with file as input
                fclose(file); //close file
            }
        } 
    } 
    //If no other files given
    else {
        writeWords(stdin);
    }

    if (error == true){
        return 1;
    }

    return 0; //end program successfully

}