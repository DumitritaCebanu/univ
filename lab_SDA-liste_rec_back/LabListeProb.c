#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *child;
};

struct Node *initializeList (struct Node *head) {
    struct Node *temp_1 = head, *aux;
    if (head == NULL)
        return head;
    while (temp_1 != NULL) {
        struct Node *temp_2 = temp_1->child;
        while (temp_2 != NULL) {
               aux = temp_2->child;
               free(temp_2);
               temp_2 = aux;
        }
        aux = temp_1->next;
        free(temp_1);
        temp_1 = aux;
    }
}
struct Node *addToPrimary (struct Node *head, int data) {
    struct Node *new_node = (struct Node *) malloc (sizeof(struct Node));
    new_node->data = data;

    if (head == NULL) {
        new_node->next = NULL;
        new_node->child = NULL;
        head = new_node;
        return head;
    }
    struct Node *temp;
    for (temp = head; temp->next != NULL; temp = temp->next);
    new_node->next = temp->next;
    new_node->child = NULL;
    temp->next = new_node;
    return head;
}
struct Node *addToSecondary (struct Node *head, int data, int node_nr) {
     if (head == NULL)
         return head;
     struct Node *new_node = (struct Node *) malloc (sizeof(struct Node));
     new_node->data = data;
     struct Node *temp, *aux;
     int counter = 0;
     for (temp = head; temp->next != NULL && counter != node_nr; temp = temp->next)
          counter++;
     if (temp->child == NULL) {
         new_node->child = NULL;
         temp->child = new_node;
         return head;
     }
     for (aux = temp; aux->child != NULL; aux = aux->child);
     new_node->child = aux->child;
     aux->child = new_node;
     return head;
}
struct Node *removeFromPrimary (struct Node *head, int node) {
    struct Node *temp_1, *temp_2, *aux;
    if (head == NULL)
        return head;
    if (head->data == node) {
        temp_1 = head->child;
        while (temp_1 != NULL) {
               aux = temp_1->child;
               free(temp_1);
               temp_1 = aux;
        }
        temp_1 = head->next;
        free(head);
        head = temp_1;
        return head;
    }
    for (temp_1 = head; temp_1 != NULL; temp_1 = temp_1->next)
        if (temp_1->next != NULL && temp_1->next->data == node) {
            temp_2 = temp_1->next->child;
            while (temp_2 != NULL) {
                  aux = temp_2->child;
                  free(temp_2);
                  temp_2 = aux;
            }
            aux = temp_1->next->next;
            free(temp_1->next);
            temp_1->next = aux;
            return head;
        }
    return head;
}
struct Node *removeFromSecondary (struct Node *head, int node) {
    struct Node *temp_1, *temp_2, *aux;
    if (head == NULL)
        return head; 
    
    for (temp_1 = head; temp_1 != NULL; temp_1 = temp_1->next)
        for (temp_2 = temp_1->child; temp_2 != NULL; temp_2 = temp_2->child)
             if (temp_2->data == node) {
                 temp_1->child = temp_2->child;
                 free(temp_2);
                 return head;
             }
             else if (temp_2->child != NULL && temp_2->child->data == node) {
                 aux = temp_2->child->child;
                 free(temp_2->child);
                 temp_2->child = aux;
                 return head;
             }
    return head;
}
void displayList (struct Node *head) {
    struct Node *temp_1, *temp_2;
    int counter = 1;
    if (head == NULL) {
       printf("Empty linked list.\n");
       return;
    }
    for (temp_1 = head; temp_1 != NULL; temp_1 = temp_1->next) {
        printf("Sublista %d: %d", counter++, temp_1->data);
        if (temp_1->child != NULL)
            printf(" -> ");
        for (temp_2 = temp_1->child; temp_2 != NULL; temp_2 = temp_2->child) {
            printf("%d", temp_2->data);
            if (temp_2->child != NULL)
                printf(" -> ");
        }
        printf("\n");
    }
    printf("\n");
}
int main (void) {
    struct Node *linked_list = NULL;

    linked_list = addToPrimary(linked_list, 1);
    linked_list = addToPrimary(linked_list, 2);
    linked_list = addToPrimary(linked_list, 3);

    linked_list = addToSecondary(linked_list, 4, 0);
    linked_list = addToSecondary(linked_list, 5, 0);
    linked_list = addToSecondary(linked_list, 6, 0);
    linked_list = addToSecondary(linked_list, 7, 1);
    linked_list = addToSecondary(linked_list, 8, 1);
    linked_list = addToSecondary(linked_list, 9, 2);
    linked_list = addToSecondary(linked_list, 10, 2);
    linked_list = addToSecondary(linked_list, 11, 2);

    linked_list = removeFromPrimary(linked_list, 2);

    linked_list = removeFromSecondary(linked_list, 10);
    linked_list = removeFromSecondary(linked_list, 6);
    linked_list = removeFromSecondary(linked_list, 4);
    linked_list = removeFromSecondary(linked_list, 4);

    displayList(linked_list);
    
    printf("The program was executed successfully.\n");
}
//Sublista 1: 1 -> 4 -> 5 -> 6
 //Sublista 2: 2 -> 7 -> 8
 //Sublista 3: 3 -> 9 -> 10 -> 11