
#include <stdio.h>
int main () {
    int a = 20;

    printf("Even numbers from 20 to 0:\n");

    for (a=20; a >= 0; a-=2) //using for loop
    
        printf("a is equal to %d\n", a);

    //you can add another {} and in between add a printf("I've finished this loop and a is equal to x%d/n",a); to get the final value of a
      return 0;
}