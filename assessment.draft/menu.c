#include <stdio.h>
int main ()  {

    int choice, i;

while (1)
{   
    printf("A. Specify the filename to be imported – you need to check that the file opened correctly");
    printf("B. Display the total number of records in the file\n"); 
    printf("C. Find the date and time of the timeslot with the fewest steps\n"); 
    printf("D. Find the date and time of the timeslot with the most steps\n\n\n"); 
    printf("E. Find the data and time of the timeslot with the largest number of steps");
    printf("F. Find the longest continuous period where the step count is above 500 steps");
    printf("Q. Exit");
    printf("Enter choice: ");
    scanf("%d", &choice );
  
  switch(choice)  {
    
    case 1:
    
    char filename[] = "StepCounter.c";
    FILE *file = fopen(filename, "r"); // r to read the file - not w as there is no writing in
    if (file == NULL) {
        printf("Error in opening file");
        return 1;

    fclose(file); 

    case 2:
    printf("24/05/2023 - 13:00"); break;

    case 3:
    printf("21/05/2023 - 14:00"); break;

    case 4:
    printf("21/05/2023 - 14:00"); break;

    case 5:
    printf("21/05/2023 - 14:00"); break;

    case 6:
    printf("21/05/2023 - 14:00"); break;

    case 7:
    printf("21/05/2023 - 14:00"); break;


    

  }
  return 0;
        


    
}
   

}