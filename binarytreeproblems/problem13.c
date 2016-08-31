/*
 * Problem 13 - isBST()
 * 
 * Suppose you have helper functions minValue() and maxValue() that
 * return the min or max int value from a non-empty tree (see problem
 * 3 above). Write an isBST() function that returns true if a tree is
 * a binary search tree and false otherwise. Use the helper functions,
 * and don't forget to check every node in the tree. It's ok if your
 * solution is not very efficient.
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

int isBST(struct node* node) {
	if (node->data < maxValue(node->left) || node->data > minValue(node->right)) {
		return 0;
	} else {
		return 1;
	}
	
	return isBST(node->left) && isBST(node->right);
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
