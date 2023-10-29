#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];  //string
	char time[6];   //string
	int steps;      //integer
} FITNESS_DATA;

// Define any additional variables here



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
int main() {
    char filename[] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");  // "r" mode for reading
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    FITNESS_DATA Fitnessdata[61]; // Array to store records
    int records = 0; // Number of successful records read

    // Reading file content
    while (fscanf(file, "%10[^,],%5[^,],%d\n", Fitnessdata[records].date, Fitnessdata[records].time, &Fitnessdata[records].steps) == 3) {
        records++;
        if (records >= 61) {
            printf("Reached maximum storage capacity.\n");
            break;
        }
    }

    fclose(file);  // Close the file after reading

    if (records == 0) {
        printf("No records could be read, or file is empty.\n");
        return 1;
    }

    // Printing the number of records
    printf("\n%d records read.\n\n", records);

    // Printing each record
    for (int i = 0; i < records; i++) {
        printf("%s %s %d\n", Fitnessdata[i].date, 
                             Fitnessdata[i].time, 
                             Fitnessdata[i].steps);
    }

    return 0;
}