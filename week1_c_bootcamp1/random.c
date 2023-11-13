/*#include <stdio.h>
int main () {

    char string[6] ="hello";
    printf("%c\n", string[2]);

    return 0;
}

#include <stdio.h>
int main () {   //Print an int array- 
   
   int age[]= {9,0,8,3,6,5};
   printf("%d\n", age[5]);

   return 0;
}
*/
/*
#include <stdio.h>
int main () {   //user input

int ages[7];

printf("Enter 6 values\n:  ");
scanf("%d", &ages[0]);
scanf("%d", &ages[1]);
scanf("%d", &ages[2]);
scanf("%d", &ages[3]);
scanf("%d", &ages[4]);
scanf("%d", &ages[5]);
scanf("%d", &ages[6]);


return 0;
}
*/
#include <stdio.h>
int main() {   //print out each character of a string:
 char stringOne[]="hello";
 int length=0;

 //while loop to make a length array- to count before the null terminator:
 while (stringOne[length] != '\0') {

    length++;
 }
    for(int i = 0; i < length; i++) 
    {
        printf("%c", stringOne[i]);
    }
   return 0;
}
