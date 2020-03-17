#include <stdio.h>

#define k 5

int solution[100] = {0}, size;
int setOfValues[] = {2, 5, 3, 1, 4, 6, 0};

void printSolution (int n) {
    for (int index = 1; index <= n; index++)
        printf("%d ", solution[index]);

    printf("\n");
}

int validSolution (int n) {
    for (int index = 1; index <= n - 1; index++)
         if (solution[n] == solution[index])
             return 0;

    for (int index = 1; index <= n - 1; index++)
         if (solution[index] > solution[index + 1])
             return 0;

    return 1;
}

int isSolution (int n, int j) {
    if (n == j) {
        int sum = 0;
        for (int index = 1; index <= n; index++)
             sum += solution[index];
        if (sum == k)
            return 1;
    }

    return 0;
}

void findSolutions (int n, int j) {
     for (int index = 0; index < size; index++) {
          solution[n] = setOfValues[index];
          if (validSolution(n))
              if (isSolution(n, j))
                  printSolution(n);
              else
                   findSolutions(n + 1, j);
     }
}

void backtrackingCalls () {
    for (int index = 2; index <= size; index++)
         findSolutions(1, index);

}

int main (void) {
    size = sizeof(setOfValues) / sizeof(setOfValues[0]);
    backtrackingCalls();
}
