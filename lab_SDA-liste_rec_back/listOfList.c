#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Toy {
    char name[50];
    struct Toy *next;
} tToy;

typedef struct Child {
    char name[50];
    tToy *firstToy;
    struct Child *next;
} tChild;

void *chkMalloc (size_t size) {
    void *mem = malloc (size);
    // Just fail immediately on error.
    if (mem == NULL) {
        printf ("Out of memory!\n");
        exit (1);
    }
    // Otherwise we know it worked.
    return mem;
}
void addChild (tChild **first, char *name) {
    // Insert new item at start.
    tChild *newest = chkMalloc (sizeof (*newest));
    strcpy (newest->name, name);
    newest->next = *first;
    *first = newest;
}
void addToy (tChild *first, char *name) {
    // Insert at start of list.
    tToy *newest = chkMalloc (sizeof (*newest));
    strcpy (newest->name, name);
    newest->next = first->firstToy;
    first->firstToy = newest;
}
void dumpDetails (tChild *currChild) {
    // For every child.
    while (currChild != NULL) {
        printf ("%s has:\n", currChild->name);
        // For every toy that child has.
        tToy *currToy = currChild->firstToy;
        if (currToy == NULL) {
            printf ("   <<nothing>>\n");
        } else {
            while (currToy != NULL) {
                printf ("   %s\n", currToy->name);
                currToy = currToy->next;
            }
        }
        currChild = currChild->next;
    }
}
int main (void) {
    tChild *firstChild = NULL;

    addChild (&firstChild, "Anita");
    addToy (firstChild, "skipping rope");
    addChild (&firstChild, "Beth");
    addChild (&firstChild, "Carla");
    addToy (firstChild, "model car");
    
    addToy (firstChild, "trampoline");

    dumpDetails (firstChild);

    return 0;
}
