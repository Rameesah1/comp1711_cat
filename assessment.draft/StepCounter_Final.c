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
     int choice, i;

while (1)
{   
    printf("A. Specify the filename to be imported – you need to check that the file opened correctly");
    printf("B. Display the total number of records in the file\n"); 
    printf("C. Find the date and time of the timeslot with the fewest steps\n"); 
    printf("D. Find the date and time of the timeslot with the most steps\n\n\n"); 
    printf("E. Find the data and time of the timeslot with the largest number of steps");
    printf("F. Find the longest continuous period where the step count is above 500 steps");
    printf("Q. Exit");
    printf("Enter choice: ");
    scanf("%d", &choice );
  
  switch(choice)  {
    
    case 1:
    
    char filename[] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r"); // r to read the file - not w as there is no writing in
    if (file == NULL) {
        printf("Error in opening file");
        return 1;
    }
    

    case 2:
    printf("24/05/2023 - 13:00"); break;

    case 3:
    printf("21/05/2023 - 14:00"); break;

    case 4:
    printf("21/05/2023 - 14:00"); break;

    case 5:
    printf("21/05/2023 - 14:00"); break;

    case 6:
    printf("21/05/2023 - 14:00"); break;

    case 7:
    printf("21/05/2023 - 14:00"); break;


    

  }
  return 0;
        



} 
}









