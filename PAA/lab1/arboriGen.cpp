#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_N 10

struct Zona{
	char cheie;
	int prim_fiu;
	int fr_dr;
};
struct Arbore{
	struct Zona noduri[MAX_N + 1];
	int radacina;
	int count_noduri;
};

Arbore arbore;

void initial(){
	arbore.count_noduri = 0;
	for (int i = 0; i <= MAX_N; i++){
		arbore.noduri[i].prim_fiu = 0;
		arbore.noduri[i].fr_dr = 0;
		arbore.radacina = 0;
	}//arbore gol sau reinitializare pe 0 tot 
}
int grad(){
	//parcurgi toate noduri ..mergi pe copii->fragii drepti ..return max
	int max = 0;
	int count = 0;
	for (int i = 1; i <= arbore.count_noduri; i++){
		if (arbore.noduri[i].prim_fiu != 0){
			int index = arbore.noduri[i].prim_fiu;
			while (arbore.noduri[index].fr_dr != 0){
				index = arbore.noduri[index ].fr_dr;
				count++;
			}
		}
	}
	if (count > max) {
		max = count;
	}
		return max + 1;
}
void inserare(char cheie, int parinte){
	int index = ++arbore.count_noduri;
	arbore.noduri[index].cheie = cheie;
	int index_fii;
	if (arbore.radacina == 0) {
		if (parinte != 0)
			printf("eroare");
	}
	else arbore.radacina = index;
	if (arbore.noduri[parinte].prim_fiu == 0)
		arbore.noduri[parinte].prim_fiu = index;
	else {
		index_fii = arbore.noduri[parinte].prim_fiu;
		while (arbore.noduri[index_fii].fr_dr != 0){
			index_fii = arbore.noduri[index_fii].fr_dr;
		}
		arbore.noduri[index_fii].fr_dr;
	}
}


void main(){
	initial();
	inserare('a' ,0);
	inserare('b', 1);
	inserare('c', 1);
}


