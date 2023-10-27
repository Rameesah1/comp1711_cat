
#include <stdio.h>
int main() {

    int x = 0;
    int y = 0;

    printf("Insert x: ");   
    scanf("%d", &x);        

    printf("Insert y: ");
    scanf("%d", &y);        

    int sum = x + y;
    printf("Sum: %d\n", sum); 

    return 0;
}