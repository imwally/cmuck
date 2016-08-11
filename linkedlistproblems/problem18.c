/*
 * Problem 18 - RecursiveReverse() 
 *
 * (This problem is difficult and is only possible if you are familiar with
 * recursion.) There is a short and efficient recursive solution to this
 * problem. As before, the code should only make a single pass over the list.
 * Doing it with multiple passes is easier but very slow, so here we insist on
 * doing it in one pass.. Solving this problem requires a real understanding of
 * pointer code and recursion.
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

/*
 * I've accepted defeat. This is the solution taken from the end of Linked List
 * Problems workbook.
 */
void RecursiveReverse(struct node** headRef) {
    struct node* head;
    struct node* rest;

    if (*headRef == NULL) {
        return;
    }

    head = *headRef;
    rest = head->next;

    if (rest == NULL) {
        return;
    }

    RecursiveReverse(&rest);

    head->next->next = head;
    head->next = NULL;
    
    *headRef = rest; 

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

    RecursiveReverse(&list);
    PrintList(list);    
}
