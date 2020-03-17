#include <string.h> 
#include <stdio.h> 
  
int max (int a, int b) { 
    if (a > b)
        return a;
    
    return b;
} 

void badCharHeuristic(char *str, int size, int badchar[256]) { 
    int i; 

    for (i = 0; i < size; i++) 
         badchar[(int) str[i]] = i; 
} 

void search (char *txt, char *pat) { 
    int m = strlen(pat), n = strlen(txt), badchar[n]; 
  
    badCharHeuristic(pat, m, badchar); 
  
    int s = 0;  

    while(s <= (n - m)) { 
        int j = m - 1; 
        while (j >= 0 && pat[j] == txt[s + j]) 
              j--; 

        if (j < 0) { 
            printf("\nPattern is found at shift = %d\n", s); 
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1; 
        } 
        else
            s += max(1, j - badchar[txt[s+j]]); 
    } 
} 
  
int main() { 
    char txt[] = "ABATAAABCDTA"; 
    char pat[] = "TA"; 
    search(txt, pat); 
} 