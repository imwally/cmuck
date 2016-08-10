/* 
 * Problem 6 - SortedInsert()
 * 
 * Write a SortedInsert() function which given a list that is sorted in
 * increasing order, and a single node, inserts the node into the correct
 * sorted position in the list. While Push() allocates a new node to add to the
 * list, SortedInsert() takes an existing node, and just rearranges pointers to
 * insert it into the list. There are many possible solutions to this problem.
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int           data;
    struct  node* next;
};

/*
 * Build the list {1, 2, 3} in the heap and store its head pointer in a local
 * stack variable.  Returns the head pointer to the caller.
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

void PrintList(struct node* head) {
    struct node* current;

    int count = 0;
    for (current = head; current != NULL; current = current->next) {
        printf("index: %d, value: %d\n", count, current->data);
        count++;
    }
    printf("---\n");
}

void SortedInsert(struct node** headRef, struct node* newNode) {
    struct node* current;
    struct node* beforeInsert;

    for (current = *headRef; (current != NULL && current->data < newNode->data); current = current->next) {
        beforeInsert = current;
    }

    beforeInsert->next = newNode;
    newNode->next = current;    
}

int main(int argc, char* argv[]) {
    struct node* head = BuildOneTwoThree();

    struct node* newNodeTen = malloc(sizeof(struct node));
    newNodeTen->data = 10;
    newNodeTen->next = NULL;

    SortedInsert(&head, newNodeTen);
    PrintList(head);

    struct node* newNodeFour = malloc(sizeof(struct node));
    newNodeFour->data = 4;
    newNodeFour->next = NULL;

    SortedInsert(&head, newNodeFour);
    PrintList(head);

    struct node* newNodeEleven = malloc(sizeof(struct node));
    newNodeEleven->data = 11;
    newNodeEleven->next = NULL;

    SortedInsert(&head, newNodeEleven);
    PrintList(head);
}
