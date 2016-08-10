/*
 * Problem 2 - GetNth()
 *
 * Write a GetNth() function that takes a linked list and an integer
 * index and returns the data value stored in the node at that index
 * position. GetNth() uses the C numbering convention that the first
 * node is index 0, the second is index 1, ... and so on. So for the
 * list {42, 13, 666} GetNth() with index 1 should return 13. The
 * index should be in the range [0..length- 1]. If it is not, GetNth()
 * should assert() fail (or you could implement some other error case
 * strategy).
 */
#include <stdio.h>
#include <stdlib.h>

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

int ListLen(struct node* head) {
    int count = 0;
    struct node* current;
    for (current = head; current != NULL; current = current->next) {
        count++;
    }

    return count;
}

int GetNth(struct node* head, int index) {
    if (index > ListLen(head)-1) {
        printf("error: index %d is out of bounds.\n", index);
        return -1;
    }

    int count = 0;
    struct node* current;
    for (current = head; current != NULL; current = current->next) {
        if (count == index) {
	    return current->data;
        }
	count++;
    }

    return -1;
}

int main(int argc, char* argv[]) {
    struct node* myList = BuildOneTwoThree();
    
    int lastNode = GetNth(myList, 2);
    if (lastNode >= 0) {
	printf("index 2 of myList contains %d\n", lastNode);
    }

    int outOfBounds = GetNth(myList, 5); 
    if (outOfBounds >= 0) {
	printf("index 5 of myList contains %d\n", outOfBounds);
    }
   
    return 0;
}
