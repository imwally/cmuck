/*
 * Problem 13 - ShuffleMerge()
 *
 * Given two lists, merge their nodes together to make one list, taking nodes
 * alternately between the two lists. So ShuffleMerge() with {1, 2, 3} and {7,
 * 13, 1} should yield {1, 7, 2, 13, 3, 1}. If either list runs out, all the
 * nodes should be taken from the other list. The solution depends on being
 * able to move nodes to the end of a list as discussed in the Section 1
 * review. You may want to use MoveNode() as a helper. Overall, many techniques
 * are possible: dummy node, local reference, or recursion. Using this function
 * and FrontBackSplit(), you could simulate the shuffling of cards.
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

struct node* ShuffleMerge(struct node* a, struct node* b) {
    assert(a != NULL && b != NULL);
    struct node* currentA = a; 
    struct node* currentB = b; 

    struct node* newList;
    if (a == NULL) {
        newList = NewNode(b->data, NULL); 
        currentB = currentB->next;
    } else {
        newList = NewNode(a->data, NULL);
        currentA = currentA->next;
    }
    struct node* newListHead = newList;

    int count = 1;
    while (currentA != NULL || currentB != NULL) {
        if (count % 2 == 0) {
            newList->next = NewNode(currentA->data, NULL);
            currentA = currentA->next;
            count++;
        } else {
            newList->next = NewNode(currentB->data, NULL);
            currentB = currentB->next;
            count--; 
        }
        newList = newList->next;
    }
    
    return newListHead;
}

int main(int argc, char *arg[]) {
    struct node* listA = NULL;
    Push(&listA, 3);
    Push(&listA, 2);
    Push(&listA, 1);

    struct node* listB = NULL;
    Push(&listB, 1);
    Push(&listB, 13);
    Push(&listB, 7);

    PrintList(listA);
    PrintList(listB);

    struct node* newList = NULL;
    newList = ShuffleMerge(listA, listB); 

    PrintList(newList);
}
