#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }

// Complete the main function
int main() {
    char choice;

    while (1) {   
        printf("A. Specify the filename to be imported – you need to check that the file opened correctly\n");
        printf("B. Display the total number of records in the file\n"); 
        // ... (other menu options) ...
        printf("Q. Exit the menu\n");
        printf("Enter choice: ");
        scanf(" %c", &choice); // The space before %c tells scanf to ignore any whitespaces
        while (getchar() != '\n'); // Clear the input buffer
  
        switch(choice) {
            case 'A': { // Braces to create a new scope for the case
                char filename[100];
                printf("Enter file name:\n");
                // Use a space before %99s to ignore any leading whitespace
                scanf(" %99s", filename);
                FILE *file = fopen(filename, "r"); // Try to open the file for reading
                if (file == NULL) {
                    printf("Error opening file"); // Use perror to print the error message
                } else {
                    printf("File opened successfully\n");
                    fclose(file); // Close the file if it's opened successfully
                }
                break; // Break out of the switch case
            }
            // ... (other cases should be implemented accordingly) ...
            case 'Q': {
                printf("Exiting\n");
                return 0; // Exits the program
            }
        }
    }
    return 0;
}


    











