#include <stdio.h>
void printArray(int a[][3] ){ //in this example 3 is the fixed number of columns
for (int i = 0; i <= 1; ++i) {  //better to use size_t as this is better for arrays
  for (int j = 0; j <= 2; ++j) {  //counting the columns IN the rows hence inside the i for loop
printf("%d ", a[i][j]); //must use whitespace after format specifier so there is a space between the elements 
}
printf("\n"); // start new line of output
}
}
int main() {
int array1[2][3] = {{1, 2, 3}, {4, 5, 6}};  //best way to initialise
printf("Values in array1 by row are:\n");
printArray(array1);
int array2[2][3] = {1, 2, 3, 4, 5};
printf("Values in array2 by row are:\n");
printArray(array2);
int array3[2][3] = {{1, 2}, {4}};
printf("Values in array3 by row are:\n");
printArray(array3);
return 0;
}
