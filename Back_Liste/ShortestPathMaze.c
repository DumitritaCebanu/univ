#include <stdio.h>

#define N 8

int solution[N][N] = {{0}}, visited[N][N] = {{0}}, auxSolution[N][N], paths = 1;
int maze[N][N] = {{1, 1, 1, 1, 1, 1, 1, 1},  
                  {1, 1, 0, 0, 0, 0, 0, 1}, 
                  {1, 1, 0, 0, 0, 0, 0, 1}, 
                  {1, 1, 1, 1, 0, 0, 0, 1},
                  {1, 1, 0, 1, 0, 0, 0, 1},
                  {1, 1, 0, 1, 1, 1, 0, 1},
                  {1, 1, 0, 0, 0, 1, 0, 1},
                  {0, 0, 0, 0, 0, 1, 1, 1}};

int stepsNumber (int matrix[N][N]) {
    int sum = -1;

    for (int index_1 = 0; index_1 < N; index_1++)
         for (int index_2 = 0; index_2 < N; index_2++)
              sum += matrix[index_1][index_2];
    
    return sum;
}

void allignSolutions () {
    for (int index_1 = 0; index_1 < N; index_1++)
         for (int index_2 = 0; index_2 < N; index_2++)
              auxSolution[index_1][index_2] = solution[index_1][index_2];
}

int validSolution (int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N || maze[x][y] == 0 || visited[x][y] == 1)
       return 0;

    return 1;
}

int isSolution (int x, int y) {
    if (x == N - 1 && y == N - 1)
        return 1;

    return 0;
}

void printSolution (int matrix[N][N]) {
    printf("- The shortest path -\n\n");
    for (int index_1 = 0; index_1 < N; index_1++) {
        for (int index_2 = 0; index_2 < N; index_2++)
             printf("%d ", matrix[index_1][index_2]);
        printf("\n");
    }
}

void backtracking (int x, int y) {
     if (!validSolution(x, y))
         return;

     if (isSolution(x, y)) {
        solution[x][y] = 1; 
        if (paths > 1) {
            int path1 = stepsNumber(solution);
            int path2 = stepsNumber(auxSolution);
            if (path1 <= path2)
                allignSolutions();
        }
        if (paths == 1)
            allignSolutions();
        paths++;
        return; 
    } 

    visited[x][y] = 1;
    solution[x][y] = 1;

    if (validSolution(x + 1, y)) 
        backtracking(x + 1, y);

    if (validSolution(x, y - 1)) 
        backtracking(x, y - 1);
    

    if (validSolution(x, y + 1)) 
        backtracking(x, y + 1);
    

    if (validSolution(x - 1, y)) 
        backtracking(x - 1, y);

    visited[x][y] = 0;
    solution[x][y] = 0;
}

int main (void) {    
    backtracking(0, 0);
    printSolution(auxSolution);
}