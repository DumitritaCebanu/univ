#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void printarray(int array[], int data[], int start, int end, int index, int k){
    if (index == k) {
        for(int j = 0; j < k; j++)
        printf("%d ", data[j]);
        printf("\n");
        return;
    }
    for(int i = start; i <= end && end - i + 1 >= k - index; i++){
        data[index] = array[i];
        printarray(array, data, i + 1, end, index + 1, k);
    }
}
void print(int array[], int n, int k){
    int data[k];
    printarray(array, data, 0, n - 1, 0, k);
}

int main(){
    int array[] = {1, 2, 3, 4};
    int k = 3;
    int n = sizeof(array)/sizeof(array[0]);
    print(array, n, k);
}