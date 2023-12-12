// /* #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Define the struct for the fitness data
// typedef struct {
//     char date[11];
//     char time[6];
//     int steps;
// } FITNESS_DATA;

// // Function to tokenize a record
// void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
//     char *ptr = strtok(record, &delimiter);
//     if (ptr != NULL) {
//         strcpy(date, ptr);
//         ptr = strtok(NULL, &delimiter);
//         if (ptr != NULL) {
//             strcpy(time, ptr);
//             ptr = strtok(NULL, &delimiter);
//             if (ptr != NULL) {
//                 *steps = atoi(ptr);
//             }
//         }
//      }
// }
        
        
// int import_file(char *filename, FITNESS_DATA Fitnessdata[], int *records) {
//             FILE *file = fopen(filename, "r");
//             if (file == NULL) {
//                 fprintf(stderr, "Error: Could not find or open the file.\n");
//                 return 0;
//             }

//             char line_buffer[100];
//             char date[11], time[6], steps[10];
//             *records = 0;

//             while (*records < 1000 && fgets(line_buffer, sizeof(line_buffer), file) != NULL) {
//                 tokeniseRecord(line_buffer, "," , date, time, steps);

//                 strcpy(Fitnessdata[*records].date, date);
//                 strcpy(Fitnessdata[*records].time, time);
//                 Fitnessdata[*records].steps = atoi(steps);  
                
//                 (*records)++;
//             }
//         }

// void bubble_Sort(FITNESS_DATA Fitnessdata[], int records)


// int main() {
    
//     FITNESS_DATA Fitnessdata[1000];

//     printf("Input filename: ");
//     scanf("%20s", filename);  // Limit input to 20 characters

//     if (!import_file(filename, Fitnessdata, &records)) {
//     return 1;
//     }

    
//     bubble_Sort(Fitnessdata, records);  //the call to bubblesort

//     for (int i = 0; i < records, i++) {
//         printf ("%d\n", Fitnessdata[i].steps);
//         }
// }

// void bubble_Sort(FITNESS_DATA Fitnessdata[], int records) 
//    {
//     for (int i = 0; i < records, i++ ) {

//         for (int j = 0;, j < ( records - 1 ); j++ )

//             {
//                 if (Fitnessdata[j].steps > Fitnessdata [j + 1].steps)
//             /   {
//                 int temp = Fitnessdata[j].steps;
//                 Fitnessdata[j].steps = Fitnessdata[j+1].steps;
//                 Fitnessdata[j+1].steps = temp;
//                 }
//             }
//         } 
    

//     return 0;
    
// }
// */

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Define the struct for the fitness data
// typedef struct {
//     char date[11];
//     char time[6];
//     int steps;
// } FITNESS_DATA;

// // Function to tokenize a record
// void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
//     char *ptr = strtok(record, &delimiter);
//     if (ptr != NULL) {
//         strcpy(date, ptr);
//         ptr = strtok(NULL, &delimiter);
//         if (ptr != NULL) {
//             strcpy(time, ptr);
//             ptr = strtok(NULL, &delimiter);
//             if (ptr != NULL) {
//                 *steps = atoi(ptr);
//             }
//         }
//     }
// }

// // Function to import data from a file
// int open_file(char *filename, FITNESS_DATA Fitnessdata[], int *records) {
//     FILE *file = fopen(filename, "r");
//     if (file == NULL) {
//         fprintf(stderr, "Error: Could not find or open the file.\n");
//         return 0;
//     }

//     char line_buffer[100];
//     char date[11], time[6];
//     int steps;
//     *records = 0;

//     while (*records < 1000 && fgets(line_buffer, sizeof(line_buffer), file) != NULL) {
//       //  tokeniseRecord(line_buffer, ',', date, time, &steps); {
//             if (strrchr(line_buffer, '.') == NULL) {
//                 printf("Incorrect file type. Must be a CSV file.\n");
//                 return 0;
//             }
    
                
//         tokeniseRecord(line_buffer, ',', date, time, &steps);

//         strcpy(Fitnessdata[*records].date, date);
//         strcpy(Fitnessdata[*records].time, time);
       
