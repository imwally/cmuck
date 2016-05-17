#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/*
 * A very frequent technique in linked list code is to iterate a
 * pointer over all the nodes in a list. Traditionally, this is
 * written as a while loop. The head pointer is copied into a local
 * variable current which then iterates down the list. Test for the
 * end of the list with current!=NULL. Advance the pointer with
 * current=current->next.
 */
int Length(struct node *head) {
  int count = 0;

  struct node *current = head;

  for (current = head; current != NULL; current = current->next) {
    count++;
  }

  return count;
}

int main() {
  struct node *head = NULL;

  Push(&head, 1);
  Push(&head, 2);

  int len = Length(head);

  printf("%d\n", len);
}
