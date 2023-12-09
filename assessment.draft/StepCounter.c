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
    int value;  //will be used for strcmp function to check if the value of the filename characters is the same
    FITNESS_DATA Fitnessdata[60]; 
                                 
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
            continue; //This continues to the next iteration after the message has been displayed
         }

        while (getchar() != '\n'); // Clear the input buffer
  
        switch(choice) {
            case 'A': {
                char filename[20];
                printf("Input filename:\n");
                scanf(" %20s", filename); // Used a space before %20s to ignore any leading whitespace
                
                value = strcmp(filename, actualfilename);  // https://www.geeksforgeeks.org/strcmp-in-c/
                if (value == 0) {  //this checks if the value of the two filename strings are the same. I bases this on an idea from : 
                                   //https://www.scaler.com/topics/c/string-comparison-in-c/
    
                FILE *file = fopen(actualfilename, "r"); // Try to open the file for reading
                if (file == NULL) {
                    printf("Error opening file"); // Error message if file doesn't open
                } else {
                    printf("File successfully loaded\n");
                    fclose(file); // Closes the file if it's opened successfully
                
                }
                }   else { 
                    printf("Incorrect file name entered\n");
                    return 1;  //Exits the program if an incorrect file name is entered

                }
        
                break; 
            }

            case 'B' :  {
        
                char line_buffer[100];
                char date[11], time[6], steps[10];
               
                
                FILE *file = fopen(actualfilename, "r"); 
                if (file == NULL) {
                printf("Error opening file\n"); 
                break;
                }

                while (fgets(line_buffer, sizeof(line_buffer), file) != NULL && records < 60) {   //sizeof(line_buffer) 
                tokeniseRecord(line_buffer, "," , date, time, steps);

                strcpy(Fitnessdata[records].date, date);
                strcpy(Fitnessdata[records].time, time);
                int intsteps;
                intsteps = atoi(steps);  //converts the string - steps into an integer
                Fitnessdata[records].steps = intsteps;  

                records++;
                }
                fclose(file);

        
                printf("Total records: %d\n", records); 
    
                }
                break;

            case 'C': {

                 if (records > 0) {
                 int minSteps = Fitnessdata[0].steps;   
                 int minIndex = 0;
                 

                    //for (i = 0; i < records; i++) {
                   for (int i = 1; i < records; i++) {    
                    if(minSteps > Fitnessdata[i].steps) {   
                    minSteps = Fitnessdata[i].steps;  //Updates the value of minsteps
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
                 

                   for (int i = 1; i < records; i++) {    
                    if(maxSteps < Fitnessdata[i].steps) {   //I based this on an idea I got from: https://www.youtube.com/watch?v=9DJYGr2W5y8
                    maxSteps = Fitnessdata[i].steps;  //Updates the value 
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

                        sum = sum + Fitnessdata[i].steps;       //I based this of an idea from:
                        aveSteps = sum / records;               //https://www.youtube.com/watch?v=gCv170-cN_s    (Portfolio Courses)
                                                               
                    }
                    if (records > 0) {
                    aveSteps = (int)((sum / records) + 0.5);
                    }

                       // printf("Total sum of steps in the records: %f\n", sum);
                        printf("Mean step count: %d\n", aveSteps);
  

                      break;
                }

             case 'F': {

                  int startofDuration = -1; 
                  int endofDuration = -1;
                  int startofLong = -1;
                  int endofLong = -1;
                  int longestDuration = 0; 
                  //currentDuration variable is assigned later

                  for (int i = 0; i < records; i++) {

                  if (Fitnessdata[i].steps > 500) {
                  if (startofDuration == -1) {   
                  startofDuration = i;  //Updates it to current index 
                     }
                     endofDuration = i;

                  } else {

                   if (startofDuration != -1) {
                   int currentDuration = endofDuration - startofDuration;
                   if (currentDuration > longestDuration) {
                    longestDuration = currentDuration;
                    startofLong = startofDuration;
                    endofLong = i - 1; // - 1 because the index before that is when the condition is true
                }
                startofDuration = -1; //reset
            }
        }
    
    }

    if (startofDuration != -1) {
        int currentDuration = endofDuration - startofDuration;
        if (currentDuration > longestDuration) {
            longestDuration = currentDuration;
            startofLong = startofDuration;
            endofLong = records - 1; //This checks for the last record (array indexes go from 0-59)
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
    
            case 'Q': 
                printf("\nExiting\n");
                return 0; // Exits the program
            
            }
    
    return 0;
        }
    
            

}
    
}
    

    



    



    
    



    











