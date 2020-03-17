#include <stdio.h>
#include <stdlib.h>
unsigned int factorial(unsigned int n) 
{ 
    if (n == 0) 
      return 1; 
    return n * factorial(n - 1); 
} 
  
int main() 
{ 
    int num;
    printf("Introdu un numar: ");
    scanf("%d", &num);
    printf(" %d ! =  %d", num, factorial(num)); 
    return 0; 
} 
