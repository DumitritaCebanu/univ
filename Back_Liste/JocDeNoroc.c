#include <stdio.h>
#include <stdlib.h>

int A, B, N, arraySol[1000];

void displaySolution (int k) {
    for (int index = 1; index <= k; index++)
        printf("%d ", arraySol[index]);

    printf("\n");
}

void backtracking (int k, int val[]) {
    for (int index = 0; index < 2; index++) {
        arraySol[k] = val[index];
        if (k == N) {
            int sum = 0;
            for (int i = 1; i <= k; i++)
                 sum += arraySol[i];
            if (sum == A)
                displaySolution(k);
        } 
        else 
            backtracking(k + 1, val);      
    }
}

int main (void) {
    printf("Suma initiala de bani: ");
    scanf("%d", &A);
    printf("Suma ce poate fi castigata/pierduta: ");
    scanf("%d", &B);
    printf("Numarul de runde: ");
    scanf("%d", &N);
    printf("\n");

    int val[] = {-B, B};

    backtracking(1, val);
}