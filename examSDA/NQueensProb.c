#include <stdio.h>

#define N 8

int chessTable[N][N] = {{0}};
int a = 0;
void display () {
    for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++)
              printf("%d ", chessTable[i][j]);
         printf("\n");
    }
    printf("\n");     
}

int valid (int x, int y) {
    if (x < 0 && x >= N && y < 0 && y >= N)
        return 0;

    for (int i = 0; i < y; i++)
         if (chessTable[x][i] == 1)
             return 0;

    for (int i = 0; i < x; i++)
        if (chessTable[i][y] == 1)
            return 0;

    int i = x - 1, j = y - 1;

    while (i >= 0 && i >= 0) {
        if (chessTable[i][j] == 1)
            return 0;
        i--;
        j--;
    }

    i = x - 1, j = y + 1;

    while (i < N && j >= 0) {
        if (chessTable[i][j] == 1)
            return 0;
        i++;
        j--;
    }

    return 1;
}

int solution (int x) {
    if (x >= N)
        return 1;

    return 0;
}

void backtracking (int col) {
    if (solution(col)) {
        display();
        return;
    }

    for (int i = 0; i < N; i++) {
         if (valid(i, col)) {
             chessTable[i][col] = 1;
             a++;
             backtracking(col + 1);
             chessTable[i][col] = 0;
         }
    }
}

int main (void) {
    backtracking(0);
    printf("nr of solutions = %d ", a);
}