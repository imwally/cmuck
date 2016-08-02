/*
 * Problem 9
 *
 * Given a list, split it into two sublists — one for the front half, and one
 * for the back half. If the number of elements is odd, the extra element
 * should go in the front list. So FrontBackSplit() on the list {2, 3, 5, 7,
 * 11} should yield the two lists {2, 3, 5} and {7, 11}. Getting this right for
 * all the cases is harder than it looks. You should check your solution
 * against a few cases (length = 2, length = 3, length=4) to make sure that the
 * list gets split correctly near the short-list boundary conditions. If it
 * works right for length=4, it probably works right for length=1000. You will
 * probably need special case code to deal with the (length <2) cases.
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int           data;
    struct  node* next;
};

struct node* BuildList(int start, int end) {
    struct node* head = malloc(sizeof(struct node));
    struct node* current = head;

    for (int i = start; i <= end; i++) {
        struct node* new = malloc(sizeof(struct node));

        current->data = i;
        current->next = i < end ? new : NULL;
        
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

int ListLength(struct node* head) {
    int count = 0;
    struct node* current;
    for (current = head; current != NULL; current = current->next) {
        count++;
    }

    return count;
}

void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef) {

    int length = ListLength(source);
    // The front list will always contain the extra element of an odd length source list.
    int frontLength = (length / 2) + (length % 2); 

    int count = 0;
    struct node* current;
    struct node* beforeLast;
    for (current = source; (current != NULL && count < frontLength); current = current->next) {
        count++;
        beforeLast = current;
    }
    
    // Sever the source list roughly in the middle.
    beforeLast->next = NULL;

    *frontRef = source;
    *backRef = current;
}

int main(int argc, char* argv[]) {
    struct node* head = BuildList(1, 13);
    PrintList(head);
  
    struct node* front;
    struct node* back; 
    FrontBackSplit(head, &front, &back); 

    PrintList(front);
    PrintList(back);
}
