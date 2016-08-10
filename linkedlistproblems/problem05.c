/*
 * Problem 5 - InsertNth()
 *
 * A more difficult problem is to write a function InsertNth() which
 * can insert a new node at any index within a list. Push() is
 * similar, but can only insert a node at the head end of the list
 * (index 0). The caller may specify any index in the range
 * [0..length], and the new node should be inserted so as to be at
 * that index.
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int           data;
    struct  node* next;
};

struct node* NewNode(int data, struct node* next) {
        struct node* newNode = malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = next;   

        return newNode; 
}

void InsertNth(struct node** headRef, int index, int data) {
    struct node* head = *headRef;

    if (index == 0) {
        struct node* next = NULL;
        if (head != NULL) {
            next = head->next;
        }
        *headRef = NewNode(data, next);
        return;
    }

    int count = 0;
    struct node* current;
    for (current = head; current != NULL; current = current->next) {
        // Stop at the node just before the one being replaced so that
        // current->next can be set to the new node.
        if (count == index-1) {
            struct node* afterNext = NULL;
            if (current->next != NULL) {
                afterNext = current->next->next;
            }
            // Free original node.
            free(current->next);
            // Link new node.
            current->next = NewNode(data, afterNext);
            return;
        } 
        count++;
    } 

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

int main(int argc, char* argv[]) {
    struct node* head = NULL;

    InsertNth(&head, 0, 13);
    PrintList(head); 
    InsertNth(&head, 1, 42);
    PrintList(head); 
    InsertNth(&head, 2, 56);
    PrintList(head); 
    InsertNth(&head, 1, 23);
    PrintList(head); 
    InsertNth(&head, 0, 18);
    PrintList(head); 
    InsertNth(&head, 3, 88);
    PrintList(head); 
    InsertNth(&head, 7, 88);
    PrintList(head); 
}
