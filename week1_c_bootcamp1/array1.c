#include <stdio.h>
int main() {
  int multipleVariables[]= {55,65,64,76}; //this assigns a variable with multiple values (array)
  multipleVariables[0]=34;  //NOT NECCESSARY- this just changes the value of the first element

  printf("%d", multipleVariables[0]); //prints the new value - 34 instead of 55

return 0;
}