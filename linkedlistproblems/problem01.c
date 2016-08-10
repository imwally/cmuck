/*
 * Problem 1 - Count()
 *
 * Write a Count() function that counts the number of times a given
 * int occurs in a list. The code for this has the classic list
 * traversal structure as demonstrated in Length().
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

/*
 * Given a list and an int, return the number of times that int occurs
 * in the list.
 */
int Count(struct node* head, int searchFor) {

    int counter = 0;

    struct node* current;
    for (current = head; current != NULL; current = current->next) {
        if (current->data == searchFor) {
            counter++;
        }
    }

    return counter;
}

int main(int argc, char* argv[]) {
  
    struct node* List = BuildOneTwoThree();

    int searchTwo = Count(List, 2);
    int searchSix = Count(List, 6);

    printf("2: %d\n6: %d\n", searchTwo, searchSix);
}

  
