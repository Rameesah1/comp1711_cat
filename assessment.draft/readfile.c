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
// Complete the main function
int main() 
{

char filename [] = "FitnessData_2023.csv";
FILE *file = fopen(filename, "r");
if (file == NULL) {
perror("");
return 1;
}


FITNESS_DATA Fitnessdata [61]; //can store up to 61 student records from the file
//make a loop that will read each line of the file and store each record into this Fitness_Data array
int read = 0;
int records = 0; //tracks number of records in the file
 do
   {
    read = fscanf(file, 
                  "%11[^,],%6[^,],%d",    //this reads a string up to 11 characters and stops displaying it after the comma 
                  Fitnessdata[records].date,   // no & as date and time are arrays     
                  Fitnessdata[records].time,
                  &Fitnessdata[records].steps);
    if (read == 3 ) records++; 
   
    if (read != 3 && !feof(file))
    {
      printf("File format incorrect.\n");
      return 1;
    }
                                                        
    } while (!feof(file)); 

  fclose(file);
  
  // print out the number of records read
  printf("\n%d records read.\n\n", records);
  
  // print out each of the records that was read 
  for (int i = 0; i < records; i++)
    printf("%s %s %d\n", 
           Fitnessdata[i].date,
           Fitnessdata[i].time,
           Fitnessdata[i].steps);
return 0;
}
