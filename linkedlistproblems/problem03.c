/*
 * Problem 3 - DeleteList()
 *
 * Write a function DeleteList() that takes a list, deallocates all of
 * its memory and sets its head pointer to NULL (the empty list).
 */
#include <stdlib.h>
#include <stdio.h>

struct node {
    int           data;
    struct  node* next;
};

/*
 * Build the list {1, 2, 3} in the heap and store its head pointer in
 * a local stack variable.  Returns the head pointer to the caller.
 */
struct node* BuildOneTwoThree() {

    struct node* head = malloc(sizeof(struct node));

    struct node* current = head;
    for (int i = 1; i < 4; i++) {
        struct node* new = malloc(sizeof(struct node));

        current->data = i;
        current->next = i < 3 ? new : NULL;
        
        current = new;
    }

    return head;
}

void DeleteList(struct node** headRef) {
    struct node* head = *headRef;
    struct node* current;
    for (current = head; current != NULL; current = current->next) {
        free(current);
    }

    *headRef = NULL;
}
 
int main(int argc, char *argv[]) {

    struct node* myList = BuildOneTwoThree();
    DeleteList(&myList);

    struct node* current;
    for(current = myList; current != NULL; current = current->next) {
        printf("%p\n", current);
    }
}
