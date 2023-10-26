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
printf("Type %d numbers:\n ", num_lines);
for (int i = 0; i < num_lines; i++) {  //or you can do i<11 and initialise i to 1?
scanf("%d", &number);
fprintf(file, "%d\n", number);
}
fclose(file);
return 0;
}

