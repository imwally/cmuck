/* 
 * Problem 15 - MergeSort()
 *
 * (This problem requires recursion) Given FrontBackSplit() and SortedMerge(),
 * it's pretty easy to write a classic recursive MergeSort(): split the list
 * into two smaller lists, recursively sort those lists, and finally merge the
 * two sorted lists together into a single sorted list. Ironically, this
 * problem is easier than either FrontBackSplit() or SortedMerge().
 */

#include <assert.h>
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

int Pop(struct node** headRef) {
    struct node* head = *headRef;
    assert(head != NULL);
    
    int value = head->data;
    *headRef = head->next;
    free(head);

    return value;
}

struct node* NewNode(int data, struct node* next) {
        struct node* newNode = malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = next;   

        return newNode; 
}

int ListLength(struct node* head) {
    int count = 0;
    struct node* current;
    for (current = head; current != NULL; current = current->next) {
        count++;
    }

    return count;
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

struct node* SortedMerge(struct node* a, struct node* b) {
    struct node* newList = NULL; 

    if (a->data < b->data) {
        newList = NewNode(Pop(&a), NULL);
    } else {
        newList = NewNode(Pop(&b), NULL);
    } 
    struct node* newListHead = newList;

    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            newList->next = NewNode(Pop(&a), NULL);
        } else {
            newList->next = NewNode(Pop(&b), NULL);
        }
        newList = newList->next;
    }
    
    struct node* remaining = NULL;   
    if (a != NULL) {
        remaining = a;
    }
    if (b != NULL) {
        remaining = b;
    }

    while (remaining != NULL) {
        newList->next = NewNode(Pop(&remaining), NULL);
        newList = newList->next;
    }

    return newListHead;
}

void MergeSort(struct node** headRef) {
    struct node* head = *headRef;
    struct node* front;
    struct node* back;
    if (ListLength(head) == 1) {
        return;
    }

    FrontBackSplit(head, &front, &back);
    
    MergeSort(&front);
    MergeSort(&back);

    *headRef = SortedMerge(front, back);
}

int main(int argc, char* argv[]) {
    struct node* list = NULL;
    Push(&list, 34);
    Push(&list, 4);
    Push(&list, 84);
    Push(&list, 37);
    Push(&list, 21);
    Push(&list, 12);
    Push(&list, 9);
    Push(&list, 2);
    Push(&list, 92);
    Push(&list, 78);
    Push(&list, 100);
    PrintList(list);

    MergeSort(&list);
    PrintList(list);
}
