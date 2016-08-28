/*
 * Problem 11 - sameTree()
 * 
 * Given two binary trees, return true if they are structurally
 * identical -- they are made of nodes with the same values arranged
 * in the same way.
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

struct node* buildBSTree() {
    struct node* root = NewNode(2);
    root->left = NewNode(1);
    root->right = NewNode(3);

    return root; 
}

void printPostorder(struct node* node) {
    if (node == NULL) {
        return;
    }

    if (node->left != NULL) {
        printPostorder(node->left);
    }
    
    if (node->right != NULL) {
        printPostorder(node->right);
    }

    printf("%d  ", node->data);
}

int sameTree(struct node* a, struct node* b) {
    if (a == NULL && b == NULL) {
	return 1;
    }

    if (a == NULL || b == NULL) {
	return 0;
    }
    
    if (a->data != b->data) {
	return 0;
    }

    return sameTree(a->left, b->left) &&
	sameTree(a->right, b->right);
}

int main(int argc, char* argv[]) {
    struct node* a = buildBSTree();
    struct node* b = buildBSTree();
    
    if (sameTree(a, b)) {
	printf("match\n");
    } else {
	printf("no match\n");
    }
}
