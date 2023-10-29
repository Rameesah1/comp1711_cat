#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
    char date[11];  // string
    char time[6];   // string
    int steps;      // integer
} FITNESS_DATA;

// ... [The rest of your code remains unchanged, including the tokeniseRecord function]

int main() {
    char filename[] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r"); // "r" means read mode
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
        records++;  // increment the number of records
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
