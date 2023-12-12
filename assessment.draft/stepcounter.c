#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FitnessDataStruct.h"
#include <math.h>
           
               
typedef struct {
    char date[11];
    char time[6];
    int steps;
}
    
TokenizedData;

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

int import_file(char *filename, FITNESS_DATA Fitnessdata[], int *records) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not find or open the file.\n");
        return 0;
    }

    char line_buffer[100];
    char date[11], time[6], steps[10];
    *records = 0;

    while (*records < 1000 && fgets(line_buffer, sizeof(line_buffer), file) != NULL) {
        tokeniseRecord(line_buffer, "," , date, time, steps);

        strcpy(Fitnessdata[*records].date, date);
        strcpy(Fitnessdata[*records].time, time);
        Fitnessdata[*records].steps = atoi(steps);  
        
        (*records)++;
    }

    fclose(file);
    return 1;
}


int main() {
    char filename[21];
    char choice;
    FITNESS_DATA Fitnessdata[1000];
    int records = 0;
    int startofDuration;
    int currentDuration;
    int startofLong;
    int longestDuration;

    while (1) {
        printf("Menu options:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);
        choice = toupper(choice);

        if (choice == 'A' || choice == 'B' || choice == 'C' || choice == 'D' || choice == 'E' || choice == 'F' || choice == 'Q') {
        } else {
            printf("Invalid choice.Try again.\n");
            continue;
        }
        while (getchar() != '\n'); // Clear the input buffer

        switch(choice) {

    
            case 'A': 
                printf("Input filename:\n ");
                scanf("%20s", filename);  // Limit input to 20 characters

                if (!import_file(filename, Fitnessdata, &records)) {
                    return 1;
                }
                break;
                

                /*char line_buffer[100];
                char date[11], time[6], steps[10];
                records = 0;

                while (fgets(line_buffer, sizeof(line_buffer), file) != NULL && records < 60) {
                    tokeniseRecord(line_buffer, "," , date, time, steps);

                    strcpy(Fitnessdata[records].date, date);
                    strcpy(Fitnessdata[records].time, time);
                    Fitnessdata[records].steps = atoi(steps);  

                    (*records++); */
                //}

            //     fclose(file);
            //     break;
            // }

        case 'B' : 
            printf("Total records: %d\n", records);
	    break;

        case 'C': 
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
        
        case 'D' : 
            if (records > 0) {
                int maxSteps = Fitnessdata[0].steps;   
                int maxIndex = 0;

                for (int i = 1; i < records; i++) {    
                    if(maxSteps < Fitnessdata[i].steps) {   
                        maxSteps = Fitnessdata[i].steps;
                        maxIndex = i;
                    }
                }

                printf("Largest steps: %s %s\n", Fitnessdata[maxIndex].date, Fitnessdata[maxIndex].time);
            }
            break;
        case 'E': {
           
            int sum = 0;
            int aveSteps = 0;  // Declare aveSteps here

            for (int i = 0; i < records; i++) {
                sum += Fitnessdata[i].steps;
            }

            if (records > 0) {
                aveSteps = round((double)sum / records); // Properly rounded average
            }

            printf("Mean step count: %d\n", aveSteps);
            break;
            }
        

        case 'F':
            startofDuration = -1;
            currentDuration = 0;
            startofLong = -1;
            longestDuration = 0;
            for (int i = 0; i < records; i++) {
                if (Fitnessdata[i].steps > 500) {
                    if (startofDuration == -1) {
                        startofDuration = i;
                    }
                    currentDuration++;
                } else {
                        if (currentDuration > longestDuration) {
                            longestDuration = currentDuration;
                            startofLong = startofDuration;
                        }
                        startofDuration = -1;
                        currentDuration = 0;
                    }
                }
            

            // Check after the loop in case the longest period is at the end of the array
            if (currentDuration > longestDuration) {
                    longestDuration = currentDuration;
                    startofLong = startofDuration;
                }

            if (startofLong != -1) {
                printf("Longest period start: %s %s\n", 
                    Fitnessdata[startofLong].date, Fitnessdata[startofLong].time);
                printf("Longest period end: %s %s\n",  Fitnessdata[startofLong + longestDuration - 1].date, Fitnessdata[startofLong + longestDuration - 1].time);
            } else{
                printf("No period with step count above 500 found.\n");
            }

            break;
        case 'Q': 
            return 0;
        }
    }

    return 0;
}

