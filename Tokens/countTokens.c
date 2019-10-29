/**
 *  Author     : abhijithvijayan
 *  Created on : 29 Oct 19, 10:24
 *  Title      : valid identifier or not    
 *  Aim        : Check if entered identifier is valid or not
 */

#include <stdio.h>

/**
 *  f1 file to r/w the entered input program
 *  f2 file to w identifiers
 *  f3 file to w special symbols
 */
FILE *f1, *f2, *f3;

int readInputAndWriteToFile() {
    char c;
    f1 = fopen("input.log", "w");

    printf("Enter the C program\nNote: Append EOF using CTRL+d\n");

    while ((c = getchar()) != EOF)
    {
        putc(c, f1);
    }
    
    fclose(f1);
}

int parseUserInputsFromFile() {
    char c;
    f1 = fopen("input.log", "r");
    f2 = fopen("identifiers.log", "w");
    f3 = fopen("specialCharacters.log", "w");

    while((c = getc(f1) != EOF)) {
        if (isdigit(c)) {
            // do w operations
        } else if (isalpha(c)) {
            // do w operations
        } else if (c == '\n') {
            // increment line count
        } else {
            // write special symbol to file
        }
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
}

int main() {

    // Read User Program & Write to file
    readInputAndWriteToFile();

    parseUserInputsFromFile();

    return 0;
}