#include <stdio.h>
#include <string.h>

#define M 3
#define N 4

char boggle[M][M] = {{'G', 'I', 'Z'},
                     {'U', 'E', 'K'},
                     {'Q', 'S', 'E'}};

char *dictionary[N] = {"GEEKS", "FFF", "QUIZ", "GEE"};
char visited[M][M], solution[1000];
int already[N];

void initialization() {
    for (int index_1 = 0; index_1 < M; index_1++)
        for (int index_2 = 0; index_2 < M; index_2++)
             visited[index_1][index_2] = '0';
}

int validSolution(int x, int y) {
    if (visited[x][y] == '0')
        return 1;

    return 0;
}

void printSolution() {
    puts(solution);
}

int isSolution(int k, int z) {
    if (k == z) 
        return 1;

    return 0;
}

void findSolutions(int k, int z) {
    if (isSolution(k, z)) {
        for (int index = 0; index < N; index++) 
            if (strcmp(dictionary[index], solution) == 0 && already[index] == 0) {
                already[index] = 1;
                printSolution();
            } 
        return;
    }

    for (int x = 0; x < M; x++)
        for (int y = 0; y < M; y++)
            if (validSolution(x, y)) {
                solution[k] = boggle[x][y];
                visited[x][y] = boggle[x][y];
                findSolutions(k + 1, z);
                visited[x][y] = '0';
            }
}

void allPossibleLengths() {
    for (int index = 3; index <= 5; index++) {
        initialization();
        findSolutions(0, index);
    }
}

int main(void) {
    allPossibleLengths();
}