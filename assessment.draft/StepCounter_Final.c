#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


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

// Complete the main function
int main() {
    char choice;
    char actualfilename[21]= "FitnessData_2023.csv";
    int value;  //will be used for strcmp function to check if the value is the same. 
    FITNESS_DATA Fitnessdata[59];
                                   // Global declaration of the Fitnessdata array
    int records = 0;


    while (1) {   
        printf("Menu options:\n");
        printf("A. Specify the filename to be imported – you need to check that the file opened correctly\n");
        printf("B. Display the total number of records in the file\n"); 
        printf("C. Find the date and time of the timeslot with the fewest steps\n");
        printf("D. Find the data and time of the timeslot with the largest number of steps\n"); //2023-09-01,16:15,1100
        printf("E. Find the mean step count of all the records in the file\n");
        printf("F. Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q. Quit the menu\n");
        printf("Enter choice: ");
        scanf(" %c", &choice); // The space before %c tells scanf to ignore any whitespaces

        if (choice == 'A' || choice == 'B' || choice == 'C' || choice == 'D' || choice == 'E' || choice == 'F' || choice == 'Q') {

         } else {
            printf("Invalid choice. Please enter valid option from A to F or Q, in uppercase.\n");
            continue; //this continues to the next iteration after the message has displayed
         }

        while (getchar() != '\n'); // Clear the input buffer
  
        switch(choice) {
            case 'A': {
                char filename[20];
                printf("Enter file name:\n");
                scanf(" %20s", filename); // Use a space before %99s to ignore any leading whitespace
                
                value = strcmp(filename, actualfilename) ;  //first filename is the one user will enter/ second one is the actual one
                if (value == 0) {
    
                FILE *file = fopen(actualfilename, "r"); // Try to open the file for reading
                if (file == NULL) {
                    printf("Error opening file"); // Use perror to print the error message
                } else {
                    printf("File opened successfully\n");
                    printf("File successfully loaded\n");
                    fclose(file); // Close the file if it's opened successfully
                
                }
                }   else { 
                    printf("Incorrect file name entered\n");
                    return 1;

                }
        
                break; // Break out of the switch case
            }

            case 'B' :  {
                //FITNESS_DATA Fitnessdata[59]; // Can store up to 60 records from the file
                char line_buffer[100];
                char date[11], time[6], steps[10];
                //int records=0;
                
                FILE *file = fopen(actualfilename, "r"); 
                if (file == NULL) {
                printf("Error opening file\n"); // Use perror to print the error message
                break;
                }

                while (fgets(line_buffer, sizeof(line_buffer), file) != NULL && records < 60) {   //sizeof(line_buffer) helps prevent buffer overflow- better than writing 100
                tokeniseRecord(line_buffer, "," , date, time, steps);

                strcpy(Fitnessdata[records].date, date);
                strcpy(Fitnessdata[records].time, time);
                int intsteps;
                intsteps = atoi(steps);  //converts the string- steps into an integer
                Fitnessdata[records].steps = intsteps;  

                records++;
                }
                fclose(file);

        
                printf("Total number of records: %d\n", records); 
    
                }
                break;

            case 'C': {

                //So you want the min  value of field- steps value but you want the date and time to be the output
                //e.g max steps 
                 if (records > 0) {
                 int minSteps = Fitnessdata[0].steps;   
                 int minIndex = 0;
                 

                    //for (i = 0; i < records; i++) {
                   for (int i = 1; i < records; i++) {    
                    if(minSteps > Fitnessdata[i].steps) {   //then make array get new value so
                    minSteps = Fitnessdata[i].steps;  //(updates the value) 
                    minIndex = i;
                    }
                   }

                    printf("Fewest steps: %s %s\n", Fitnessdata[minIndex].date, Fitnessdata[minIndex].time);

                 }
                    
                    break;
                 
            case 'D' : {
                if (records > 0) {
                 int maxSteps = Fitnessdata[0].steps;   
                 int maxIndex = 0;
                 

                    //for (i = 0; i < records; i++) {
                   for (int i = 1; i < records; i++) {    
                    if(maxSteps < Fitnessdata[i].steps) {   //then make array get new value so
                    maxSteps = Fitnessdata[i].steps;  //(updates the value) 
                    maxIndex = i;
                    }
                   }

                    printf("Largest Steps: %s %s\n", Fitnessdata[maxIndex].date, Fitnessdata[maxIndex].time);

                 }
                    
                    break;
                
            case 'E': {

                    double sum = 0;
                    int aveSteps = 0;
                    int i = 0; 

                    for(int i = 0; i < records; i++) {

                        sum = sum + Fitnessdata[i].steps;  
                        aveSteps = sum / records;
                    }
                       // printf("Total sum of steps in the records: %f\n", sum);
                        printf("Mean step count: %d\n", aveSteps);
  

                      break;
                }

             case 'F': {

                  int startofDuration = -1;  //the variables set to -1 represent the invalidity of the indexes as they have not started any period count yet
                  int endofDuration = -1;
                  int startofLong = -1;
                  int endofLong = -1;
                  int longestDuration = 0; //the current duration index variable will be 
                  

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
                    endofLong = i - 1; //because the index before that the condition is still true
                }
                startofDuration = -1; //reset the loop
            }
        }
    
    }
    // Check if the last period is the longest and still ongoing
    if (startofDuration != -1) {
        int currentDuration = endofDuration - startofDuration;
        if (currentDuration > longestDuration) {
            longestDuration = currentDuration;
            startofLong = startofDuration;
            endofLong = records - 1; //this checks for the last record (array indexes go from 0-59
    }
}
    if (startofLong != -1 && endofLong != -1) { //checks if it the start and end of the indexes are both valid is true, then: 

        printf("Longest period start: %s %s\nLongest period end: %s %s\n", 
        Fitnessdata[startofLong].date, Fitnessdata[startofLong].time,
         Fitnessdata[endofLong].date, Fitnessdata[endofLong].time);
    }
    
    }
    break;
    
    }
        
        
            //other cases..
            case 'Q': 
                printf("\nExiting\n");
                return 0; // Exits the program
            
            }
    
    return 0;
        }
    
            

}
    
}
    

    



    



    
    



    











