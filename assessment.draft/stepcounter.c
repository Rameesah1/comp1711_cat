#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FitnessDataStruct.h"

typedef struct {
    char date[11];
    char time[6];
    int steps;
} TokenizedData;

void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps) {
    char *inputCopy = strdup(input);
    
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

    free(inputCopy);
}

int main() {
    char choice;
    FITNESS_DATA Fitnessdata[60];
    int records = 0;

    while (1) {
        printf("Menu options:\n");
        printf("A. Specify the filename to be imported – you need to check that the file opened correctly\n");
        printf("B. Display the total number of records in the file\n");
        printf("C. Find the date and time of the timeslot with the fewest steps\n");
        printf("D. Find the data and time of the timeslot with the largest number of steps\n");
        printf("E. Find the mean step count of all the records in the file\n");
        printf("F. Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q. Quit the menu\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);
        choice = toupper(choice);

        if (choice == 'A' || choice == 'B' || choice == 'C' || choice == 'D' || choice == 'E' || choice == 'F' || choice == 'Q') {
        } else {
            printf("Invalid choice. Please enter a valid option from A to F or Q, in uppercase.\n");
            continue;
        }

        while (getchar() != '\n'); // Clear the input buffer

        switch(choice) {
            case 'A': {
                char filename[21];
                printf("Input filename:\n");
                scanf(" %20s", filename);

                FILE *file = fopen(filename, "r");
                if (file == NULL) {
                    printf("Error: could not open file\n");
                    return 1;
                }

                char line_buffer[100];
                char date[11], time[6], steps[10];
                records = 0;

                while (fgets(line_buffer, sizeof(line_buffer), file) != NULL && records < 60) {
                    tokeniseRecord(line_buffer, "," , date, time, steps);

                    strcpy(Fitnessdata[records].date, date);
                    strcpy(Fitnessdata[records].time, time);
                    Fitnessdata[records].steps = atoi(steps);  
                    records++;
                }

                fclose(file);
                break;
            }

            case 'B' : 
                printf("Total records: %d\n", records);
                break;

            case 'C': {
                if (records > 0) {
                    int minSteps = Fitnessdata[0].steps;   
                    int minIndex = 0;

                    for (int i = 1; i < records; i++) {    
                        if(minSteps > Fitnessdata[i].steps) {   
                            minSteps = Fitnessdata[i].steps;
                            minIndex = i;
                        }
                    }

                    printf("Fewest steps: %s %s\n", Fitnessdata[minIndex].date, Fitnessdata[minIndex].time);
                }
                break;
            }
            
            case 'D' : {
                if (records > 0) {
                    int maxSteps = Fitnessdata[0].steps;   
                    int maxIndex = 0;

                    for (int i = 1; i < records; i++) {    
                        if(maxSteps < Fitnessdata[i].steps) {
                            maxSteps = Fitnessdata[i].steps;
                            maxIndex = i;
                        }
                    }

                    printf("Largest Steps: %s %s\n", Fitnessdata[maxIndex].date, Fitnessdata[maxIndex].time);
                }
                break;
            }
            
            case 'E': {
                double sum = 0;
                int aveSteps = 0;

                for (int i = 0; i < records; i++) {
                    sum = sum + Fitnessdata[i].steps;
                }

                if (records > 0) {
                    aveSteps = (int)((sum / records) + 0.5);
                }

                printf("Mean step count: %d\n", aveSteps);
                break;
            }

            case 'F': {
                int startofDuration = -1; 
                int endofDuration = -1;
                int startofLong = -1;
                int endofLong = -1;
                int longestDuration = 0; 

                for (int i = 0; i < records; i++) {
                    if (Fitnessdata[i].steps > 500) {
                        if (startofDuration == -1) {   
                            startofDuration = i;
                        }
                        endofDuration = i;
                    } else {
                        if (startofDuration != -1) {
                            int currentDuration = endofDuration - startofDuration;
                            if (currentDuration > longestDuration) {
                                longestDuration = currentDuration;
                                startofLong = startofDuration;
                                endofLong = i - 1; 
                            }
                            startofDuration = -1;
                        }
                    }
                }

                if (startofDuration != -1) {
                    int currentDuration = endofDuration - startofDuration;
                    if (currentDuration > longestDuration) {
                        longestDuration = currentDuration;
                        startofLong = startofDuration;
                        endofLong = records - 1;
                    }    
                }

                if (startofLong != -1 && endofLong != -1) {
                    printf("Longest period start: %s %s\nLongest period end: %s %s\n", 
                        Fitnessdata[startofLong].date, Fitnessdata[startofLong].time,
                        Fitnessdata[endofLong].date, Fitnessdata[endofLong].time);
                }
                break;
            }

            case 'Q': 
                return 0;
        }
    }

    return 0;
}
