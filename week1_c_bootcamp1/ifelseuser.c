
#include <stdio.h>
int main () {
    int mark;
    
    printf("Enter mark here: \n");
    scanf("%d", &mark);

if( mark == 0) {
    printf("The mark %d is zero\n", mark);
    }
else if( mark <= 40) {
    printf("The mark %d is a fail", mark);
}
else {
    printf("The mark %d is a pass", mark);
}
 return 0;
}
