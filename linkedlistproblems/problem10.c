/*
 * Problem 10 - RemoveDuplicates()
 *
 * Write a RemoveDuplicates() function which takes a list sorted in increasing
 * order and deletes any duplicate nodes from the list. Ideally, the list
 * should only be traversed once.
 */

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

void RemoveDuplicates(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        if (current->next != NULL && current->data == current->next->data) {
            // Save pointer to the duplicate node.
            struct node* duplicate = current->next;

            // Point next to the node AFTER the duplicate.
            current->next = current->next->next;

            // Free up the original duplicate.
            free(duplicate);
            
            // Don't advance the pointer until all duplicates have been removed.
            current = current;
        } 
        else {
            // Duplicates have been removed, advance the pointer.
            current = current->next;
        }
    }
    
}

int main(int argc, char* argv[]) {
    struct node* head = NULL;
    Push(&head, 10);
    Push(&head, 10);
    Push(&head, 9);
    Push(&head, 8);
    Push(&head, 7);
    Push(&head, 7);
    Push(&head, 7);
    Push(&head, 6);
    Push(&head, 6);
    Push(&head, 6);
    Push(&head, 5);
    Push(&head, 4);
    Push(&head, 4);
    Push(&head, 4);
    Push(&head, 4);
    Push(&head, 3);
    Push(&head, 2);
    Push(&head, 2);
    Push(&head, 1);
    PrintList(head);

    RemoveDuplicates(head);
    PrintList(head);
}
