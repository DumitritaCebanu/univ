#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

typedef struct mesaje{
	int Id;
	int prioritate;
	char text[MAX];
	struct mesaje* next;
} mesaje;

typedef struct categorie{
	char tip[35];
	mesaje *first;
} categorie;

categorie tab[10];

int nr_cat = 0;
int length = 0, max_size = 10;

void adaugare_categorie(char tip[]){
	if (nr_cat < 10){
		strcpy(tab[nr_cat].tip, tip);
		tab[nr_cat].first = NULL;
		nr_cat++;
	}
}

void adaugare_mesaj(char tip[],char *text,int prioritate){
	mesaje* q = (mesaje *)malloc(sizeof(mesaje));
	strcpy(q->text, text);
	q->prioritate = prioritate;

	for (int i = 0; i < nr_cat; i++){
		if (strcmp(tab[i].tip, tip) == 0){
			mesaje *p;
			if (tab[i].first == NULL || tab[i].first->prioritate >= q->prioritate)
			{
				q->next = tab[i].first;
				tab[i].first = q;
			}
			else
			{
				p = tab[i].first;
				while (p->next != NULL && p->next->prioritate < q->prioritate)
				{
					p = p->next;
				}
				q->next = p->next;
				p->next = q;
			}
		}
	}
}
void transmitere_mesaj(char tip[]){
	for (int i = 0; i < nr_cat; i++){
		if (strcmp(tab[i].tip, tip) == 0){
			tab[i].first = tab[i].first->next;
		}
	}
}
/*
char deservire () {
    if (length == 0)
        return -1;
        
    int min = mesaje[0].prioritate, min_pos = 0;

    for (int i = 1; i < length; i++)
         if (mesaje[i].prioritate < min) {
             min = mesaje[i].prioritate;
             min_pos = i;
         }

    return mesaje[min_pos].text;
}
*/
void afisare()
{
	for (int i = 0; i < nr_cat; i++){
		printf("Categorie: %s\n", tab[i].tip);
		for (mesaje*p = tab[i].first; p != NULL; p = p->next){
			printf("\t%d %s\n", p->prioritate, p->text);
		}
	}
	printf("\n");
}

int main()
{
	adaugare_categorie("Craciun");
	adaugare_categorie("Paste");
	adaugare_mesaj("Craciun", "brad", 3);
	adaugare_mesaj("Craciun", "zapada",1);
	adaugare_mesaj("Craciun", "colinde", 5);
	adaugare_mesaj("Craciun", "fulgi ", 8);
	adaugare_mesaj("Paste", "flori", 3);
	adaugare_mesaj("Paste", "oua", 3);
	adaugare_mesaj("Paste", "sarbatoare", 2);
	adaugare_mesaj("Paste", "lumini", 12);
	
	afisare();
	return 0;
}