#include <stdio.h>

#define N 4

int solution[N][N] = {{0, 0, 0, 0}, 
                      {0, 0, 0, 0}, 
                      {0, 0, 0, 0}, 
                      {0, 0, 0, 0}}; 

int maze[N][N] = {{1, 0, 0, 0}, 
                  {1, 1, 0, 1}, 
                  {0, 1, 0, 0}, 
                  {1, 1, 1, 1}}; 

void printSolution () {
    for (int index_1 = 0; index_1 < N; index_1++) {
        for (int index_2 = 0; index_2 < N; index_2++)
             printf("%d ", solution[index_1][index_2]);
        printf("\n");
    }

    printf("\n");
}

int validSolution (int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
       return 1;

    return 0;
}

int backtracking (int x, int y) {
    if (x == N - 1 && y == N - 1) {
         solution[x][y] = 1;
         printSolution();
         return 1;
    }

    if (validSolution(x, y)) {
        solution[x][y] = 1;
        if (backtracking(x + 1, y))
            return 1;
        if (backtracking(x, y + 1))
            return 1;
        solution[x][y] = 0;
        return 0;
    }

    return 0;
}

int main (void) {
    backtracking(0, 0);
}