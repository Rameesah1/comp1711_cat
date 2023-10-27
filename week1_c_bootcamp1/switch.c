

#include <stdio.h>
int main() {
 int a;  
 a= 0; //if all have break then the case that matches variable will output
 switch (a) 
 { case 0: printf ("Option 0 has been selected\n"); break; //for e.g if there was no break then option 0 and option 1 will be selected (but not option 2 as there is a break after case 1).
 
    case 1: printf ("Option 1 has been selected\n"); break; //the break here terminates the switch statement, terminating any subsequent case or default blocks from executing

     case 2: printf ("Option 2 has been selected\n"); 
   }

   return 0;
    }
