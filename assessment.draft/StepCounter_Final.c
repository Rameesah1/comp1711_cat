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

while (1)
{   
    printf("A. Specify the filename to be imported – you need to check that the file opened correctly\n");
    printf("B. Display the total number of records in the file\n"); 
    printf("C. Find the date and time of the timeslot with the fewest steps\n"); 
    printf("D. Find the date and time of the timeslot with the most steps\n"); 
    printf("E. Find the data and time of the timeslot with the largest number of steps\n");
    printf("F. Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q. Exit the menu\n");
    printf("Enter choice:\n ");
    scanf("%c", &choice);
    while (getchar() != '\n') //idea from stack overflow- clears the input buffer. The while loop has a function inside it (getchar) and thsi reads each character of teh standard input. The while loop only gets executed if the character is not equal to != '\n' (so the newline character when the user adds enter).
  
  switch(choice)  {
    
    case 'A':  {
    
    char filename[100];
    printf("Enter file name:  \n");
    scanf("%99s", filename);  //not &filename as its not an int. use array name - filename- only

    FILE *file = fopen(filename, "r"); // r to read the file - not w as there is no writing in
    if (file == NULL) {
        printf("Error in opening file");
        return 1;
    } else {
        printf("File opened successfully\n");
        fclose(file); // Close the file
        } break;
    }

    case 'B':
    printf("24/05/2023 - 13:00"); break;

    case 'C':
    printf("21/05/2023 - 14:00"); break;

    case 'D':
    printf("21/05/2023 - 14:00"); break;

    case 'E':
    printf("21/05/2023 - 14:00"); break;

    case 'F':
    printf("21/05/2023 - 14:00"); break;

    case 'Q' :
    printf("Exiting");
    return 0;
    break; 


    

  }
  
        



}
return 0; 
}









