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
    FILE *file = fopen(filename, "r"); // "r" means read mode
    if (file == NULL) {
        printf("Error in opening file");
        return 1;
    }

    FITNESS_DATA Fitnessdata[61]; // Can store up to 61 records from the file
    int records = 0; // Tracks the number of records in the file

    // Read each line of the file and store each record into the Fitness_Data array
    for (records = 0;  records < 61 && fscanf(file, "%11[^,],%6[^,],%d\n", 
                                 Fitnessdata[records].date, 
                                 Fitnessdata[records].time, 
                                 &Fitnessdata[records].steps) == 3; records++) {
      
    }

    fclose(file); // Always close the file handle once you're done with it.

    // Check if there are at least three records to print
    if (records < 3) {
        printf("Not enough records in the file.\n");
        return 1;  // exit with an error code
    }

    // Print the number of records in the required format
    printf("Number of records in file: %d\n", records);

    // Print the first three records in the desired format
    for (int i = 0; i < 3; i++) {  // Only the first three records
        printf("%s/%s/%d\n", 
               Fitnessdata[i].date, 
               Fitnessdata[i].time, 
               Fitnessdata[i].steps);
    }

    // You can continue with other processing here

    return 0;  // Successful execution
}
