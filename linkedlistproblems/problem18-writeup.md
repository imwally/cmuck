# How Does Problem 18 Work?

tl;dr: The magic happens in the unwinding of the call stack of RecursiveReverse.

Initially the `list` looks like this:

10->9->8->7->6->5->4->3->2->1->NULL

The head of the list, 10, is passed to RecursiveReverse function where it
deconstructs the list into it's head and the rest of the list. It looks similar
to this on each recursive call:

### 1.
```
head = 10
rest = 9->8->7 ...
```

### 2.
```
head = 9
rest = 8->7->6 ...
```

### 3.
```
head = 8
rest = 7->6->5 ...
```


But when `rest` finally reaches `NULL` the function returns where the stack
unwinding occurs and each frame is popped off the stack. The thing to
remember however is that on the current invocation of RecursiveReverse the
frame stack looks something like this:

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

Execution continues on each frame (starting at #1 from above, not #0) as the
stack unwinds on the following lines of code:

```
head->next->next = head;
head->next = NULL;

*headRef = rest;
```

So looking at frame #1 and following each frame down the stack the code would
look like this:

### 1.
before assignment:
```
head->next->next = NULL 
head->next = 1 

*headRef = 2 

```

after assignment:
```
head->next->next = 2 
head->next = NULL 

*headRef = 1 

```

### 2. 
before assignment:
```
head->next->next = NULL 
head->next = 1 

*headRef = 2 

```

after assignment:
```
head->next->next = 2 
head->next = NULL 

*headRef = 1 

```


