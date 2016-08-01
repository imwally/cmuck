/*
 * Problem 7
 *
 * Write an InsertSort() function which given a list, rearranges its nodes so
 * they are sorted in increasing order. It should use SortedInsert().
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int           data;
    struct  node* next;
};

struct node* BuildInvertedList() {
    struct node* head = malloc(sizeof(struct node));
    struct node* current = head;

    for (int i = 10; i > 0; i--) {
        struct node* new = malloc(sizeof(struct node));

        current->data = i;
        current->next = i > 1 ? new : NULL;
        
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
    struct node* head = *headRef;

    // Deal with the empty list.
    if (head == NULL) {
        newNode->next = *headRef; 
        *headRef = newNode;
        return;
    }

    // Deal with new nodes that have a lower value than the head. 
    if (newNode->data <= head->data) {
        newNode->next = *headRef; 
        *headRef = newNode;
        return;
    }

    struct node* beforeInsert;
    struct node* current;
    for(current = head; (current != NULL && current->data < newNode->data); current = current->next) {
        beforeInsert = current;
    }

    beforeInsert->next = newNode;
    newNode->next = current;
}

void InsertSort(struct node** headRef) {
    struct node* newList = NULL;
    struct node* current = *headRef;
    struct node* next;
    while (current != NULL) {
        next = current->next;
        SortedInsert(&newList, current);
        current = next;
    }

    *headRef = newList;
}

int main(int argc, char* argv[]) {
    struct node* invertedList = BuildInvertedList();
    PrintList(invertedList); 

    InsertSort(&invertedList);
    PrintList(invertedList); 
}
