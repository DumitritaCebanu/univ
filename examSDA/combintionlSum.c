#include <stdio.h>

void printCombination(int out[], int n){
    for(int i = 0; i < n; i++)
        printf("%d ", out[i]);
    printf("\n");
}

void recursiv(int i, int n, int out[], int index){
    if (n == 0)
        printCombination(out, index);
    int j;
    for( j = i; j <= n; j++){
    out[index] = j;
    recursiv(j, n - j, out, index + 1);
    }
}

int main(void){
    int n = 5; 
    int out[n];
    recursiv(1, n, out, 0);
    return 0;
}