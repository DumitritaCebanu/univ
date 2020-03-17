#include <stdio.h>
#include <stdlib.h>

struct echipa {
    int ID;
    int dimMax;
    int nrMembri;
    char **membru;
    struct echipa *next;
} *echipa;

struct echipa *adaugareEchipa (int ID, int dimMax) {
    struct echipa *newNode = (struct echipa *) malloc (sizeof(struct echipa));

    newNode->ID = ID;
    newNode->dimMax = dimMax;
    newNode->nrMembri = 0;
    newNode->next = NULL;

    newNode->membru = (char **) malloc (dimMax * sizeof(char *));

    if (newNode->membru == NULL) {
        printf("Memoria nu a fost alocata corespunzator.\n");
        exit(1);
    }

    for (int index = 0; index < dimMax; index++)  {
         newNode->membru[index] = (char *) malloc (100 * sizeof(char));
         newNode->membru[index] = "";
         if (newNode->membru == NULL) {
             printf("Memoria nu a fost alocata corespunzator.\n");
             exit(2);
         }
    }

    if (echipa == NULL) {
        echipa = newNode;
        return echipa;
    }
    
    struct echipa *temp;

    for (temp = echipa; temp->next != NULL; temp = temp->next);
    temp->next = newNode;
    return echipa;
}

void adaugareMembru (int ID, char *membru) {
       struct echipa *temp;

       for (temp = echipa; temp != NULL; temp = temp->next)
            if (temp->ID == ID && temp->nrMembri < temp->dimMax) {
                temp->nrMembri++;
                for (int i = echipa->nrMembri; i >= 1; i--)
                     temp->membru[i] = temp->membru[i - 1];
                temp->membru[0] = membru;
                return;
            }
}

void afisare () {
    struct echipa *temp;
    
    for (temp = echipa; temp != NULL; temp = temp->next) 
        if (temp->nrMembri != 0) {
            printf("ID-ul echipei: %d\n", temp->ID);
            printf("Membrii: \n");
            for (int index = 0; index < temp->nrMembri; index++)
                puts(temp->membru[index]);
            printf("\n");
        }
}

int main (void) {
    echipa = NULL;

    echipa = adaugareEchipa(0, 4);
    echipa = adaugareEchipa(1, 4);
    echipa = adaugareEchipa(2, 13);
    
    adaugareMembru(0, "Victor");
    adaugareMembru(0, "Denisa");
    adaugareMembru(0, "Dumitrita");
    adaugareMembru(0, "Cristi");
    adaugareMembru(2, "Ion");

    afisare();
}