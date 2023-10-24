
#include <stdio.h>
 int sum (int a, int b) //specify the inputs and the data type, a int repectively
 {
      int answer;
      answer = a + b;
      return answer;
 }
  
    int main ()
    {
        int y = 2;
        int z = sum(5, y); //calling our new function

        int x= sum(10,y);

printf("The sum of 5 and %d is %d\n", y, z);

    }

