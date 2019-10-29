/**
 *  Author     : abhijithvijayan
 *  Created on : 19 Oct 19, 13:00
 *  Title      : comment or not    
 *  Aim        : Check if entered string is a comment or not
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_LIMIT 1000

char *inputString() {
    // allocate memory dynamicaly (+1 for '\0') | stored in heap
    char *str = malloc((CHAR_LIMIT + 1) *sizeof(char));
    if (!str) {
        printf("Cannot allocate bytes for string");
        exit(0);
    }
    // scanf(); is unsafe
    fgets(str, CHAR_LIMIT + 1, stdin);
    return str;
}

/* 
    This is a
    multiline comment
*/

int checkIfComment(char *str) {
    if (str[0] == '/') {
        if (str[1] == '/') {
            return 1;
        }
        else if (str[1] == '*') {
            for (int i = 2; i < strlen(str); ++str) {
                if (str[i] == '*' && str[i+1] == '/') {
                    return 1;
                }
            }
        }
        return 0;
    }
    return 0;
}

int main(int argc, char **argv) {
    char *str;
    int isComment;

    printf("Enter a string\n");
    str = inputString();
    // printf("Entered string is \n%s", str);

    isComment = checkIfComment(str);
    if (isComment) {
        printf("The entered string is a comment\n");
    } else {
        printf("The entered string is not a comment");
    }

    // free the allocated space
    free(str);

    return 0;
}