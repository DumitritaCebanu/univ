#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// RETURNEAZA CEL MAI MIC CARACTER (ASCII)
char functie1(char s[], char c){
    if(strlen(s) == 0)
        return c;
    else
        s[0] < c ? functie1(s+1, s[0]) : functie1(s+1, c);
}

// OGLINDESTE UN STRING
char * functie2(char *s){
     int i = 0;
     char q[256];
    if(*s){
        functie2(s+1);
        q[i++] = *s;
    }
    return q;
}

int main(){
    char x[] = "elisabeth";
    char y[] = "focus";
    printf("%c\n", functie1(x+1, x[0]));
    printf("%s", functie2(y));
    return 0;
}