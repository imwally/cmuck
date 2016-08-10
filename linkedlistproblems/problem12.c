/*
 * Problem 12 - AlternatingSplit()
 * 
 * Write a function AlternatingSplit() that takes one list and divides up its
 * nodes to make two smaller lists. The sublists should be made from
 * alternating elements in the original list. So if the original list is {a, b,
 * a, b, a}, then one sublist should be {a, a, a} and the other should be {b,
 * b}. You may want to use MoveNode() as a helper. The elements in the new
 * lists may be in any order (for some implementations, it turns out to be
 * convenient if they are in the reverse order from the original list.)
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int           data;
    struct  node* next;
};

void Push(struct node** headRef, int data) {
    struct node* newNode = malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}   

int Pop(struct node** headRef) {
    struct node* head = *headRef;
    assert(head != NULL);
    
    int value = head->data;
    *headRef = head->next;
    free(head);

    return value;
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

void MoveNode(struct node** destRef, struct node** sourceRef) {
    Push(destRef, Pop(sourceRef));
}

void AlternatingSplit(struct node* source, struct node** aRef, struct node** bRef) {
    int count = 1;
    struct node* current = source;
    while (current != NULL) {
        if (count % 2 == 0) {
            MoveNode(aRef, &source);
        }
        else {
            MoveNode(bRef, &source);
        }
        count++;
        current = source;
    }
}

int main(int argc, char *arg[]) {
    struct node* list = NULL;
    Push(&list, 8); 
    Push(&list, 7); 
    Push(&list, 6); 
    Push(&list, 5); 
    Push(&list, 4);  
    Push(&list, 3);  
    Push(&list, 2);  
    Push(&list, 1);  
    
    struct node* listA = NULL;
    struct node* listB = NULL;

    AlternatingSplit(list, &listA, &listB);

    PrintList(listA);
    PrintList(listB);
}
