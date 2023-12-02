#include <stdio.h>
#include <stdlib.h>
int main(){
    int array_size;
    printf("\n Input the size of the array = ");
    scanf("%d", &array_size);
    printf("\n\n");int* vector = (int *) malloc (sizeof(int)*array_size);

    return 0;
}