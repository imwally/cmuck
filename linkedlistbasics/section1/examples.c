#include <stdio.h>
#include <stdlib.h>

struct node {
    int     data;
    struct  node* next;
};

/*
* Build the list {1, 2, 3} in the heap and store
* its head pointer in a local stack variable.
* Returns the head pointer to the caller.
*/
struct node* BuildOneTwoThree() {
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    return head;
}

/*
* Given a linked list head pointer, compute
* and return the number of nodes in the list.
*/
int Length(struct node* head) {
   struct node* current = head;

   int count = 0;
   while (current != NULL) {
      count++;
      current = current->next;
   }

   return count;
}

int main() {
    struct node* head = BuildOneTwoThree();

    struct node* current;
    for(current = head; current != NULL;) {
        printf("%d\n", current->data);
        current = current->next;
    }

    int len;
    len = Length(head);
    printf("length: %d\n", len);
}
