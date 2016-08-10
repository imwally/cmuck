/*
 * Problem 8 - Append()
 * 
 * Write an Append() function that takes two lists, 'a' and 'b', appends 'b'
 * onto the end of 'a', and then sets 'b' to NULL (since it is now trailing off
 * the end of 'a'). Here is a drawing of a sample call to Append(a, b) with the
 * start state in gray and the end state in black. At the end of the call, the
 * 'a' list is {1, 2, 3, 4}, and 'b' list is empty.
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int           data;
    struct  node* next;
};

struct node* BuildList(int start, int end) {
    struct node* head = malloc(sizeof(struct node));
    struct node* current = head;

    for (int i = start; i <= end; i++) {
        struct node* new = malloc(sizeof(struct node));

        current->data = i;
        current->next = i < end ? new : NULL;
        
        current = new;
    }

    return head;
}

void PrintList(struct node* head) {
    struct node* current;

    int count = 0;
    for (current = head; current != NULL; current = current->next) {
        printf("index: %d, value: %d\n", count, current->data);
        count++;
    }
    printf("---\n");
}

void Append(struct node** aRef, struct node** bRef) {
    // If A list is NULL B will become the only list.
    if (*aRef == NULL) {
        *aRef = *bRef;
        return;
    }
    
    // Find end of A list.
    struct node* currentA;
    struct node* lastNodeA;
    for (currentA = *aRef; currentA != NULL; currentA = currentA->next) {
        lastNodeA = currentA;
    }
    
    // Create new B head and set old B to NULL;
    struct node* newB = malloc(sizeof(struct node));
    newB->data = (*bRef)->data;
    newB->next = (*bRef)->next;
    free(*bRef);
    *bRef = NULL;

    // Link end of list A to new B head.
    lastNodeA->next = newB;
}

int main(int argc, char* argv[]) {
    struct node* listA = BuildList(1, 4);
    struct node* listB = BuildList(5, 8);
    
    PrintList(listA);
    PrintList(listB);

    Append(&listA, &listB);
    PrintList(listA);
    PrintList(listB); // This should be NULL.
}
