#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

typedef struct mesaje{
	char text[MAX];
	struct mesaje* next;
} mesaje;

typedef struct categorie{
	int tip;
	mesaje *first;
} categorie;

categorie tab[10];
int nr_tipuri = 0;
int length = 0;

void adaugare_categorie(int tip){
	struct categorie aux;
	if (nr_tipuri < 10){
		tab[nr_tipuri].tip = tip;
		tab[nr_tipuri].first = NULL;
		nr_tipuri++;
	}
	/*for(int i = 0; i < nr_tipuri; i++)
		for (int j = 0; j < nr_tipuri - i - 1; j++)
			if (tab[j].tip > tab[j + 1].tip)
			{
			 int aux = tab[j].tip;
			 tab[j].tip = tab[j + 1].tip;
			 tab[j + 1].tip = aux;
			 }*/
}


void adaugare_mesaj(int tip,char *text){
	mesaje* q = (mesaje *)malloc(sizeof(mesaje));
	strcpy(q->text, text);

	for (int i = 0; i < nr_tipuri; i++){
		if (tab[i].tip == tip){
			mesaje *p;
			if (tab[i].first == NULL) 
			{
				q->next = tab[i].first;
				tab[i].first = q;
			}
			else
			{
				p = tab[i].first;
				while (p->next != NULL) 
				{
					p = p->next;
				}
				q->next = p->next;
				p->next = q;
			}
		}
	}
}
/*char pop () {
    if (length == 0)
        return -1;
        
    char min;
	int min_pos = 0; ;
	strcpy(min, tab[0].tip);

    for (int i = 1; i < length; i++)
         if (strcmp(tab[i].tip, min) < 0) {
             strcpy(min, tab[i].tip);
             min_pos = i;
         }

    return tab[min_pos].tip;
}*/
void afisare()
{
	for (int i = 0; i < nr_tipuri; i++){
		printf("Categorie cu prioritatea:  %d\n", tab[i].tip);
		for (mesaje*p = tab[i].first; p != NULL; p = p->next){
			printf("\t%s\n", p->text);
		}
	}
	printf("\n");
}

int main()
{
	adaugare_categorie(1);
	adaugare_categorie(2);
	adaugare_categorie(3);
	adaugare_mesaj(1, "Avion");
	adaugare_mesaj(2, "Submarin");
	adaugare_mesaj(2, "Barca");
	adaugare_mesaj(3, "Bicicleta");
	adaugare_mesaj(1, "Masina");
	adaugare_mesaj(3, "Motocicleta");
	adaugare_mesaj(3, "Trotineta");
	pop();
	afisare();
	return 0;
}