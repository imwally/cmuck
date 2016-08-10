/*
 * Problem 11 - MoveNode()
 *
 * This is a variant on Push(). Instead of creating a new node and pushing it
 * onto the given list, MoveNode() takes two lists, removes the front node from
 * the second list and pushes it onto the front of the first. This turns out to
 * be a handy utility function to have for several later problems.
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

int main(int argc, char *arg[]) {
    struct node* listA = NULL;
    Push(&listA, 3); 
    Push(&listA, 2); 
    Push(&listA, 1); 

    struct node* listB = NULL;
    Push(&listB, 6); 
    Push(&listB, 5); 
    Push(&listB, 4); 

    printf("List A\n");
    PrintList(listA);
    printf("List B\n");
    PrintList(listB);

    MoveNode(&listA, &listB);
    printf("List A\n");
    PrintList(listA);
    printf("List B\n");
    PrintList(listB);

    MoveNode(&listA, &listB);
    printf("List A\n");
    PrintList(listA);
    printf("List B\n");
    PrintList(listB);
}
