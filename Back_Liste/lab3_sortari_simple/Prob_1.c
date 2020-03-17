#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *input_file, *output_file;

struct {
       char nume[35];
       char optional1[3];
       char optional2[3];
       char optional3[3];
       char optional4[3];
} array[5000];

int length = 5000, cock_sort = 0;

// Sortare crescatoare
void CocktailSortInc () {

     int swapped = 1, start = 0, end = length - 1;
     char temp[35];

     while (swapped) {
            swapped = 0;
            cock_sort++;
            for (int index = start; index < end; index++) {
                 cock_sort++;
                 if (strcmp(array[index].nume, array[index + 1].nume) > 0) {
                      strcpy(temp, array[index].nume);
                      strcpy(array[index].nume, array[index + 1].nume);
                      strcpy(array[index + 1].nume, temp);
                      swapped = 1;
                      cock_sort += 4;
                 }
            }
            cock_sort++;
            if (!swapped)     
                break;
            swapped = 0;
            end--;
            cock_sort += 2;
            for (int index = end - 1; index >= start; index--) {
                 cock_sort++;
                 if (strcmp(array[index].nume, array[index + 1].nume) > 0) {
                      strcpy(temp, array[index].nume);
                      strcpy(array[index].nume, array[index + 1].nume);
                      strcpy(array[index + 1].nume, temp);
                      swapped = 1;
                      cock_sort += 4;
                 }
            }
            start++;
            cock_sort++;
     }
}

// Sortare descrescatoare
void CocktailSortDec () {

     int swapped = 1, start = 0, end = length - 1;
     char temp[35];

     while (swapped) {
            swapped = 0;
            for (int index = start; index < end; index++)
                 if (strcmp(array[index].nume, array[index + 1].nume) < 0) {
                      strcpy(temp, array[index].nume);
                      strcpy(array[index].nume, array[index + 1].nume);
                      strcpy(array[index + 1].nume, temp);
                      swapped = 1;
                 }
            if (!swapped)
                break;
            swapped = 0;
            end--;
            for (int index = end - 1; index >= start; index--)
                 if (strcmp(array[index].nume, array[index + 1].nume) < 0) {
                      strcpy(temp, array[index].nume);
                      strcpy(array[index].nume, array[index + 1].nume);
                      strcpy(array[index + 1].nume, temp);
                      swapped = 1;
                 }
            start++;
     }
}

// Sortare prin insertie

void insertionSort (int index) {

     char aux_array[4][4];
     strcpy(aux_array[0], array[index].optional1);
     strcpy(aux_array[1], array[index].optional2);
     strcpy(aux_array[2], array[index].optional3);
     strcpy(aux_array[3], array[index].optional4);

     char key[3];
     int j;

     for (int i = 1; i < 4; i++) {
          strcpy(key, aux_array[i]);
          for (j = i - 1; j >= 0 && strcmp(aux_array[j], key) > 0; j--)
               strcpy(aux_array[j + 1], aux_array[j]);
          strcpy(aux_array[j + 1], key);
     }


     puts(array[index].nume);
     for (int i = 0; i < 4; i++)
          printf("%s ", aux_array[i]);

     printf("\n\n");

}

// Afisarea vectorului
void printArray () {

     for (int index = 0; index < length; index++) {
          fputs(array[index].nume, output_file);
          if (index != length - 1)
              fprintf(output_file, "\n");
     }
}

int main (void) {

    input_file = fopen("D:/Prob_1.txt", "r");

    if (!input_file) {
        printf("Eroare. Fisierul nu a putut fi deschis.\n");
        exit(-1);
    }

    int index = 0;
    char aux;

    while (!feof(input_file)) {
           fgets(array[index].nume, 35, input_file);
           int l = strlen(array[index].nume);
           array[index].nume[l - 1] = 0;
           fscanf(input_file, "%s", array[index].optional1);
           fscanf(input_file, "%s", array[index].optional2);
           fscanf(input_file, "%s", array[index].optional3);
           fscanf(input_file, "%s", array[index].optional4);
           fscanf(input_file, "%c", &aux);
           index++;
    }

    fclose(input_file);
    CocktailSortInc();
    output_file = fopen("D:/out.txt", "w");

    if (!output_file) {
        printf("Eroare. Fisierul nu a putut fi deschis.\n");
        exit(-2);
    }

    printArray();
    fclose(output_file);

    // for (int index = 0; index < length; index++)
        // insertionSort(index);

    printf("Numarul operatiilor de atribuire si comparari efectuate in cadrul metodei amestecului: %d\n\n", cock_sort);
}
