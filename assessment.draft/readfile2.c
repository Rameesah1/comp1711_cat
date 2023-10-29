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

// Main function
int main() {
    char filename[] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r"); // "r" is the mode for reading
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    FITNESS_DATA Fitnessdata[61]; // Can store up to 61 records from the file
    int records = 0; // Tracks the number of records in the file

    // Read each line of the file and store each record into the Fitness_Data array
    while(records < 61 && fscanf(file, "%10[^,],%5[^,],%d\n", 
                                 Fitnessdata[records].date, 
                                 Fitnessdata[records].time, 
                                 &Fitnessdata[records].steps) == 3) {
        records++; 
    }

    fclose(file); // Always close the file handle once you're done

    if(records == 0) {
        printf("No records found or file format incorrect.\n");
        return 1;
    }

    // Print out the number of records read
    printf("\n%d records read.\n\n", records);

    // Print out each of the records that was read
    for (int i = 0; i < records; i++) {
        printf("%s %s %d\n", Fitnessdata[i].date, Fitnessdata[i].time, Fitnessdata[i].steps);
    }

    return 0;
}