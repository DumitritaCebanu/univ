#include <stdio.h>

#define N 9

int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                  {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                  {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                  {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                  {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                  {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                  {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                  {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                  {0, 0, 5, 2, 0, 6, 3, 0, 0}}; 

int validSolution (int x, int y, int num) {
    for (int index = 0; index < N; index++)
         if (grid[x][index] == num)
             return 0;

    for (int index = 0; index < N; index++)
         if (grid[index][y] == num)
             return 0;

    return 1;
}

int isSolution () {
    for (int index_1 = 0; index_1 < N; index_1++)
         for (int index_2 = 0; index_2 < N; index_2++)
              if (grid[index_1][index_2] == 0)
                  return 0;

    return 1;
}

void printSolution () {
    for (int index_1 = 0; index_1 < N; index_1++) {
        for (int index_2 = 0; index_2 < N; index_2++) 
             printf("%d ", grid[index_1][index_2]);
        printf("\n");
    }

    printf("\n");
}

void findSolutions (int i, int j) {
     if (isSolution()) {
         printSolution();
         return;
     }

     if (grid[i][j] == 0) {
         for (int num = 1; num <= 9; num++) 
              if (validSolution(i, j, num)) {
                  grid[i][j] = num;
                  if (i == N - 1)
                      findSolutions(0, j + 1);
                  findSolutions(i + 1, j);
                  grid[i][j] = 0;
              }
     }
     else {
          if (i == N - 1)
              findSolutions(0, j + 1);
          findSolutions(i + 1, j);
     }
}

int main (void) {
    findSolutions(0, 0);
}