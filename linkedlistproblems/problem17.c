/*
 * Problem 17 - Reverse()
 *
 * Write an iterative Reverse() function that reverses a list by rearranging
 * all the .next pointers and the head pointer. Ideally, Reverse() should only
 * need to make one pass of the list. The iterative solution is moderately
 * complex. It's not so difficult that it needs to be this late in the
 * document, but it goes here so it can be next to #18 Recursive Reverse which
 * is quite tricky. 
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

void ReverseList(struct node** headRef) {
    assert(*headRef != NULL);
    struct node* current = *headRef;
    struct node* newList = NULL;

    while (current != NULL) {
        struct node* next = current->next;

        current->next = newList;
        newList = current;  
        
        current = next;
    }        

    *headRef = newList;
}

int main(int argc, char* argv[]) {
    struct node* list = NULL;
    Push(&list, 1);
    Push(&list, 2);
    Push(&list, 3);
    Push(&list, 4);
    Push(&list, 5);
    Push(&list, 6);
    Push(&list, 7);
    Push(&list, 8);
    Push(&list, 9);
    Push(&list, 10);
    PrintList(list);

    ReverseList(&list);
    PrintList(list);

}
