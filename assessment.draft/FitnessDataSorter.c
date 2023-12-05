#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} Fitnessdata;



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


int main() {

    char choice;
    char actualfilename[21]= "FitnessData_2023.csv";
    int value;  //will be used for strcmp function to check if the value is the same. 
    
                                   // Global declaration of the Fitnessdata array
    int records = 0;
   

    for (filename == "FitnessData_2023.csv");
    while(1) {
    char filename[20];
                printf("Enter file name:\n");
                scanf(" %20s", filename); // Use a space before %99s to ignore any leading whitespace
                
                value = strcmp(filename, actualfilename) ;  //first filename is the one user will enter/ second one is the actual one
                if (value == 0) {
    
                FILE *file = fopen(actualfilename, "r"); // Try to open the file for reading
                if (file == NULL) {
                    printf("Error opening file"); // Use  to print the error message
                } else {
                    printf("File opened successfully\n");
                    fclose(file); // Close the file if it's opened successfully
                
                }
                }   else { 
                    printf("Incorrect file name entered. Please try again\n");

     
               }

    
    }
               return 0;
    }

    /*}
    //to make the file in descending order of step count

       for (int i = 0; i < records; i++)
{
    for (int j = 0; j < (records - 1); j++)
    {
        if (Fitnessdata[j].steps > Fitnessdata[j+1].steps)
        {
            int temp = Fitnessdata[j].steps;
            Fitnessdata[j].steps = Fitnessdata[j+1].steps;
            Fitnessdata[j + 1].steps = temp;
        }
    }
}

for (int i = 0; i < records; i++)
{
    printf("a[%d] = %d\n", i, Fitnessdata[i].steps);
}

      



return 0;
}
*/
