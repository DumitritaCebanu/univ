#include <stdio.h>

#define N 8

int solution[N][N] = {{0}};

void printSolution () {
    for (int index_1 = 0; index_1 < N; index_1++) {
         for (int index_2 = 0; index_2 < N; index_2++)
              printf("%d ", solution[index_1][index_2]);
         printf("\n");
    }

    printf("\n");     
}

int validSolution (int x, int y) {
    if (x < 0 && x >= N && y < 0 && y >= N)
        return 0;

    for (int index = 0; index < y; index++)
         if (solution[x][index] == 1)
             return 0;

    for (int index = 0; index < x; index++)
        if (solution[index][y] == 1)
            return 0;

    int index_1 = x - 1, index_2 = y - 1;

    while (index_1 >= 0 && index_2 >= 0) {
        if (solution[index_1][index_2] == 1)
            return 0;
        index_1--;
        index_2--;
    }

    index_1 = x - 1, index_2 = y + 1;

    while (index_1 < N && index_2 >= 0) {
        if (solution[index_1][index_2] == 1)
            return 0;
        index_1++;
        index_2--;
    }

    return 1;
}

int isSolution (int x) {
    if (x >= N)
        return 1;

    return 0;
}

void backtracking (int col) {
    if (isSolution(col)) {
        printSolution();
        return;
    }

    for (int index = 0; index < N; index++) {
         if (validSolution(index, col)) {
             solution[index][col] = 1;
             backtracking(col + 1);
             solution[index][col] = 0;
         }
    }
}

int main (void) {
    backtracking(0);
}