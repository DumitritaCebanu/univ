#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *input_file, *output_file;

struct {
       char nume[35];
       float medie;
} array[5000];

int length = 5000, sel_count = 0, bubble_count = 0;

// Sortare crescatoare
void selectionSortInc () {

     for (int i = 0; i < length - 1; i++) {
          int min_index = i;
          sel_count++;
          for (int j = i + 1; j < length; j++) {
               sel_count++;
               if (array[j].medie < array[min_index].medie) {
                   min_index = j;
                   sel_count++;
               }
          }
          float temp = array[min_index].medie;
          array[min_index].medie = array[i].medie;
          array[i].medie = temp;
          sel_count += 3;
     }
}

// Sortare descrescatoare
void selectionSortDec () {

     for (int i = 0; i < length - 1; i++) {
          int max_index = i;
          for (int j = i + 1; j < length; j++)
               if (array[j].medie > array[max_index].medie)
                   max_index = j;
          float temp = array[max_index].medie;
          array[max_index].medie = array[i].medie;
          array[i].medie = temp;
     }
}

// Sortare crescatoare
void bubbleSortInc () {
     
     for (int i = 0; i < length - 1; i++)
          for (int j = 0; j < length - 1 - i; j++) {
              bubble_count++;
              if (array[j].medie > array[j + 1].medie) {
                  float temp = array[j].medie;
                  array[j].medie = array[j + 1].medie;
                  array[j + 1].medie = temp;
                  bubble_count += 3;
              }  
          }
}

// Sortare descrescatoare
void bubbleSortDec () {
     
     for (int i = 0; i < length - 1; i++)
          for (int j = 0; j < length - 1 - i; j++)
              if (array[j].medie < array[j + 1].medie) {
                  float temp = array[j].medie;
                  array[j].medie = array[j + 1].medie;
                  array[j + 1].medie = temp;
              }
}

void printArray () {
     
     for (int i = 0; i < length; i++) {
          fprintf(output_file, "%f", array[i].medie);
          if (i != length - 1)
              fprintf(output_file, "\n");
     }
}

int main (void) {

    input_file = fopen ("D:/Prob_2.txt", "r");

    if (!input_file) {
        printf("EROARE. Fisierul nu a putut fi deschis.\n");
        exit(-1);
    }

    int index = 0;
    char c;

    while (!feof(input_file)) {
           fgets(array[index].nume, 35, input_file);
           int l = strlen(array[index].nume);
           array[index].nume[l - 1] = 0;
           fscanf(input_file, "%f", &array[index].medie);
           fscanf(input_file, "%c", &c);
           index++;
    }

    fclose(input_file);
    output_file = fopen("D:/out.txt", "w");

    if (!output_file) {
        printf("EROARE. Fisierul nu poate fi deschis.\n");
        exit(-2);
    }

     selectionSortInc();
    // selectionSortDec();
     bubbleSortInc();
    // bubbleSortDec();
    printArray();
    fclose(output_file);
    printf("Numarul de operatii de atribuire si comparare in cadrul metodei selectiei: %d\n", sel_count);
    printf("Numarul de operatii de atribuire si comparare in cadrul metodei bulelor: %d\n\n", bubble_count);
}