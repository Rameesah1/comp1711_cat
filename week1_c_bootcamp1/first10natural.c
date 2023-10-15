#include <stdio.h>
int main () {
    int a = 1;
    printf("The square of the first ten natural numbers:\n");

    while (a <= 10)
    { int square = a * a;
        printf("%d\n",square); //prints the value of the variable square 
        a +=1;
    }
    return 0;
}