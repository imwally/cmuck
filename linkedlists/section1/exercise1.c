/*
* Write the code with the smallest number of assignments (=) which will build
* the above memory structure. A: It requires 3 calls to malloc(). 3 int
* assignments (=) to setup the ints. 4 pointer assignments to setup head and
* the 3 next fields. With a little cleverness and knowledge of the C language,
* this can all be done with 7 assignment operations (=).
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int          data;
    struct node* next;
};

/*
* Build the list {1, 2, 3} in the heap and store
* its head pointer in a local stack variable.
* Returns the head pointer to the caller.
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

int main() {

    struct node* head = BuildOneTwoThree();

    struct node* current;
    for(current = head; current != NULL;) {
        printf("%d\n", current->data);
        current = current->next;
    }
}
