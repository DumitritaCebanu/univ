#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue {
    int data;
    int priority;
} *array;

int length = 0, max_size = 10;

void push (int data, int priority) {  
     if (length == max_size)
         return;

     length++;
     array = (struct queue *) realloc (array, length * sizeof(struct queue)); 

     if (length > 1)
        for (int index = length; index > 0; index--) 
            array[index] = array[index - 1];

     array[0].data = data;
     array[0].priority = priority;    
}

int pop () {
    if (length == 0)
        return -1;
        
    int min = array[0].priority, min_pos = 0;

    for (int index = 1; index < length; index++)
         if (array[index].priority < min) {
             min = array[index].priority;
             min_pos = index;
         }

    return array[min_pos].data;
}

bool gol () {
    if (length == 0)
        return true;

    return false;
}

int plin () {
    if (length == max_size)
        return true;

    return false;
}

void display () {
    if (length == 0) 
        return;

    for (int index = length - 1; index >= 0; index--) 
        printf("Elementul %d <---> Prioritatea %d\n", array[index].data, array[index].priority);
    
    printf("\n");
}

int main (void) {
    array = (struct queue *) malloc (length * sizeof(struct queue));

    push(2, 2);
    push(1, 0);
    push(4, 5);
    push(4, 2);
    push(16, 3);
    push(2, 1);
    push(2, 8);
    push(13, 0);
    push(1, 1);
    push(7, 5);

    display();
    
    if (gol())
        printf("Coada este goala.\n");
    else 
        printf("Coada nu este goala.\n");

    if (plin())
        printf("Coada este plina.\n");
    else 
        printf("Coada nu este plina.\n");

    printf("\nProgramul a fost executat cu succes.\n");
}