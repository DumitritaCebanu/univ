/*1. Se da un fisier continand date despre optiunile unor studenti cu privire la un set de materii optionale. 
Acest fisier poate fi gasit in sectiunea resurse laborator 3. Fisierul contine 10.000 de linii,
 fiecarui elev revenindu-i 2 linii consecutive din fisier. Pe prima linie din cele doua se afla numele studentuluiiar pe cea de a doua 
 se afla o serie de 4 coduri reprezentand tot atatea optiuni. Cunoscand ca sunt in total 5.000 de studenti si ca numele nici unui student 
 nu ocupa mai mult de 35 de caractere, se cere:
Sa se citeasca datele din fisier intr-un tablou de 5.000 de elemente de forma < nume , optional1, optional2, opptional3, optional4 >
·         Utilizand algoritmul de sortare prin amestecare (ShakerSort), sa se afiseze studentii alfabetic si apoi invers, si sa se 
contorizeze comparatiile si atribuirile care se fac in timpul sortarii
·         Utilizand algoritmul de sortare prin insertie (InsertSort), sa se afiseze optionalele unui student in ordinea alfabetica a acestora.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
    char nume[35];
    char optional_1[3];
    char optional_2[3];
    char optional_3[3];
    char optional_4[3];
} studenti[5000];

FILE *text_file;

void InsertSort(struct a[], int n)
{
 int i,j;
       //fanionul pe poziţia a[n]
 for(i = n - 2; i >= 0; i--)
 {
    a[n] = a[i];
    j = i + 1;
    while(a[j].cheie < a[n].cheie) 
    {
      a[j-1] = a[j]; 
      j++;                       
    }
    a[j-1] = a[n];
 }
}

int main (void) {

    text_file = fopen("D:/Studenti1.txt", "r");

    if (text_file == NULL) {
        printf("EROARE.");
        exit(-1);
    }

    char aux[255], c;
    int index = 0;
    fgets(aux, 255, text_file);
    
    while (!feof(text_file)) {
        fgets(studenti[index].nume, 35, text_file);
        int a = strlen(studenti[index].nume);
        studenti[index].nume[a - 1] = 0;
        fscanf(text_file, "%s", studenti[index].optional_1); 
        fscanf(text_file, "%s", studenti[index].optional_2);
        fscanf(text_file, "%s", studenti[index].optional_3);
        fscanf(text_file, "%s", studenti[index].optional_4);
        fscanf(text_file, "%c", &c);
        index++;
    }

    fclose(text_file);

}