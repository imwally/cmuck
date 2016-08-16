# How does the solution to problem 18 work?

tl;dr: The magic happens in the unwinding of the call stack of RecursiveReverse.

## The Basics

Initially the `list` looks like this:

```C
10->9->8->7->6->5->4->3->2->1->NULL
```

The head of the list, `10`, is passed to `RecursiveReverse()` where it
deconstructs the list into it's head and the rest of the list. It looks similar
to this on each recursive call:

### 1.
```C
head = 10
rest = 9->8->7 ...
```

### 2.
```C
head = 9
rest = 8->7->6 ...
```

### 3.
```C
head = 8
rest = 7->6->5 ...
```

Since this is a recursive function there needs to be a base case to tell it
when to stop. In this instance there are actually two, one when `*headRef ==
NULL` and one when `rest == NULL`. It's not hard to see that the list is
shortened by 1 node on each call so when the list has been exhausted and `rest
== NULL` the function returns. I always assumed that once a function returned
then all code execution inside of that function ceases. Turns out I was wrong. 

## The Call Stack

When a function is called certain information about it is placed on what is
called the [Call Stack](https://en.wikipedia.org/wiki/Call_stack). The stack
consists of frames where information such as the return address, function
parameters and local variables of the currently running function are kept. If a
function calls another function then another frame is placed on top of the
stack. The stack grows top to bottom so the currently running function is
always on top. In a very simple program where `main()` calls `a()` which calls
`b()` the stack would look something like this when `b()` is called:

```
frame #0 :
    b()
frame #1:
    a()
frame #3:
    main()
```

Eventually execution will return to `main()` when `b()` then `a()` is finished.
Applying this information to a recursive function it's easy to see how quickly
the stack can grow each time the function calls itself. Specifically in the
case of `RecursiveReverse()` and a list length of 10 it would look something
like this:


```
frame #0:
    head = 1
    rest = NULL
frame #1:
    head = 2
    rest = 1->NULL
frame #2:
    head = 3
    rest = 2->1->NULL 
frame #3:
    head = 4
    rest = 3->2->1->NULL

...

frame #9:
    head = 10
    rest = 9->8->7 ...
```


## Reversing the list

The unique thing in this case are the few lines of code *after* the recursive
call. This is where the new list is built in reverse as the stack shrinks and
execution returns to each frame below itself.


``` C
void RecursiveReverse(struct node** headRef) {
    struct node* head;
    struct node* rest;

    if (*headRef == NULL) {
        return;
    }

    head = *headRef;
    rest = head->next;

    if (rest == NULL) {
        return;
    }

    RecursiveReverse(&rest);

    head->next->next = head;
    head->next = NULL;

    *headRef = rest;
}
```

Looking at the call stack frame information from above you can see execution
continues starting at #1, not #0. This is because in frame #0 `rest` reaches
`NULL` and thus starting a return to each frame below as the stack shrinks.
What happens though is execution continues in each frame on the lines just
after the recursive call:

```C
head->next->next = head;
head->next = NULL;

*headRef = rest;
```

So looking at frame #1 and following each frame down the stack the code would
look like this:

### 1.
before assignment:
```C
head->next->next = NULL 
head->next = 1 

*headRef = 2 
```

after assignment:
```C
head->next->next = 2 
head->next = NULL 

*headRef = 1 
```

### 2. 
before assignment:
```C
head->next->next = NULL 
head->next = 2 

*headRef = 3 
```

after assignment:
```C
head->next->next = 3 
head->next = NULL 

*headRef = 1 
```

### 3.
before assignment:
```C
head->next->next = NULL 
head->next = 3 

*headRef = 4 
```

after assignment:
```C
head->next->next = 4 
head->next = NULL 

*headRef = 1 
```

You'll notice `*headRef` will always point to 1 on each recursive call. This
makes sense, the head should now be the last element of the original list. The
interesting part though is the assignment of `head->next->next` to `head`. So
what's really happening here?

Without these 3 lines of code that shift pointers around `head` would look like
this on each call in the stack rewind instead:

### 1.
```C
2->1->NULL
```

### 2.
```C
3->2->1->NULL
```

### 3. 
```C
4->3->2->1->NULL
```

etc...

Replacing the code with the actual list elements and following along down the
stack you'll see the list being build.

### 1.
```C
head->next->next = head (2->1->2->1->... infinite loop)
head->next = NULL (2->NULL ends infinite loop from above)
```

The ONE thing to remember here is that `rest` pointed to `head->next` or the `1`.

```
head   rest
 |       |
 2 ----> 1
 ^       | 
 |       |
 +-------+
```

So the line that assigns `head->next = NULL` is terminating this infinite loop
but keep in mind that what it pointed to, `rest` is not removed.

```
head      rest
 |          |
 2 -> NULL  1
 |          |
 +----------+
```

And of course the last line reassigns `*headRef = rest` so it always points to
the `1`. Keep following along...

### 2.
```C
head->next->next = head (3->2->3->2->... infinite loop)
head->next = NULL (3->NULL ends infinite loop from above)
```

`rest` pointed to the `1` which pointed to the `2` which now points to this new
infinite loop.

```
head           rest
 |               |
 3 ----> 2 <---- 1
 ^       | 
 |       |
 +-------+
```

Once again the loop is terminated by setting `head->next = NULL`.

```
head              rest
 |                  |
 3 -> NULL  2 <---- 1
 ^          | 
 |          |
 +----------+
```

Eventually the stack will return to the original call to `RecursiveReverse()`
with `10` as the head parameter and the list will be fully reversed.
