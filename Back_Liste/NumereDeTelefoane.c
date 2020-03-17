#include <stdio.h>

int solutie[10];

int validSolutions (int k) {
    int cifrePare = 2;
    
    for (int index = 5; index <= k; index++)
         if (solutie[index] % 2 == 0)
             cifrePare++;
    
    if (cifrePare % 2 != 0)
        return 1;

    return 0;
}

int isSolution (int k) {
    if (k == 10)
        return 1;

    return 0;
}

void displaySolution (int k) {    
    for (int index = 1; index <= k; index++) {
        printf("%d", solutie[index]);
        if (index == 4 || index == 7)
            printf(" ");
    }

    printf("\n");
}

void findSolutions (int k) {
     for (int index = 0; index <= 9; index++) {
         solutie[k] = index;
         if (validSolutions(k))
             if (isSolution(k))
                 displaySolution(k);
             else 
                  findSolutions(k + 1);
     }
}

int main (void) {
    solutie[1] = 0;
    solutie[2] = 7;
    solutie[3] = 2;
    solutie[4] = 1;
    findSolutions(5);
}