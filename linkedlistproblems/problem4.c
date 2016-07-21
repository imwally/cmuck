/*
 * Problem 4
 *
 * Write a Pop() function that is the inverse of Push(). Pop() takes a
 * non-empty list, deletes the head node, and returns the head node's
 * data. If all you ever used were Push() and Pop(), then our linked
 * list would really look like a stack. However, we provide more
 * general functions like GetNth() which what make our linked list
 * more than just a stack. Pop() should assert() fail if there is not
 * a node to pop.
 */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct node {
    int           data;
    struct  node* next;
};

/*
 * Build the list {1, 2, 3} in the heap and store its head pointer in
 * a local stack variable.  Returns the head pointer to the caller.
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

/*
 * ListLen returns the length of a linked list. It takes as an
 * argument the head of a linked list, a pointer to a struct node.
 */
int ListLen(struct node* head) {
    int count = 0;
    struct node* current;
    for (current = head; current != NULL; current = current->next) {
        count++;
    }

    return count;
}

/*
 * Pop returns the data of the first node of a linked list and then
 * removes the node from the list.
 */
int Pop(struct node** headRef) {
    struct node* head = *headRef;

    assert(head != NULL);
    
    int value = head->data;
    *headRef = head->next;
    free(head);

    return value;
}

int main(int argc, char* argv[]) {
    struct node* head= BuildOneTwoThree();
    int lenBefore = ListLen(head);
    printf("length of list before pops: %d\n", lenBefore);

    int a = Pop(&head);
    int b = Pop(&head);
    int c = Pop(&head);
    printf("a: %d\nb: %d\nc: %d\n", a, b, c); 
    
    int lenAfter= ListLen(head);
    printf("length of list after pops: %d\n", lenAfter);

    // Assert failure when list is empty.
    int d = Pop(&head);
}
