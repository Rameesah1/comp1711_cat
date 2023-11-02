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
    
    
    //struct FITNESS_DATA Fitnessdata = {""2023-09-01" , "07:30", "300" }
     
     int num_of_records = 60 , storage;
     FITNESS_DATA Fitnessdata = {"2023-09-01" , "07:30", 300};
     for ( storage = 0; storage<60; storage++); {
     
    printf("Date of data: %s\n", Fitnessdata[storage].date);
    printf("Time of data: %s\n", Fitnessdata[storage].time);
    printf("Steps of data: %d\n", Fitnessdata[storage].steps);
    }

   return 0;
}

   
// strcpy(Fitnessdata.date,"2023-09-01");
    //strcpy(Fitnessdata.time, "07:30");
    //Fitnessdata.steps=300;

//return 0;

