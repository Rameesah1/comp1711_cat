#include <stdio.h>

struct student { //not creating a variable- it is creating a new type
char name [20];
char student_id [10]; // Assuming up to 10 digits.
unsigned mark;
}; //semi colon at end 

int main () {
struct student new_student = {
                              .name ="Name Surname",
                              .student_id = "28932123",
                              .mark = 35
                             };  //create a variable of ... the dot is the only way to access the field of a struct
printf("Student name: %s\n"
, new_student.name);
printf("Student ID: %s\n"
, new_student.student_id);
printf("Final mark: %u\n"
, new_student.mark);
return 0;
}