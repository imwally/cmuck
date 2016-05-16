# Correct Push() Code

```
void Push(struct node** headRef, int data) {
   struct node* newNode = malloc(sizeof(struct node));
   newNode->data = data;
   newNode->next = *headRef;  // The '*' to dereferences back to the real head
   *headRef = newNode;        // ditto
}
   
void PushTest() {
   struct node* head = BuildTwoThree();// suppose this returns the list {2, 3}
   Push(&head, 1);      // note the &
   Push(&head, 13);
   // head is now the list {13, 1, 2, 3}
}
```

```
Stack           |   Heap
------          |   ------
                |
PushTest()      |
                |
	  head . . .|. . . > [ 2 |  ] ---> [ 3 | / ]
	    ^ \     |         ^
        |  \    |         | 
        |   `---|--> [ 1 |  ]
Push()  |       |
      headRef   |
	  data [1]  |
	
```

# Exercise

The above drawing shows the state of memory at the end of the first
call to Push() in PushTest(). Extend the drawing to trace through the
second call to Push(). The result should be that the list is left with
elements {13, 1, 2, 3}.


```
Stack           |   Heap
------          |   ------
                |
PushTest()      |
                |
	  head . . .|. . . . .> [ 2 |  ] ---> [ 3 | / ]
	    ^ \ .   |            ^
        |  \ .  |            | 
        |   \ . |. . .> [ 1 |  ]
Push()  |    \  |         ^
        |     \ |         |
        |      `|--> [ 13|  ]
      headRef   |
	  data [13] |
	
```
