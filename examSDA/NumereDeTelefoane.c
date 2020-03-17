#include <stdio.h>

int solutie[10];

int valid (int k) {
    int cifre_pare = 2;
    
    for (int i = 5; i <= k; i++)
         if (solutie[i] % 2 == 0)
             cifre_pare++;
    
    if (cifre_pare % 2 != 0)
        return 1;

    return 0;
}

int solution (int k) {
    if (k == 10)
        return 1;

    return 0;
}

void display (int k) {    
    for (int i = 1; i <= k; i++) {
        printf("%d", solutie[i]);
        if (i == 4 || i == 7)
            printf(" ");
    }

    printf("\n");
}

void backtraking (int k) {
     for (int i = 0; i <= 9; i++) {
         solutie[k] = i;
         if (valid(k))
             if (solution(k))
                 display(k);
             else 
                 backtraking(k + 1);
     }
}

int main (void) {
    solutie[1] = 0;
    solutie[2] = 7;
    solutie[3] = 2;
    solutie[4] = 1;
    backtraking(5);
}