//         Fitnessdata[*records].steps = steps;  
        
//         (*records)++;
//     }

//     fclose(file);
//     return 1;
// }
// //function for TSV file output


// // Function to sort the data using bubble sort
// void bubble_Sort(FITNESS_DATA Fitnessdata[], int records) {
//     for (int i = 0; i < records - 1; i++) {
//         for (int j = 0; j < records - i - 1; j++) {
//             if (Fitnessdata[j].steps < Fitnessdata[j + 1].steps) {
//                 FITNESS_DATA temp = Fitnessdata[j];
//                 Fitnessdata[j] = Fitnessdata[j + 1];
//                 Fitnessdata[j + 1] = temp;
//             }
//         }
//     }
// }
// void write_to_tsv(FITNESS_DATA Fitnessdata[], int records, const char *filename) {
//     FILE *file = fopen(filename, "w");
//     if (file == NULL) {
//         fprintf(stderr, "Error: Could not open the file for writing.\n");
//         return;
//     }

//     // Writing header (optional)
//     fprintf(file, "Date\tTime\tSteps\n");

//     // Writing data
//     for (int i = 0; i < records; i++) {
//         fprintf(file, "%s\t%s\t%d\n", Fitnessdata[i].date, Fitnessdata[i].time, Fitnessdata[i].steps);
//     }

//     fclose(file);
// }

// /*int main() {
//     FITNESS_DATA Fitnessdata[1000];
//     int records = 0;
//     char filename[21];
//     char tsvFilenameoutput[100];

//     printf("Input filename: ");
//     scanf("%s", filename);  // Limit input to 20 characters

//     if (!open_file(filename, Fitnessdata, &records)) {
//         return 1;
//     }

//     bubble_Sort(Fitnessdata, records);  // Call to bubbleSort

//     for (int i = 0; i < records; i++) {
//         printf("Date: %s, Time: %s, Steps: %d\n", Fitnessdata[i].date, Fitnessdata[i].time, Fitnessdata[i].steps);
//     }

//     return 0;
// }
// */
// int main() {
//     FITNESS_DATA Fitnessdata[1000];
//     int records = 0;
//     char inputFilename[100];
//     char outputFilename[100];  // Increased size to accommodate additional extension

//     printf("Input CSV filename: ");
//     scanf("%20s", inputFilename);  // Limit input to 20 characters

//     if (!open_file(inputFilename, Fitnessdata, &records)) {
//         return 1;
//     }

//     bubble_Sort(Fitnessdata, records);  // Call to bubbleSort

//     // Create output filename by appending ".tsv" to the input filename
//     snprintf(outputFilename, sizeof(outputFilename), "%s.tsv", inputFilename);
    
//     // Write data to the new TSV file
//     write_to_tsv(Fitnessdata, records, outputFilename);

//     // Optional: Print sorted data
//     for (int i = 0; i < records; i++) {
//         printf("Date: %s, Time: %s, Steps: %d\n", Fitnessdata[i].date, Fitnessdata[i].time, Fitnessdata[i].steps);
//     }

//     return 0;
// }

 


// Function to write data to a TSV file
// void write_to_tsv(FITNESS_DATA Fitnessdata[], int records, const char *filename) {
//     FILE *file = fopen(filename, "w");
//     if (file == NULL) {
//         fprintf(stderr, "Error: Could not open the file for writing.\n");
//         return;
//     }

//     fprintf(file, "Date\tTime\tSteps\n"); // Writing header
//     for (int i = 0; i < records; i++) {
//         fprintf(file, "%s\t%s\t%d\n", Fitnessdata[i].date, Fitnessdata[i].time, Fitnessdata[i].steps);
//     }

//     fclose(file);
// }


    // printf("Input CSV filename: ");
    // scanf("%20s", inputFilename);

   
    bubble_Sort(Fitnessdata, records);

    // Generate output filename by appending ".tsv" to the input filename
    printf(outputFilename, sizeof(outputFilename), "%s.tsv", inputFilename);
    write_to_tsv(Fitnessdata, records, outputFilename); // Write data to TSV file

    printf("Data sorted and written to %s\n", outputFilename); // Optional confirmation message

    return 0;
}
