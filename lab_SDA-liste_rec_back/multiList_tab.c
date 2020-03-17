#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

typedef struct mesaje{
    int ID;
	int prioritate;
	char text[MAX];
	struct mesaje* next;
} mesaje;

typedef struct planificator{
	char message;
	mesaje *first;
} planificator;

planificator tab[10];
int k = 0;

void adaugaCategorie(char message){
	if (k < 10){
		tab[k].message = message;
		tab[k].first = NULL;
		k++;
	}
}
void adaugaMesaj(char message,char *text,int prioritate){
	mesaje* q = (mesaje *)malloc(sizeof(mesaje));
	strcpy(q->text, text);
	q->prioritate = prioritate;

	for (int i = 0; i < k; i++){
		if (tab[i].message == message){
			if (tab[i].first == NULL){
				tab[i].first = q;
				q->next = NULL;
			}
			else{
				mesaje* p = tab[i].first;
				while (p->next != NULL){
					p = p->next;
				}
				p->next = q;
				q->next = NULL;
			}
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
void deservire(){

}
void afisare()
{
	for (int i = 0; i < k; i++){
		printf("Prioritate:%c\n", tab[i].message);
		for (mesaje*p = tab[i].first; p != NULL; p = p->next){
			printf("\t%d %s\n", p->prioritate, p->text);
		}
	}
	printf("\n");
}
int main()
{
	adaugaCatPrioritati('a');
	adaugaCatPrioritati('b');
	adaugaMesaj('a', "hello", 6);
	adaugaMesaj('a', "good",1);
	adaugaMesaj('a', "felice", 5);
	adaugaMesaj('b', "old ", 123);
	adaugaMesaj('b', "gold", 3);
	adaugaMesaj('b', "ancestors", 32);
	adaugaMesaj('b', "children", 12);
//transmitere_mesaj('a');
//transmitere_mesaj('b');
	afisare();
	return 0;
}