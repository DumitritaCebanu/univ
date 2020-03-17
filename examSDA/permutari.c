// printeaza toate permutarile
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r){
    int i;
    if (l == r)
        printf("%s\n", a);
    else {
        for(i = l; i <= r; i++)
        {
            swap((a + 1), (a + i));
            permute(a, l + 1, r);
            swap((a + l), (a + 1));
        }
    }
}
int main (){
    char string[] = "ABC";
    int size = strlen(string);
    permute(string, 0, size-1);
    return 0;
}