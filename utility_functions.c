#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utility_functions.h"

int inputValidationNum () {
    char input[100];
    int number=0;
    char *endptr;

    while (1) 
    {
        fgets(input, sizeof(input), stdin);  // Read the entire line of input
        
        // Check if the input is valid number
        number = strtol(input, &endptr, 10);

        // Check if the input is valid number and no extra characters
        if (*endptr == '\n' || *endptr == '\0') 
        {
            //Valid Input
            return number;
        } 
        else 
        {
            // Invalid input (contains non-digit characters)
            printf("\nInvalid input! Please enter a number only\n> ");
        }
    }
}

float inputValidationFloat()
{
    char input[100];
    float number;
    char *endptr;

    while (1) 
    {
        fgets(input, sizeof(input), stdin); 

        // Convert input to a float
        number = strtof(input, &endptr);

        // Check if the input is valid number and no extra characters
        if (*endptr == '\n' || *endptr == '\0') {
            // Valid float entered
            return number;
        } 
        else 
        {
            // Invalid input
            printf("Invalid input. Please enter a valid floating point number\n> ");
        }
    }
}

void capitalize_word(char *name) {
    int i = 0;
    int new_word = 1;  // Flag to check if we're at the start of a word

    while (name[i] != '\0') {
        if (isalpha(name[i])) {
            if (new_word) {
                name[i] = toupper(name[i]);  // Capitalize the first letter of each word
                new_word = 0;
            } else {
                name[i] = tolower(name[i]);  // Convert the rest to lowercase
            }
        } else {
            new_word = 1;  // If we encounter a non-alphabetic character, the next letter will be the start of a new word
        }
        i++;
    }
}