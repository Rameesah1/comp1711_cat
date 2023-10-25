//A function to find the max number
#include <stdio.h>
//declare function prototype- so declare a function with parameters
int max_number (int a, int b)
{
    if (b>a) return b;
    else return a;
}

int main () {
    //assign a  variable int max to the function
    int max = max_number (33, -1);
    printf ("max: %d\n", max);
    return 0;
}