#include <stdio.h>
#include <stdlib.h>

struct rezervare {
    char categorie;
    int ID;
    int nrSolicitari;
    char *solicitant[35];
    struct rezervare *next;
};

struct rezervare *adaugaCategorie (struct rezervare *rezervare, char c, int ID) {
    struct rezervare *newNode = (struct rezervare*) malloc (sizeof(struct rezervare));
    
    newNode->categorie = c;
    newNode->ID = ID;
    newNode->nrSolicitari = 0;
    newNode->next = NULL;

    if (rezervare == NULL) {
        rezervare = newNode;
        return rezervare;
    }

    struct rezervare *temp;

    for (temp = rezervare; temp->next != NULL; temp = temp->next);
    temp->next = newNode;

    return rezervare;
}

void adaugareCerere (struct rezervare *rezervare, char *solicitant, char c) {
     struct rezervare *temp;

     for (temp = rezervare; temp != NULL; temp = temp->next) {
         if (temp->categorie == c) {
             temp->solicitant[temp->nrSolicitari] = solicitant;
             temp->nrSolicitari++;
             return;
         }
     }
}

void afisare (struct rezervare *rezervare) {
    struct rezervare *temp;

    for (temp = rezervare; temp != NULL; temp = temp->next) 
        if (temp->nrSolicitari != 0) {
            printf("Categoria: %c\n", temp->categorie);
            for (int index = temp->nrSolicitari - 1; index >= 0; index--)
                 puts(temp->solicitant[index]);
            printf("\n");
        }
    
    printf("\n");
}

int main (void) {
    struct rezervare *rezervare = NULL;

    rezervare = adaugaCategorie(rezervare, 'a', 0);
    rezervare = adaugaCategorie(rezervare, 'a', 1);
    rezervare = adaugaCategorie(rezervare, 'b', 2);
    rezervare = adaugaCategorie(rezervare, 'c', 3);
    
    adaugareCerere(rezervare, "Victor", 'a');
    adaugareCerere(rezervare, "Denisa", 'a');
    adaugareCerere(rezervare, "Ion", 'c');

    afisare(rezervare);
}