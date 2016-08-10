/* 
 * Problem16 - SortedIntersect()
 *
 * Given two lists sorted in increasing order, create and return a new list
 * representing the intersection of the two lists. The new list should be made
 * with its own memory — the original lists should not be changed. In other
 * words, this should be Push() list building, not MoveNode(). Ideally, each
 * list should only be traversed once. This problem along with Union() and
 * Difference() form a family of clever algorithms that exploit the constraint
 * that the lists are sorted to find common nodes efficiently.
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

struct node* SortedIntersect(struct node* a, struct node* b) {
    struct node* newList = NULL;
   
    struct node* currentA = a;
    struct node* currentB = b;
    while (currentA != NULL && currentB != NULL) {
        if (currentA->data < currentB->data) {
            currentA = currentA->next; 
        }
        else if (currentB->data < currentA->data) {
            currentB = currentB->next; 
        }
        else {
            Push(&newList, currentA->data);
            currentA = currentA->next; 
            currentB = currentB->next; 
        }
    }
   
    return newList;
}

int main(int argc, char* argv[]) {
    struct node* listA = NULL;
    Push(&listA, 500);
    Push(&listA, 300);
    Push(&listA, 150);
    Push(&listA, 129);
    Push(&listA, 124);
    Push(&listA, 123);
    Push(&listA, 122);
    Push(&listA, 119);
    Push(&listA, 113);
    Push(&listA, 110);
    Push(&listA, 100);
    Push(&listA, 89);
    Push(&listA, 88);
    Push(&listA, 83);
    Push(&listA, 59);
    Push(&listA, 35);
    Push(&listA, 33);
    Push(&listA, 24);
    Push(&listA, 12);
    Push(&listA, 9);
   
    struct node* listB = NULL;
    Push(&listB, 500);
    Push(&listB, 124);
    Push(&listB, 87);
    Push(&listB, 60);
    Push(&listB, 59);
    Push(&listB, 35);
    Push(&listB, 24);
    Push(&listB, 21);
    Push(&listB, 18);
    Push(&listB, 12);

    PrintList(listA); 
    PrintList(listB); 

    struct node* intersected = SortedIntersect(listA, listB);
    PrintList(intersected);
}
