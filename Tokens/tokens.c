/**
 *  Author     : abhijithvijayan
 *  Created on : 25 Nov 19, 21:27
 *  Title      : lexical analyzer  
 *  Aim        : Design a lexical analyzer for a given language
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 *  fp1 file to r/w the entered input program
 *  fp2 file to w identifiers
 *  fp3 file to w special symbols
 */
FILE *fp1,
    *fp2, *fp3;

int digitCount = 0;
int lineCount = 0;

void displayNumbers(int numbers[]);

/**
 *  Read user input and store file
 */
int readInputAndWriteToFile()
{
    char ch;
    fp1 = fopen("input.log", "w");

    printf("Enter the C program\nNote: Append EOF using CTRL+d\n");

    while ((ch = getchar()) != EOF)
    {
        fputc(ch, fp1);
    }

    fclose(fp1);
}

/** 
 *  Parse inputs
 */
int parseUserInputsFromFile(int numbers[])
{
    char ch;

    fp1 = fopen("input.log", "r");
    fp2 = fopen("identifiers.log", "w");
    fp3 = fopen("specialCharacters.log", "w");

    while ((ch = fgetc(fp1)) != EOF) // need () around assignment
    {
        if (isdigit(ch))
        {
            // get correct value | remove ASCII value
            int num = ch - '0';

            // read next character and check if it is a digit too
            ch = fgetc(fp1); // fgetc guarantees single evaluation

            // read until the character is not a digit
            while (isdigit(ch))
            {
                num = num * 10 + ch - '0';
                // read next
                ch = fgetc(fp1);
            }

            // push the number into array
            numbers[digitCount++] = num;

            // push into input stream
            ungetc(ch, fp1);
        }
        else if (isalpha(ch))
        {
            // push into identifiers file
            putc(ch, fp2);

            // read next character and check if it is a alphabet or _ or digit
            ch = fgetc(fp1);

            // identifier (alphabets | digits | underscore | null char)
            while (isalpha(ch) || isdigit(ch) || ch == '_' || ch == '$')
            {
                fputc(ch, fp2);
                // read next
                ch = fgetc(fp1);
            }

            // append space
            fputc(' ', fp2); // printing empty-char

            // push into input stream
            ungetc(ch, fp1);
        }
        else if (ch == '\n')
        {
            // increment line count
            ++lineCount;
        }
        else if (ch == ' ' || ch == '\t')
        {
            // do nothing with whitespaces
        }
        else
        {
            // write special symbol to file
            fputc(ch, fp3);
        }
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}

int checkIfIdentifierOrKeyword(char str[])
{
    if (strcmp("if", str) == 0 ||
        strcmp("do", str) == 0 ||
        strcmp("if", str) == 0 ||
        strcmp("for", str) == 0 ||
        strcmp("int", str) == 0 ||
        strcmp("char", str) == 0 ||
        strcmp("case", str) == 0 ||
        strcmp("else", str) == 0 ||
        strcmp("float", str) == 0 ||
        strcmp("while", str) == 0 ||
        strcmp("static", str) == 0 ||
        strcmp("double", str) == 0 ||
        strcmp("switch", str) == 0 ||
        strcmp("printf", str) == 0)
    {
        return 1;
    }

    return 0;
}

void parseIdentifiers()
{
    char ch;
    char str[10];

    fp2 = fopen("identifiers.log", "r");

    printf("\nThe identifiers and keywords are: \n\n");

    int k = 0;
    while ((ch = fgetc(fp2)) != EOF)
    {
        // extract each word and push to an array (append \0 when required)
        if (ch != ' ')
        {
            str[k++] = ch;
        }
        // make a word using the characters
        else
        {
            // append null character to specify end of string
            str[k] = '\0';

            // check if keyword or not
            if (checkIfIdentifierOrKeyword(str))
            {
                printf("`%s` is a keyword\n", str);
            }
            else
            {
                printf("`%s` is an identifier\n", str);
            }

            // reset k
            k = 0;
        }
    }

    fclose(fp2);
}

void parseSpecialSymbols()
{
    char ch;
    printf("\nSpecial characters are\n");

    fp3 = fopen("specialCharacters.log", "r");

    while ((ch = fgetc(fp3)) != EOF)
    {
        printf("%c ", ch);
    }

    printf("\n");

    fclose(fp3);
}

void displayNumbers(int numbers[])
{
    int i;

    if (digitCount)
    {
        printf("\nThe numbers in the program are: ");

        for (i = 0; i < digitCount; ++i)
        {
            printf("%d ", numbers[i]);
        }

        printf("\n");
    }
}

int main()
{
    int numbers[100];

    // Read User Program & Write to file
    readInputAndWriteToFile();

    parseUserInputsFromFile(numbers);

    parseIdentifiers();

    parseSpecialSymbols();

    // print numbers array
    displayNumbers(numbers);

    printf("\nTotal number of lines is %d\n", lineCount);

    return 0;
}