/**
 *  Author     : abhijithvijayan
 *  Created on : 29 Oct 19, 10:24
 *  Title      : valid identifier or not    
 *  Aim        : Check if entered identifier is valid or not
 */

#include <stdio.h>
#include <ctype.h>

int checkIfIdentifierOrNot(char str[]) {
    // check if first character is alphabet/underscore
    if (str[0] == '_' || isalpha(str[0])) {
        int i = 1;
        int flag = 1;

        while (str[i] != '\0')
        {
            // check if not underscore/alphabet/number
            if (str[i] != '_' && !isalnum(str[i])) {
                flag = 0;
                break;
            }

            ++i;
        }
    
        if (flag) {
            return 1;
        }
    }

    return 0;
}


int main(int argc, char **argv) {
    char str[20];

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    int isValid = checkIfIdentifierOrNot(str);
    
    if (isValid) {
        printf("The entered string '%s' is a valid identifier\n", str);
    } else {
        printf("The entered string '%s' is not a valid identifer\n", str);
    }

    return 0;
}