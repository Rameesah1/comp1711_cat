

#include <stdio.h>
int main() {
 int a;  
 a= 0; //if all have break then the case that matches variable will output
 switch (a) 
 { case 1: printf ("Option 0 has been selected\n"); break;  //for e.g if there was no breaks at all options be selected 
 
    case 0: printf ("Option 1 has been selected\n");  //the break here terminates the switch statement, terminating any subsequent case or default blocks from executing

     case 2: printf ("Option 2 has been selected\n"); 
   }              //the case that matches the variable will print - in this casse- case 0
                      
   return 0;
    }
