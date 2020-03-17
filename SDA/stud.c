/*
Sortare prin insertie & Sortare prin bubblesort (sortare descrescator dupa nota, alfabetic daca notele sunt egale)
*/
#include <stdio.h>
#include<stdlib.h>

#define MAX 10000

struct student{
    char nume[50];
    float nota;
}s[MAX];

void afisare(int N){
    int i;
    for(i=0;i<N;i++)
        printf("%s\n%f\n",s[i].nume,s[i].nota);
}

void insertsort(struct student a[],int n){
    int i,j;
    //fanionul pe poziĹŁia a[n]
    for( i=n-2;i>=0;i--){
        a[n]=a[i];
        j=i+1;
        while((a[j].nota>a[n].nota) || ((a[j].nota==a[n].nota) && (strcmp(a[j].nume,a[n].nume) < 0 ))){
            a[j-1]=a[j];
            j++;
        }
        a[j-1]=a[n];
    }
}

void bubblesort(struct student a[], int n){
    int i,j;
    struct student temp;
    for( i= 0; i < n - 1; i ++){
        for( j= i+1; j<n; j ++)
            if (a[i].nota<a[j].nota){
                temp = a[i]; a[i]= a[j]; a[j]= temp;
            }
            else if((a[i].nota==a[j].nota) && (strcmp(a[i].nume,a[j].nume) > 0 ) ) {
                temp = a[i]; a[i]= a[j]; a[j]= temp;
            }
    }
}

int main(){
    FILE *f=fopen("Studenti2.txt","rt");
    int N;
    int i=0;


    // CITIRE DIN FISIER

    while(!feof(f)){
        fgets(s[i].nume,50,f);
        s[i].nume[strlen(s[i].nume)-1]='\0';
        fscanf(f,"%f\n",&s[i].nota);
        i++;
    }
    N=i;

    // SORTARE PRIN INSERTIE

    insertsort(s,N);

    // SORTARE PRIN BUBBLESORT

    bubblesort(s,N);

    // AFISARE DATE

    afisare(N);

    return 0;
}

