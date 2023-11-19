#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
    char date[11];  // string
    char time[6];   // string
    int steps;      // integer
} FITNESS_DATA;

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Outputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {
        strcpy(date, token);
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

int main() {

    char filename[] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r"); // r to read the file - not w as there is no writing in
    if (file == NULL) {
        printf("Error in opening file");
        return 1;
    }
    FITNESS_DATA Fitnessdata[60]; // Can store up to 60 records from the file
    char line_buffer[100];
    char date[11], time[6], steps[10];
    int records=0;

    while (fgets(line_buffer, sizeof(line_buffer), file) != NULL && records < 60) {
    tokeniseRecord(line_buffer, "," date, time, steps);

    strcpy(Fitnessdata[records].date, date);
    strcpy(Fitnessdata[records].time, time);
    int intsteps;
    intsteps = atoi(steps);  //converts the string- steps into an integer
    Fitnessdata[records].steps = intsteps;  

    records++;
    }

    fclose(file);

    if (records < 3) {                                     //checks if there are three records to print at least
        printf("Not enough records in the file.\n");
        return 1;  // exits with an error code
    }
    else {
    // Print the number of records in the required format
    printf("Number of records in file: %d\n", records);
      }

    for (int storage = 0; storage < 3; storage++) {    
    
    if (storage < records) {
        printf("%s/%s/%d\n",                             
                            Fitnessdata[storage].date,
                            Fitnessdata[storage].time,
                            Fitnessdata[storage].steps);
     }
    }
    return 0;

    }


    





