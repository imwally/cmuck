#include <stdio.h>
#include <stdlib.h>

struct node {
    int          data;
    struct node* next;
};

/*
* Build the list {2, 3} in the heap and store its head pointer in a local stack
* variable. Returns the head pointer to the caller.
*/
struct node* BuildTwoThree() {

    struct node* head = malloc(sizeof(struct node));

    struct node* current = head;
    for (int i = 2; i < 4; i++) {
        struct node* new = malloc(sizeof(struct node));

        current->data = i;
        current->next = i < 3 ? new : NULL;
        
        current = new;
    }

    return head;
}

/*
* WrongPush() is very close to being correct. It takes the correct 3-Step Link
* In and puts it an almost correct context. The problem is all in the very last
* line where the 3-Step Link In dictates that we change the head pointer to
* refer to the new node. What does the line head = newNode; do in WrongPush()?
* It sets a head pointer, but not the right one. It sets the variable named head
* local to WrongPush(). It does not in any way change the variable named head
* we really cared about which is back in the caller WrontPushTest().
*/
void WrongPush(struct node* head, int data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;      // NO this line does not work!
}

/*
* Takes a list and a data value.  Creates a new link with the given data and
* pushes it onto the front of the list.  The list is not passed in by its
* head pointer.  Instead the list is passed in as a "reference" pointer to the
* head pointer -- this allows us to modify the caller's memory.
*/
void Push(struct node** headRef, int data) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *headRef;  // The '*' to dereferences back to the real head
    *headRef = newNode;        // ditto
}

int main() {

    // PushTest()
    struct node* head = BuildTwoThree();// suppose this returns the list {2, 3}
    Push(&head, 1);      // note the &
    Push(&head, 13);     // head is now the list {13, 1, 2, 3}

    struct node* current;
    for(current = head; current != NULL;) {
        printf("%d\n", current->data);
        current = current->next;
    }
}
