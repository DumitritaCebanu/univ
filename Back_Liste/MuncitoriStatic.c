#include <stdio.h>
#include <stdlib.h>

#define N 10

int nrEchipa = 0;

struct echipa {
    int ID;
    int dimMax;
    int nrMembri;
    char **membru;
} echipa[N];

void adaugareEchipa (int ID, int dimMax) {
    echipa[nrEchipa].ID = ID;
    echipa[nrEchipa].dimMax = dimMax;
    echipa[nrEchipa].nrMembri = 0;

    echipa[nrEchipa].membru = (char **) malloc (dimMax * sizeof(char *));

    if (echipa[nrEchipa].membru == NULL) {
        printf("Memoria nu a fost alocata corespunzator.\n");
        exit(1);
    }

    for (int index = 0; index < dimMax; index++)  {
         echipa[nrEchipa].membru[index] = (char *) malloc (100 * sizeof(char));
         echipa[nrEchipa].membru[index] = "";
         if (echipa[nrEchipa].membru == NULL) {
             printf("Memoria nu a fost alocata corespunzator.\n");
             exit(2);
         }
    }
    
    nrEchipa++;
}

void adaugareMembru (int ID, char *membru) {
       for (int index = 0; index < nrEchipa; index++)
            if (echipa[index].ID == ID && echipa[index].nrMembri < echipa[index].dimMax) {
                for (int i = echipa[index].nrMembri; i >= 1; i--)
                     echipa[index].membru[i] = echipa[index].membru[i - 1];
                echipa[index].membru[0] = membru;
                echipa[index].nrMembri++;
                return;
            }
}

void afisare () {
    for (int index1 = 0; index1 < nrEchipa; index1++) 
        if (echipa[index1].nrMembri != 0) {
            printf("ID-ul echipei: %d\n", echipa[index1].ID);
            printf("Membrii: \n");
            for (int index2 = 0; index2 < echipa[index1].nrMembri; index2++)
                puts(echipa[index1].membru[index2]);
            printf("\n");
        }
}

int main (void) {
    adaugareEchipa(0, 4);
    adaugareEchipa(1, 4);
    adaugareEchipa(2, 13);
    
    adaugareMembru(0, "Victor");
    adaugareMembru(0, "Denisa");
    adaugareMembru(0, "Dumitrita");
    adaugareMembru(0, "Cristi");
    adaugareMembru(2, "Ion");

    afisare();
}