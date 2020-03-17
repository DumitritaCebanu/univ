#include <stdio.h>

#define n 2
#define m 3

int parametru[n] = {0}, value[m] = {0};

int valid(int p, int v){
    for(int i = 1; i <= p - 1; i++)
        if(parametru[p] == parametru[i])
            return 0;
    for(int j = 1; j <= v - 1; j++)
            if (value[v] == value[j])
                return 0;
     for(int i = 1; i <= p - 1; i++)
                if(parametru[i] > parametru[i + 1])
                    return 0;
     return 1;
}

int solution(int p, int v){
    if(p == n && v == n)
        return 1;
    return 0;
}

int display(int p, int v){
    for(int i = 1; i <= p; i++)
        printf("f(%d) = %d \n", parametru[i], value[i]);
    printf("\n");
}

int backtraking(int p, int v){
    for(int i = 1; i <= n; i++){
        parametru[p] = i;
    for(int j = 1; j <= m; j++){
        value[v] = j;
    if(valid(p, v))
        if(solution(p, v))
            display(p, v);
        else
            backtraking(p + 1, v + 1);
        }
    }

}

int main(){
    backtraking(1, 1);
}

