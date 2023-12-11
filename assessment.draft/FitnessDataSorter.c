#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} Fitness_Data;





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

    int import_file(char *filename, FITNESS_DATA, int *records) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not find or open the file.\n");
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



        printf("Input filename:\n ");
        scanf("%s", filename); 
        if (!import_file(filename, Fitnessdata, &records)) {
        return 1;
        }

        return 0;
}
