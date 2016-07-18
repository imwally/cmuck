struct node {
  int data;
  struct node *next;
};

void Push(struct node **headRef, int data) {
  struct node *newNode = malloc(sizeof(struct node));

  newNode->data = data;
  newNode->next = *headRef;
  
  *headRef = newNode;
}

 
