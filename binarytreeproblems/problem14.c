/*
 * Problem 14 - isBST() -- version 2
 * 
 * Version 1 above runs slowly since it traverses over some parts of
 * the tree many times. A better solution looks at each node only
 * once. The trick is to write a utility helper function
 * isBSTRecur(struct node* node, int min, int max) that traverses down
 * the tree keeping track of the narrowing min and max allowed values
 * as it goes, looking at each node only once. The initial values for
 * min and max should be INT_MIN and INT_MAX -- they narrow from
 * there.
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* NewNode(int data) {
	struct node* node = malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

int minValue(struct node* node) {
	if (node->left == NULL) {
		return node->data;
	}

	return minValue(node->left);
}

int maxValue(struct node* node) {
	if (node->right == NULL) {
		return node->data;
	}

	return maxValue(node->right);
}

int isBSTRecur(struct node* node, int min, int max) {
	if (node == NULL) {
		return 1;
	}
	
	if (node->data < min || node->data > max) {
		return 0;
	}

	return isBSTRecur(node->left, min, node->data) &&
		isBSTRecur(node->right, node->data+1, max);
}

int isBST(struct node* node) {
	return (isBSTRecur(node, minValue(node), maxValue(node)));
}


int main(int argc, char* argv[]) {
	struct node* a = NewNode(5);
	a->left = NewNode(2);
	a->right = NewNode(7);

	struct node* b = NewNode(5);
	b->left = NewNode(6);
	b->right = NewNode(7);

	struct node* c = NewNode(5);
	c->left = NewNode(2);
	c->left->left = NewNode(1);
	c->right = NewNode(7);

	struct node* d = NewNode(5);
	d->left = NewNode(2);
	d->left->left = NewNode(1);
	d->left->right = NewNode(6);
	d->right = NewNode(7);
	
	printf("a: %d\n", isBST(a));
	printf("b: %d\n", isBST(b));
	printf("c: %d\n", isBST(c));
	printf("d: %d\n", isBST(d));
}
