//sa se genere toti vectorii de n elemente 0.....a(n-1)
//cu urmatoarele proprietati
//R2
//a(0) = par;
//a(n-1) = 7 sau 8
// a(i) e par
// a(i + 1) e impar

#include <stdio.h>
#include <stdlib.h>

int v[100], n;

void afisare(int k){
    for (int i = 0; i < k; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int solutie (int k){
    if(k == n ) 
        return 0;
    return 1;
}

int valid(int k){
    if (v[0] % 2 == 0) return 0;
    if (k >= 2 && k <= n - 1){
         if (k % 2 == 0 && v[k ] % 2 == 0)
            return 0;
        if (k % 2 == 1 && v[k ] % 2 == 1)
            return 0;
        }
    if (k == n - 1)
      if (v[k] != 7 && v[k] != 8)
      return 0;

    return 1;
}

void backTraking(int k){
    for(int i = 0; i <= 9; i++){
    v[k] = i;
     if(valid(k))
            if(solutie(k))
                afisare(k);
            else backTraking(k + 1);
    }
}

void main (){
    printf("n= ");
    scanf("%d", &n);
    backTraking(0);
        
}