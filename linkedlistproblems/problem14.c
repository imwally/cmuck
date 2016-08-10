/*
 * Problem 14 - SortedMerge()
 * 
 * Write a SortedMerge() function that takes two lists, each of which is sorted
 * in increasing order, and merges the two together into one list which is in
 * increasing order. SortedMerge() should return the new list. The new list
 * should be made by splicing together the nodes of the first two lists (use
 * MoveNode()). Ideally, Merge() should only make one pass through each list.
 * Merge() is tricky to get right — it may be solved iteratively or
 * recursively. There are many cases to deal with: either 'a' or 'b' may be
 * empty, during processing either 'a' or 'b' may run out first, and finally
 * there's the problem of starting the result list empty, and building it up
 * while going through 'a' and 'b'.
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

struct node* NewNode(int data, struct node* next) {
        struct node* newNode = malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = next;   

        return newNode; 
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

struct node* SortedMerge(struct node* a, struct node* b) {
    struct node* newList = NULL; 

    if (a->data < b->data) {
        newList = NewNode(Pop(&a), NULL);
    } else {
        newList = NewNode(Pop(&b), NULL);
    } 
    struct node* newListHead = newList;

    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            newList->next = NewNode(Pop(&a), NULL);
        } else {
            newList->next = NewNode(Pop(&b), NULL);
        }
        newList = newList->next;
    }
    
    struct node* remaining = NULL;   
    if (a != NULL) {
        remaining = a;
    }
    if (b != NULL) {
        remaining = b;
    }

    while (remaining != NULL) {
        newList->next = NewNode(Pop(&remaining), NULL);
        newList = newList->next;
    }

    return newListHead;
}

int main(int argc, char *arg[]) {
    struct node* listA = NULL;
    Push(&listA, 18);
    Push(&listA, 12);
    Push(&listA, 9);
    Push(&listA, 8);
    Push(&listA, 6);
    Push(&listA, 4);

    struct node* listB = NULL;
    Push(&listB, 15);
    Push(&listB, 3);
    Push(&listB, 2);
    Push(&listB, 1);

    PrintList(listA);
    PrintList(listB);

    struct node* sortedList = SortedMerge(listB, listA); 
    PrintList(sortedList);
}
