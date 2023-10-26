#include <stdio.h>
//declare function prototype
int sum (int a, int b)
 {
    //body of the prototype function- first assign a value to int sum, int a and int b
    int sum; //assign a sum to 
    sum = a + b;
    return sum;
 }

 int main ()
 {
  //assign values to your main function variables
   int y = 3;
   int x = sum (2, y);
   printf ("The sum of 2 and %d is %d\n", y, x); 
 }
