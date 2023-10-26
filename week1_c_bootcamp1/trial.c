#include <stdio.h>
int main ()
{
    char filename [] = "trial.txt";
FILE *file = fopen (filename, "w");
if (file == NULL){
    perror ("");
    return 1;
}

int number, num_lines = 10;
printf("Type %d numbers:\n", num_lines); // prints the value of int num_lines
for (int i = 0; i < num_lines; i+=2) {  //or you can do i<11 and initialise i to 1... you can baso use numbers instead
scanf("%d", &number);
fprintf(file, "%d\n", number);
}
fclose(file);
return 0;
}

