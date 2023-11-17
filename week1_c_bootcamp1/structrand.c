#include <stdio.h>

   typedef struct
{
char date[20];
float bloodIron;

} reading;

int main () {
    //creating a variable in the struct 'reading'
    reading today;  
    reading reading1;
    reading reading2;
    reading reading3;
    reading reading4;
    reading reading5;
    reading reading6;
    reading reading7;
    //array of structs 
    reading thisWeek[7]= {reading1, reading2, reading3, reading4, reading5, reading6, reading7};

    for (int i=0; i<7; i++)
    {
        thisWeek[i].date[0] = '\0';
        thisWeek[i].bloodIron=0;
    }

    return 0;

}