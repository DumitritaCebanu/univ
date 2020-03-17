#include <stdio.h>
#include <stdlib.h>

#define N 10

struct masina {
    char *nrInmatriculare;
    struct masina *next;
};

struct parc {
    int ID;
    struct masina *car;
} parcuri[N];

void initializareParcuri () {
    for (int index = 0; index < N; index++) 
         parcuri[index].ID = index;
}

void transferaMasina (int ID, char *nrInmatriculare) {
       for (int index = 0; index < N; index++)
            if (parcuri[index].ID == ID) {
                struct masina *newNode = (struct masina *) malloc (sizeof(struct masina));
                newNode->nrInmatriculare = nrInmatriculare;
                newNode->next = NULL;
                if (parcuri[index].car == NULL) {
                    parcuri[index].car = newNode;
                    return;
                }
                struct masina *temp;
                for (temp = parcuri[index].car; temp->next != NULL; temp = temp->next);
                temp->next = newNode;
                return;
            }
}

void listeazaParc () {
    struct masina *temp;

    for (int index = 0; index < N; index++) 
        if (parcuri[index].car != NULL) {
            printf("ID-ul parcului auto: %d\n", parcuri[index].ID);
            for (temp = parcuri[index].car; temp != NULL; temp = temp->next)
                printf("%s ", temp->nrInmatriculare);
            printf("\n\n");
        }

    printf("\n");
}

int main (void) {
    initializareParcuri();

    transferaMasina(0, "TTL120");
    transferaMasina(0, "QQQ564");
    transferaMasina(3, "QYR110");
    transferaMasina(3, "KAW850");
    transferaMasina(3, "PRM009");

    listeazaParc();
}