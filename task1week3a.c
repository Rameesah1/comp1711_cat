

#include <stdio.h>
#include <stdlib.h>

int main() {
char* filename = "squares.dat";
FILE *file = fopen(filename, "w"); //use w not r to create a file
if (file == NULL) {
perror("");
return 1;
}

   int squares;   //assign the variables
   int num_lines;

    scanf("%d\n", &num_lines);  //user input
    fprintf(file,"Enter the number of lines you want to square starting from 1:\n ");
    

    for (int i = 1; i <= num_lines; i++) {
        squares = i*i;  //give the integer the values
        fprintf(file, "%d\n", squares);
    }
 fclose(file);
 return 0;
}




