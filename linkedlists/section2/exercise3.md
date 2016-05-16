# Exercise

The following function correctly builds a three element list using nothing but
Push(). Make the memory drawing to trace its execution and show the final state
of its list. This will also demonstrate that Push() works correctly for the
empty list case.

```
void Push(struct node** headRef, int data) {
   struct node* newNode = malloc(sizeof(struct node));
   newNode->data = data;
   newNode->next = *headRef;  // The '*' to dereferences back to the real head
   *headRef = newNode;        // ditto
}

void PushTest2() {
   struct node* head = NULL;  // make a list with no elements
   Push(&head, 1);
   Push(&head, 2);
   Push(&head, 3);
   // head now points to the list {3, 2, 1}
}
```

```
Stack           |  Heap
------          |  ------
                |
PushTest2()     |
                |
       head . . |. . .-> NULL
        ^ \     |          ^
Push()  |  \    |          |
        |   \   |          |
    headRef  `--|---> [ 1 |  ]
    data [1]    |
```

```
Stack           |  Heap
------          |  ------
                |
PushTest2()     |               NULL
                |                 ^
       head.    |                 |
        ^ \ .   |                 |
Push()  |  \  . |. . . . .-> [ 1 |  ]
        |   \   |              ^       
    headRef  \  |              |
    data [2]  \ |              |
               `|-------> [ 2 |  ]
```

```
Stack           |  Heap
------          |  ------
                |
PushTest2()     |               NULL
                |                 ^
       head     |                 |
        ^ \ .   |                 |
Push()  |  \ .  |            [ 1 |  ]
        |   \ . |              ^       
    headRef  \ .|              |
    data [3]  \ |.             |
               `|  . .->  [ 2 |  ]
                |\          ^
                | \         |
                |  \        |
                |   `->[ 3 |  ]
```
