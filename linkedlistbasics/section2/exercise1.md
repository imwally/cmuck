## WrongPush()

```
void WrongPush(struct node* head, int data) {
   struct node* newNode = malloc(sizeof(struct node));
   newNode->data = data;
   newNode->next = head;
   head = newNode;      // NO this line does not work!
}
   
void WrongPushTest() {
   List head = BuildTwoThree();
   WrongPush(head, 1);  // try to push a 1 on front -- doesn't work
}
```

## Exercise

Make the memory drawing tracing WrongPushTest() to see how it does not
work. The key is that the line head = newElem; changes the head local
to WrongPush() not the head back in WrongPushTest(). Remember that the
local variables for WrongPush() and WrongPushTest() are separate (just
like the locals for LengthTest() and Length() in the Length() example
above).


```

Stack                |  Heap
------               |  ------
                     |
WrongPushTest()      |
                     |
    head             |
    +------+         |       +-----+--+     +----+---+
    |      | ------- | ----> |  2  |  |---> | 3  | / |
    +------+         |       +-----+--+     +----+---+
                     |
    WrongPush()      |
                     |
        head         |			 
        +------+     |       +----+---+
        |      | --- | ----> | 1  | / |
        +------+             +----+---+

```
