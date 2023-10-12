
#include <stdio.h>
int main() {
    char name[15];
    char postcode[8];

    printf("Hello, please enter your name:");
    scanf("%s", name);
    printf("Your name is %s\n", name);
    printf("Hello, please enter your postcode:");
    scanf("%7s", postcode); //a number between the % and s restricts the printf below
    printf("Your postcode is %s\n", postcode);

  return 0;
}