#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

// Function to import data from a file
int importFile(char *filename, FITNESS_DATA Fitnessdata[], int *records) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not find or open the file.\n");
        return 0;
    }

    char line_buffer[100];
    char date[11], time[6];
    int steps;
    *records = 0;

    while (*records < 1000 && fgets(line_buffer, sizeof(line_buffer), file) != NULL) {
      //  tokeniseRecord(line_buffer, ',', date, time, &steps); {
            if (strrchr(line_buffer, ',') == NULL || steps == -1 ) {
                printf("Incorrect file type. Must be a CSV file.\n");
                return 0;
            }
            if (strlen(date) != 10 || strlen(time) != 5) {
                printf("Incorrect data order or format in file.\n");
                fclose(file);
                return 0;
            }
    
                
        tokeniseRecord(line_buffer, ',', date, time, &steps);

        strcpy(Fitnessdata[*records].date, date);
        strcpy(Fitnessdata[*records].time, time);
        Fitnessdata[*records].steps = steps;  
        
        (*records)++;
    }

    fclose(file);
    return 1;
}
//printf("Error: Could not find or open the file.\n");

// Function to sort the data using bubble sort
void bubble_Sort(FITNESS_DATA Fitnessdata[], int records) {
    for (int i = 0; i < records - 1; i++) {
        for (int j = 0; j < records - i - 1; j++) {
            if (Fitnessdata[j].steps < Fitnessdata[j + 1].steps) {
                FITNESS_DATA temp = Fitnessdata[j];
                Fitnessdata[j] = Fitnessdata[j + 1];
                Fitnessdata[j + 1] = temp;
            }
        }
    }
}
int tsvOutput(FITNESS_DATA Fitnessdata[], int records, const char *filename) {  //function to write to the tsv file
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open the file for writing.\n");

        return 1;
    }

    for (int i = 0; i < records; i++) {
        fprintf(file, "%s\t%s\t%d\n", Fitnessdata[i].date, Fitnessdata[i].time, Fitnessdata[i].steps);
    }

    fclose(file);
    return 0;
}

int main() {
    FITNESS_DATA Fitnessdata[1000];
    int records = 0;
    char inputFilename[100];
    char outputFilename[150];  

    printf("Enter Filename: ");
    scanf("%s", inputFilename); 

    if (!importFile(inputFilename, Fitnessdata, &records)) {
        return 1;
    }

    bubble_Sort(Fitnessdata, records);  // Call to bubbleSort function

    // Create output filename by appending ".tsv" to the input filename
    snprintf(outputFilename, sizeof(outputFilename), "%s.tsv", inputFilename);
    
    // Write data to the new TSV file
    tsvOutput(Fitnessdata, records, outputFilename);

    printf("Data sorted and written to %s\n", outputFilename);  //output on this terminal


    return 0;
}

 
