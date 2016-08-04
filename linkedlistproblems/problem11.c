/*
 * Problem 11
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
    assert(*sourceRef != NULL);
    struct node* sourceHeadCopy = malloc(sizeof(struct node));
    sourceHeadCopy->data = (*sourceRef)->data;
    sourceHeadCopy->next = *destRef;
    *destRef = sourceHeadCopy;

    struct node* oldSourceRef = *sourceRef; 
    *sourceRef = (*sourceRef)->next;
    free(oldSourceRef);
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
