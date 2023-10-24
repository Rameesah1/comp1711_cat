
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
   int number;
    scanf("Type %d square numbers: ", num_lines);  //user input
    fprintf("Type the number of numbers you want to square from 1: ");

    for (int i = 0; i < num_lines; i++) {
        squares = i*i;  //give the integer the values
        fprintf(file, "%d\n", squares);
    }

    fclose(file);
    return 0;
}
